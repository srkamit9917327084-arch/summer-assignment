#include <stdio.h>

int main() {
    int score = 0;
    int answer;

    printf("--- Quiz Application ---\n\n");

    printf("1. Where is g.l. bajaj?\n");
    printf("1. Delhi 2. Agra  3. Greater noida \n");
    printf("choose your answer (1/2/3): ");
    scanf("%d", &answer);
    if(answer == 2) {
        printf("Right answer!\n\n");
        score++;
    } else {
        printf("Wrong ans. write ans is 2 .\n\n");
    }

    printf("2. Which type of C language ?\n");
    printf("1. Low-level  2. High-level  3. Middle-level\n");
    printf("Choose your answer (1/2/3): ");
    scanf("%d", &answer);
    if(answer == 3) {
        printf("Right ans. !\n\n");
        score++;
    } else {
        printf("Wrong ans. Right ans. is 3\n\n");
    }

    printf("Quiz end: your total score is %d/2\n", score);

    return 0;
}