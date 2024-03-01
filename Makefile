OBJS = main.o matrix.o

matrix.o : matrix.cpp matrix.h
	c++ -c matrix.cpp -O -Wall -Werror -Wshadow
	

main.o : main.cpp matrix.h
	c++ -c main.cpp -O -Wall -Werror -Wshadow
	 
main : $(OBJS)
	c++ -o main $(OBJS) -O -Wall -Werror -Wshadow
	
clear: 
	rm -f $(OBJS) main
	
build:
	make clear main
