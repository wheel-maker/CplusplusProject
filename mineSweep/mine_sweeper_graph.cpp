
#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  �������ƣ�fun_5_mine_map
  ��    �ܣ�αͼ�ν�������
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_5_mine_map(int a[][30], int m, int n, int SUM)
{
	/*���ô�����ʽ*/
	cct_setfontsize("Terminal", 16, 8);
	if (m == 9)
		cct_setconsoleborder(59, 35, 59, 35);
	else if (n == 16)
		cct_setconsoleborder(101, 56, 101, 56);
	else
		cct_setconsoleborder(185, 56, 185, 56);

	graphic_first_line(n);

	/*����ɨ������*/
	MinesGenerate(a, m, n, SUM);

	/*ѭ�����ɨ�׵�ͼ*/
	fun_5_output(a, m, n, 5);

	cout << endl << endl << endl;
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}
void fun_5_output(int a[][30], int m, int n, int order)
{
	for (int row = 0; row < m; row++)
	{
		/*�����һ��*/
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "  ";
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "�U";
		for (int col = 0; col < n; col++)
		{
			if (order == 5)
				cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			else
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
			cout << "    ";
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
		}
		cout << endl;

		/*����ڶ���*/
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << char('A' + row) << ' ';
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << "�U";
		for (int col = 0; col < n; col++)
		{
			if (order == 5)
				cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			else
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
			cout << ' ';
			if (a[row][col] == -1)
				cout << '*';
			else if (a[row][col] == 0)
				cout << ' ';
			else                    //�����׵����Ҫƥ����ɫ�͸���
			{
				if (order == 5)
					cct_setcolor(COLOR_WHITE, COLOR_BLACK);
				else
					cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << a[row][col];
			}
			if (order == 5)
				cct_setcolor(COLOR_WHITE, COLOR_BLACK);
			else
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
			cout << "  ";
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			cout << "�U";
		}
		cout << endl;

		/*���������*/
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "  ";
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		if (row != m - 1)
		{
			cout << "�d";
			for (int col = 0; col < n - 1; col++)
				cout << "�T�T�p";
			cout << "�T�T�g";
		}
		else
		{
			cout << "�^";
			for (int col = 0; col < n - 1; col++)
				cout << "�T�T�m";
			cout << "�T�T�a";
		}
		cout << endl;
	}
}

/***************************************************************************
  �������ƣ�mouce_test
  ��    �ܣ�������ĺϷ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void mouce_test(int m, int n)
{
	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]";
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT)
		{
			/*ת������ӡ*/
			cct_gotoxy(10, 3 * m + 3);

			int x = 0;
			int y = 0;

			if (X % 6 == 4)
				x = (X + 2) / 6;
			if (X % 6 == 5)
				x = (X + 1) / 6;
			if (X % 6 == 0)
				x = X / 6;
			if (X % 6 == 1)
				x = (X - 1) / 6;

			if (Y % 3 == 1)
				y = (Y - 1) / 3;
			if (Y % 3 == 0)
				y = Y / 3;

			if (x >= 1 && x <= n && y >= 1 && y <= m)
				cout << char('A' + y - 1) << "��" << x - 1 << "��    ";
			else
				cout << "λ�÷Ƿ�";

			if (maction == MOUSE_LEFT_BUTTON_CLICK)
				break;
		}
	}
	cout << endl << endl << endl;
}

