#include <iostream>
#include <cmath>

using namespace std;

/*
	Baekjoon Algorithm 1064번 문제
	문제 링크 : https://www.acmicpc.net/problem/1064
	* 문제: 평행사변형은 평행한 두 변을 가진 사각형이다. 세 개의 서로 다른 점이 주어진다. A(xA,yA), B(xB,yB), C(xC,yC)
			이때, 적절히 점 D를 찾아서 네 점으로 평행사변형을 만들면 된다. 이때, D가 여러 개 나올 수도 있다.
			만들어진 모든 사각형 중 가장 큰 둘레 길이와 가장 작은 둘레 길이의 차이를 출력하는 프로그램을 작성하시오. 만약 만들 수 있는 평행사변형이 없다면 -1을 출력한다.
	* 입력: 첫째 줄에 xA yA xB yB xC yC가 주어진다. 모두 절댓값이 5000보다 작거나 같은 정수이다.
	* 출력: 첫째 줄에 문제의 정답을 출력한다. 절대/상대 오차는 십억분의 일까지 허용한다.
*/

double Dist(double Ax, double Ay, double Bx, double By) {
	return sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
}

struct Vector2
{
	double x;
	double y;
};

int main()
{
	Vector2 A;
	Vector2 B;
	Vector2 C;

	int ParallelogramPoints[6];

	for (int i = 0; i < 6; i++)
		cin >> ParallelogramPoints[i];

	A.x = ParallelogramPoints[0];
	A.y = ParallelogramPoints[1];

	B.x = ParallelogramPoints[2];
	B.y = ParallelogramPoints[3];

	C.x = ParallelogramPoints[4];
	C.y = ParallelogramPoints[5];

	double m1 = 1987654321, m2 = 1987654321;

	if (A.x != A.y) m1 = abs(B.y - A.y) / abs(B.x - A.x);
	if (B.x != B.y) m2 = abs(C.y - B.y) / abs(C.x - B.x);

	// 기울기가 같은 경우
	if (m1 == m2)
	{
		cout << -1 << '\n';
		return 0;
	}

	// 3개의 변
	double distA = Dist(A.x, A.y, B.x, B.y);
	double distB = Dist(A.x, A.y, C.x, C.y);
	double distC = Dist(B.x, B.y, C.x, C.y);

	// 3개 변 중 2개 골라서 평행 사변형 만들었을 때 둘레 길이
	double len1 = 2 * (distA + distB);
	double len2 = 2 * (distB + distC);
	double len3 = 2 * (distC + distA);

	cout << fixed;
	cout.precision(16);

	cout << max(len1, max(len2, len3)) - min(len1, min(len2, len3)) << '\n';

	return 0;
}