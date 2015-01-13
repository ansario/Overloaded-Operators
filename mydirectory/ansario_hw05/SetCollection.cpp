#include "SetCollection.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SetCollection' for organizing and testing sets.
 *
 * Author: Duncan A. Buell
 * Date last modified: 18 October 2014
**/

/******************************************************************************
 * Constructor
**/
SetCollection::SetCollection()
{
}

/******************************************************************************
 * Destructor
**/
SetCollection::~SetCollection()
{
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'initialize'.
 *
 * Parameters:
 *   scanner - the 'Scanner' from which to read
**/
void SetCollection::initialize(Scanner& scanner)
{
  string inputLine = "";

  ScanLine scanLine;
  MySet mySet;

#ifdef EBUG
  Utils::logStream << "enter initialize\n"; 
#endif

  // read the first line and split into tokens in a 'vector'
  while (scanner.hasNext())
  {
    inputLine = scanner.nextLine();
    scanLine.openString(inputLine);

    MySet localSet;
    while (scanLine.hasNext())
    {
      string elt = scanLine.next();
      localSet.add(elt);
    }
//    cout << "SET " << localSet.toString() << endl;
    this->myCollection.push_back(localSet);
  }

#ifdef EBUG
  vector<MySet>::iterator iter;
  for(iter = this->myCollection.begin();
          iter != this->myCollection.end(); ++iter)
  {
    cout << "INIT " << (*iter).toString() << "\n";
  }
  Utils::logStream << "leave initialize\n"; 
#endif
}

/******************************************************************************
 * Function 'testContainmentLocally'.
 * This function tests whether 'firstSet' contains 'secondSet' by getting
 * the elts from each and testing each elt.
 *
 * To a certain extent this code duplicates the code in the 'MySet' class.
 * On the other hand, if one were to assume that one programmer wrote the
 * the class and another wrote the testing code, then one might hope that
 * they did not make the same mistakes in the two different code modules.
**/
bool SetCollection::testContainmentLocally(MySet left, MySet right)
{
#ifdef EBUG
  Utils::logStream << "enter testContainmentLocally\n"; 
#endif

#ifdef SET
  set<string> leftElts = left.getElts();
  set<string> rightElts = right.getElts();
  set<string>::iterator iter;

  for(iter = rightElts.begin(); iter != rightElts.end(); ++iter)
  {
    set<string>::iterator eltPtrInLeft = leftElts.find(*iter);
    if(eltPtrInLeft == leftElts.end())
    {
      return false;
    }
  }
#endif

#ifdef VECTOR
  bool foundElt = false;
  vector<string> leftElts = left.getElts();
  vector<string> rightElts = right.getElts();
  vector<string>::iterator iterOuter;
  vector<string>::iterator iterInner;

  for(iterOuter = rightElts.begin();
      iterOuter != rightElts.end(); ++iterOuter)
  {
    string outerElt = *iterOuter;
    foundElt = false;
    for(iterInner = leftElts.begin();
        iterInner != leftElts.end(); ++iterInner)
    {
      string innerElt = *iterInner;
      if(innerElt == outerElt)
      {
        foundElt = true;
        break;
      }
    } 

    if(!foundElt)
    {
      return false;
    }
  } 
#endif

  // if we get through the loop we have never found the elts
  // of right not to be present in left 
  return true;

#ifdef EBUG
  Utils::logStream << "leave testContainmentLocally\n"; 
#endif
}

/******************************************************************************
 * Function 'testContainsEltLocally'.
 * This function tests whether 'firstSet' contains 'elt'.
 *
 * To a certain extent this code duplicates the code in the 'MySet' class.
 * On the other hand, if one were to assume that one programmer wrote the
 * the class and another wrote the testing code, then one might hope that
 * they did not make the same mistakes in the two different code modules.
**/
bool SetCollection::testContainsEltLocally(MySet theSet, string elt)
{
  bool returnValue = true;
#ifdef EBUG
  Utils::logStream << "enter testContainsEltLocally\n"; 
#endif

#ifdef SET
  set<string> theElts = theSet.getElts();

  set<string>::iterator eltPtrInSet = theElts.find(elt);

  if(eltPtrInSet == theElts.end())
  {
    returnValue = false;
  }

  return returnValue;
#endif

#ifdef VECTOR
  vector<string> theElts = theSet.getElts();

  vector<string>::iterator iter;

  for(iter = theElts.begin(); iter != theElts.end(); ++iter)
  {
    if(*iter == elt)
    {
      returnValue = true;
      break;
    }
  }

  return returnValue;
#endif

#ifdef EBUG
  Utils::logStream << "leave testContainsEltLocally\n"; 
#endif
}

/******************************************************************************
 * Function 'testEqualsLocally'.
 * This function tests whether 'firstSet' equals 'secondSet' by getting
 * the elts from each and testing each elt.
 *
 * To a certain extent this code duplicates the code in the 'MySet' class.
 * On the other hand, if one were to assume that one programmer wrote the
 * the class and another wrote the testing code, then one might hope that
 * they did not make the same mistakes in the two different code modules.
**/
bool SetCollection::testEqualsLocally(MySet left, MySet right)
{
#ifdef EBUG
  Utils::logStream << "enter testEqualsLocally\n"; 
#endif

#ifdef SET
  set<string>::iterator iter;
  set<string> leftElts = left.getElts();
  set<string> rightElts = right.getElts();

  // test that each elt in right is also in left
  for(iter = rightElts.begin(); iter != rightElts.end(); ++iter)
  {
    set<string>::iterator eltPtrInLeft = leftElts.find(*iter);
    if(eltPtrInLeft == leftElts.end())
    {
      return false;
    }
  }

  // test that each elt in left is also in right
  for(iter = leftElts.begin(); iter != leftElts.end(); ++iter)
  {
    set<string>::iterator eltPtrInRight = rightElts.find(*iter);
    if(eltPtrInRight == rightElts.end())
    {
      return false;
    }
  }

  // if we get through the loop we have never found the elts
  // of right not to be present in left 
  return true;
#endif

#ifdef VECTOR
  return this->testContainmentLocally(left, right) &&
         this->testIsContainedInLocally(left, right);
#endif

#ifdef EBUG
  Utils::logStream << "leave testEqualsLocally\n"; 
#endif
}

/******************************************************************************
 * Function 'testIsContainedInLocally'.
 * This function tests whether 'firstSet' is contained in 'secondSet' by
 * getting the elts from each and testing each elt.
 *
 * To a certain extent this code duplicates the code in the 'MySet' class.
 * On the other hand, if one were to assume that one programmer wrote the
 * the class and another wrote the testing code, then one might hope that
 * they did not make the same mistakes in the two different code modules.
**/
bool SetCollection::testIsContainedInLocally(MySet left, MySet right)
{
#ifdef EBUG
  Utils::logStream << "enter testIsContainedInLocally\n"; 
#endif

#ifdef SET
  set<string> leftElts = left.getElts();
  set<string> rightElts = right.getElts();

  set<string>::iterator iter;
  for(iter = leftElts.begin(); iter != leftElts.end(); ++iter)
  {
    set<string>::iterator eltPtrInRight = rightElts.find(*iter);
    if(eltPtrInRight == rightElts.end())
    {
      return false;
    }
  }

  // if we get through the loop we have never found the elts
  // of right not to be present in left 
  return true;
#endif

#ifdef VECTOR
  bool foundElt = false;
  vector<string> leftElts = left.getElts();
  vector<string> rightElts = right.getElts();
  vector<string>::iterator iterOuter;
  vector<string>::iterator iterInner;

  for(iterOuter = leftElts.begin();
      iterOuter != leftElts.end(); ++iterOuter)
  {
    string outerElt = *iterOuter;
    foundElt = false;
    for(iterInner = rightElts.begin();
        iterInner != rightElts.end(); ++iterInner)
    {
      string innerElt = *iterInner;
      if(innerElt == outerElt)
      {
        foundElt = true;
        break;
      }
    } 

    if(!foundElt)
    {
      return false;
    }
  } 
#endif

  return true;
#ifdef EBUG
  Utils::logStream << "leave testIsContainedInLocally\n"; 
#endif
}

/******************************************************************************
 * Function 'testSets'.
 * This function tests the set functions in the 'MySet' class.
**/
void SetCollection::testSets(ofstream& outStream)
{
  bool testFunction = false;
  bool testLocally = false;
  bool testOverload = false;

#ifdef EBUG
  Utils::logStream << "enter testSets\n"; 
#endif

  outStream << "Sets are\n" << this->toString() << endl;;

  // test set containment
  // test whether the outer loop set contains the inner loop set
  outStream << "\nTest set containment\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 24, "left");
      outStream << " contains? ";
      outStream << Utils::Format(secondSet.toString(), 24, "left");

      // use the function in the class
      // use the overload
      // use the test function in this class
      // then compare the three booleans to make sure they agree
      testFunction = firstSet.containsSet(secondSet);
      testOverload = firstSet >= secondSet;
      testLocally = this->testContainmentLocally(firstSet, secondSet);
      outStream << this->toStringTrueFalse(testFunction);
      outStream << this->toStringTrueFalse(testOverload);
      outStream << this->toStringTrueFalse(testLocally);
      outStream << endl;

      // compare the class function with the overloading
      if (testFunction != (testOverload))
      {
        outStream << "\nZORK ERROR function not overload\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
      // compare the class function with the local function
      if (testFunction != (testLocally))
      {
        outStream << "\nZORK ERROR function not locally\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test set containment

  // test set is contained in
  // test whether the outer loop set is contained in the inner loop set
  testFunction = false;
  testLocally = false;
  testOverload = false;
  outStream << "\nTest set is contained in\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 24, "left");
      outStream << " is cont in? ";
      outStream << Utils::Format(secondSet.toString(), 24, "left");

      // use the function in the class
      // use the overload
      // use the test function in this class
      // then compare the three booleans to make sure they agree
      testFunction = firstSet.isContainedInSet(secondSet);
      testOverload = firstSet <= secondSet;
      testLocally = this->testIsContainedInLocally(firstSet, secondSet);
      outStream << this->toStringTrueFalse(testFunction);
      outStream << this->toStringTrueFalse(testOverload);
      outStream << this->toStringTrueFalse(testLocally);
      outStream << endl;

      // compare the class function with the overloading
      if ( testFunction != (testOverload))
      {
        outStream << "\nZORK ERROR function not overload\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
      // compare the class function with the local function
      if ( testFunction != (testLocally))
      {
        outStream << "\nZORK ERROR function not locally\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test set is contained in set

  // test set equality
  // test whether the outer loop set equals the inner loop set
  testFunction = false;
  testLocally = false;
  testOverload = false;
  outStream << "\nTest set equality\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 24, "left");
      outStream << " equals? ";
      outStream << Utils::Format(secondSet.toString(), 24, "left");

      // use the function in the class
      // use the overload
      // use the test function in this class
      // then compare the three booleans to make sure they agree
      testFunction = firstSet.equals(secondSet);
      testOverload = firstSet == secondSet;
      testLocally = this->testEqualsLocally(firstSet, secondSet);
      outStream << this->toStringTrueFalse(testFunction);
      outStream << this->toStringTrueFalse(testOverload);
      outStream << this->toStringTrueFalse(testLocally);
      outStream << endl;

      // compare the class function with the overloading
      if ( testFunction != (testOverload))
      {
        outStream << "\nZORK ERROR function not overload\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
      // compare the class function with the local function
      if ( testFunction != (testLocally))
      {
        outStream << "\nZORK ERROR function not locally\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test set equals amother set

  // test set equality for empty sets
  MySet firstSet = MySet();
  MySet secondSet = MySet();
  outStream << "\n";
  outStream << Utils::Format(firstSet.toString(), 24, "left");
  outStream << " empty equals? ";
  outStream << Utils::Format(secondSet.toString(), 24, "left");
  testFunction = firstSet.equals(secondSet);
  testOverload = firstSet == secondSet;
  testLocally = this->testEqualsLocally(firstSet, secondSet);
  outStream << this->toStringTrueFalse(testFunction);
  outStream << this->toStringTrueFalse(testOverload);
  outStream << this->toStringTrueFalse(testLocally);
  outStream << endl;

  // test element containment
  // note that we have to have a function to return a 'set<string>'
  // or a 'vector<string>' so we can iterate over elements
  testFunction = false;
  testLocally = false;
//  testOverload = false;
  outStream << "Test element containment\n" << endl;
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
#ifdef SET
    set<string> firstSetElts = firstSet.getElts();
    for (set<string>::iterator iter = firstSetElts.begin();
                               iter != firstSetElts.end(); ++iter)
#endif
#ifdef VECTOR
    vector<string> firstSetElts = firstSet.getElts();
    for (vector<string>::iterator iter = firstSetElts.begin();
                                  iter != firstSetElts.end(); ++iter)
#endif
    {
      string thatElt = (*iter);
      outStream << Utils::Format(firstSet.toString(), 24, "left");
      outStream << " containsElt? ";
      outStream << Utils::Format(thatElt, 5, "left");

      // use the function in the class
      // use the overload
      // use the test function in this class
      // then compare the three booleans to make sure they agree
      testFunction = firstSet.containsElt(thatElt);
      testLocally = this->testContainsEltLocally(firstSet, thatElt);
      outStream << this->toStringTrueFalse(testFunction);
      outStream << this->toStringTrueFalse(testOverload);
      outStream << this->toStringTrueFalse(testLocally);
      outStream << endl;

      // compare the class function with the local function
      if ( testFunction != (testLocally))
      {
        outStream << "\nZORK ERROR function not locally\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test element containment

  // test element remove and add
  // note that we have to have a function to return a 'set<string>'
  // or a 'vector<string>' so we can iterate over elements
  //
  // we are going to remove elts one at a time until there is nothing 
  // more to remove
  bool testBefore = false;
  bool testAfter = false;
  bool testAfterAfter = false;
//  testOverload = false;
  outStream << "Test element remove and add\n" << endl;
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
#ifdef SET
    set<string> firstSetElts = firstSet.getElts();
    for (set<string>::iterator iter = firstSetElts.begin();
                               iter != firstSetElts.end(); ++iter)
#endif
#ifdef VECTOR
    vector<string> firstSetElts = firstSet.getElts();
    for (vector<string>::iterator iter = firstSetElts.begin();
                                  iter != firstSetElts.end(); ++iter)
#endif
    {
      string thatElt = (*iter);
      outStream << Utils::Format(firstSet.toString(), 24, "left");
      outStream << " removeAddElt ";
      outStream << Utils::Format(thatElt, 5, "left");

      // test presence before
      // remove the elt
      // test presence after
      // add the elt
      // test presence after after
      testBefore = firstSet.containsElt(thatElt);
      firstSet.remove(thatElt);
      testAfter = firstSet.containsElt(thatElt);
      firstSet.add(thatElt);
      testAfterAfter = firstSet.containsElt(thatElt);
      outStream << this->toStringTrueFalse(testBefore);
      outStream << this->toStringTrueFalse(!testAfter);
      outStream << this->toStringTrueFalse(testAfterAfter);
      outStream << endl;

      // compare the before and the after
      if ( testBefore != (!testAfter))
      {
        outStream << "\nZORK ERROR remove fails\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
      // compare the after and the afterafter
      if ( testAfter != (!testAfterAfter))
      {
        outStream << "\nZORK ERROR add fails\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test remove and add

#ifdef EBUG
  Utils::logStream << "leave testSets\n"; 
#endif
}

/******************************************************************************
 * Function 'toString'.
 * This function dumps the 'vector' of data to a 'string' and returns it.
**/
string SetCollection::toString()
{
#ifdef EBUG
  Utils::logStream << "enter toString\n"; 
#endif

  string s = "\n";

  vector<MySet>::iterator iter;
  for(iter = this->myCollection.begin();
         iter != this->myCollection.end(); ++iter)
  {
    s += (*iter).toString();
    s += "\n";
  }

#ifdef EBUG
  Utils::logStream << "leave toString\n"; 
#endif
  return s;
}
/******************************************************************************
 * Function 'toStringTrueFalse'.
 * This function formats the boolean argument in fixed width string.
**/
string SetCollection::toStringTrueFalse(bool what)
{
  string s = " false";

  if(what)
  {
    s = " true ";
  }

  return s;
}
