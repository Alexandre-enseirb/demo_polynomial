CC=g++
CFLAGS=-Wall -g -O0
EXEC=build/bin
BINDIR=build
OBJDIR=.obj
INCDIR=include
SRCDIR=src
MKDIR_P := mkdir -p
OBJFILES := main.o polynomial.o
OBJS := $(OBJFILES:%=$(OBJDIR)/%) 

all: $(EXEC)

directories: $(BINDIR) $(OBJDIR)

$(BINDIR):
	${MKDIR_P} $(BINDIR)

$(OBJDIR):
	${MKDIR_P} $(OBJDIR)

$(EXEC): $(BINDIR) $(OBJDIR) $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) -I$(INCDIR)
	

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | directories
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCDIR)


clean:
	@rm -rf $(BINDIR)
	@rm -rf $(OBJDIR)
	@rm -f build/bin
