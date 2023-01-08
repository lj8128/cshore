main: main.o startup.o
	gcc main.o startup.o -o cshore

main.o: main.c
	gcc -c main.c

startup.o: $(CURDIR)/src/startup.c
	gcc -c $(CURDIR)/src/startup.c

.PHONY: clean
clean:
	rm cshore *.o