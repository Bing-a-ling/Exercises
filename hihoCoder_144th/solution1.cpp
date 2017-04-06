#include <iostream>
using namespace std;
int main(){
    
    long N,M;
    long numN = 0;
    long numM = 0;
    long base;
    long chance = 0;
    long indx;
    bool flag;
    cin >> N >> M;
    for(indx = 1; indx <= N || indx <= M; indx++){
        flag  = false;
        if(indx <= N){
            if(N % indx == 0){
                numN ++;
                flag = true;
            }
        }
        if(indx <= M){
            if(M % indx == 0){
                numM ++;
                if(flag){
                    chance++;
                }
            }
        }
    }
    base = numM * numN;
    long factor = 2;
    while(factor <= chance){
        if(base % factor == 0 && chance % factor == 0){
            base /= factor;
            chance /= factor;
        }
        else
            factor++;
    }
    cout << base << ' '<< chance << endl;
    return 0;
}
