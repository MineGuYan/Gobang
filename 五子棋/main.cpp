#include"Gobang.h"
MODE mode;
BG bg;
BGM bgm;
STATE RightClick, LeftClick, Repentance, GiveUp, Ctrl, FS;
AI ai;
INTERNET internet;
LOGFONT font;
vector<Point> Gobang;
int main()
{
	bg = bg1;
	bgm = off;
	LeftClick = ON;
	RightClick = OFF;
	Repentance = ON;
	GiveUp = ON;
	Ctrl = ON;
	FS = ON;
	internet = single;
	srand(time(0));
	initgraph(600, 600);
	gettextstyle(&font);
	font.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&font);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);
	setlinecolor(BLACK);
	BeginBatchDraw();
	StartMenu();
	checkClick();
}