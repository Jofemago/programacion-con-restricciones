
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 110 ;
	int NumCanales = 8 ;
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
66000  ,		//  Barco 4
66000  ,		//  Barco 5
66000  ,		//  Barco 6
66000  ,		//  Barco 7
66000  ,		//  Barco 8
539  ,		//  Barco 9
491  ,		//  Barco 10
552  ,		//  Barco 11
497  ,		//  Barco 12
541  ,		//  Barco 13
621  ,		//  Barco 14
576  ,		//  Barco 15
566  ,		//  Barco 16
623  ,		//  Barco 17
722  ,		//  Barco 18
369  ,		//  Barco 19
434  ,		//  Barco 20
528  ,		//  Barco 21
529  ,		//  Barco 22
432  ,		//  Barco 23
384  ,		//  Barco 24
379  ,		//  Barco 25
790  ,		//  Barco 26
471  ,		//  Barco 27
497  ,		//  Barco 28
575  ,		//  Barco 29
482  ,		//  Barco 30
498  ,		//  Barco 31
527  ,		//  Barco 32
753  ,		//  Barco 33
490  ,		//  Barco 34
573  ,		//  Barco 35
677  ,		//  Barco 36
590  ,		//  Barco 37
507  ,		//  Barco 38
574  ,		//  Barco 39
643  ,		//  Barco 40
188  ,		//  Barco 41
668  ,		//  Barco 42
185  ,		//  Barco 43
637  ,		//  Barco 44
505  ,		//  Barco 45
582  ,		//  Barco 46
513  ,		//  Barco 47
532  ,		//  Barco 48
663  ,		//  Barco 49
415  ,		//  Barco 50
536  ,		//  Barco 51
661  ,		//  Barco 52
509  ,		//  Barco 53
525  ,		//  Barco 54
358  ,		//  Barco 55
528  ,		//  Barco 56
711  ,		//  Barco 57
397  ,		//  Barco 58
815  ,		//  Barco 59
468  ,		//  Barco 60
717  ,		//  Barco 61
479  ,		//  Barco 62
523  ,		//  Barco 63
264  ,		//  Barco 64
367  ,		//  Barco 65
419  ,		//  Barco 66
386  ,		//  Barco 67
545  ,		//  Barco 68
353  ,		//  Barco 69
631  ,		//  Barco 70
350  ,		//  Barco 71
691  ,		//  Barco 72
359  ,		//  Barco 73
584  ,		//  Barco 74
491  ,		//  Barco 75
726  ,		//  Barco 76
537  ,		//  Barco 77
535  ,		//  Barco 78
408  ,		//  Barco 79
374  ,		//  Barco 80
677  ,		//  Barco 81
566  ,		//  Barco 82
500  ,		//  Barco 83
592  ,		//  Barco 84
578  ,		//  Barco 85
461  ,		//  Barco 86
601  ,		//  Barco 87
464  ,		//  Barco 88
436  ,		//  Barco 89
202  ,		//  Barco 90
645  ,		//  Barco 91
531  ,		//  Barco 92
432  ,		//  Barco 93
571  ,		//  Barco 94
403  ,		//  Barco 95
540  ,		//  Barco 96
396  ,		//  Barco 97
400  ,		//  Barco 98
458  ,		//  Barco 99
734  ,		//  Barco 100
530  ,		//  Barco 101
411  ,		//  Barco 102
571  ,		//  Barco 103
740  ,		//  Barco 104
417  ,		//  Barco 105
365  ,		//  Barco 106
461  ,		//  Barco 107
460  ,		//  Barco 108
492  ,		//  Barco 109
547  ,		//  Barco 110
221  ,		//  Barco 111
824  ,		//  Barco 112
555  ,		//  Barco 113
424  ,		//  Barco 114
478  ,		//  Barco 115
404  ,		//  Barco 116
686  ,		//  Barco 117
193  ,		//  Barco 118
66000  ,		//  Barco 119
66000  ,		//  Barco 120
66000  ,		//  Barco 121
66000  ,		//  Barco 122
66000  ,		//  Barco 123
66000  ,		//  Barco 124
66000  ,		//  Barco 125
6600
 };

	vector<int> TiempoEstimadoDecruce = {
	0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
0  ,		//  Barco 5
0  ,		//  Barco 6
0  ,		//  Barco 7
0  ,		//  Barco 8
6  ,		//  Barco 9
8  ,		//  Barco 10
24  ,		//  Barco 11
7  ,		//  Barco 12
9  ,		//  Barco 13
14  ,		//  Barco 14
15  ,		//  Barco 15
2  ,		//  Barco 16
7  ,		//  Barco 17
23  ,		//  Barco 18
24  ,		//  Barco 19
18  ,		//  Barco 20
14  ,		//  Barco 21
22  ,		//  Barco 22
22  ,		//  Barco 23
23  ,		//  Barco 24
2  ,		//  Barco 25
16  ,		//  Barco 26
5  ,		//  Barco 27
22  ,		//  Barco 28
16  ,		//  Barco 29
9  ,		//  Barco 30
23  ,		//  Barco 31
12  ,		//  Barco 32
6  ,		//  Barco 33
1  ,		//  Barco 34
14  ,		//  Barco 35
6  ,		//  Barco 36
9  ,		//  Barco 37
13  ,		//  Barco 38
17  ,		//  Barco 39
11  ,		//  Barco 40
15  ,		//  Barco 41
0  ,		//  Barco 42
24  ,		//  Barco 43
4  ,		//  Barco 44
7  ,		//  Barco 45
13  ,		//  Barco 46
7  ,		//  Barco 47
18  ,		//  Barco 48
11  ,		//  Barco 49
4  ,		//  Barco 50
5  ,		//  Barco 51
3  ,		//  Barco 52
24  ,		//  Barco 53
12  ,		//  Barco 54
9  ,		//  Barco 55
3  ,		//  Barco 56
21  ,		//  Barco 57
11  ,		//  Barco 58
13  ,		//  Barco 59
6  ,		//  Barco 60
21  ,		//  Barco 61
6  ,		//  Barco 62
19  ,		//  Barco 63
22  ,		//  Barco 64
15  ,		//  Barco 65
3  ,		//  Barco 66
13  ,		//  Barco 67
24  ,		//  Barco 68
18  ,		//  Barco 69
9  ,		//  Barco 70
21  ,		//  Barco 71
8  ,		//  Barco 72
13  ,		//  Barco 73
19  ,		//  Barco 74
8  ,		//  Barco 75
22  ,		//  Barco 76
2  ,		//  Barco 77
6  ,		//  Barco 78
5  ,		//  Barco 79
0  ,		//  Barco 80
14  ,		//  Barco 81
10  ,		//  Barco 82
14  ,		//  Barco 83
9  ,		//  Barco 84
23  ,		//  Barco 85
19  ,		//  Barco 86
19  ,		//  Barco 87
21  ,		//  Barco 88
22  ,		//  Barco 89
23  ,		//  Barco 90
23  ,		//  Barco 91
9  ,		//  Barco 92
9  ,		//  Barco 93
8  ,		//  Barco 94
7  ,		//  Barco 95
14  ,		//  Barco 96
4  ,		//  Barco 97
12  ,		//  Barco 98
14  ,		//  Barco 99
22  ,		//  Barco 100
4  ,		//  Barco 101
7  ,		//  Barco 102
21  ,		//  Barco 103
23  ,		//  Barco 104
13  ,		//  Barco 105
23  ,		//  Barco 106
4  ,		//  Barco 107
16  ,		//  Barco 108
8  ,		//  Barco 109
20  ,		//  Barco 110
3  ,		//  Barco 111
7  ,		//  Barco 112
0  ,		//  Barco 113
10  ,		//  Barco 114
15  ,		//  Barco 115
4  ,		//  Barco 116
15  ,		//  Barco 117
6  ,		//  Barco 118
24  ,		//  Barco 119
24  ,		//  Barco 120
24  ,		//  Barco 121
24  ,		//  Barco 122
24  ,		//  Barco 123
24  ,		//  Barco 124
24  ,		//  Barco 125
24  
 };


	vector<int> PuntoDeArranque = { 
	0  ,		//  Barco 1
0  ,		//  Barco 2
0  ,		//  Barco 3
0  ,		//  Barco 4
0  ,		//  Barco 5
0  ,		//  Barco 6
0  ,		//  Barco 7
0  ,		//  Barco 8
0  ,		//  Barco 9
1  ,		//  Barco 10
1  ,		//  Barco 11
1  ,		//  Barco 12
0  ,		//  Barco 13
0  ,		//  Barco 14
0  ,		//  Barco 15
1  ,		//  Barco 16
0  ,		//  Barco 17
0  ,		//  Barco 18
1  ,		//  Barco 19
0  ,		//  Barco 20
0  ,		//  Barco 21
1  ,		//  Barco 22
1  ,		//  Barco 23
0  ,		//  Barco 24
1  ,		//  Barco 25
0  ,		//  Barco 26
1  ,		//  Barco 27
1  ,		//  Barco 28
0  ,		//  Barco 29
0  ,		//  Barco 30
0  ,		//  Barco 31
1  ,		//  Barco 32
1  ,		//  Barco 33
0  ,		//  Barco 34
1  ,		//  Barco 35
1  ,		//  Barco 36
0  ,		//  Barco 37
1  ,		//  Barco 38
0  ,		//  Barco 39
0  ,		//  Barco 40
1  ,		//  Barco 41
0  ,		//  Barco 42
1  ,		//  Barco 43
1  ,		//  Barco 44
1  ,		//  Barco 45
1  ,		//  Barco 46
0  ,		//  Barco 47
1  ,		//  Barco 48
0  ,		//  Barco 49
0  ,		//  Barco 50
0  ,		//  Barco 51
1  ,		//  Barco 52
1  ,		//  Barco 53
0  ,		//  Barco 54
1  ,		//  Barco 55
0  ,		//  Barco 56
1  ,		//  Barco 57
1  ,		//  Barco 58
1  ,		//  Barco 59
1  ,		//  Barco 60
0  ,		//  Barco 61
1  ,		//  Barco 62
1  ,		//  Barco 63
1  ,		//  Barco 64
1  ,		//  Barco 65
0  ,		//  Barco 66
1  ,		//  Barco 67
0  ,		//  Barco 68
1  ,		//  Barco 69
0  ,		//  Barco 70
1  ,		//  Barco 71
0  ,		//  Barco 72
0  ,		//  Barco 73
1  ,		//  Barco 74
1  ,		//  Barco 75
1  ,		//  Barco 76
1  ,		//  Barco 77
0  ,		//  Barco 78
0  ,		//  Barco 79
0  ,		//  Barco 80
0  ,		//  Barco 81
0  ,		//  Barco 82
1  ,		//  Barco 83
0  ,		//  Barco 84
1  ,		//  Barco 85
1  ,		//  Barco 86
0  ,		//  Barco 87
1  ,		//  Barco 88
1  ,		//  Barco 89
0  ,		//  Barco 90
1  ,		//  Barco 91
1  ,		//  Barco 92
1  ,		//  Barco 93
0  ,		//  Barco 94
1  ,		//  Barco 95
0  ,		//  Barco 96
1  ,		//  Barco 97
1  ,		//  Barco 98
0  ,		//  Barco 99
1  ,		//  Barco 100
1  ,		//  Barco 101
0  ,		//  Barco 102
0  ,		//  Barco 103
1  ,		//  Barco 104
0  ,		//  Barco 105
0  ,		//  Barco 106
0  ,		//  Barco 107
1  ,		//  Barco 108
1  ,		//  Barco 109
0  ,		//  Barco 110
1  ,		//  Barco 111
1  ,		//  Barco 112
1  ,		//  Barco 113
0  ,		//  Barco 114
0  ,		//  Barco 115
1  ,		//  Barco 116
1  ,		//  Barco 117
0  ,		//  Barco 118
0  ,		//  Barco 119
0  ,		//  Barco 120
0  ,		//  Barco 121
0  ,		//  Barco 122
0  ,		//  Barco 123
0  ,		//  Barco 124
0  ,		//  Barco 125
0 
};

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {64, 63, 65, 62, 66, 61, 67, 60, 121, 118, 117, 116, 115, 114, 113, 112, 16, 110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94, 93, 92, 91, 90, 89, 88, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 76, 75, 74, 73, 72, 71, 70, 69, 68, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 111, 15, 14, 13, 12, 11, 10, 119, 120, 9, 123, 125, 126, 124, 122, 1, 2, 3, 4, 5, 6, 7, 8};


	vector<int>  MinutoDeSalida = {0, 0, 0, 0, 0, 0, 0, 0, 1271, 906, 991, 910, 963, 1205, 1042, 1260, 1156, 768, 873, 719, 887, 984, 822, 906, 951, 661, 800, 568, 814, 781, 643, 756, 895, 565, 730, 518, 604, 434, 381, 609, 442, 328, 440, 307, 445, 209, 306, 391, 261, 217, 292, 257, 382, 61, 40, 246, 55, 31, 90, 0, 0, 0, 0, 0, 0, 0, 311, 138, 108, 194, 76, 297, 221, 184, 411, 287, 413, 281, 283, 513, 359, 320, 474, 409, 705, 425, 787, 710, 494, 562, 714, 540, 756, 611, 914, 879, 773, 915, 840, 631, 845, 679, 1122, 1075, 972, 1106, 915, 868, 948, 788, 1095, 1315, 1154, 1229, 990, 940, 1036, 1038, 1389, 1393, 1392, 1375, 1383, 1130, 1126, 1100};

	vector<int>  MinutoLLegada = {0, 0, 0, 0, 0, 0, 0, 0, 1391, 1038, 1108, 1040, 1083, 1309, 1154, 1374, 1260, 858, 1049, 868, 1010, 1106, 972, 1075, 1122, 743, 938, 698, 927, 915, 773, 879, 981, 697, 843, 614, 714, 562, 494, 710, 787, 425, 791, 409, 573, 320, 432, 513, 359, 373, 413, 355, 509, 184, 221, 369, 146, 194, 169, 138, 90, 135, 124, 246, 177, 155, 479, 257, 292, 297, 261, 391, 402, 295, 543, 376, 534, 402, 442, 686, 455, 434, 604, 518, 817, 565, 895, 850, 643, 883, 814, 662, 906, 724, 1075, 999, 937, 1077, 981, 719, 967, 837, 1235, 1162, 1127, 1284, 1055, 1009, 1080, 906, 1389, 1393, 1271, 1382, 1125, 1100, 1130, 1374, 1389, 1393, 1392, 1375, 1383, 1130, 1126, 1100};


	//vector<int>  = {};
