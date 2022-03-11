#include <iostream>
using namespace std;
const int X = 100;
const int Y = 100;
const int B = 10;
struct Data {
    int x, y, bright;
};
int M[1000][3];

int check(Data d, int X,int Y, int B, int kol ){
    if(((d.x<=X) & (d.y <= Y)) || (d.bright>= B)){
        for(int i = 0;i<kol;++i){
            if((d.x == M[i][0])& (d.y == M[i][1]) & (d.bright == M[i][2])){
                return kol;
            }
        };
        M[kol][0] = d.x;
        M[kol][1] = d.y;
        M[kol][2] = d.bright;
        cout<<d.x<<' '<<d.y<< ' '<< d.bright<<endl;
        kol+=1;
        return kol;
    }
    else{
        return kol;
    }
};



int main() {
    long n;
    int kol=0;
    cin>>n;
    cout<< endl;
    for(int i = 0; i<n;++i){
        Data d;
        cin>>d.x >>d.y>> d.bright;
        kol = check(d,X,Y,B,kol);

    }
    return 0;
}