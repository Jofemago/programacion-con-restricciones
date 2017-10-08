include "alldifferent.mzn";

%ENTRADAS
int:MinutosxHora = 60;
int:HorasDisponibles;
int:MinutosDisponibles = (HorasDisponibles ) * MinutosxHora; 
set of int: Minutos = 0 .. MinutosDisponibles;


int:NumCanales;  % barcos de salida que representan cada canal.
%Hay un número igual de barcos de salida a barcos de llegada por canal, estos barcos son fanasmas a velocidades muy altas y no afectan el proceso

int:NumBarcos; %Numero de barcos que cruzarán el canal

int:InicioLlegada = NumCanales + NumBarcos + 1;%en este punto se cuentan los barcos finales fantasmas que avisan el fin de asignacion de un canal
int:FinBarcos = NumCanales * 2 + NumBarcos; %total barcos mas barcos fantasma

int:InicioBarcosReales=NumCanales+1;
int:FinBarcosReales=NumCanales+NumBarcos;

set of int: BarcosReales = InicioBarcosReales..FinBarcosReales; %rango barcos reales dentro del conjunto

set of int:CANALES = 1..NumCanales;%solo los barcos que identifican cada canal
set of int: FINCANALES =InicioLlegada..FinBarcos ;
set of int: BARCOS = 1..FinBarcos; %total barcos con barcos fantasma incluidos

array[BARCOS] of int:HoraEstimadaCruce;%Hora en que cada barco debe estar cruzando el barco

array[BARCOS] of int:Velocidades; %velociadad con la que cada barco cruza 

array[BARCOS] of 0..1 :PuntoDeArranque; %lugar de donde arranca un barco a -> 0 y b ->1

int:distSeguridad = 15000; %Distancia de seguridad que debe haber entre barcos
int:DistanciaCanal = 65000; %Distancia del canal dada en metros
 
 
%--------------------------------------------------------------------------------


%VARIABLES A DECIDIR 


%Se tendra en cuenta que los BarcoSalida significa el inicio canal y tendran asignado el barco con el arranca y este con el siguiente y asi sucesivamente por cada canal Ademas BarcoLlegada es el fin del canal y este apuntara siguiente el inicio canal osea que en ese canal se ha asignado completamente el paso de barcos
array[BARCOS] of var BARCOS: BarcoSiguiente; %especifica a cada barco cual es que debe seguir


/*MinutoDeSalida[i] = n es el minuto en el que el barco empezara a pasar por el canal. Se iran asingando con respecto al orden que vaya obteniendo en la variable BarcoSiguiente */
array[BARCOS] of var Minutos :MinutoDeSalida; %


/* MinutoDeLlegada[i] = n es el minuto en el cual el barco pasa el canal */
array[BARCOS] of var int :MinutoDeLlegada;


%EnRuta[b] = N significa por que canal va cada barco
array[BARCOS] of var CANALES :Enruta;


%Cada canal tiene unos barcos a pasar y el numero de canal define la ruta de esos barcos
constraint forall(c in CANALES)(Enruta[c] = c);

%Un barco b y su siguiente van en la misma ruta
constraint forall(b in BARCOS)
            (Enruta[BarcoSiguiente[b]] =  Enruta[b]);
            
%constraint sum([Enruta[b] * 1|b in BARCOS]) = FinBarcos; %todos los barcos estan enrutados



/*
%EnRuta[b] = N significa cuantos barcos van por el canal
array[CANALES] of var 0 .. FinBarcos :Enruta;

%por cada canal cuento cuantos barcos se tiene
constraint forall( c in CANALES)(
                   Enrutando( BarcoSiguiente[c], 1 , c) );

%si no se llega al barco que es igual al canal entonces que siga recorriendo
predicate Enrutando(var int: Barco, int: Acumulado , int: canal) = 
       not (Enrutando2(Barco, Acumulado, canal)) -> Enrutando(BarcoSiguiente[Barco],Acumulado + 1,canal);


%termino el recorrido, asigna la cantidad de barcos que tiene ese canal
predicate Enrutando2(var int: barco, int: Acumulado , int: canal) = 
       barco = canal -> Enruta[canal] = Acumulado;

*/
%PRUEBA FALLIDA
                    

