#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int a[2][2],i,j,det,m[2][2],q[5],d[5],r[5],p[5],no;
int determinent()
{
    return a[0][0]*a[1][1]-a[0][1]*a[1][0];
}
void euclid(int num,int n)
{
    for(i=0;i<5;i++)
    {
            q[i]=n/num;
            d[i]=num;
            r[i]=n%num;
            n=d[i];
            num=r[i];
            if(r[i]==0){
                no=i;
                break;}
    }
    for(i=2;i<no+2;i++)
    {
            p[0]=0;
            p[1]=1;
            p[i]=p[i-2]-p[i-1]*q[i-2]%26;
            if(p[i]<0)
            {
                p[i]=26+p[i];
            }
    }
}
int main()
{
    printf("Enter the matrix\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    det=determinent();
    printf("%d\n",det);
    m[0][0]=a[1][1];
    m[0][1]=-1*a[0][1];
    m[1][0]=-1*a[1][0];
    m[1][1]=a[0][0];
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",m[i][j]);
        }
    }
    printf("\n");
    euclid(det,26);
     for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            m[i][j]=(p[no+1]*m[i][j])%26;
            if(m[i][j]<0)
            {
                m[i][j]=26+m[i][j];
            }
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            printf("%d\t",m[i][j]);
        }
    }
    return 0;
}
