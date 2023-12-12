#include <iostream>
#include <string>
#include "avionDeLigne.hpp"
#include "jet.hpp"
#include "avion.hpp"
#include "compagnie.hpp"
#include "Avion.cpp"
#include "jet.cpp"
#include "avionDeLigne.cpp"
#include "compagnie.cpp"
#include "aeroport.hpp"
#include "aeroport.cpp"


int main(){

    Compagnie maCompagnie("Air France", 18, 04, 2001, "France", 123456789, "fdfdfd@gmail.com", "www.cccc.com");
   

    AvionDeLigne Avion1("Boeing 700", 100, 900, 14000, 350 ,12000, 1,1,2021, "France", &maCompagnie, 1,1,1);
    Avion1.displayInfoAvion();

    AvionDeLigne Avion2("Boeing 321", 100, 900, 14000, 350 ,12000, 1,1,2021, "France", &maCompagnie, 1,1,1);
    Avion2.displayInfoAvion();

    AvionDeLigne Avion3("Boeing 700", 100, 900, 14000, 350 ,12000, 1,1,2021, "France", &maCompagnie, 1,1,1);
    Avion3.displayInfoAvion();

    AvionDeLigne Avion4("Boeing 750", 100, 900, 14000, 350 ,12000, 1,1,2021, "France", &maCompagnie, 1,1,1);
    Avion4.displayInfoAvion();

    AvionDeLigne Avion5("Boeing 790", 100, 900, 14000, 350 ,12000, 1,1,2021, "France", &maCompagnie, 1,1,1);
    Avion5.displayInfoAvion();

    Aeroport aeroportDeParis("Aéroport International de Paris", "144 rue de chennviere", 3 );

    Aeroport aeroportDeLondre("Aéroport International de Londre", "54 avenue of Boston", 2);

    Aeroport aeroportDeBerlin("Aéroport International de Berlin", "54 avenue of Boston", 2);

    aeroportDeParis.displayInfoAeroport();

    aeroportDeLondre.displayInfoAeroport();

    aeroportDeBerlin.displayInfoAeroport();





    return 0;
}