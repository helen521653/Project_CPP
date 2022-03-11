#include <iostream>
#include <iomanip>
using namespace std;
struct Game{
    char name[29] = {0};
    int k;
    long  int s;
};
int main(){
    int n = 0;
    char c='0';
    Game *m = new Game[10000];
    cin>>n;
    for(int i = 0; i<n;++i){
        cin>>c;
        int j = 0;
        while(((c-'0')<'0') && ((c-'0')>'9') && (c!=32)){
            m[i].name[j] = c;
            ++j;
        };

        cin>>m[i].k;
        int s = 0;
        int b = 0;
        for(int l; l<(m[i].k); ++l){
            cin>>b;
            s+=b;
        };
        (m+i)->s = s;
    };

    for(int i = 0; i<n;++i){
        int j = 0;
        while((m[i].name[j])!=0){
            cout<<m[i].name[j];
        };
        cout<<' '<<fixed<<setprecision(3)<<((m[i].s)/(m[i].k));


    };

    delete [] m;

    return 0;
};

