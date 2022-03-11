#include <iostream>
#include <algorithm>
using namespace std;
struct Table{
    int time_stamp;
    int id;
    double vit_d;
    double acat;
    double anti_tg;
    double neural_activity;
    double mch;
};
bool compare(Table a, Table b) {
    return (a.id > b.id);
}


int main()
{
    int n;
    Table m[1000];
    cin>>n;
    for(int i = 0; i<n;++i){
        cin>>m[i].time_stamp>>m[i].id>>m[i].vit_d>>m[i].acat>>m[i].anti_tg>>m[i].neural_activity>>m[i].mch;
    }
    sort(m, m + sizeof(m) / (sizeof(int)*2+ sizeof(double)*5), compare);

    return 0;
}