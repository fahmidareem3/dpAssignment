
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;




int lcs( char *X, char *Y, int m, int n )
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m-1] == Y[n-1])
		return 1 + lcs(X, Y, m-1, n-1);
	else
		return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}




int main()
{   auto start = high_resolution_clock::now();
    char X[1000], Y[1000];
    cin >> X;
    cin >>Y;
	
	
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ;
     auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	
	return 0;
}


