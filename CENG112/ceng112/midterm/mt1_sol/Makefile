CC:=gcc
CFLAGS:=-Wall -g -std=c99

targets = q1a q1b q2 q3a q3b q4b q5i q5r
all: $(targets)

q1a: q1a.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q1b: q1b.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q2: q2.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q3a: q3a.o queue.o queue.h Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q3b: q3b.o queue.o queue.h Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q4b: q4b.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q5i: q5i.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

q5r: q5r.o Makefile
	$(CC) $(CFLAGS) $(filter %.o,$^) -o $@

clean:
	@rm *.o *~ $(targets) -f
