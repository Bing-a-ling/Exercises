//给定字符串，求它的回文子序列个数。回文子序列反转字符顺序后仍然与原序列相同。例如字符串aba中，回文子序列为"a", "a", "aa", "b", "aba"，共5个。内容相同位置不同的子序列算不同的子序列。
//输入
//第一行一个整数T，表示数据组数。之后是T组数据，每组数据为一行字符串。

//输出
//对于每组数据输出一行，格式为"Case #X: Y"，X代表数据编号（从1开始），Y为答案。答案对100007取模。


//  main.cpp

#include<iostream>
using namespace std;
int len(char *str);
int check(char*strings,int length);
int check_(char *strings,int length);

int main(){
    int Times,i;
    cin>>Times;
    cin.clear();
    cin.ignore(1024,'\n');
    char *strings=new char[Times*1001];
    for (i=0; i<Times; i++) {
        
        cin.getline(strings+i*1001, 1001, '\n');
    }
    for(i=0;i<Times;i++)
    {
        int length,sum=0;
        length=len(strings+1001*i);
        sum=check_(strings+1001*i,length);
        cout<<"Case #"<<i+1<<": "<<sum%100007<<endl;
    }
    delete []strings;
}

int check_(char *strings,int length){
    int sum;
    if (length==0) {
        return 0;
    }
    else {
        sum=check(strings,length)+check_(strings+1,length-1);
        return sum;}
}

int check(char*strings,int length){
    int sum1=0,sum2=0;
    char ch;
    if (length==1) {
        return 1;
    }
    ch=*strings+length-1;
    if (*strings==*(strings+length-1)) {
        sum1=1+check_(strings+1, length-2);
        return sum1+check(strings,length-1);
    }
    else sum2=check(strings,length-1);
    return sum2;
}
int len(char *str){
    int i,length=0;
    
    for (i=0; str[i]!='\0'; i++) {
        length++;
    }
    return length;
}
