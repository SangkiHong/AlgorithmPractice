#include <iostream>
#include <cmath>

using namespace std;

/*
	Baekjoon Algorithm 1064�� ����
	���� ��ũ : https://www.acmicpc.net/problem/1064
	* ����: ����纯���� ������ �� ���� ���� �簢���̴�. �� ���� ���� �ٸ� ���� �־�����. A(xA,yA), B(xB,yB), C(xC,yC)
			�̶�, ������ �� D�� ã�Ƽ� �� ������ ����纯���� ����� �ȴ�. �̶�, D�� ���� �� ���� ���� �ִ�.
			������� ��� �簢�� �� ���� ū �ѷ� ���̿� ���� ���� �ѷ� ������ ���̸� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. ���� ���� �� �ִ� ����纯���� ���ٸ� -1�� ����Ѵ�.
	* �Է�: ù° �ٿ� xA yA xB yB xC yC�� �־�����. ��� ������ 5000���� �۰ų� ���� �����̴�.
	* ���: ù° �ٿ� ������ ������ ����Ѵ�. ����/��� ������ �ʾ���� �ϱ��� ����Ѵ�.
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

	// ���Ⱑ ���� ���
	if (m1 == m2)
	{
		cout << -1 << '\n';
		return 0;
	}

	// 3���� ��
	double distA = Dist(A.x, A.y, B.x, B.y);
	double distB = Dist(A.x, A.y, C.x, C.y);
	double distC = Dist(B.x, B.y, C.x, C.y);

	// 3�� �� �� 2�� ��� ���� �纯�� ������� �� �ѷ� ����
	double len1 = 2 * (distA + distB);
	double len2 = 2 * (distB + distC);
	double len3 = 2 * (distC + distA);

	cout << fixed;
	cout.precision(16);

	cout << max(len1, max(len2, len3)) - min(len1, min(len2, len3)) << '\n';

	return 0;
}