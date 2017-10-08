
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 60 ;
	int NumCanales = 3 ;
	int TotalBarcos = NumBarcos + NumCanales*2;
	int TotalHoras = 50;


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
747  ,		//  Barco 4
289  ,		//  Barco 5
631  ,		//  Barco 6
843  ,		//  Barco 7
382  ,		//  Barco 8
505  ,		//  Barco 9
505  ,		//  Barco 10
354  ,		//  Barco 11
653  ,		//  Barco 12
495  ,		//  Barco 13
543  ,		//  Barco 14
561  ,		//  Barco 15
631  ,		//  Barco 16
539  ,		//  Barco 17
271  ,		//  Barco 18
426  ,		//  Barco 19
303  ,		//  Barco 20
612  ,		//  Barco 21
780  ,		//  Barco 22
452  ,		//  Barco 23
340  ,		//  Barco 24
551  ,		//  Barco 25
525  ,		//  Barco 26
320  ,		//  Barco 27
569  ,		//  Barco 28
475  ,		//  Barco 29
274  ,		//  Barco 30
298  ,		//  Barco 31
412  ,		//  Barco 32
499  ,		//  Barco 33
290  ,		//  Barco 34
663  ,		//  Barco 35
740  ,		//  Barco 36
353  ,		//  Barco 37
377  ,		//  Barco 38
522  ,		//  Barco 39
303  ,		//  Barco 40
734  ,		//  Barco 41
417  ,		//  Barco 42
655  ,		//  Barco 43
554  ,		//  Barco 44
229  ,		//  Barco 45
613  ,		//  Barco 46
496  ,		//  Barco 47
420  ,		//  Barco 48
623  ,		//  Barco 49
346  ,		//  Barco 50
295  ,		//  Barco 51
575  ,		//  Barco 52
479  ,		//  Barco 53
372  ,		//  Barco 54
581  ,		//  Barco 55
447  ,		//  Barco 56
385  ,		//  Barco 57
610  ,		//  Barco 58
402  ,		//  Barco 59
476  ,		//  Barco 60
245  ,		//  Barco 61
717  ,		//  Barco 62
424  ,		//  Barco 63
66000  ,		//  Barco 64
66000  ,		//  Barco 65
66000
	 };

	vector<int> TiempoEstimadoDecruce = { 0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
31  ,		//  Barco 4
19  ,		//  Barco 5
13  ,		//  Barco 6
46  ,		//  Barco 7
49  ,		//  Barco 8
41  ,		//  Barco 9
5  ,		//  Barco 10
3  ,		//  Barco 11
4  ,		//  Barco 12
34  ,		//  Barco 13
16  ,		//  Barco 14
5  ,		//  Barco 15
30  ,		//  Barco 16
17  ,		//  Barco 17
7  ,		//  Barco 18
26  ,		//  Barco 19
34  ,		//  Barco 20
22  ,		//  Barco 21
4  ,		//  Barco 22
43  ,		//  Barco 23
49  ,		//  Barco 24
37  ,		//  Barco 25
48  ,		//  Barco 26
7  ,		//  Barco 27
28  ,		//  Barco 28
28  ,		//  Barco 29
7  ,		//  Barco 30
30  ,		//  Barco 31
50  ,		//  Barco 32
25  ,		//  Barco 33
50  ,		//  Barco 34
49  ,		//  Barco 35
38  ,		//  Barco 36
28  ,		//  Barco 37
9  ,		//  Barco 38
14  ,		//  Barco 39
12  ,		//  Barco 40
45  ,		//  Barco 41
36  ,		//  Barco 42
35  ,		//  Barco 43
0  ,		//  Barco 44
30  ,		//  Barco 45
25  ,		//  Barco 46
5  ,		//  Barco 47
38  ,		//  Barco 48
16  ,		//  Barco 49
16  ,		//  Barco 50
22  ,		//  Barco 51
47  ,		//  Barco 52
50  ,		//  Barco 53
41  ,		//  Barco 54
27  ,		//  Barco 55
11  ,		//  Barco 56
7  ,		//  Barco 57
7  ,		//  Barco 58
25  ,		//  Barco 59
4  ,		//  Barco 60
18  ,		//  Barco 61
11  ,		//  Barco 62
20  ,		//  Barco 63
50  ,		//  Barco 64
50  ,		//  Barco 65
50};


	vector<int> PuntoDeArranque = { 
0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
1  ,		//  Barco 5
0  ,		//  Barco 6
0  ,		//  Barco 7
1  ,		//  Barco 8
0  ,		//  Barco 9
0  ,		//  Barco 10
0  ,		//  Barco 11
1  ,		//  Barco 12
1  ,		//  Barco 13
0  ,		//  Barco 14
1  ,		//  Barco 15
1  ,		//  Barco 16
0  ,		//  Barco 17
0  ,		//  Barco 18
1  ,		//  Barco 19
0  ,		//  Barco 20
0  ,		//  Barco 21
0  ,		//  Barco 22
0  ,		//  Barco 23
0  ,		//  Barco 24
1  ,		//  Barco 25
0  ,		//  Barco 26
1  ,		//  Barco 27
0  ,		//  Barco 28
0  ,		//  Barco 29
0  ,		//  Barco 30
0  ,		//  Barco 31
1  ,		//  Barco 32
0  ,		//  Barco 33
1  ,		//  Barco 34
0  ,		//  Barco 35
0  ,		//  Barco 36
0  ,		//  Barco 37
0  ,		//  Barco 38
0  ,		//  Barco 39
1  ,		//  Barco 40
0  ,		//  Barco 41
0  ,		//  Barco 42
0  ,		//  Barco 43
1  ,		//  Barco 44
1  ,		//  Barco 45
1  ,		//  Barco 46
1  ,		//  Barco 47
0  ,		//  Barco 48
0  ,		//  Barco 49
0  ,		//  Barco 50
1  ,		//  Barco 51
1  ,		//  Barco 52
1  ,		//  Barco 53
1  ,		//  Barco 54
1  ,		//  Barco 55
1  ,		//  Barco 56
1  ,		//  Barco 57
0  ,		//  Barco 58
1  ,		//  Barco 59
0  ,		//  Barco 60
0  ,		//  Barco 61
0  ,		//  Barco 62
1  ,		//  Barco 63
0  ,		//  Barco 64
0  ,		//  Barco 65
0 
	};

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 1, 2, 3};


	vector<int>  MinutoDeSalida = {0, 0, 0, 0, 604, 0, 28, 698, 23, 45, 868, 151, 173, 960, 173, 225, 1020, 288, 248, 1101, 446, 400, 1206, 470, 483, 1255, 661, 600, 1283, 864, 626, 1419, 1002, 844, 1576, 1066, 1068, 1598, 1086, 1252, 1703, 1114, 1466, 1791, 1269, 1565, 1818, 1552, 1671, 1949, 1706, 1775, 2136, 1793, 1803, 2167, 1838, 1914, 2200, 2006, 1938, 2361, 2142, 2204, 2452, 2295};

	vector<int>  MinutoLLegada = {0, 0, 0, 87, 828, 103, 105, 868, 151, 173, 1051, 250, 304, 1079, 288, 328, 1140, 527, 400, 1315, 552, 483, 1349, 661, 600, 1378, 864, 714, 1419, 1101, 844, 1576, 1132, 1068, 1674, 1153, 1252, 1770, 1210, 1466, 1791, 1269, 1565, 1908, 1552, 1671, 1949, 1706, 1775, 2136, 1926, 1888, 2271, 1967, 1914, 2312, 2006, 2020, 2361, 2142, 2203, 2451, 2295, 2204, 2452, 2295};


	//vector<int>  = {};
