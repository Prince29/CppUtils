//============================================================================
// Name        : CppUtils.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <iostream>
//#include <string>
using namespace std;

#include "../tests/student/Student.h"
#include "../utils/SortUtils.h"
#include "../utils/ArrayUtils.h"

#include <cstring>
#include <algorithm>
#include <list>

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

	std::list<Student> studentList;
	studentList.push_back(student);
	studentList.push_back(student1);
	//studentList.sort(student.cmpAsc());

	student.show();
	student1.show();
	cout<<"list size:"<<studentList.size()<<endl;

	int a[]={6,2,7,3,8,9};
	char b[]={'a','z','k','b','g'};
	int c[6]={0};
	char d[5]={0};
	ArrayShow(a);
	cout<<endl;
	//arrayShow(a,"->");

//	QuickSort(a);
//	QuickSort(b);
	MergeSort(a,c);
	MergeSort(b,d);
	cout<<"len:"<<ArrayLength(c)<<":"<<ArrayLength(d)<<endl;
	ArrayShow(c);
	cout<<":";
	ArrayShow(d);
	cout<<endl;
	ArrayShow(b);

}
