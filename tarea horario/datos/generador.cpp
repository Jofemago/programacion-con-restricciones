#include "treapuno.hh"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <utility>
#include <cassert>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Session{
private:
	int num;
	int semestre;
	string asignatura_;
	int creditos_;
	int grupo_;
	int intensidadHor_;
	int Duracion_;
	string profesor_;

public:
	Session():
		num(),
		semestre(),
		asignatura_(),
		creditos_(),
		grupo_(),
		intensidadHor_(),
		Duracion_(),
		profesor_(){}

	void setnum(int n){num = n;}
	void setsemestre(int c){semestre = c;}
	void setAsig(string a){asignatura_ = a;}
	void setCred(int c){creditos_ = c;}
	void setGrupo(int g){grupo_ = g;}
	void setIntHor(int i){intensidadHor_ = i;}
	void setDuracion(int d){Duracion_ = d;}
	void setProfe(string p){profesor_ = p;}

	int getnum(){return num;}
	int getsemestre(){ return semestre;}
	string getAsig(){return asignatura_;}
	int getCred(){ return creditos_;}
	int getGrupo(){ return grupo_;}
	int getIntHor(){ return intensidadHor_;}
	int getDura(){return Duracion_;}
	string getProfesor(){ return profesor_;}

	void MostrarS(){
		cout << num <<" "<<semestre << " " << asignatura_ << " " << creditos_ << " "
				<< grupo_ << " " << intensidadHor_<< " "<< Duracion_<<" "<<profesor_<<endl;
	}

	bool operator <(const Session &a)const{
		return num < a.num;
	}

	bool operator ==(const Session &a)const{
		return num == a.num;
	}

};


//objeto para guardarle a cada profe las sesiones que debe dar
class Profesor{
	private:
		string Prof;
		vector<int> clases;
	public:
		//cuando se crea una clase se debe crear con el nombre del profesor
		Profesor( string p):Prof(p) , clases() {}

		//añade una session a las sesiones que el profe ya tiene 
		void AddClass(int n){
			clases.push_back(n);
		}
		string getProf(){return Prof;}

		vector<int> Getclases(){
			return clases;
		}

		//imprime en pantalla entre conchetes las sesiones que tiene el profe
		void MostrarClase(){
			cout <<"{ ";
			/*for(int n : clases){
				cout << n << ", ";
			}*/
			int k = clases.size();
			for(int i = 0; i< k; i++){
				cout << clases[i] << ", ";
			}
			cout << "} ,  \t% "<<Prof << endl;
		}

		//muestra el nombre de el profesor de esa materia
		void MostrarNombre(){
			cout <<Prof << endl;
		}


		bool operator <(const Profesor &a)const{
			return Prof < a.Prof;
		}

		bool operator ==(const Profesor &a)const{
			return Prof == a.Prof;
		}
};



//vuelve una linea de codigo un objeto de tipo session
Session GenerateSession(string &line,int &x){
	Session res;
	res.setnum(x);
	char *input = new char[line.length()+1];
	strcpy(input,line.c_str());
	char *token = strtok(input, ",");
	string n;
	n=token;
	n = n.substr(2,1);
	int j= atoi(n.c_str()); 

	res.setsemestre(j);
	token = strtok(NULL, ",");
	n = token;
	res.setAsig(n);
	token = strtok(NULL, ",");
	int b = atoi(token);
	res.setCred(b);
	token = strtok(NULL, ",");
	b = atoi(token);
	res.setGrupo(b);
	token = strtok(NULL, ",");
	b = atoi(token);
	res.setIntHor(b);
	token = strtok(NULL, ",");
	b = atoi(token);
	res.setDuracion(b);
	token = strtok(NULL, ",");
	n=token;
	res.setProfe(n);
	return res;
}

void SemSesion( Treap<Session> &b){ //imprime nombre de las sessione
	cout << "SemSesion = [  "<< endl ;

	b.inorder([](Session n){cout<<"\t" <<n.getsemestre()<< ", "
				<< "\t\t%"<< n.getnum() << endl;});
	cout << "];" << endl;

}




