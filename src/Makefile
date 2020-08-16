# *****************************************************
# Variables to control Makefile operation

CXX = g++
CXXFLAGS = -Wall -g

# ****************************************************
# Targets needed to bring the executable up to date

all: server

server: server.o clear.o cross.o distinct.o index.o join.o list.o load.o print.o projection.o rename.o selection.o sort.o executor.o semanticParser.o syntacticParser.o tableCatalogue.o table.o cursor.o bufferManager.o page.o logger.o
	$(CXX) $(CXXFLAGS) -o server server.o clear.o cross.o distinct.o index.o join.o list.o load.o print.o projection.o rename.o selection.o sort.o executor.o semanticParser.o syntacticParser.o tableCatalogue.o table.o cursor.o bufferManager.o page.o logger.o

clean:
	rm -f *.o *~

server.o: server.cpp global.h

clear.o: clear.cpp global.h

cross.o: cross.cpp global.h

distinct.o: distinct.cpp global.h

index.o: index.cpp global.h

join.o: join.cpp global.h

list.o: list.cpp global.h

load.o: load.cpp global.h

print.o: print.cpp global.h

projection.o: projection.cpp global.h

rename.o: rename.cpp global.h

selection.o: selection.cpp global.h

sort.o: sort.cpp global.h

executor.o: executor.cpp global.h

semanticParser.o: semanticParser.cpp global.h

syntacticParser.o: syntacticParser.cpp global.h

tableCatalogue.o: tableCatalogue.cpp global.h

table.o: table.cpp global.h

cursor.o: cursor.cpp global.h

bufferManager.o: bufferManager.cpp global.h

page.o: page.cpp global.h

logger.o: logger.cpp global.h


