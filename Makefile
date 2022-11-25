CC:=gcc
CFLAGSLIB:=-O2 -Wall -Werror -c
CFLAGSTEST:=-O2 -Wall -Werror -static
SRC:=src/slog.c
TESTDIR:=testing
TEST:=$(TESTDIR)/test.c
BUILDDIR:=build
BINDIR:=bin
LIBBINNAME:=slog.a
TESTBINNAME:=test
RELEASEDIR:=release

lib:
	$(CC) $(CFLAGSLIB) $(SRC) && \
	mkdir -p $(BUILDDIR) && \
	mv *.o $(BUILDDIR) && \
	mkdir -p $(BINDIR) && \
	ar rcs $(BINDIR)/$(LIBBINNAME) $(BUILDDIR)/*.o


test: lib
	$(CC) $(CFLAGSTEST) $(SRC) $(TEST) -o $(TESTDIR)/$(TESTBINNAME) && \
	cd $(TESTDIR) && \
	./$(TESTBINNAME)

clean:
	rm -rf $(TESTBINNAME) $(RELEASEDIR) $(BINDIR) $(BUILDDIR)