/*
 * StudentStruct.h
 *
 *  Created on: 2018年3月6日
 *      Author: Prince29
 */

#ifndef STUDENTSTRUCT_H_
#define STUDENTSTRUCT_H_

enum Sex{MALE,FEMALE};//性别
enum Degree{PRESCHOOL,PRIMARY,JUNIOR,SENIOR,UNIVERSITY};//学历



struct SchoolInfo{
	int mGrade;
	int mClass;
	Degree mDegree;
};



#endif /* STUDENTSTRUCT_H_ */
