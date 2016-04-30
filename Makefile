CPPFLAG = -std=c++11 -Wall

all: temporary.exe

temporary.exe: temporary.o Database.o Single_Word.o User.o Console.o NewWords_Strategy.o NewWords_Strategy1.o Test_Strategy.o Test_Strategy_Multi.o Test_Strategy_TF.o Memory_Strategy.o Memory_Strategy_Shanbay.o Memory_Strategy_Towords.o
	g++ -o temporary.exe $^ $(CPPFLAG)

temporary.o: temporary.cpp
	g++ -c $< $(CPPFLAG)

Database.o: Database.cpp
	g++ -c $< $(CPPFLAG)

Single_Word.o: Single_Word.cpp
	g++ -c $< $(CPPFLAG)

User.o: User.cpp
	g++ -c $< $(CPPFLAG)

Console.o: Console.cpp
	g++ -c $< $(CPPFLAG)

NewWords_Strategy.o: NewWords_Strategy.cpp
	g++ -c $< $(CPPFLAG)

NewWords_Strategy1.o: NewWords_Strategy1.cpp
	g++ -c $< $(CPPFLAG)

Test_Strategy.o: Test_Strategy.cpp
	g++ -c $< $(CPPFLAG)

Test_Strategy_Multi.o: Test_Strategy_Multi.cpp
	g++ -c $< $(CPPFLAG)

Test_Strategy_TF.o: Test_Strategy_TF.cpp
	g++ -c $< $(CPPFLAG)

Memory_Strategy.o: Memory_Strategy.cpp
	g++ -c $< $(CPPFLAG)

Memory_Strategy_Shanbay.o: Memory_Strategy_Shanbay.cpp
	g++ -c $< $(CPPFLAG)

Memory_Strategy_Towords.o: Memory_Strategy_Towords.cpp
	g++ -c $< $(CPPFLAG)
clean:
	del *.o *.exe