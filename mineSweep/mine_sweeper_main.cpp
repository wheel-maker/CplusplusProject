
#include <iostream>
#include <time.h>
#include <conio.h>
#include "mine_sweeper.h"
#include "cmd_console_tools.h"
using namespace std;

int main()
{
	srand((unsigned int)(time(0)));

	time_t begin;
	begin = clock();
	int choice;

	/*��������*/
	cct_setconsoleborder(100, 30, 100, 30);
	cct_setfontsize("������", 27, 12);

	/*�˵�ѡ��*/
	while (choice = menu())
	{
		fun(choice, begin);

		cout << "���س�������...";
		while (_getch() != 13);

		cct_setconsoleborder(100, 30, 100, 30);
		cct_setfontsize("������", 27, 12);

	}
	cout << endl;

	return 0;
}
