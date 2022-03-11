#include <iostream>
using namespace std;
int searching_way( int nomber, int a[50] , int x[50], int n) {
     a[n - 1] = x[n - 1];
     a[n - 2] = x[n - 2];
     if ((nomber == n - 1)) {
         return a[n - 1];
     } else if (nomber == n - 2) {
         return a[n - 2];
     } else {
         if(nomber == -1){
             int u;
             u = min(searching_way(nomber + 1, a, x, n), searching_way(nomber + 2, a, x, n));
             return u;
         }
         else {
             if (a[nomber] > 0){
                 return a[nomber];
             }
             a[nomber] = x[nomber] + min(searching_way(nomber + 1, a, x, n), searching_way(nomber + 2, a, x, n));
             return a[nomber];
         }
         }
};



int main(){
    int nomber = -1;
    int x[50] = {0};
    int a[50]= {0};
    int n;
    cin>>n;
    for(int g =0; g<n;++g){
        cin>> x[g];
    }
    cout<<searching_way(nomber,a,x,n);
    return 0;
}