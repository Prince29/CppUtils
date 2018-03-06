/*
 * Student.cpp
 *
 *  Created on: 2018年3月6日
 *      Author: Prince29
 */

#include "Student.h"

Student::Student() {
	// TODO Auto-generated constructor stub
	this->age=0;
	this->score=0.0;
	this->sex=Sex::MALE;

}

Student::~Student() {
	// TODO Auto-generated destructor stub
}

void Student::show(){
	std::cout<<"============="<<std::endl;
	std::cout<<"name:"<<this->name<<std::endl;
	std::cout<<"sex:"<<this->sex<<std::endl;
	std::cout<<"age:"<<this->age<<std::endl;
	std::cout<<"score:"<<this->score<<std::endl;
	std::cout<<"grade:"<<this->school.mGrade<<std::endl;
	std::cout<<"class:"<<this->school.mClass<<std::endl;
	std::cout<<"degree:"<<this->school.mDegree<<std::endl;
	std::cout<<"============="<<std::endl;
}

Student Student::copy(){
	Student student;
	student.setName(this->name);
	student.setSex(this->sex);
	student.setAge(this->age);
	student.setScore(this->score);

	SchoolInfo schoolInfo;
	schoolInfo.mGrade=this->school.mGrade;
	schoolInfo.mClass=this->school.mClass;
	schoolInfo.mDegree=this->school.mDegree;

	student.setSchool(schoolInfo);
	return student;
}

bool Student::cmpDesc(const Student &a,const Student &b){
	return a.getScore()>b.getScore();
}
bool Student::cmpAsc(const Student &a,const Student &b){
	return a.getScore()<b.getScore();
}
