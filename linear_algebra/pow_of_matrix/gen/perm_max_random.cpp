#include <iostream>
#include "random.h"
#include "../params.h"

using namespace std;
using ll = long long;

void out(int n, ll K, vector<vector<ll>> a) {
  printf("%d %lld\n", n, K);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%lld", a[i][j]);
      if (j + 1 != n) printf(" ");
    }
    printf("\n");
  }
}

int main(int, char* argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int n = gen.uniform(N_MAX - 10, N_MAX);
  vector<vector<ll>> a(n, vector<ll>(n));
  vector<int> p = gen.perm<int>(n);
  for (int i = 0; i < n; i++) { a[i][p[i]] = gen.uniform<int>(0, MOD - 1); }

  ll K = gen.uniform<ll>(0, K_MAX);
  out(n, K, a);
  return 0;
}