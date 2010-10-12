# Makefile for simple_dbms
EXEC    = simple_dbms
HEADER  = $(wildcard *.h) y.tab.hh
SRC     = $(filter-out $(HEADER) lex.yy.cc, $(wildcard *.cc)) lex.yy.cc

CFLAGS = -Wall -g
LFLAGS =

#-------------------------------------------------
# Lex & yacc options -----------------------------
#
LEX = lex
LEX_OPT = -i

YACC = yacc
YACC_OPT = -d -t --debug --locations -v


#-------------------------------------------------
# Compiler options -------------------------------

CC      = g++
CFLAGS += $(addprefix -I, $(INCLUDE))

OBJ = $(SRC:.cc=.o)


# Configure ------------------------------------------

all: $(EXEC)


# Build ------------------------------------------

%.o: %.cc
	$(CC)  $(CFLAGS) -c $< -o $@

%.d : %.cc y.tab.hh
	@$(CC) $(CFLAGS) -M $< > $@

-include $(patsubst %.cc, %.d, $(wildcard *.cc))

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LFLAGS)


#lex and yark build----------------------------

y.tab.hh : y.tab.cc

lex.yy.cc : lexer.l
	$(LEX) $(LEX_OPT) $<
	`mv lex.yy.c lex.yy.cc`

lex.yy.o : lex.yy.cc y.tab.hh
	$(CC) $(CFLAGS) -c $< -o $@

y.tab.cc : parser.y
	$(YACC) $(YACC_OPT) $< -o $@


# Clean ------------------------------------------

clean:
	-rm -vf *.o *.d $(EXEC) core # lex.yy.cc y.tab.cc y.tab.hh y.output

.PHONY: clean all

#------------------------------------------------
