
#include <vector>
using namespace std;
//barcos y rango de los barcos 


	int NumBarcos = 8 ;
	int NumCanales = 1 ;
	int TotalBarcos = NumBarcos + NumCanales*2;
	int TotalHoras = 34;

//BARCOS
//--------------------------------------------------------------------------------------
	int inicioCanal = 1;
	int FinCanal = NumCanales;//Estos barcos hacen referencia al principio de cada canal

	int InicioBarcos = NumCanales + 1;
	int FinBarcos = NumBarcos + NumCanales; //En este rango estan todos los barcos a asignar tiempo

	int BarcosFantasmas = NumBarcos + NumCanales + 1;
	int FinFantasmas =TotalBarcos;//Estos indican cuando cada canal ha terminado su recorrido

	//velocidad en la que va cada barco 
	vector<int> velocidades = { };

	vector<int> TiempoEstimadoDecruce = { };


	vector<int> PuntoDeArranque = { };

	//vector<int> Enruta = {};


	vector<int> BarcoSiguiente = {};


	vector<int>  MinutoDeSalida = {};

	vector<int>  MinutoLLegada = {};


	//vector<int>  = {};
