#include "header.h"

extern char user[USER_NUM][USER_NAME_LENGTH];	// main�� ����� �迭�� ����
extern int userNum;								// main�� ����� �迭 �ε����� ����

extern int playingUser;							// ������ �����ϴ� ����� �ε���

int score_easy[USER_NUM];						// ����ں� Easy ���� ���� �迭
int score_normal[USER_NUM];						// ����ں� Normal ���� ���� �迭
int score_hard[USER_NUM];						// ����ں� Hard ���� ���� �迭

double remain_time;		// ���� �ð�

//����ں� �Ҹ� �ð�
float user_time_easy[USER_NUM];
float user_time_normal[USER_NUM];
float user_time_hard[USER_NUM];

// ����� ���� ���̵��� ����� ���� ���� �� ���� ����
float correct_cnt_easy[USER_NUM];
float correct_cnt_normal[USER_NUM];
float correct_cnt_hard[USER_NUM];
float wrong_cnt_easy[USER_NUM];
float wrong_cnt_normal[USER_NUM];
float wrong_cnt_hard[USER_NUM];

int question_num;		// ���� ��ȣ (���̵��� 10���� ���)

extern int SCORE;
extern int dificulty;		// ����ڰ� �����ϴ� ���̵� ���� ����

char* n[WORDS_MAX];			// �ܾ� ���
int word_random_index;			// �ܾ� �迭 ���� index
int word_size = 0;		// ���̵��� ���� �ܾ� ���� �迭�� ������
int word_time = 0;		// ���̵��� ���� �ð�

char go_stop;		// ���� ���� �� ���� �ܰ�� �Ѿ���� �޾Ƶ��̴� ����

int correct_cnt;	// ���� ����
int wrong_cnt;		// ���� ����

float user_used_time;	// ����ڰ� ����� �� �ð� (Ÿ��Ʋ ���� Ÿ�� ���� ���)

// ���̵��� 100����
char* easy_word[] = { "act", "age", "all", "any", "are", "arm", "ask", "bad", "bag", "bat", "bed","bet","big","bin","bio","bow","box","boy","bug","bus", "bus","but","can","cap","car","cat","ceo","cow","cry","cup","did","dog","dry","due","ear","egg","etc","eye","fan","fat","fee","few","fit", "fly","fog","fox","fun","gas","get","god","gum","gym","hat ","hen","her","hey","hip","his","hmm","hot","ice","ill","ink","jam","jaw","joy", "key","lag","lay","leg","let","lip","man","map","may","mid","mom","nap","net","nod","not","odd","oil","out","own","pet","pin", "pot","rat","red","see","set","six","ten","the","vet","wet","yet","you","zoo" };
char* normal_word[] = { "admit", "after", "alarm", "among", "angry", "apple", "below", "birth", "block", "block","board ","brave","brick","bring ","claim ","clock","cloth","codes","could","drawn","dress","drive","eager","early ","eight","empty","enrol ","enter","essay", "fifth","first","flame","flood","flown","fluid ","glare","guess","happy","hello","horse","house","hurry","issue ","knife","later ","leave","lunch","marry","maybe","meter","might","model","mouse", "music","naver","never","night","offer","ought","paper","phone","piano","place","pound","print","proud","queen","radio","reuse","roast","round","seven","shake","shape","shift","shirt","skate","skirt","smack", "snack","sorce","sound","space","spend","store ","swear","teach","third","three","today ","train","under","urban","vivid","where","which","while","witch","woman","world","would" };
char* hard_word[] = { "analyse", "abolish", "abusive", "annular", "applaud", "artless", "attract", "battery", "bedroom", "behinds","analyse","abolish","abusive","annular","applaud","artless","attract","battery","bedroom","behinds","bestows","central","chiefly","citizen","college","company", "conduce","consult","contain","control","country","courier","croatia","curable","curious","dancing","deliver","develop","dictate","dilutes","dirties","earnest","economy","educate","elastic","envelop","episode","example", "feeling","forsook","fouling","funeral","gassier","general","greater","handled","history","holders","horizon","however","hunting","journey","lagging","leanest","manager","meeting","moaners","monthly","numeral", "oppress","optical","ordered","organic","osmotic","outcome","outside","oversea","partner","peering","picture","popular","precise","present","pretend","prevent","product","profess","quelled", "quilted","refined","respond","ruinous","salable","seattle","serious","servant","settled","sipping","smartly","someone","special","stomach","success","teenage","through","tuesday","upgrade","various","whistle","willing" };


