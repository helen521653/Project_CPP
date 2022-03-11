#include <iostream>
using namespace std;

int search_rec(int x, int* array, int n){
    int middle = n /2;

    if(array[middle] ==x){
        return middle;
    }
    else if (( (n-middle-1==middle+1) and (array[n-middle-1]!=x)) or ((0 == middle) and  (array[middle]!=x))){
        return -1;
    }
    else{
        if(x>array[middle]){
            return search_rec(x, array+middle+1,n-middle-1);
        }
        else{
            return search_rec(x,array+0, middle);
        }
    }
}

int main()
{
    int n, a[100], x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < 5; i++)
    {
        cin >> x;
        cout << search_rec(x, a, n) << " ";
    }
    cout << endl;
    return 0;
}