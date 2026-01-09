#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int printer();

int game() {
    int random = rand() % 20;
    int maxScore = 1000;
    int chance = 1;
    int ending = 0;
    char guess[7] = "";
    char words[20][7] = {
        "ACTION", "BOTTLE", "BRIDGE", "BRIGHT", "CHANCE",
        "COFFEE", "DANGER", "FLOWER", "FRIEND", "MARKET",
        "PLAYER", "POCKET", "PUBLIC", "SCHOOL", "SILENT",
        "SILVER", "STREET", "TARGET", "WINDOW", "YELLOW"
    };
    char *targetWord = words[random];

    while (chance <7) {
        time_t start_time = time(NULL);
        printf("입력: \n");
        scanf("%6s", guess);
        for (int i = 0; i < 6; i++) {
            guess[i] = toupper(guess[i]);
            }
        ending = printer(targetWord, guess);
        time_t end_time = time(NULL);
        chance ++;

        maxScore-=100;
        int tookTime = end_time - start_time;
        maxScore -= tookTime;
        if (tookTime <11) {
            maxScore += tookTime;
        }

        if (ending == 1) {
            maxScore += 1000;
            return maxScore;
        }
    }
    return maxScore;
}

int printer(char *targetWord, char *guess) {
    int howMany = 0;
    for (int i=0; i<6; i++) {
        if (guess[i] == targetWord[i]) {
            printf("\033[102;30m %c \033[0m ", guess[i]);
            howMany+=1;
        }

        else {
            int found = 0;
            for (int k=0; k<6; k++) {
                if (guess[i] ==targetWord[k]) {
                    found =1;
                    break;
                }
            }

            if (found) {
                printf("\033[103;30m %c \033[0m ", guess[i]);
            }
            else {
                printf("\033[101;30m %c \033[0m ", guess[i]);
            }
        }
    }
    printf("\n\n");
    if (howMany == 6) {
        return 1;
    }
    return 0;
}


int main() {
    srand(time(NULL));
    int highscore = 0;
    int score =0;
    printf("\n\n\n반갑습니다! 오늘의 Wordle을 시작해보겠습니다.\n\n");
    int choice =0;
    while (choice != 4) {
        printf("1. game start \n 2. view high score \n 3. end game\n\n ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("게임을 시작합니다.\n");
                score = game();
                if (highscore < score) {
                    highscore = score;
                    printf("축하합니다! 최고기록입니다!\n%d점이 기록되었습니다.\n\n", highscore);
                }
                break;
            case 2:
                if (highscore == 0) {
                    printf("아직 최고기록이 없습니다. 도전해보세요!\n");
                    break;
                }
                printf("현재 최고기록은 %d입니다.\n", highscore);
                break;
            case 3:
                printf("게임을 종료합니다.");
                choice =4;
                break;
        }
    }
}