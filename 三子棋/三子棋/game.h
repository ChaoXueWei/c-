#define ROW 3//行
#define COL 3//列
void menu();
void initBoard(char board[][COL]);//初始化棋盘
void printBoard(char arr[][COL]);//大厅棋盘
char leapWin(char board[][COL]);//判断输赢
bool boardFull(char board[][COL]);//判断棋盘是否放满
void comMove(char board[][COL]);//电脑走棋
void player(char board[][COL]);//玩家走棋

