include ../config.make

FLAGS = -std=c++11

.PHONY: all
all: libdata.$(Extension)

libdata.$(Extension): $(OBJECTS)
	g++ -shared -fPIC -o $@ $^

%.o: %.cpp %.h
	g++ $(FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(RM) *.o libdata.$(Extension)