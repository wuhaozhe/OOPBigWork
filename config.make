LS = ls
RM = rm -f
CP = cp
SLASH = /

ifeq ($(shell uname),Linux)
	Extension = so
else

ifeq ($(shell uname),Darwin)
	Extension = dylib
else
	LS = dir /b
	RM = del /f
	CP = copy
	SLASH = \\
	Extension = dll
endif

endif

SOURCES := $(shell $(LS) *.cpp)
HEADERS := $(shell $(LS) *.h *.cpp)
OBJECTS := $(patsubst %.cpp, %.o, $(SOURCES))