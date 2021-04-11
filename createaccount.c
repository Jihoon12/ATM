#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 22
#define MAX_NUM_LEN 15
#define MAX_PASS_LEN 6
#define MAX_USERS 100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct Account
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASS_LEN];
}Account_t;

void CreateAccount();

Account_t accounts[MAX_USERS];

int main()
{
    CreateAccount();
    return 0;
}

void CreateAccount()
{
    srand(time(NULL));

    FILE* accounts_txt = fopen("Accounts_Info.txt", "a+");

    if (accounts_txt = fopen("Accounts_Info.txt", "a+") == NULL);
    {
        printf("파일 OPNE 실패\n");
        exir(1);
    }

    int users_index = 0;

    accounts[users_index].money = 0;

    accounts[users_index].num[0] = rand() % 9 + '1';
    for (int i = 1; i < 14; i++)
    {
        accounts[users_index].num[i] = rand() % 10 + '0';
    }
    accounts[users_index].num[14] = '\0';


    char input_name[MAX_NAME_LEN];

    printf("계좌번호에 사용할 이름을 입력하세요.\n>>");
    while (true)
    {
        fgets(input_name, MAX_NAME_LEN, stdin);
        rewind(stdin);
        sscanf(input_name, "%s", accounts[users_index].name);
        if (strlen(accounts[users_index].name) + 1 < MAX_NAME_LEN)
        {
            break;
        }
        else
        {
            printf("최대 이름이 초과하였습니다.\n 다시 입력해주세요.\n>>");
        }
    }


    char input_password[MAX_PASS_LEN];

    printf("비밀번호 4자리를 입력하세요\n>>");
    while (true)
    {
        fgets(input_password, MAX_PASS_LEN, stdin);
        rewind(stdin);
        sscanf(input_password, "%s", accounts[users_index].password);

        
        if (strlen(accounts[users_index].password) == 4)
        {
            break;
        }
        else
        {
            printf("비밀번호 4자리가 아닙니다.\n 다시 입력해주세요.\n>>");
        }
    }

    if (users_index == 0)
    {
        fprintf(accounts_txt, "Users_Count:%d\n", users_index + 1);
    }
    fprintf(accounts_txt, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
    users_index++;
    fclose(accounts_txt);
}
