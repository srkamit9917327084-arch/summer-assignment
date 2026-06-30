#include <stdio.h>

#define TOTAL_SEATS 10

int seats[TOTAL_SEATS] = {0}; // 0 = Available, 1 = Booked

void showSeats() {
    printf("\n--- Seat Status (0: Available, 1: Booked) ---\n");
    for(int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %d: %s\n", i+1, (seats[i] == 0 ? "Available" : "Booked"));
    }
}

void bookTicket() {
    int seatNum;
    printf("Enter seat number (1-%d): ", TOTAL_SEATS);
    scanf("%d", &seatNum);

    if(seatNum < 1 || seatNum > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
    } else if(seats[seatNum-1] == 1) {
        printf("Sorry, seat %d is already booked.\n", seatNum);
    } else {
        seats[seatNum-1] = 1;
        printf("Seat %d booked successfully!\n", seatNum);
    }
}

int main() {
    int choice;
    while(1) {
        printf("\n--- Ticket Booking System ---\n");
        printf("1. View Seats\n2. Book Ticket\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: showSeats(); break;
            case 2: bookTicket(); break;
            case 3: return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}