void game()		// ���� ���� �Լ�
{
	question_num = 1;	// ���� ��ȣ �ʱ�ȭ
	correct_cnt = 0;	// ���� ���� �ʱ�ȭ
	wrong_cnt = 0;		// ���� ���� �ʱ�ȭ
	user_used_time = 0;	// ��� �ð� �ʱ�ȭ

	switch (dificulty)
	{
	case 1:
		word_size = EASY_LENGTH;
		word_time = EASY_TIME;
		break;
	case 2:
		word_size = NORMAL_LENGTH;
		word_time = NORMAL_TIME;
		break;
	case 3:
		word_size = HARD_LENGTH;
		word_time = HARD_TIME;
		break;
	}

	char ch;			// ����� �Է� �ܾ� ���� üũ�� ����

	// �ִ� ũ���� HARD ���̵� �������� ����
	char word[HARD_LENGTH + 1];	// ���� ���� �ܾ� �迭 ����
	char input[HARD_LENGTH + 1];	// ����� �Է� �ܾ� �迭 ����

	time_t s_time;		// start(����) time
	int j = 0;		// ����� �Է� �ܾ� ���� üũ�� ����

	remain_time = 0;		// ���� �ð�
	double last_time = 0;

	clock_t start, end;	// �ð� ������ ����

	double pause_total_time = 0;		// �Ͻ������� �ҿ�� �� �ð� ���� ����

	srand(time(0));

	printf("\n������ �����ϴ� ����� -->> %s\n\n", user[playingUser - 1]);

	Sleep(2000);
	printf("3..\n\n");
	Sleep(1000);
	printf("2..!\n\n");
	Sleep(1000);
	printf("1..!!!\n\n");
	Sleep(1000);

	printf("\n%s��, ������ �����մϴ�!\n\n", user[playingUser - 1]);
	SCORE = 0;
	Sleep(1500);
	system("cls");
	show_string(word);
	s_time = time(0);
	start = clock();

	while (question_num <= 10)
	{
		//pause_total_time = 0;

		if (time(0) == s_time + word_time / CLOCKS_PER_SEC + pause_total_time)	// start time �������� n�� ���
		{
			//system("cls");
			printf("\n�ð� �ʰ�!\n\n");
			wrong(dificulty);
			Sleep(1000);
			start = clock();
			s_time = time(0);
			j = 0;		// ����� �Է� �迭 �ʱ�ȭ
			question_num++;
			show_string(word);
		}
		if (_kbhit())		// Ű���尡 �ԷµǸ� _kbhit()�Լ��� 1�� ��ȯ, ���ǹ� ����
		{
			ch = _getch();
			if (ch == 27)	// ����ڰ� escŰ(27)�� �Է��ϸ� ���α׷� ����		--> �����Ͻðڽ��ϱ�? �� ����
			{
				printf("\n\n�޴��� ���ư��ϴ�...\n\n");
				break;
			}
			if (ch == '1')
			{
				pause_total_time = 0;
				clock_t pause_start, pause_end;
				pause_start = clock();
				printf("\nGame Pause, Press 1 to Continue!\n");
				while (_getch() != '1');
				pause_end = clock();
				pause_total_time = (pause_end - pause_start);
				printf("\n>> ");
				for (int i = 1; i < j + 1; i++)
					printf("%c", input[i - 1]);
			}
			if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			{
				printf("%c", ch);		// ���� �Է��� ���� ���
				input[j] = ch;
				j++;
			}
			if (ch == 8)	// ����ڰ� back-space(8)�� �Է��� ���
			{
				if (j > 0)	// j�� 0���� ū ��쿡�� input[] �迭�� j�ε��� 1 ����
				{
					input[j - 1] = 0;
					printf("\b \b");  //Ŀ�� �ű� �� �� ���� ����, �ٽ� Ŀ�� �ű��
					j--;
				}
			}
			if (ch == 13)		// ����ڰ� ���͸� �Է����� ��
			{
				end = clock();
				remain_time = (double)word_time / CLOCKS_PER_SEC - ((end - start - pause_total_time) / (double)CLOCKS_PER_SEC);
				pause_total_time = 0;
				input[j] = 0;	// ����� �Է� �迭�� ������ �ε����� 0�� �־ ���ڿ��� ����

				/* �Է°� Ȯ�ο� �ڵ�
				printf("\n");
				for (int i = 0; i < sizeof(word); i++) {
					printf("%c", word[i]);
				}
				printf("\n");
				for (int i = 0; i < sizeof(word); i++) {
					printf("%c", input[i]);
				}
				printf("\n\n");
				*/

				if (!strcmp(word, input))		// strcmp()�� �̿��� word�迭�� input�迭�� ���ڿ� ��
					correct(dificulty);
				else
					wrong(dificulty);
				printf("\n");
				s_time = time(0);
				j = 0;
				start = clock();
				question_num++;
				if (question_num > 10)
					break;
				show_string(word);
			}
		}
	}
	system("cls");
	GameTitle();//����
	printf("\n\t������ �����մϴ�!\n\n");
	Sleep(1000);
	if (correct_cnt >= 8)		// 80%�̻� ������ �� ���� �ܰ�� ���� ����
	{
		printf("�Ϳ�!! 80%% �̻� �����̽��ϴ�! ���� ������ �����Ͻðڽ��ϱ�? (Y/N)\n���� 3�� �� ���� ���� �� ����.)\n");
		while (1)
		{
			printf(">> ");
			scanf("%s", &go_stop);
			if (go_stop == 'Y' || go_stop == 'y')
			{
				if (dificulty < 3)
					dificulty++;
				game();		// ��� �Լ� ���
				break;
			}
			else if (go_stop == 'N' || go_stop == 'n')
			{
				printf("�޴��� ���ư��ϴ�..\n\n");
				Sleep(1000);
				return 0;
				break;
			}
			else
				printf("\n�߸� �Է��ϼ̽��ϴ�!\n\n");
		}
	}
}

