all: app

app: main.o NC_A_P0.o NC_A_P1.o NC_A_P2.o NC_A_P3.o NC_A_P4.o NC_F_P1.o NC_F_P2.o NC_F_P3.o NC_F_P4.o GLD_P1.o GLD_P2.o GLD_P3.o GLD_P4.o GH_P2.o GH_P3.o GH_P4.o GLR_P2.o GLR_P3.o GLR_P4.o GC_PN.o
	g++ main.o NC_A_P0.o NC_A_P1.o NC_A_P2.o NC_A_P3.o NC_A_P4.o NC_F_P1.o NC_F_P2.o NC_F_P3.o NC_F_P4.o GLD_P1.o GLD_P2.o GLD_P3.o GLD_P4.o GH_P2.o GH_P3.o GH_P4.o GLR_P2.o GLR_P3.o GLR_P4.o GC_PN.o -o app	
	
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

GLD_P1.o:GLD_P1.cpp GLD_P1.hpp
	g++ -g -c GLD_P1.cpp 

GLD_P2.o:GLD_P2.cpp GLD_P2.hpp
	g++ -g -c GLD_P2.cpp 

GLD_P3.o:GLD_P3.cpp GLD_P3.hpp
	g++ -g -c GLD_P3.cpp 

GLD_P4.o:GLD_P4.cpp GLD_P4.hpp
	g++ -g -c GLD_P4.cpp 

GH_P2.o:GH_P2.cpp GH_P2.hpp
	g++ -g -c GH_P2.cpp

GH_P3.o:GH_P3.cpp GH_P3.hpp
	g++ -g -c GH_P3.cpp

GH_P4.o:GH_P4.cpp GH_P4.hpp
	g++ -g -c GH_P4.cpp 

GLR_P2.o:GLR_P2.cpp GLR_P2.hpp
	g++ -g -c GLR_P2.cpp

GLR_P3.o:GLR_P3.cpp GLR_P3.hpp
	g++ -g -c GLR_P3.cpp

GLR_P4.o:GLR_P4.cpp GLR_P4.hpp
	g++ -g -c GLR_P4.cpp 

GC_PN.o:GC_PN.cpp GC_PN.hpp
	g++ -g -c GC_PN.cpp 


clean:
	rm -f *.o appls