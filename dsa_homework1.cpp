/* 
 * File:   main.cpp
 * Author: Alex
 *
 * Created on March 5, 2015, 9:44 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

void isPerfect(int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (n % i == 0) {
            sum += i;
            cout << "here";
        }
    }
    cout << sum;
}

/*
 * 
 */
int main() {
    isPerfect(6);
    return 0;
}

