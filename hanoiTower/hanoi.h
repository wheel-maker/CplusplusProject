
#define DEEP 18
/* -----------------------------------------

     ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
   ----------------------------------------- */

    
 /**������غ���**/
int menu();
int input_para(char* begin, char* middle, char* end);
void hanoi_initial(char begin,int level);
int is_correct(char begin, char end);

/**��ŵ����ص�ʵ��**/
void hanoi_tower(int choice);
void hanoi_move(char begin, char middle, char end, int level, int choice, int speed);
void hanoi_tower_game(char begin, char middle, char end, int level);

/**�����غ���**/
void move_output(int plate_num, char begin, char end, int level=10, int choice=9,int speed=5);
void tower_routput();
void tower_coutput(int plate_num, char begin, char end,int choice);
void hanoi_init_output(char begin, char end, int level, int choice,int speed=5);

/**αͼ�������صĺ���**/
void tower_draw(char begin, char end, int level, int choice,int speed=5);
void column_draw(char begin, char end, int level, int choice);
void init_disk_draw(char begin, int level);
void disk_move(char begin, char end,int choice,int speed=5);
void disk_move_xy(int x1, int y1, int x2, int y2, int disk_size,int speed);

/*αͼ�ι��ߺ���*/
int find_color(int color_num);
int move_height(int x);
int game_win(char begin, char end,int level);
