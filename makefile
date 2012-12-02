# Ficheros con codigo fuente
MAIN  = TestPolinomio.C 
SRCS  = polinomio.C monomio.C
INCS  = polinomio.h monomio.h
OBJS  = polinomio.o monomio.o TestPolinomio.o
EXEC  = polinomio
LIBS  =

# Compilador y opciones
#
CC      = g++
CFLAGS  = -c -ansi -pedantic -Wno-deprecated
CDEBUG  = -g -Wall

# Reglas
default : $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LIBS)

$(OBJS): $(MAIN) $(SRCS) $(INCS)
	$(CC) $(CFLAGS) $(CDEBUG) $(MAIN) $(SRCS)

clean:
	clear
	rm -f $(OBJS) $(EXEC) core*.* *~ .*.sw* *.out
