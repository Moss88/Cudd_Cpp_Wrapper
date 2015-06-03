/*
 * CBDD.h
 *
 *  Created on: Jan 7, 2015
 *      Author: lpierce
 */

#include "CuddManager.h"

class CBDD : public SymbolicVar {
	public:
	CBDD();
	CBDD(DdNode *);
	~CBDD();
	CBDD& operator=(const CBDD& other);
	CBDD operator+(const CBDD& other) const;
	CBDD operator*(const CBDD& other) const;
	CBDD operator-() const;
    bool isZero() const;
    void setZero();
    virtual string toString() const;

    // Data Members
	DdNode *func;


	protected:
    void clear();



};






