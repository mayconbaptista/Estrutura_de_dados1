exe3:
	@gcc -c ./pilha/exe3/exe3main.c -o ./pilha/exe3/exe3main.o
	@gcc -c ./pilha/exe3/TadPilhaSeq.c -o ./pilha/exe3/TadPilhaSeq.o
	@gcc -o stakexe3.exe ./pilha/exe3/exe3main.o ./pilha/exe3/TadPilhaSeq.o
	@./stakexe3.exe

exe4:
	@gcc -c ./pilha/exe4/exe4main.c -o ./pilha/exe4/exe4main.o
	@gcc -c ./pilha/exe3/TadPilhaSeq.c -o ./pilha/exe3/TadPilhaSeq.o
	@gcc -o pilhaexe4.exe ./pilha/exe4/exe4main.o ./pilha/exe3/TadPilhaSeq.o
	@./pilhaexe4.exe

exe2:
	@gcc -c ./pilha/encadeada/WrapperEncmain.c -o ./pilha/encadeada/WrapperEncmain.o
	@gcc -c ./pilha/encadeada/auxlista.c -o ./pilha/encadeada/auxlista.o
	@gcc -c ./pilha/encadeada/PilhaEncWrapper.c -o ./pilha/encadeada/PilhaEncWrapper.o
	@gcc -o WrapperEncmain.exe ./pilha/encadeada/WrapperEncmain.o ./pilha/encadeada/PilhaEncWrapper.o ./pilha/encadeada/auxlista.o
	@./WrapperEncmain.exe

exe1:
	@gcc -c ./pilha/estatica/PilhaEstWramain.c -o ./pilha/estatica/PilhaEstWramain.o
	@gcc -c ./pilha/estatica/bibliFilaEst.c -o ./pilha/estatica/bibliFilaEst.o
	@gcc -c ./pilha/estatica/PilhaEstWrapper.c -o ./pilha/estatica/PilhaEstWrapper.o
	@gcc -o main1.exe ./pilha/estatica/PilhaEstWramain.o ./pilha/estatica/bibliFilaEst.o ./pilha/estatica/PilhaEstWrapper.o
	@./main1.exe

exe5:
	@gcc -c ./pilha/exe5/exe5main.c -o ./pilha/exe5/exe5main.o
	@gcc -c ./pilha/exe3/TadPilhaSeq.c -o ./pilha/exe3/TadPilhaSeq.o
	@gcc -c ./pilha/exe5/Posf.c -o ./pilha/exe5/Posf.o 
	@gcc -o main5.exe ./pilha/exe5/exe5main.o ./pilha/exe3/TadPilhaSeq.o ./pilha/exe5/Posf.o
	@./main5.exe

exe6:
	@gcc -c ./pilha/exe6/expre6main.c -o ./pilha/exe6/expre6main.o
	@gcc -c ./pilha/exe6/PilhaEstint.c -o ./pilha/exe6/PilhaEstint.o
	@gcc -c ./pilha/exe3/TadPilhaSeq.c -o ./pilha/exe3/TadPilhaSeq.o
	@gcc -c ./pilha/exe5/Posf.c -o ./pilha/exe5/Posf.o
	@gcc -o main6.exe ./pilha/exe6/expre6main.o ./pilha/exe6/PilhaEstint.o ./pilha/exe5/Posf.o ./pilha/exe3/TadPilhaSeq.o
	@./main6.exe

filaexe1:
	@gcc -c ./fila/filaexe1/FilaWrapperEnc.c -o ./fila/filaexe1/FilaWrapperEnc.o
	@gcc -c ./fila/filaexe1/auxiliar.c -o ./fila/filaexe1/auxiliar.o
	@gcc -c ./fila/filaexe1/FilaWrapperEncmain.c -o ./fila/filaexe1/FilaWrapperEncmain.o
	@gcc -o filaexe1.exe ./fila/filaexe1/FilaWrapperEnc.o ./pilha/encadeada/auxlista.o ./fila/filaexe1/FilaWrapperEncmain.o
	@./filaexe1.exe

filaexe2:
	@gcc -c ./fila/filaexe2/FilaEncexe2.c -o ./fila/filaexe2/FilaEncexe2.o
	@gcc -c ./fila/filaexe2/FilaEncmainexe2.c -o ./fila/filaexe2/FilaEncmainexe2.o
	@gcc -o filaexe2.exe ./fila/filaexe2/FilaEncmainexe2.o ./fila/filaexe2/FilaEncexe2.o
	@./filaexe2.exe

filaexe3:
	@gcc -c ./fila/filaexe3/TadFilaVaria.c -o ./fila/filaexe3/TadFilaVaria.o
	@gcc -c ./fila/filaexe3/TadfilaVariamain.c -o ./fila/filaexe3/TadfilaVariamain.o
	@gcc -o filaexe3.exe ./fila/filaexe3/TadFilaVaria.o ./fila/filaexe3/TadfilaVariamain.o
	@./filaexe3.exe

listacir:
	@gcc -c ./fila/Listacircular/ListaEncCir.c -o ./fila/Listacircular/ListaEncCir.o
	@gcc -c ./fila/Listacircular/mainListaCirc.c -o ./fila/Listacircular/mainListaCirc.o
	@gcc -o listacir.exe ./fila/Listacircular/ListaEncCir.o ./fila/Listacircular/mainListaCirc.o
	@./listacir.exe

trab:
	@gcc -c ./trabfinal/main.c -o ./trabfinal/main.o
	@gcc -c ./trabfinal/auxmatriz.c -o ./trabfinal/auxmatriz.o
	@gcc -o imm ./trabfinal/main.o ./trabfinal/auxmatriz.o
	

clean:
	@rm ./fila/filaexe1/*.o
	@rm ./fila/filaexe2/*.o
	@rm ./fila/filaexe3/*.o
	@rm ./fila/Listacircular/*.o
	@rm *.exe
	
	
