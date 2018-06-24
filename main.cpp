#include <iostream>
#include "mtm_array.h"
using std::cout;
using std::endl;

int main() {
    Array<int,10> arr;
    int i=0;
    for (Array <int, 10>::iterator it=arr.begin(); it != arr.end(); ++it){
        *it = i++;
        cout<<*it<<endl;
    }

    const Array<int,5> arr2;
    i=0;
    for(Array<int,5>::const_iterator it = arr2.begin();it++){
        
    }
    return 0;
}