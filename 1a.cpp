//rod cutting problem using only recursion


#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


int rodcutRec(int price[], int index, int n)
{
	
	if (index == 0) {
		return n * price[0];
	}
	
	int notCut = rodcutRec(price,index - 1,n);
	int cut = INT_MIN;
	int rod_length = index + 1;

	if (rod_length <= n)
		cut = price[index]
			+ rodcutRec(price,index,n - rod_length);

	return max(notCut, cut);
}


int main()
{   
    auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[i] = x;
    }
	
	
	cout << rodcutRec(a, n - 1, n)<<"\n";
    auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

	return 0;
}


