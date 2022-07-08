#include <stdio.h>
#include <iostream>

using namespace std;

/*
	Baekjoon Algorithm 2292�� ����
	���� N�� �־����� ��, ������ �߾� 1���� N�� ����� �ּ� ������ ���� ������ �� �� �� ���� ���� ����������(���۰� ���� �����Ͽ�)�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� ��ũ : https://www.acmicpc.net/problem/2292
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