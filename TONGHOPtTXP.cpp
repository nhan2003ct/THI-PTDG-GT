#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
   int id;
   int start;
   int finish;
}lophoc;
void swap(lophoc *x,lophoc *y)
{
    lophoc temp=*x;
    *x=*y;
    *y=temp;
}
void sapxepchon(lophoc a[],long n)
{   int i,j,iMin;
    for (i = 0; i < n - 1; i++)
  { iMin = i;
      for ( j = i + 1; j < n; j++)
    {
     if (a[iMin].finish > a[j].finish) // Tìm vị trí nhỏ nhất trong dãy hiện thời
     iMin = j;
    }
    if (i != iMin)
    swap(&a[i],&a[iMin]); // Đổi chỗ cho phần tử nhỏ nhất
  }
}
void sapxepnoibot(lophoc a[],long n)
{
    long j;
    for(int i=0;i<n-1;i++)
        for(j=n-1;j>i;j--)
          if(a[j].finish<a[j-1].finish)
            swap(&a[j],&a[j-1]);
}
void sort_insert(lophoc arr[], long n)
{
    long j;
    lophoc x;// X được Định dạng kiểu lớp học
    for(long i = 1; i < n; i++)
    {
        x = arr[i];// gán x = mảng i
        j = i;
        while (j > 0 && arr[j-1].finish > x.finish)// Tìm phần tử không đúng trật tự
        {
            arr[j] = arr[j-1]; // Dồn chỗ
            j--;// xóa phần tử đã dồn
        }
        arr[j] = x; // chèn phần tử được dồn đúng vị trí
    }
}
void sapxepnoibot2(lophoc a[],long n)
{
    int Left = 0; // Biên bên trái
    int Right = n - 1; // Biên bên phải
    int i; // Biến chỉ số của mảng
    while (Left < Right)
  {
    for (i = Left; i < Right; i++) // Lượt chạy sắp xếp chìm dần
     if (a[i].finish > a[i + 1].finish) // Nếu không đúng thứ tự
     swap(&a[i], &a[i + 1]); // Thì tráo đổi
     Right --; // Thu hẹp biên phải
    for (i = Right; i > Left; i--) // Lượt chạy sắp xếp nổi dần
     if (a[i].finish < a[i - 1].finish)
     swap(&a[i], &a[i - 1]);
     Left++; // Thu hẹp biên trái
   }
}

int main()
{
    printf("bai toan sap xep lich\n");
    FILE *f,*f2;
    int a[1000],num,i=0;
    long n=0;
    char tenfile[50],tenfilera[50];
    printf("nhap ten file vao ~~\n");
    gets(tenfile);
    printf("nhap ten file ra ''\n");
    gets(tenfilera);
    f=fopen(tenfile,"r");
    f2=fopen(tenfilera,"w");
    lophoc C[1000],O[1000];
    printf("\n du lieu vao:\n");
    while(fscanf(f,"%d",&num)!=EOF)
    {
        if(i%3==2)
        {
            C[n].finish=num;
            printf("%d) ",num);
        }
        else
            if(i%3==1)
        {
            C[n].start=num;
            printf("%d-",num);
        }
        else{
            C[n].id=num;
            printf(" %d(",num);
        }
        i++;
        if(i%3==0)
            n++;//doc tung so vao cac gia tri, cu 3 so thi tang n len 1
    }
    printf("\n Tong so lop hoc la :%d\n",n);
    //sort_insert(C,n);
    //sapxepnoibot(C,n);
    //sapxepchon(C,n);
    sapxepnoibot2(C,n);
    printf("\ncac lop sap xep theo thu tu tang dan cua thoi gian ket thuc:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d(%d-%d) ",C[i].id,C[i].start,C[i].finish);
    }
//xep lich
    O[0]=C[0];
    int k=C[0].finish;
    int count=1;
    for(i=1;i<n;i++)
    {
        if(C[i].start>k)
        {
            O[count]=C[i];
            k=O[count].finish;
            count++;
        }
    }
    printf("\nSo lop toi uu :%d\n",count);
    printf("waiting for computer loading....\n");
    for(i=0;i<count;i++)
    {
        fprintf(f2,"%8d%8d%8d\n",O[i].id,O[i].start,O[i].finish);
        printf("%8d(%d-%d)",O[i].id,O[i].start,O[i].finish);
    }
    printf("\nxong !!!\n");
    fclose(f);
    fclose(f2);
}