
#include <iostream>
#include <conio.h>
#include <ctime>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：fun_1_mine_map
  功    能：生成不同大小的地雷数组
  输入参数：数组，地雷规模
  返 回 值：
  说    明：
***************************************************************************/
void fun_1_mine_map(int a[][30], int m, int n, int SUM)
{
	cct_cls();

	MinesGenerate(a, m, n, SUM);

	fun_display(a, m, n, 1);
}

/***************************************************************************
  函数名称：fun_2_mine_map
  功    能：完成地雷数组的显示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_2_mine_map(int a[][30], int m, int n, int SUM)
{
	cct_cls();

	int i;
	int j;
	int sum = 1;

	fun_display(a, m, n, 2);

	/****输入处理****/
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
	char x;
	char y;
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q')
		x = _getch();
	cout << x;
	if (x != 'Q' && x != 'q')
	{
		y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;
	}
	else
	{
		cout << endl << endl;
		return;
	}
	/****输入处理****/

	/****生成地雷数组****/
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;

	fun_2_map_first(a, m, n, SUM, i, j);
	/****生成地雷数组****/
}
//生成确定位置(s,t)处值为0的地图
void fun_2_map_first(int a[][30], int m, int n, int SUM, int s, int t)
{
	int i;
	int j;
	int tag[16][30];
	int sum = 1;

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tag[i][j] = 0;

	mines_generate(a, m, n, SUM, s, t);

	fun_2_display(a, m, n, s, t, tag);

	/********输出*******/
	fun_output(a, m, n, tag);
}

/***************************************************************************
  函数名称：fun_3_mine_map
  功    能：扫雷地图动态更新
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_3_mine_map(int a[][30], int m, int n, int SUM)
{
	cct_cls();
	int i;
	int j;
	int sum = 1;
	int tag[16][30];
	int found = 0;

	fun_display(a, m, n, 3);

	/****输入处理****/
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
	char x;
	char y;
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q')
		x = _getch();
	cout << x;
	if (x != 'Q' && x != 'q')
	{
		y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;
	}
	else
	{
		cout << endl << endl;
		return;
	}
	/****输入处理****/

	/****生成地雷数组****/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tag[i][j] = 0;
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	fun_3_map_times(a, m, n, SUM, i, j, tag);
	/****生成地雷数组****/

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[h][k])
				found++;
	while (found < m * n - SUM && found >= 0)
		fun_3_map_update(a, m, n, SUM, tag, found);
	if (found == m * n)
		cout << "你输了，游戏结束" << endl;
	if (found == m * n - SUM)
		cout << "恭喜胜利，游戏结束" << endl;
}
//扫雷的第一次地图
void fun_3_map_times(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30])
{
	mines_generate(a, m, n, SUM, s, t);

	fun_2_display(a, m, n, s, t, tag);

	fun_output(a, m, n, tag);
	cout << endl << endl;
}
//扫雷地图的实时更新
void fun_3_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found)
{
	char x;
	char y;
	int i;
	int j;
	/****输入处理****/
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q')
		x = _getch();
	cout << x;
	if (x != 'Q' && x != 'q')
	{
		y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;
	}
	else
	{
		found = -1;
		cout << endl << endl;
		return;
	}

	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	/****输入处理****/

	if (a[i][j] == -1)
	{
		found = m * n;
		tag[i][j]++;
	}
	else if (!a[i][j])
		fun_2_display(a, m, n, i, j, tag);
	else
		tag[i][j]++;

	/********输出*******/
	if (1)
	{
		cout << endl << endl;
		cout << "当前数组：" << endl;
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
					if (a[i][j] == -1)
						cout << "* ";
					else
					{
						cct_setcolor(6, a[i][j]);
						cout << a[i][j];
						cct_setcolor(0, 7);
						cout << ' ';
					}
				}
				else
					cout << "X ";
			cout << endl;
		}
		cout << endl << endl;
	}

	if (found != m * n)
	{
		found = 0;
		for (int k = 0; k < m; k++)
			for (int h = 0; h < n; h++)
				if (tag[h][k])
					found++;
	}

}

