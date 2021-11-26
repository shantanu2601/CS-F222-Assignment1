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
    int arr[n][n], out[n], id[n], flag[n];
    for(int i = 0; i < n; i++){
    	for(int j = 0; j < n; j++){
    		inFile >> arr[i][j];
    	}
    }
    int i, j, k, count = 0, r = 0;
    for(i=0;i<n;i++){
        id[i]=0;
        flag[i]=0;
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            id[i] += arr[j][i];
        }
    }

    while(count < n){
        for(k = 0; k < n; k++){
            if((id[k]==0) && (flag[k]==0)){
                //cout<<k+1<<"$";
                out[r++] = k+1;
                flag[k]=1;
            }
            for(i = 0; i < n; i++){
                if(arr[i][k]==1)
                    id[k]--;
            }
        }
        count++;
    }
    for(i = 0; i < n-1; i++){
        cout << out[i] << "$";
    }
    cout << out[i];
}