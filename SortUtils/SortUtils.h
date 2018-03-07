/*
 * SortUtils.h
 *
 *  Created on: 2018年3月7日
 *      Author: Prince29
 */

#ifndef SORTUTILS_H_
#define SORTUTILS_H_

/**快排*/
template<typename T>
void QuickSort(T &a,int low,int high){
	if(low>=high)return;

	int first=low;
	int last=high;
	int key=a[low];
	while(first<last){
		while(first<last&&key<a[last]){
			last--;
		}
		a[first]=a[last];
		while(first<last&&key>a[first]){
			first++;
		}
		a[last]=a[first];
	}
	a[first]=key;
	QuickSort(a,low,first-1);
	QuickSort(a,first+1,high);
}



#endif /* SORTUTILS_H_ */
