/*
 * Map.h
 *
 *  Created on: 2018年3月8日
 *      Author: Prince29
 */

#ifndef MAP_H_
#define MAP_H_

#include <map>
#include <list>

namespace classes {
template<typename KEY,typename VALUE>
class Map {
private:
	std::map<KEY,VALUE> mMap;
public:
	Map(){}
	virtual ~Map(){}

	/*插入键值对*/
	void put(const KEY key,const VALUE val){
		if(mMap.count(key))
			mMap[key]=val;
		else
			mMap.insert(std::pair<KEY,VALUE>(key,val));
	}

	/*返回对应键的值的内存地址*/
	VALUE *get(const KEY key){
		typename std::map<KEY,VALUE>::iterator iter=mMap.find(key);
		if(iter!=mMap.end())
			return &iter->second;
		return NULL;
	}

	/*返回map的size*/
	int size() const{
		return mMap.size();
	}

	/*查询是否包含某个键，有的话返回1，没有的话返回0*/
	short containKey(const KEY key) const{
		return mMap.count(key);
	}
};

} /* namespace classes */

#endif /* MAP_H_ */
