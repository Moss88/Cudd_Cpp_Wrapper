/*
 * CUDDManager.h
 *
 *  Created on: Jan 8, 2015
 *      Author: lukepierc
 */


#include "util.h"
#include "cudd.h"
#include "cuddInt.h"
#include "dddmp.h"
class CuddManager {
	public:
	static DdNode* newVar();
	static DdManager* manager;
	static DdNode* zero();
};




