#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;

const int N = 10010;

int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
//        while (!max_heap.empty()) max_heap.pop();
//        while (!min_heap.empty()) min_heap.pop();
        int m, n;
        cin >> m >> n;
        priority_queue<int> max_heap;
        priority_queue<int, vector<int>, greater<int>> min_heap;

        printf("%d %d \n",m,(n+1)/2);

        int num;
        for (int i = 1; i <= n; i++) {
            cin>>num;
            min_heap.push(num);
            if (i%2==1){
                while(min_heap.size()>max_heap.size()+1){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                }

                printf("%d ",min_heap.top());
            }
        }

        puts("");
        }

    }
