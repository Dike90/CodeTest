#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int>> array);
};
//矩阵是有序的，从左下角开始查找
bool Solution::Find(int target, vector<vector<int>> array){
    int row = array.size();
    int col = array[0].size();
    int i= row -1,j=0;
    while(i >= 0 && j < col){
        if( array[i][j] < target) j++; //如果当前值小于target，那么目标值一定在它右边
        else if (array[i][j] > target) i--; //如果当前值大于target，那么目标值一定在它上边
        else return true; 
    }
    return false;
}

int main(){
    Solution test;
    vector<vector<int>> arr(8);
    for(int i=0; i< 8; i++){
        for(int j = 0; j < 8; j++){
            arr[i].push_back(i+j);
        }
    }
    for(int i = 0 ; i< 8 ; i++) {
        for( int j =0; j < 8 ; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
        
    cout << test.Find(0,arr)<<endl;
    while(1);
    return 0;
}