#handling
CC = g++
CFLAGS = -std=c++17

#directories
SRCDIR = src
INCDIR = inc
BUILDDIR = build

#headers
INCLUDES = $(wildcard $(INCDIR)/*.hpp)

#sources
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

#objects
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

#exe
EXECUTABLE = test

#default
all: $(BUILDDIR)/$(EXECUTABLE)

$(BUILDDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

#srctoobj
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	@mkdir -p $(BUILDDIR)
	$(CC) -c $(CFLAGS) $< -o $@

#cleaning
clean:
	rm -rf $(BUILDDIR)

run: $(BUILDDIR)/$(EXECUTABLE)
	./$(BUILDDIR)/$(EXECUTABLE) $(ARGS)

.PHONY: all clean run
