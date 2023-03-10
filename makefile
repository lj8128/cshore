all: main.o startup.o repl.o ansi.o errors.o file_print_cmds.o file_nav_cmds.o file_create_cmds.o util.o pid_print_cmds.o bin_cmds.o
	gcc main.o startup.o repl.o ansi.o errors.o file_print_cmds.o file_nav_cmds.o file_create_cmds.o util.o pid_print_cmds.o bin_cmds.o -o cshore

main.o: main.c
	gcc -c main.c

startup.o: $(CURDIR)/src/startup.c
	gcc -c $(CURDIR)/src/startup.c

repl.o: $(CURDIR)/src/repl.c
	gcc -c $(CURDIR)/src/repl.c

ansi.o: $(CURDIR)/src/ansi.c
	gcc -c $(CURDIR)/src/ansi.c

errors.o: $(CURDIR)/src/errors.c 
	gcc -c $(CURDIR)/src/errors.c

file_print_cmds.o: $(CURDIR)/src/file_print_cmds.c 
	gcc -c $(CURDIR)/src/file_print_cmds.c 

file_nav_cmds.o: $(CURDIR)/src/file_nav_cmds.c 
	gcc -c $(CURDIR)/src/file_nav_cmds.c 

file_create_cmds.o: $(CURDIR)/src/file_create_cmds.c
	gcc -c $(CURDIR)/src/file_create_cmds.c

util.o: $(CURDIR)/src/util.c
	gcc -c $(CURDIR)/src/util.c

pid_print_cmds.o: $(CURDIR)/src/pid_print_cmds.c
	gcc -c $(CURDIR)/src/pid_print_cmds.c

bin_cmds.o: $(CURDIR)/src/bin_cmds.c
	gcc -c $(CURDIR)/src/bin_cmds.c

.PHONY: clean
clean:
	rm cshore *.o