#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const ll INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
int a[51][51], b[51], n;

bool check(int idx, int v) {
  for (int i=0; i<n; i++) if (i != idx) {
    if (a[i][idx] > v) return false;
  }
  return true;
}

int get_index(int v) {
  for (int i=0; i<n; i++) if (b[i] == -1) {
    if (check(i, v)) return i;
  }
  return -1;
}

void do_case(int n) {
  memset(b, -1, sizeof(b));
  for (int i=0; i<n; i++)
    for (int j=0; j<n; j++) scanf("%d", &a[i][j]);

  for (int i=1; i<=n; i++) {
    int idx = get_index(i);
    assert(idx != -1);
    b[idx] = i;
  }
  for (int i=0; i<n; i++) printf("%d%c", b[i], i+1 == n?'\n': ' ');
}

int main() {
  //freopen("test.in", "r", stdin);
  while (cin >> n) do_case(n);
  return 0;
}
