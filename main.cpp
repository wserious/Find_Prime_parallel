#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void primer(int m);

void primer(int m)
{
    int count = 0;
    int j,k,i;
    int min,max;

    vector<int> primers;

    for(i = 1 ;i <= m;i = i + 2)
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
    for( i = 0; i < count; i++)
    {
        cout << primers[i] ;
        if(i < count - 1)
            cout << " ";
        else
            cout << endl;
    }

}
int main()
{
    int x, y;
    cout << "please input number:\n";
    cin >> x;
    primer(x);
    return 0;
}