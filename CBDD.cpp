/*
 * CBDD.cpp
 *
 *  Created on: Jan 7, 2015
 *      Author: lpierce
 */

#include "CBDD.h"

using namespace BFAST;

CBDD::CBDD(){
	func = Cudd_ReadOne(CuddManager::manager);
    Cudd_Ref(func);
}

void CBDD::clear() {
	Cudd_RecursiveDeref(CuddManager::manager, func);
}

CBDD::CBDD(DdNode *node) {
	func = node;
    Cudd_Ref(func);
}

CBDD& CBDD::operator=(const CBDD& other) {
	if(this == &other)
		return *this;

	clear();
	func = other.func;
	Cudd_Ref(func);
	return *this;
}

CBDD::~CBDD() {
	clear();
}

CBDD CBDD::operator*(const CBDD& other) const {
	DdNode *node = Cudd_bddAnd(CuddManager::manager, this->func, other.func);
	return CBDD(node);
}

CBDD CBDD::operator+(const CBDD& other) const {
	DdNode *node = Cudd_bddOr(CuddManager::manager, this->func, other.func);
	return CBDD(node);
}

CBDD CBDD::operator-() const {
	DdNode *node = Cudd_Not(this->func);
	return CBDD(node);
}
bool CBDD::isZero() const {
	if(Cudd_CountPathsToNonZero(this->func) == 0)
		return true;
	return false;
}

string CBDD::toString() const {
    return "CBDD";
}


void CBDD::setZero() {
	clear();
	func = CuddManager::zero();
	Cudd_Ref(func);
}

