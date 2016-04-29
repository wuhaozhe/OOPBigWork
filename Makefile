all: temporary.exe

temporary.exe: temporary.o Database.o Single_Word.o
	g++ -o temporary.exe $^

temporary.o: temporary.cpp
	g++ -c $<

Database.o: Database.cpp
	g++ -c $<

Single_Word.o: Single_Word.cpp
	g++ -c $<
clean:
	del *.o *.exe