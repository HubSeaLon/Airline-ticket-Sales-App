#include <iostream>
#include <string>
#include "Aeroport.hpp"
#include "Aeroport.cpp"



int main() {
    Aeroport aeroportDeParis("Aéroport International de Paris", "144 rue de chennviere", 3 );

    Aeroport aeroportDeLondre("Aéroport International de Londre", "54 avenue of Boston", 2);

    Aeroport aeroportDeBerlin("Aéroport International de Berlin", "54 avenue of Boston", 2);

    aeroportDeParis.displayInfoAeroport();

    aeroportDeLondre.displayInfoAeroport();

    aeroportDeBerlin.displayInfoAeroport();

    return 0;
}