/***************************************************************************
  �������ƣ�fun_7_mine_map
  ��    �ܣ�αͼ�ν����ɨ�׵�һ��
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_7_mine_map(int a[][30], int m, int n, int SUM)
{
	/*���ô�����ʽ*/
	cct_setfontsize("Terminal", 16, 8);
	if (m == 9)
		cct_setconsoleborder(59, 35, 59, 35);
	else if (n == 16)
		cct_setconsoleborder(101, 56, 101, 56);
	else
		cct_setconsoleborder(185, 56, 185, 56);

	/*�����һ��*/
	graphic_first_line(n);

	fun_5_output(a, m, n);

	/*������ɫ*/
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);

	cout << "[��ǰ���]";
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int x = 0;
	int y = 0;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);
	while (loop)
	{
		int X = 0, Y = 0;
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT)
		{
			position_judge(x, y, X, Y, m, n);

			/*����������¼�*/
			if (maction == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (x >= 1 && x <= n && y >= 1 && y <= m)
				{
					fun_7_mine_first(a, m, n, SUM, y - 1, x - 1);
					break;
				}
			}
		}
	}
	cout << endl << endl << endl;
}
//���ݵ������ɨ������
void fun_7_mine_first(int a[][30], int m, int n, int SUM, int s, int t)
{
	/*���ݵ��λ������ɨ������*/
	int i;
	int j;
	int tag[16][30];
	int sum = 1;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			tag[i][j] = 0;

	mines_generate(a, m, n, SUM, s, t);

	fun_7_display(a, m, n, s, t, tag);

	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]" << char('A' + s) << "��" << t << "��    ";

}
//�ݹ���
void fun_7_display(int a[][30], int m, int n, int s, int t, int tag[][30])
{
	int i = s;
	int j = t;
	tag[i][j]++;

	update(a, m, s, t, 1);

	/*�ݹ�������ģ��*/
	if (!a[i][j] && tag[i][j] == 1)
	{
		if (i - 1 >= 0 && j - 1 >= 0)
			fun_7_display(a, m, n, i - 1, j - 1, tag);
		if (i - 1 >= 0)
			fun_7_display(a, m, n, i - 1, j, tag);
		if (i - 1 >= 0 && j + 1 < n)
			fun_7_display(a, m, n, i - 1, j + 1, tag);

		if (j - 1 >= 0)
			fun_7_display(a, m, n, i, j - 1, tag);
		if (j + 1 < n)
			fun_7_display(a, m, n, i, j + 1, tag);

		if (i + 1 < m && j - 1 >= 0)
			fun_7_display(a, m, n, i + 1, j - 1, tag);
		if (i + 1 < m)
			fun_7_display(a, m, n, i + 1, j, tag);
		if (i + 1 < m && j + 1 < n)
			fun_7_display(a, m, n, i + 1, j + 1, tag);
	}

	/*������ɫ*/
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

/***************************************************************************
  �������ƣ�fun_8_mine_map
  ��    �ܣ�αͼ�ν����ɨ����Ϸ�������棩
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_8_mine_map(int a[][30], int m, int n, int SUM)
{
	int mark[16][30];
	for (int h = 0; h < 16; h++)
		for (int k = 0; k < 30; k++)
			mark[h][k] = 0;

	/*���ô�����ʽ*/
	cct_setfontsize("Terminal", 16, 8);
	if (m == 9)
		cct_setconsoleborder(59, 35, 59, 35);
	else if (n == 16)
		cct_setconsoleborder(101, 56, 101, 56);
	else
		cct_setconsoleborder(185, 56, 185, 56);

	graphic_first_line(n, 8);

	fun_5_output(a, m, n);

	/*������ɫ*/
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);

	cout << "[��ǰ���]";
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int x = 0;
	int y = 0;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);
	int found = 0;
	int tag[16][30];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tag[i][j] = 0;
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT)
		{
			position_judge(x, y, X, Y, m, n);

			/*����������¼�*/
			if (maction == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (x >= 1 && x <= n && y >= 1 && y <= m)//�Ϸ�λ��
				{
					if (found == 0)
						fun_8_mine_first(a, m, n, SUM, y - 1, x - 1, tag, mark, found);
					else
						fun_8_mine_game(a, m, n, SUM, y - 1, x - 1, tag, mark, found);

					if (found == SUM || found == SUM - m * n)
						break;
				}
			}
			else if (maction == MOUSE_RIGHT_BUTTON_CLICK)
				if (x >= 1 && x <= n && y >= 1 && y <= m)//�Ϸ�λ��
					graphic_mark(x, y, tag, mark, m);
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if (keycode1 == 27)
			{
				cout << endl;
				break;
			}

		}
	}

	/*��Ϸʧ��*/
	if (found == SUM)
	{
		/*������ɫ*/
		cct_gotoxy(0, 3 * m + 3);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "�����ˣ���Ϸ����" << endl;
	}

	if (found == SUM - m * n)
	{
		cct_gotoxy(10, 3 * m + 3);
		cout << "��ϲʤ������Ϸ����" << endl;
	}
}
//���ݵ������ɨ������(��ӱ��)
void fun_8_mine_first(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found)
{
	mines_generate(a, m, n, SUM, s, t);

	fun_8_display(a, m, n, s, t, tag, mark, 1);

	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]" << char('A' + s) << "��" << t << "��    ";

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[k][h])
				found++;
}
//������̬����ɨ������
void fun_8_mine_game(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found)
{

	if (!mark[s][t] && a[s][t] == -1)
	{
		tag[s][t]++;
		fun_8_display(a, m, n, s, t, tag, mark);
		found = SUM;
		return;
	}

	/*DFS*/
	fun_8_display(a, m, n, s, t, tag, mark);
	found = 0;

	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]" << char('A' + s) << "��" << t << "��    ";

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[k][h])
				found++;
}
//�ݹ���
void fun_8_display(int a[][30], int m, int n, int s, int t, int tag[][30], int mark[][30], int para)
{
	if (mark[s][t])
		return;
	int i = s;
	int j = t;
	tag[i][j]++;

	update(a, m, s, t, para);

	/*�ݹ�������ģ��*/
	if (!a[i][j] && tag[i][j] == 1)
	{
		if (i - 1 >= 0 && j - 1 >= 0)
			fun_8_display(a, m, n, i - 1, j - 1, tag, mark, para);
		if (i - 1 >= 0)
			fun_8_display(a, m, n, i - 1, j, tag, mark, para);
		if (i - 1 >= 0 && j + 1 < n)
			fun_8_display(a, m, n, i - 1, j + 1, tag, mark, para);

		if (j - 1 >= 0)
			fun_8_display(a, m, n, i, j - 1, tag, mark, para);
		if (j + 1 < n)
			fun_8_display(a, m, n, i, j + 1, tag, mark, para);

		if (i + 1 < m && j - 1 >= 0)
			fun_8_display(a, m, n, i + 1, j - 1, tag, mark, para);
		if (i + 1 < m)
			fun_8_display(a, m, n, i + 1, j, tag, mark, para);
		if (i + 1 < m && j + 1 < n)
			fun_8_display(a, m, n, i + 1, j + 1, tag, mark, para);
	}

	/*������ɫ*/
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

/***************************************************************************
  �������ƣ�fun_9_mine_map
  ��    �ܣ�αͼ�ν����ɨ����Ϸ�������棩
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void fun_9_mine_map(int a[][30], int m, int n, int SUM, time_t begin)
{
	time_t end = clock();
	int mark[16][30];
	int mines = SUM;
	for (int h = 0; h < 16; h++)
		for (int k = 0; k < 30; k++)
			mark[h][k] = 0;

	/*���ô�����ʽ*/
	cct_setfontsize("Terminal", 16, 8);
	if (m == 9)
		cct_setconsoleborder(59, 35, 59, 35);
	else if (n == 16)
		cct_setconsoleborder(101, 56, 101, 56);
	else
		cct_setconsoleborder(185, 56, 185, 56);

	graphic_first_line(n, 9);

	fun_5_output(a, m, n);

	/*������ɫ*/
	cct_setcolor(COLOR_BLACK, COLOR_WHITE);

	cout << "[��ǰ���]";
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;
	int x = 0;
	int y = 0;

	cct_enable_mouse();

	cct_setcursor(CURSOR_INVISIBLE);
	int found = 0;
	int tag[16][30];

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			tag[i][j] = 0;
	while (loop)
	{
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);

		if (ret == CCT_MOUSE_EVENT)
		{
			position_judge(x, y, X, Y, m, n);
			/*����������¼�*/
			if (maction == MOUSE_LEFT_BUTTON_CLICK)
			{
				if (x >= 1 && x <= n && y >= 1 && y <= m)//�Ϸ�λ��
				{
					if (found == 0)
						fun_9_mine_first(a, m, n, SUM, y - 1, x - 1, tag, mark, found, mines);
					else
						fun_9_mine_game(a, m, n, SUM, y - 1, x - 1, tag, mark, found, mines);

					if (found == SUM || found == SUM - m * n)
						break;
				}
			}
			else if (maction == MOUSE_RIGHT_BUTTON_CLICK)
			{
				if (x >= 1 && x <= n && y >= 1 && y <= m)//�Ϸ�λ��
					fun_9_mark(x, y, m, n, SUM, mark, tag, mines);
			}
		}
		else if (ret == CCT_KEYBOARD_EVENT)
		{
			if (keycode1 == 27)
			{
				cout << endl;
				break;
			}
			else if (keycode1 == 32)
			{
				end = clock();
				cct_gotoxy(0, 0);
				cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
				cout << "��ǰʱ�䣺" << double(end - begin) / CLOCKS_PER_SEC << "�룬";
				cct_setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "Esc�˳����ո���ʾʱ��";
				cct_gotoxy(10, 3 * m + 3);
			}

		}
	}

	result_judge(m, n, SUM, found, begin);
}
//��Ϸ����ж�
void result_judge(int m, int n, int SUM, int found, time_t begin)
{
	time_t end;
	/*��Ϸʧ��*/
	if (found == SUM)
	{
		/*������ɫ*/
		cct_gotoxy(0, 3 * m + 3);
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);

		end = clock();
		cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
		cout << "����ʱ��" << double(end - begin) / CLOCKS_PER_SEC << "�룬";
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "�����ˣ���Ϸ����" << endl;
	}

	if (found == SUM - m * n)
	{
		cct_gotoxy(10, 3 * m + 3);
		end = clock();
		cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
		cout << "����ʱ��" << double(end - begin) / CLOCKS_PER_SEC << "�룬";
		cct_setcolor(COLOR_BLACK, COLOR_WHITE);
		cout << "��ϲʤ������Ϸ����" << endl;
	}
}
//���±�Ǻ���
void fun_9_mark(int x, int y, int m, int n, int SUM, int mark[][30], int tag[][30], int& mines)
{
	if (x >= 1 && x <= n && y >= 1 && y <= m)//�Ϸ�λ��
	{
		if (!mark[y - 1][x - 1] && tag[y - 1][x - 1] == 0)
		{
			if (mines > 0)
				mines--;
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
			cout << "ʣ��������" << mines << ',';
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << "Esc�˳����ո���ʾʱ��    ";
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
			if (mines < SUM)
				mines++;
			cct_gotoxy(0, 0);
			cct_setcolor(COLOR_BLACK, COLOR_YELLOW);
			cout << "ʣ��������" << mines << ',';
			cct_setcolor(COLOR_BLACK, COLOR_WHITE);
			cout << "Esc�˳����ո���ʾʱ��    ";
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
}
//���ݵ������ɨ������(��ӱ��)
void fun_9_mine_first(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found, int& mines)
{
	mines_generate(a, m, n, SUM, s, t);

	fun_8_display(a, m, n, s, t, tag, mark, 1);

	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]" << char('A' + s) << "��" << t << "��    ";

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[k][h])
				found++;
}
//������̬����ɨ������
void fun_9_mine_game(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found, int& mines)
{
	if (!mark[s][t] && a[s][t] == -1)
	{
		tag[s][t]++;
		fun_8_display(a, m, n, s, t, tag, mark);
		found = SUM;
		return;
	}

	/*DFS*/
	fun_8_display(a, m, n, s, t, tag, mark);
	found = 0;

	cct_gotoxy(0, 3 * m + 3);
	cout << "[��ǰ���]" << char('A' + s) << "��" << t << "��    ";

	for (int k = 0; k < m; k++)
		for (int h = 0; h < n; h++)
			if (tag[k][h])
				found++;
}
