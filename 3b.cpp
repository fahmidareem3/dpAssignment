
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


int lcsTopDown(char* X, char* Y, int m, int n,
		vector<vector<int> >& dp)
{
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcsTopDown(X, Y, m - 1, n - 1, dp);

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	return dp[m][n] = max(lcsTopDown(X, Y, m, n - 1, dp),
						lcsTopDown(X, Y, m - 1, n, dp));
}


int main()
{   
    auto start = high_resolution_clock::now();
	char X[1000], Y[1000];
    cin >> X;
    cin >> Y;

	int m = strlen(X);
	int n = strlen(Y);
	vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
	cout << "Length of lcsTopDown is " << lcsTopDown(X, Y, m, n, dp)<<" ";
     auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

	return 0;
}
