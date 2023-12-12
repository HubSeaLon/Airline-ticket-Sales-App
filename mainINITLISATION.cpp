#include <iostream>
#include <string>
#include "Avion.cpp"
#include "jet.cpp"
#include "avionDeLigne.cpp"
#include "compagnie.cpp"
#include "aeroport.cpp"




int main(int argc, char const *argv[])
{

    // INITIALISATION DES COMPAGNIES 

    Compagnie AirFrance("Air France", 7, 10, 1933, "France", 33141567800LL, "airfrance@gmail.com", "www.airfrance.com");                  
    Compagnie DeltaAirLines("Delta Air Lines", 30, 05, 1924, "Etats-Unis", 18002211212LL, "deltaairlines@gmail.com", "deltaairlines.com");
    Compagnie Emirates("Emirates", 25, 03, 1985, "Emirates Arabes Unis", 971600555555LL, "emirates@gmail.com", "emirates.com");
    Compagnie Lufthansa("Lufthansa", 6, 01, 1953, "Allemagne", 496986799799LL, "lufthansa@gmail.com", "lufthansa.com");
    Compagnie QatarAirways("Qatar Airways", 22, 11, 1993, "Qatar", 97440226000LL, "quatar@gmail.com", "qatar.com");
   
    // INITLISATION DES AVIONS 

    AvionDeLigne Avion1("Boeing 737", 150, 900, 11000, 350, 5000, 1,1,2023, "France", &AirFrance, 20, 100, 30);
    AvionDeLigne Avion2("Boeing 430", 200, 1000, 12000, 400, 7000, 5,4,2022, "France", &Emirates, 20, 150, 30);
    AvionDeLigne Avion3("Boeing A380", 853, 900, 13100, 1235, 15200, 25,10,2007, "France", &DeltaAirLines, 98, 555, 14);
    AvionDeLigne Avion4("Boeing 777", 550, 905, 13100, 239.370, 15843, 7,6,1995, "Etats-Unis", &QatarAirways, 70, 430, 50);
    AvionDeLigne Avion5("Boeing 787", 330, 903, 13100, 118, 15372, 26, 10, 2011, "Etats-Unis", &Lufthansa, 48, 230, 52);
   
    JetPrive Jet1("Gulfstream G650", 19, 956, 15545, 24.5, 12964, 01,01,2012, "Etats-Unis", &DeltaAirLines, 1,1,1);
    JetPrive Jet2("Bombardier Global 7500", 19, 930, 15545, 24.5, 14264, 01,01,2018, "Canada", &Lufthansa, 1,2,1);
    JetPrive Jet3("Dassault Falcon 8X", 14, 900, 15545, 19.3, 11945, 01,01,2016, "France", &AirFrance ,1,1,2);
    JetPrive Jet4("Dassault Falcon 7X", 16, 1060, 15545, 31, 11000, 01,01,2007, "France", &Emirates, 1,1,1);
    JetPrive Jet5("Embraer Phenom 300", 10, 834, 13716, 9.585, 3650, 01, 01, 2009, "Bresil", &QatarAirways, 1, 0, 0);

    // INITLISATION DES AEROPORTS 

    Aeroport aeroportDeParis("Aeroport International de Paris", "144 rue de chennviere", 3 );
    Aeroport aeroportDeLondre("Aeroport International de Londre", "54 avenue of Boston", 2);
    Aeroport aeroportDeBerlin("Aroport International  de Berlin", "54 avenue of Boston", 2);

    // INITLISATION DES VOLS 

    return 0;
}
