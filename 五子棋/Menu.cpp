#include"Gobang.h"
SOCKET opponent, Server;
void StartMenu()
{
	loadimage(NULL, _T(".\\startbg.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 210 && m.y <= 300)
			{
				if (DoubleModeSet())
				{
					mode = Two_player;
					draw();
					return;
				}
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 340 && m.y <= 430)
			{
				if (DifficultySet())
				{
					mode = Single_player_block;
					draw();
					return;
				}
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 470 && m.y <= 560)
			{
				SetUpMenu();
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\startbg.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
void SetUpMenu()
{
	cleardevice();
	loadimage(NULL, _T(".\\setupbg.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 60 && m.y <= 150)
			{
				bgsetMenu();
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 190 && m.y <= 280)
			{
				bgmsetMenu();
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 320 && m.y <= 410)
			{
				keysetMenu();
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 450 && m.y <= 540)
			{
				cleardevice();
				loadimage(NULL, _T(".\\startbg.png"), 600, 600);
				if (rand() == 0)
				{
					_tcscpy_s(font.lfFaceName, _T("Adobe 黑体 Std"));
					font.lfHeight = 16;
					settextstyle(&font);
					TCHAR s[] = _T("MADE BY ZWZ");
					outtextxy(500, 580, s);
				}
				FlushBatchDraw();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\setupbg.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
void keysetMenu()
{
	drawkeysetMenu();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 370 && m.x <= 490 && m.y >= 80 && m.y <= 130)
			{
				if (LeftClick)LeftClick = OFF;
				else LeftClick = ON;
				drawkeysetMenu();
			}
			else if (m.x >= 370 && m.x <= 490 && m.y >= 180 && m.y <= 230)
			{
				if (RightClick)RightClick = OFF;
				else RightClick = ON;
				drawkeysetMenu();
			}
			else if (m.x >= 370 && m.x <= 490 && m.y >= 280 && m.y <= 330)
			{
				if (Repentance)Repentance = OFF;
				else Repentance = ON;
				drawkeysetMenu();
			}
			else if (m.x >= 370 && m.x <= 490 && m.y >= 380 && m.y <= 430)
			{
				if (GiveUp)GiveUp = OFF;
				else GiveUp = ON;
				drawkeysetMenu();
			}
			else if (m.x >= 370 && m.x <= 490 && m.y >= 480 && m.y <= 530)
			{
				if (Ctrl)Ctrl = OFF;
				else Ctrl = ON;
				drawkeysetMenu();
			}
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				if (LeftClick || RightClick)
				{
					cleardevice();
					loadimage(NULL, _T(".\\setupbg.png"), 600, 600);
					FlushBatchDraw();
					return;
				}
				else
				{
					_tcscpy_s(font.lfFaceName, _T("华文楷体"));
					font.lfHeight = 30;
					settextstyle(&font);
					TCHAR s[] = _T("左/右键落子至少开启一个");
					outtextxy(170, 20, s);
					FlushBatchDraw();
				}
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			drawkeysetMenu();
		}
	}
}
void bgsetMenu()
{
	drawbgsetMenu();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 80 && m.x <= 240 && m.y >= 160 && m.y <= 220)bgDefault(bg1);
			else if (m.x >= 360 && m.x <= 520 && m.y >= 160 && m.y <= 220)bgDefault(bg2);
			else if (m.x >= 80 && m.x <= 240 && m.y >= 290 && m.y <= 350)bgDefault(bg3);
			else if (m.x >= 360 && m.x <= 520 && m.y >= 290 && m.y <= 350)bgDefault(bg4);
			else if (m.x >= 80 && m.x <= 240 && m.y >= 420 && m.y <= 480)bgDefault(bg5);
			else if (m.x >= 360 && m.x <= 520 && m.y >= 420 && m.y <= 480)bgCustomize();
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				cleardevice();
				loadimage(NULL, _T(".\\setupbg.png"), 600, 600);
				FlushBatchDraw();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			drawbgsetMenu();
		}
	}
}
void bgmsetMenu()
{
	drawbgmsetMenu();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 80 && m.x <= 240 && m.y >= 160 && m.y <= 220)
			{
				bgm = off;
				playBGM();
				drawbgmsetMenu();
			}
			else if (m.x >= 360 && m.x <= 520 && m.y >= 160 && m.y <= 220)
			{
				bgmCustomize();
			}
			else if (m.x >= 80 && m.x <= 240 && m.y >= 280 && m.y <= 340)
			{
				bgm = bgm1;
				playBGM();
				drawbgmsetMenu();
			}
			else if (m.x >= 360 && m.x <= 520 && m.y >= 280 && m.y <= 340)
			{
				bgm = bgm2;
				playBGM();
				drawbgmsetMenu();
			}
			else if (m.x >= 80 && m.x <= 240 && m.y >= 400 && m.y <= 460)
			{
				bgm = bgm3;
				playBGM();
				drawbgmsetMenu();
			}
			else if (m.x >= 360 && m.x <= 520 && m.y >= 400 && m.y <= 460)
			{
				bgm = bgm4;
				playBGM();
				drawbgmsetMenu();
			}
			else if (m.x >= 380 && m.x <= 500 && m.y >= 490 && m.y <= 540)
			{
				if (FS)FS = OFF;
				else FS = ON;
				drawbgmsetMenu();
			}
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				cleardevice();
				loadimage(NULL, _T(".\\setupbg.png"), 600, 600);
				FlushBatchDraw();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			drawbgmsetMenu();
		}
	}
}
bool DifficultySet()
{
	cleardevice();
	loadimage(NULL, _T(".\\mode.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 60 && m.y <= 150)
			{
				ai = easy;
				return true;
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 190 && m.y <= 280)
			{
				ai = normal;
				return true;
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 320 && m.y <= 410)
			{
				ai = difficulty;
				return true;
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 450 && m.y <= 540)
			{
				cleardevice();
				loadimage(NULL, _T(".\\startbg.png"), 600, 600);
				FlushBatchDraw();
				return false;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\mode.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
bool DoubleModeSet()
{
	cleardevice();
	loadimage(NULL, _T(".\\DoubleMode.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 60 && m.y <= 150)
			{
				internet = single;
				return true;
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 190 && m.y <= 280)
			{
				if (ServerMenu())
				{
					internet = server;
					return true;
				}
				else
				{
					falseMenu();
					return false;
				}
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 320 && m.y <= 410)
			{
				if (ClientMenu())
				{
					internet = client;
					return true;
				}
				else
				{
					falseMenu();
					return false;
				}
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 450 && m.y <= 540)
			{
				cleardevice();
				loadimage(NULL, _T(".\\startbg.png"), 600, 600);
				FlushBatchDraw();
				return false;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\DoubleMode.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
void bgDefault(BG x)
{
	BG tem = bg;
	bg = x;
	IMAGE apply, cancel;
	loadimage(&apply, _T(".\\apply.png"), 100, 40);
	loadimage(&cancel, _T(".\\cancel.png"), 100, 40);
	cleardevice();
	drawBoard();
	putimage(500, 520, &apply);
	putimage(500, 560, &cancel);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 500 && m.x <= 600 && m.y >= 520 && m.y <= 560)
			{
				drawbgsetMenu();
				return;
			}
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				bg = tem;
				drawbgsetMenu();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			drawBoard();
			putimage(500, 520, &apply);
			putimage(500, 560, &cancel);
			FlushBatchDraw();
		}
	}
}
void bgCustomize()
{
	BG tem = bg;
	bg = Customizebg_png;
	IMAGE png, jpg;
	loadimage(&png, _T(".\\png.png"), 160, 60);
	loadimage(&jpg, _T(".\\jpg.png"), 160, 60);
	cleardevice();
	loadimage(NULL, _T(".\\Customizebg.png"), 600, 600);
	if (bg == Customizebg_png)putimage(340, 310, &png);
	else if (bg == Customizebg_jpg)putimage(340, 310, &jpg);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 340 && m.x <= 500 && m.y >= 310 && m.y <= 370)
			{
				if (bg == Customizebg_png)bg = Customizebg_jpg;
				else if (bg == Customizebg_jpg)bg = Customizebg_png;
				cleardevice();
				loadimage(NULL, _T(".\\Customizebg.png"), 600, 600);
				if (bg == Customizebg_png)putimage(340, 310, &png);
				else if (bg == Customizebg_jpg)putimage(340, 310, &jpg);
				FlushBatchDraw();
			}
			else if (m.x >= 160 && m.x <= 440 && m.y >= 400 && m.y <= 460)system("start .");
			else if (m.x >= 160 && m.x <= 440 && m.y >= 490 && m.y <= 550)
			{
				IMAGE apply, cancel;
				loadimage(&apply, _T(".\\apply.png"), 100, 40);
				loadimage(&cancel, _T(".\\cancel.png"), 100, 40);
				cleardevice();
				drawBoard();
				putimage(500, 520, &apply);
				putimage(500, 560, &cancel);
				FlushBatchDraw();
				while (true)
				{
					m = getmessage(EX_MOUSE | EX_WINDOW);
					if (m.message == WM_LBUTTONDOWN)
					{
						if (m.x >= 500 && m.x <= 600 && m.y >= 520 && m.y <= 560)
						{
							drawbgsetMenu();
							return;
						}
						else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
						{
							bg = tem;
							drawbgsetMenu();
							return;
						}
					}
					else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
					{
						cleardevice();
						drawBoard();
						putimage(500, 520, &apply);
						putimage(500, 560, &cancel);
						FlushBatchDraw();
					}
				}
			}
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				bg = tem;
				drawbgsetMenu();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\Customizebg.png"), 600, 600);
			if (bg == Customizebg_png)putimage(340, 310, &png);
			else if (bg == Customizebg_jpg)putimage(340, 310, &jpg);
			FlushBatchDraw();
		}
	}
}
void bgmCustomize()
{
	cleardevice();
	loadimage(NULL, _T(".\\Customizebgm.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 160 && m.x <= 440 && m.y >= 320 && m.y <= 390)system("start .");
			else if (m.x >= 160 && m.x <= 440 && m.y >= 440 && m.y <= 510)
			{
				bgm = Customizebgm;
				playBGM();
				drawbgmsetMenu();
				return;
			}
			else if (m.x >= 500 && m.x <= 600 && m.y >= 560 && m.y <= 600)
			{
				drawbgmsetMenu();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\Customizebgm.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
bool ServerMenu()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)return false;
	
	SOCKET serverSocker = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocker == SOCKET_ERROR)
	{
		WSACleanup();
		return false;
	}

	SOCKADDR_IN addr = { 0 };
	addr.sin_family = AF_INET;
	wchar_t IP[16];
	InputBox(IP, 16, L"请输入本地IP,格式：“xxx.xxx.xxx.xxx”");
	addr.sin_addr.S_un.S_addr = inet_addr(tranIP(IP));
	//addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(25565);
	
	int r = bind(serverSocker, (struct sockaddr*)&addr, sizeof addr);
	if (r == -1)
	{
		closesocket(serverSocker);
		WSACleanup();
		return false;
	}

	r = listen(serverSocker, SOMAXCONN);
	if (r == -1)
	{
		closesocket(serverSocker);
		WSACleanup();
		return false;
	}

	_tcscpy_s(font.lfFaceName, _T("楷体"));
	font.lfHeight = 60;
	settextstyle(&font);
	TCHAR ip[16], s[] = _T("房间号：");
	_stprintf_s(ip, _T("%d"), addr.sin_addr.S_un.S_addr);
	cleardevice();
	loadimage(NULL, _T(".\\wait.png"), 600, 600);
	outtextxy(275, 300, ip);
	outtextxy(70, 300, s);
	FlushBatchDraw();

	SOCKADDR_IN Caddr = { 0 };
	int len = sizeof Caddr;
	opponent = accept(serverSocker, (sockaddr*)&Caddr, &len);
	if (opponent == SOCKET_ERROR)
	{
		closesocket(serverSocker);
		WSACleanup();
		return false;
	}
	Server = serverSocker;

	return true;
}
bool ClientMenu()
{
	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2)return false;

	SOCKET serverSocker = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocker == SOCKET_ERROR)
	{
		WSACleanup();
		return false;
	}

	SOCKADDR_IN addr = { 0 };
	wchar_t ip[16], port[6];
	/*InputBox(ip, 16, L"请输入房间IP,格式：“xxx.xxx.xxx.xxx”");
	addr.sin_addr.S_un.S_addr = inet_addr(tranIP(ip));*/
	/*InputBox(port, 6, L"请输入房间端口,格式：“xxxxx”");
	int PORT = _wtoi(port);*/
	InputBox(ip, 16, L"请输入房间号");
	addr.sin_addr.S_un.S_addr = _wtoi(ip);
	int PORT = 25565;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);

	int r = connect(serverSocker, (sockaddr*)&addr, sizeof addr);
	if (r == -1)
	{
		closesocket(serverSocker);
		WSACleanup();
		return false;
	}
	opponent = serverSocker;

	return true;
}
void falseMenu()
{
	cleardevice();
	loadimage(NULL, _T(".\\false.png"), 600, 600);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 350 && m.y <= 440)
			{
				cleardevice();
				loadimage(NULL, _T(".\\startbg.png"), 600, 600);
				FlushBatchDraw();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\false.png"), 600, 600);
			FlushBatchDraw();
		}
	}
}
const char* tranIP(wchar_t* ip)
{
	size_t L = wcslen(ip) + 1;
	size_t converted = 0;
	char* c = (char*)malloc(L * sizeof(char));
	wcstombs_s(&converted, c, L, ip, _TRUNCATE);
	return c;
}