#include"Gobang.h"
int humanScore[19][19] = {}, aiScore[19][19] = {};
int ifBlack=3;
void checkClick()
{
	ExMessage m;
	Point l;
	while (true)
	{
		if (internet)
		{
			if (ifBlack == 3)
			{
				if (internet == server)ifBlack = 0;
				else ifBlack = 1;
			}
			if (ifBlack == 0)
			{
				if (winJudge(selfPlay()))continue;
				ifBlack = 2;
			}
			if (winJudge(opponentPlay()))continue;
			if (winJudge(selfPlay()))continue;
		}
		else
		{
			m = getmessage(EX_MOUSE | EX_WINDOW | EX_KEY);
			if (m.message == WM_LBUTTONDOWN && LeftClick || m.message == WM_RBUTTONDOWN && RightClick)
			{
				l.x = (m.x + 15) / block;
				l.y = (m.y + 15) / block;
				int judge = 1;
				if (l.x == 0 || l.x == 20 || l.y == 0 || l.y == 20)judge = 0;
				else
				{
					for (int i = 0; i < Gobang.size(); i++)
					{
						if (Gobang[i].x == l.x && Gobang[i].y == l.y)
						{
							judge = 0;
							break;
						}
					}
				}
				if (judge)
				{
					Gobang.push_back(l);
					if (FS)playFallSound();
					draw();
					if (winJudge(l))continue;
					if (mode)
					{
						switch (ai)
						{
						case easy:
							easyAI();
							break;
						case normal:
							normalAI();
							break;
						case difficulty:
							difficultAI();
							break;
						}
						draw();
						winJudge(Gobang[Gobang.size() - 1]);
					}
				}
			}
			else if (m.message == WM_KEYDOWN)
			{
				if (m.vkcode == VK_CONTROL || Ctrl == OFF)
				{
					m = getmessage(EX_KEY);
					if (m.vkcode == 0x5A && Repentance)
					{
						if (mode == Two_player && Gobang.size())Gobang.pop_back();
						else if (mode && Gobang.size() && Gobang.size() != 1)
						{
							Gobang.pop_back();
							Gobang.pop_back();
						}
						draw();
					}
					else if (m.vkcode == 0x51 && GiveUp)
					{
						GameOver(Gobang.size() % 2);
					}
				}
			}
			else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)draw();
		}
	}
}
bool winJudge(Point l)
{
	int judge = 1, j;
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x - i == Gobang[j].x && l.y == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x + i == Gobang[j].x && l.y == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	if (judge >= 5)
	{
		GameOver(Gobang.size() % 2);
		return true;
	}
	else judge = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x == Gobang[j].x && l.y - i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x == Gobang[j].x && l.y + i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	if (judge >= 5)
	{
		GameOver(Gobang.size() % 2);
		return true;
	}
	else judge = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x - i == Gobang[j].x && l.y - i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x + i == Gobang[j].x && l.y + i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	if (judge >= 5)
	{
		GameOver(Gobang.size() % 2);
		return true;
	}
	else judge = 1;
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x - i == Gobang[j].x && l.y + i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	for (int i = 1; i <= 5; i++)
	{
		for (j = Gobang.size() % 2 ? 0 : 1; j < Gobang.size(); j += 2)
		{
			if (l.x + i == Gobang[j].x && l.y - i == Gobang[j].y)
			{
				judge++;
				break;
			}
		}
		if (j >= Gobang.size())break;
	}
	if (judge >= 5)
	{
		GameOver(Gobang.size() % 2);
		return true;
	}
	if (Gobang.size() == 361)
	{
		GameOver(0, false);
		return true;
	}
	return false;
}
void GameOver(int x, bool Draw)
{
	cleardevice();
	loadimage(NULL, _T(".\\gameoverbg.png"), 600, 600);
	_tcscpy_s(font.lfFaceName, _T("华文新魏"));
	font.lfHeight = 90;
	settextstyle(&font);
	RECT r = { 100, 60, 500, 150 };
	if (x && Draw)drawtext(_T("黑方胜出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	else if (Draw)drawtext(_T("白方胜出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	else drawtext(_T("黑白和棋"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	FlushBatchDraw();
	ExMessage m;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN)
		{
			if (m.x >= 150 && m.x <= 450 && m.y >= 190 && m.y <= 280)
			{
				Gobang.clear();
				if (mode == Single_player_block)
				{
					mode = Single_player_white;
					normalAI();
				}
				else if (mode == Single_player_white)mode = Single_player_block;
				if (ifBlack == 2)ifBlack = 1;
				else if (ifBlack == 1)ifBlack = 0;
				draw();
				return;
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 320 && m.y <= 410)
			{
				cleardevice();
				drawBoard();
				drawChess();
				_tcscpy_s(font.lfFaceName, _T("华文楷体"));
				font.lfHeight = 20;
				settextstyle(&font);
				TCHAR s[] = _T("点击任意处再来一局");
				outtextxy(220, 5, s);
				FlushBatchDraw();
				while (true)
				{
					m = getmessage(EX_MOUSE | EX_WINDOW);
					if (m.message == WM_LBUTTONDOWN || m.message == WM_RBUTTONDOWN)
					{
						Gobang.clear();
						if (mode == Single_player_block)
						{
							mode = Single_player_white;
							normalAI();
						}
						else if (mode == Single_player_white)mode = Single_player_block;
						if (ifBlack == 2)ifBlack = 1;
						else if (ifBlack == 1)ifBlack = 0;
						draw();
						return;
					}
					else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
					{
						cleardevice();
						drawBoard();
						drawChess();
						TCHAR s[] = _T("点击任意处再来一局");
						outtextxy(220, 5, s);
						FlushBatchDraw();
					}
				}
			}
			else if (m.x >= 150 && m.x <= 450 && m.y >= 450 && m.y <= 540)
			{
				if (internet)
				{
					if(internet==server)closesocket(Server);
					else closesocket(opponent);
					WSACleanup();
					internet = single;
					ifBlack = 3;
				}
				Gobang.clear();
				StartMenu();
				return;
			}
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)
		{
			cleardevice();
			loadimage(NULL, _T(".\\gameoverbg.png"), 600, 600);
			RECT r = { 100, 60, 500, 150 };
			if (x)drawtext(_T("黑方胜出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			else drawtext(_T("白方胜出"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			FlushBatchDraw();
		}
	}
}
Point selfPlay()
{
	char buff[2];
	ExMessage m;
	Point l;
	while (true)
	{
		m = getmessage(EX_MOUSE | EX_WINDOW | EX_KEY);
		if (m.message == WM_LBUTTONDOWN && LeftClick || m.message == WM_RBUTTONDOWN && RightClick)
		{
			l.x = (m.x + 15) / block;
			l.y = (m.y + 15) / block;
			int judge = 1;
			if (l.x == 0 || l.x == 20 || l.y == 0 || l.y == 20)judge = 0;
			else
			{
				for (int i = 0; i < Gobang.size(); i++)
				{
					if (Gobang[i].x == l.x && Gobang[i].y == l.y)
					{
						judge = 0;
						break;
					}
				}
			}
			if (judge)
			{
				Gobang.push_back(l);
				buff[0] = l.x;
				buff[1] = l.y;
				send(opponent, buff, 2, NULL);
				if (FS)playFallSound();
				draw();
				return l;
			}
		}
		else if (m.message == WM_KEYDOWN)
		{
			
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)draw();
	}
}
Point opponentPlay()
{
	char buff[2];
	ExMessage m;
	Point l;
	while (true)
	{
		int r = recv(opponent, buff, 2, NULL);
		if (r > 0)
		{
			l.x = buff[0];
			l.y = buff[1];
			Gobang.push_back(l);
			if (FS)playFallSound();
			draw();
			return l;
		}
		m = getmessage(EX_MOUSE | EX_WINDOW);
		if (m.message == WM_LBUTTONDOWN && LeftClick || m.message == WM_RBUTTONDOWN && RightClick)
		{
			
		}
		else if (m.message == WM_KEYDOWN)
		{
			
		}
		else if (m.message == WM_ACTIVATE || m.message == WM_MOVE)draw();
	}
}
void playBGM()
{
	mciSendString(_T("close BGM"), 0, 0, 0);
	switch (bgm)
	{
	case off:
		break;
	case Customizebgm:
		mciSendString(_T("open .\\bgm.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		break;
	case bgm1:
		mciSendString(_T("open .\\bgm1.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		break;
	case bgm2:
		mciSendString(_T("open .\\bgm2.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		break;
	case bgm3:
		mciSendString(_T("open .\\bgm3.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		break;
	case bgm4:
		mciSendString(_T("open .\\bgm4.mp3 alias BGM"), 0, 0, 0);
		mciSendString(_T("play BGM repeat"), 0, 0, 0);
		break;
	}
}
void playFallSound()
{
	mciSendString(_T("close FS"), 0, 0, 0);
	mciSendString(_T("open .\\FallSound.mp3 alias FS"), 0, 0, 0);
	mciSendString(_T("play FS"), 0, 0, 0);
}
void easyAI()
{
	int k;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			for (k = 0; k < Gobang.size(); k++)
			{
				if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
			}
			humanScore[i][j] = 0;
			aiScore[i][j] = 0;
			if (k == Gobang.size())easyCalculateScore(i + 1, j + 1);
		}
	}
	int tem = 0;
	vector<Point>max;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (tem == humanScore[i][j] + aiScore[i][j])max.push_back({ i + 1,j + 1 });
			else if (tem < humanScore[i][j] + aiScore[i][j])
			{
				tem = humanScore[i][j] + aiScore[i][j];
				max.clear();
				max.push_back({ i + 1,j + 1 });
			}
		}
	}
	if (Gobang.size() == 0)Gobang.push_back({ 10,10 });
	else Gobang.push_back(max[rand() % max.size()]);
}
void easyCalculateScore(int x, int y)
{
	int j, p = 7;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(p, i);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(p, i);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, i);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, i);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
}
void normalAI()
{
	int k;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			for (k = 0; k < Gobang.size(); k++)
			{
				if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
			}
			humanScore[i][j] = 0;
			aiScore[i][j] = 0;
			if (k == Gobang.size())normalCalculateScore(i + 1, j + 1);
		}
	}
	int tem = 0;
	vector<Point>max;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (tem == humanScore[i][j] + aiScore[i][j])max.push_back({ i + 1,j + 1 });
			else if (tem < humanScore[i][j] + aiScore[i][j])
			{
				tem = humanScore[i][j] + aiScore[i][j];
				max.clear();
				max.push_back({ i + 1,j + 1 });
			}
		}
	}
	if (Gobang.size() == 0)Gobang.push_back({ 10,10 });
	else Gobang.push_back(max[rand() % max.size()]);
}
void normalCalculateScore(int x, int y)
{
	int j, w = 10, p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(w, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(w, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(10, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(10, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
}
void difficultAI()
{
	if (Gobang.size() == 0)Gobang.push_back({ 10,10 });
	else 
	{
		PointValue result = getMinMaxEvaluate(1);
		Gobang.push_back(result.P[rand()% result.P.size()]);
	}
}
void difficultCalculateScore(int x, int y)
{
	int j, wh = 10, wa = 10, p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)break;
				else humanScore[x - 1][y - 1] += pow(wh, p++);
			}
			else
			{
				if (mode == Single_player_block)humanScore[x - 1][y - 1] += pow(wh, p++);
				else break;
			}
		}
		else
		{
			humanScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 0 || y + i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	p = 1;
	for (int i = 1; i <= 5; i++)
	{
		if (x - i == 0 || y + i == 20)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x - i && Gobang[j].y == y + i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
	for (int i = 1; i <= 5; i++)
	{
		if (x + i == 20 || y - i == 0)break;
		for (j = 0; j < Gobang.size(); j++)
		{
			if (Gobang[j].x == x + i && Gobang[j].y == y - i)break;
		}
		if (j < Gobang.size())
		{
			if (j % 2)
			{
				if (mode == Single_player_block)aiScore[x - 1][y - 1] += pow(wa, p++);
				else break;
			}
			else
			{
				if (mode == Single_player_block)break;
				else aiScore[x - 1][y - 1] += pow(wa, p++);
			}
		}
		else
		{
			aiScore[x - 1][y - 1] += 5;
			break;
		}
	}
}
PointValue getMinMaxEvaluate(int depth)
{
	PointValue output;
	if (depth)
	{
		int k;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				for (k = 0; k < Gobang.size(); k++)
				{
					if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
				}
				if (k == Gobang.size())
				{
					humanScore[i][j] = 0;
					aiScore[i][j] = 0;
					difficultCalculateScore(i + 1, j + 1);
					int Score = aiScore[i][j] + humanScore[i][j];
					Gobang.push_back({ i + 1,j + 1 });
					PointValue tem = getMinMaxEvaluate(depth - 1);
					/*if (mode == Single_player_block)
					{
						if (Gobang.size() % 2)
						{
							output.V = INT_MAX;
							if (output.V > tem.V + Score)
							{
								output = tem;
								output.V += Score;
							}
							else if (tem.V == output.V)output.P.push_back({ i + 1,j + 1 });
						}
						else
						{
							output.V = INT_MIN;
							if (output.V < tem.V + Score)
							{
								output = tem;
								output.V += Score;
							}
							else if (tem.V == output.V)output.P.push_back({ i + 1,j + 1 });
						}
					}
					else
					{
						if (Gobang.size() % 2)
						{
							output.V = INT_MIN;
							if (output.V < tem.V + Score)
							{
								output = tem;
								output.V += Score;
							}
							else if (tem.V == output.V)output.P.push_back({ i + 1,j + 1 });
						}
						else
						{
							output.V = INT_MAX;
							if (output.V > tem.V + Score)
							{
								output = tem;
								output.V += Score;
							}
							else if (tem.V == output.V)output.P.push_back({ i + 1,j + 1 });
						}
					}*/
					output.V = 0;
					if (output.V < tem.V + Score)
					{
						output = tem;
						output.V += Score;
					}
					else if (output.V == tem.V)output.P.push_back({ i + 1,j + 1 });
					Gobang.pop_back();
				}
			}
		}
	}
	else
	{
		int k;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				for (k = 0; k < Gobang.size(); k++)
				{
					if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
				}
				humanScore[i][j] = 0;
				aiScore[i][j] = 0;
				if (k == Gobang.size())difficultCalculateScore(i + 1, j + 1);
			}
		}
		/*if (mode == Single_player_block)
		{
			if (Gobang.size() % 2)
			{
				output.V = INT_MIN;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						if (output.V < aiScore[i][j] + humanScore[i][j])
						{
							output.V = aiScore[i][j] + humanScore[i][j];
							output.P.clear();
							output.P.push_back({ i + 1,j + 1 });
						}
						else if (output.V == aiScore[i][j] + humanScore[i][j])output.P.push_back({ i + 1,j + 1 });
					}
				}
			}
			else
			{
				output.V = INT_MAX;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						if (output.V > aiScore[i][j] + humanScore[i][j])
						{
							output.V = aiScore[i][j] + humanScore[i][j];
							output.P.clear();
							output.P.push_back({ i + 1,j + 1 });
						}
						else if (output.V == aiScore[i][j] + humanScore[i][j])output.P.push_back({ i + 1,j + 1 });
					}
				}
			}
		}
		else
		{
			if (Gobang.size() % 2)
			{
				output.V = INT_MAX;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						if (output.V > aiScore[i][j] + humanScore[i][j])
						{
							output.V = aiScore[i][j] + humanScore[i][j];
							output.P.clear();
							output.P.push_back({ i + 1,j + 1 });
						}
						else if (output.V == aiScore[i][j] + humanScore[i][j])output.P.push_back({ i + 1,j + 1 });
					}
				}
			}
			else
			{
				output.V = INT_MIN;
				for (int i = 0; i < 19; i++)
				{
					for (int j = 0; j < 19; j++)
					{
						if (output.V < aiScore[i][j] + humanScore[i][j])
						{
							output.V = aiScore[i][j] + humanScore[i][j];
							output.P.clear();
							output.P.push_back({ i + 1,j + 1 });
						}
						else if (output.V == aiScore[i][j] + humanScore[i][j])output.P.push_back({ i + 1,j + 1 });
					}
				}
			}
		}*/
		output.V = 0;
		for (int i = 0; i < 19; i++)
		{
			for (int j = 0; j < 19; j++)
			{
				if (output.V < aiScore[i][j] + humanScore[i][j])
				{
					output.V = aiScore[i][j] + humanScore[i][j];
					output.P.clear();
					output.P.push_back({ i + 1,j + 1 });
				}
				else if (output.V == aiScore[i][j] + humanScore[i][j])output.P.push_back({ i + 1,j + 1 });
			}
		}
	}
	return output;
}