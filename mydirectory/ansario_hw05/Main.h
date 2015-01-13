/****************************************************************
 * Rather generic header file that includes the 'Utilities' code.
 *
 * Author/copyright:  Duncan Buell
 * Date: 18 July 2014
 *
**/
#ifndef MAIN_H
#define MAIN_H
#define VECTOR

#include <iostream>
#include <cmath>
using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

#include "SetCollection.h"
#include "SetCollection2.h"

class Main
{
public:
  int main();
  virtual ~Main();

private:

};

#endif // MAIN_H
