
#include <iostream>
using namespace std;
//M - размер памяти занятый под массив
//N - количество рыб в массиве на данный момент

void doubling(int** arr, unsigned int M){
    int *m = new int[2*M];
    for(int i = 0;i<M;++i){
        m[i] = *((*arr)+i);
    };
    delete [](*arr);
    *arr = m;
};

void plus_day(int *m, int* N,int* M){
    for(int i = 0; i<(*N);++i){
        if(m[i]>0){
            m[i]-=1;
        }
        else{
            if((m[i] == 0) && ((*N)== (*M))){
                doubling(&m,*M);
                (*M)*=2;
            };
            m[i] = 6;
            m[(*N)] = 9;
            ++(*N);
        };
    };
}

void print(int *m, int N, int days) {
    cout<<"Total now "<<N<<" fish. "<<endl;
    cout<<"After "<<days<<" day(s): ";
    for (int i = 0; i < N; ++i) {
        cout << m[i] << " ";
    }
    cout<<endl;
}


int main(){
    int M = 5;
    int *m = new int[M];
    int i = 0;
    cout<< "Initial state (separated by a space): ";
    int p = 0;
    while((std::cin>>p)&&(p!=33)){
        m[i] = p;
        ++i;
        cin.ignore(1);
    };
    int N = i;
    int days = 3;
    cout<<"How many days after: ";
    cin>>days;
    for(int i = 0; i<days;++i){
        plus_day(m,(&N),(&M));
    };
    print(m,N,days);
    delete [] m;
    return 0;
}