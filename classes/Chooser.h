/*
 * BashChooser.h
 *
 *  Created on: 2018年3月8日
 *      Author: Prince29
 */

#ifndef BASHCHOOSER_H_
#define BASHCHOOSER_H_

#include "Map.h"

namespace classes{
template<typename KEY,typename VALUE>
class Chooser{
protected:
	static classes::Map<KEY,VALUE> chooserMap;
protected:
	Chooser(classes::Map<KEY,VALUE> mMap){
		chooserMap=mMap;
	}
	virtual ~Chooser(){
	}

	virtual void registor(const KEY key,VALUE& val);
	virtual void registor();
	virtual VALUE *get(const KEY key);
	virtual VALUE *get();
	//virtual void show() const=0;
};
}/* namespace classes */

#endif /* BASHCHOOSER_H_ */
