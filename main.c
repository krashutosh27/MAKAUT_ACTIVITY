#include <stdio.h>
#include <stdlib.h>
int *a,*b,*sum,*sub,*mul,*trs1,*trs2,i,j,r,c;
void input(int *);
void addition(int *,int *,int *);
void display(int *);
void multiply(int *,int *,int *);
void subtraction(int *,int *,int *);
void transpose(int *,int *);
int main()
{
    printf("Enter the row & column :\n");
    scanf("%d%d",&r,&c);

    a=(int *)malloc(sizeof(int)*r*c);
    b=(int *)malloc(sizeof(int)*r*c);
    sum=(int *)malloc(sizeof(int)*r*c);
    mul=(int *)malloc(sizeof(int)*r*c);
    sub=(int *)malloc(sizeof(int)*r*c);
    trs1=(int *)malloc(sizeof(int)*r*c);
    trs2=(int *)malloc(sizeof(int)*r*c);

    printf("\nEnter the first matrix :\n");
    input(a);
    printf("\nEnter the second matrix :\n");
    input(b);
    addition(a,b,sum);
    printf("\nFirst matrix is :\n");
    display(a);
    printf("\nSecond matrix is :\n");
    display(b);
    printf("\nAddition of matrix is :\n");
    display(sum);
    subtraction(a,b,sub);
    printf("\nSubtraction of matrix:\n");
    display(sub);
    multiply(a,b,mul);
    printf("\nMultiplication of matrix is :\n");
    display(mul);
    transpose(a,trs1);
    transpose(b,trs2);
    printf("\nTranspose of first matrix is :\n");
    display(trs1);
    printf("\nTranspose of second matrix is :\n");
    display(trs2);

    return 0;
}
void input(int *p)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            scanf("%d",(p+i*c+j));
    }
}
void display(int *p)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",*(p+i*c+j));
        printf("\n");
    }
}
void addition(int *p,int *q,int *s)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(s+i*c+j)=*(p+i*c+j)+*(q+i*c+j);
    }
}
void multiply(int *p,int *q,int *s)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            *(s+i*c+j)=0;
            for(int k=0;k<c;k++)
                *(s+i*c+j)+=*(p+i*c+k)**(q+j*c+k);
        }
    }
}
void subtraction(int *p,int *q,int *s)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(s+i*c+j)=*(p+i*c+j)-*(q+i*c+j);
    }
}
void transpose(int *p,int *q)
{
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            *(q+i*c+j)=*(p+j*r+i);
    }
}
