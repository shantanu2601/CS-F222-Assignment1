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
    int arr[n][n];
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		inFile >> arr[i][j];
    	}
    }
    //antisymmetric check
    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i > j){ //lower elements of diagonal
                if(arr[i][j] == 1 && arr[j][i] == 1){
                    flag = false;
                    break;
                }
            }
        }
        if(flag == false){
            cout << "0";
            break;
        }
    }
    if(flag == true){
        cout << "1";
    }
    //transitive check
    flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 1){
                for(int k = 0; k < n; k++){
                    if(arr[j][k] == 1 && arr[i][k] == 0){
                        flag = false;
                        break;
                    }
                }
                if(flag == false){
                    cout << "0";
                    return 0;
                }
            }
        }
    }
    if(flag == true){
        cout << "1";
    }
}
