make
./geninput
for program in fgetc fgets fscanf extraction getline
do
	echo -e "START: ${program}"
	./${program} input.txt
	echo -e "FINISH: ${program}\n\n"
done
