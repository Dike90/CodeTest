#include <iostream>
using namespace std;
int main(){
    int n;
    double u,v;
    cin>>n;
    cin>>v;
    cin>>u;
    double c[n];
    double d[n];
    for(int i =0; i< n; i++){
        cin>>c[i];
    }
    cin.get();
    for(int i =0; i< n; i++){
        cin>>d[i];
    }
    cin.get();
    double dis = u * n;
    double tt;
    for(int i =0; i< n ; i++){
        tt += dis / (c[i] - i* d[i] - v);
    }
    cout<<tt;

    while(1);
    return 0;
}