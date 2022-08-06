#include <string>
#include <vector>

/*
    Programmers Lv.2 문자열 압축
    URL : https://school.programmers.co.kr/learn/courses/30/lessons/60057
    * 문제: 압축할 문자열 s가 매개변수로 주어질 때, 위에 설명한 방법으로 1개 이상 단위로 문자열을 잘라 압축하여
           표현한 문자열 중 가장 짧은 것의 길이를 return 하도록 solution 함수를 완성해주세요.
*/

using namespace std;

int SplitString(int maxSplit, string *s);
typedef vector<char> stringData;

int solution(string s)
{
    int answer = 0;
    int buff = 0;

    buff = SplitString(1, &s);
    printf("%d로 쪼개었을 때 길이: %d\n", 1, buff);
    answer = buff;

    for (int i = 2; i < 11; i++)
    {
        buff = SplitString(i, &s);
        printf("%d로 쪼개었을 때 길이: %d\n", i, buff);
        if (answer > buff)
            answer = buff;
    }

    return answer;
}

int SplitString(int maxSplit, string *s)
{
    int patternCount = 0;
    int length = (*s).length();
    int startIndex = 0;
    stringData matchString;
    bool isMatch = false;
    int i = 0, j = 0;

    for (i = 0; i < length; i++)
    {
        if (startIndex + maxSplit > i && i < length - 1)
            continue;
        else if (startIndex + maxSplit <= i || i >= length - 1)
        {
            if ((*s)[i - maxSplit] == (*s)[i] && i < length - 1)
            {
                if (!isMatch)
                    isMatch = true;

                patternCount++;
            }
            else
            {
                if (isMatch)
                {
                    isMatch = false;

                    //분할 갯수가 2 이상인 경우
                    if (maxSplit > 1)
                    {
                        matchString.push_back((int)((i - (startIndex - 1)) / maxSplit));

                        for (j = startIndex; j < startIndex + maxSplit; j++)
                        {
                            matchString.push_back((*s)[j]);
                        }
                    }
                    // 분할 갯수가 1인 경우
                    else
                    {
                        if (i < length - 1)
                            patternCount++;
                        else
                            patternCount += 2;

                        // 다음 문자가 다른지 확인
                        if ((*s)[startIndex] != (*s)[i] || i >= length - 1)
                        {
                            matchString.push_back(patternCount);
                            matchString.push_back((*s)[startIndex]);
                            patternCount = 0;
                        }
                    }
                    startIndex = i;
                }
                else
                {
                    for (j = startIndex; j < i; j++)
                    {
                        matchString.push_back((*s)[j]);
                        if (j == length - 2)
                            matchString.push_back((*s)[i]);
                    }
                    startIndex = i;
                }
            }
        }
        else
            startIndex = i;
    }
    for (i = 0; i < matchString.size(); i++)
        printf("%c", matchString.at(i));
    
    printf("\n");
    
    return matchString.size();
}

int main()
{
    solution("xababcdcdababcdcd");

    return 0;
}