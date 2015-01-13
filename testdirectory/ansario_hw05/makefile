GPP = g++ -O3 -Wall -DVECTOR=VECTOR

UTILS = ../../Utilities

A = Main.o
C = SetCollection.o
M = MySet.o
O = Operators.o
S = Scanner.o
SL = ScanLine.o
U = Utils.o

Aprog: $A $C $M $O $S $(SL) $U
	$(GPP) -o Aprog $A $C $M $O $S $(SL) $U

Main.o: Main.h Main.cpp
	$(GPP) -c Main.cpp

SetCollection.o: SetCollection.h SetCollection.cpp
	$(GPP) -c SetCollection.cpp

Team.o: Team.h Team.cpp
	$(GPP) -c Team.cpp

Operators.o: Operators.cpp
	$(GPP) -c Operators.cpp

Scanner.o: $(UTILS)/Scanner.h $(UTILS)/Scanner.cpp
	$(GPP) -c $(UTILS)/Scanner.cpp

ScanLine.o: $(UTILS)/ScanLine.h $(UTILS)/ScanLine.cpp
	$(GPP) -c $(UTILS)/ScanLine.cpp

Utils.o: $(UTILS)/Utils.h $(UTILS)/Utils.cpp
	$(GPP) -c $(UTILS)/Utils.cpp
