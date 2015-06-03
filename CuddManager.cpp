/*
 * CUDDManager.cpp
 *
 *  Created on: Jan 8, 2015
 *      Author: lukepierc
 */
#include "BoolLogic/CuddManager.h"

DdManager* CuddManager::manager = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0);

DdNode* CuddManager::newVar() {
    return Cudd_bddNewVar(manager);
}

DdNode* CuddManager::zero() {
	return Cudd_ReadLogicZero(manager);
}

