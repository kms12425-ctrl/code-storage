#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <random>

using namespace std;

typedef long long ll;

int absVal(int x) // 返回 x 的绝对值
{
    int m = x >> 31;
    x = (m + x) ^ m;
    return x;
}
int absVal_standard(int x) { return (x < 0) ? -x : x; }

int negate(int x) // 不使用负号，实现 -x
{
    return (~x + 1);
}
int netgate_standard(int x) { return -x; }

int bitAnd(int x, int y) // 仅使用 ~ 和 |，实现 &
{
    int res = ~((~x) | (~y));
    return res;
}
int bitAnd_standard(int x, int y) { return x & y; }

int bitOr(int x, int y) // 仅使用 ~ 和 &，实现 |
{
    int res = ~((~x) & (~y));
    return res;
}
int bitOr_standard(int x, int y) { return x | y; }

int bitXor(int x, int y) // 仅使用 ~ 和 &，实现 ^
{
    int res = ~((~(x & (~y))) & (~(y & (~x))));
    return res;
}
int bitXor_standard(int x, int y) { return x ^ y; }

int isTmax(int x) // 判断x是否为最大的正整数（7FFFFFFF）
{
    return (!((x + 1) ^ (~x))) & (!!(x + 1));
}
int isTmax_standard(int x) { return (x == 0x7FFFFFFF); }

int bitCount(int x) // 统计x的二进制表示中 1 的个数
{
    int m1 = 0x55; // 构建01010101....
    m1 = m1 | (m1 << 8);
    m1 = m1 | (m1 << 16);

    int m2 = 0x33; // 构建00110011...
    m2 = m2 | (m2 << 8);
    m2 = m2 | (m2 << 16);

    int m3 = 0x0f; // 构建00001111...
    m3 = m3 | (m3 << 8);
    m3 = m3 | (m3 << 16);

    int m4 = 0xff; // 构建00000000 11111111...
    m4 = m4 | (m4 << 16);

    int m5 = 0xff; // 构建00000000000000001111111111111111
    m5 = m5 | (m4 << 8);

    x = (x & m1) + ((x >> 1) & m1);
    x = (x & m2) + ((x >> 2) & m2);
    x = (x & m3) + ((x >> 4) & m3);
    x = (x & m4) + ((x >> 8) & m4);
    x = (x & m5) + ((x >> 16) & m5);
    return x;
}
int bitCount_standard(int x) { return __builtin_popcount(x); }

int bitMask(int lowbit, int highbit) // 产生从lowbit 到 highbit 全为1，其他位为0的数
{
    int x;
    int m1 = ~((~0 << highbit) << 1);
    int m2 = ~((~0 << lowbit));
    x = m1 ^ m2;
    return x;
}
int bitMask_standard(int lowbit, int highbit)
{
    int result = 0;
    for (int i = lowbit; i <= highbit; i++)
    {
        result |= (1U << i);
    }
    return result;
}

int addOK(int x, int y) // 当 x+y 会产生溢出时返回1，否则返回 0
{
    int sum = x + y;
    int sign_x = x >> 31;
    int sign_y = y >> 31;
    int sign_sum = sum >> 31;

    int over_F = (~(sign_x ^ sign_y)) & (sign_x ^ sign_sum);
    return over_F;
}
int addOK_standard(int x, int y)
{
    int sum = x + y;
    int neg_over = x < 0 && y < 0 && sum >= 0;
    int pos_over = x >= 0 && y >= 0 && sum < 0;
    return !neg_over && !pos_over;
}

int byteSwap(int x, int n, int m) // 将x的第n个字节与第m个字节交换，返回交换后的结果。 n、m的取值在 0~3之间
{
    int byte_m = (x >> (m << 3)) & 0xff;
    int place_m = byte_m << (n << 3);

    int byte_n = (x >> (n << 3)) & 0xff;
    int place_n = byte_n << (m << 3);

    int clear = (0xff << (n << 3)) | (0xff << (m << 3));
    clear = (~clear) & x;
    return (clear | place_m | place_n);
}
int byteSwap_standard(int x, int n, int m)
{
    // 利用联合体（Union）或者强制指针转换来按字节访问
    // 这里使用最直观的指针转换。因为 x 是按值传递的临时变量，修改它不会影响外面的变量。
    unsigned char *bytes = (unsigned char *)&x;

    // 直接交换第 n 个和第 m 个字节
    unsigned char temp = bytes[n];
    bytes[n] = bytes[m];
    bytes[m] = temp;

    // 返回被修改后的 x
    return x;
}

int bang(int x) // x =0 时，返回 1; 其他情况返回 0。实现逻辑非(!)
{
    int sign_minus_x = (~x + 1) >> 31;
    int sign = sign_minus_x | x;
    sign = (sign >> 31) & 1;
    return (sign ^ 1);
}
int bang_standard(int x) { return !x; }

