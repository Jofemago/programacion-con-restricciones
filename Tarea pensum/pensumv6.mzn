int:NumMaterias; 
int:MaxCred; 
int:MinCred; 
int:Ns;

%Representación de las materias
set of int:MATERIAS = 1 .. NumMaterias;
set of int:SEMESTRES= 1 .. Ns;

%Numero de creditos de las materias
array[MATERIAS] of int:CREDITOS;

%Nombre de las materias para generar salidas
array[MATERIAS] of string:NameMaterias; 

%prerrequesitos de cada materia
array[MATERIAS]of set of int:PRERREQUISTOS; 

%var 1..10:Ns;%Numero de semestres
array[MATERIAS]of var SEMESTRES:UbSemestral;

%Asigno la materia que corresponde al semestre en una matriz
array[MATERIAS,SEMESTRES]of var 0..1:MatvsSem;


/*
%OPTIMIZACION 1
  %optimizando por numero de semestres

%una variable para optimizar los semestres
var 1..Ns:OptSem;

constraint forall(m in MATERIAS)(UbSemestral[m] <= OptSem);
*/

%OPTIMIZACION 2
  %optimizando las distacias entre los perrequisitos
  
%var 0..200:Dist;

%constraint sum( m in MATERIAS)(min( i in PRERREQUISTOS[m] where card(PRERREQUISTOS[m])>0)(UbSemestral[i] )) = Dist;
var 1..1000000000000: Dist = sum (m in MATERIAS where (card(PRERREQUISTOS[m]) >0))(min(i in PRERREQUISTOS[m] )
                                                     (UbSemestral[i]));

/*var 1..1000000000000: Dist = sum( m in MATERIAS)( 
                                  if(card(PRERREQUISTOS[m]) > 0) then min( i in PRERREQUISTOS[m] )(UbSemestral[i] )
                                  else 0 endif);*/

%las materias solo tendran un semestre y cuando este en esta fila existira un 1 representado en el smestre que esta
constraint forall(m in MATERIAS)(
  forall(s in SEMESTRES)(
    %UbSemestral[m] == s -> MatvsSem[m,s] = 1
    MatvsSem[m,s] = bool2int(UbSemestral[m] = s)
  )
);


%restricciones para que cada semestre tenga un maximo o minimo de creditos
constraint
  forall(s in SEMESTRES)(
    sum(m in MATERIAS)(MatvsSem[m,s]*CREDITOS[m]) <= 21);
    
    
constraint
  forall(s in SEMESTRES)(
    sum(m in MATERIAS)(MatvsSem[m,s]*CREDITOS[m]) >= 9);


          
%restricciones de los prerrequisitos
constraint
  forall(m in MATERIAS)(
    forall(x in PRERREQUISTOS[m])
      ( UbSemestral[x] < UbSemestral[m])); 
      
%restricciones de los laboratorios
constraint UbSemestral[8] = UbSemestral[9] ; 
constraint UbSemestral[15] = UbSemestral[16] ;  
constraint UbSemestral[24] = UbSemestral[25] ;
constraint UbSemestral[27] = UbSemestral[30] ; 
constraint UbSemestral[20] = UbSemestral[22] ;
constraint UbSemestral[44] = UbSemestral[45] ;     
       
 %solve satisfy;     
 solve minimize Dist; 
%solve minimize OptSem;

/*output ["1 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 1]++["\n\n"]++
       ["2 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 2]++["\n\n"]++
       ["3 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 3]++["\n\n"]++
       ["4 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 4]++["\n\n"]++
       ["5 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 5]++["\n\n"]++
       ["6 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 6]++["\n\n"]++
       ["7 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 7]++["\n\n"]++
       ["8 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 8]++["\n\n"]++
       ["9 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 9]++["\n\n"]++
       ["10 Semestre"]++["\n"]++[NameMaterias[m]++" "|m in MATERIAS where fix(UbSemestral[m]) = 10]++["\n\n"];*/

%intentamos mostrar todas las materias de cada semestre separadas por ---
/*output[ if ( m < 58 ) then NameMaterias[m]++", " else NameMaterias[m]++"---" endif|s in SEMESTRES , m in MATERIAS where fix(MatvsSem[m,s])==1]++ ["\n"];*/

%output[NameMaterias[m]++", "|s in SEMESTRES , m in MATERIAS where fix(MatvsSem[m,s])=1]++ ["\n"];





/*NameMateriasoutput [name[g]++ " " | s in Seats, g in Guests where fix(pos[g]) == s] ++ [ "\n" ];
  
  output [ if fix(q[j]) == i then "Q" else "." endif ++
         if j == n then "\n" else "" endif | i,j in 1..n]*/








