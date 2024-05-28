#include <stdio.h>
void distributie(int n, int a[], int b[]);
int main ()
{
 int i, n, a[20], b[20];

 printf("n = "); scanf("%d", &n);
 for (i = 1; i <= n; ++i){
 printf("a[%d] = ",i);
 scanf("%d", &a[i]);
 }

 for (i = 1; i <= n; ++i)
 printf((i<n)?"%d, ": "%d.\n",a[i]);

 distributie(n, a, b);

 printf("\nvector sortat: ");
 for(i = n; i >= 1; --i)
 printf((i<n)?"%d, ": "%d, ",b[i]);
}
void distributie(int n, int a[20], int b[20])
{
int COUNT[20],i,j, u = a[1], v = a[1];
for(i = 2; i <= n; ++i)
 if(u >= a[i])
 u = a[i];
 else if (v <= a[i])
 v = a[i];
for(i = u; i <= v; ++i)
 COUNT[i] = 0;
for(j = 1; j <= n; ++j)
 COUNT[a[j]] = COUNT[a[j]] + 1;
for(i = u + 1; i <= v; ++i)
 COUNT[i] = COUNT[i] + COUNT[i - 1];
for(j = n; j >= 1; --j) {
 i = COUNT[a[j]];
 b[i] = a[j];
 COUNT[a[j]] = i - 1;
}
}
