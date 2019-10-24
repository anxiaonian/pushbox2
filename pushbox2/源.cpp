#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
#define RPow 7
#define CPow 8
int map[RPow][CPow] = {
	{ 0,1,1,1,1,1,1,0 },  //0表示空地
	{ 0,1,0,0,0,0,1,1 },  //1是墙
	{ 1,1,3,1,1,4,0,1 },  //3是目的地
	{ 1,0,3,3,4,0,0,1 },  //4是箱子
	{ 1,0,0,1,4,0,0,1 },  //5是人
	{ 1,0,0,5,0,1,1,1 },
	{ 1,1,1,1,1,1,0,0 }
};

void DrawMap();
//void Game();
//void draw(IMAGE img[], int map[][CPow + 2]);
void Move();
int main() {
	//mciSendString(L"")
	//PlaySound((LPCTSTR)IDR_WAVE1, 0, SND_RESOURCE | SND_ASYNC);
	while (1) {
		system("cls");
		DrawMap();
		//   做界面670*680
		//initgraph(680, 670);
		//Game();
		_getch();
		Move();
	}
	return 0;
}
//遍历数组
void DrawMap() {
	for (int i = 0; i < RPow; i++)
	{
		for (int j = 0; j < CPow; j++) {
			//printf("%d",map[i][j]);
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("■");
				break;
			case 3:
				printf("☆");
				break;
			case 4:
				printf("□");
				break;
			case 5:
				printf("♀");
				break;
			case 7:
				printf("★");   //箱子和目的地
				break;
			case 8:
				printf("♀");    //人和目的地
				break;
				//default:
				//break;
			}
		}
		printf("\n");
	}
}

//移动
void Move() {
	char ch;
	int i, j;
	int r, c;       //人的坐标
	ch = _getch();   //需加载<conio.h>头文件,直接接收字符,不用按回车
	for (i = 0; i < RPow; i++)
	{
		for (j = 0; j < CPow; j++)
		{
			if (map[i][j] == 5 || map[i][j] == 8)
			{
				r = i;
				c = j;
			}
		}
		if (map[i][j] == 5 || map[i][j] == 8)  //判断人在目的地
			break;
	}

	switch (ch)
	{
	case'w':         //上
	case'W':
	case 72:        //键值
					//人的坐标 map[r][c], 人上一个位置 map[r-1][c] 是否为空地0或目的地3,是就交换值
		if (map[r - 1][c] == 0 || map[r - 1][c] == 3)
		{
			map[r - 1][c] += 5;    //人向上移动
			map[r][c] -= 5;        //原位置变回空地0 
		}
		else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)   //人5的前面是箱子4, 或箱子4与目的地3重合为7位置
		{
			if (map[r - 2][c] == 0 || map[r - 2][c] == 3)   //箱子前面 map[r-2][c]是否为空地或目的地
			{
				map[r - 2][c] += 4;       //箱子向上移动
				map[r - 1][c] += 1;       //人移动到原箱子位置
				map[r][c] -= 5;           //原先的人位置变为空地0
			}
		}
		//	if (map[r - 1][c] == 0)
		//	{
		//		map[r - 1][c] += 5;    //人向上移动
		//		map[r][c] -= 5;        //原位置变回空地0 
		//}
		//	else if (map[r - 1][c] == 3)        //人5的前面是目的地
		//	{
		//		map[r - 1][c] += 8;   
		//		map[r][c] -= 5;
		//	}
		break;

	case's':         //下
	case'S':
	case 80:
		if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
		{
			map[r + 1][c] += 5;    //人向上移动
			map[r][c] -= 5;        //原位置变回空地0 
		}
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)   //人5的前面是箱子4, 或箱子4与目的地3重合为7位置
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)   //箱子前面 map[r-2][c]是否为空地或目的地
			{
				map[r + 2][c] += 4;       //箱子向上移动
				map[r + 1][c] += 1;       //人移动到原箱子位置
				map[r][c] -= 5;           //原先的人位置变为空地0
			}
		}

		break;


	case'a':         //左
	case'A':
	case 75:
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)
		{
			map[r][c - 1] += 5;    //人向上移动
			map[r][c] -= 5;        //原位置变回空地0 
		}
		else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)   //人5的前面是箱子4, 或箱子4与目的地3重合为7位置
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)   //箱子前面 map[r-2][c]是否为空地或目的地
			{
				map[r][c - 2] += 4;       //箱子向上移动
				map[r][c - 1] += 1;       //人移动到原箱子位置
				map[r][c] -= 5;           //原先的人位置变为空地0
			}
		}
		break;

	case'd':         //右
	case'D':
	case 77:
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
		{
			map[r][c + 1] += 5;    //人向上移动
			map[r][c] -= 5;        //原位置变回空地0 
		}
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)   //人5的前面是箱子4, 或箱子4与目的地3重合为7位置
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)   //箱子前面 map[r-2][c]是否为空地或目的地
			{
				map[r][c + 2] += 4;       //箱子向上移动
				map[r][c + 1] += 1;       //人移动到原箱子位置
				map[r][c] -= 5;           //原先的人位置变为空地0
			}
		}
		//if (map[r][c + 1] == 0)
		//{
		//	map[r][c + 1] += 5;    //人向上移动
		//	map[r][c] -= 5;        //原位置变回空地0 
		//}
		//else if (map[r][c + 1] == 3)        //人5的前面是目的地
		//{
		//	map[r][c + 1] += 8;
		//	map[r][c] -= 5;
		//}
		break;
	}
}
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
//MessageBox(NULL, L"恭喜你赢啦 !", L"提示", 0);
//return 0;
//}
