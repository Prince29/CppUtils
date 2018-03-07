/*
 * ArrayUtils.h
 *
 *  Created on: 2018年3月7日
 *      Author: Prince29
 */

#ifndef ARRAYUTILS_H_
#define ARRAYUTILS_H_

template<typename T>
int ArrayLength(const T &array){
	return sizeof(array)/sizeof(array[0]);
}

template<typename T,typename C>
void ArrayShow(const T &array,C c){
	int len=arrayLength(array);
	for(int i=0;i<len;i++){
		std::cout<<array[i];
		if(i<len-1){
			std::cout<<c;
		}
	}
}

template<typename T>
void ArrayShow(const T &array){
	for(int i=0;i<ArrayLength(array);i++){
		std::cout<<array[i]<<" ";
	}
}

template<typename T,typename R>
void ArrayCopy(T &res,R &src,int size){
	for(int i=0;i<size;i++){
		res[i]=src[i];
	}
}
#endif /* ARRAYUTILS_H_ */
