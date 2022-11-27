//đặt n quân hậu vào n * n (n>=4)ô sao cho không quân nào được ăn quân nào
//thuật toán: dùng phương pháp quay lui
//hàm đặt quân hậu hợp lệ ở vị trí tiếp theo
//hàm in vị trí hợp lệ
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <time.h>

int solution[20];
int count = 0;
FILE *file_target;

void wait(int seconds)
{
	clock_t ew;
	ew = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < ew) {}
}

//kiểm tra cách đặt có thỏa mãn không
// x2,y2 : vị trí đặt Queen ở cột mới
int Ok(int x2,int y2)
{
// So sánh với các vị trí đã đặt Queen lúc trước
for(int i = 1; i < x2 ;i++)
if(solution[i] == y2 || abs(i-x2) == abs(solution[i] - y2) )
return 0;
//Nếu kiểm tra hết các trường hợp vẫn không sai thì trả về true
return 1;
}

void Xuat(int n)
{
//In ra màn hình
for (int col=1;col<=n;col++)
printf(" %d",solution[col]);
printf("\n");
for (int row=1;row<=n;row++)
{
for(int col=1;col<=n;col++)
{
if (solution[col]==row) printf(" Q");
else printf(" -");
}
printf("\n");
}
printf("-----------------------------------\n");
//In vào file
for (int col=1;col<=n;col++)
fprintf(file_target,"% d",solution[col]);
fprintf(file_target,"\n");
for (int row=1;row<=n;row++)
{
for(int col=1;col<=n;col++)
{
if (solution[col]==row) fprintf(file_target," Q");
else fprintf(file_target," -");
}
fprintf(file_target,"\n");
}
fprintf(file_target,"-----------------------------------\n");
}

// Hàm thử một phương án đặt quân hậu
void Try(int i,int n){
    for(int j = 1;j<=n;j++){
    // thử đặt quân hậu vào các cột từ 1 đến n
        if(Ok(i,j))
        {
        //nếu cách đặt này thỏa mãn thì lưu lại vị trí
        solution[i] = j;
        //printf("\nhop le i = %d, j = %d\n", i, j);
        //nếu đặt xong quân hậu thứ n thì xuất ra một kết quả);
        if(i==n) Xuat(n);
        Try(i+1,n);
        }
    //printf("chay i = %d, j = %d\n", i, j);
    //wait(1); // 2 giây.
    }
}


int main()
{
int n = 8;// bài toán là 8 quân hậu trên bàn 8*8
file_target=fopen("ketqua_8queen.txt","w");
Try(1,n);
fclose(file_target);
return 0;
}