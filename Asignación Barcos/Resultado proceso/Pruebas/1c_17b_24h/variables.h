
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 17 ;
	int NumCanales = 1 ;
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
594  ,		//  Barco 2
230  ,		//  Barco 3
525  ,		//  Barco 4
258  ,		//  Barco 5
494  ,		//  Barco 6
349  ,		//  Barco 7
808  ,		//  Barco 8
402  ,		//  Barco 9
241  ,		//  Barco 10
611  ,		//  Barco 11
752  ,		//  Barco 12
735  ,		//  Barco 13
473  ,		//  Barco 14
466  ,		//  Barco 15
617  ,		//  Barco 16
931  ,		//  Barco 17
625  ,		//  Barco 18
66000 
	 };

	vector<int> TiempoEstimadoDecruce = { 
	0  ,		//  Barco 1
14  ,		//  Barco 2
23  ,		//  Barco 3
3  ,		//  Barco 4
2  ,		//  Barco 5
19  ,		//  Barco 6
3  ,		//  Barco 7
16  ,		//  Barco 8
18  ,		//  Barco 9
7  ,		//  Barco 10
14  ,		//  Barco 11
3  ,		//  Barco 12
3  ,		//  Barco 13
20  ,		//  Barco 14
5  ,		//  Barco 15
24  ,		//  Barco 16
0  ,		//  Barco 17
10  ,		//  Barco 18
24 
};


	vector<int> PuntoDeArranque = { 
	0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
1  ,		//  Barco 5
0  ,		//  Barco 6
1  ,		//  Barco 7
0  ,		//  Barco 8
1  ,		//  Barco 9
0  ,		//  Barco 10
0  ,		//  Barco 11
0  ,		//  Barco 12
0  ,		//  Barco 13
1  ,		//  Barco 14
0  ,		//  Barco 15
1  ,		//  Barco 16
0  ,		//  Barco 17
1  ,		//  Barco 18
0
};

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {17, 9, 2, 3, 8, 11, 5, 4, 6, 15, 19, 13, 14, 16, 12, 18, 10, 7, 1};


	vector<int>  MinutoDeSalida = {0, 1004, 805, 777, 508, 1274, 466, 759, 1113, 16, 1324, 252, 271, 359, 179, 416, 0, 442, 1431};

	vector<int>  MinutoLLegada = {0, 1113, 1087, 900, 759, 1405, 652, 839, 1274, 285, 1430, 338, 359, 496, 318, 521, 69, 546, 1431};


	//vector<int>  = {};
