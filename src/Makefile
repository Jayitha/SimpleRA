# Makefile for Writing Make Files Example

# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

server: server.o clear.o cross.o distinct.o index.o list.o load.o print.o projection.o rename.o selection.o sort.o executor.o semanticParser.o syntacticParser.o table.o column.o
	$(CXX) $(CXXFLAGS) -o server server.o clear.o cross.o distinct.o index.o list.o load.o print.o projection.o rename.o selection.o sort.o executor.o semanticParser.o syntacticParser.o table.o column.o

clean:
	rm -f *.o *~ 

server.o: server.cpp executor.h

clear.o: clear.cpp executor.h

cross.o: cross.cpp executor.h

distinct.o: distinct.cpp executor.h

index.o: index.cpp executor.h

list.o: list.cpp executor.h

load.o: load.cpp executor.h

print.o: print.cpp executor.h

projection.o: projection.cpp executor.h

rename.o: rename.cpp executor.h

selection.o: selection.cpp executor.h

sort.o: sort.cpp executor.h

executor.o: executor.cpp executor.h semanticParser.h

semanticParser.o: semanticParser.cpp semanticParser.h syntacticParser.h

syntacticParser.o: syntacticParser.cpp syntacticParser.h table.h

table.o: table.cpp table.h column.h

column.o: column.cpp column.h