%RESTRICCIONES
/*BarcoSiguiente[i] = j  del barco i sigue el barco j*/
constraint alldifferent(BarcoSiguiente);

/*El barco siguiente no puede ser el mismo */
constraint forall(b in BARCOS)
                 (BarcoSiguiente[b] != b);

/*Cada barco fantasma en el rango FINCANALES le corresponde un barco en el rango CANALESs que forman un ciclo de inicio y fin de barcos que pasan por el canal*/
int:PosInicio = NumBarcos + NumCanales;
constraint forall(b in FINCANALES)
                 (BarcoSiguiente[b] = b - PosInicio); 
                 
/*Cada inicio debe ser diferente a otros canales y me aseguro que ningun canal interfiera con el otro*/
constraint forall(b1,b2 in CANALES ) /*where b2 != b1*/
                 (BarcoSiguiente[b1] != b2 );
                 
/*El inicio de los barcos fantasma de salida es el minuto 0*/ 
constraint forall(b in CANALES)
                 (MinutoDeSalida[b] = 0);
          
/*La hora de llegada de cada barco esta relaciona con la hora de salida */
constraint forall(b in BARCOS)
                 (MinutoDeLlegada[b] = (MinutoDeSalida[b] + ceil(DistanciaCanal div Velocidades[b])));

/*Rango de barcos de las siguiente restricciones ya que los barcos fantasmas del fin tienen asignado el barco siguiente no se puede aplicar sobre estos por que estos ya tienen asignada la hora 0 y me generaria conflicto*/
set of int:RANGOBARCOS = 1 .. FinBarcosReales;

%Cuando el siguiente barco arranca en un punto distinto debe de salir despues de que el otro barco cruce el canal
constraint forall(b in RANGOBARCOS )
                  (PuntoDeArranque[b] != PuntoDeArranque[BarcoSiguiente[b]] -> 
                  MinutoDeLlegada[b] <= MinutoDeSalida[BarcoSiguiente[b]]);
                  

%b y su barco siguiente van por el mismo camino y la velocidad de b es mayor o igual a la de su siguiente
constraint forall(b in RANGOBARCOS )
       (PuntoDeArranque[b] = PuntoDeArranque[BarcoSiguiente[b]] /\ Velocidades[b] >= Velocidades[BarcoSiguiente[b]] ->
        MinutoDeSalida[BarcoSiguiente[b]] >= MinutoDeSalida[b] + ceil(distSeguridad div  Velocidades[b]));
        
%b y su barco siguiente van por el mismo camino y la velocidad de b es menor que la de su barco siguiente
%me aseguro que la diferencia de tiempo entre los dos barcos cuando llegue el barco b sea como minimo el tiempo que se demore el barco siguiente de b en recorrer esa distancia de seguridad
constraint forall(b in RANGOBARCOS )
       (PuntoDeArranque[b] = PuntoDeArranque[BarcoSiguiente[b]] /\ Velocidades[b] < Velocidades[BarcoSiguiente[b]] ->
      MinutoDeLlegada[BarcoSiguiente[b]] >= MinutoDeLlegada[b] + (distSeguridad div Velocidades[BarcoSiguiente[b]] + 1));


%OPTIMIZACION

var int: MakeSpan;
MakeSpan = sum(b in BarcosReales)(abs(HoraEstimadaCruce[b]*60 - MinutoDeSalida[b]));


%ann: search_ann= int_search(BarcoSiguiente, input_order, indomain_min, complete);
%ann: search_ann = int_search(BarcoSiguiente, input_order, indomain_median, complete);
%ann:search_ann =int_search(BarcoSiguiente, first_fail, indomain_min, complete);
ann:search_ann =int_search(BarcoSiguiente, first_fail, indomain_median, complete);

%solve :: search_ann satisfy;
%solve :: search_ann minimize MakeSpan;
solve minimize MakeSpan;
%solve satisfy;
output[show(BarcoSiguiente)]++["\n\n"]++[show(MinutoDeSalida)]++["\n\n"]++[show(MinutoDeLlegada)]++["\n\n"]++[show(Enruta)];


