#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <omp.h>
#include <cmath>

using namespace std;
bool goToNext;

void primer(int m);

void primer(int m) {
    int count = 0;
    int j, k, i;
    int min, max;

    vector<int> primers;
#pragma omp parallel for
    for (i = 1; i <= m; i += 2) {
        k = sqrt(i);
        goToNext = false;
        int j_result = 0;
//#pragma omp parallel for
        for (j = 2; j <= k; j++) {
            if (goToNext) {
                continue;
            }
            if (i % j == 0) {
                j_result = j;
                goToNext = true;
            }
        }

        if (j_result != 0) {
            j = j_result;
        }
            if (j >= k + 1) {
                count++;
                primers.push_back(i);

            }
    }

    cout << count << endl;
}

int main() {
    long beginTime = clock();
    int x, y;
    x = 1000;
    cout << x << endl;
//    cout << "please input number:\n";
//    cin >> x;
//#pragma omp parallel
    { primer(x); }
    long endTime = clock();
    cout << "time is: " << endTime - beginTime << endl;
    return 0;
}