#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Baekjoon Algorithm 1059번 문제
	문제 링크 : https://www.acmicpc.net/problem/1059
	* 문제: 정수 집합 S가 주어졌을때, 다음 조건을 만족하는 구간 [A, B]를 좋은 구간이라고 한다.
			- A와 B는 양의 정수이고, A < B를 만족한다.
			- A ≤ x ≤ B를 만족하는 모든 정수 x가 집합 S에 속하지 않는다.
		   집합 S와 n이 주어졌을 때, n을 포함하는 좋은 구간의 개수를 구해보자.
	* 입력: 첫째 줄에 집합 S의 크기 L이 주어진다. 둘째 줄에는 집합에 포함된 정수가 주어진다. 셋째 줄에는 n이 주어진다.
	* 출력: 첫째 줄에 n을 포함하는 좋은 구간의 개수를 출력한다.
	* 제한: 
		- 1 ≤ L ≤ 50
		- 집합 S에는 중복되는 정수가 없다.
		- 집합 S에 포함된 모든 정수는 1보다 크거나 같고, 1,000보다 작거나 같다.
		- 1 ≤ n ≤ (집합 S에서 가장 큰 정수)
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