include ../config.make
LD_FLAG = -L../dylib_database
LD_LIB = -ldata
CC_FLAG = -I../dylib_database -std=c++11


.PHONY: all
all: libstrategy.$(Extension)

libstrategy.$(Extension): $(OBJECTS)
	g++ $(LD_FLAG) -shared -fPIC -o $@ $^ $(LD_LIB)

%.o: %.cpp %.h
	g++ $(CC_FLAG) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) *.o libstrategy.$(Extension)