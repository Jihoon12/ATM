#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 22
#define MIN_NAME_LEN 4
#define MAX_NUM_LEN 15
#define MAX_PASSWORD_LEN 6
#define MAX_USERS 100

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct Bank
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASSWORD_LEN];
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
    int users_index = 0;
    char users_count[15];
    FILE* accounts_txt = fopen("Accounts_Info.txt", "a+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    fseek(accounts_txt, 0, SEEK_SET);
    fgets(users_count, 15, accounts_txt);
    sscanf(users_count, "유저수:%d", &users_index);

    if (users_index == 0)
    {
        fprintf(accounts_txt, "유저수:%d\n", users_index);
    }

    fclose(accounts_txt);

    accounts_txt = fopen("Accounts_Info.txt", "a+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    accounts[users_index].money = 0;

    accounts[users_index].num[0] = rand() % 9 + '1';
    for (int i = 1; i < 14; i++)
    {
        accounts[users_index].num[i] = rand() % 10 + '0';
    }
    accounts[users_index].num[14] = '\0';


    char input_name[MAX_NAME_LEN];

    printf("계좌번호에 사용할 이름을 입력하세요.\n(한글 10자, 영문 20자 이내)\n>>");
    while (1)
    {
        fgets(input_name, MAX_NAME_LEN, stdin);
        rewind(stdin);
        input_name[MAX_NAME_LEN - 1] = '\0';
        sscanf(input_name, "%s", accounts[users_index].name);
        if (MIN_NAME_LEN < strlen(accounts[users_index].name) + 1 && strlen(accounts[users_index].name) + 1 < MAX_NAME_LEN)
        {
            break;
        }
        else if (strlen(accounts[users_index].name) + 1 < MIN_NAME_LEN)
        {
            printf("최소 한글 2글자, 영문 4글자 이상이어야 합니다.\n 다시 입력해주세요.\n>>");
        }
        else
        {
            printf("한글 10자, 영문 20자 이내이어야 합니다.\n 다시 입력해주세요.\n>>");
        }
    }

    char input_password[MAX_PASSWORD_LEN];

    printf("비밀번호 4자리를 입력하세요\n>>");
    while (1)
    {
        fgets(input_password, MAX_PASSWORD_LEN, stdin);
        rewind(stdin);
        input_password[MAX_PASSWORD_LEN - 1] = '\0';
        sscanf(input_password, "%s", accounts[users_index].password);
        if (strlen(accounts[users_index].password) + 2 == MAX_PASSWORD_LEN)
        {
            break;
        }
        else
        {
            printf("비밀번호 4자리가 아닙니다.\n 다시 입력해주세요.\n>>");
        }
    }
    fprintf(accounts_txt, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
    printf("계좌생성이 완료되었습니다.\n");
    printf("이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
    fclose(accounts_txt);

    accounts_txt = fopen("Accounts_Info.txt", "r+");

    users_index++;
    fseek(accounts_txt, 0, SEEK_SET);
    fprintf(accounts_txt, "유저수:%d\n", users_index);

    fclose(accounts_txt);
}
