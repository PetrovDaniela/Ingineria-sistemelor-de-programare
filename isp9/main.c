#include <stdio.h>
#include <stdlib.h>
const int X[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
const int Y[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int n, sol[100][2], t[10][10];
void back(int k, int lin, int col);
int main()
{
int i, j, lin, col;
printf("n = ");
scanf("%d", &n);
back(1, 1, 1);
return 0;
}
void back(int k, int lin , int col)
{
int i, linie, coloana;
if ( k == n*n ){
for ( i = 1; i < k; ++i)
printf("%d %d \n", sol[i][0], sol[i][1]);
printf("%d %d", lin, col);
exit(EXIT_SUCCESS);
}
else {
sol[k][0] = lin;
sol[k][1] = col;
for ( i = 0; i <= 7; ++i ){
linie = lin + X[i];
coloana = col + Y[i];
if ( linie <= n && linie >= 1 && coloana <= n && coloana >= 1 &&

t[linie][coloana] == 0){
t[linie][coloana] = 1;
back(k + 1, linie, coloana);
t[linie][coloana] = 0;
}
}
}
}
