#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "mingw.thread.h"
#include <pthread.h>
#include <time.h>

using namespace std;

void* primer(void* arg);

int amount;

void* primer(void* arg)
{
    int count = 0;
    int j,k,i;
//    int min,max;
//    cout << "ref is" << ref << " &ref is " << &ref<< endl;
    int max = *((int**)arg)[1];
    int min = *((int**)arg)[0];
//    for(i = 0; i<2; i++ ); {
//        max[i] = *((int**)arg)[i];
//    }

//    *((int*)(&arg));
//    cout << "ref is " << refi << endl;
//    if(m >= n) {
//        max = m;
//        min = n;
//    }else {
//        max = m;
//        min = n;
//    }

    vector<int> primers;

    for(i = min ;i <= max ;i = i + 2)
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
    return NULL;
}



int main()
{
    long beginTime = clock();
//    cout << "input numbers:\n";
//    cin >> x >> y;
//    cin >> z >> w;

    int res;
    int x = 1;
    int y = 6000000;
    int z = 6000001;
    int w = 10000000;
    void* pnum[2] = {&x, &y};
    void* pnum2[2] = {&z, &w};
    pthread_t threads[2];
    void *thread_result;
    pthread_create(&threads[0], NULL, primer, (void *)pnum);
    pthread_create(&threads[1], NULL, primer, (void *)pnum2);
    /*if (res != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }*/
    printf("Waiting for thread to finish...\n");
    res = pthread_join(threads[0], &thread_result);
    res = pthread_join(threads[1], &thread_result);
    if (res != 0) {
        perror("Thread join failed");
        exit(EXIT_FAILURE);
    }
//    printf("Thread joined, it returned %s\n", (char *)thread_result);

    long endTime = clock();
    cout << "amount is " << amount << endl;
    cout << "time is " << endTime - beginTime << endl;
    exit(EXIT_SUCCESS);

    return 0;
}