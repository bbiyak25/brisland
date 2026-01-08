#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int decider(int x) {

    int hubo = 1;
    for (int i=0; i<x; i++) {
        hubo*=2;
    }

    hubo--;
    int result=0;
    if (hubo<2) {
        return 0;
    }
    for (int i=1; i*i<x; i++) {
        if (hubo%i==0) {
            result += i;
            return 0;
        }
    }
    if (result == 0) {
        return 1;
    }
}

int printer(int x, int result) {
    if (result==0) {
       
    }

    if (result == 1) {
        printf("2^%d -1은 메르센 소수입니다.\n", x);
    }
}

int main() {
    printf("안녕!");

    for (int i=2; i<1000; i++) {
        int result=decider(i);
        printer(i,result);
    }
}