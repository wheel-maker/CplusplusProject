#include "hanoi.h"
#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include <time.h>
#include <Windows.h>
using namespace std;

/* -----------------------------------------

	 本文件功能：
	1、放被 hanoi_main.cpp/hanoi_menu.cpp 中的各函数调用的菜单各项对应的执行函数

	 本文件要求：
	1、不允许定义外部全局变量（const及#define不在限制范围内）
	2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
	3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------- */

   /*--------------全局变量--------------*/
int        move_num;            //移动步数

static int a[11] = { 0 };       //a[0]表示栈顶位置
static int b[11] = { 0 };
static int c[11] = { 0 };



/*-----------下列为汉诺塔数组相关函数-----------*/
int pop(char array)
{
	switch (array)
	{
		case 'a':
		case 'A':
			if (!a[0])
				return -1;
			a[0]--;
			return a[a[0] + 1];
			break;

		case 'b':
		case 'B':
			if (!b[0])
				return -1;
			b[0]--;
			return b[b[0] + 1];
			break;

		case 'c':
		case 'C':
			if (!c[0])
				return -1;
			c[0]--;
			return c[c[0] + 1];
			break;

		default:
			return 0;
			break;
	}
}
void push(char array, int& num)
{
	switch (array)
	{
		case 'a':
		case 'A':
			if (a[0] >= 10)
				exit(-1);
			a[0]++;
			a[a[0]] = num;
			break;

		case 'b':
		case 'B':
			if (b[0] >= 10)
				exit(-1);
			b[0]++;
			b[b[0]] = num;
			break;

		case 'c':
		case 'C':
			if (c[0] >= 10)
				exit(-1);
			c[0]++;
			c[c[0]] = num;
			break;

		default:
			break;
	}
}




/*-----------下列为汉诺塔的主要功能函数-----------*/

/***************************************************************************
  函数名称：hanoi_tower
  功    能：完成汉诺塔各种输出要求
  输入参数：用户选择
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_tower(int choice)
{
	char begin = 'a';
	char middle = 'b';
	char end = 'c';
	int level = 0;
	int speed = 0;

	if (choice == 5)
	{
		cct_cls();
		tower_draw(begin, end, level, choice, speed);
		while (_getch() != 13);
		return;
	}

	cout << endl << endl;
	level = input_para(&begin, &middle, &end);//输入汉诺塔参数
	hanoi_initial(begin, level);

	if (choice == 4 || choice == 8) {
		while (1) {
			cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短)";
			cin >> speed;
			if (speed >= 0 && speed <= 5)
				break;
		}
		hanoi_init_output(begin, end, level, choice, speed);
		if (choice == 8)
			tower_draw(begin, end, level, choice, speed);
	}

	if (choice == 6 || choice == 7)
		tower_draw(begin, end, level, choice, speed);

	if (choice == 9)
		hanoi_tower_game(begin, middle, end, level);
	else
	{
		hanoi_move(begin, middle, end, level, choice, speed);
		cout << endl << "按回车键继续";
	}
	while (_getch() != 13);

	move_num = 0;//将移动步数清零
	a[0] = b[0] = c[0] = 0;//将汉诺塔数组清零
}

/***************************************************************************
  函数名称：hanoi_move
  功    能：汉诺塔递归移动函数
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_move(char begin, char middle, char end, int level, int choice, int speed) {
	int plate_num;
	if (level == 1) {   //移动一次的情况
		move_num++;
		push(end, (plate_num = pop(begin)));
		move_output(plate_num, begin, end, level, choice, speed);
	}
	else {
		hanoi_move(begin, end, middle, level - 1, choice, speed);  //从begin到middle移动level-1个盘子
		move_num++;
		push(end, (plate_num = pop(begin)));
		move_output(plate_num, begin, end, level, choice, speed);
		hanoi_move(middle, begin, end, level - 1, choice, speed);//从middle到end移动level-1个盘子
	}
}

/***************************************************************************
  函数名称：hanoi_tower_game
  功    能：汉诺塔游戏
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_tower_game(char begin, char middle, char end, int level)
{
	hanoi_init_output(begin, end, level, 9);
	tower_draw(begin, end, level, 9);
	cct_gotoxy(0, 36);
	cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";

	char from;
	char to;
	while (1)
	{
		char buff[10] = " ";
		cct_gotoxy(60, 36);
		cout << setw(10) << ' ';
		cct_gotoxy(60, 36);
		//while (cin.get() != 10);

		for (int i = 0; i < 10; i++)
		{
			buff[i] = cin.get();
			if (buff[i] == 10)
				break;
		}
		from = buff[0];
		to = buff[1];
		if (from == 'q' || from == 'Q')
		{
			cout << endl << "游戏中止！";
			return;
		}

		if ((from >= 'a' && from <= 'c') || from >= 'A' && from <= 'C')
			if ((to >= 'a' && to <= 'c' && to != from) || to >= 'A' && to <= 'C' && from != to)
				if (is_correct(from, to)&&game_win(begin,end,level))
					break;
	}

	cct_gotoxy(0, 40);
	cout << "恭喜你！游戏胜利！";

}




/*-------------------下列为完成基本解的辅助函数------------------*/

