#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 21
#define MAX_NUM_LEN 15
#define MAX_PASS_LEN 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Account_t
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASS_LEN];
}Account;

typedef struct AccountsInfo_t
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASS_LEN];
}AccountsInfo;

void CreateAccount();

int main()
{
    CreateAccount();
    return 0;
}

void CreateAccount()
{
    srand(time(NULL));

    Account account[100];
    FILE* fp = fopen("Account_Info.txt", "r");

    int users_index = 0;
    account[users_index].money = 0;
    strcpy(account[users_index].password, "0");
    
    account[users_index].num[0] = rand() % 8 + '1';
    for (int i = 1; i < 14; i++)
    {
        account[users_index].num[i] = rand() % 10 + '0';
    }
    account[users_index].num[14] = '\0';

    printf("계좌번호에 사용할 이름을 입력하세요.\n>>");
    scanf("%s", account[users_index].name);


    do
    { 
        printf("비밀번호 4자리를 입력하세요\n>>");
        scanf("%s", account[users_index].password);

        if (strlen(account[users_index].password) != 4)
        {
            printf("비밀번호 4자리가 아닙니다.\n비밀번호 4자리를 다시 입력하세요.\n>>");
            scanf("%s", account[users_index].password);
        }

    } while (account[users_index].password == "0");

    fprintf(fp, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", account[users_index].name, account[users_index].num, account[users_index].money, account[users_index].password);

    fclose(fp);
}
