build:
	g++ main.cpp -lncurses -o main.out

start: 
	./main.out

dev:
	make build && make start