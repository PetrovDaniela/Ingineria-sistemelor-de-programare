#include <stdio.h>
#define N 20
#define M 20
void citire(int a[], int* n);
void interclasare(int a[], int b[], int c[],
int n, int m, int* k);
void afisare(int a[], int n);
int main()
{
 int i, n, m, k, a[N], b[M], c[N + M];

 printf("\n citirea primului vector sortat: \n"); citire(a, &n);
 printf("\n afisarea primului vector: \n"); afisare(a, n);

 printf("\n citirea celui de-al 2-lea vector sortat: \n"); citire(b, &m);
 printf("\n afisarea celui de-al 2-lea vector: \n"); afisare(b, m);

 interclasare(a, b, c, n, m, &k);

 printf("\n afisarea vectorului obtinut prin interclasarea celor doi vectori: \n");
 afisare(c, k);

 return 0;
}
void citire(int a[], int* n)
{
 int i;
 printf("numarul de elemente = ");
 scanf("%d", n);
 for(i = 1; i <= *n; ++i){
 printf("[%d] = ", i);
 scanf("%d", &a[i]);
 }
}
void afisare(int a[], int n)
{
 int i;
 for(i = 1; i <= n; ++i)
 printf(i < n ? "%d, ":"%d.\n", a[i]);
}
void interclasare(int a[], int b[], int c[], int n, int m, int* k)
{
int i = 1, j = 1;
*k = 0;
while(i <= n && j <= m)
 if(a[i] <= b[j])
 c[++*k] = a[i++];
 else
 c[++*k] = b[j++];
if(i <= n )
 for(j = i; j <= n; ++j)
 c[++*k] = a[j];
else
 for(i = j; i <= m; ++i)
 c[++*k] = b[i];
}
