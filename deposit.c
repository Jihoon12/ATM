#define _CRT_SECURE_NO_WARNINGS
#define MAX_NAME_LEN 21
#define MAX_NUM_LEN 15
#define MAX_PASS_LEN 5

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct AccountsInfo
{
    char name[MAX_NAME_LEN];
    char num[MAX_NUM_LEN];
    int money;
    char password[MAX_PASS_LEN];
}AccountsInfo_t;

void Deposit();

int main()
{
    Deposit();
	return 0;
}

void Deposit()
{
    FILE* fp = fopen("Account_Info.txt", "r");
    AccountsInfo_t accounts[100];
    char accounts_info[1024];

    int index = 0; // 송금, 출금, 입금
    while (feof(fp) == 0) // while (feof(fp) == 0)
    {
        fgets(accounts_info, 1024, fp);
        sscanf(accounts_info, "이름:%s 계좌번호:%s 잔액:%d 비밀번호:%s", accounts[index].name, accounts[index].num, &accounts[index].money, accounts[index].password);
        index++;
    }

    char my_acc_num[15];
    char deposit_acc_num[15];
    char password[5];

    int acc_compare = 0;
    int deposit_money = 0;
    int my_acc_index = 0;
    int deposit_acc_index = 0;
    
    printf("계좌번호 14자리를 입력하세요.\n>>");
    scanf("%s", my_acc_num);

    while (1)
    {
        acc_compare = strcmp(accounts[my_acc_index].num, my_acc_num);

        if (strlen(my_acc_num) == 14)
        {
            if (acc_compare == 0) // fix me : txt에 계좌정보가 없을 시 오류
            {
                break;
            }
        }
        else
        {
            printf("계좌번호 14자리가 아닙니다. 다시 입력해주세요.\n>>");
            scanf("%s", my_acc_num);
        }
        my_acc_index++;
    }

    printf("비밀번호 4자리를 입력하세요\n>>");
    scanf("%s", password);

    while (1)
    {
        acc_compare = strcmp(accounts[my_acc_index].password, password);

        if (strlen(password) == 4)
        {
            if (acc_compare == 0)
            {
                break;
            }
            else
            {
                printf("비밀번호가 다릅니다. 다시입력해주세요.\n>>");
                scanf("%s", password);
            }
        }
        else
        {
            printf("비밀번호 4자리를 다시 입력하세요\n>>");
            scanf("%s", password);
        }
    }

    printf("송금할 금액을 입력하세요.\n>>");
    scanf("%d", &deposit_money);

    while (1)
    {
        if ((accounts[my_acc_index].money - deposit_money) < 0)
        {
            printf("잔액이 부족합니다. 다시 입력해주세요.");
            printf("남은 잔액 : %d\n\n>>", accounts[my_acc_index].money);
            scanf("%d", &deposit_money);
        }
        else
        {
            break;
        }
    }

    printf("송금할 계좌번호를 입력해주세요.\n>>");
    scanf("%s", deposit_acc_num);

    while (1)
    {
        acc_compare = strcmp(accounts[deposit_acc_index].num, deposit_acc_num);

        if (strlen(deposit_acc_num) == 14)
        {
            if (acc_compare == 0)
            {
                accounts[my_acc_index].money -= deposit_money;
                accounts[deposit_acc_index].money += deposit_money;
                printf("남은 잔액 : %d", accounts[my_acc_index].money);
                break;
            }
        }
        else
        {
            printf("계좌번호 14자리가 아닙니다. 다시 입력해주세요.\n>>");
            scanf("%s", deposit_acc_num);
        }
        deposit_acc_index++;
    }

    fclose(fp);
}
