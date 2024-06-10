#include"Gobang.h"
void draw()
{
	cleardevice();
	drawBoard();
	drawChess();
	FlushBatchDraw();
}
void drawBoard()
{
	switch (bg)
	{
	case Customizebg_png:
		loadimage(NULL, _T(".\\bg.png"), 600, 600);
		break;
	case Customizebg_jpg:
		loadimage(NULL, _T(".\\bg.jpg"), 600, 600);
		break;
	case bg1:
		loadimage(NULL, _T(".\\bg1.png"), 600, 600);
		break;
	case bg2:
		loadimage(NULL, _T(".\\bg2.png"), 600, 600);
		break;
	case bg3:
		loadimage(NULL, _T(".\\bg3.png"), 600, 600);
		break;
	case bg4:
		loadimage(NULL, _T(".\\bg4.png"), 600, 600);
		break;
	case bg5:
		loadimage(NULL, _T(".\\bg5.png"), 600, 600);
		break;
	}
	for (int i = 1; i <= 21; i++)
	{
		line(30, i * block, 570, i * block);
		line(i * block, 30, i * block, 570);
	}
	setfillcolor(BLACK);
	solidcircle(10 * block, 10 * block, 4);
	solidcircle(4 * block, 4 * block, 4);
	solidcircle(4 * block, 10 * block, 4);
	solidcircle(4 * block, 16 * block, 4);
	solidcircle(16 * block, 4 * block, 4);
	solidcircle(16 * block, 10 * block, 4);
	solidcircle(16 * block, 16 * block, 4);
	solidcircle(10 * block, 4 * block, 4);
	solidcircle(10 * block, 16 * block, 4);
	_tcscpy_s(font.lfFaceName, _T("Adobe 黑体 Std"));
	font.lfHeight = 16;
	settextstyle(&font);
	TCHAR s[] = _T("A");
	TCHAR c[3];
	for (int i = 0; i < 19; i++)
	{
		outtextxy(25 + i * block, 580, s);
		s[0]++;
		_stprintf_s(c, _T("%d"), i + 1);
		outtextxy(10, 563 - i * block, c);
	}
}
void drawChess()
{
	for (int i = 0; i < Gobang.size(); i++)
	{
		if (i % 2)
		{
			setfillcolor(WHITE);
		}
		else
		{
			setfillcolor(BLACK);
		}
		solidcircle(Gobang[i].x * block, Gobang[i].y * block, 14);
	}
}
void drawkeysetMenu()
{
	IMAGE on, off;
	loadimage(&on, _T(".\\on.png"), 120, 50);
	loadimage(&off, _T(".\\off.png"), 120, 50);
	cleardevice();
	loadimage(NULL, _T(".\\keyset.png"), 600, 600);
	if (LeftClick)putimage(370, 80, &on);
	else putimage(370, 80, &off);
	if (RightClick)putimage(370, 180, &on);
	else putimage(370, 180, &off);
	if (Repentance)putimage(370, 280, &on);
	else putimage(370, 280, &off);
	if (GiveUp)putimage(370, 380, &on);
	else putimage(370, 380, &off);
	if (Ctrl)putimage(370, 480, &on);
	else putimage(370, 480, &off);
	FlushBatchDraw();
}
void drawbgsetMenu()
{
	cleardevice();
	loadimage(NULL, _T(".\\bgset.png"), 600, 600);
	_tcscpy_s(font.lfFaceName, _T("楷体"));
	font.lfHeight = 60;
	settextstyle(&font);
	TCHAR s[9];
	switch (bg)
	{
	case Customizebg_png:
		_stprintf_s(s, _T("当前背景：自定义"));
		break;
	case bg1:
		_stprintf_s(s, _T("当前背景：预设1"));
		break;
	case bg2:
		_stprintf_s(s, _T("当前背景：预设2"));
		break;
	case bg3:
		_stprintf_s(s, _T("当前背景：预设3"));
		break;
	case bg4:
		_stprintf_s(s, _T("当前背景：预设4"));
		break;
	case bg5:
		_stprintf_s(s, _T("当前背景：预设5"));
		break;
	}
	outtextxy(70, 50, s);
	FlushBatchDraw();
}
void drawbgmsetMenu()
{
	cleardevice();
	IMAGE fs;
	if (FS)loadimage(&fs, _T(".\\on.png"), 120, 50);
	else loadimage(&fs, _T(".\\off.png"), 120, 50);
	loadimage(NULL, _T(".\\bgmset.png"), 600, 600);
	putimage(380, 490, &fs);
	_tcscpy_s(font.lfFaceName, _T("楷体"));
	font.lfHeight = 60;
	settextstyle(&font);
	TCHAR s[9];
	switch (bgm)
	{
	case off:
		_stprintf_s(s, _T("当前音乐：已关闭"));
		break;
	case Customizebgm:
		_stprintf_s(s, _T("当前音乐：自定义"));
		break;
	case bgm1:
		_stprintf_s(s, _T("当前音乐：预设1"));
		break;
	case bgm2:
		_stprintf_s(s, _T("当前音乐：预设2"));
		break;
	case bgm3:
		_stprintf_s(s, _T("当前音乐：预设3"));
		break;
	case bgm4:
		_stprintf_s(s, _T("当前音乐：预设4"));
		break;
	default:
		break;
	}
	outtextxy(70, 50, s);
	FlushBatchDraw();
}