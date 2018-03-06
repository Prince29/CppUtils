/*
 * Student.h
 *
 *  Created on: 2018年3月6日
 *      Author: Prince29
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
#include <iostream>
#include "StudentStruct.h"


class Student {
private:
	std::string name;
	Sex sex;
	int age;
	float score;
	SchoolInfo school;

public:
	void show();
	Student copy();
	bool cmpDesc(const Student &a,const Student &b);
	bool cmpAsc(const Student &a,const Student &b);

	Student();
	virtual ~Student();

	int getAge() const {
		return age;
	}

	void setAge(int age) {
		this->age = age;
	}

	const std::string& getName() const {
		return name;
	}

	void setName(const std::string& name) {
		this->name = name;
	}

	const SchoolInfo& getSchool() const {
		return school;
	}

	void setSchool(const SchoolInfo& school) {
		this->school = school;
	}

	float getScore() const {
		return score;
	}

	void setScore(float score) {
		this->score = score;
	}

	Sex getSex() const {
		return sex;
	}

	void setSex(Sex sex) {
		this->sex = sex;
	}
};

#endif /* STUDENT_H_ */
