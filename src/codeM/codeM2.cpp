#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int N ;
    cin >> N;
    int max = log2(N);
    //int *a = new int [N];
    int temp;
    int a0 ;
    cin>>a0;

    int cnt = 1;
    for(int i =1; i< N; i++){
        cin>>temp;
        if(a0 >= temp)
            cnt ++;
    }
    cout << (int)log2(cnt) <<endl;

   // while(1);
    return 0;
}