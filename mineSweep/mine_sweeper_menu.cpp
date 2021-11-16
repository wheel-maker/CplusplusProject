
#include <iostream>
#include <conio.h>
#include <ctime>
#include "cmd_console_tools.h"
#include "mine_sweeper.h"
using namespace std;

/***************************************************************************
  函数名称：menu
  功    能：调用游戏的初始菜单
  输入参数：
  返 回 值：用户的菜单选择
  说    明：
***************************************************************************/
int menu()
{
	cct_cls();
	char ch;

	cout << "------------------------------------------" << endl;
	cout << "1.选择难度并显示内部数组" << endl;
	cout << "2.输入初始位置并显示被打开的初始区域 " << endl;
	cout << "3.内部数组基础版" << endl;
	cout << "4.内部数组完整版（标记、运行时间）" << endl;
	cout << "5.画出伪图形化框架并显示内部数据" << endl;
	cout << "6.检测鼠标位置和合法性（左键单击退出）" << endl;
	cout << "7.鼠标选择初始位置并显示被打开的初始区域" << endl;
	cout << "8.伪图形界面基础版" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0.退出游戏" << endl;
	cout << "------------------------------------------" << endl;
	cout << "[请选择] :";

	while (ch = _getch())
		if (ch >= '0' && ch <= '9')
			break;

	return int(ch - '0');
}

/***************************************************************************
  函数名称：dif_menu
  功    能：调用游戏的难度菜单
  输入参数：
  返 回 值：用户的难度选择
  说    明：
***************************************************************************/
int dif_menu()
{
	cct_cls();

	char dif;

	cout << "请选择难度：" << endl;
	cout << "1.初级(9 * 9 - 10颗雷)" << endl;
	cout << "2.中级(16 * 16 - 40颗雷)" << endl;
	cout << "3.高级(16 * 30 - 99颗雷)" << endl;
	cout << "请输入[1..3]：";

	while (dif = _getch())
		if (dif >= '1' && dif <= '3')
			break;

	return int(dif - '0');
}
/***************************************************************************
  函数名称：explain
  功    能：菜单4的输出提示
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
char explain(int m)
{
	char x;
	cout << "特殊输入说明：& - 游戏已运行时间(单字符即可，不需要加坐标)" << endl;
	cout << "              ! - 标记该坐标为雷(例：!E3)" << endl;
	cout << "              # - 取消标记      (例：#E3)" << endl;
	cout << "输入非雷位置的行列坐标（先行后列，严格区分大小写，例：G1 / Af，按Q / q退出）：";
	x = _getch();
	while ((x < 'A' || x>'A' + m) && x != 'Q' && x != 'q' && x != '&' && x != '!' && x != '#')
		x = _getch();
	return x;
}
