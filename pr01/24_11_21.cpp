#include <iostream>
#include <algorithm>
using namespace std;


int N[11] = {0};

int search_rec(int x, int *a) {
    //int static a[100] = {0};
    if (x == 0) {return 0;};
    if (x < 0) { return 2147483647; }
    else {
        if (a[x]  > 0) { return a[x] ; }
        else {
            a[x] = 1 + min(min(search_rec(x - 1, a), search_rec(x - 5,a)), min(search_rec(x - 7,a), search_rec(x - 10,a)));
        };
    };
    return a[x];
};



int money(int x,int *a,int *N){
    if (a[x]==0){return 0;};
    if((a[x-10] == a[x]-1) && (x-10>=0) ) { ++N[10];return money(x-10,a,N);};
    if((a[x-7] == a[x]-1) && (x-7>=0) ){ ++N[7];return money(x-7,a,N);};
    if((a[x-5] == a[x]-1) && (x-5>=0) ){ ++N[5];return money(x-5,a,N);};
    if((a[x-1] == a[x]-1) && (x-1>=0) ){ ++N[1];return money(x-1,a,N);};
    return 0;
}
void  print(int *N){
    int i = 0;
    while(i<=10){
        while(N[i]!=0){
            cout<<i<<' ';
            --N[i];
        };
        ++i;
    };
};

int main()
{
    int static a[100] = {0};
    int n;
    cin >> n;
    search_rec(n,a);
    money(n,a,N);
    print(N);
    return 0;
}
