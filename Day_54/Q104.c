/*
Question 104: Find the pivot integer x such that sum 1..x equals sum x..n.
*/

#include <stdio.h>
int main(){long long n; scanf("%lld",&n); long long total=n*(n+1)/2; for(long long x=1;x<=n;x++) if(x*x==total){printf("%lld",x);return 0;} printf("-1"); return 0;}
