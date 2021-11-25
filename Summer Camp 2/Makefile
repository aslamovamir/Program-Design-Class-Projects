summer_camp: request.o readline.o summer_camp.o
		gcc -o summer_camp request.o readline.o summer_camp.o
summer_camp.o: summer_camp.c readline.h request.h
		gcc -c summer_camp.c
request.o: request.c  request.h readline.h
		gcc -c request.c
readline.o: readline.c readline.h
		gcc -c readline.c