//根据汉诺塔参数初始化数组
void hanoi_initial(char begin, int level)
{
	int i;
	switch (begin)
	{
		case 'a':
		case 'A':
			for (i = 1; i <= level; i++)
				a[i] = level - i + 1;
			a[0] = level;
			break;
		case 'b':
		case 'B':
			for (i = 1; i <= level; i++)
				b[i] = level - i + 1;
			b[0] = level;
			break;
		case 'c':
		case 'C':
			for (i = 1; i <= level; i++)
				c[i] = level - i + 1;
			c[0] = level;
			break;
		default:
			break;
	}
}

//根据输入确定汉诺塔的层数、起始柱等参数
int input_para(char* begin, char* middle, char* end)
{
	int level;

	while (1)//确定汉诺塔的层数
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> level;
		while (cin.fail() == 1)
		{
			cin.clear();
			while (cin.get() != 10);
		}
		if (level > 0 && level < 11)
			break;
	}

	while (1)//确定汉诺塔的起始柱
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> *begin;
		if ((*begin - 'a' >= 0 && *begin - 'a' <= 2) || (*begin - 'A' >= 0 && *begin - 'A' <= 2))
		{
			while (cin.get() != 10);
			break;
		}
	}

	while (1)//确定汉诺塔的目标柱
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> *end;
		if ((*end - 'a' >= 0 && *end - 'a' <= 2) || (*end - 'A' >= 0 && *end - 'A' <= 2))
			if (*end != *begin)
				break;
	}
	if (*begin - 'A' >= 0 && *begin - 'A' <= 2)
		*begin = *begin + 32;
	if(*end - 'A' >= 0 && *end - 'A' <= 2)
		*end = *end + 32;

	*middle = 'a' + 'b' + 'c' - *begin - *end;//确定汉诺塔的中间柱

	return level;
}

//根据坐标求移动到塔顶的步数
int move_height(int x)
{
	char disk = 'b';
	if (x < 12)
		disk = 'a';
	else if (x > 44)
		disk = 'c';

	switch (disk)
	{
		case 'a':
			return 12 - a[0];
		case 'b':
			return 12 - b[0];
		case 'c':
			return 12 - c[0];

		default:
			return 0;
	}
}

//根据输入修改纵向和横向数组
void array_move(char begin, char end)
{
	int plate_num;
	move_num++;
	push(end, (plate_num = pop(begin)));
	move_output(plate_num, begin, end);
}



/*-------------------下列为汉诺塔的输出相关的函数------------------*/

//汉诺塔移动输出函数
void move_output(int plate_num, char begin, char end, int level, int choice, int speed)
{
	switch (choice)
	{
		case 1:
			cout << plate_num << "# " << begin << "-->" << end << endl;
			break;
		case 2:
			cout << "第" << setw(4) << move_num << " 步(" << setw(2) << plate_num << "#: " << begin << "-->" << end << ')' << endl;
			break;
		case 3:
			cout << "第" << setw(4) << move_num << " 步(" << setw(2) << plate_num << "#: " << begin << "-->" << end << ")  ";
			tower_routput();
			break;
		case 7:
			if (move_num == 1)
			{
				Sleep(1000);
				disk_move(begin, end, choice, speed);
			}
			break;
		case 4:
		case 8:
			if (!speed)
				while (_getch() != 13);
			else
				Sleep((6 - speed) * 200);
		case 9:
			tower_coutput(plate_num, begin, end, choice);
			if (choice == 8||choice==9)
				cct_gotoxy(0, DEEP + 16);
			else
				cct_gotoxy(0, 16);
			cout << "第" << setw(4) << move_num << " 步(" << setw(2) << plate_num << "#: " << begin << "-->" << end << ")  ";
			tower_routput();

			if (choice == 8||choice==9)
				disk_move(begin, end, choice, speed);
			break;
		default:
			break;
	}
}

