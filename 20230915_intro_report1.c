#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int scores[10];
    int sum = 0;
    double average;

    srand(time(NULL));
    printf("학생 10명의 성적:\n");
    for(int i = 0; i < 10; i++) {
        scores[i] = rand() % 101;
        printf("%d번 학생: %d점\n", i + 1, scores[i]);
        sum += scores[i];
    }

    average = (double)sum / 10.0;
    printf("\n전체 학생의 평균 점수: %.2f점\n", average);

    return 0;
}