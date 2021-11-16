
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

	/*窗口设置*/
	cct_setconsoleborder(100, 30, 100, 30);
	cct_setfontsize("新宋体", 27, 12);

	/*菜单选择*/
	while (choice = menu())
	{
		fun(choice, begin);

		cout << "按回车键继续...";
		while (_getch() != 13);

		cct_setconsoleborder(100, 30, 100, 30);
		cct_setfontsize("新宋体", 27, 12);

	}
	cout << endl;

	return 0;
}
