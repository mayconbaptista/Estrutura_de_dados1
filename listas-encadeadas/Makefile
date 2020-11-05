all:
	
simples1:
	@gcc -c ./simples-exe1/main1.c -o ./simples-exe1/main1.o
	@gcc -c ./simples-exe1/linked-list1.c -o ./simples-exe1/linked-list1.o
	@gcc -o tad1.exe ./simples-exe1/main1.o ./simples-exe1/linked-list1.o
	@./tad1.exe

simples2:
	@gcc -c ./simples-exe2/main2.c -o ./simples-exe2/main2.o
	@gcc -c ./simples-exe2/linked-list2.c -o ./simples-exe2/linked-list2.o
	@gcc -o tad2.exe ./simples-exe2/main2.o ./simples-exe2/linked-list2.o
	@./tad2.exe

dupla:
	@gcc -c ./duplamente/tdmain.c -o ./duplamente/tdmain.o
	@gcc -c ./duplamente/tdlinked-list.c -o ./duplamente/tdlinked-list.o
	@gcc -o dupla.exe ./duplamente/tdmain.o ./duplamente/tdlinked-list.o
	@./dupla.exe

clean:
	@rm ./simples-exe1/*.o
	@rm ./simples-exe2/*.o
	@rm ./duplamente/*.o
	@rm ./*.exe
