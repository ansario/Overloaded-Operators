/****************************************************************
 * Header file for the class to organize and test sets.
 *
 * Author/copyright:  Duncan Buell
 * Date: 18 July 2014
 *
**/

#ifndef SETCOLLECTION_H
#define SETCOLLECTION_H
#define VECTOR

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "MySet.h"

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class SetCollection
{
public:
  SetCollection();
  virtual ~SetCollection();

  void initialize(Scanner& scanner);
  bool testContainsEltLocally(MySet left, string elt);
  bool testContainmentLocally(MySet left, MySet right);
  bool testEqualsLocally(MySet left, MySet right);
  bool testIsContainedInLocally(MySet left, MySet right);
  void testSets(ofstream& outStream);
  string toString();
  string toStringTrueFalse(bool what);

private:
  vector<MySet> myCollection;

};

#endif
