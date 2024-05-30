#include "header.h"

// ����� ��ȸ Ȥ�� ����ǥ ��½� ������� Ȯ���� �޴� ����
char user_sign;

extern char user[USER_NUM][USER_NAME_LENGTH];	// main�� ����� �迭�� ����
extern int userNum;								// main�� ����� �迭 �ε����� ����
extern int playingUser;							// ������ �����ϴ� ����� �ε���
extern int score_easy[USER_NUM];				//����ں� easy ���� �迭
extern int score_normal[USER_NUM];				//����ں� normal ���� �迭
extern int score_hard[USER_NUM];				//����ں� hard ���� �迭

//����ں� �ð� �ҿ�
extern float user_time_easy[USER_NUM];
extern float user_time_normal[USER_NUM];
extern float user_time_hard[USER_NUM];

// ����� ���� ���̵��� ����� ���� ���� �� ���� ����
extern float correct_cnt_easy[USER_NUM];
extern float correct_cnt_normal[USER_NUM];
extern float correct_cnt_hard[USER_NUM];
extern float wrong_cnt_easy[USER_NUM];
extern float wrong_cnt_normal[USER_NUM];
extern float wrong_cnt_hard[USER_NUM];

int score[USER_NUM];	// ���� ������ �������� ���� �� '����'�� ��� �迭
int rank[USER_NUM];		// ���� ������ �������� ���� �� '�ε��� ��ȣ'�� ��� �迭


int dificulty;		// ����ڰ� �����ϴ� ���̵� ���� ����

void user_select()	// ����� ���� �Լ�
{
	if (userNum == 0)
	{
		printf("\t\t��ϵ� ����ڰ� �����ϴ�!\n\t\t����ڸ� �߰��� �ּ���.\n\n");
		Sleep(500);
	}
	else
	{
		printf("\n*****************************\"����� ����\"***************************\n\n");
		for (int i = 0; i < userNum; i++)
		{
			printf("\t   %d. %s\n", i + 1, user[i]);
		}
		while (1)
		{
			printf("\n\t    ������ ������ ������� ��ȣ�� �Է��� �ּ���.\n\t>> ");
			scanf("%d", &playingUser);
			if (playingUser - 1 < 0 || playingUser - 1 >= userNum)
			{
				printf("\t\t�߸� �Է��ϼ̽��ϴ�.\n\n\n");
				return 0;
			}	
			else
			{
				while (1)
				{
					printf("\n ������ ���̵��� ������ �ּ���. (1: Easy, 2: Normal, 3: Hard)\n>> ");		// ���̵� ���� -> 1.�̸� ���̵��� �Լ� ����? �ƴϸ� 2.�Լ� �ϳ��� ����� �ٸ���?
					scanf(" %d", &dificulty);
					switch (dificulty)
					{
					case 1:		// easy
					case 2:		// normal
					case 3:		// hard
						//word(dificulty);	//������ ���̵��� ����� ���ӿ� �Ҵ�
						game();
						break;
					default:	// �߸� �Է��ϼ̽��ϴ�.
						printf("\n�߸� �Է��ϼ̽��ϴ�.\n");
					}
					return 0;
				}
				break;
			}
		}
		game();
	}
}

void user_add()		// ����� �߰� �Լ�
{
	printf("\n*****************************\"����� �߰�\"***************************\n\n");
	printf("    �߰��ϰ��� �ϴ� ������� �̸��� �Է��� �ּ���. (�ִ� 20��)\n\t>> ");
	scanf("%s", user[userNum]);
	printf("\n\t\t����� �߰� �Ϸ�!\n\n");
	printf("\t    %d. %s\n\n", userNum + 1, user[userNum]);
	userNum += 1;		// ����� �迭 �ε��� ����
}

void user_view()	// ����� ���� ��ȸ �Լ�
{
	float easy_rate;
	float normal_rate;
	float hard_rate;

	float easy_per_min;
	float normal_per_min;
	float hard_per_min;

	if (userNum == 0)
		printf("\t\t��ϵ� ����ڰ� �����ϴ�!\n\n");
	else
	{
		printf("\n*****************************\"����� ��ȸ\"***************************\n\n");

		for (int i = 0; i < userNum; i++)
		{
			// �����, Ÿ�� ����ó�� (�и� 0�� ��)
			if (correct_cnt_easy[i] + wrong_cnt_easy[i] == 0)
				easy_rate = 0;
			else
				easy_rate = (100 * correct_cnt_easy[i] / (float)(correct_cnt_easy[i] + wrong_cnt_easy[i]));

			if (correct_cnt_normal[i] + wrong_cnt_normal[i] == 0)
				normal_rate = 0;
			else
				normal_rate = (100 * correct_cnt_normal[i] / (float)(correct_cnt_normal[i] + wrong_cnt_normal[i]));

			if (correct_cnt_hard[i] + wrong_cnt_hard[i] == 0)
				hard_rate = 0;
			else
				hard_rate = (100 * correct_cnt_hard[i] / (float)(correct_cnt_hard[i] + wrong_cnt_hard[i]));
			if (user_time_easy[i] == 0)
				easy_per_min = 0;
			else
				easy_per_min = correct_cnt_easy[i] * EASY_LENGTH * 60 / user_time_easy[i];
			if (user_time_normal[i] == 0)
				normal_per_min = 0;
			else
				normal_per_min = correct_cnt_normal[i] * NORMAL_LENGTH * 60 / user_time_normal[i];
			if (user_time_hard[i] == 0)
				hard_per_min = 0;
			else
				hard_per_min = correct_cnt_hard[i] * HARD_LENGTH * 60 / user_time_hard[i];


			printf("\t%d. %s\n", i+1, user[i]);
			printf("    [ Easy    >> ����: %d��, �����: %.1f%%, Ÿ��: %.1fŸ/�� ]\n", score_easy[i], easy_rate, easy_per_min);
			printf("    [ Normal  >> ����: %d��, �����: %.1f%%, Ÿ��: %.1fŸ/�� ]\n", score_normal[i], normal_rate, normal_per_min);
			printf("    [ Hard    >> ����: %d��, �����: %.1f%%, Ÿ��: %.1fŸ/�� ]\n\n", score_hard[i], hard_rate, hard_per_min);
		}

	}
	printf("\n\t    �ƹ� Ű�� ���� ���ư���...\n\n\n");
	user_sign = _getch();
}

