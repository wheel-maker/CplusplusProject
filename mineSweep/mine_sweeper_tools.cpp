
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�fun
  ��    �ܣ�����order�Ĳ���ֵȷ�����ú���������
  �������������order
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun(int order, time_t begin)
{
	int a[16][30];

	/*��ʼ��*/
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 30; j++)
			a[i][j] = 0;
	}

	/*�ѶȲ˵�*/
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
			cout << "ϵͳ����";
			break;
	}
}

/***************************************************************************
  �������ƣ�MinesGenerate
  ��    �ܣ����ɵ�������(�������ڵ�һ���͵�5��)
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void MinesGenerate(int a[][30], int m, int n, int SUM)
{
	int i;
	int j;
	int sum = 1;

	/*����SUM����*/
	while (sum <= SUM)
	{
		i = rand() % m;
		j = rand() % n;

		while (a[i][j] == -1)//�����λ��������������
		{
			i = rand() % m;
			j = rand() % n;
		}
		a[i][j] = -1;

		sum++;
	}

	/*������Χ����*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
			{
				/*��һ��*/
				if (i - 1 > 0)
				{
					if (j - 1 > 0 && a[i - 1][j - 1] >= 0)
						a[i - 1][j - 1]++;
					if (a[i - 1][j] >= 0)
						a[i - 1][j]++;
					if (j + 1 < n && a[i - 1][j + 1] >= 0)
						a[i - 1][j + 1]++;
				}

				/*�м�һ��*/
				if (j - 1 > 0 && a[i][j - 1] >= 0)
					a[i][j - 1]++;
				if (j + 1 < n && a[i][j + 1] >= 0)
					a[i][j + 1]++;

				/*��һ��*/
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
  �������ƣ�mines_generate
  ��    �ܣ����ɵ�������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void mines_generate(int a[][30], int m, int n, int SUM, int s, int t)
{
	int i;
	int j;
	int sum = 1;

	/*����SUM����*/
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

	/*������Χ����*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			if (a[i][j] == -1)
			{
				/*��һ��*/
				if (i - 1 > 0)
				{
					if (j - 1 > 0 && a[i - 1][j - 1] >= 0)
						a[i - 1][j - 1]++;
					if (a[i - 1][j] >= 0)
						a[i - 1][j]++;
					if (j + 1 < n && a[i - 1][j + 1] >= 0)
						a[i - 1][j + 1]++;
				}

				/*�м�һ��*/
				if (j - 1 > 0 && a[i][j - 1] >= 0)
					a[i][j - 1]++;
				if (j + 1 < n && a[i][j + 1] >= 0)
					a[i][j + 1]++;

				/*��һ��*/
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
  �������ƣ�fun_display
  ��    �ܣ��ڲ���������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_display(int a[][30], int m, int n, int order)
{
	cout << "�ڲ����飺" << endl;
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
  �������ƣ�fun_2_display
  ��    �ܣ��ݹ���ʾ��ʼλ�õĵ���ͼ
  ���������
  �� �� ֵ��
  ˵    ����
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
  �������ƣ�fun_output
  ��    �ܣ�ʵʱ����仯��ĵ���ͼ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_output(int a[][30], int m, int n, int tag[][30], int order, int mark[][30])
{
	cout << endl << endl;
	cout << "�㿪������飺" << endl;
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
  �������ƣ�time_out
  ��    �ܣ������Ϸʱ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void time_out(time_t begin)
{
	time_t end = clock();
	double ret = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << endl << "������ʱ�䣺" << ret << "��" << endl;
}

/***************************************************************************
  �������ƣ�graphic_first_line
  ��    �ܣ�αͼ�ν����һ�е����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void graphic_first_line(int n, int order)
{
	/*�����һ��*/
	if (order >= 8)
		cout << "��Esc���˳�";
	if (order == 9)
		cout << "���ո���ʾʱ��";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << setw(6) << i;
	cout << endl << "  ";
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "�X";
	for (int col = 0; col < n - 1; col++)
		cout << "�T�T�j";
	cout << "�T�T�[";
	cout << endl;
}

/***************************************************************************
  �������ƣ�position_judge
  ��    �ܣ�αͼ�ν������λ���ж�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void position_judge(int& x, int& y, int X, int Y, int m, int n)
{
	/*����ת��*/
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
		cout << char('A' + y - 1) << "��" << x - 1 << "��    ";
	else
		cout << "λ�÷Ƿ�";
}

/***************************************************************************
  �������ƣ�update
  ��    �ܣ�αͼ�ν������ͼ��ָ����
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void update(int a[][30], int m, int s, int t, int para)
{
	/*����ˢ�¸õ�ַģ��*/
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
  �������ƣ�graphic_mark
  ��    �ܣ�αͼ�ν������ͼ��ָ����ǿ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void graphic_mark(int x, int y, int tag[][30], int mark[][30], int m)
{
	if (!mark[y - 1][x - 1] && tag[y - 1][x - 1] == 0)
	{
		/*��Ǹ�ģ��*/
		mark[y - 1][x - 1] = 1;
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 3);
		cct_setcolor(COLOR_RED, COLOR_WHITE);
		cout << "    ";
		cct_gotoxy(6 * (x - 1) + 4, 3 * (y - 1) + 4);
		cout << " #  ";
	}
	else if (tag[y - 1][x - 1] == 0)
	{
		/*ȡ����Ǹ�ģ��*/
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
