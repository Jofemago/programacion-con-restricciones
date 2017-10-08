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



int main(){

	/*//sacar un numero de un string
	string a = "IS0A0";

	a = a.substr(2,1);
	int c;
	c=atoi(a.c_str()); 
	
	cout<< c << endl;*/

	/*unordered_map<pair<string, int>,int,GrupoHash<string,int>,GrupoEqual<string,int>> n;

	n[{"hola0",2}] = 1;
	n[{"hola1",2}] = 2;
	n[{"hola2",3}] = 3;
	n[{"jaime",5}] = 4;
	n[{"jaja",3}] = 5;

	for(pair<pair<string,int>,int> j : n){
		cout << j.first.first << " "<< j.second <<endl;
	}*/
	string myString("11");
	int n =atoi(myString.c_str());
	cout << n;
}