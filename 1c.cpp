//rod cutting bottom up using tabular method

#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


const int INF = 100000;

int rodCutBottomUp(int c[], int n) {
  int r[n+1];
  r[0] = 0;
  int i,j;

  for(j=1; j<=n; j++) {
    int maximum_revenue = -1*INF;
    for(i=1; i<=j; i++) {
      maximum_revenue = max(maximum_revenue, c[i] + r[j-i]);
    }
    r[j] = maximum_revenue;
  }
  return r[n];
}

int main() {
    auto start = high_resolution_clock::now();
  int n;
  cin >> n;
  int c[n+1];
  c[0] = 0;
  for(int i = 1; i <= n; i++){
    int x; 
    cin >> x;
    c[i] = x;
  }
  
  printf("%d\n", rodCutBottomUp(c, n));
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
  return 0;
}