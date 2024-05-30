#include "header.h"

char user_sign;	// ����� ��ȸ Ȥ�� ����ǥ ��½� ������� Ȯ���� �޴� ����
char user[USER_NUM][USER_NAME_LENGTH];	// ����� �迭�� ���� ������ ����, �ִ� 20��, ���� �ִ� 20��
int userNum;				// ����� �迭 �� �ε���

// Ÿ��Ʋ�� ��µǴ� ���� ���� ����
int playingUser;
int SCORE;
extern int dificulty;
extern int correct_cnt;
extern int wrong_cnt;
extern float user_used_time;


main(void)
{

	int user_choice_1;

	while (1)
	{
		system("tiTle \"WeType\" Ÿ�ڿ�������");		// ���� ����
		system("mode con: cols=69 lines=31");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("********************************************************************\n");
		printf("********************************************************************\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		printf("********************************\"WE\"********************************\n");
		Sleep(500);
		printf("*******************************\"TYPE\"*******************************\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("********************************************************************\n");
		printf("********************************************************************\n\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("\t\t   Press ENTER key to Continue...\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		getchar();

		while (1)
		{

			printf("\t\t\t     1. ����\n\n");
			printf("\t\t\t     2. �߰�\n\n");
			printf("\t\t\t     3. ��ȸ\n\n");
			printf("\t\t\t     4. ����\n\n");
			printf("\t\t\t     5. ����\n\n");
			printf("\t\t\t     6. ����ǥ\n\n");
			printf("\t\t\t     7. ���ӹ��\n\n");
			printf("\t\t\t     8. ũ����\n\n");
			printf("\t\t\t     0. ����\n\n\t>> ");

			scanf(" %d", &user_choice_1);

			switch (user_choice_1)
			{
			case 1:		// <���� ����>
				user_select();
				break;
			case 2:		// ���ο� ����� �߰�
				user_add();
				break;
			case 3:		// ����� ��ȸ (��Ȯ��, Ÿ��)
				user_view();
				break;
			case 4:		// ����� �̸� ����
				user_modify();
				break;
			case 5:		// ����� ����
				user_del();
				break;
			case 6:		// ����ǥ ���
				score_board();
				break;
			case 7:		// ���� ��� ���
				readme();
				break;
			case 8:		// ũ���� ���
				ending_credit();
				break;
			case 0:		// ���� ����
				printf("\n\t �÷��� �� �ּż� �����մϴ�! ������ �����մϴ�.\n\n");
				Sleep(1000);
				return 0;
				break;
			default:	// �߸� �Է��ϼ̽��ϴ�. (��� ȣ�� ���)
				printf("\n\t  �߸� �Է��ϼ̽��ϴ�!\n\n\n");
				Sleep(1000);
			}


		}

	}

}
void GameTitle()   // ���� ���� �� ��� Ÿ��Ʋ
{
	float correct_rate;
	float per_min;

	if (correct_cnt + wrong_cnt == 0)
		correct_rate = 0;
	else
		correct_rate = 100 * ((float)correct_cnt / (correct_cnt + wrong_cnt));

	if (user_used_time == 0)
		per_min = 0;
	else
		per_min = correct_cnt * (2*dificulty+2) * 60 / user_used_time;

	
	system("cls");
	// ���� ����� ���(�̸� ���̿� ���� ���� ����)
	if (strlen(user[playingUser - 1]) < 6)
		printf("\t  Player[%s]\t\t", user[playingUser - 1]);
	else
		printf("\t  Player[%s]\t", user[playingUser - 1]);	// ���� ����� ���
	printf("\t   Score[%d]\n", SCORE);						// ���� ���
	printf("\t  Rate[%.1f%%]\t\t", correct_rate);			// ����� ���
	printf("\t   Per Min[%.1f]\n", per_min);				// �д� Ÿ�� ���			
	printf("\t  Level[%d]\t\t", dificulty);					// ���� ���
	printf("   Press 1 to Pause ESC to Exit\n");
	for (int i = 0; i < 69; i++)
	{
		printf("_");
	}
	printf("\n");
}

void readme()		// 7. ���� ��� ����
{
	char* n[33];	// ���� ���� �� 32��
	char* name;

	srand(time(0));

	FILE* fp = NULL;
	int cnt = 0;

	fp = fopen("readme.txt", "r");	// ���� ���� (�����̸�: credit.txt)
	if (fp == 0)
	{
		fprintf(stderr, "File Open Error!\n");	//ǥ�ؿ��������ġ
		exit(1);
	}
	for (int i = 0; i < 32; i++)	// �� 32�� ����
	{
		name = (char*)calloc(100, sizeof(char));	// 100��ŭ�� ���� �޸� �Ҵ�
		fgets(name, 100, fp);	//���� ����
		n[i] = name;
	}
	printf("\n");
	for (int i = 0; i < 32; i++)	// ���ݾ� �ð� ���� �ΰ� �� �پ� ���
	{
		printf("%s", n[i]);
		Sleep(500);
	}
	Sleep(1500);
	printf("\n\n\n\t    �ƹ� Ű�� ���� ���ư���...\n\n");
	user_sign = _getch();
	fclose(fp);		// ���� �ݱ�
	free(name);		// ���� �޸� �ݳ�
}

void ending_credit()	// 8. ���� ũ����
{
	char* n[36];		// ���� ũ���� �� 33��
	char* name;

	srand(time(0));

	FILE* fp = NULL;
	int cnt = 0;

	fp = fopen("credit.txt", "r");	// ���� ���� (�����̸�: credit.txt)
	if (fp == 0)
	{
		fprintf(stderr, "File Open Error!\n");	//ǥ�ؿ��������ġ
		exit(1);
	}
	for (int i = 0; i < 35; i++)	// �� 43�� ����
	{
		name = (char*)calloc(150, sizeof(char));	// 150��ŭ�� ���� �޸� �Ҵ�
		fgets(name, 150, fp);	//���� ����
		n[i] = name;
	}
	printf("\n");
	for (int i = 0; i < 35; i++)	// ���ݾ� �ð� ���� �ΰ� �� �پ� ���
	{
		printf("%s", n[i]);
		Sleep(500);				// ���� ���� ���� ���� (������ ��µǰ�)
	}
	Sleep(1000);
	printf("\n\n   �����մϴ�!\n");
	Sleep(1000);
	printf("\n\n\t    �ƹ� Ű�� ���� ���ư���...\n\n");
	user_sign = _getch();
	fclose(fp);		//���� �ݱ�
	free(name);		// ���� �޸� �ݳ�
}