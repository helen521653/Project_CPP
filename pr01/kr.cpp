#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
struct Road{
    int x,y,d;
};



int main()
{
    int n  = 0, m = 0,k = 0;
    int sh =0, a = 0, b = 0, c = 0, h = 0;
    cin>>n>>m;
    cin>> k;
    Road* r = new Road[k];
    unsigned int** p = new unsigned int*[n];
    for (unsigned int i = 0; i < n; i++)
        p[i] = new unsigned int[m];
    for(int i = 0; i <n; ++i)
        p[i] = {0};

    for(int i = 1; i<k;++i){
        cin>>r[i].x>>r[i].y>>r[i].d;
        if(r[i].d=0){
            p[r[i].x][r[i].y]+=1;
        }
        else if(r[i].d>0){
            if((r[i].x-r[i].d)<0){
                a=0;
            }
            else{
                a = r[i].x-r[i].d;
            };
            if ((r[i].x+r[i].d)>(n-1)){
                b=n-1;
            } else{
                b= r[i].x+r[i].d;
            };

            if((r[i].y-r[i].d)<0){
                c=0;
            }
            else{
                c=r[i].y-r[i].d;
            };
            if ((r[i].y+r[i].d)>(m-1)){
                h=m-1;
            } else{
                h=r[i].y+r[i].d;
            };
            for(int z = a;z<=b;++z){
                for(int q = c;c<=h;++q){
                    p[z][q]+=1;
                };
            };
            a = 0;
            b = 0;
            c = 0;
            h = 0;
        }else{
            sh+=0;
        };
    };
    int s = 0;
    for(int z = 0;z<=n-1;++z){
        for(int q = c;c<=h;++q){
            if(p[z][q]==0){
                s+=1;
            };
        };
    };
    cout<<s;
    for(int i = 0; i <n; ++i)
        delete [] p[i];
    delete []p;
    delete []r;
    return 0;
}