
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：fun
  功    能：根据order的参数值确定调用函数的类型
  输入参数：参数order
  返 回 值：
  说    明：
***************************************************************************/
void fun(int order, time_t begin)
{
	int a[16][30];

	/*初始化*/
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 30; j++)
			a[i][j] = 0;
	}

	/*难度菜单*/
	switch (dif_menu())
	{
		case 1:
			switch (order)
			{
				case 1:fun_1_mine_map(a, 9, 9, 10);
					break;
				case 2:fun_2_mine_map(a, 9, 9, 10);
					break;
				case 3:fun_3_mine_map(a, 9, 9, 10);
					break;
				case 4:fun_4_mine_map(a, 9, 9, 10, begin);
					break;
				case 5:fun_5_mine_map(a, 9, 9, 10);
					break;
				case 6:fun_5_mine_map(a, 9, 9, 10);
					mouce_test(9, 9);
					break;
				case 7:fun_7_mine_map(a, 9, 9, 10);
					break;
				case 8:fun_8_mine_map(a, 9, 9, 10);
					break;
				case 9:fun_9_mine_map(a, 9, 9, 10, begin);
					break;
			}
			break;
		case 2:
			switch (order)
			{
				case 1:fun_1_mine_map(a, 16, 16, 40);
					break;
				case 2:fun_2_mine_map(a, 16, 16, 40);
					break;
				case 3:fun_3_mine_map(a, 16, 16, 40);
					break;
				case 4:fun_4_mine_map(a, 16, 16, 40, begin);
					break;
				case 5:fun_5_mine_map(a, 16, 16, 40);
					break;
				case 6:fun_5_mine_map(a, 16, 16, 40);
					mouce_test(16, 16);
					break;
				case 7:fun_7_mine_map(a, 16, 16, 40);
					break;
				case 8:fun_8_mine_map(a, 16, 16, 40);
					break;
				case 9:fun_9_mine_map(a, 16, 16, 40, begin);
					break;
			}
			break;
		case 3:
			switch (order)
			{
				case 1:fun_1_mine_map(a, 16, 30, 99); break;
				case 2:fun_2_mine_map(a, 16, 30, 99); break;
				case 3:fun_3_mine_map(a, 16, 30, 99); break;
				case 4:fun_4_mine_map(a, 16, 30, 99, begin); break;
				case 5:fun_5_mine_map(a, 16, 30, 99); break;
				case 6:fun_5_mine_map(a, 16, 30, 99);
					mouce_test(16, 30); break;
				case 7:fun_7_mine_map(a, 16, 30, 99); break;
				case 8:fun_8_mine_map(a, 16, 30, 99); break;
				case 9:fun_9_mine_map(a, 16, 30, 99, begin); break;
			}
			break;
		default:
			cout << "系统错误！";
			break;
	}
}

/***************************************************************************
  函数名称：MinesGenerate
  功    能：生成地雷数组(仅适用于第一个和第5个)
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void MinesGenerate(int a[][30], int m, int n, int SUM)
{
	int i;
	int j;
	int sum = 1;

	/*生成SUM个雷*/
	while (sum <= SUM)
	{
		i = rand() % m;
		j = rand() % n;

		while (a[i][j] == -1)//如果该位置是雷重新生成
		{
			i = rand() % m;
			j = rand() % n;
		}
		a[i][j] = -1;

		sum++;
	}

	/*生成周围雷数*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
			{
				/*上一行*/
				if (i - 1 > 0)
				{
					if (j - 1 > 0 && a[i - 1][j - 1] >= 0)
						a[i - 1][j - 1]++;
					if (a[i - 1][j] >= 0)
						a[i - 1][j]++;
					if (j + 1 < n && a[i - 1][j + 1] >= 0)
						a[i - 1][j + 1]++;
				}

				/*中间一行*/
				if (j - 1 > 0 && a[i][j - 1] >= 0)
					a[i][j - 1]++;
				if (j + 1 < n && a[i][j + 1] >= 0)
					a[i][j + 1]++;

				/*下一行*/
				if (i + 1 < m)
				{
					if (j - 1 > 0 && a[i + 1][j - 1] >= 0)
						a[i + 1][j - 1]++;
					if (a[i + 1][j] >= 0)
						a[i + 1][j]++;
					if (j + 1 < n && a[i + 1][j + 1] >= 0)
						a[i + 1][j + 1]++;
				}
			}
		}
}