//汉诺塔初始化状态下的打印
void hanoi_init_output(char begin, char end, int level, int choice, int speed)
{
	cct_cls();
	cout << "从 " << begin << " 移动到 " << end << "，共" << setw(2) << level << " 层";
	if (choice != 9)
		cout << "，延时设置为 " << speed;
	cout << endl;

	if (choice == 8 || choice == 9)
		cct_gotoxy(0, DEEP + 1);
	for (int j = 10; j >= 1; j--)
	{
		cout << setw(10) << ' ';
		if (j > a[0])
			cout << "  ";
		else
			cout << setw(2) << a[j];

		cout << setw(8) << ' ';
		if (j > b[0])
			cout << "  ";
		else
			cout << setw(2) << b[j];

		cout << setw(8) << ' ';
		if (j > c[0])
			cout << "  ";
		else
			cout << setw(2) << c[j];
		cout << endl;
	}
	cout << setw(9) << ' ' << "=========================" << endl;
	cout << setw(11) << ' ' << "A         B         C" << endl;

	if (choice == 8)
		cct_gotoxy(0, DEEP + 16);
	else
		cout << endl << endl << endl;
	cout << "初始:   ";
	tower_routput();
}

//横向打印汉诺塔
void tower_routput()
{
	int i;
	cout << "A:";
	for (i = 1; i <= a[0]; i++)
		cout << setw(2) << a[i];
	for (; i < 11; i++)
		cout << "  ";

	cout << "B:";
	for (i = 1; i <= b[0]; i++)
		cout << setw(2) << b[i];
	for (; i < 11; i++)
		cout << "  ";

	cout << "C:";
	for (i = 1; i <= c[0]; i++)
		cout << setw(2) << c[i];
	for (; i < 11; i++)
		cout << "  ";

	cout << endl;
}

//纵向打印汉诺塔
void tower_coutput(int plate_num, char begin, char end, int choice)
{
	switch (begin)
	{
		case 'a':
		case 'A':
			if (choice == 8||choice==9)
				cct_gotoxy(11, DEEP + 10 - a[0]);
			else
				cct_gotoxy(11, 10 - a[0]);
			cout << ' ';
			break;
		case 'b':
		case 'B':
			if (choice == 8 || choice == 9)
				cct_gotoxy(21, DEEP + 10 - b[0]);
			else
			    cct_gotoxy(21, 10 - b[0]);
			cout << ' ';
			break;
		case 'c':
		case 'C':
			if (choice == 8 || choice == 9)
				cct_gotoxy(31, DEEP + 10 - c[0]);
			else
			    cct_gotoxy(31, 10 - c[0]);
			cout << ' ';
			break;
		default:
			break;
	}

	switch (end)
	{
		case 'a':
		case 'A':
			if (choice == 8 || choice == 9)
				cct_gotoxy(11, DEEP + 11 - a[0]);
			else
			    cct_gotoxy(11, 11 - a[0]);
			cout << plate_num;
			break;
		case 'b':
		case 'B':
			if (choice == 8 || choice == 9)
				cct_gotoxy(21, DEEP + 11 - b[0]);
			else
			    cct_gotoxy(21, 11 - b[0]);
			cout << plate_num;
			break;
		case 'c':
		case 'C':
			if (choice == 8 || choice == 9)
				cct_gotoxy(31, DEEP + 11 - c[0]);
			else
			    cct_gotoxy(31, 11 - c[0]);
			cout << plate_num;
			break;
		default:
			break;
	}
}





/*-------------------下列为汉诺塔伪图形相关的函数------------------*/
//伪图形输出
void tower_draw(char begin, char end, int level, int choice, int speed)
{
	if (choice == 6 || choice == 7)
	{
		cct_cls();
		cout << "从 " << begin << " 移动到 " << end << "，共" << setw(2) << level << " 层" << endl;
	}

	column_draw(begin, end, level, choice);
	if (choice >= 6)
		init_disk_draw(begin, level);

}

