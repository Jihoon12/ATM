#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 22
#define MAX_NUM_LEN 16
#define MAX_PASSWORD_LEN 6
#define MAX_USERS 100
#define MAX_INFO 1024

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

typedef struct AccountsSave
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASSWORD_LEN];
}AccountsSave_t;

void Deposit();

AccountsSave_t accounts[MAX_USERS];

int main()
{
    Deposit();

    return 0;
}

void Deposit()
{
    FILE* accounts_txt = fopen("Accounts_Info.txt", "a+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    char accounts_info[MAX_INFO];
    char buf[2]; // 2번 출력
    int users_index = 0; // 입금
    int index = 0;
    int users_count = 0;
    char read_users_count[20];

    fgets(read_users_count, 20, accounts_txt);
    sscanf(read_users_count, "유저수:%d", &users_count);

    while (!feof(accounts_txt)) // while (feof(fp) == 0)
    {
        if (fread(&buf, 1, 1, accounts_txt) == 0) // 2번 출력
        {
            break;
        }
        else
        {
            fseek(accounts_txt, -1, SEEK_CUR);
        }
        fgets(accounts_info, MAX_INFO, accounts_txt);
        sscanf(accounts_info, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s", accounts[users_index].name, accounts[users_index].num, &accounts[users_index].money, accounts[users_index].password);
        printf("이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
        users_index++;
    }
    index = users_index;
    users_index = 0;

    fclose(accounts_txt);

    accounts_txt = fopen("Accounts_Info.txt", "r+");

    if (accounts_txt == NULL)
    {
        printf("파일 OPEN 실패");
        exit(1);
    }

    char input_account_num[MAX_NUM_LEN];
    char input_account_num2[MAX_NUM_LEN];
    int compare_account_num = 0;

    printf("입금할 계좌 번호를 입력해주세요.\n>>");

    while (1)
    {
        fgets(input_account_num, MAX_NUM_LEN, stdin);
        rewind(stdin);
        input_account_num[MAX_NUM_LEN - 1] = '\0';
        sscanf(input_account_num, "%s", input_account_num2);
        if (strlen(input_account_num2) + 2 == MAX_NUM_LEN)
        { 
            while (users_index <= index)
            {
                compare_account_num = strcmp(input_account_num2, accounts[users_index].num);
                if (compare_account_num == 0)
                {
                    goto OUT; // fix me
                }
                else
                {
                    users_index++;
                }
            }
                printf("입력한 계좌번호가 없습니다.\n 다시 입력하세요.\n>>");
                users_index = 0;
        }
        else
        {
            printf("계좌번호 14자리가 아닙니다.\n 다시 입력해주세요.\n>>");
        }

    }

    OUT: // fix me
    char input_account_password[MAX_PASSWORD_LEN];
    char input_account_password2[MAX_PASSWORD_LEN];
    int compare_account_password = 0;
    int input_count = 3;

    printf("계좌 번호 비밀번호를 입력해주세요. ( 기회 : %d )\n>>", input_count);

    while (1)
    {
        fgets(input_account_password, MAX_PASSWORD_LEN, stdin);
        rewind(stdin);
        input_account_password[MAX_PASSWORD_LEN - 1] = '\0';
        sscanf(input_account_password, "%s", input_account_password2);

        compare_account_password = strcmp(input_account_password2, accounts[users_index].password);
        if (strlen(input_account_password2) + 2 != MAX_PASSWORD_LEN)
        {
            printf("비밀번호 4자리가 아닙니다.\n 다시 입력해주세요.\n>>");
        }
        else if (compare_account_password == 0)
        {
            break;
        }
        else
        {
            input_count--;
            printf("비밀번호가 다릅니다.\n 다시 입력해주세요. ( 기회 : %d )\n>>", input_count);
        }
        if (input_count == 0)
        {
            printf("비밀번호 3회 실패");
            break; // fix me
        }
    }

    printf("계좌 주인 : \"%s\"님 입니다.", accounts[users_index].name);
    int input_money;
    scanf("%d", &input_money);
    accounts[users_index].money = accounts[users_index].money + input_money;
    users_index = 0;
    fprintf(accounts_txt, "유저수:%d\n", users_count);
    while (users_index < index)
    {
        fprintf(accounts_txt, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s\n", accounts[users_index].name, accounts[users_index].num, accounts[users_index].money, accounts[users_index].password);
        users_index++;
    }   

    fclose(accounts_txt);
}
