
#include <iostream>
#include <conio.h>
#include <ctime>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�fun_1_mine_map
  ��    �ܣ����ɲ�ͬ��С�ĵ�������
  ������������飬���׹�ģ
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_1_mine_map(int a[][30], int m, int n, int SUM)
{
	cct_cls();

	MinesGenerate(a, m, n, SUM);

	fun_display(a, m, n, 1);
}

/***************************************************************************
  �������ƣ�fun_2_mine_map
  ��    �ܣ���ɵ����������ʾ
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_2_mine_map(int a[][30], int m, int n, int SUM)
{
	cct_cls();

	int i;
	int j;
	int sum = 1;

	fun_display(a, m, n, 2);

	/****���봦��****/
	cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
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
	/****���봦��****/

	/****���ɵ�������****/
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;

	fun_2_map_first(a, m, n, SUM, i, j);
	/****���ɵ�������****/
}
//����ȷ��λ��(s,t)��ֵΪ0�ĵ�ͼ
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

	/********���*******/
	fun_output(a, m, n, tag);
}

/***************************************************************************
  �������ƣ�fun_3_mine_map
  ��    �ܣ�ɨ�׵�ͼ��̬����
  ���������
  �� �� ֵ��
  ˵    ����
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

	/****���봦��****/
	cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
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
	/****���봦��****/

	/****���ɵ�������****/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tag[i][j] = 0;
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	fun_3_map_times(a, m, n, SUM, i, j, tag);
	/****���ɵ�������****/

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[h][k])
				found++;
	while (found < m * n - SUM && found >= 0)
		fun_3_map_update(a, m, n, SUM, tag, found);
	if (found == m * n)
		cout << "�����ˣ���Ϸ����" << endl;
	if (found == m * n - SUM)
		cout << "��ϲʤ������Ϸ����" << endl;
}
//ɨ�׵ĵ�һ�ε�ͼ
void fun_3_map_times(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30])
{
	mines_generate(a, m, n, SUM, s, t);

	fun_2_display(a, m, n, s, t, tag);

	fun_output(a, m, n, tag);
	cout << endl << endl;
}
//ɨ�׵�ͼ��ʵʱ����
void fun_3_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found)
{
	char x;
	char y;
	int i;
	int j;
	/****���봦��****/
	cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
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
	/****���봦��****/

	if (a[i][j] == -1)
	{
		found = m * n;
		tag[i][j]++;
	}
	else if (!a[i][j])
		fun_2_display(a, m, n, i, j, tag);
	else
		tag[i][j]++;

	/********���*******/
	if (1)
	{
		cout << endl << endl;
		cout << "��ǰ���飺" << endl;
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
  �������ƣ�fun_4_mine_map
  ��    �ܣ�ɨ�׵�ͼ��̬����
  ���������
  �� �� ֵ��
  ˵    ����
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

	/*��ʼ��*/
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
		{
			mark[i][j] = 0;
			tag[i][j] = 0;
		}

	/*���봦��*/
	fun_display(a, m, n, 4);
	cout << endl << endl;

	char x;
	char y;
	x = explain(m);
	cout << x;

	while (x == '&' || x == '!' || x == '#')
	{
		if (x == '&')/*ʱ�䴦��*/
		{
			time_out(begin);
			x = explain(m);
			cout << x;
		}
		else/*��Ǵ���*/
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
	/****���봦��****/

	/****���ɵ�������****/
	i = x - 'A';
	if (y < 'a')
		j = y - '1';
	else
		j = y - 'a' + 9;
	fun_4_map_times(a, m, n, SUM, i, j, tag);
	/****���ɵ�������****/

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[h][k])
				found++;
	while (found < m * n - SUM && found >= 0)
		fun_4_map_update(a, m, n, SUM, tag, found, begin, mark);
	if (found == m * n)
		cout << "�����ˣ���Ϸ����" << endl;
	if (found == m * n - SUM)
		cout << "��ϲʤ������Ϸ����" << endl;
}
//��Ǵ�����
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
//ɨ�׵ĵ�һ�ε�ͼ
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
				if (i == 0)           //��һ�е����
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
				else if (i == m - 1)      //���һ�е����
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
				else if (j == 0)     //��һ�бߵ����
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
				else if (j == n - 1)    //���һ�бߵ����
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
				else             //�м�����
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

	/********���*******/
	if (1)
	{
		cout << endl << endl;
		cout << "��ǰ���飺" << endl;
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
	/********���*******/

}
//ɨ�׵�ͼ��ʵʱ����
void fun_4_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found, time_t begin, int mark[][30])
{
	char x;
	char y;
	int i;
	int j;
	time_t end = clock();
	/****���봦��****/
	cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
	cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
	cout << "              # - ȡ�����      (����#E3)" << endl;
	cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
		x = _getch();
	cout << x;
	while (x == '&' || x == '!' || x == '#')
	{
		/*ʱ�䴦��*/
		if (x == '&')
		{
			end = clock();
			double ret = (double)(end - begin) / CLOCKS_PER_SEC;
			cout << endl << "������ʱ�䣺" << ret << "��" << endl;
			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
			x = _getch();
			while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
				x = _getch();
			cout << x;
		}

		/*��Ǵ���*/
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

			/********���*******/
			if (1)
			{
				cout << endl << endl;
				cout << "��ǰ���飺" << endl;
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
			/********���*******/

			cout << "��������˵����& - ��Ϸ������ʱ��(���ַ����ɣ�����Ҫ������)" << endl;
			cout << "              ! - ��Ǹ�����Ϊ��(����!E3)" << endl;
			cout << "              # - ȡ�����      (����#E3)" << endl;
			cout << "�������λ�õ��������꣨���к��У��ϸ����ִ�Сд������G1 / Af����Q / q�˳�����";
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
	/****���봦��****/

	if (a[i][j] == -1)
	{
		found = m * n;
		tag[i][j]++;
	}
	else if (!a[i][j])
		fun_2_display(a, m, n, i, j, tag);
	else
		tag[i][j]++;

	/********���*******/
	if (1)
	{
		cout << endl << endl;
		cout << "��ǰ���飺" << endl;
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

