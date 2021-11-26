#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;


int main()
{
    int n, m;
	ifstream inFile;
    inFile.open("input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    inFile >> n;
    int arr[n][n], tr[n][n];
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		inFile >> arr[i][j];
    	}
    }
    int i, j, k;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(arr[i][j] == 1){
                tr[i][j] = 1;
            }
            else{
                tr[i][j] = 0;
            }
        }
    }
    for(k = 0; k < n; k++){
        for(i = 0; i < n; i++){
            for(j = 0; j < n; j++){
                tr[i][j] = tr[i][j] || (tr[i][k] && tr[k][j]);
            }
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            cout << tr[i][j] << "$";
        }
        cout << "$";
    }
}