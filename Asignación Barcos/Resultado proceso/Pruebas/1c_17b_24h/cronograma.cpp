#include <iostream>
#include <vector>
#include "variables.h"

using namespace std;


void ImprimirTitulos(int n){
	cout<< "Canal: " << n << endl;
	cout<< "Barco	 Velocidad  	PuntoSalida 	HoraEstimada 	MinutoSalida 	MinLleg"<< endl;
}


void imprimirRuta(int Canal){
	int n = 1;
	ImprimirTitulos(Canal);
	int d = Canal;
	cout << d << "     \t"<< velocidades[d -1] << "\t\t" << PuntoDeArranque[d - 1]<<
		"\t\t"<< TiempoEstimadoDecruce[d-1] * 60<<"\t\t"<< MinutoDeSalida[d - 1]<<"\t\t"<< 
		MinutoLLegada[d - 1]<< endl;
	d = BarcoSiguiente[Canal-1];
	
	while(d != Canal){
		 //d = Canal;
		cout << d << "     \t"<< velocidades[d -1] << "\t\t" << PuntoDeArranque[d - 1]<<
		"\t\t"<< TiempoEstimadoDecruce[d-1] * 60 <<"\t\t"<< MinutoDeSalida[d - 1]<<"\t\t"<< 
		MinutoLLegada[d - 1]<< endl;
		d = BarcoSiguiente[d - 1];
		n++;
	}
	cout << "Numero de Barcos = "<< n ;
	cout << endl << endl;
}

int main(){
	for (int i = 1; i <= NumCanales ; i++)
		imprimirRuta(i);
	
}


