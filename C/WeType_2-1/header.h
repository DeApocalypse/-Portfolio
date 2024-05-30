#include <stdio.h>
#include <stdlib.h>
#include <time.h>		// tmie()
#include <windows.h>	// system()
#include <conio.h>		// _getch(), _kbhit()

// ����� �迭�� ���� ������ ����, �ִ� 20��, ���� �ִ� 20��
#define USER_NUM 21	
#define USER_NAME_LENGTH 21

//���̵��� ��� �� ��ü �ܾ� ��
#define WORDS_MAX 100	

// ���̵��� ���� ���� (2*dificulty+2 = length)
#define EASY_LENGTH 4		// 1
#define NORMAL_LENGTH 6		// 2
#define HARD_LENGTH 8		// 3

// ���̵��� �ð� �Ҵ� (time + dificulty =6)
#define EASY_TIME 5000		// 1
#define NORMAL_TIME 4000	// 2
#define HARD_TIME 3000		// 3

void game();		// ���� ���� �Լ�

// ����� ���� �Լ��� ���� ���� ����
void user_select();	// ����� ���� �Լ�
void user_add();	// ����� �߰� �Լ�
void user_view();	// ����� ���� ��ȸ �Լ�
void user_modify();	// ����� �̸� ���� �Լ�
void user_del();	// ����� ���� �Լ�
void score_board();	// ������ ��� �Լ�
void bubble_sort(int arr[], int cnt);		// ��������, ������ �迭�� ����� ������ ����.
void readme();		// ���� ��� ��� �Լ�
void ending_credit();	// ���� ũ���� ��� �Լ�
void GameTitle();//���� ����
void show_string(char* w);	// ���� �� ���� ��� �Լ�	
void correct(int dificulty);	// ������ ��� ȣ���ϴ� �Լ�
void wrong(int dificulty);		// ������ ��� ȣ���ϴ� �Լ