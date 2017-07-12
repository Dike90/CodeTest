#include <iostream>
#include <cmath>
using namespace std;

int difference(int *a, int N, int *b,int start){
    int sum = 0;
    for(int i=0; i< N ; i++){
        sum += pow(a[i] - b[start+i],2);
    }
    return sum;
}

int main(){
    int n1;
    cin>>n1;
    int *rhythm1 = new int[n1];
    for(int i = 0; i < n1; i++){
        cin>>rhythm1[i];
    }
    int n2;
    cin >> n2;
    int *rhythm2 = new int [n2];
    for(int i = 0; i< n2; i++){
        cin>>rhythm2[i];
    }
    int dif=0;
    int mindif;
    mindif = difference(rhythm1,n1,rhythm2,0);
    for(int i=1; i< n2 - n1; i++){
        dif = difference(rhythm1,n1,rhythm2,i);
        if(dif < mindif)    mindif = dif;
        if(mindif == 0) break;
    }
    cout<<mindif<<endl;

    //while(1);
    return 0;
}