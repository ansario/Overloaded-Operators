#include "SetCollection2.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'SetCollection2' for organizing and testing sets.
 *
 * Author: Duncan A. Buell
 * Date last modified: 18 July 2014
**/

/******************************************************************************
 * Constructor
**/
SetCollection2::SetCollection2()
{
}

/******************************************************************************
 * Destructor
**/
SetCollection2::~SetCollection2()
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
void SetCollection2::initialize(Scanner& scanner)
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
  vector<set<string> >::iterator iter;
  for(iter = this->myCollection.begin();
          iter != this->myCollection.end(); ++iter)
  {
    cout << "INIT " << (iter->second).toString() << "\n";
  }
  Utils::logStream << "leave initialize\n"; 
#endif
}

/******************************************************************************
 * Function 'testSets'.
 * This function tests the set functions in the 'MySet' class.
**/
void SetCollection2::testSets(ofstream& outStream)
{
#ifdef EBUG
  Utils::logStream << "enter testSets\n"; 
#endif

  outStream << "Sets are\n" << this->toString() << endl;;

  // test set equality
  // test whether the inner loop set is equal to the outer loop set
  outStream << "\nTest set equality\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 20, "left");
      outStream << " equals? ";
      outStream << Utils::Format(secondSet.toString(), 20, "left");
      if (firstSet.equals(secondSet))
      {
        outStream << " true\n";
      }
      else
      {
        outStream << " false\n";
      }
    }
  } // end of test set equality

  // test set equality using overloading
  outStream << "\nTest set equality with overloading\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 20, "left");
      outStream << " ==? ";
      outStream << Utils::Format(secondSet.toString(), 20, "left");
      if (firstSet == secondSet)
      {
        outStream << " true\n";
      }
      else
      {
        outStream << " false\n";
      }
      if ( (firstSet == secondSet) != (firstSet.equals(secondSet)) )
      {
        outStream << "\nZORK ERROR\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test set equality with overloading

  // now we are going to hard code a kluge, but this is testing code
  // so kluges are more acceptable
  MySet setMunge = this->myCollection[0];
  setMunge.remove("a");
  this->myCollection[0] = setMunge;

  setMunge = this->myCollection[2];
  setMunge.remove("a");
  setMunge.remove("f");
  setMunge.remove("g");
  this->myCollection[2] = setMunge;

  // test set equality using overloading
  outStream << "\nTest set equality with overloading\n";
  for(int i = 0; i < this->myCollection.size(); ++i)
  {
    MySet firstSet = this->myCollection[i];
    for(int j = 0; j < this->myCollection.size(); ++j)
    {
      MySet secondSet = this->myCollection[j];
      outStream << Utils::Format(firstSet.toString(), 20, "left");
      outStream << " ==? ";
      outStream << Utils::Format(secondSet.toString(), 20, "left");
      if (firstSet == secondSet)
      {
        outStream << " true\n";
      }
      else
      {
        outStream << " false\n";
      }
      if ( (firstSet == secondSet) != (firstSet.equals(secondSet)) )
      {
        outStream << "\nZORK ERROR\n";
        outStream.flush();
        outStream.close();
        exit(1);
      }
    }
  } // end of test set equality with overloading

#ifdef EBUG
  Utils::logStream << "leave testSets\n"; 
#endif
}

/******************************************************************************
 * Function 'toString'.
 * This function dumps the 'vector' of data to a 'string' and returns it.
**/
string SetCollection2::toString()
{
#ifdef EBUG
  Utils::logStream << "enter toString\n"; 
#endif

  string s = "";

  vector<MySet>::iterator iter;
  for(iter = this->myCollection.begin();
         iter != this->myCollection.end(); ++iter)
  {
    s += (*iter).toString();
  }

#ifdef EBUG
  Utils::logStream << "leave toString\n"; 
#endif
  return s;
}
