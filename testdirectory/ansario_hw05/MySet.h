/****************************************************************
 * Header file for a single set.
 * This class wraps the built in 'vector' container.
 *
 * Author/copyright:  Duncan Buell edited by Omar Ansari.
 * Date: 21 October 2014
 *
**/

#ifndef MYSET_H
#define MYSET_H
#define VECTOR

#include <iostream>
#include <set>
using namespace std;

#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

class MySet
{
public:
  MySet();
  virtual ~MySet();

  bool add(string elt);
  bool containsElt(string elt) const;
  bool containsSet(MySet thatSet) const;
  bool equals(MySet thatSet) const;
  vector<string> getElts() const;
  bool isContainedInSet(MySet thatSet) const;
  bool remove(string elt);
  string toString() const;

  /////////////////////////////////////////////////////////////////
  // Overloaded 'friend' operators.
  friend ostream& operator <<(ostream& outputStream,
                              const MySet& mySet);
  friend bool operator <=(const MySet& setLeft, const MySet& setRight);
  friend bool operator >=(const MySet& setLeft, const MySet& setRight);
  friend bool operator ==(const MySet& setLeft, const MySet& setRight);

private:
  vector<string> theSet;

};

#endif

