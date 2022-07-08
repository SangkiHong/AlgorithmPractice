#include <stdio.h>
#include <iostream>

using namespace std;

/*
	Baekjoon Algorithm 2292번 문제
	숫자 N이 주어졌을 때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오.
	문제 링크 : https://www.acmicpc.net/problem/2292
*/
int main()
{
	unsigned int targetNum = 0;

	cin >> targetNum;

	if (targetNum > 1000000000) return 0;
	else if (targetNum == 1)
	{
		cout << 1;
		return 0;
	}

	unsigned int currentNum = 1;
	for (int i = 0; i < INT16_MAX; i++)
	{
		if (currentNum < targetNum && targetNum <= currentNum + (i * 6))
		{
			cout << i + 1;
			break;
		}
		currentNum += (i * 6);
	}

	return 0;
}