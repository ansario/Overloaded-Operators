/****************************************************************
 * Header file for the class to organize and test sets.
 *
 * Author/copyright:  Duncan Buell
 * Date: 18 July 2014
 *
**/

#ifndef SETCOLLECTIONTWO_H
#define SETCOLLECTIONTWO_H

#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "MySet.h"

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class SetCollection2
{
public:
  SetCollection2();
  virtual ~SetCollection2();

  void initialize(Scanner& scanner);
  void testSets(ofstream& outStream);
  string toString();

private:
  vector<MySet> myCollection;

};

#endif