void NameSesion( Treap<Session> &b){ //imprime nombre de las sessione
	cout << "NameSesion = [  "<< endl ;

	b.inorder([](Session n){cout<<"\t"<<"\"" <<n.getAsig()<< "\", "
				<< "\t\t%"<< n.getnum() << endl;});
	cout << "];" << endl;

}

void GrupoSesion(Treap<Session> &b){ //imprime el grupo de cada session
	cout << "GrupoSesion = [  "<< endl ;

	b.inorder([](Session n){cout<<"\t" <<n.getGrupo()<< ", "
				<< "\t\t%"<< n.getnum() << endl;});
	cout << "];" << endl;
}

void DuracionSesion(Treap<Session> &b){ //imprime la duracion de cada session
	cout << "DuracionSesion = [  "<< endl ;

	b.inorder([](Session n){cout<<"\t"<<n.getDura()<< ", "
				<< "\t\t%"<< n.getnum() << endl;});
	cout << "];" << endl;
}


void ProSesion(Treap<Session> &b){ //imprime el profesor de cada session
	cout << "ProSesion = [  "<< endl ;

	b.inorder([](Session n){cout<<"\t"<<"\"" <<n.getProfesor()<< "\", "
				<< "\t\t%"<< n.getnum() << endl;});
	cout << "];" << endl;
}



void imprimir( Treap<Session> &b){//imprime entrada 1
	cout<< "NumSesiones = " << b.getSize()<<"; "<< endl<< endl;
	SemSesion(b);
	cout << endl;
	NameSesion(b);
	cout << endl;
	GrupoSesion(b);
	cout << endl;
	DuracionSesion(b);
	cout << endl;
	ProSesion(b);
	cout << endl;
}



//ingreso todos los profesores en un treap
	//void  ProfConjuntos( Treap<Session> &a, TreapPro<Profesor> &k){
	void  ProfConjuntos( Treap<Session> &a, vector<Profesor> &k){
	//Treap<Profesor> k;
	a.inorder([&]( Session b){ Profesor x(b.getProfesor());
									x.AddClass(b.getnum());
									//k.insert(x);
								 	int n = k.size();
									for(int i=0; i< n; i++){
										if(x.getProf() == k[i].getProf()){
											vector<int> j = x.Getclases();
											int m = j.size();
											for(int h = 0; h < m ; h++){
												k[i].AddClass(j[h]);
											}
											return;
										}

											 }
									k.push_back(x);
								});
	//cout << "good";

	//return k;

}


void imprimirsesProf(vector<Profesor> &teacher){
	//imprime el numero de profesores	
	cout << endl << endl <<"NumProfesores = " << teacher.size() << ";"<< endl;
	cout << "SesProfesor = [ " << endl;
	//imprime las sesiones que da cada profesor entre corchetes
	int x = teacher.size();
	for(int i = 0; i<x; i++){
		teacher[i].MostrarClase();
	}
	cout << "];"<< endl;

}


/*	//imprime las sesiones que da cada profesor separadas por conjuntos de enteros 
void imprimir2(TreapPro<Profesor> n){
	cout << "SesProfesor = [ " << endl;
	n.inorder([&](Profesor x){x.MostrarClase();});
	cout << "];"<< endl;
}

*/

//separar por grupos
template <typename V,typename K>
class GrupoHash {
public:
    size_t operator()(const pair<V, K>& key) const {
    return hash<V>()(key.first) ^ (hash<K>()(key.second) << 1);
  }
};
//sacar hash de una pareja de dos cosas de tipo v {V,V}
/**
 * @brief Used to determine when two edges are the same.
 */
template <typename V,typename K>
class GrupoEqual {
public:
  bool operator()(const pair<V, K>& lhs,
                  const pair<V, K>& rhs) const {
    return lhs.first == rhs.first && lhs.second == rhs.second;
  }
};// cuando dos parejas son iguales


