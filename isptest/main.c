#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{int m,n,r,p,c;
printf("m=");
scanf("%d",&m);
printf("n=");
scanf("%d",&n);
p=n*m;
r=n%m;
while(r!=0)
{
n=m;
m=r;
r=n%m;
}
c=p/m;
printf("Cmmmc= %d",c);
}
