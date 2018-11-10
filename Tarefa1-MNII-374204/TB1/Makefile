all: app

app: main.o NC_A_P0.o NC_A_P1.o NC_A_P2.o NC_A_P3.o NC_A_P4.o NC_F_P1.o NC_F_P2.o NC_F_P3.o NC_F_P4.o
	g++ main.o NC_A_P0.o NC_A_P1.o NC_A_P2.o NC_A_P3.o NC_A_P4.o NC_F_P1.o NC_F_P2.o NC_F_P3.o NC_F_P4.o -o app	
	
main.o: main.cpp Funcao.hpp Funcao_01.hpp Funcao_02.hpp Funcao_03.hpp Funcao_04.hpp Integracao.hpp NC_A_P0.hpp NC_A_P1.hpp NC_A_P2.hpp NC_A_P3.hpp NC_A_P4.hpp NC_F_P1.hpp NC_F_P2.hpp NC_F_P3.hpp NC_F_P4.hpp
	g++ -g -c main.cpp
	
NC_A_P0.o: NC_A_P0.cpp NC_A_P0.hpp
	g++ -g -c NC_A_P0.cpp

NC_A_P1.o: NC_A_P1.cpp NC_A_P1.hpp
	g++ -g -c NC_A_P1.cpp

NC_A_P2.o: NC_A_P2.cpp NC_A_P2.hpp
	g++ -g -c NC_A_P2.cpp

NC_A_P3.o: NC_A_P3.cpp NC_A_P3.hpp
	g++ -g -c NC_A_P3.cpp

NC_A_P4.o: NC_A_P4.cpp NC_A_P4.hpp
	g++ -g -c NC_A_P4.cpp

NC_F_P1.o: NC_F_P1.cpp NC_F_P1.hpp
	g++ -g -c NC_F_P1.cpp

NC_F_P2.o: NC_F_P2.cpp NC_F_P2.hpp
	g++ -g -c NC_F_P2.cpp

NC_F_P3.o: NC_F_P3.cpp NC_F_P3.hpp
	g++ -g -c NC_F_P3.cpp

NC_F_P4.o: NC_F_P4.cpp NC_F_P4.hpp
	g++ -g -c NC_F_P4.cpp

clean:
	rm -f *.o appls