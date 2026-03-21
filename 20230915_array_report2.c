#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double calAver(int scores[], int size);
int getStud(int scores[], int size, int studentNumber);
void printScore(int scores[], int size, double average, int option);
void delStud(int* scores, int size, int studentNumber);

int main(void) {
    int *scores;
    int size = 30;
    int capacity = 30;
    int choice;
    int studentNumber;

    scores = malloc(capacity * sizeof(int));
    if (!scores) {
        printf("allocation error\n");
        return 1;
    }

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        scores[i] = rand() % 101;
    }
    printf("입 력 완 료\n");

    while (1) {
        printf("---학 생  성 적  관 리  프 로 그 램---\n");
        printf("1. 학 생 정 보  추 가\n");
        printf("2. 학 생 정 보  삭 제\n");
        printf("3. 학 생 정 보  검 색\n");
        printf("4. 학 생 정 보  출 력(옵 션: 0, 1, 2)\n");
        printf("5. 프 로 그 램  종 료\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size >= capacity) {
                    capacity += 10;
                    int *newScores = realloc(scores, capacity * sizeof(int));
                    if (!newScores) {
                        printf("allocation error\n");
                        free(scores);
                        return 1;
                    }
                    scores = newScores;
                }
                scores[size++] = rand() % 101;
                printf("새 로 운  학 생  추 가: 번 호 - %d\n", size);
                break;

            case 2:
                printf("삭 제 할  학 생 번 호  입력(1~%d): ", size);
                scanf("%d", &studentNumber);
                delStud(scores, size, studentNumber);
                break;

            case 3: {
                printf("검 색 할  학 생 번 호  입력(1~%d): ", size);
                scanf("%d", &studentNumber);
                int score = getStud(scores, size, studentNumber);
                if (score != -1) {
                    printf("%d번 학생의 점수: %d\n", studentNumber, score);
                } else {
                    printf("해당 학생은 없는 학생입니다.\n");
                }
                break;
            }

            case 4: {
                int option;
                printf("옵 션  입 력 (0, 1, 2): ");
                scanf("%d", &option);
                double average = calAver(scores, size);
                printScore(scores, size, average, option);
                break;
            }

            case 5:
                free(scores);
                printf("프 로 그 램  종 료\n");
                return 0;

            default:
                printf("잘 못 된  입 력\n");
                break;
        }
    }

    return 0;
}

double calAver(int scores[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / (double)size;
}

int getStud(int scores[], int size, int studentNumber) {
    if (studentNumber >= 1 && studentNumber <= size && scores[studentNumber - 1] != -1) {
        return scores[studentNumber - 1];
    }
    return -1;
}

void printScore(int score[], int size, double average, int option) {
    switch (option) {
        case 0:
            for (int i = 0; i < size; i++) {
                if (score[i] != -1) {
                    printf("학 생 번 호: %d, 점 수: %d\n", i + 1, score[i]);
                }
            }
            break;

        case 1:
            printf("평균이상 학생\n");
            for (int i = 0; i < size; i++) {
                if (score[i] != -1 && score[i] >= average) {
                    printf("학 생 번 호: %d, 점 수: %d\n", i + 1, score[i]);
                }
            }
            break;

        case 2:
            printf("평균미만 학생\n");
            for (int i = 0; i < size; i++) {
                if (score[i] != -1 && score[i] < average) {
                    printf("학 생 번 호: %d, 점 수: %d\n", i + 1, score[i]);
                }
            }
            break;

        default:
            printf("유효하지 않은 옵션입니다.\n");
            break;
    }
}

void delStud(int* scores, int size, int studentNumber) {
    if (studentNumber < 1 || studentNumber > size) {
        printf("학 생 번 호  오 류\n");
        return;
    }
    if (scores[studentNumber - 1] == -1) {
        printf("없 는  학 생 입 니 다\n");
    } else {
        scores[studentNumber - 1] = -1;
        printf("%d번 학생의 정보가 삭제되었습니다.\n", studentNumber);
    }
}