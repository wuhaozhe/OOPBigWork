CPPFLAG = -std=c++11 -Wall

all: temporary.exe

temporary.exe: temporary.o Database.o Single_Word.o User.o
	g++ -o temporary.exe $^ $(CPPFLAG)

temporary.o: temporary.cpp
	g++ -c $< $(CPPFLAG)

Database.o: Database.cpp
	g++ -c $< $(CPPFLAG)

Single_Word.o: Single_Word.cpp
	g++ -c $< $(CPPFLAG)

User.o: User.cpp
	g++ -c $< $(CPPFLAG)

clean:
	del *.o *.exe