#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Baekjoon Algorithm 1059�� ����
	���� ��ũ : https://www.acmicpc.net/problem/1059
	* ����: ���� ���� S�� �־�������, ���� ������ �����ϴ� ���� [A, B]�� ���� �����̶�� �Ѵ�.
			- A�� B�� ���� �����̰�, A < B�� �����Ѵ�.
			- A �� x �� B�� �����ϴ� ��� ���� x�� ���� S�� ������ �ʴ´�.
		   ���� S�� n�� �־����� ��, n�� �����ϴ� ���� ������ ������ ���غ���.
	* �Է�: ù° �ٿ� ���� S�� ũ�� L�� �־�����. ��° �ٿ��� ���տ� ���Ե� ������ �־�����. ��° �ٿ��� n�� �־�����.
	* ���: ù° �ٿ� n�� �����ϴ� ���� ������ ������ ����Ѵ�.
	* ����: 
		- 1 �� L �� 50
		- ���� S���� �ߺ��Ǵ� ������ ����.
		- ���� S�� ���Ե� ��� ������ 1���� ũ�ų� ����, 1,000���� �۰ų� ����.
		- 1 �� n �� (���� S���� ���� ū ����)
*/

int main()
{
    int length;
    int n;
    int s, e;
    bool b = true;

    cin >> length;

    vector<int> v(length);

    for (int i = 0; i < length; i++) {
        cin >> v[i];
    }
    v.push_back(0);

    cin >> n;

    sort(v.begin(), v.end());
    for (int i = 1; i < length + 1; i++) {
        if (n == v[i]) b = false;
        else if (n < v[i]) {
            s = v[i - 1] + 1;
            e = v[i] - 1;
            break;
        }
    }

    if (b) cout << (n - s) * (e - n + 1) + (e - n);
    else cout << 0;

    return 0;
}