/***************************************************************************
  函数名称：mines_generate
  功    能：生成地雷数组
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void mines_generate(int a[][30], int m, int n, int SUM, int s, int t)
{
	int i;
	int j;
	int sum = 1;

	/*生成SUM个雷*/
	while (sum <= SUM)
	{
		i = rand() % m;
		j = rand() % n;

		while (a[i][j] == -1
			|| (i == s - 1 && j == t - 1) || (i == s - 1 && j == t) || (i == s - 1 && j == t + 1)
			|| (i == s && j == t - 1) || (i == s && j == t) || (i == s && j == t + 1)
			|| (i == s + 1 && j == t - 1) || (i == s + 1 && j == t) || (i == s + 1 && j == t + 1))
		{
			i = rand() % m;
			j = rand() % n;
		}
		a[i][j] = -1;

		sum++;
	}

	/*生成周围雷数*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
			{
				/*上一行*/
				if (i - 1 > 0)
				{
					if (j - 1 > 0 && a[i - 1][j - 1] >= 0)
						a[i - 1][j - 1]++;
					if (a[i - 1][j] >= 0)
						a[i - 1][j]++;
					if (j + 1 < n && a[i - 1][j + 1] >= 0)
						a[i - 1][j + 1]++;
				}

				/*中间一行*/
				if (j - 1 > 0 && a[i][j - 1] >= 0)
					a[i][j - 1]++;
				if (j + 1 < n && a[i][j + 1] >= 0)
					a[i][j + 1]++;

				/*下一行*/
				if (i + 1 < m)
				{
					if (j - 1 > 0 && a[i + 1][j - 1] >= 0)
						a[i + 1][j - 1]++;
					if (a[i + 1][j] >= 0)
						a[i + 1][j]++;
					if (j + 1 < n && a[i + 1][j + 1] >= 0)
						a[i + 1][j + 1]++;
				}
			}
		}
}

/***************************************************************************
  函数名称：fun_display
  功    能：内部数组的输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_display(int a[][30], int m, int n, int order)
{
	cout << "内部数组：" << endl;
	cout << "  |";
	for (int i = 1; i <= n; i++)
		if (i < 10)
			cout << i << ' ';
		else
			cout << char(i - 10 + 'a') << ' ';
	cout << endl;
	cout << "--+";
	for (int i = 0; i < n + 1; i++)
		cout << "--";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < n; j++)
			if (order == 1)
				if (a[i][j] != -1)
					cout << a[i][j] << ' ';
				else
					cout << "* ";
			else if (order == 2 || order == 3 || order == 4)
				cout << "X ";
		cout << endl;
	}
	cout << endl;

}

/***************************************************************************
  函数名称：fun_2_display
  功    能：递归显示初始位置的地雷图
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_2_display(int a[][30], int m, int n, int s, int t, int tag[][30])
{
	int i = s;
	int j = t;
	if (a[s][t] != -1)
		tag[i][j]++;

	if (!a[i][j] && tag[i][j] == 1)
	{
		if (i - 1 >= 0 && j - 1 >= 0)
			fun_2_display(a, m, n, i - 1, j - 1, tag);
		if (i - 1 >= 0)
			fun_2_display(a, m, n, i - 1, j, tag);
		if (i - 1 >= 0 && j + 1 < n)
			fun_2_display(a, m, n, i - 1, j + 1, tag);

		if (j - 1 >= 0)
			fun_2_display(a, m, n, i, j - 1, tag);
		if (j + 1 < n)
			fun_2_display(a, m, n, i, j + 1, tag);

		if (i + 1 < m && j - 1 >= 0)
			fun_2_display(a, m, n, i + 1, j - 1, tag);
		if (i + 1 < m)
			fun_2_display(a, m, n, i + 1, j, tag);
		if (i + 1 >= 0 && j + 1 < n)
			fun_2_display(a, m, n, i + 1, j + 1, tag);
	}

}
/***************************************************************************
  函数名称：fun_output
  功    能：实时输出变化后的地雷图
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_output(int a[][30], int m, int n, int tag[][30], int order, int mark[][30])
{
	cout << endl << endl;
	cout << "点开后的数组：" << endl;
	cout << "  |";
	for (int i = 1; i <= n; i++)
		if (i < 10)
			cout << i << ' ';
		else
			cout << char(i - 10 + 'a') << ' ';
	cout << endl;
	cout << "--+";
	for (int i = 0; i < n + 1; i++)
		cout << "--";
	cout << endl;
	for (int i = 0; i < m; i++)
	{
		cout << char(i + 'A') << " |";
		for (int j = 0; j < n; j++)
			if (tag[i][j])
			{
				cct_setcolor(6, a[i][j]);
				cout << a[i][j];
				cct_setcolor(0, 7);
				cout << ' ';
			}
			else
			{
				if (order == 4 && mark[i][j])
				{
					cct_setcolor(COLOR_RED, COLOR_WHITE);
					cout << 'X';
					cct_setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << ' ';
				}
				else
					cout << "X ";
			}
		cout << endl;
	}
}

/***************************************************************************
  函数名称：time_out
  功    能：输出游戏时间
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void time_out(time_t begin)
{
	time_t end = clock();
	double ret = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << endl << "已运行时间：" << ret << "秒" << endl;
}

/***************************************************************************
  函数名称：graphic_first_line
  功    能：伪图形界面第一行的输出
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void graphic_first_line(int n, int order)
{
	/*输出第一行*/
	if (order >= 8)
		cout << "按Esc键退出";
	if (order == 9)
		cout << "，空格显示时间";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(6) << i;
	cout << endl << "  ";
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "╔";
	for (int col = 0; col < n - 1; col++)
		cout << "══╦";
	cout << "══╗";
	cout << endl;
}

