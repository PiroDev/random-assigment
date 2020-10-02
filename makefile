COMPILER := g++
COMPILER_FLAGS := -std=c++17 -Wall -Werror -pedantic -Wextra
OBJDIR := out
OBJS := $(OBJDIR)/hashing.o $(OBJDIR)/input_output.o
SRCDIR := src
INCDIR := inc
RM := rm

ifeq ($(mode), debug)
	COMPILER_FLAGS += -g3
	COMPILER_FLAGS += -ggdb
endif

ifeq ($(mode), release)
	COMPILER_FLAGS += -DNDEBUG -g0
endif

assigment.exe : $(OBJS) $(OBJDIR)/main.o
	$(COMPILER) $(COMPILER_FLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(INCDIR)/*.h
	mkdir -p $(OBJDIR)
	$(COMPILER) $(COMPILER_FLAGS) -c $< -o $@

.PHONY : clean
clean :
	$(RM) -f *.exe
	$(RM) -f out/*.o