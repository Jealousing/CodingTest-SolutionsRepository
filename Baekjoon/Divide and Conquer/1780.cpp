﻿#include <iostream>
using namespace std;

/*
Problem Number: 1780

Problem Description :
N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

Link: https://www.acmicpc.net/problem/1780

Input:
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

Output:
첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

Limit: none

*/

/*
input:
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1

output:
10
12
11
*/

#define MAXSIZE 2187
int arr[MAXSIZE][MAXSIZE];
int n,cnt[3];

void DivideAndConquer(int begin, int end, int size)
{
    int flag = arr[begin][end];

    for (int i = begin; i < begin+size; i++)
    {
        for (int j = end; j < end+size; j++)
        {
            if (flag != arr[i][j])
            {
                int temp = size / 3;
                DivideAndConquer(begin, end, temp);
                DivideAndConquer(begin, end + temp, temp);
                DivideAndConquer(begin, end + 2 * temp, temp);
                DivideAndConquer(begin + temp, end, temp);
                DivideAndConquer(begin + temp, end + temp, temp);
                DivideAndConquer(begin + temp, end + 2 * temp, temp);
                DivideAndConquer(begin + 2 * temp, end, temp);
                DivideAndConquer(begin + 2 * temp, end + temp, temp);
                DivideAndConquer(begin + 2 * temp, end + 2 * temp, temp);
                return;
            }
        }
    }

    cnt[flag + 1]++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    DivideAndConquer(0, 0, n);

    for (int i = 0; i < 3; i++)
    {
        cout << cnt[i] << '\n';
    }

    return 0;
}