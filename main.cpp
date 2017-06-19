#include <iostream>
#include <vector>
#include <algorithm>
#include "mingw.thread.h"
#include <time.h>

using namespace std;
int amount;
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
    amount = amount+count;
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
    long beginTime = clock();
    int x, y, z, w;
    std::thread t1(primer, 1, 6000000);
    std::thread t2(primer, 6000001, 10000000);
    t1.join();
    t2.join();
    cout << "amount is " << amount << endl;
    long endTime = clock();
    cout << "time: "<< endTime - beginTime << endl;
    return 0;
}