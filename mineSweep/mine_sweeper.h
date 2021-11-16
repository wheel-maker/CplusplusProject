
/*-------------------------------------------*/
/*             菜单相关的函数                */
/*-------------------------------------------*/
int menu();
int dif_menu();

/*-------------------------------------------*/
/*            游戏的辅助功能函数             */
/*-------------------------------------------*/
void update(int a[][30], int m, int s, int t, int para);
void fun_output(int a[][30], int m, int n, int tag[][30], int order = 0, int mark[][30] = 0);
char explain(int m);
void time_out(time_t begin);
void graphic_first_line(int n, int order = 0);
void fun(int order, time_t begin);
void mouce_test(int m, int n);
void MinesGenerate(int a[][30], int m, int n, int SUM);
void mines_generate(int a[][30], int m, int n, int SUM, int s, int t);
void position_judge(int& x, int& y, int X, int Y, int m, int n);
void graphic_mark(int x, int y, int tag[][30], int mark[][30], int m);
void result_judge(int m, int n, int SUM, int found, time_t begin);

/*-------------------------------------------*/
/*          不同功能的地雷游戏函数           */
/*-------------------------------------------*/
void fun_display(int a[][30], int m, int n, int order);
void fun_2_map_first(int a[][30], int m, int n, int SUM, int s, int t);
void fun_2_display(int a[][30], int m, int n, int s, int t, int tag[][30]);

void fun_3_map_times(int a[][30], int m, int n, int SUM, int i, int j, int tag[][30]);
void fun_3_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found);

void fun_4_mark(int a[][30], int m, int n, int tag[][30], int mark[][30], char x);
void fun_4_map_times(int a[][30], int m, int n, int SUM, int i, int j, int tag[][30]);
void fun_4_map_update(int a[][30], int m, int n, int SUM, int tag[][30], int& found, time_t begin, int mark[][30]);

void fun_5_output(int a[][30], int m, int n, int order = 0);

void fun_7_mine_first(int a[][30], int m, int n, int SUM, int s, int t);
void fun_7_display(int a[][30], int m, int n, int s, int t, int tag[][30]);

void fun_8_display(int a[][30], int m, int n, int s, int t, int tag[][30], int mark[][30], int para = 0);
void fun_8_mine_first(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found);
void fun_8_mine_game(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found);

void fun_9_mine_first(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found, int& mines);
void fun_9_mine_game(int a[][30], int m, int n, int SUM, int s, int t, int tag[][30], int mark[][30], int& found, int& mines);
void fun_9_mark(int x, int y, int m, int n, int SUM, int mark[][30], int tag[][30], int& mines);

/*-------------------------------------------*/
/*            不同功能的函数实现             */
/*-------------------------------------------*/
void fun_1_mine_map(int a[][30], int m, int n, int SUM);
void fun_2_mine_map(int a[][30], int m, int n, int SUM);
void fun_3_mine_map(int a[][30], int m, int n, int SUM);
void fun_4_mine_map(int a[][30], int m, int n, int SUM, time_t begin);
void fun_5_mine_map(int a[][30], int m, int n, int SUM);
void fun_7_mine_map(int a[][30], int m, int n, int SUM);
void fun_8_mine_map(int a[][30], int m, int n, int SUM);
void fun_9_mine_map(int a[][30], int m, int n, int SUM, time_t begin);
