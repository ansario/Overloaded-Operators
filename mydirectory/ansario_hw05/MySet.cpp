#include "MySet.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'MySet' for the edit distance computation.
 *
 * Author: Duncan A. Buell modified by Omar A. Ansari
 * Date last modified: 21 October 2014
 *
 * This class contains all of the functions needed to emulate a typical set. It 
 * uses a vector<string> as the internal data structure.
**/

/******************************************************************************
 * Constructor
**/
MySet::MySet()
{
}

/******************************************************************************
 * Destructor
**/
MySet::~MySet()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function to add an element.
 *
 * This function works similarly to the add function in Java, however internally
 * uses push_back(string) to add the specified element to the vector<string>.
 *
 * parameter -- string elt; Element to be added to the internal vector<string>
 * returns -- true; Returns true after adding element to the internal vector.
 *
**/
bool MySet::add(string elt)
{
	theSet.push_back(elt);
	return true;
}

/******************************************************************************
 * Function to test if "this" set contains "that" element.
 *
 * This function quite simply, runs through every element in the internal 
 * vector<string> and if the element at the ith index matches the passed
 * parameter, return true.
 *
 * parameter -- string thatElt; Element to be checked against all the elements 
 * in the internal vector<string>
 * returns -- true or false dependent on if thatElt appears in the internal 
 * vector<string>.
**/
bool MySet::containsElt(string thatElt) const
{
	bool returnValue = false;

	for (int i = 0; i < theSet.size(); ++i)
	{
		if ((theSet[i]) == (thatElt)) //Check if ith element equals parameter.
		{
			returnValue = true;
		}
	}

	return returnValue;
}

/******************************************************************************
 * Function to test if "this" set contains "that" set.
 * 
 * Similar to the containsElt function, this function checks if all the elements
 * in thatSet appear in the internal vector<string>. If all elements appear, 
 * return true. If at least one element does not appear in the internal 
 * vector<string>, return false.
 *
 * parameter -- MySet thatSet; Set to be checked if contained in this Set.
 * returns -- true or false dependent on if all elements in thatSet appear in 
 * internal vector<string>.
**/
bool MySet::containsSet(MySet thatSet) const
{
	bool returnValue = true;
	//Create tempElts vector containing thatSet elements.
	vector<string> tempElts = thatSet.getElts(); 

	for (int i = 0; i < tempElts.size(); ++i)
	{
		if (containsElt(tempElts[i]))
		{
			continue;
		} else
		{
			returnValue = false;
		}

	}

	return returnValue;
}

/******************************************************************************
 * Function to test if "this" set equals "that" set.
 * 
 * This function compares the size of the storage structure of thatSet and the 
 * internal vector<string>. If they are the same, and all the elements in 
 * thatSet are contained in this internal structure, return true, else, return
 * false.
 *
 * parameter -- MySet thatSet; Set to be checked if equals to thisSet.
 * returns -- true or false if the two sets are the same size and all the eleme
 * elements in thatSet are contained in thisSet.
**/
bool MySet::equals(MySet thatSet) const
{
	bool returnValue;
	//Create tempElts vector containing thatSet elements.
	vector<string> tempElts = thatSet.getElts();

	//Check if theSet contains thatSet and they are the same size.
	if (containsSet(thatSet) && (theSet.size() == tempElts.size()))
	{
		returnValue = true;
	} else 
	{
		returnValue = false;
	}

	return returnValue;
}

/******************************************************************************
 * Function to return a 'vector<string>' of the elements.
 *
 * returns theSet; This is the local internal storage structure used by the 
 * MySet class.
**/
vector<string> MySet::getElts() const
{
	return theSet;
}

/******************************************************************************
 * Function to test if "this" set is contained in "that" set.
 *
 * This function is similar to containsSet but checks the opposite. It checks
 * if thisSet is contained in thatSet. It requires the use of a local set which
 * contains all of the internal elements to this class. It then calls containSet
 * to determine if thatSet contains the temporary Set we have created with the 
 * internal elements of vector<string>.
 *
 * parameter -- MySet thatSet; Check if local set is contained in thatSet.
 * returns -- true or false; Dependent on if thatSet contains the local set.
 *
**/
bool MySet::isContainedInSet(MySet thatSet) const
{
	//Create temporary Set with the elements of the local storage vector.
	MySet testSet;

	for (int i = 0; i < theSet.size(); ++i)
	{
		testSet.add(theSet[i]);
	}


	if (thatSet.containsSet(testSet))
	{
		return true;
	} else
	{
		return false;
	}
}

/******************************************************************************
 * Function to remove elements from the Set.
 *
 * This function removes the specified element from the local storage structure.
 * It loops through the whole structure, and if the element at the ith position 
 * matches the passed parameter, swap the element to the end of the structure and
 * pop_back.
 *
 * parameter -- string elt; Element to be removed from local structure.
 * returns -- true or false; Dependent on if thatSet contains the local set.
 *
**/

bool MySet::remove(string elt)
{
	if (containsElt(elt))
	{
		for (int i = 0; i < theSet.size(); ++i)
		{
			if (theSet[i] == elt)
			{
				//Swap element at ith position to the end of the vector.
				swap(theSet[i], theSet.back());
				theSet.pop_back();
			}
		}
		
	} else {
		return false;
	}
}

/******************************************************************************
 * Function 'toString'.
 * This function dumps the set to a 'string' and returns it.
**/
string MySet::toString() const
{
  string s = "[";

  vector<string>::const_iterator iter;
  for (iter = this->theSet.begin(); iter != this->theSet.end(); ++iter)
  {
    s += " " + (*iter);
  }
  s += " ]";

  return s;
}
