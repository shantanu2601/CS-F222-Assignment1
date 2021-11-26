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
    //checkOneOne(n, arr);
    bool flag = true;
    for(int i = 0; i < n; i++){
    	int count = 0;
    	for(int j = 0; j < n; j++){
    		if(arr[j][i] == 1){
    			count++;
    		}
    	}
    	if(count > 1){
    		cout << "0";
    		flag = false;
    		break;
    	}
    }
    if(flag == true){
    	cout << "1";
    }
    //checkOnto(n, arr);
    for(int i = 0; i < n; i++){
    	flag = false;
    	for(int j = 0; j < n; j++){
    		if(arr[j][i] == 1){
    			flag = true; // 1 is present in column
    			break;
    		}
    	}
    	if(flag == false){ // 1 not present in column
    		cout << "0";
    		break;
    	}
    }
    if(flag == true){
    	cout << "1";
    }
}