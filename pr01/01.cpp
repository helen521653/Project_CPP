#include <iostream>

using namespace std;
void QuickSort(long c[1000], unsigned long s,unsigned long e){
    unsigned long indopporn = e;
    for(unsigned int i = 0; i<=e;++i ){
        if ((c[i]> c[indopporn]) && (i<indopporn)){
            swap(c[i],c[indopporn]);
            indopporn = i;

        }
    }
    unsigned long opl = indopporn, opr = indopporn;
    if (opl>0){
        QuickSort(c, 0,opl - 1);

    }
    if (opr<e){
        QuickSort(c,opr+1,e);

    }
}


int kolvom(long d[1000], long n, long s){
    long int current = n-1;
    int kol = 0;
    for(;current>=0;--current) {
        if ((s - d[current]) >= 0) {
            s -= d[current];
            kol += 1;
        }
    }
    if(s>0){
        return -1;
    }
    else {
        return kol;
    }
}


int main()
{
    long int n,s;

    long d[1000];
    cin>>n;
    for(int k = 0;k<n;++k){
        cin>>d[k];
    }
    cin>>s;
    QuickSort(d,0,n-1);
    cout<< kolvom(d,n,s);
    return 0;
}