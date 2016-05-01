CPPFLAG = -std=c++11

all: temporary.exe

temporary.exe: temporary.o Database.o Single_Word.o User.o Memory_Strategy.o
	g++ -o temporary.exe $^ $(CPPFLAG)

temporary.o: temporary.cpp
	g++ -c $< $(CPPFLAG)

Database.o: Database.cpp
	g++ -c $< $(CPPFLAG)

Single_Word.o: Single_Word.cpp
	g++ -c $< $(CPPFLAG)

User.o: User.cpp
	g++ -c $< $(CPPFLAG)

Memory_Strategy.o: Memory_Strategy.cpp
	g++ -c $< $(CPPFLAG)

clean:
	del *.o *.exe