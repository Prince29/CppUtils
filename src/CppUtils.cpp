//============================================================================
// Name        : CppUtils.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//#include <string>
//using namespace std;

#include "../tests/student/Student.h"

int main() {
	Student student;
	Student student1;
	student.setName("张三");
	student.setAge(18);
	student.setSex(Sex::FEMALE);
	student.setScore(99.5);
	SchoolInfo schoolInfo;
	schoolInfo.mGrade=6;
	schoolInfo.mClass=10;
	schoolInfo.mDegree=Degree::SENIOR;
	student.setSchool(schoolInfo);

	student1=student.copy();
	student1.setName("李四");

	student.show();
	student1.show();
}
