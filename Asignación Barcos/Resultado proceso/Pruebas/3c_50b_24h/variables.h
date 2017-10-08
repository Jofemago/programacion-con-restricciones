
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 50 ;
	int NumCanales = 3 ;
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
66000  ,		//  Barco 3
503  ,		//  Barco 4
312  ,		//  Barco 5
642  ,		//  Barco 6
325  ,		//  Barco 7
582  ,		//  Barco 8
716  ,		//  Barco 9
577  ,		//  Barco 10
551  ,		//  Barco 11
295  ,		//  Barco 12
514  ,		//  Barco 13
449  ,		//  Barco 14
869  ,		//  Barco 15
512  ,		//  Barco 16
262  ,		//  Barco 17
495  ,		//  Barco 18
350  ,		//  Barco 19
402  ,		//  Barco 20
482  ,		//  Barco 21
459  ,		//  Barco 22
397  ,		//  Barco 23
637  ,		//  Barco 24
656  ,		//  Barco 25
369  ,		//  Barco 26
836  ,		//  Barco 27
506  ,		//  Barco 28
776  ,		//  Barco 29
593  ,		//  Barco 30
502  ,		//  Barco 31
671  ,		//  Barco 32
389  ,		//  Barco 33
316  ,		//  Barco 34
319  ,		//  Barco 35
472  ,		//  Barco 36
568  ,		//  Barco 37
390  ,		//  Barco 38
680  ,		//  Barco 39
479  ,		//  Barco 40
402  ,		//  Barco 41
467  ,		//  Barco 42
510  ,		//  Barco 43
380  ,		//  Barco 44
567  ,		//  Barco 45
595  ,		//  Barco 46
863  ,		//  Barco 47
635  ,		//  Barco 48
248  ,		//  Barco 49
673  ,		//  Barco 50
405  ,		//  Barco 51
581  ,		//  Barco 52
715  ,		//  Barco 53
66000  ,		//  Barco 54
66000  ,		//  Barco 55
66000
};

	vector<int> PuntoDeArranque = { 
0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
0  ,		//  Barco 5
1  ,		//  Barco 6
1  ,		//  Barco 7
1  ,		//  Barco 8
1  ,		//  Barco 9
1  ,		//  Barco 10
0  ,		//  Barco 11
1  ,		//  Barco 12
1  ,		//  Barco 13
1  ,		//  Barco 14
0  ,		//  Barco 15
1  ,		//  Barco 16
0  ,		//  Barco 17
1  ,		//  Barco 18
1  ,		//  Barco 19
0  ,		//  Barco 20
1  ,		//  Barco 21
0  ,		//  Barco 22
0  ,		//  Barco 23
1  ,		//  Barco 24
1  ,		//  Barco 25
1  ,		//  Barco 26
1  ,		//  Barco 27
0  ,		//  Barco 28
1  ,		//  Barco 29
0  ,		//  Barco 30
0  ,		//  Barco 31
1  ,		//  Barco 32
1  ,		//  Barco 33
0  ,		//  Barco 34
0  ,		//  Barco 35
0  ,		//  Barco 36
0  ,		//  Barco 37
0  ,		//  Barco 38
1  ,		//  Barco 39
0  ,		//  Barco 40
1  ,		//  Barco 41
0  ,		//  Barco 42
0  ,		//  Barco 43
0  ,		//  Barco 44
0  ,		//  Barco 45
0  ,		//  Barco 46
1  ,		//  Barco 47
0  ,		//  Barco 48
0  ,		//  Barco 49
1  ,		//  Barco 50
0  ,		//  Barco 51
0  ,		//  Barco 52
0  ,		//  Barco 53
0  ,		//  Barco 54
0  ,		//  Barco 55
0
	};


	vector<int> TiempoEstimadoDecruce = { 
	0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
1  ,		//  Barco 4
10  ,		//  Barco 5
19  ,		//  Barco 6
7  ,		//  Barco 7
8  ,		//  Barco 8
24  ,		//  Barco 9
10  ,		//  Barco 10
18  ,		//  Barco 11
8  ,		//  Barco 12
5  ,		//  Barco 13
3  ,		//  Barco 14
6  ,		//  Barco 15
3  ,		//  Barco 16
7  ,		//  Barco 17
17  ,		//  Barco 18
11  ,		//  Barco 19
8  ,		//  Barco 20
13  ,		//  Barco 21
2  ,		//  Barco 22
16  ,		//  Barco 23
0  ,		//  Barco 24
8  ,		//  Barco 25
4  ,		//  Barco 26
7  ,		//  Barco 27
24  ,		//  Barco 28
23  ,		//  Barco 29
5  ,		//  Barco 30
22  ,		//  Barco 31
3  ,		//  Barco 32
7  ,		//  Barco 33
7  ,		//  Barco 34
22  ,		//  Barco 35
23  ,		//  Barco 36
9  ,		//  Barco 37
0  ,		//  Barco 38
8  ,		//  Barco 39
11  ,		//  Barco 40
8  ,		//  Barco 41
6  ,		//  Barco 42
10  ,		//  Barco 43
7  ,		//  Barco 44
23  ,		//  Barco 45
14  ,		//  Barco 46
6  ,		//  Barco 47
20  ,		//  Barco 48
10  ,		//  Barco 49
1  ,		//  Barco 50
4  ,		//  Barco 51
23  ,		//  Barco 52
5  ,		//  Barco 53
24  ,		//  Barco 54
24  ,		//  Barco 55
24 
};

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 42, 41, 43, 44, 45, 46, 47, 55, 51, 50, 52, 48, 56, 49, 53, 54, 1, 2, 3};


	vector<int>  MinutoDeSalida = {0, 0, 0, 0, 0, 0, 129, 208, 32, 243, 319, 52, 268, 436, 272, 297, 580, 346, 326, 705, 376, 511, 742, 432, 652, 905, 475, 751, 1018, 552, 780, 1037, 661, 809, 1133, 828, 927, 1209, 965, 953, 987, 1269, 991, 1148, 1325, 1035, 1319, 1281, 1097, 1336, 1060, 1304, 1346, 1437, 1440, 1432};

	vector<int>  MinutoLLegada = {0, 0, 0, 129, 208, 101, 329, 319, 122, 355, 436, 272, 394, 580, 346, 423, 828, 477, 511, 866, 510, 652, 905, 534, 751, 1081, 552, 879, 1101, 661, 909, 1133, 828, 1014, 1336, 965, 1041, 1375, 1060, 1088, 1148, 1408, 1118, 1319, 1439, 1144, 1394, 1383, 1359, 1432, 1220, 1415, 1436, 1437, 1440, 1432};


	//vector<int>  = {};
