
// 大学的同学来自全国各地，对于远离家乡步入陌生大学校园的大一新生来说，碰到老乡是多么激动的一件事，于是大家都热衷于问身边的同学是否与自己同乡，来自新疆的小赛尤其热衷。
// 但是大家都不告诉小赛他们来自哪里，只是说与谁同乡，从所给的信息中，你能告诉小赛有多少人确定是她的同乡吗？
// 输入
// 每个测试实例首先包括2个整数，N（1 <= N <= 1000），M(0 <= M <= N*(N-1)/2)，代表现有N个人（用1~N编号）和M组关系；
// 在接下来的M行里，每行包括2个整数，a，b，代表a跟b是同乡；
// 当N = 0，M = 0输入结束；
// 已知1表示小赛本人。
// 输出
// 对于每个测试实例，输出一个整数，代表确定是小赛同乡的人数。

//  Created by Cynthia on 2018/10/18.
//  Copyright © 2018年 Cynthia. All rights reserved.

#include <iostream>
using namespace std;
int getAncestor(int a[],int x){
    while(a[x]!=-1){
        x = a[x];
    }
    return x;
}

int main(int argc, const char * argv[]) {
    int N ;
    long M ;
    cin >> N >> M;

    while(N!= 0 || M!= 0){
        int *people = new int[N + 1];
        int *children = new int[N + 1];
        for(int i = 0; i <= N; i++){
            people[i] = -1;
            children[i] = 1;
        }
        int a, b;
        while(M){
            cin >> a >> b;
            int ra = getAncestor(people, a);
            int rb = getAncestor(people, b);
            if(ra != rb){
                people[rb] = ra;
                children[ra] += children[rb];
            }
            M--;

        }
        int rsai = getAncestor(people, 1);
        cout << children[rsai] - 1<<endl;
        delete[] people;
        delete[] children;
        cin >> N >> M;
    }

    return 0;
}
