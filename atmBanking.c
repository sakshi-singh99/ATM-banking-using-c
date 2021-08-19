#include<stdio.h>
#include<windows.h>
#include<time.h>

int main(){
    system("COLOR B0");
    int pin=1234, option,enteredPin,count=0,amount=1;
    float balance=5000;
    int continueTransaction=1;

    time_t now;
    time(&now);
    printf("\n");
    printf("\t\t\t\t\t   %s",ctime(&now));
    printf("\n\t\t\t====================*Welcome to ATM Banking*=====================");
    

    while(pin!=enteredPin){
        printf("\n Please enter the pin: ");
        scanf("%d",&enteredPin);
        if(enteredPin!=pin){
            Beep(60,500);
            printf("Invalid Pin!");
        }
        count++;
        if(count==3 && pin!=enteredPin){
            exit(0);}
    }

    while(continueTransaction!=0){
         printf("\n\t\t\t\t==============*Available Transaction*==============");
        printf("\n\n\t\t1.Withdraw");
        printf("\n\n\t\t2.Deposit");
        printf("\n\n\t\t3.Check Balance");
        printf("\n\n\tPlease select the option: ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
                   printf("\n\t\t Enter the amount: ");
                   scanf("%d",&amount);
               if(balance<amount){
                   printf("\n\t Sorry insufficient balance");
                   amount=1;
                   break;}
            else{
                balance-=amount;
                printf("\n\t\tYou have withdraw Rs.%d.Your new balance is %.2f\n",amount,balance);
                printf("\n\t\t=========================Thank you for using our service=========================");
                amount=1;
                break;
            }
        case 2:
               printf("\n\t\tPlease enter the amount: ");
               scanf("%d",&amount);
               balance+=amount;
               printf("\nnt\t You have deposited Rs.%d.Yor new balance is %.2f\n",amount,balance);
               printf("\n\t\t=========================Thank you for using our service=========================");
               amount=1;
               break;
        case 3:
              printf("\n\t\t Your balance is Rs.%.2f\n",balance);
              printf("\n\t\t=========================Thank you for using our service=========================\n");
              break;
        default:
              Beep(610,500);
              printf("\n\t\t Invalid Option!");}
        printf("\nDo you wish to perform another transaction?For\n  Yes: Press 1\n  No: Press 0\n");
        scanf("%d",&continueTransaction);      
    }
            return 0;
}
       