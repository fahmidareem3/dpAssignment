//knapsack bottom up with tabular method


#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;




int bottomUpKnapsack(int W, int wt[], int val[], int n)
{
	int i, w;
	vector<vector<int>> K(n + 1, vector<int>(W + 1));

	
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(val[i - 1] +
								K[i - 1][w - wt[i - 1]],
								K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	return K[n][W];
}


int main()
{   
	auto start = high_resolution_clock::now();
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
	
	cout << bottomUpKnapsack(W, wt, val, n)<<"\n";
	
	
     auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0;
}


