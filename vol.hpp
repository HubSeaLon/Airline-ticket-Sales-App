#ifndef  DEF_VOL
#define DEF_VOL

#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include "compagnie.hpp"
#include "aeroport.hpp"


class Vol{
    private:
        int idVol;
        static int dernierIdVol;
        tm dateDepart;
        tm dateArrivee;
        Aeroport* aeroportDepart;
        Aeroport* aeroportArrivee;
        int nombrePlaces;
        double prix;
        int terminalDepart;
        int terminalArrivee;
        Compagnie* compagnie;

    public:
        Vol(int jourDepart, int moisDepart, int anneeDepart,int jourArrivee, int moisArrivee, int anneeArrivee, Aeroport* _aeroportDepart, Aeroport* _aeroportArrivee, int _nombrePlaces, double _prix, int _terminalDepart, int _terminalArrivee, Compagnie* _compagnie);
        ~Vol(){
            // Vol sera détruit si l'avion associé au vol est détruit 
        }
        int getIdVol() const;  

        

        

        void setDateDepart(int annee, int mois, int jour);
        std::string getDateDepart() const; 

        tm getDateDepart1() const;

        void setDateArrivee(int annee, int mois, int jour);
        std::string getDateArrivee() const; 

        std::string getAeroportDepart() const;

        std::string getAeroportArrivee() const;

        void setNombrePlaces(int _nombrePlaces);
        int getNombrePlaces() const;

        void setPrix(double _prix);
        double getPrix() const;

        void setTerminalDepart(int _terminalDepart);
        int getTerminalDepart() const;

        void setTerminalArrivee(int _terminalArrivee);
        int getTerminalArrivee() const;  

        void displayInfoVol() const;
};

bool compareVols(const Vol& vol1, const Vol& vol2);

void afficherVolsTries(const std::vector<Vol>& vols);
#endif