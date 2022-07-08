#include <stdio.h>
#include <iostream>

using namespace std;

/*
	Baekjoon Algorithm 1712�� ����
	A, B, C�� �־����� ��, ���ͺб����� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
	���� ��ũ : https://www.acmicpc.net/problem/1712
*/

const int LIMIT_PRICE = 2100000000;

int main()
{
	unsigned long A = 0;
	unsigned long B = 0;
	unsigned long C = 0;
	unsigned long breakEvenPoint = 0;
	// �Է� ���� �޾� ������ ����
	cin >> A >> B >> C;

	if (B >= C)
	{
		cout << "-1";
		return 0;
	}

	// �Է� ���� 21�� �̻��� ��� 21������ ����
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