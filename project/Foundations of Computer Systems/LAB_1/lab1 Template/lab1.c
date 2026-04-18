#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"

student_t student;

void main(void)
{
	memset(&student, 0, sizeof(student_t));
	strcpy(student.name, "wangwu");
	student.age = 20;
	student.score = 90;
	strcpy(student.remark, "good!");

	printf("%s  %d  %f  %s\n", student.name, student.age, student.score, student.remark);
}