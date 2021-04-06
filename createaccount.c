#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 21
#define MAX_NUM_LEN 15
#define MAX_PASS_LEN 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Account
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASS_LEN];
}Account_t;

void CreateAccount();
Account_t accounts[100];

int main()
{
    CreateAccount();
    return 0;
}

void CreateAccount()
{
    srand(time(NULL));

    FILE* fp = fopen("Account_Info.txt", "a");

    int users_index = 0;
    accounts[users_index].money = 0;
    strcpy(accounts[users_index].password, "0");

    accounts[users_index].num[0] = rand() % 8 + '1';
    for (int i = 1; i < 14; i++)
    {
        accounts[users_index].num[i] = rand() % 9 + '0';
    }
    accounts[users_index].num[14] = '\0';

    printf("계좌번호에 사용할 이름을 입력하세요.\n>>");
    scanf("%s", accounts[users_index].name);

    printf("비밀번호 4자리를 입력하세요\n>>");
    scanf("%s", accounts[users_index].password);

    while (4 != strlen(accounts[users_index].password))
    {
        printf("비밀번호 4자리가 아닙니다.\n비밀번호 4자리를 다시 입력하세요.\n>>");
        scanf("%s", accounts[users_index].password);
    }

    fprintf(fp, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);

    fclose(fp);
}
