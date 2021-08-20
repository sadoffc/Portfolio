//  Created by Connor Sadoff on 10/26/20
//  atm.c
//  CSC 345
//  Lab 2
//  This program will mimic an ATM machine by implementing the common functions seen in ATM machines

#include <stdio.h>
#include <stdlib.h>

//global variables
double balance = 5000;
int withdrawalAmt = 0;
int depositionAmt = 0;
int pin = 0;
int pinAttempts = 0;
int choice = 0;
int numTransactions = 0;
int withdrawalLimit = 0;
int depositionLimit = 0;
int receiptChoice = 0;
int invalidInputs = 0;

void balanceChoice() //prints balance
{
    printf("\nYour balance is: $%.2f\n", balance);
}

void cashWithdrawal() //can only withdrawal in multiples of $20. Limit of $1000
{
    printf("\nHow much would you like to withdrawal?: $");
    scanf("%d", &withdrawalAmt);
    
    if(withdrawalAmt <= 0) //checks for invalid numerical inputs
    {
        invalidInputs++;
        if(invalidInputs == 3)
        {
            printf("\nERROR! Too many unsuccessful inputs. Logging off...\n");
            exit(0);
        }
        printf("Please retry with a valid amount to withdrawal.\n"); 
    }
    else if(withdrawalAmt % 20 != 0) //checks that the withdrawal is a multiple of $20
    {
        printf("Sorry. ATM can only dispense $20 bills\n");
    }
    else if(withdrawalAmt > balance) //makes sure user has enough money in account to withdraw
    {
        printf("\nNot enough money to withdrawal.\n");
    }
    else
    {
        withdrawalLimit += withdrawalAmt; //tracks how much money has been withdrawn that day

        if(withdrawalLimit >= 1001)
        {
            printf("You have reached the withdrawal limit for the day.\n");
            withdrawalLimit -= withdrawalAmt; //resets daily withdrawal total
        }
        else
        {
            balance -= withdrawalAmt;
            numTransactions++;
            printf("\n\t1. Yes\n\t2. No\n\nWould you like a receipt?: ");
            scanf("%d", &receiptChoice);
        }
    }
}

void cashDeposition() //limit of $10000
{
    printf("\nHow much would you like to deposit?: $");
    scanf("%d", &depositionAmt);
    
    if(depositionAmt <= 0) //checks for invaid numerical inputs
    {
        invalidInputs++;
        if(invalidInputs == 3)
        {
            printf("\nERROR! Too many unsuccessful inputs. Logging off...\n");
            exit(0);
        }
        printf("Please retry with a valid amount to deposit.\n"); 
    }
    else
    {
        depositionLimit += depositionAmt; //tracks how much money has been deposited that day

        if(depositionLimit >= 10001)
        {
            printf("You have reached the deposition limit for the day.\n");
            depositionLimit -= depositionAmt; //resets daily deposition total
        }
        else
        {
            balance += depositionAmt;
            numTransactions++;
            printf("\n\t1. Yes\n\t2. No\n\nWould you like a receipt?: ");
            scanf("%d", &receiptChoice);
        }
    }

}

void quitChoice()
{
    printf("\nTotal number of transactions: %d\n", numTransactions);
    printf("Thank you!\n");
    exit(0);
}

int main(int argc, char* argv[])
{

    while(pinAttempts < 3) //allows three attempts to enter correct PIN number
    {
        printf("\nPlease enter PIN number: ");
        scanf("%d", &pin);

        if(pin == 3014) //correct PIN number
        {
            break;
        }
        else
        {
            printf("Invalid PIN number.\n"); 
            pinAttempts++;
        }
    }

    if(pinAttempts == 3) //Program ends if PIN is incorrect 3 times.
    {
        printf("\nNumber of login attempts exceeded. Logging off...\n");
        exit(0);
    }
    
    printf("\nWelcome! \n");
    
    while(0 < 1) //infinite while loop to keep taking transaction choices. Broken by quit choice.
    {
        printf("\n\t1. Balance \n\t2. Cash Withdrawal\n\t3. Cash Deposition\n\t4. Quit\n\n");
        printf("Please select a transaction: ");
        scanf("%d", &choice);

        if(choice == 1) //Balance choice
        {
            balanceChoice();
        }
        else if(choice == 2) //Cash Withdrawal
        {
            cashWithdrawal();
        }
        else if(choice == 3) //Case Deposition
        {  
            cashDeposition();
        }
        else if(choice == 4) //Quit 
        {
           quitChoice();
        }
        else //catches invalid input ex. user enters 5 or 10
        {
            printf("Please enter a valid menu option.\n");
        }
    }
   

}
