#include<stdio.h>
#include<stdlib.h>
void swap1(int *a,int *b)
{
    int tg=*a;
    *a=*b;
    *b=tg;
}
void sapxepnoibot2(int a[],int n)
{
    int left=0;
    int right=n-1;
    while(left<right)
    {
        for(int i=left;i<right;i++)
            if(a[i]>a[i+1])
            swap1(&a[i],&a[i+1]);
            right--;
            for(int i=right;i>left;i--)
                if(a[i]<a[i-1])
                swap1(&a[i],&a[i-1]);
            left++;
    }
}
void docvaxapxep()
{
    FILE *f,*f1;
    int a[100];
    f=fopen("10.txt","r");
    f1=fopen("11.txt","w");
    int n=0;
    int num=0;
    while(fscanf(f,"%d",&num)!=EOF)
    {
        a[n]=num;
        n++;
        printf("%8d",num);
    }
    printf("\n");
    printf("file co %d so ",n);
    sapxepnoibot2(a,n);
    printf("file sau khi sap xep \n");
    for(int i=0;i<n;i++)
    {
        printf("%8d",a[i]);
        fprintf(f1,"%8d",a[i]);
    }
    fclose(f);
    fclose(f1);
}
void hamdem()
{   FILE *f1;
    f1=fopen("11.txt","r");
    int n=0;
    int num=0;
    int a[100];
    int dem1=0,dem2=0;
    while(fscanf(f1,"%d",&num)!=EOF)
    {
        a[n]=num;
        n++;
    }
    int k,x,y;
    printf("nhap vao k ");scanf("%d",&k);
    printf("nhap vao x ");scanf("%d",&x);
    printf("nhap vao y ");scanf("%d",&y);
    for(int i=0;i<n;i++)
    {
        if(a[i]==k)
        {
            dem1++;
        }
        if(a[i]>x && a[i]<y)
        {
            dem2++;
        }
    }
    printf("file co %d so bang k\n",dem1);
    printf("file co %d so lon hon x va nho hon y",dem2);
}
int main()
{
    docvaxapxep();
    printf("\n");
    hamdem();
    return 0;
}