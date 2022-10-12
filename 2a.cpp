//knapsack with only recursion

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

int knapSack(int W, int wt[], int val[], int n)
{

	
	if (n == 0 || W == 0)
		return 0;

	
	if (wt[n - 1] > W)
		return knapSack(W, wt, val, n - 1);

	
	else
		return max(
			val[n - 1]
				+ knapSack(W - wt[n - 1],
						wt, val, n - 1),
			knapSack(W, wt, val, n - 1));
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
	
	cout << knapSack(W, wt, val, n)<<"\n";
     auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
	return 0;
}


