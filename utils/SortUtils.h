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
	QuickSort(array,0,ArrayLength(array)-1);
}

/*归并排序 */
template<typename T,typename R>
void Merge(T &array,int start,int mid,int end,R &result){
	int first=start;
	int second=mid+1;
	int resIndex=0;
	while(first<=mid&&second<=end){
		if(array[first]<array[second])
			result[resIndex++]=array[first++];
		else{
			result[resIndex++]=array[second++];
		}
	}
	while(first<=mid)
		result[resIndex++]=array[first++];
	while(second<=end)
		result[resIndex++]=array[second++];
	for(int i=0;i<resIndex;i++){
		array[start+i]=result[i];
	}
}

/*归并排序 */
template<typename T,typename R>
void MergeSort(T &array,int start,int end,R &result){
	if(start<end){
		int mid=(start+end)/2;
		MergeSort(array,start,mid,result);
		MergeSort(array,mid+1,end,result);
		Merge(array,start,mid,end,result);
	}
}

/*归并排序 */
template<typename T,typename R>
void MergeSort(T &array,R &result){
	MergeSort(array,0,ArrayLength(array)-1,result);
}

#endif /* SORTUTILS_H_ */
