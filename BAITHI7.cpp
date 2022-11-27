#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void shakersort(int a[],int n)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        for(int i=left;i<right;i++)
        if(a[i]>a[i+1])
            swap(&a[i],&a[i+1]);
        right--;
        for(int i=right;i>left;i--)
            if(a[i]<a[i-1])
            swap(&a[i],&a[i-1]);
            left++;
    }
}
void dem(int a[],int n,int k)
{   int demt=0,demh=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
          {
              if(a[i]+a[j]==k)
              {
                  demt++;
              }
              else if(a[i]-a[j]==k)
              {
                  demh++;
              }
              else if(a[j]-a[i]==k)
              {
                  demh++;
              }
          }
    }
    printf("co %d cap so co tong bang k \n",demt);
    printf("co %d cap so co hieu bang k \n",demh);
}
int main()
{
    FILE *f;
    int a[100];
    f=fopen("D:\\New folder\\vatly\\file1-10.txt","r");
    int n=0;
    int num=0;
    while(fscanf(f,"%d",&num)!=EOF)
    {
        a[n]=num;
        n++;
        printf("%8d",num);
        printf("\n");
    }
    printf("file co %d so ",n);
    shakersort(a,n);
    for(int i=0;i<n;i++)
    {
        printf("%8d",a[i]);
    }
    printf("\n\n");
    int k;
    printf("nhap vao so k :");scanf("%d",&k);
    dem(a,n,k);
}