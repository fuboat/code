#include <cstdio>
#include <cmath>
#include <algorithm>
#define REP(i, x, y) for(int i = x, _ = y; i <= _; i ++)
int min(int x, int y)
{
	return x < y? x : y;
}

void readint(int &x){
	x = 0;
	bool flag = 0;
	char c;
	while(c = getchar()){
		if('0' <= c && c <= '9'){
			x = x * 10 + c -'0';
			flag = 1;
		}
		else if(flag && (c == ' ' || c == '\n'))
			return;
	}
}

using namespace std;
const int MAXN = 100000, MAXK = 100000;
const double pi = 3.1415926
double len[MAXN + 100];
int main()
{
	double l = 0, r = 1e8;
	int n, k;
	scanf("%d%d", &n, &k);
	k ++;
	REP(i, 1, n){
		int x;
		l[i] = x * x * pi;
	}
	while(l + 1 < r){
		double mid = (l + r) / 2;
		int sum = 0;
		REP(i, 1, n)
			sum += len[i] / mid;
		if(sum < k) r = mid;
		else l = mid;
	}
	printf("%.3lf", l);
	return 0;
}
