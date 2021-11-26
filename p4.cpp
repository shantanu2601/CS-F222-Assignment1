#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a, b;
    ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    inFile >> a;
    inFile >> b;

    int d = gcd(a,b);
    a = a/d;
    b = b/d;
    int i = 1, j = 1, k = 1;

    while(a != i || b != j){
        j++;
        k++;
        if(a == i && b == j){
            break;
        }
        while(j > 1 && (a!=i || b!=j)){
            i++;
            j--;
            if(gcd(i,j) == 1){
                k++;
            }
        }
        if(a == i && b == j){
            break;
        }
        i++;
        k++;
        if(a == i && b == j){
            break;
        }
        while(i > 1 && (a!=i || b!=j)){
            i--;
            j++;
            if(gcd(i,j) == 1){
                k++;
            }
        }
        if(a == i && b == j){
            break;
        }
    }
    cout << k;
}
