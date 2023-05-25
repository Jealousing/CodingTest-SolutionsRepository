﻿#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <vector>
using namespace std;

/*
Problem Number: 1269

Problem Description :
자연수를 원소로 갖는 공집합이 아닌 두 집합 A와 B가 있다. 이때, 두 집합의 대칭 차집합의 원소의 개수를 출력하는 프로그램을 작성하시오. 
두 집합 A와 B가 있을 때, (A-B)와 (B-A)의 합집합을 A와 B의 대칭 차집합이라고 한다.
예를 들어, A = { 1, 2, 4 } 이고, B = { 2, 3, 4, 5, 6 } 라고 할 때,  A-B = { 1 } 이고, B-A = { 3, 5, 6 } 이므로, 대칭 차집합의 원소의 개수는 1 + 3 = 4개이다.

Link: https://www.acmicpc.net/problem/1269

Input:
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다. 둘째 줄에는 집합 A의 모든 원소가, 
셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다.각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.

Output:
첫째 줄에 대칭 차집합의 원소의 개수를 출력한다.

Limit: none
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
    int N, M;
	cin >> N >> M;

    set<int> data1;
    set<int> data2;
    int data1Size = 0;
    int data2Size = 0;


    for (int i = 0; i < N; ++i)
    {
        int temp;
        cin >> temp;
        data1.insert(temp);
    }
    data1Size = data1.size();
    for (int i = 0; i < M; ++i)
    {
        int temp;
        cin >> temp;
        data2.insert(temp);
    }
    data2Size = data2.size();

    for (const auto& element : data2) {
        if (data1.find(element) != data1.end()) {
            data1Size--;
        }
    }
    for (const auto& element : data1) {
        if (data2.find(element) != data2.end()) {
            data2Size--;
        }
    }

    cout << data2Size+ data1Size << '\n';

	return 0;
}