/***************************************************************************
  函数名称：position_judge
  功    能：伪图形界面鼠标位置判断
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void position_judge(int& x, int& y, int X, int Y, int m, int n)
{
	/*坐标转换*/
	cct_gotoxy(10, 3 * m + 3);
	if (X % 6 == 4)
		x = (X + 2) / 6;
	else if (X % 6 == 5)
		x = (X + 1) / 6;
	else if (X % 6 == 0)
		x = X / 6;
	else if (X % 6 == 1)
		x = (X - 1) / 6;
	else
		x = 0;

	if (Y % 3 == 1)
		y = (Y - 1) / 3;
	else if (Y % 3 == 0)
		y = Y / 3;
	else
		y = 0;

	if (x >= 1 && x <= n && y >= 1 && y <= m)
		cout << char('A' + y - 1) << "行" << x - 1 << "列    ";
	else
		cout << "位置非法";
}

/***************************************************************************
  函数名称：update
  功    能：伪图形界面更新图形指定块
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void update(int a[][30], int m, int s, int t, int para)
{
	/*重新刷新该地址模块*/
	cct_gotoxy(6 * t + 4, 3 * s + 3);
	cct_setcolor(COLOR_WHITE, COLOR_BLACK);
	cout << "    ";
	cct_gotoxy(6 * t + 4, 3 * s + 4);
	cout << ' ';
	cct_setcolor(COLOR_WHITE, a[s][t]);
	if (a[s][t] == -1)
	{
		cct_setcolor(COLOR_WHITE, COLOR_BLACK);
		if (para == 0)
			cout << '*';
		else
			cout << ' ';
	}
	else if (a[s][t] == 0)
		cout << ' ';
	else
		cout << a[s][t];
	cct_setcolor(COLOR_WHITE, COLOR_BLACK);
	cout << "  ";
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_gotoxy(10, 3 * m + 3);
}

/***************************************************************************
  函数名称：graphic_mark
  功    能：伪图形界面更新图形指定标记块
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void graphic_mark(int x, int y, int tag[][30], int mark[][30], int m)
{
	if (!mark[y - 1][x - 1] && tag[y - 1][x - 1] == 0)
	{
		/*标记该模块*/
		mark[y - 1][x - 1] = 1;
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 3);
		cct_setcolor(COLOR_RED, COLOR_WHITE);
		cout << "    ";
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 4);
		cout << " #  ";
	}
	else if (tag[y - 1][x - 1] == 0)
	{
		/*取消标记该模块*/
		mark[y - 1][x - 1] = 0;
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 3);
		cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
		cout << "    ";
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 4);
		cout << "    ";
	}
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
	cct_gotoxy(10, 3 * m + 3);
}
