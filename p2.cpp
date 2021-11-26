#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

int countWays(int s)
{
    return fib(s + 1);
}

int main()
{
    int s;
	ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    while (inFile >> s) {
        cout << countWays(s);
    }
    inFile.close();
    return 0;
}