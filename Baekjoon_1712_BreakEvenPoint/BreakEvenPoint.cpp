#include <stdio.h>
#include <iostream>

using namespace std;

/*
	Baekjoon Algorithm 1712번 문제
	A, B, C가 주어졌을 때, 손익분기점을 구하는 프로그램을 작성하시오.
	문제 링크 : https://www.acmicpc.net/problem/1712
*/

const int LIMIT_PRICE = 2100000000;

int main()
{
	unsigned long A = 0;
	unsigned long B = 0;
	unsigned long C = 0;
	unsigned long breakEvenPoint = 0;
	// 입력 값을 받아 변수에 저장
	cin >> A >> B >> C;

	if (B >= C)
	{
		cout << "-1";
		return 0;
	}

	// 입력 값이 21억 이상인 경우 21억으로 제한
	if (A > LIMIT_PRICE)
		A = LIMIT_PRICE;
	if (B > LIMIT_PRICE)
		B = LIMIT_PRICE;
	if (C > LIMIT_PRICE)
		C = LIMIT_PRICE;

	unsigned long gap = C - B;
	breakEvenPoint = (A / gap) + 1;
	cout << breakEvenPoint;

	return 0;
}