void addgrupo(unordered_map<pair<string, int>,vector<int>,GrupoHash<string,int>,GrupoEqual<string,int>> &n,
				string a, int b, int d){
				//nombre materia, numero del grupo, nnumero de la sesion
	if (n.count({a,b}) > 0){
		n[{a,b}].push_back(d);
	}else{

		n.insert({{a,b},vector<int>()});
		n[{a,b}].push_back(d);
	}

}

void GenerateGrupos(Treap<Session> &clases,
	unordered_map<pair<string, int>,vector<int>,GrupoHash<string,int>,GrupoEqual<string,int>> &gr){
	
	clases.inorder([&](Session n){	addgrupo(gr,n.getAsig(),n.getGrupo(),n.getnum());});

}

void imprimirGrupos(unordered_map<pair<string, int>,vector<int>,GrupoHash<string,int>,GrupoEqual<string,int>> &gr){
	cout << "NumGrupos = " << gr.size() << ";"<< endl;
	cout << "GruposTotal = [ ";
	int k = 1;
	for(pair<pair<string,int>,vector<int>> n: gr){
		cout<< "{ ";
		for(int j : n.second){
			cout<< j <<" , ";
		}
		cout <<"}, % "<<n.first.first << " grupo " <<k << endl;
		k++;
	}
	cout << "];" << endl;
}


//paso toda la informacion de las sesiones a un vector para su mejor uso
void treetovector(Treap<Session> &clases , vector<Session> &clases2){
	clases.inorder([&](Session n){clases2.push_back(n);});
}




void llenargrxmateria(unordered_map<string,pair<int,vector<int>>> &grupXmat,
						string materia, int semestre, int grupo){
	if(grupXmat.count(materia) > 0){
		grupXmat[materia].second.push_back(grupo);
	}else{
		grupXmat.insert({materia,{semestre,vector<int>()}});
		grupXmat[materia].second.push_back(grupo);
	}
	

}
//GRUPOS POR MATERIA 
unordered_map<string,pair<int,vector<int>>> grupoxmateria(unordered_map<pair<string, int>,vector<int>,GrupoHash<string,int>,GrupoEqual<string,int>> &gr
	,vector<Session> &clases2){
	unordered_map<string,pair<int,vector<int>>> grupXmat;

	int grupo = 1;
	for(pair<pair<string,int>,vector<int>> n: gr){
		//accedo a una session de ese grupo y todo el semestre
		int semestre = clases2[n.second[0] - 1].getsemestre();
		string materia =  n.first.first;
		llenargrxmateria(grupXmat,materia,semestre,grupo);
	grupo++;
	}
	return grupXmat;
}


void mostrarGrupoxMateria(unordered_map<string,pair<int,vector<int>>> &grupXmat){
	cout << "NumMaterias= "<< grupXmat.size()<< " ; %"<<"Numero de materias" << endl;
	int num= 1;

	cout << "GrupoxMAteria = [ ";
	for(pair<string, pair <int, vector<int>>> n  : grupXmat){
		cout << " { ";
		for(int k : n.second.second){
			cout<< k << " , ";
		}
		cout << "}, \t%"<< n.first <<"  Materia Nr " << num<<endl;
		num++;
	}
	cout << " ];" << endl;
}


//MATERIASXSEMESTRE
void llenarmateriaporsemestre(unordered_map<int ,vector<int>> &MatxSem,
							int semestre, int materia){
	if(MatxSem.count(semestre)> 0){
		MatxSem[semestre].push_back(materia);
	}else{
		MatxSem.insert({semestre,vector<int>()});
		MatxSem[semestre].push_back(materia);
	}

}

unordered_map<int ,vector<int>> materiasxsemestre(unordered_map<string,pair<int,vector<int>>> &grupXmat){
	unordered_map<int ,vector<int>> MatxSem;
	int materia = 1;
	for(pair<string, pair <int, vector<int>>> n  : grupXmat){
		int semestre = n.second.first;
		llenarmateriaporsemestre(MatxSem,semestre,materia);
		materia++;
	}
	return MatxSem;
}

