
#define DEEP 18
/* -----------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ----------------------------------------- */

    
 /**工具相关函数**/
int menu();
int input_para(char* begin, char* middle, char* end);
void hanoi_initial(char begin,int level);
int is_correct(char begin, char end);

/**汉诺塔相关的实现**/
void hanoi_tower(int choice);
void hanoi_move(char begin, char middle, char end, int level, int choice, int speed);
void hanoi_tower_game(char begin, char middle, char end, int level);

/**输出相关函数**/
void move_output(int plate_num, char begin, char end, int level=10, int choice=9,int speed=5);
void tower_routput();
void tower_coutput(int plate_num, char begin, char end,int choice);
void hanoi_init_output(char begin, char end, int level, int choice,int speed=5);

/**伪图形输出相关的函数**/
void tower_draw(char begin, char end, int level, int choice,int speed=5);
void column_draw(char begin, char end, int level, int choice);
void init_disk_draw(char begin, int level);
void disk_move(char begin, char end,int choice,int speed=5);
void disk_move_xy(int x1, int y1, int x2, int y2, int disk_size,int speed);

/*伪图形工具函数*/
int find_color(int color_num);
int move_height(int x);
int game_win(char begin, char end,int level);
