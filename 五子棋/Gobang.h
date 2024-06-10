#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include <graphics.h>
#include <conio.h>
#include<vector>
#include<time.h>
#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

const int block = 30;
enum MODE{ Two_player, Single_player_block, Single_player_white };
enum BG { Customizebg_png, Customizebg_jpg, bg1, bg2, bg3, bg4, bg5 };
enum BGM{ off, Customizebgm, bgm1, bgm2, bgm3, bgm4 };
enum STATE{ OFF, ON };
enum AI { easy, normal, difficulty };
enum INTERNET { single, server, client };
struct Point
{
	int x, y;
};
struct PointValue
{
	vector<Point> P;
	int V;
};
extern MODE mode;
extern BG bg;
extern BGM bgm;
extern STATE RightClick, LeftClick, Repentance, GiveUp, Ctrl, FS;
extern AI ai;
extern INTERNET internet;
extern LOGFONT font;
extern vector<Point> Gobang;
extern SOCKET opponent, Server;

void draw();
void drawBoard();
void drawChess();
void drawkeysetMenu();
void drawbgsetMenu();
void drawbgmsetMenu();

void checkClick();
bool winJudge(Point l);
void GameOver(int x, bool Draw = true);
Point selfPlay();
Point opponentPlay();
void easyAI();
void easyCalculateScore(int x, int y);
void normalAI();
void normalCalculateScore(int x, int y);
void playBGM();
void playFallSound();
void difficultAI();
void difficultCalculateScore(int x, int y);
PointValue getMinMaxEvaluate(int depth);

void StartMenu();
void SetUpMenu();
void keysetMenu();
void bgsetMenu();
bool DifficultySet();
bool DoubleModeSet();
void bgDefault(BG x);
void bgCustomize();
void bgmsetMenu();
void bgmCustomize();
bool ServerMenu();
bool ClientMenu();
void falseMenu();
const char* tranIP(wchar_t* ip);