#include<vector>
using namespace std;

struct Point
{
	int x, y;
};

int Score[19][19] = {};//记录分数
vector<Point> Gobang;//记录落子

void AI()
{
	int k;

	//遍历整个棋盘
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			//判断（i，j）处是否已落子
			for (k = 0; k < Gobang.size(); k++)
			{
				if (Gobang[k].x == i + 1 && Gobang[k].y == j + 1)break;
			}

			//初始化此处的分数为0
			Score[i][j] = 0;

			//若（i，j）处未落子，则计算此处分数
			if (k == Gobang.size())CalculateScore(i + 1, j + 1);
		}
	}

	//打完分后遍历整个棋盘，寻找分数最高处
	int tem = 0;
	vector<Point>max;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (tem == Score[i][j])max.push_back({ i + 1,j + 1 });
			else if (tem < Score[i][j])
			{
				tem = Score[i][j];
				max.clear();
				max.push_back({ i + 1,j + 1 });
			}
		}
	}

	//落子
	if (Gobang.size() == 0)Gobang.push_back({ 10,10 });//棋盘无子时，默认落子中间
	else Gobang.push_back(max[rand() % max.size()]);//分数最高的位置有多个时，随机选择一处落子
}
void CalculateScore(int x, int y)
{
	//声明搜索的方向
	Point Vector[] = { {1,0},{0,1},{1,1},{1,-1} };

	int j, counter, w = 10;
	for (int k = 0; k < 4; k++)
	{
		//搜索该方向上有几个白子
		counter = 1;
		//朝反方向搜索
		for (int i = 1; i <= 5; i++)
		{
			//判断是否到边界
			if (x - i * Vector[k].x == 0 || y - i * Vector[k].y == 0 || x - i * Vector[k].x == 20 || y - i * Vector[k].y == 20)break;
			
			//判断此处是否有子
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x - i * Vector[k].x && Gobang[j].y == y - i * Vector[k].y)break;
			}

			if (j < Gobang.size())//此处有子
			{
				if (j % 2)break;//此处为白子
				else Score[x - 1][y - 1] += pow(w, counter++);//此处为黑子
			}
			else//此处无子
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
		//朝正方向搜索
		for (int i = 1; i <= 5; i++)
		{
			//判断是否到边界
			if (x + i * Vector[k].x == 0 || y + i * Vector[k].y == 0 || x + i * Vector[k].x == 20 || y + i * Vector[k].y == 20)break;
			
			//判断此处是否有子
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x + i * Vector[k].x && Gobang[j].y == y + i * Vector[k].y)break;
			}

			if (j < Gobang.size())//此处有子
			{
				if (j % 2)break;//此处为白子
				else Score[x - 1][y - 1] += pow(w, counter++);//此处为黑子
			}
			else//此处无子
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}

		//搜索该方向上有几个黑子
		counter = 1;
		//朝反方向搜索
		for (int i = 1; i <= 5; i++)
		{
			//判断是否到边界
			if (x - i * Vector[k].x == 0 || y - i * Vector[k].y == 0 || x - i * Vector[k].x == 20 || y - i * Vector[k].y == 20)break;

			//判断此处是否有子
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x - i * Vector[k].x && Gobang[j].y == y - i * Vector[k].y)break;
			}

			if (j < Gobang.size())//此处有子
			{
				if (j % 2)Score[x - 1][y - 1] += pow(w, counter++);//此处为白子
				else break;//此处为黑子
			}
			else//此处无子
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
		//朝正方向搜索
		for (int i = 1; i <= 5; i++)
		{
			//判断是否到边界
			if (x + i * Vector[k].x == 0 || y + i * Vector[k].y == 0 || x + i * Vector[k].x == 20 || y + i * Vector[k].y == 20)break;

			//判断此处是否有子
			for (j = 0; j < Gobang.size(); j++)
			{
				if (Gobang[j].x == x + i * Vector[k].x && Gobang[j].y == y + i * Vector[k].y)break;
			}

			if (j < Gobang.size())//此处有子
			{
				if (j % 2)Score[x - 1][y - 1] += pow(w, counter++);//此处为白子
				else break;//此处为黑子
			}
			else//此处无子
			{
				Score[x - 1][y - 1] += 5;
				break;
			}
		}
	}
}