main: main.o startup.o repl.o ansi.o
	gcc main.o startup.o repl.o ansi.o -o cshore

main.o: main.c
	gcc -c main.c

startup.o: $(CURDIR)/src/startup.c
	gcc -c $(CURDIR)/src/startup.c

repl.o: $(CURDIR)/src/repl.c
	gcc -c $(CURDIR)/src/repl.c

ansi.o: $(CURDIR)/src/ansi.c
	gcc -c $(CURDIR)/src/ansi.c

.PHONY: clean
clean:
	rm cshore *.o