void mostarMateriaxSemestres(unordered_map<int ,vector<int>> &MatxSem){
	cout << "Numsemestres = 9;" << endl;
	cout << "MatxSem = [ ";
	for(pair<int, vector<int>> n : MatxSem){
		cout << "{ ";
		for(int k : n.second){
			cout<< k << " , ";
		}
		cout << " }," << "\t %"<< "Semestre " <<n.first << endl;
	}
	cout << "];"<<endl;
}

vector<vector<int>> IngresarEntrada(int n){
	vector<vector<int>> salidas;
	for(int i = 0; i < n; i++)
		salidas.push_back(vector<int>());
	string filename("salida.txt");
	ifstream is(filename);
    if (is.good()) {
     	string line;
     	int k = 0; //variable de control en el arreglo 
      	while (getline(is, line)) {
      	   	stringstream ss(line);
      	   	char *input = new char[line.length()+1];
			strcpy(input,line.c_str());
			char *token = strtok(input, ",[]");
			while (token != NULL) {
    			string j;
    			j= token;
    			if(k == n){ /*cout << k << endl;*/ k =0; }
        		salidas[k].push_back(atoi(j.c_str()));
        		/*salidas[k][0] hora inicio
        		  salidas[k][1] hora fin
        		  salidas[k][2] dia*/
        		k++;
        		token = strtok(NULL, ",[]");
    		}
      	   
     	}
    }
    	return salidas;
}

void analisisResultados(vector<vector<int>> &salidas,vector<Session> &clases2){
	for(int i = 0; i < clases2.size(); i++){
		/*if(clases2[i].getProfesor() == "2b525139518edac9f75dd2ff44e2802b"){//mirar que las clases de  un mismo profesor no se cruce
			cout << clases2[i].getAsig() << " ";  //miro que esten en dias distintos
			cout << salidas[i][0] << " " << salidas[i][1] << " " << salidas[i][2] <<endl;
		}*/

		if(clases2[i].getsemestre() == 1 ){
			cout << clases2[i].getAsig() << " Gr."<< clases2[i].getGrupo()<<" " ;  //miro que esten en dias distintos
			cout << salidas[i][0] << " " << salidas[i][1] << " " << salidas[i][2] <<endl<<endl;

		}
	}

}

int main(){

	Treap<Session> clases; 
	string filename("sessionsData.txt");
	ifstream is(filename);
    if (is.good()) {
     	string line;
     	int n = 1;
      	while (getline(is, line)) {
      	//saca linea por linea del archivo que corresponde a una Session
        	stringstream ss(line);
      // cout << line<< endl;
        	Session captura = GenerateSession(line,n);
        	//pair<int,Session> y = {n,captura};
        	clases.insert(captura);
        	n++;
    	}
	}
	//imprimir(clases);
	//Cargo todos los profesores con sus respectivas sesiones
	vector<Profesor> teacher;
	ProfConjuntos(clases,teacher);
	//imprimirsesProf(teacher);
	

	//sessionesa agrupadas
	unordered_map<pair<string, int>,vector<int>,GrupoHash<string,int>,GrupoEqual<string,int>> gr;
	GenerateGrupos(clases,gr);
	cout << endl;
	//imprimirGrupos(gr);
	

	vector<Session> clases2;
	treetovector(clases,clases2);
	unordered_map<string,pair<int,vector<int>>> grupXmat=grupoxmateria(gr,clases2);
	//mostrarGrupoxMateria(grupXmat);//muestro las materia y los grupos que contienen sesiones
	

	//MateriasxSemestre
	unordered_map<int ,vector<int>> MatxSem = materiasxsemestre(grupXmat);
	//mostarMateriaxSemestres(MatxSem);

	is.close();

	vector<vector<int>> salidas = IngresarEntrada(clases2.size());
	analisisResultados(salidas,clases2);
	return EXIT_SUCCESS;

}

/* separar string
	char input[100] = "A bird came down the walk";
    char *token = std::strtok(input, " ");
    while (token != NULL) {
    	string n;
    	n= token;
        cout << n << '\n';
        token = strtok(NULL, " ");
    }*/


    /*convierte un string a entero
	string a = "22";
	int b = atoi(a.c_str());
	cout << b << endl;






    */