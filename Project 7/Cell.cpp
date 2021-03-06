//
//  Cell.cpp
//  SudokuGame
//
//  Created by Howard Stahl on 11/5/17.
//  Copyright � 2017 Howard Stahl. All rights reserved.
//

#include "Cell.h"

#include <iostream>

namespace cs31
{
	// default Cell constructor
	// since it has no arguments, we can declare an array of Cell's
	Cell::Cell()
	{
		mValue = 0;
		mImmutable = false;
	}

	// mutator method for the member mValue
	void Cell::setValue(int value)
	{
		mValue = value;
	}

	// stringify this Cell, turning 0's into    .
	std::string Cell::stringify() const
	{
		std::string s;
		if (mValue == 0)
		{
			s = ".";
		}
		else
		{
			s = s + std::to_string(mValue);
		}
		return(s);
	}
	
	bool Cell::isValueOK(int thisvalue, NumberSet box, NumberSet row, NumberSet column) const // to check the value entered is okay
	{
		// for now...
		bool result = false;				//sets the isValue to false to have a value to hold the result
		if (thisvalue == 0)					//if the cell is empty or a 0 the value is okey
		{
			result = true;
		}
		else if (box.notFound(thisvalue) && row.notFound(thisvalue) && column.notFound(thisvalue))		//if the value passed is the only one found in the box, row, or column return a true value
		{
			result = true;
		}
		return(result);
	}

	// called before the Board attempts to change a cell's value
	// when true, the Board will change the cell's value to thisvalue
	bool Cell::isOKToSetValue(int thisvalue, NumberSet box, NumberSet row, NumberSet column) const
	{
		// thisvalue cannot be found any of the NumberSets passed here
		bool result = isValueOK(thisvalue, box, row, column);
		// in addition, this cell must not be immutable
		if (mImmutable)
		{
			result = false;
		}
		return(result);
	}

	// accessor method for member mValue
	int Cell::getValue() const
	{
		return(mValue);
	}

	// this function returns if we are able to change the cell or not
	bool Cell::isImmutable() const								
	{

		return(mImmutable);
	}

	// mutator method for member mImmutable
	void Cell::setImmutable(bool i)
	{
		mImmutable = i;
	}

}
