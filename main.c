/******************************************************************************

banking system program.

Account Creation : Add new customer accounts to a file.

Deposit Money: Update the account balance by depositing the money.

Withdraw Money : Update the balance by withdrawing money.

Note 1: You have to check if the funds are sufficient!
Note 2: Minimum balance should be maintained !


Search : Retrieve account details using a unique account number.

Display the accounts: show all account records stored in the file.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>


#define FILENAME "Accounts.txt"


typedef struct{

    char name[100];
    int age;
    char nationality[100];
    bool marital_status;
    int account_number;
    float balance  ;

}Account;

int account_count = 0;
Account accounts[100];

float Minimum_credit = -10000;


void create_account(){

    Account acc;


    FILE *fh;
    fh = fopen(FILENAME, "a");

    if ( fh == NULL )
    {
        printf("File does not exist!");
        return ;
    }




    printf("Enter name : ");
    getchar();

    fgets(acc.name,sizeof(acc.name),stdin);
    // Find the newline character ""\n" if present and replcae it with "\0"
    acc.name[strcspn(acc.name,"\n")]='\0';

    printf("Enter age : ");
    scanf("%d",&acc.age);


    printf("Enter nationality: ");
    getchar();
    fgets(acc.nationality,sizeof(acc.nationality),stdin);
    acc.nationality[strcspn(acc.nationality,"\n")]='\0';


    printf("Enter marital_status: \n");
    printf("Enter 0 if you are single .\n");
    printf("Enter 1 if you are married.\n");
    scanf("%d",(int *)&acc.marital_status);




    printf("Enter account_number : ");
    scanf("%d",&acc.account_number);

    printf("Enter balance : ");
    scanf("%f",&acc.balance);

    accounts[account_count]=acc;
    account_count++;

    printf("The account had been successfully created!Horra...\n");
    fprintf(fh,"%s --- %d --- %s --- %d --- %d ---  %f\n", acc.name,acc.age,acc.nationality, acc.marital_status, acc.account_number , acc.balance );
    fclose(fh);


}


void Display(){



    for (int i=0 ; i < account_count; i++){
        printf("----------------------------------------\n");
        printf("This is account number %d\n", i+1);
        printf("name : %s\n",accounts[i].name);
        printf("age : %d \n",accounts[i].age);
        printf("nationality : %s\n",accounts[i].nationality);
        printf("account_number : %d\n",accounts[i].account_number);
        printf("balance : %f\n",accounts[i].balance);
    }

}

void Deposite(){



    FILE *fh;
    fh = fopen(FILENAME, "a");

    if ( fh == NULL ){

        printf("File does not exist!\n");
        return;
    }







    printf("Please lemmi know your account number !\n");
    int account_number;
    scanf("%d",&account_number);


    int flag=0;


    for (int i=0 ; i < account_count; i++)
    {
        if (accounts[i].account_number == account_number)
        {
                flag=1;
                printf("How much money you want to deposite:\n");
                float deposited_money;
                scanf("%f",&deposited_money);

                accounts[i].balance += deposited_money;
                printf("The money has been deposited successfully! Thank you for making us bank owners rich !\n");
                printf("Your balance is %f now.\n",accounts[i].balance);

        }


    }

    if (flag==0){

        printf("The account does not exist!\n");
    }


}




void Deposite2() {
    Account acc;
    int flag = 0;

    FILE *fh;
    FILE *fh2;

    fh = fopen(FILENAME, "r");
    fh2 = fopen("TEMPFILE.txt", "w"); // Use a temporary file for modifications.

    if (fh == NULL || fh2 == NULL) {
        printf("File does not exist!\n");
        return;
    }

    printf("Please let me know your account number!\n");
    int account_number;
    scanf("%d", &account_number); // Removed the `\n` in scanf as it was causing issues.

    while (fscanf(fh, "%s --- %d --- %s --- %d --- %d --- %f\n", acc.name, &acc.age, acc.nationality,
                  (int *)&acc.marital_status, &acc.account_number, &acc.balance) != EOF) {

        printf("Reading the file ...\n");

        if (acc.account_number == account_number) {
            flag = 1;
            printf("How much money do you want to deposit:\n");
            float deposited_money;
            scanf("%f", &deposited_money);

            printf("This is your current balance:\n");
            printf("%.2f\n", acc.balance);

            acc.balance += deposited_money;

            printf("This is your new balance:\n");
            printf("%.2f\n", acc.balance);
        }

        // Write the current account data to the new file.
        fprintf(fh2, "%s --- %d --- %s --- %d --- %d --- %.2f\n", acc.name, acc.age, acc.nationality,
                acc.marital_status, acc.account_number, acc.balance);
    }

    fclose(fh);
    fclose(fh2);


    if (!flag) {
        printf("Account number not found.\n");
    }



}


void Withdraw2(){

    Account acc;

    int flag=0;

    FILE *fh;
    FILE *fh2;

    fh = fopen(FILENAME,"r");
    fh2 = fopen("TEMPFILE.txt","w");

    if ( fh==NULL || fh2 ==NULL){

        printf("File does not exist.\n");
        return;
    }

    printf("Please lemmi know ur acount number:\n");

    int account_number;
    scanf("%d",&account_number);

    while (fscanf(fh, "%s --- %d --- %s --- %d --- %d --- %f\n", acc.name, &acc.age, acc.nationality,
                  (int *)&acc.marital_status, &acc.account_number, &acc.balance) != EOF){

        printf("Reading the file ...\n");

        if (acc.account_number == account_number )

        {
            flag=1;
            printf("How much you want to widthraw?!\n");
            float withdrown_money;
            scanf("%f",&withdrown_money);

            printf("This is your current balance %f:\n",acc.balance );

            acc.balance -= withdrown_money;

            printf("This is new current balance %f:\n",acc.balance );
        }


        // Write the current account data to the new file.
        fprintf(fh2, "%s --- %d --- %s --- %d --- %d --- %.2f\n", acc.name, acc.age, acc.nationality,
                acc.marital_status, acc.account_number, acc.balance);


        }


        fclose(fh);
        fclose(fh2);


    if (!flag){

        printf("No account found by this account number!\n");
    }


















}

void Withdraw(){


    printf("Please lemmi know the account number:\n");
    int account_number;
    scanf("%d",&account_number);

    int flag=0; // To check if the account exists

    for (int i=0; i < account_count; i++){

        if (accounts[i].account_number == account_number){
            flag = 1;
            printf("How much money do you want to widthraw?!\n");
            float widthrawed_money;
            scanf("%f",&widthrawed_money);

            float Total_balance = accounts[i].balance;


            if (  Total_balance - widthrawed_money > Minimum_credit  )
            {
                accounts[i].balance -= widthrawed_money;
                printf("The money is successfully withdrawn.\n");
                printf("The total balance is %.2f now.\n",accounts[i].balance);
            }

            else{

                printf("Oppps! you don't have enough credit in your account !\n");

            }

        }

    }


    if (flag==0){
        printf("The account does not exist!\n");
    }


}


















int main()
{


    printf("You have the following options!\n");
    printf("1. Create an account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Search an account\n");
    printf("5. Display an account\n");

    int choice;


    while(1){


    printf("Please choose your banking operation:\n");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            create_account();
            break;

        case 2:
            Display();
            break;

        case 3:
            Deposite2();
            break;

        case 4:
            Withdraw2();
            break;

        //case 5:
            //Display();
            //break;

        case 5:
            printf("invalid choice:\n");
            break;

        default:
            exit(0);


    }

}
}































