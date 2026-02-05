#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#define PEOPLE 18



typedef struct {
    char big[20];        // 1. 기지중대 2. 대대본부 3. 작지
    char mid[20];        // 1.보급반 수송반 공병 2.군경 인행 화지 3.레이더 캐리어 기상관측
    char name[20];
    int num;
} soldier;

soldier br[18] = {
    {"기지중대", "보급반", "조준영", 860},
    {"기지중대", "보급반", "최주엽", 868}, 
    {"기지중대", "보급반", "김수민", 870},

    {"기지중대", "수송병", "누구지", 870},

    {"기지중대", "공병", "최재영", 861},
    {"기지중대", "공병", "김성우", 871},
    {"기지중대", "공병", "박호진", 860},

    {"대대본부", "군사경찰", "최효민", 870},
    {"대대본부", "군사경찰", "전이현", 869}, 
    {"대대본부", "군사경찰", "민태훈", 869},
    {"대대본부", "군사경찰", "조재인", 868},

    {"대대본부", "인사행정", "오종현", 871},

    {"대대본부", "화지병", "누구", 870},

    {"작전지역", "레이더", "이진우", 870},

    {"작전지역", "캐리어", "이강빈", 870},
    {"작전지역", "캐리어", "이우주", 871},

    {"작전지역", "기상관측", "박민수", 860},
    {"작전지역", "기상관측", "윤태빈", 871},

};

soldier findsol(char *guess, soldier *br); 
int printer2(soldier target, soldier guesser);

int game() {
    int random = rand() % PEOPLE;
    int maxScore = 1000;
    int chance = 1;
    int ending = 0;
    char guess[20] = "";
    soldier guesser;
    soldier target= br[random];

    while (chance <7) {
        time_t start_time = time(NULL);
        printf("입력: ");
        scanf("%s", guess);
        guesser = findsol(guess, br);
        ending = printer2(target, guesser);
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

int printer2 (soldier target, soldier guesser) {
    int good = 0;

    int targetNum = target.num;
    int guessNum = guesser.num;
  
        if (strcmp(target.big, guesser.big) == 0) {
            printf("\033[102;30m %s \033[0m ", guesser.big);
            good +=100;
        }
        else {
            printf("\033[101;30m %s \033[0m ", guesser.big);
        }

        if (strcmp(target.mid, guesser.mid) == 0) {
            printf("\033[102;30m %s \033[0m ", guesser.mid);
            good += 10;
        }
        else {
            printf("\033[101;30m %s \033[0m ", guesser.mid);
        }

        if (strcmp(target.name, guesser.name) == 0) {
            printf("\033[102;30m %s \033[0m ", guesser.name);
            good += 1;
        }
        else {
            printf("\033[101;30m %s \033[0m ", guesser.name);
        }

        if (targetNum == guessNum) {
            printf("\033[102;30m %d \033[0m \n\n", guessNum);
        }
        else if (targetNum < guessNum) {
            printf("\033[101;30m %d보다 선임입니다. \033[0m \n\n", guessNum);
        }
        else if (targetNum > guessNum) {
            printf("\033[101;30m %d보다 후임입니다. \033[0m \n\n", guessNum);
        }
        
    
    if (good == 111) {
        return 1;
    }
    return 0;
}

soldier findsol(char *guess, soldier *guesser) {
    for (int i=0; i<PEOPLE; i++) {
        if (strcmp(br[i].name, guess) ==0) {
            return br[i];
        }
    }
    soldier empty = { "", "", "", 0 }; 
    return empty;
}

int main() {
    srand(time(NULL));
    int highscore = 0;
    int score =0;
    printf("\n\n\n반갑습니다! 오늘의 Wordle을 시작해보겠습니다.\n\n");
    int choice =0;
    while (choice != 4) {
        printf("1. game start \n2. view high score \n3. end game\n\n ");
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