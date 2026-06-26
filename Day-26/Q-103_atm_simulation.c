#include <stdio.h>

int main() {
    int choice;
    float balance = 5000.0, amount;

    printf("--- Welcome to ATM ---\n");
    printf("1. Check Balance\n");
    printf("2. Withdraw Money\n");
    printf("3. Deposit Money\n");
    printf("4. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Your current balance is: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount > balance) {
                    printf("Insufficient balance!\n");
                } else {
                    balance -= amount;
                    printf("Withdrawal successful. Remaining balance: %.2f\n", balance);
                }
                break;
            case 3:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                printf("Deposit successful. New balance: %.2f\n", balance);
                break;
            case 4:
                printf("Thank you for using our ATM!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);

    return 0;
}