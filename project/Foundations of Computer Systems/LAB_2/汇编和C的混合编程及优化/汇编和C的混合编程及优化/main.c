#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <string.h>

#define STUDENTS_NUM 10

typedef struct temp
{
	char sname[8];
	char sid[11];	 //  学号
	short scores[8]; //  8门课的分数
	short average;	 //  平均分
} student;

void displayStu(student* s, int num)
{
	for (int i = 0; i < num; i++)
	{
		printf("学生姓名：%s ", s[i].sname);
		printf("学号:%s ", s[i].sid);
		printf("八门课分数分别为:");
		for (int j = 0; j < 8; j++)
		{
			printf("%d ", s[i].scores[j]);
		}
		printf("平均分为:%d\n", s[i].average);
	}
}
void initStudents(student* s, int num)
{
	srand((unsigned int)time(NULL));
	strcpy(s[0].sname, "JunHao");
	strcpy(s[0].sid, "U202490042");
	s[0].scores[0] = 95;
	s[0].scores[1] = 85;
	s[0].scores[2] = 90;
	for (int i = 1; i < 8; i++)
		s[0].scores[i] = 80 + i;
	s[0].average = 0;

	for (int i = 1; i < num; i++)
	{
		sprintf(s[i].sname, "Stu%d", i + 1);
		sprintf(s[i].sid, "U2024%05d", i + 1);
		for (int j = 0; j < 8; j++)
		{
			s[i].scores[j] = rand() % 101;
		}
		s[i].average = 0;
	}
}

void computeAverageScore(student* s, int num);
void computeAverageScore_improve(student* s, int num);
//{
//	for (int i = 0; i < num; i++)
//	{
//		int sum = 0;
//		for (int j = 0; j < 8; j++)
//		{
//			sum = sum + s[i].scores[j];
//		}
//		s[i].average = sum / 8;
//	}
//}

int compareStudent(void* a, void* b)
{
	student* s1 = (student*)a;
	student* s2 = (student*)b;
	return s2->average - s1->average;
}

void SortStudentScore(student* s, int num)
{
	qsort(s, num, sizeof(student), compareStudent);
}

void QueryPerformanceCounter_demo()
{
	LARGE_INTEGER start, finish, frequency;

	double duration;
	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&start);
	for (int x = 0; x < 2000000; x++)
		x = x;
	QueryPerformanceCounter(&finish);
	duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 /
		frequency.QuadPart;
	printf("counter demo : %f 毫秒 \n", duration);
}

#define Time_Anyfunc(afuncall)                                           \
	do                                                                   \
	{                                                                    \
		LARGE_INTEGER start, finish, frequency;                          \
		double duration;                                                 \
		QueryPerformanceFrequency(&frequency);                           \
		QueryPerformanceCounter(&start);                                 \
		afuncall;                                                        \
		QueryPerformanceCounter(&finish);                                \
		duration = (double)(finish.QuadPart - start.QuadPart) * 1000.0 / \
				   frequency.QuadPart;                                   \
		printf("Time_Anyfunc : %f 毫秒 \n", duration);                   \
	} while (0);

void GetTickCount_demo()
{
	unsigned int start, finish, duration;
	start = GetTickCount(); // 头文件windows.h。得到的是系统运行的时间 精确到毫秒，

	for (int x = 0; x < 2000000; x++)
		x = x;
	finish = GetTickCount();
	duration = finish - start;
	printf("GetTickCount demo： %d  毫秒\n", duration);
	;
}

int main()
{
	student s[STUDENTS_NUM];

	QueryPerformanceCounter_demo();
	GetTickCount_demo();

	printf("%d\n", sizeof(student));
	initStudents(s, STUDENTS_NUM); // 初始化学生信息

	printf("\n");
	printf("计算平均成绩时间（未优化）:\n");
	Time_Anyfunc(computeAverageScore(s, STUDENTS_NUM));


	printf("计算平均成绩时间（优化）:\n");
	Time_Anyfunc(computeAverageScore_improve(s, STUDENTS_NUM));
	printf("排序前的学生信息如下:\n");
	displayStu(s, STUDENTS_NUM);

	printf("计算按平均成绩排序时间:\n");
	Time_Anyfunc(SortStudentScore(s, STUDENTS_NUM));

	printf("排序后的学生信息如下:\n");
	displayStu(s, STUDENTS_NUM);

	getchar();
	return 0;
}
