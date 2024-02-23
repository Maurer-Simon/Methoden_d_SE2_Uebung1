
all: runfile

runfile: main.o hero.o character.o item.o
	g++ -o runfile main.o hero.o character.o item.o -Werror

main.o: main.cpp
	g++ -c main.cpp -Werror

hero.o: hero.cpp hero.h
	g++ -c hero.cpp -Werror

character.o: character.cpp character.h
	g++ -c character.cpp -Werror

item.o: item.cpp item.h
	g++ -c item.cpp -Werror

clean:
	rm *.o runfile

