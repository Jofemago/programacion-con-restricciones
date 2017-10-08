include "alldifferent.mzn";
include "cumulative.mzn";


%ENTRADAS

%numero de sesiones a asignar horarios
int:NumSesiones;%
set of int:Sesiones = 1..NumSesiones;

int: SessionesAlmuerzos = 205;
set of int: ALMUERZOS = SessionesAlmuerzos .. NumSesiones;

%nombre de cada sesion 
array[Sesiones] of string:NameSesion;%


%Semestre en el que se encuentra cada sesion
array[Sesiones] of int:SemSesion; %


%Grupo en que se encuentra cada sesion 
array[Sesiones] of int:GrupoSesion;%


%cuanto dura cada session
array[Sesiones] of int:DuracionSesion;%


%Que profesor tiene cada Sesion
array[Sesiones] of string:ProSesion;%


%numero de profesores por asignar horario
int:NumProfesores;%
set of int:PROFESORES = 1..NumProfesores;
%Sesiones que da cada profesor
array[PROFESORES] of set of int:SesProfesor; %


%cantidad de grupos que existen
int: NumGrupos;%
set of int: GRUPOS =  1..NumGrupos;
%GupoTotal[i] acede a las sesiones del grupo i
array[GRUPOS] of set of int:GruposTotal;%


%cantidad de materias que existen
int: NumMaterias;
set of int:MATERIAS = 1..NumMaterias;
%GrupoxMateria[i] accede a los grupos de la materia i
array[MATERIAS] of set of int:GrupoxMateria;


%Semestres
int:NumSemestres;
set of int:SEM = 1..NumSemestres;
%MatxSem[i] contiene las materias del semestre i
array[SEM] of set of MATERIAS:MateriaxSem;

%--------------------------------------------------------
%VARIABLES DE DESICION 
int:CantidadHor = 59;
set of int:HorasSemana = 0..CantidadHor;%cantidad de horas a la semana 

array[Sesiones] of var HorasSemana:HoraInicio;
array[Sesiones] of var HorasSemana:HoraFin;
int: HorasxDia = 12;
array[Sesiones] of var 1..5:DiaMateria;

int: MaxSalones;
set of int : Salones = 1..MaxSalones;
var Salones:NumRecursos;


%RESTRICCIONES

%establezco el la hora final de cada sesion
constraint forall(s in Sesiones)
                  (HoraFin[s] = HoraInicio[s]+DuracionSesion[s]);
                  

%Me aseguro de que la sesion empiece y termine en el mismo dia
constraint forall(s in Sesiones)%volver ese 12 un numero de horas al dia en una vaariable
            (DiaMateria[s] = (HoraInicio[s] div HorasxDia) + 1 /\ DiaMateria[s] = (HoraFin[s] div HorasxDia) + 1);
                    
                    
%una sesion debe ir antes o despues de otra                 
predicate nonoverlap(var int:s1,  int:d1,
                      var int:s2,  int:d2)=
                  s1 + d1 <= s2 \/ s2 + d2 <= s1;

%me aseguro que no se crucen las sesiones de los profesores
constraint forall(p in PROFESORES)(
                  forall(i,j in SesProfesor[p] where i != j)
                         (nonoverlap(HoraInicio[i],DuracionSesion[i],
                                       HoraInicio[j],DuracionSesion[j])));
                         
                        
%Las sesiones dentro de un grupo deben estar en dias distintos distintos
constraint 
    forall(gr in GRUPOS)(
          forall( s1,s2 in GruposTotal[gr] where s1 > s2)
                  (DiaMateria[s1] != DiaMateria[s2]));

 %las horas de almuerzo deben empezar entre las 11 y la 1 del dia en que se dictan
  %restar 1 al dia ya que estan de uno a 5
constraint 
      forall(al in ALMUERZOS)
            ( HoraInicio[al] >= (DiaMateria[al] - 1)*HorasxDia + 5 /\
            HoraInicio[al] <= (DiaMateria[al] - 1)*HorasxDia + 7);
 
 %asegurar que exista un grupo en cada materia en el que los horarios de sus sesiones esten en un horario distinto
 %con las sesiones de los grupos de las otras materias en un mismo semestre
 constraint
       forall(s in SEM)(
              forall(m in MateriaxSem[s])(
                exists(gr in GrupoxMateria[m])(
                      SeeSession(s,m,gr))));
                      
predicate SeeSession(int: s, int: m1 , int: gr) =
            forall(m2 in MateriaxSem[s] where m1!=m2)(
                  forall(gr2 in GrupoxMateria[m2])(
                        noverlapgruop(gr,gr2)));
                        
predicate noverlapgruop(int:gr1 , int:gr2) =
          forall(s1 in GruposTotal[gr1])(
                forall(s2 in GruposTotal[gr2])(
                      nonoverlap(HoraInicio[s2],DuracionSesion[s2],
                                 HoraInicio[s1],DuracionSesion[s1]))); 
                                 
set of int: Session2 = 1..204;
%de 1..204 son las sesiones que necesitan un salon
constraint (let { array[int] of var int:start =
                  [HoraInicio[s]| s in Session2];
                  array[int] of int:duracion =
                  [DuracionSesion[s]| s in Session2];
                  array[int] of int:recursoxtarea =
                  [1| s in Session2]; } in
            cumulative(start,duracion,recursoxtarea,NumRecursos));
                  

 
solve minimize NumRecursos;
