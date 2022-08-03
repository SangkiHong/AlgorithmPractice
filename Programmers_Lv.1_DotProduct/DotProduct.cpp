#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
	Programmers Lv.1 내적 구하기
	URL : https://school.programmers.co.kr/learn/courses/30/lessons/70128
	* 문제: 이가 같은 두 1차원 정수 배열 a, b가 매개변수로 주어집니다. a와 b의 내적을 return 하도록 solution 함수를 완성해주세요.
		   이때, a와 b의 내적은 a[0]*b[0] + a[1]*b[1] + ... + a[n-1]*b[n-1] 입니다. (n은 a, b의 길이)
*/

// a_len은 배열 a의 길이입니다.
// b_len은 배열 b의 길이입니다.
int solution(int a[], int a_len, int b[], int b_len) {
    int answer = 0;
    for (int i = 0; i < a_len; i++)
        answer += a[i]*b[i];
    
    return answer;
}

int main()
{
    int a[4] = {1, 2, 3, 4};
    int b[4] = {-3, -1, 0, 2};
    printf("&d",solution(a, 4, b, 4));
}