#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<mmsystem.h>
#pragma comment(lib,"WINMM.LIB")
#define RPow 7
#define CPow 8
int map[RPow][CPow] = {
	{ 0,1,1,1,1,1,1,0 },  //0��ʾ�յ�
	{ 0,1,0,0,0,0,1,1 },  //1��ǽ
	{ 1,1,3,1,1,4,0,1 },  //3��Ŀ�ĵ�
	{ 1,0,3,3,4,0,0,1 },  //4������
	{ 1,0,0,1,4,0,0,1 },  //5����
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
		//   ������670*680
		//initgraph(680, 670);
		//Game();
		_getch();
		Move();
	}
	return 0;
}
//��������
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
				printf("��");
				break;
			case 3:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 5:
				printf("��");
				break;
			case 7:
				printf("��");   //���Ӻ�Ŀ�ĵ�
				break;
			case 8:
				printf("��");    //�˺�Ŀ�ĵ�
				break;
				//default:
				//break;
			}
		}
		printf("\n");
	}
}

//�ƶ�
void Move() {
	char ch;
	int i, j;
	int r, c;       //�˵�����
	ch = _getch();   //�����<conio.h>ͷ�ļ�,ֱ�ӽ����ַ�,���ð��س�
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
		if (map[i][j] == 5 || map[i][j] == 8)  //�ж�����Ŀ�ĵ�
			break;
	}

	switch (ch)
	{
	case'w':         //��
	case'W':
	case 72:        //��ֵ
					//�˵����� map[r][c], ����һ��λ�� map[r-1][c] �Ƿ�Ϊ�յ�0��Ŀ�ĵ�3,�Ǿͽ���ֵ
		if (map[r - 1][c] == 0 || map[r - 1][c] == 3)
		{
			map[r - 1][c] += 5;    //�������ƶ�
			map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		}
		else if (map[r - 1][c] == 4 || map[r - 1][c] == 7)   //��5��ǰ��������4, ������4��Ŀ�ĵ�3�غ�Ϊ7λ��
		{
			if (map[r - 2][c] == 0 || map[r - 2][c] == 3)   //����ǰ�� map[r-2][c]�Ƿ�Ϊ�յػ�Ŀ�ĵ�
			{
				map[r - 2][c] += 4;       //���������ƶ�
				map[r - 1][c] += 1;       //���ƶ���ԭ����λ��
				map[r][c] -= 5;           //ԭ�ȵ���λ�ñ�Ϊ�յ�0
			}
		}
		//	if (map[r - 1][c] == 0)
		//	{
		//		map[r - 1][c] += 5;    //�������ƶ�
		//		map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		//}
		//	else if (map[r - 1][c] == 3)        //��5��ǰ����Ŀ�ĵ�
		//	{
		//		map[r - 1][c] += 8;   
		//		map[r][c] -= 5;
		//	}
		break;

	case's':         //��
	case'S':
	case 80:
		if (map[r + 1][c] == 0 || map[r + 1][c] == 3)
		{
			map[r + 1][c] += 5;    //�������ƶ�
			map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		}
		else if (map[r + 1][c] == 4 || map[r + 1][c] == 7)   //��5��ǰ��������4, ������4��Ŀ�ĵ�3�غ�Ϊ7λ��
		{
			if (map[r + 2][c] == 0 || map[r + 2][c] == 3)   //����ǰ�� map[r-2][c]�Ƿ�Ϊ�յػ�Ŀ�ĵ�
			{
				map[r + 2][c] += 4;       //���������ƶ�
				map[r + 1][c] += 1;       //���ƶ���ԭ����λ��
				map[r][c] -= 5;           //ԭ�ȵ���λ�ñ�Ϊ�յ�0
			}
		}

		break;


	case'a':         //��
	case'A':
	case 75:
		if (map[r][c - 1] == 0 || map[r][c - 1] == 3)
		{
			map[r][c - 1] += 5;    //�������ƶ�
			map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		}
		else if (map[r][c - 1] == 4 || map[r][c - 1] == 7)   //��5��ǰ��������4, ������4��Ŀ�ĵ�3�غ�Ϊ7λ��
		{
			if (map[r][c - 2] == 0 || map[r][c - 2] == 3)   //����ǰ�� map[r-2][c]�Ƿ�Ϊ�յػ�Ŀ�ĵ�
			{
				map[r][c - 2] += 4;       //���������ƶ�
				map[r][c - 1] += 1;       //���ƶ���ԭ����λ��
				map[r][c] -= 5;           //ԭ�ȵ���λ�ñ�Ϊ�յ�0
			}
		}
		break;

	case'd':         //��
	case'D':
	case 77:
		if (map[r][c + 1] == 0 || map[r][c + 1] == 3)
		{
			map[r][c + 1] += 5;    //�������ƶ�
			map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		}
		else if (map[r][c + 1] == 4 || map[r][c + 1] == 7)   //��5��ǰ��������4, ������4��Ŀ�ĵ�3�غ�Ϊ7λ��
		{
			if (map[r][c + 2] == 0 || map[r][c + 2] == 3)   //����ǰ�� map[r-2][c]�Ƿ�Ϊ�յػ�Ŀ�ĵ�
			{
				map[r][c + 2] += 4;       //���������ƶ�
				map[r][c + 1] += 1;       //���ƶ���ԭ����λ��
				map[r][c] -= 5;           //ԭ�ȵ���λ�ñ�Ϊ�յ�0
			}
		}
		//if (map[r][c + 1] == 0)
		//{
		//	map[r][c + 1] += 5;    //�������ƶ�
		//	map[r][c] -= 5;        //ԭλ�ñ�ؿյ�0 
		//}
		//else if (map[r][c + 1] == 3)        //��5��ǰ����Ŀ�ĵ�
		//{
		//	map[r][c + 1] += 8;
		//	map[r][c] -= 5;
		//}
		break;
	}
}
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
//MessageBox(NULL, L"��ϲ��Ӯ�� !", L"��ʾ", 0);
//return 0;
//}
