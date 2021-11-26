#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void getUnion(int a[], int b[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
      s.insert(a[i]);

    for (int i = 0; i < m; i++)
        s.insert(b[i]);

    for (auto itr = s.begin(); itr != s.end(); itr++)
        cout << *itr << " ";
    cout << endl;
}

void getIntersection(int a[], int b[], int n, int m)
{
    sort(a,a+n);
    sort(b,b+m);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            j++;
        }
        else if (b[j] > a[i]) {
            i++;
        }
        else {
            cout << a[i] << " ";
            i++;
            j++;
        }
    }
    cout << endl;
}

void getDifference(int a[], int b[], int n, int m)
{
	int c[n];
	int i,j,l,k=0;
	for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(b[j]==a[i])
             break;
        }
        if(j==m)
        {
            for(l = 0; l < k; l++)
            {
                if(c[l]==a[i])
                 break;
            }
            if(l==k)
            {
                c[k]=a[i];
                k++;
            }
        }
    }
    for(i = 0; i < k; i++)
    {
         cout << c[i] << " ";
    }
}

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
    int arr1[n];
    for(int i = 0; i < n; i++){
    	inFile >> arr1[i];
    }
    inFile >> m;
    int arr2[m];
    for(int i = 0; i < m; i++){
    	inFile >> arr2[i];
    }

    getUnion(arr1, arr2, n, m);
    getIntersection(arr1, arr2, n, m);
    getDifference(arr1, arr2, n, m);
}
