#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

/*
	Baekjoon Algorithm 1977번 문제
	문제 링크 : https://www.acmicpc.net/problem/1977
	* 문제: M과 N이 주어질 때 M이상 N이하의 자연수 중 완전제곱수인 것을 모두 골라 그 합을 구하고 그 중 최솟값을 찾는 프로그램을 작성하시오. 
		   예를 들어 M=60, N=100인 경우 60이상 100이하의 자연수 중 완전제곱수는 64, 81, 100 이렇게 총 3개가 있으므로 그 합은 245가 되고 이 중 최솟값은 64가 된다.
	* 입력: 첫째 줄에 M이, 둘째 줄에 N이 주어진다. M과 N은 10000이하의 자연수이며 M은 N보다 같거나 작다.
	* 출력: M이상 N이하의 자연수 중 완전제곱수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최솟값을 출력한다.
		   단, M이상 N이하의 자연수 중 완전제곱수가 없을 경우는 첫째 줄에 -1을 출력한다.
*/

int main()
{
	int m, n;
	int sum = 0; // 완전제곱수의 합
	int min = 0; // 최소 완전제곱수
    float sqrt_m = 0; // m의 루트 값
	float sqrt_n = 0; // n의 루트 값

	cin >> m;
	cin >> n;

	if (m >= 10000 || n >= 10000)
	{
		cout << "N 또는 M이 10000보다 크거나 같습니다.";
		return 0;
	}

	sqrt_m = sqrt(m);
	sqrt_n = sqrt(n);

	// 완전제곱수를 저장할 변수
	int squareNum = 0;
	for (int i = 0; i < 100; i++)
	{
		// m 보다 크거나 같거나, n 보다 작거나 같은 경우
		if (sqrt_m <= i && i <= sqrt_n)
		{
			squareNum = i * i;
			// 최솟값 변수에 저장
			if (min == 0) min = squareNum;
			sum += squareNum;
		}
	}

	// 완전제곱수가 없는 경우 -1을 리턴
	if (min == 0)
	{
		cout << -1;
		return 0;
	}

	// 완전제곱수들의 합을 출력
	cout << sum << endl;

	// 완전제곱수 중 최솟값 출력
	cout << min << endl;

	return 0;
}