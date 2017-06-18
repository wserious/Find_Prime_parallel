#include <iostream>
#include <vector>
#include <algorithm>
#include "mingw.thread.h"

using namespace std;

void primer(int m, int n)
{
    int count = 0;
    int j,k,i;
    int min,max;

    if(m >= n) {
        max = m;
        min = n;
    }else {
        max = n;
        min = m;
    }

    vector<int> primers;

    for(i = min ;i <= max;i = i + 2)
    {
        k = sqrt(i);
        for(j = 2;j <= k;j++)
        {
            if(i % j ==0)break;
        }
        if(j >= k + 1)
        {
            count++;
            primers.push_back(i);

        }
    }
    cout << count <<endl;
    /*for( i = 0; i < count; i++)
    {
        cout << primers[i] ;
        if(i < count - 1)
            cout << " ";
        else
            cout << endl;
    }*/

}
int main()
{
    int x, y, z, w;
    cout << "input four numbers:\n";
    cin >> x >> y;
    cin >> z >> w;
//    primer(x, y);
    std::thread t1(primer, x, y);
    std::thread t2(primer, z, w);
    t1.join();
    t2.join();
    return 0;
}