#include <iostream>
#include <cmath>
using namespace std;

double step_to(int n){
    double k =0;
    while(n>2){
        n/=2;
        ++k;
    };
    if(n>0){++k;};
    return k;
};


int main()
{
    int n;
    cin>>n;
    cout <<ceil((step_to(n)+20)/ 8 )<<endl ;
    cout <<(step_to(n)+20)/8<<endl ;
    cout <<step_to(n)<<endl ;




    return 0;
}