void user_modify()	// ����� �̸� ���� �Լ�
{
	int changeNum;		// ������ ������� �ε��� ��ȣ
	if (userNum == 0)
		printf("\t\t��ϵ� ����ڰ� �����ϴ�!\n\n\n");
	else {
		printf("\n*****************************\"����� ����\"***************************\n\n");
		while (1)
		{
			printf("\t    �̸��� ������ ������� ��ȣ�� �Է��� �ּ���.\n\t>> ");
			scanf("%d", &changeNum);
			if (changeNum - 1 < 0 || changeNum - 1 >= userNum)
				printf("\t\t�߸� �Է��ϼ̽��ϴ�.\n\n");
			else
				break;
		}
		printf("\t    �ش� ������� �̸�: %s\n\n", user[changeNum - 1]);
		printf("\t    �̸��� ���� �Է��� �ּ���.\n\t>> ");
		scanf("%s", user[changeNum - 1]);
		printf("\n\t\t����� ���� �Ϸ�!\n\n");
		printf("\t\t%d. %s\n\n", changeNum, user[changeNum - 1]);
	}
}

void user_del()		// ����� ���� �Լ�
{
	int delNum;		// ������ ������� �ε��� ��ȣ
	if (userNum == 0)
		printf("\t\t��ϵ� ����ڰ� �����ϴ�!\n\n\n");
	else
	{
		printf("\n*****************************\"����� ����\"***************************\n\n");
		while (1)
		{
			printf("\t    ������ ������� ��ȣ�� �Է��� �ּ���.\n\t>> ");
			scanf("%d", &delNum);
			if (delNum - 1 < 0 || delNum - 1 >= userNum)
				printf("\t    �߸� �Է��ϼ̽��ϴ�.\n\n");
			else
				break;
		}
		for (int i = delNum - 1; i < userNum - 1; i++)			// ���� ����ڸ� ������ �� ĭ �ű��
		{
			strcpy(user[i], user[i + 1]);
			score_easy[i] = score_easy[i + 1];
			score_normal[i] = score_normal[i + 1];
			score_hard[i] = score_hard[i + 1];
			correct_cnt_easy[i] = correct_cnt_easy[i + 1];
			wrong_cnt_easy[i] = wrong_cnt_easy[i + 1];
			correct_cnt_normal[i] = correct_cnt_normal[i + 1];
			wrong_cnt_normal[i] = wrong_cnt_normal[i + 1];
			correct_cnt_hard[i] = correct_cnt_hard[i + 1];
			wrong_cnt_hard[i] = wrong_cnt_hard[i + 1];
			user_time_easy[i] = user_time_easy[i + 1];
			user_time_normal[i] = user_time_normal[i + 1];
			user_time_hard[i] = user_time_hard[i + 1];
		}
		userNum--;
		printf("\n\t\t%d�� ����ڸ� �����Ͽ����ϴ�.\n\n\n", delNum);
	}
}

void score_board()	// ������ ��� �Լ�
{	
	printf("\n*****************************\"Score Board\"***************************\n\n");

	bubble_sort(score_easy, userNum);
	printf("\tEasy\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d�� >> %s:\t\t%d��\n", i + 1, user[rank[i]], score_easy[rank[i]]);
	}

	bubble_sort(score_normal, userNum);
	printf("\n\tNormal\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d�� >> %s:\t\t%d��\n", i + 1, user[rank[i]], score_normal[rank[i]]);
	}

	bubble_sort(score_hard, userNum);
	printf("\n\tHard\n");
	for (int i = 0; i < userNum; i++)
	{
		printf("\t       %d�� >> %s:\t\t%d��\n", i + 1, user[rank[i]], score_hard[rank[i]]);
	}
	printf("\n\t    �ƹ� Ű�� ���� ���ư���...\n\n\n");
	user_sign = _getch();
}

void bubble_sort(int arr[], int cnt)
{	
	// ���� ������ �������� ���� �� �ε��� ��ȣ�� ��� �迭
	for (int i = 0; i < userNum; i++)
		score[i] = arr[i];
	for (int i = 0; i < userNum; i++)
		rank[i] = i;

	int temp_1;
	int temp_2;

	// ���� (Sorting)
	for (int i = 0; i < userNum; i++)
	{
		for (int j = 0; j < userNum - 1; j++)
		{
			if (score[j] < score[j + 1])
			{
				temp_1 = score[j];
				score[j] = score[j + 1];
				score[j + 1] = temp_1;
				
				temp_2 = rank[j];
				rank[j] = rank[j + 1];
				rank[j + 1] = temp_2;
			}
		}
	}

}