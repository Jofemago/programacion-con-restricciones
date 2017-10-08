include "cumulative.mzn";
include "alldifferent.mzn";

int:NumEquipos= 20; %numero de equipos que jugaran el torneo


set of int:Equipos = 1..NumEquipos; %los equipos que jugaran el torneo

%el numero de equipos debe ser divisible por 4, este modelo se basara en divisiones de 5 equipos
int:EquiposxDivision =4;

int:NumeroDivisiones = NumEquipos div EquiposxDivision;%calculo de cuantas divisiones tengo en el torneo 

int:PartidosxEquipo =EquiposxDivision - 1; %cada equipo va jugar con todos los equipos de la division a la que perteneza
set of int:Partidos = 1..PartidosxEquipo;%partidos que juega cada equipo

int:tiempoDescaso = 2; %slots(tiempo) de descanso entre cada partido 

int:partidosxDia = 2; %Numero de partidos que juega un equipo en el dia

array[Equipos,Partidos] of int: ListaOponentes =[|2 , 3 , 4, %cada fila corresponde a un equipo y alfrente los equipos 
                                                 |1 , 3 , 4, %que este enfrentará
                                                 |1 , 2 , 4,
                                                 |1 , 2 , 3,
                                                 |6 , 7 , 8,
                                                 |5 , 7 , 8,
                                                 |5 , 6 , 8,
                                                 |5 , 6 , 7,
                                                 |10, 11, 12,
                                                 |9 , 11, 12,
                                                 |9 , 10, 12,
                                                 |9 , 10, 11,
                                                 |14, 15, 16,
                                                 |13, 15, 16,
                                                 |13, 14, 16,
                                                 |13, 14, 15,
                                                 |18, 19, 20,
                                                 |17, 19, 20,
                                                 |17, 18, 20,
                                                 |17, 18, 19|];
                                                 
                                                 
int: PartidosxDivision = 6; %el numero de partidos que se jugaran por division

%cantidad de partidos que se juegan en la fase preliminar                                                
int: NumPartidos = NumEquipos*PartidosxEquipo;

%Partidos que se jugaran en toda la fase preliminar
set of int:Games = 1..NumPartidos;

int:NumCanchas = 20; %numero de canchas para jugar el torneo
int:HorasxDia = 10; %horas de juego maximas en el dia 
int:NumDias = 5; %Numero de dias en los que se jugara el torneo 
set of int:Dias = 0..NumDias;
set of int:CamposDejuego = 1 .. NumCanchas;

%Ahora se decidira el numero de cada partido.
array[Equipos,Partidos] of var Games:ListaDeJuegos;


int: totalHoras = HorasxDia*NumDias;
set of int:DiasHabiles= 1..totalHoras;%ojo
%Hora de inicio que depende unicamente del numero de partido asignado en la variable de arriba 
array[Equipos,Partidos] of var DiasHabiles: HoraInicio;

%rango de las canchas CamposDejuego
array[Equipos,Partidos] of var int: Cancha;

%Dia que se juega cada partido sacado por la formula
array[Equipos,Partidos] of var Dias:DiaDelJuego;
/*
constraint (let { array[int] of var int:arreglo =
                  [DiaDelJuego[e,p]| e in Equipos,p in Partidos ];} in
                   alldifferent(arreglo));*/

%basado en la hora calculo el dia
constraint forall(e in Equipos)(
                 forall(p in Partidos)(DiaDelJuego[e,p] = (HoraInicio[e,p] - 1) div (HorasxDia) ));
                 
constraint forall(e in Equipos)( %inicializo la  Cancha por medio de la formula.
                  forall(p in Partidos)(Cancha[e,p] = ListaDeJuegos[e,p]-(HoraInicio[e,p] - 1)* NumCanchas));



constraint forall(e in Equipos)( %inicializo la hora inicio por medio de la formula.
                  forall(p in Partidos)(HoraInicio[e,p] = (ListaDeJuegos[e,p] - 1)*NumCanchas + 1 ));
/*                  
% dos equipos solo juegan una vez no hay partidos de vuelta
constraint forall( e in Equipos)(
                 forall(p in Partidos)(
                         No_Redundancia( e , ListaOponentes[e,p] ,HoraInicio[e,p]  )));

predicate No_Redundancia(int:e1,int:e2, var int:dia) =
          forall(p in Partidos where ListaOponentes[e2,p] = e1)
                (HoraInicio[e2,p] = dia);
*/

% dos equipos solo juegan una vez no hay partidos de vuelta
constraint forall( e in Equipos)(
                 forall(p in Partidos)(
                         No_Redundancia( e , ListaOponentes[e,p] ,DiaDelJuego[e,p]  )));

predicate No_Redundancia(int:e1,int:e2, var int:dia) =
          forall(p in Partidos where ListaOponentes[e2,p] = e1)
                (DiaDelJuego[e2,p] != dia);
                

                
%Debe haber un tiempo de descanso entre partidos del mismo equipo
constraint  forall(e in Equipos)(   
                    forall(p1,p2 in Partidos where p1 != p2)
                      (nonoverlap(HoraInicio[e,p1],tiempoDescaso,
                                       HoraInicio[e,p2],tiempoDescaso)));
                                       
predicate nonoverlap(var int:s1,  int:d1,
                     var int:s2,  int:d2)=
          s1 + d1 <= s2 \/ s2 + d2 <= s1; 
                                     
                                 
%el numero maximo de partidos que puede jugar un equipo en un dia es igual a 2
constraint forall(e in Equipos)(   
                    forall( d in Dias)(
                          sum(p in Partidos)(
                                    if DiaDelJuego[e,p] = d then 1 else 0 endif) <= partidosxDia));
                                    
 
                                                                         
constraint (let { array[int] of var int:start =
                  [HoraInicio[e,p]| e in Equipos,p in Partidos ];
                  array[int] of int:duracion =
                  [1| s in 1..NumPartidos];
                  array[int] of int:recursoxtarea =
                  [1| s in 1..NumPartidos]; } in %hay partidos que tienen redundancia 
            cumulative(start,duracion,recursoxtarea,NumCanchas));                                    
                             

%Optimizare la expación de el calendario 
int:TotalHoras = (NumDias + 1) * HorasxDia;
var 1..TotalHoras:Makespan;

constraint forall(e in Equipos)(
                 forall(p in Partidos)(HoraInicio[e,p] <= Makespan));






solve minimize Makespan;
%solve satisfy;