//画汉诺塔的柱子
void column_draw(char begin, char end, int level, int choice)
{
	cct_gotoxy(1, 16);
	cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);
	cout << setw(23) << ' ';
	cct_gotoxy(33, 16);
	cout << setw(23) << ' ';
	cct_gotoxy(65, 16);
	cout << setw(23) << ' ';

	for (int i = 15; i > 3; i--)
	{
		cct_gotoxy(12, i);
		cout << ' ';
		cct_gotoxy(44, i);
		cout << ' ';
		cct_gotoxy(76, i);
		cout << ' ';

		Sleep(300);
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

//画初始状态的圆盘
void init_disk_draw(char begin, int level)
{
	for (int i = 1; i <= level; i++)
	{
		switch (begin)
		{
			case 'a':
			case 'A':
				//cct_showch(12-a[i],16-i,' ', find_color(a[i]), find_color(a[i]),2*a[i]+1);
				cct_gotoxy(12 - a[i], 16 - i);
				cct_setcolor(find_color(a[i]), find_color(a[i]));
				for (int j = 0; j < 2 * a[i] + 1; j++)
					cout << ' ';
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cct_gotoxy(0, 20);
				break;
			case 'b':
			case 'B':
				cct_gotoxy(44 - b[i], 16 - i);
				cct_setcolor(find_color(b[i]), find_color(b[i]));
				for (int j = 0; j < 2 * b[i] + 1; j++)
					cout << ' ';
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cct_gotoxy(0, 20);
				break;
			case 'c':
			case 'C':
				cct_gotoxy(76 - c[i], 16 - i);
				cct_setcolor(find_color(c[i]), find_color(c[i]));
				for (int j = 0; j < 2 * c[i] + 1; j++)
					cout << ' ';
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cct_gotoxy(0, 20);
				break;
			default:
				break;
		}
	}
}

//根据坐标移动圆盘
void disk_move_xy(int x1, int y1, int x2, int y2, int disk_size, int speed)
{
	int bg_color = find_color(disk_size);
	int fg_color = bg_color;
	int height = move_height(x1);

	for (int i = 0; i <= height; i++) {    //从x1，y1上移
		cct_showch(x1, y1 - i, ' ', COLOR_BLACK, COLOR_WHITE, disk_size);
		cct_showch(x1 + disk_size, y1 - i, ' ', COLOR_HYELLOW, COLOR_HYELLOW);
		cct_showch(x1 + disk_size + 1, y1 - i, ' ', COLOR_BLACK, COLOR_WHITE, disk_size);

		cct_showch(x1, y1 - i - 1, ' ', bg_color, fg_color, 2 * disk_size + 1);
		Sleep((6 - speed) * 30);
	}
	for (int i = height + 1; i < y1 - 1; i++) {
		cct_showch(x1, y1 - i, ' ', COLOR_BLACK, COLOR_WHITE, 2 * disk_size + 3);
		cct_showch(x1, y1 - i - 1, ' ', bg_color, fg_color, 2 * disk_size + 1);
		Sleep((6 - speed) * 30);
	}

	if (x1 <= x2)           //平行移动
		for (int i = x1; i < x2; i++) {
			cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * disk_size + 3);
			cct_showch(i + 1, 1, ' ', bg_color, fg_color, 2 * disk_size + 1);
			Sleep((6 - speed) * 10);
		}
	else
		for (int i = x1; i > x2; i--) {
			cct_showch(i, 1, ' ', COLOR_BLACK, COLOR_WHITE, 2 * disk_size + 3);
			cct_showch(i - 1, 1, ' ', bg_color, fg_color, 2 * disk_size + 1);
			Sleep((6 - speed) * 10);
		}

	for (int j = 1; j < 4; j++) {//垂直移动到（x2,y2）
		cct_showch(x2, j, ' ', COLOR_BLACK, COLOR_WHITE, 2 * disk_size + 1);
		cct_showch(x2, j + 1, ' ', bg_color, fg_color, 2 * disk_size + 1);
		Sleep((6 - speed) * 30);
	}
	for (int j = 4; j < y2; j++) {
		cct_showch(x2, j, ' ', COLOR_BLACK, COLOR_WHITE, disk_size);
		cct_showch(x2 + disk_size, j, ' ', COLOR_HYELLOW, COLOR_HYELLOW);
		cct_showch(x2 + disk_size + 1, j, ' ', COLOR_BLACK, COLOR_WHITE, disk_size);

		cct_showch(x2, j + 1, ' ', bg_color, fg_color, disk_size);
		cct_showch(x2 + disk_size, j + 1, ' ', bg_color, fg_color);
		cct_showch(x2 + disk_size + 1, j + 1, ' ', bg_color, fg_color, disk_size);
		Sleep((6 - speed) * 30);
	}
}




