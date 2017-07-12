#include <iostream>
#include <cstring>
using namespace std;
class Solution {
public:
	void replaceSpace(char *str,int length) {
        int cnt =0;
        char copy[length];
        memcpy(copy,str,length);
        int i=0,j=0;
        while( i < length){
            if( copy[i] != ' ') str[j++] = copy[i];
            else{
                str[j++] = '2';
                str[j++] = '0';
                str[j++] = '%';
            }
            i++;
        }
        str[j] = '\0';
	}
	void replaceSpace2(char *str,int length) {
        int len = strlen(str);
	}    
};

int main(){
    char str[] = "we will win! ";
    Solution test;
    test.replaceSpace(str,13);
    cout << str<<endl;
    cout<< strlen(str);

    while(1);
    return 0;
}