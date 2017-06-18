#include <iostream>
#include <vector>
#include <algorithm>
#include "mingw.thread.h"
#include <pthread.h>
#include <time.h>

using namespace std;
int amount;
void *primer(void* p_ref)
{
    int count = 0;
    int j,k,i;
    int min,max;
    int ref = *(int*)p_ref;
    cout << "ref is " << ref << endl;
//    if(m >= n) {
//        max = m;
//        min = n;
//    }else {
//        max = m;
//        min = n;
//    }

    vector<int> primers;

    for(i = 1 ;i <= ref;i = i + 2)
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
//    cout << "input numbers:\n";
//    cin >> x >> y;
//    cin >> z >> w;

    pthread_t threads[2];
    int p_ref = 10000;
    cout << "p_ref is " << p_ref << endl;
    int rc1 = pthread_create(&threads[1], NULL, primer , (void*)&p_ref);
    if(rc1) {
        cout << "Error: unbale to create thread, " << rc1 << endl;
        exit(-1);
    }
    pthread_exit(NULL);
    cout << "amount is " << amount << endl;
    long endTime = clock();
    cout << "time: "<< endTime - beginTime << endl;
    return 0;
}