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
 for(i = 1; i <= n; ++i)
 printf((i<n)?"%d, ": "%d.\n",b[i]);
}
void distributie(int n, int a[20], int b[20])
{
int COUNT[20],i,j, u = a[1], v = a[1];
for(i = 2; i <= n; ++i) /* atribuim lui u cea mai mica, */
 if(u >= a[i]) /* iar lui v cea mai mare valoare */
 u = a[i]; /* dintre elementele a[1]...a[n] */
 else if (v <= a[i]) /* astfel toate elementele lui a[] */
 v = a[i]; /* se vor afla in intervalul [u, v] */
for(i = u; i <= v; ++i) /* se initializeaza vectorul auxiliar */
 COUNT[i] = 0; /* COUNT[], de la COUNT[u] la COUNT[v] cu zero */
/* parcurg toate elementele din a[] si daca a[j] = 7 se incrementeaza cu 1 COUNT[7] */
for(j = 1; j <= n; ++j)
 COUNT[a[j]] = COUNT[a[j]] + 1;
/* in acest punct COUNT[i] contine numarul de elemente din a[] care au valoarea i */
for(i = u + 1; i <= v; ++i)
 COUNT[i] = COUNT[i] + COUNT[i - 1];
 /* in acest punct COUNT[i] contine numarul de elemente din a[] care sunt <= i, e.g.
COUNT[v] = n */
for(j = n; j >= 1; --j) {
 i = COUNT[a[j]]; /* i contine numarul de elemente <= a[j] */
 b[i] = a[j]; /* plasez in b[] pe a[j] in pozitia data de numarul de valori <= a[j] */
 COUNT[a[j]] = i - 1; /* daca am plasat o valoare a[j] decrementez COUNT[a[j]] */
}
}
