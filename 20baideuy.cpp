#include <bits/stdc++.h>

// Bai 1 S(n) = 1+2+3+...+n
int BT1(int n)
{
    if(n == 1)
    return 1;
    else
    return BT1(n-1) + n;
}

// Bai 2 S(n) = 1~2+2~2+3~2+...+n~2
int BT2(int n)
{
    if(n == 1)
    return 1;
    else
    return  BT2(n - 1) + (n * n);
}

// Bai 3 S(n) = 1+ ½ +1/3 +...+1/n
float BT3(float n)
{
    if(n == 1)
    return 1.0;
    if(n > 1)
    return BT3(n-1) + (1/n);
}

// Bai 4 S(n) = 1/2+ 1/4 +1/6 +...+1/2n
float BT4(float n)
{
    if(n == 1)
    return 1.0;
    else
    return BT4(n - 1) + (1/(2*n));
}

// Bai 5 S(n) = 1/(1x2)+ 1/(2x3) +...+1/(n x(n+1))
float BT5(float n)
{
    if(n == 1)
    return 1.0;
    else
    return BT5(n - 1) + (1/(n*(n+1)));
}

// Bai 6 S(n) = ½ + ¾ +5/6 +... +(2n+1)/(2n+2)
float BT6(float n)
{
    if(n == 1)
    return 1.0;
    else
    return BT6(n-1) + (float)((((2 * n) + 1)/((2 * n) + 2)));
}

// Bai 7 S(n) = 1/3+1/5+...+1/(2n+1)
float BT7(float n)
{
    if(n == 0)
    return 1.0;
    else
    return BT7(n - 1) + (1/(2*n+1));
}

// bai 8 S(n) = ½+2/3+...+n/(n+1)
float BT8(float n)
{
    if(n == 0)
    return 0;
    else
    return BT8(n - 1) + (n / (n+1));
}

// Bai 9 S(n) = 1+ x+ x2 +...+ xn
int BT9(int n, int x)
{
    if(n == 0)
    return 1;
    else
    return BT9(n - 1, x) + (pow(x,n));
}

// Bai 10 S(n) = x2+ x4 +...+ x2n
int BT10(int n, int x)
{
    if(n == 0)
    return 1;
    else
    return BT10(n - 1, x) + (pow(x,n*2));
}

// Bai 11 S(n) = 1! +2!+ ...+n!
int BT11(int n)
{
    if(n == 0)
    return 1;
    else
    return BT11(n - 1) * n;
}

// Bai 12 S(n) = x2/2+ x4/4 +...+ x2n/2n
float BT12(float n, float x)
{
    if(n == 1)
    return (x*x)/2;
    else
    return BT12(n - 1, x) + ((pow(x,n * 2))/(n * 2));
}

// Bai 13 Tìm ước số chung lớn nhất (a,b) của 2 số nguyên a, b
int BT13(int a , int b)
{
    if(b == 0) 
    return a;
    return BT13(b, a % b); 
}

// Bai 14 Đếm số lượng chữ số của một số nguyên n
int BT14(int n)
{
    if(n < 10)
    return 1;
    else
    return 1 + BT14(n / 10);
}

// Bai 15 Hãy tính tổng các chữ số của số nguyên dương n
int BT15(int n)
{
    if(n == 0)
    return 0;
    else
    return n % 10 + BT15(n / 10);
}

// Bai 16 Hãy tính tích các chữ số của số nguyên dương n
int BT16(int n)
{
    if(n == 0)
    return 1;
    else
    return n % 10 * BT15(n / 10);
}

// Bai 17 Hãy đếm số lượng chữ số lẻ của số nguyên dương n
int BT17(int n)
{
    if(n%2 == 0)
    return 0;
    else
    return 1 + BT17(n / 10);
}

// Bai 18 Hãy tính tổng các chữ số chẵn của số nguyên dương n
static int sum = 0;
int BT18(int n)
{
    if(n == 0) return sum;
    int temp = n % 10;
    if(temp % 2 == 0) 
    sum = sum + temp;
    return BT18(n / 10);
}

// Bai 19 Tìm chữ số lớn nhất của số nguyên dương n
int max(int a, int b)
{
    if(a > b)
    return a;
    else
    return b;
}
int BT19(int n)
{
    if(n < 10)
    return n;
    else 
    return max(BT19(n / 10), n % 10);
}

// Bai 20  Hãy kiểm tra số nguyên dương n có toàn chữ số lẻ hay không ?
int BT20(long n)
{
    if(n < 10)
    {
        if(n % 2 == 0)
        return 0;
        else
        return 1;
    }
    else
    {
        if((n % 10) % 2 == 0)
        return 0;
        else
        return BT20(n / 10);
    }
}
int main()
{
    int a = 12, x = 2, b = 5;
    printf("BT1 = %d( S(n) = 1+2+3+...+n )\n",BT1(a));
    printf("BT2 = %d( S(n) = 12+22+32+...+n2 )\n",BT2(a));
    printf("BT3 = %f( S(n) = 1+ ½ +1/3 +...+1/n )\n",BT3(a));
    printf("BT4 = %f( S(n) = 1/2+ 1/4 +1/6 +...+1/2n )\n",BT4(a));
    printf("BT5 = %f( S(n) = 1/(1x2)+ 1/(2x3) +...+1/(n x(n+1)) )\n",BT5(a));
    printf("BT6 = %f( S(n) = 1/2 + 3/4 +5/6 +... +(2n+1)/(2n+2) )\n",BT6(a));
    printf("BT7 = %f( S(n) = 1/3+1/5+...+1/(2n+1) )\n",BT7(a));
    printf("BT8 = %f( S(n) = 1/2+2/3+...+n/(n+1) )\n",BT8(a));
    printf("BT9 = %d( S(n) = 1+ x+ x2 +...+ xn )\n",BT9(a,x));
    printf("BT10 = %d( S(n) = x2+ x4 +...+ x2n )\n",BT10(a,x));
    printf("BT11 = %d( S(n) = 1! +2!+ ...+n! )\n",BT11(a));
    printf("BT12 = %f( S(n) = x2/2+ x4/4 +...+ x2n/2n )\n",BT12(a,x));
    printf("BT13 = %d( Tim uoc so chung lon nhat (a,b) cua 2 so nguyen a, b )\n",BT13(a,b));
    printf("BT14 = %d( Dem so luong chu so cua mot so nguyen n )\n",BT14(a));
    printf("BT15 = %d( Hay tinh tong cac chu so nguyen duong n )\n",BT15(a));
    printf("BT16 = %d( Hay tinh tich cac chu so nguyen duong n )\n",BT16(a));
    printf("BT17 = %d( Hay dem so luong chu so le cua so nguyen n )\n",BT17(a));
    printf("BT18 = %d( Hay tinh tong cac chu so chan cua so nguyen n )\n",BT18(123456));
    printf("BT19 = %d( Tim so lon nhat cua so nguyen n )\n",BT19(129456));
    printf("BT20 = [%d] ( 1 la toan so chan - 0 la toan so le )\n",BT20(12986456));
    return 0;
}
