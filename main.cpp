#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <omp.h>
#include <cmath>

using namespace std;

void primer(int m);

void primer(int m) {
    int count = 0;
    int j,k,i;
    int min,max;

    vector<int> primers;
#pragma omp parallel for
    for(i = 1 ;i <= m;i += 2) {
        k = sqrt(i);
#pragma omp parallel for
        for(j = 2;j <= k;j++) {
            if(i % j ==0) {
                break;
            }
        }
        if(j >= k + 1) {
            count++;
//#pragma omp ordered
            primers.push_back(i);
        }
    }
    cout << count <<endl;
   /* for( i = 0; i < count; i++)
    {
        cout << primers[i] ;
        if(i < count - 1)
            cout << " ";
        else
            cout << endl;
    }*/

}
int main() {
    long beginTime = clock();
    int x, y;
    x = 10000000;
    cout << x << endl;
//    cout << "please input number:\n";
//    cin >> x;
#pragma omp parallel
    {primer(x);}
    long endTime = clock();
    cout << "time is: " << endTime - beginTime << endl;
    return 0;
}