void show_string(char* w)		// �ܾ� ��� �Լ�
{
	system("cls");//����
	GameTitle();//����
	int i = 0;
	word_random_index = rand() % 100;		// �������� �ε��� �̱�

	switch (dificulty)
	{
	case 1:
		for (i = 0; i < 3; i++) {
			w[i] = easy_word[word_random_index][i];
		}
		break;
	case 2:
		for (i = 0; i < 5; i++) {
			w[i] = normal_word[word_random_index][i];
		}
		break;
	case 3:
		for (i = 0; i < 8; i++) {
			w[i] = hard_word[word_random_index][i];
		}
		break;
	}

	w[i] = '\0';		// �迭�� �������� null �߰�, ���ڿ��� �ٲٱ�

	printf("\n%d. %s\n", question_num, w);		// ���ڿ� ���� �����ڸ� ����� ���
	printf(">> ");
}

void correct(int dificulty)
{
	printf("\n����!\t");
	//if (remain_time >= 0)
	printf("���� �ð��� %.1f��\n", remain_time);
	correct_cnt += 1;
	user_used_time += (6 - dificulty) - remain_time;
	Sleep(1000);
	switch (dificulty)
	{
	case 1:	// Easy
		// ���� �� �⺻ 50��+���� �ð�*10 �߰�
		correct_cnt_easy[playingUser - 1] += 1;
		score_easy[playingUser - 1] += (correct_cnt * 50 + remain_time * 10);
		SCORE += (correct_cnt * 50 + remain_time * 10);
		user_time_easy[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	case 2:	// Normal
		// ���� �� �⺻ 70��+���� �ð�*15 �߰�
		correct_cnt_normal[playingUser - 1] += 1;
		score_normal[playingUser - 1] += (correct_cnt * 70 + remain_time * 15);
		SCORE += (correct_cnt * 70 + remain_time * 15);
		user_time_normal[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	case 3:	// Hard
		// ���� �� �⺻ 100��+���� �ð�*20 �߰�
		correct_cnt_hard[playingUser - 1] += 1;
		score_hard[playingUser - 1] += (correct_cnt * 100 + remain_time * 20);
		SCORE += (correct_cnt * 100 + remain_time * 20);
		user_time_hard[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	}
}

void wrong(int dificulty)
{
	printf("\n����..\n");
	wrong_cnt += 1;
	Sleep(1000);
	user_used_time += (6 - dificulty) - remain_time;
	switch (dificulty)
	{
	case 1:	// Easy
		// ���� �� 50�� ���� (0�� ������)
		if (SCORE >= 50)
		{
			score_easy[playingUser - 1] -= 50;
			SCORE -= 50;
		}
		else
		{
			score_easy[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_easy[playingUser - 1] += 1;
		user_time_easy[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	case 2:	// Normal
		// ���� �� 70�� ���� (0�� ������)
		if (SCORE >= 70)
		{
			score_normal[playingUser - 1] -= 70;
			SCORE -= 70;
		}
		else
		{
			score_normal[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_normal[playingUser - 1] += 1;
		user_time_normal[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	case 3:	// Hard
		// ���� �� 100�� ���� (0�� ������)
		if (SCORE >= 100)
		{
			score_hard[playingUser - 1] -= 100;
			SCORE -= 100;
		}
		else
		{
			score_hard[playingUser - 1] = 0;
			SCORE = 0;
		}
		wrong_cnt_hard[playingUser - 1] += 1;
		user_time_hard[playingUser - 1] += (6 - dificulty) - remain_time;		//����ں� �Ҹ� �ð� ( �ش� ���̵� �� �ð� - ���� �ð�)
		break;
	}
}