#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;


const int INF = 100000;


void init_r(int r[],int n) {
  int i;
  r[0] = 0;
  for(i=1; i<=n; i++) {
    r[i] = -1*INF;
  }
}

int rodCupTopdown(int c[], int n, int r[]) {
  if (r[n] >= 0) {
    return r[n];
  }

  int maximum_revenue = -1*INF;
  int i;

  for(i=1; i<=n; i++) {
    maximum_revenue = max(maximum_revenue, c[i] + rodCupTopdown(c, n-i,r));
  }

  r[n] = maximum_revenue;
  return r[n];
}

int main() {
  auto start = high_resolution_clock::now();
  int n;
  cin >> n;
  int r[n+1];
  init_r(r,n);
  int c[n+1];
  c[0] = 0;
  for(int i = 1; i <= n; i++){
    int x;
    cin >> x;
    c[i] = x;
  }
 
  printf("%d\n", rodCupTopdown(c, n,r));
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
   cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

  return 0;
}