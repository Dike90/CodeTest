#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int main(){
    set<int> records;
    set<int>::iterator it;
    vector<int> result;
    int N;
    while(!cin.eof() && cin >>N ){
        cin.get();
        if(N==0) {
            result.push_back(-1);
            continue;
        }
        string line;
        bool b_err = false;
        int any = 0;
        int usedanyO = 0;
        int usedanyI = 0;
        for(int i=1; i<= N ; i++){
            getline(cin,line);
            istringstream text(line);
            char ctrl;
            text>>ctrl;
            int num = 0;
            if(!b_err){
                if(ctrl == 'I'){
                    text >> num;
                    it = records.find(num);
                    if(it == records.end()){
                        records.insert(num);
                    }
                    else{
                        if(num == usedanyI){
                            result.push_back(i);
                            b_err = true;
                            continue;
                        }
                        usedanyI = num;
                        any--;
                        if(any < 0){
                            result.push_back(i);
                            b_err = true;
                            continue;
                        }
                    }
                    
                }
                else if(ctrl == 'O'){
                    text >> num;
                    it = records.find(num);
                    if(it == records.end()){
                        if( usedanyO == num){
                            result.push_back(i);
                            //cout<<i<<endl;
                            b_err = true;
                            continue;                        
                        }
                        any--;
                        usedanyO = num;
                        if(any < 0){
                            result.push_back(i);
                            //cout<<i<<endl;
                            b_err = true;
                            continue;
                        }       
                    }
                    else{
                        records.erase(num);
                    }

                }
                else if(ctrl == '?'){
                    any++;
                }
            }                
        }
        if(!b_err)
            result.push_back(-1);
            //cout<<-1<<endl;
    }
    for(int i = 0 ; i< result.size(); i++){
        cout<<result[i]<<endl;
    }
    //while(1);
    return 0 ;
}