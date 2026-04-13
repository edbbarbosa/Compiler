CXX := g++
SRCDIRS := src src/analysis src/compilerCompiler
BIN := compiler

SRCS := $(shell find $(SRCDIRS) -type f -name '*.cpp')
OBJS := $(SRCS:.cpp=.o)

.PHONY: all clean

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) -o $@ $^

%.o: %.cc
	$(CXX) -c $< -o $@

clean:
	rm -f $(OBJS) $(BIN)

    

