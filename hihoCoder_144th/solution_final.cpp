#include <iostream>
using namespace std;

struct factor{
    long num;
    long times;
    factor  *next;
    factor(long n){
        num = n;
        times = 1;
        next = nullptr;
    }
};

void getPrimeFactors(factor* array, long num){
    factor *current = array;
    long indx = 2;
    while(indx <= num & num != 1){
        if(num % indx == 0){
            if(current->num == indx){
                current->times ++;
            }
            else{
                current->next = new factor(indx);
                current = current->next;
            }
            num /= indx;
        }
        else
        {
            indx ++;
        }
    }
}

long getTotalNum(factor* array){
    factor* current = array;
    long num = 1;
    while(current->next!= nullptr)
    {
        num *= (current->next->times + 1);
        current = current->next;
    }
    return num;
}

int main(){
    
    long N,M;
    cin >> N >> M;
    long numN = 1;
    long numM = 1;
    long base;
    long chance = 1;
    
    factor *pN = new factor(1);
    pN->times = 0;
    factor *pM = new factor(1);
    pM->times = 0;
    
    getPrimeFactors(pN, N);
    getPrimeFactors(pM, M);
    
    numN = getTotalNum(pN);
    numM = getTotalNum(pM);
    base = numM * numN;
    
    factor* current = pM;
    factor *common = pN;
    factor *tmp = nullptr;
    while(current->next!= nullptr && common->next != nullptr){
        if(current->next-> num != common->next->num){
            if(current->next->num < common->next->num)
                current = current->next;
            else{
                tmp = common->next;
                common->next = common->next->next;
                delete tmp;
            }
        }
        else{
            common = common->next;
            current = current->next;
            if(common->times > current->times){
                common->times = current->times;
            }
         
        }
    }
    if(current->next == nullptr)
        common ->next = nullptr;
    
    chance = getTotalNum(pN);
    
    long f = 2;
    while(f <= chance){
        if(base % f == 0 && chance % f == 0){
            base /= f;
            chance /= f;
        }
        else
            f++;
    }
    cout << base << ' '<< chance << endl;
    return 0;
}
