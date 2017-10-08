
#include <iostream>
#include <unordered_map>
#include <vector>
#include <random>

using namespace std;
/*
	ESTE PROGRAMA GENERA
		-Velocidades de barcos de manera aleatoria 
		-Tiempos de salida esperado de barcos de manera aletariea
		-Lugar de salida del barco de manera aleatoria}


	La tabla hash  (salidas)
		0 -> Velocidades
		1 -> Tiempos de salida
		2 -> Lugar de salida*/


void inicializar(unordered_map<int,vector<int>> &BARCOS, int &TotalBarcos){
	for (int i = 1; i <= TotalBarcos ; i++){
		BARCOS.insert({i , vector<int> () });
	} //Lleno la hash table con los barcos para empezar en cada pos del vector a agregr las entradas que necesito sobre cada barco
}


/*	Imprimo para cada barco su velocidad o  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(l, u); // genero : dis(gen)
tiempo de salida o lugar de salida*/
void visualizar(unordered_map<int,vector<int>> &BARCOS, int TotalBarcos , string texto , int salida){//salida 0 , 1 2 
	cout << texto << " = [ ";
	cout << endl;
	for (int i = 1; i <= TotalBarcos ; i++){
		cout << BARCOS[i][salida] <<"  ," << "\t\t%  Barco " << i;/*Numero de barco*/
		cout << endl;
	} 
	cout << " ]; " << endl;
}


template <typename T>
void LlenarBarcos (unordered_map<int,vector<int>> &BARCOS, int inicio, int fin , T &d ){
	random_device rd;
   	mt19937 gen(rd());

	for ( int i = inicio; i <= fin; i++){
		BARCOS[i].push_back(d(gen)); //numero que represanta lo aleatoreo
	}
}

void LlenarFantasmas(unordered_map<int,vector<int>> &BARCOS , int inicio1 , int fin1 
					, int inicio2 , int fin2, int velocidad , int puntoinicio, int Hinicio, int Hfin){
	for(int i = inicio1 ; i <= fin1 ; i++){
		BARCOS[i].push_back(velocidad);  //Una velocidad muy grande
		BARCOS[i].push_back(Hinicio);    //Hora
		BARCOS[i].push_back(puntoinicio);//Lugar que inicia
	}
	for(int i = inicio2 ; i <= fin2 ; i++){
		BARCOS[i].push_back(velocidad);  //Una velocidad muy grande
		BARCOS[i].push_back(Hfin);    //Hora
		BARCOS[i].push_back(puntoinicio);//Lugar que inicia
	}
}

void Mostrarvariable (int n , string NombreVar , string Comentario = ";  "){
	cout << NombreVar << n << Comentario;
	cout <<endl<<endl;
}

//pegar distribucion 
int main (){
	int NumBarcos = 52 ;
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

	unordered_map<int,vector<int>> BARCOS;
	inicializar(BARCOS,TotalBarcos);
	//cout << BARCOS.size()<< endl;
	  

	normal_distribution<> d0(500,150);
    //uniform_int_distribution<> d0(200,800);// genero las velocidades



    uniform_int_distribution<> d1(0, TotalHoras); //Horas posibles a programar para designar una hora aproximada de salida

    binomial_distribution<> d2(1, 0.5);  //0 sale del lado A , 1 Sale del lado B


	
 	//Empiezo a llenar los barcos 
	LlenarBarcos(BARCOS, InicioBarcos,FinBarcos, d0); //lleno su velocidad
	LlenarBarcos(BARCOS, InicioBarcos,FinBarcos, d1); //lleno hora estimada de cruce 
	LlenarBarcos(BARCOS, InicioBarcos,FinBarcos, d2); //Punto salida

	LlenarFantasmas(BARCOS,inicioCanal,FinCanal,BarcosFantasmas,FinFantasmas,66000,0,0,TotalHoras);

	Mostrarvariable(TotalHoras , "HorasDisponibles = " , " ; \t\t% Cantidad de horas habiles para que barco pueda partir" );
	Mostrarvariable(NumBarcos , "NumBarcos = " , " ; \t\t% Cantidad de barcos que cruzaran el canal");
	Mostrarvariable(NumCanales, "NumCanales = ");

	visualizar(BARCOS,TotalBarcos,"Velocidades" ,0);
	visualizar(BARCOS,TotalBarcos,"HoraEstimadaCruce" ,1);
	visualizar(BARCOS,TotalBarcos,"PuntoDeArranque" ,2);
}

//MODIFICAR LAS DISTRIBUCIONES



/*
%EnRuta[b] = N significa cuantos barcos van por el canal
array[BarcosSalida] of var 0 .. 1 :Enruta;

%por cada canal cuento cuantos barcos se tiene
constraint forall( c in BarcosSalida)(
                   Enrutando( BarcoSiguiente[c], 1 , c) );

%si no se llega al barco que es igual al canal entonces que siga recorriendo
predicate Enrutando(var int: Barco, int: Acumulado , int: canal) = 
       not (Enrutando2(Barco, Acumulado, canal)) -> Enrutando(BarcoSiguiente[Barco],Acumulado + 1,canal);


%termino el recorrido, asigna la cantidad de barcos que tiene ese canal
predicate Enrutando2(var int: barco, int: Acumulado , int: canal) = 
       barco = canal -> Enruta[canal] = Acumulado;

*/