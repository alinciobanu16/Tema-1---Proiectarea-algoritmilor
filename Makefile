# Darius-Florentin Neatu <neatudarius@gmail.com>
# Copyright 2018

# Exemplu de Makefile pentru tema

# tag-uri obligatorii (nume + comportament identic)
# build    => compileaza toata tema 
#             (ATENTIE! E important - NU compilati in tag-urile de run. Sesizati?)
# run-p$ID => ruleaza problema cu ID-ul specificat (1, 2, 3, 4)
# clean    => sterge toate fisierele generate

# restul este la alegerea studentului
# TODO

# nume necesar (build)
build:
	gcc bani.c -o bani
	gcc gard.c -o gard
	gcc bomboane.c -o bomboane

run-p1:
	./bani

run-p2:
	./gard

run-p3:
	./bomboane

run-p4:      # nume necesar 

clean:
	rm bani
	rm gard
	rm bomboane
