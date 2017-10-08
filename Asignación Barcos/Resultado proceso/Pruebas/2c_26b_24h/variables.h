
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 26 ;
	int NumCanales = 2 ;
	int TotalBarcos = NumBarcos + NumCanales*2;
	int TotalHoras = 24;

//BARCOS
//--------------------------------------------------------------------------------------
	int inicioCanal = 1;
	int FinCanal = NumCanales;//Estos barcos hacen referencia al principio de cada canal

	int InicioBarcos = NumCanales + 1;
	int FinBarcos = NumBarcos + NumCanales; //En este rango estan todos los barcos a asignar tiempo

	int BarcosFantasmas = NumBarcos + NumCanales + 1;
	int FinFantasmas =TotalBarcos;//Estos indican cuando cada canal ha terminado su recorrido

	//velocidad en la que va cada barco 
	vector<int> velocidades = { 
	66000  ,		//  Barco 1
66000  ,		//  Barco 2
477  ,		//  Barco 3
322  ,		//  Barco 4
508  ,		//  Barco 5
480  ,		//  Barco 6
525  ,		//  Barco 7
555  ,		//  Barco 8
461  ,		//  Barco 9
500  ,		//  Barco 10
657  ,		//  Barco 11
783  ,		//  Barco 12
746  ,		//  Barco 13
414  ,		//  Barco 14
361  ,		//  Barco 15
580  ,		//  Barco 16
527  ,		//  Barco 17
662  ,		//  Barco 18
316  ,		//  Barco 19
326  ,		//  Barco 20
506  ,		//  Barco 21
819  ,		//  Barco 22
339  ,		//  Barco 23
465  ,		//  Barco 24
459  ,		//  Barco 25
507  ,		//  Barco 26
458  ,		//  Barco 27
735  ,		//  Barco 28
66000  ,		//  Barco 29
66000  
};

	vector<int> TiempoEstimadoDecruce = { 
		0  ,		//  Barco 1
0  ,		//  Barco 2
4  ,		//  Barco 3
15  ,		//  Barco 4
3  ,		//  Barco 5
22  ,		//  Barco 6
20  ,		//  Barco 7
19  ,		//  Barco 8
22  ,		//  Barco 9
14  ,		//  Barco 10
3  ,		//  Barco 11
22  ,		//  Barco 12
19  ,		//  Barco 13
9  ,		//  Barco 14
8  ,		//  Barco 15
4  ,		//  Barco 16
17  ,		//  Barco 17
3  ,		//  Barco 18
12  ,		//  Barco 19
20  ,		//  Barco 20
7  ,		//  Barco 21
2  ,		//  Barco 22
0  ,		//  Barco 23
17  ,		//  Barco 24
12  ,		//  Barco 25
4  ,		//  Barco 26
17  ,		//  Barco 27
8  ,		//  Barco 28
24  ,		//  Barco 29
24 
	};


	vector<int> PuntoDeArranque = { 
		0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
1  ,		//  Barco 4
1  ,		//  Barco 5
0  ,		//  Barco 6
1  ,		//  Barco 7
0  ,		//  Barco 8
0  ,		//  Barco 9
1  ,		//  Barco 10
1  ,		//  Barco 11
0  ,		//  Barco 12
0  ,		//  Barco 13
1  ,		//  Barco 14
0  ,		//  Barco 15
0  ,		//  Barco 16
1  ,		//  Barco 17
1  ,		//  Barco 18
0  ,		//  Barco 19
1  ,		//  Barco 20
1  ,		//  Barco 21
1  ,		//  Barco 22
0  ,		//  Barco 23
1  ,		//  Barco 24
1  ,		//  Barco 25
1  ,		//  Barco 26
0  ,		//  Barco 27
0  ,		//  Barco 28
0  ,		//  Barco 29
0 
	};

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {16, 15, 18, 17, 19, 14, 20, 13, 21, 12, 22, 11, 24, 26, 10, 9, 28, 29, 27, 25, 23, 8, 7, 6, 5, 4, 3, 30, 1, 2};


	vector<int>  MinutoDeSalida = {0, 0, 1025, 1010, 764, 787, 601, 510, 142, 180, 393, 310, 561, 922, 0, 117, 1117, 1161, 891, 629, 282, 431, 410, 648, 720, 981, 988, 1240, 1259, 1329};

	vector<int>  MinutoLLegada = {0, 0, 1161, 1211, 891, 922, 724, 627, 282, 310, 491, 393, 648, 1079, 180, 229, 1240, 1259, 1096, 828, 410, 510, 601, 787, 861, 1109, 1129, 1328, 1259, 1329};


	//vector<int>  = {};
