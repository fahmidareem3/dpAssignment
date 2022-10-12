
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


int lcsBottomUp(char *X, char *Y, int m, int n)
{
	
	int L[m + 1][n + 1];

	
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}

	
	return L[m][n];
}


int main()
{
	auto start = high_resolution_clock::now();
	char X[1000], Y[1000];
    cin >> X;
    cin >> Y;

	int m = strlen(X);
	int n = strlen(Y);

	cout << "Length of lcsBottomUp is: " << lcsBottomUp(X, Y, m, n)<<"\n";
    auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;


	return 0;
}