/***************************************************************************
  函数名称：fun_4_mine_map
  功    能：扫雷地图动态更新
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void fun_4_mine_map(int a[][30], int m, int n, int SUM, time_t begin)
{
	cct_cls();

	time_t end = clock();
	int i;
	int j;
	int sum = 1;
	int tag[16][30];
	int mark[16][30];
	int found = 0;

	/*初始化*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			mark[i][j] = 0;
			tag[i][j] = 0;
		}

	/*输入处理*/
	fun_display(a, m, n, 4);
	cout << endl << endl;

	char x;
	char y;
	x = explain(m);
	cout << x;

	while (x == '&' || x == '!' || x == '#')
	{
		if (x == '&')/*时间处理*/
		{
			time_out(begin);
			x = explain(m);
			cout << x;
		}
		else/*标记处理*/
			fun_4_mark(a, m, n, tag, mark, x);
	}

	if (x != 'Q' && x != 'q')
	{
		y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;
	}
	else
	{
		cout << endl << endl;
		return;
	}
	/****输入处理****/

	/****生成地雷数组****/
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	fun_4_map_times(a, m, n, SUM, i, j, tag);
	/****生成地雷数组****/

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[h][k])
				found++;
	while (found < m * n - SUM && found >= 0)
		fun_4_map_update(a, m, n, SUM, tag, found, begin, mark);
	if (found == m * n)
		cout << "你输了，游戏结束" << endl;
	if (found == m * n - SUM)
		cout << "恭喜胜利，游戏结束" << endl;
}
//标记处理函数
void fun_4_mark(int a[][30], int m, int n, int tag[][30], int mark[][30], char x)
{
	int i;
	int j;
	char mk = x;
	if (1)
	{
		x = _getch();
		while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
			x = _getch();
		cout << x;

		char y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;

		i = x - 'A';
		if (y < 'a')
			j = y - '1';
		else
			j = y - 'a' + 9;
		if (mk == '!')
			mark[i][j] = 1;
		else
			mark[i][j] = 0;
	}
	fun_output(a, m, n, tag, 4, mark);
	cout << endl << endl;
	x = explain(m);
	cout << x;
}
//扫雷的第一次地图
void fun_4_map_times(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30])
{
	int i;
	int j;
	int sum = 1;

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
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
			{
				if (i == 0)           //第一行的情况
				{
					if (j == 0)
					{
						if (a[i + 1][j] != -1)
							a[i + 1][j]++;
						if (a[i][j + 1] != -1)
							a[i][j + 1]++;
						if (a[i + 1][j + 1] != -1)
							a[i + 1][j + 1]++;
					}
					else if (j == n - 1)
					{
						if (a[i][j - 1] != -1)
							a[i][j - 1]++;
						if (a[i + 1][j - 1] != -1)
							a[i + 1][j - 1]++;
						if (a[i + 1][j] != -1)
							a[i + 1][j]++;
					}
					else
					{
						if (a[i][j - 1] != -1)
							a[i][j - 1]++;
						if (a[i + 1][j - 1] != -1)
							a[i + 1][j - 1]++;
						if (a[i + 1][j] != -1)
							a[i + 1][j]++;
						if (a[i + 1][j + 1] != -1)
							a[i + 1][j + 1]++;
						if (a[i][j + 1] != -1)
							a[i][j + 1]++;
					}
				}
				else if (i == m - 1)      //最后一行的情况
				{
					if (j == 0)
					{
						if (a[i - 1][j] != -1)
							a[i - 1][j]++;
						if (a[i][j + 1] != -1)
							a[i][j + 1]++;
						if (a[i - 1][j + 1] != -1)
							a[i - 1][j + 1]++;
					}
					else if (j == n - 1)
					{
						if (a[i - 1][j] != -1)
							a[i - 1][j]++;
						if (a[i][j - 1] != -1)
							a[i][j - 1]++;
						if (a[i - 1][j - 1] != -1)
							a[i - 1][j - 1]++;
					}
					else
					{
						if (a[i][j - 1] != -1)
							a[i][j - 1]++;
						if (a[i - 1][j - 1] != -1)
							a[i - 1][j - 1]++;
						if (a[i - 1][j] != -1)
							a[i - 1][j]++;
						if (a[i - 1][j + 1] != -1)
							a[i - 1][j + 1]++;
						if (a[i][j + 1] != -1)
							a[i][j + 1]++;
					}
				}
				else if (j == 0)     //第一列边的情况
				{
					if (a[i - 1][j] != -1)
						a[i - 1][j]++;
					if (a[i - 1][j + 1] != -1)
						a[i - 1][j + 1]++;
					if (a[i][j + 1] != -1)
						a[i][j + 1]++;
					if (a[i + 1][j + 1] != -1)
						a[i + 1][j + 1]++;
					if (a[i + 1][j] != -1)
						a[i + 1][j]++;
				}
				else if (j == n - 1)    //最后一列边的情况
				{
					if (a[i - 1][j] != -1)
						a[i - 1][j]++;
					if (a[i - 1][j - 1] != -1)
						a[i - 1][j - 1]++;
					if (a[i][j - 1] != -1)
						a[i][j - 1]++;
					if (a[i + 1][j - 1] != -1)
						a[i + 1][j - 1]++;
					if (a[i + 1][j] != -1)
						a[i + 1][j]++;
				}
				else             //中间的情况
				{
					if (a[i - 1][j - 1] != -1)
						a[i - 1][j - 1]++;
					if (a[i - 1][j] != -1)
						a[i - 1][j]++;
					if (a[i - 1][j + 1] != -1)
						a[i - 1][j + 1]++;
					if (a[i][j - 1] != -1)
						a[i][j - 1]++;
					if (a[i][j + 1] != -1)
						a[i][j + 1]++;
					if (a[i + 1][j - 1] != -1)
						a[i + 1][j - 1]++;
					if (a[i + 1][j] != -1)
						a[i + 1][j]++;
					if (a[i + 1][j + 1] != -1)
						a[i + 1][j + 1]++;
				}
			}
		}
	}

	fun_2_display(a, m, n, s, t, tag);

	/********输出*******/
	if (1)
	{
		cout << endl << endl;
		cout << "当前数组：" << endl;
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
					if (a[i][j] == -1)
						cout << "* ";
					else
					{
						cct_setcolor(6, a[i][j]);
						cout << a[i][j];
						cct_setcolor(0, 7);
						cout << ' ';
					}
				}
				else
					cout << "X ";
			cout << endl;
		}
		cout << endl << endl;
	}
	/********输出*******/

}
//扫雷地图的实时更新
void fun_4_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found, time_t begin, int mark[][30])
{
	char x;
	char y;
	int i;
	int j;
	time_t end = clock();
	/****输入处理****/
	cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
	cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
	cout << "              # - 取消标记      (例：#E3)" << endl;
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
		x = _getch();
	cout << x;
	while (x == '&' || x == '!' || x == '#')
	{
		/*时间处理*/
		if (x == '&')
		{
			end = clock();
			double ret = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << endl << "已运行时间：" << ret << "秒" << endl;
			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
			x = _getch();
			while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
				x = _getch();
			cout << x;
		}

		/*标记处理*/
		else if (x == '!' || x == '#')
		{
			char mk = x;
			if (1)
			{
				x = _getch();
				while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
					x = _getch();
				cout << x;

				y = _getch();
				if (n == 9)
					while (y < '1' || y>'9')
						y = _getch();
				else
					while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
						y = _getch();
				cout << y;

				i = x - 'A';
				if (y < 'a')
					j = y - '1';
				else
					j = y - 'a' + 9;
				if (mk == '!')
					mark[i][j] = 1;
				else
					mark[i][j] = 0;
			}

			/********输出*******/
			if (1)
			{
				cout << endl << endl;
				cout << "当前数组：" << endl;
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
							if (a[i][j] == -1)
								cout << "* ";
							else
							{
								cct_setcolor(6, a[i][j]);
								cout << a[i][j];
								cct_setcolor(0, 7);
								cout << ' ';
							}
						}
						else
						{
							if (mark[i][j])
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
				cout << endl << endl;
			}
			/********输出*******/

			cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
			cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
			cout << "              # - 取消标记      (例：#E3)" << endl;
			cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
			x = _getch();
			while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
				x = _getch();
			cout << x;
		}
	}



	if (x != 'Q' && x != 'q')
	{
		y = _getch();
		if (n == 9)
			while (y < '1' || y>'9')
				y = _getch();
		else
			while (y < '1' || (y > '9' && y < 'a') || (y >= 'a' + n - 9))
				y = _getch();
		cout << y;
	}
	else
	{
		found = -1;
		cout << endl << endl;
		return;
	}
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	/****输入处理****/

	if (a[i][j] == -1)
	{
		found = m * n;
		tag[i][j]++;
	}
	else if (!a[i][j])
		fun_2_display(a, m, n, i, j, tag);
	else
		tag[i][j]++;

	/********输出*******/
	if (1)
	{
		cout << endl << endl;
		cout << "当前数组：" << endl;
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
					if (a[i][j] == -1)
						cout << "* ";
					else
					{
						cct_setcolor(6, a[i][j]);
						cout << a[i][j];
						cct_setcolor(0, 7);
						cout << ' ';
					}
				}
				else
					cout << "X ";
			cout << endl;
		}
		cout << endl << endl;
	}

	if (found != m * n)
	{
		found = 0;
		for (int k = 0; k < m; k++)
			for (int h = 0; h < n; h++)
				if (tag[h][k])
					found++;
	}

}

