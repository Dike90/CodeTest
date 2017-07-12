#include <iostream>
#include <cmath>
using namespace std;
class Node{
public:
    Node(int key): key(key) {};
    Node() {};
    int key = -1;
    Node *right = NULL;
    Node *left = NULL;

};

Node& put(Node &x,int key){
    if(&x == NULL) return *(new Node(key));
    if(key < x.key) x.left = &(put(*(x.left),key));
    else if(key > x.key) x.right = &(put(*(x.right),key));
    else return x;
    return x;
}
int get(Node x, int key){
    //if(x.left == NULL && x.right == NULL) return x.key;
    if(key < x.key){
        if(x.left == NULL) return x.key;
        return get(*(x.left),key);
    } 
    else if(key > x.key){
        if(x.right == NULL) return x.key;
        return get(*(x.right),key);
    } 
    else return key;
    return key;
}

int difference(int a , int b){
    return pow(a-b,2);
}

int main(){
    Node root;
    int n1;
    cin>>n1;
    int *rhythm1 = new int[n1];
    for(int i = 0; i< n1; i++){
        cin>>rhythm1[i];
    }
    int n2;
    cin>>n2;
    int rhythm;
    cin>>root.key;
    for(int i=1; i< n2; i++){
        cin>>rhythm;
        root = put(root,rhythm);
    }
    int dif;
    int mindif;
    mindif = difference(get(root,rhythm1[0]),rhythm1[0]);
    for(int i = 1 ; i< n1; i++){
        dif = difference(get(root,rhythm1[i]),rhythm1[i]);
        if( dif < mindif ) mindif = dif;
        if(mindif==0)
            break;
    }
    cout<<mindif<<endl;

    while(1);
    return 0;
}