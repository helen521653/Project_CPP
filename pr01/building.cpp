#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int mb = 0;
    cin>>mb;
    int s= 0;
    while (mb>0){
        mb /= 2;
        ++s;
    };
    cout<<s;

    cout<<(23+s)/8;
    return 0;
}