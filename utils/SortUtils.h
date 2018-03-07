/*
 * SortUtils.h
 *
 *  Created on: 2018年3月7日
 *      Author: Prince29
 */

#ifndef SORTUTILS_H_
#define SORTUTILS_H_

#include "ArrayUtils.h"

/*快排*/
template<typename T>
void QuickSort(T &array,int low,int high){
	if(low>=high)return;

	int first=low;
	int last=high;
	int key=array[low];
	while(first<last){
		while(first<last&&key<array[last]){
			last--;
		}
		array[first]=array[last];
		while(first<last&&key>array[first]){
			first++;
		}
		array[last]=array[first];
	}
	array[first]=key;
	QuickSort(array,low,first-1);
	QuickSort(array,first+1,high);
}

/*快排*/
template<typename T>
void QuickSort(T &array){
	QuickSort(array,0,arrayLength(array)-1);
}

/*归并排序 */
//template<typename T>
//void MergeSort(T )

#endif /* SORTUTILS_H_ */