/*-------------------下列为自定义的伪图形工具函数------------------*/
//根据圆盘大小确定颜色
int find_color(int color_num)
{
	switch (color_num)
	{
		case 1:
			return COLOR_HBLUE;
		case 2:
			return COLOR_HGREEN;
		case 3:
			return COLOR_PINK;
		case 4:
			return COLOR_HRED;
		case 5:
			return COLOR_HPINK;
		case 6:
			return COLOR_CYAN;
		case 7:
			return COLOR_BLUE;
		case 8:
			return COLOR_GREEN;
		case 9:
			return COLOR_RED;
		case 10:
			return COLOR_PINK;
		default:
			return COLOR_RED;
	}
}

//计算圆盘移动位置
void disk_move(char begin, char end, int choice, int speed)
{
	int x1(0), y1(0), x2(0), y2(0), disk_size(0);

	switch (end)//计算终止位置
	{
		case 'a':
		case 'A':
			y2 = 16 - a[0];
			disk_size = a[a[0]];
			x2 = 12 - disk_size;
			break;
		case 'b':
		case 'B':
			y2 = 16 - b[0];
			disk_size = b[b[0]];
			x2 = 44 - disk_size;
			break;
		case 'c':
		case 'C':
			y2 = 16 - c[0];
			disk_size = c[c[0]];
			x2 = 76 - disk_size;
			break;
	}
	switch (begin)//计算起始位置
	{
		case 'a':
		case 'A':
			y1 = 15 - a[0];
			x1 = 12 - disk_size;
			break;
		case 'b':
		case 'B':
			y1 = 15 - b[0];
			x1 = 44 - disk_size;
			break;
		case 'c':
		case 'C':
			y1 = 15 - c[0];
			x1 = 76 - disk_size;
			break;
	}
	disk_move_xy(x1, y1, x2, y2, disk_size, speed);

	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_gotoxy(0, 20);
}

//判断用户输入的移动是否合法
int is_correct(char begin, char end)
{
	int error = 0;
	int disk_size = 0;
	switch (begin)   //判断源柱是否为空
	{
		case 'a':
		case 'A':
			if (a[0] == 0)
				error = 1;
			else
				disk_size = a[a[0]];
			break;
		case 'b':
		case 'B':
			if (b[0] == 0)
				error = 1;
			else
				disk_size = b[b[0]];
			break;
		case 'c':
		case 'C':
			if (c[0] == 0)
				error = 1;
			else
				disk_size = c[c[0]];
			break;
	}

	switch (end) //判断是否大盘压小盘
	{
		case 'a':
		case 'A':
			if (a[0] != 0 && a[a[0]] < disk_size)
				error = 2;
			break;
		case 'b':
		case 'B':
			if (b[0] != 0 && b[b[0]] < disk_size)
				error = 2;
			break;
		case 'c':
		case 'C':
			if (c[0] != 0 && c[c[0]] < disk_size)
				error = 2;
			break;
	}

	if (error != 0)
	{
		cct_gotoxy(0, 37);
		if (error == 1)
			cout << "源柱为空！";
		else if (error == 2)
			cout << "大盘压小盘，非法移动!";
		Sleep(1000);
		cct_gotoxy(0, 37);
		cout << setw(30) << ' ';
		return 0;
	}
	else
	{
		array_move(begin, end);
		return 1;
	}
}

//判断游戏是否胜利
int game_win(char begin,char end,int level)
{
	int p = 0;
	switch (begin)
	{
		case 'a':
		case 'A':
			if (a[0] == 0)
				p++;
			break;
		case 'b':
		case 'B':
			if (b[0] == 0)
				p++;
			break;
		case 'c':
		case 'C':
			if (c[0] == 0)
				p++;
			break;
	}
	switch (end)
	{
		case 'a':
		case 'A':
			if (a[0] == level)
				p++;
			break;
		case 'b':
		case 'B':
			if (b[0] == level)
				p++;
			break;
		case 'c':
		case 'C':
			if (c[0] == level)
				p++;
			break;
	}

	if (p == 2)
		return 1;
	else
		return 0;
}
