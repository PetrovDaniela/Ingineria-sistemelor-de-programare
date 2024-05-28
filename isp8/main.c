#include <stdio.h>
int n, sol[10], a[10][10];
void init(int k);
int succesor(int k);
int valid(int k);
int solutie(int k);
void tipar();
void back(int k);
int main(){
int i, j;
printf("n=");
scanf("%d", &n);
for(i = 1; i <= n; ++i)
for(j = 1; j <= n; ++j){
printf("a[%d][%d] = ", i, j);
scanf("%d", &a[i][j]);
}
back(1);
}
void init(int k){
sol[k] = 0;
}
int succesor(int k){
if( sol[k] < n ){
sol[k]++;
return 1;
}
else
return 0;

}
int valid(int k){
int i, ev = 1;
for ( i = 1; i < k; ++i )
if ( sol[k] == sol[i] && a[i][k] == 1)
ev = 0;
return ev;
}
int solutie(int k){
return k == n + 1;
}
void tipar(){
int i;
for( i = 1; i <= n; ++i )
printf("%d",sol[i]);
printf("\n");
}
void back(int k){
if ( solutie(k) )
tipar();
else {
init(k);
while( succesor(k) )
if (valid(k))
back(k+1);
}
}
