nums:		nums.o
		g++ -o nums nums.o        

seq-test:	seq-test.o command.o
		g++ -o seq-test command.o seq-test.o

seq-test.o:	seq-test.cc seq.hh
		g++ -c seq-test.cc
command.o:	command.cc command.hh
		g++ -c command.cc		

clean:		rm -f *~ *.o nums seq-test
