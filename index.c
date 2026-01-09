#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int decider(int x) {

    if (x<1) {
        return 0;
    }

    long long hubo = 1;
    for (int i=0; i<x; i++) {
        hubo*=2;
    }
    hubo-=1;

    int result=0;
    for (long long i=2; i*i<hubo; i++) {
        if (hubo%i==0) {
            result += i;
            return 0;
        }
    }
    if (result == 0) {
        return 1;
    }
    printf("%d", result);
}

int printer(int x, int result) {
    if (result==0) {
       
    }

    if (result == 1) {
        printf("2^%d -1은 메르센 소수입니다.\n", x);
    }
}

int main() {
    printf("메르센 소수를 찾아보겠습니다.\n\n\n");

    for (int i=2; i<100; i++) {
        int result=decider(i);
        printer(i,result);
    }

    printf("감사합니다.");
    return 0;
}