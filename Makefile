all: geninput fgetc fgets fscanf extraction getline

geninput: geninput.cpp
	gcc -o geninput geninput.cpp

fgetc: fgetc.c
	gcc -o fgetc fgetc.c

fgets: fgets.c
	gcc -o fgets fgets.c
	
fscanf: fscanf.c
	gcc -o fscanf fscanf.c

extraction: extraction.cpp
	g++ -o extraction extraction.cpp
	
getline: getline.cpp
	g++ -o getline getline.cpp
