/*
    Author        : Justin San
    File Name     : decToBin.cpp
    Creation date : 03/March/2021
    Description   : My first time using c++
                  : created this to practice on
*/

#include <iostream>
#include <new>

using namespace std;

int main(){
    int i, j, k;
    int * bin;
    cout <<  "Input Number: ";
    cin >> k;
    i = 1;
    /*
    returns the largest bit that can house k
    ie: k = 1298, would return 2048;
        k = 267, would return 512;
        k = 45, would return 64;
    */
    while(true){ 
        if(i > k){
            j = i;
            break;
        }else{
            i = i*2;
        }
    }
    i = 0; //reset i to 0
    /*
    loop through all the bits and add it to i 
    for each bit that can be divided by 2
    ie: 128 / 2 = 64    | i = 1
        64 / 2 = 32     | i = 2
        32 / 2 = 16     | i = 3
        etc..
    
    until the bit cannot be divided by 2
    */
    for(int l = j; l > 1; l / 2){
        l = l/2;
        i++;
    }

    cout << "Binary for " << k << " is 0x";
    /*
    create a dynamic array and loop through 
    each cell for the array. then if the
    input is bigger or equal to the last bit
    (ie: 128, 64, 32, etc..) minus that from 
    the input and set the cell to true. else 
    set the cell as false.
    ie: 
        input = 45;
        highestBit = 64;
        IF input >= highestBit
            input = input - highestBit
            array[i] = TRUE
        ELSE 
            array[i] = FALSE
        END
    
    loop until all the bit are used
    ie: no more space on the array
    */
    bin = new (nothrow) int [i];
    for(int n = 0; n <= i; n++){
        if(k >= j){
            k -= j;
            bin[i] = true;
        }else{
            bin[i] = false;
        }
        j = j/2;
        cout << bin[i];
    }
    return 0;
}
