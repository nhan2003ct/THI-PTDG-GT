#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

using namespace std;
static int a[1000000], n=0;
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void nhapmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Phan Tu Thu ["<<i<<"]"; cin >> a[i];
    }
}
void xuatmang(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] <<" "; 
    }
    cout<<endl;
}
void xoa(int arr[], int &n, int vitri)
{
  for (int i = vitri + 1; i < n; i++)
  {
    arr[i-1] = arr[i];
  }
  n--;
}
void xoatrung(int arr[], int &n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for(int j = i + 1; j < n; j++)
    {
      if (arr[i]==arr[j])
      {
        xoa(arr,n,j);
        j--;
      }
    }
  }
}
// thuật toán chọn SelectionSort
void SelectionSort(int arr[], int n)
{
    int i, j, iMin;
    // di chuyển ranh giới của mảng chưa sắp xếp và đã săp xếp
    for ( i = 0; i < n - 1; i++)
    {
        iMin = i;
        for ( j = i + 1; j < n; j++)
        {
            if (arr[j]<arr[iMin])
            {
               iMin = j;
            }   
        }
        swap(&arr[iMin], &arr[i]);
    }
}
// thuat toan chen  InsertionSort
void  InsertionSort(int arr[], int n)
{
    int i, j, x;
    for ( i = 1; i < n; i++)
    {
       x=arr[i];
       j=i;
       while (j>0 && arr[j-1] > x)
       {
        arr[j] = arr[j-1];
        j--;
       }
       arr[j]=x;
    }   
}
// thuat toan noi bot bublesort
void BubleSort(int arr[], int n)
{
    int i, j;
    for ( i = 0; i < n -1; i++)
        for( j = 0; j < n - 1 - i; j++)
        if (arr[j]>arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
// thuat toan noi bot 2 chieu ShakerSort
void ShakerSort(int a[], int N)
{
   int i, k, left, right;
   k = 0;
   left = 0;
   right = N - 1;
   while (left < right) {
       for (i = right; i > left; i--)
           if (a[i] < a[i - 1]) {
               swap(a[i], a[i - 1]); // Hoan vi a[i], a[i - 1]
               k = i; // Dung bien k danh dau de bo qua doan da co thu tu.
           }
       left = k;
       for (i = left; i < right; i++)
           if (a[i] > a[i + 1]) {
              swap(a[i], a[i + 1]);
              k = i;
          }
      right = k;
   }
}
// thuat toan vun dong heapSort
void Heapify(int arr[], long n, long i)
{
    long Root = i;
    long L = 2 * i + 1;
    long R = 2 * i + 2;
    if ((L<n) && (arr[L] > arr[Root]))
    {
        Root = L;
    }
    if ((R < n) && (arr[R] > arr[Root]))
    {
        Root = R;
    }
    if (Root != i)
    {
       swap(&arr[i], &arr[Root]);
       Heapify(arr, n, Root);
    }
    
}
void HeapSort(int arr[], long n)
{
    for (long k = n / 2 - 1; k >= 0; k--)
    {
        Heapify(arr ,n ,k);
    }
    for (long i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        Heapify(arr ,i ,0);
    }
    
}
// thuat toan TRON MergeSort
void Merging( int arr[], long left, long mid, long right)
{
    long left_1, left_2, i;
    left_1 = left; left_2 = mid + 1;
    for ( i = left; left_1 <= mid && left_2 <= right; i++)
    {
        if (arr[left_1] <= arr[left_2])
            a[i] = arr[left_1++];
        else
            a[i] = arr[left_2++];
    }
    while (left_1 <= mid)
    {
        a[i++] = arr[left_1++];
    }
    while (left_2 <= right)
    {
        a[i++] = arr[left_2++];
    }
    for ( i = left; i <= right; i++)
    {
        arr[i] = a[i];
    }
}
void MergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left +(right-left)/2;
        MergeSort(arr,left,mid);
        MergeSort(arr,mid+1,right);
        Merging(arr, left, mid, right);
    }
}
// thuat toan sap xep nhanh QuickSort
int partition (int arr[], int low, int high)
{
    int pivot = arr[low];                // pivot lay phan tu o cuoi
    int left = low - 1;
    int right = high;
    // int pivot = arr[low + (high-low)/2];    // pivot lay phan tu o giua
    // int left = low;
    // int right = high ;
    // int pivot = arr[high];               // pivot lay phan tu o dau
    // int left = low;
    // int right = high - 1;
    while(1>0){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi = partition(arr, low, high);
 
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main() 
{
    static int b[1000000],x=0;
    FILE *file_input,*file_output;// bien con tro file
    file_input=fopen("d:\\code\\codeC++\\BTvecontro\\filesaver\\10.txt","r"); // mo file
        if (file_input == NULL) // kiểm tra file có tồn tại hay không nếu không thì thoát
    {
        std::cout << "file khong ton tai" << std::endl;
        exit(1);
    }
    int btg; // biến trung gian để đọc số từ file_input
    while (fscanf(file_input, "%d", &btg) != EOF) // đọc dữ liệu từ file vào mảng
    {
        b[n]=btg; // gán a = btg
        n++;
    }
    cout<<endl;
    fclose(file_input); // đóng file va lưu
    clock_t stat, end;
    double thoiluong;
    std::cout << "file dc sap xep theo thuat toan Tron" << std::endl;
    stat = clock();
    SelectionSort(b,n);
    xuatmang(b,n);
    xoatrung(b,n);
    xuatmang(b,n);
    end = clock();
    thoiluong = (double)(end - stat) / CLOCKS_PER_SEC;
    std::cout << "thoi gian hoan thanh thuat toan la:" << thoiluong << std::endl; 
    file_output=fopen("d:\\code\\codeC++\\BTvecontro\\filesaver\\test.txt","w");
    for (int i = 0; i < n; i++)
    {
       fprintf(file_output, "%8d", b[i]);
    }
    fclose(file_output);
    std::cout << "DONE" << std::endl;
}