int bitParity(int x) // 当 x有奇数个二进制位0，返回1；否则返回0
{
    x = x ^ (x >> 16);
    x = x ^ (x >> 8);
    x = x ^ (x >> 4);
    x = x ^ (x >> 2);
    x = x ^ (x >> 1);
    return x & 1;
}
int bitParity_standard(int x) { return __builtin_parity(x); }
int myrand(int y = -32768, int x = 32767)
{
    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<int> dis(y, x);

    return dis(gen);
}
int main()
{
    printf("1.abs 测试...\n"); // 1
    // bool flag = 1;
    for (int i = 0; i < 10; i++)
    {
        int num = myrand();
        if (absVal(num) != absVal_standard(num))
        {
            printf("abs 测试不通过\n");
            return 0;
        }
    }
    printf("1.abs 测试通过\n");
    printf("\n");
    printf("2.negate 测试...\n"); // 2
    for (int i = 0; i < 10; i++)
    {
        int num = myrand();
        if (::negate(num) != netgate_standard(num))
        {
            printf("negate 测试不通过\n");
            return 0;
        }
    }
    printf("2.negate 测试通过\n");
    printf("\n");
    printf("3.bitAnd 测试...\n"); // 3
    for (int i = 0; i < 10; i++)
    {
        int num_1 = myrand();
        int num_2 = myrand();
        if (bitAnd(num_1, num_2) != bitAnd_standard(num_1, num_2))
        {
            printf("bitAnd 测试不通过\n");
            return 0;
        }
    }
    printf("3.bitAnd 测试通过\n");
    printf("\n");
    printf("4.bitOr 测试...\n"); // 4
    for (int i = 0; i < 10; i++)
    {
        int num_1 = myrand();
        int num_2 = myrand();
        if (bitOr(num_1, num_2) != bitOr_standard(num_1, num_2))
        {
            printf("bitOr 测试不通过\n");
            return 0;
        }
    }
    printf("4.bitOr 测试通过\n");
    printf("\n");
    printf("5.bitXor 测试...\n"); // 5
    for (int i = 0; i < 10; i++)
    {
        int num_1 = myrand();
        int num_2 = myrand();
        if (bitXor(num_1, num_2) != bitXor_standard(num_1, num_2))
        {
            printf("bitXor 测试不通过\n");
            return 0;
        }
    }
    printf("5.bitXor 测试通过\n");
    printf("\n");
    printf("6.isTmax 测试...\n"); // 6
    for (int i = 0; i < 10; i++)
    {
        int num;
        if (i == 0)
            num = 0x7FFFFFFF;
        else if (i == 1)
            num = -1;
        else
            num = myrand();
        if (isTmax(num) != isTmax_standard(num))
        {
            printf("isTmax 测试不通过\n");
            return 0;
        }
    }
    printf("6.sTmax 测试通过\n");
    printf("\n");
    printf("7.bitCount 测试...\n"); // 7
    for (int i = 0; i < 10; i++)
    {
        int num = myrand();
        if (bitCount(num) != bitCount_standard(num))
        {
            printf("bitCount 测试不通过\n");
            return 0;
        }
    }
    printf("7.bitCount 测试通过\n");
    printf("\n");
    printf("8.bitMask 测试...\n"); // 8
    for (int i = 0; i < 10; i++)
    {
        // 位索引必须在 0 到 31 之间，并且保证 low <= high
        int low = myrand(0, 31);
        int high = myrand(low, 31);
        if (bitMask(low, high) != bitMask_standard(low, high))
        {
            printf("bitMask 测试不通过 (low=%d, high=%d)\n", low, high);
            return 0;
        }
    }
    printf("8.bitMask 测试通过\n");
    printf("\n");
    printf("9.addOK 测试...\n"); // 9
    for (int i = 0; i < 10; i++)
    {
        int num_1 = myrand();
        int num_2 = myrand();
        if (addOK(num_1, num_2) != !addOK_standard(num_1, num_2))
        {
            printf("addOK 测试不通过(num_1=%d,num_2=%d)\n", num_1, num_2);
            return 0;
        }
    }
    printf("9.addOK 测试通过\n");
    printf("\n");
    printf("10.byteSwap 测试...\n"); // 10
    for (int i = 0; i < 10; i++)
    {
        int x = myrand();
        int num_1 = myrand(0, 3);
        int num_2 = myrand(0, 3);
        if (byteSwap(x, num_1, num_2) != byteSwap_standard(x, num_1, num_2))
        {
            printf("byteSwap 测试不通过\n");
            return 0;
        }
    }
    printf("10.byteSwap 测试通过\n");
    printf("\n");
    printf("11.bang 测试...\n"); // 11
    for (int i = 0; i < 10; i++)
    {
        int num = myrand();
        if (i == 0)
            num = 0;
        if (bang(num) != bang_standard(num))
        {
            printf("bang 测试不通过\n");
            return 0;
        }
    }
    printf("11.bang 测试通过\n");
    printf("\n");
    printf("12.bitParity 测试...\n"); // 12
    for (int i = 0; i < 10; i++)
    {
        int num = myrand();
        if (bitParity(num) != bitParity_standard(num))
        {
            printf("bitParity 测试不通过\n");
            return 0;
        }
    }
    printf("12.bitParity 测试通过\n");
    printf("\n");
    return 0;
}