//knapsack top down with memoization


#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int knapsackTopdown(int W, int wt[], int val[], int n)
{
	
	int dp[W + 1];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i < n + 1; i++) {
		for (int w = W; w >= 0; w--) {

			if (wt[i - 1] <= w)
				
				dp[w] = max(dp[w],
							dp[w - wt[i - 1]] + val[i - 1]);
		}
	}
	return dp[W];
}
int main()
{   auto start = high_resolution_clock::now();
	int n;
    int w;
    cin >> n >> w;
    int val[n];
    int wt[w];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        val[i] = x;
    }
     for(int i = 0; i < w; i++){
        int x;
        cin >> x;
        wt[i] = x;
    }
	
	int W;
    cin >> W;
	cout << knapsackTopdown(W, wt, val, n);
     auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0;
}
