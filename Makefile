include config.make

CC_FLAGS = -I./dylib_database -I./dylib_strategy -std=c++11
LD_FLAGS = -L./dylib_database -L./dylib_strategy
LD_LIBS = -lstrategy -ldata

.PHONY: all
all: libdata libstrategy main

main: main.o $(OBJECTS)
	g++ $(LD_FLAGS) -o $@ $^ $(LD_LIBS)
	$(CP) dylib_database$(SLASH)libdata.$(Extension) .
	$(CP) dylib_strategy$(SLASH)libstrategy.$(Extension) .
	-mkdir User

main.o: main.cpp $(HEADERS)
	g++ $(CC_FLAGS) -o $@ -c $<

%.o: %.cpp %.h
	g++ $(CC_FLAGS) -o $@ -c $<

libdata:
	cd dylib_database && make

libstrategy:
	cd dylib_strategy && make

.PHONY: clean
clean:
	$(RM) *.o main libdata.$(Extension) libstrategy.$(Extension)
	cd dylib_strategy && make clean
	cd dylib_database && make clean
