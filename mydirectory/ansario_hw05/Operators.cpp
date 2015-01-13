#include "MySet.h"
/****************************************************************
 * This class contains the overloaded methods used in SetCollection
 *
 * Author: Omar Ansari
 * Date: October 21, 2014
**/
/****************************************************************
 * Overloaded '<' operator, not a 'MySet' member function.
 * This set is contained in that set.
**/
bool operator <=(const MySet& setLeft, const MySet& setRight)
{
	if (setRight.containsSet(setLeft))
	{
		return true;
	} else 
	{
		return false;
	}
}

/****************************************************************
 * Overloaded '>' operator, not a 'MySet' member function.
 * That set is contained in this set.
**/
bool operator >=(const MySet& setLeft, const MySet& setRight)
{
	if (setLeft.containsSet(setRight))
	{
		return true;
	} else
	{
		return false;
	}
}

/****************************************************************
 * Overloaded '==' operator, not a 'MySet' member function.
 * That set is equal to that set.
**/
bool operator ==(const MySet& setLeft, const MySet& setRight)
{
	if (setLeft.equals(setRight))
	{
		return true;
	} else
	{
		return false;
	}
}
/****************************************************************
 * Overloaded '<<' operator, not a 'MySet' member function.
 * toString.
**/
ostream& operator <<(ostream& outputStream, const MySet& mySet)
{
	outputStream << mySet.toString();
	return outputStream;
}
