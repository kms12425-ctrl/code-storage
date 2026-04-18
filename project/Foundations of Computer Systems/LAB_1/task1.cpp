#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef long long ll;

#define N 5
#define N1 2
#define N2 3

struct student
{
    char name[8];
    short age;
    float score;
    char remark[200]; // 备注信息
};

int pack_student_bytebybyte(student *s, int sno, char *buf);
int pack_student_whole(student *s, int sno, char *buf);
int restore_student(char *buf, int len, student *s);
void print_res(student *s, int len);
int main()
{
    // 解题代码
    struct student beforecompress[N];
    char message[5000];

    strcpy(beforecompress[0].name, "Rocky");
    beforecompress[0].score = 42.0;
    beforecompress[0].age = 20;
    strcpy(beforecompress[0].remark, "Great");

    printf("第0个学生的score 32位浮点数编码:\n");
    printf("二进制:0 10000100 01010000000000000000000\n");
    printf("十六进制:0x42280000\n");

    for (int i = 1; i < N; i++) // 输入学生信息
    {
        scanf("%s  %hd  %f  %s", beforecompress[i].name, &beforecompress[i].age, &beforecompress[i].score, beforecompress[i].remark);
    }

    // 打印压缩前结果
    print_res(beforecompress, N);
    printf("压缩前存放数据的长度为:%zu\n", sizeof(beforecompress));

    // 压缩
    int bytebybyte_len = pack_student_bytebybyte(beforecompress, N1, message);
    int whole_len = pack_student_whole(beforecompress, N2, message + bytebybyte_len);

    printf("压缩后存放数据的长度为:%d\n", bytebybyte_len + whole_len);

    //  输出message的前40个字节的内容
    printf("message的前40个字节的内容:\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%02X ", (unsigned char)message[i]);
    }
    printf("\n");
    // 解压
    struct student decompress[N];
    int stu_num = restore_student(message, bytebybyte_len + whole_len, decompress);

    // 打印解压后结果
    print_res(decompress, N);

    return 0;
}
int pack_student_bytebybyte(student *s, int sno, char *buf)
{
    int byte_len = 0;
    for (int i = 0; i < sno; i++)
    {
        for (int j = 0; s[i].name[j] != '\0'; j++)
            buf[byte_len++] = s[i].name[j];
        buf[byte_len++] = '\0';

        unsigned char *age_ptr = (unsigned char *)&s[i].age;
        for (int j = 0; j < sizeof(short); j++)
            buf[byte_len++] = age_ptr[j];

        unsigned char *score_ptr = (unsigned char *)&s[i].score;
        for (int j = 0; j < sizeof(float); j++)
            buf[byte_len++] = score_ptr[j];

        for (int j = 0; s[i].remark[j] != '\0'; j++)
            buf[byte_len++] = s[i].remark[j];
        buf[byte_len++] = '\0';
    }
    return byte_len;
}
int pack_student_whole(student *s, int sno, char *buf)
{
    int byte_len = 0;
    for (int i = 2; i < sno + 2; i++)
    {
        strcpy(buf + byte_len, s[i].name);
        byte_len = byte_len + strlen(s[i].name) + 1;

        *(short *)(buf + byte_len) = s[i].age;
        byte_len = byte_len + sizeof(short);

        *(float *)(buf + byte_len) = s[i].score;
        byte_len = byte_len + sizeof(float);

        strcpy(buf + byte_len, s[i].remark);
        byte_len = byte_len + strlen(s[i].remark) + 1;
    }
    return byte_len;
}
int restore_student(char *buf, int len, student *s)
{
    int cur_len = 0, i;
    for (i = 0; cur_len <= len; i++)
    {
        strcpy(s[i].name, buf + cur_len);
        cur_len = cur_len + strlen(s[i].name) + 1;

        s[i].age = *(short *)(buf + cur_len);
        cur_len = cur_len + sizeof(short);

        s[i].score = *(float *)(buf + cur_len);
        cur_len = cur_len + sizeof(float);

        strcpy(s[i].remark, buf + cur_len);
        cur_len = cur_len + strlen(s[i].remark) + 1;
    }
    return i + 1;
}
void print_res(student *s, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("第%d个学生信息如下:\n", i + 1);
        printf("姓名:%s\n", s[i].name);
        printf("年龄:%d\n", s[i].age);
        printf("分数:%.2f\n", s[i].score);
        printf("备注:%s\n", s[i].remark);
        printf("--------------------------\n");
    }
}