
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 18 ;
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
523  ,		//  Barco 2
211  ,		//  Barco 3
481  ,		//  Barco 4
627  ,		//  Barco 5
398  ,		//  Barco 6
561  ,		//  Barco 7
417  ,		//  Barco 8
604  ,		//  Barco 9
325  ,		//  Barco 10
605  ,		//  Barco 11
699  ,		//  Barco 12
445  ,		//  Barco 13
448  ,		//  Barco 14
489  ,		//  Barco 15
653  ,		//  Barco 16
720  ,		//  Barco 17
582  ,		//  Barco 18
541  ,		//  Barco 19
66000
	};

	vector<int> TiempoEstimadoDecruce = {
	 0  ,		//  Barco 1
13  ,		//  Barco 2
22  ,		//  Barco 3
4  ,		//  Barco 4
12  ,		//  Barco 5
5  ,		//  Barco 6
18  ,		//  Barco 7
3  ,		//  Barco 8
19  ,		//  Barco 9
13  ,		//  Barco 10
4  ,		//  Barco 11
2  ,		//  Barco 12
5  ,		//  Barco 13
23  ,		//  Barco 14
13  ,		//  Barco 15
22  ,		//  Barco 16
12  ,		//  Barco 17
11  ,		//  Barco 18
12  ,		//  Barco 19
24
};


	vector<int> PuntoDeArranque = {
	0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
1  ,		//  Barco 5
1  ,		//  Barco 6
1  ,		//  Barco 7
1  ,		//  Barco 8
1  ,		//  Barco 9
0  ,		//  Barco 10
0  ,		//  Barco 11
1  ,		//  Barco 12
0  ,		//  Barco 13
1  ,		//  Barco 14
1  ,		//  Barco 15
1  ,		//  Barco 16
1  ,		//  Barco 17
1  ,		//  Barco 18
1  ,		//  Barco 19
0 
 };

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {17, 11, 20, 13, 18, 19, 16, 15, 14, 12, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


	vector<int>  MinutoDeSalida = {0, 568, 1131, 116, 997, 377, 936, 293, 855, 634, 610, 834, 147, 879, 347, 975, 26, 1020, 448, 1440};

	vector<int>  MinutoLLegada = {0, 692, 1439, 251, 1100, 540, 1051, 448, 962, 834, 717, 926, 293, 1024, 479, 1074, 116, 1131, 568, 1440};


	//vector<int>  = {};
