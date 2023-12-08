#ifndef  DEF_VOL
#define DEF_VOL

#include <string>
#include <ctime>
#include "client.hpp"
#include <vector>
#include <algorithm>

class Vol{
    private:
        int idVol;
        tm dateDepart;
        tm dateArrivee;
        std::string aeroportDepart;
        std::string aeroportArrivee;
        int nombrePlaces;
        double prix;
        int terminalDepart;
        int terminalArrivee;
        std::vector <Client> clients;

    public:
        Vol(int _idVol, int jourDepart, int moisDepart, int anneeDepart,int jourArrivee, int moisArrivee, int anneeArrivee, std::string _aeroportDepart, std::string _aeroportArrivee, int _nombrePlaces, double _prix, int _terminalDepart, int _terminalArrivee);

        void setIdVol(int _idVol);
        int getIdVol() const;  

        void setDateDepart(int annee, int mois, int jour);
        std::string getDateDepart() const; 

        void setDateArrivee(int annee, int mois, int jour);
        std::string getDateArrivee() const; 

        void setAeroportDepart(std::string _aeroportDepart);
        std::string getAeroportDepart() const;

        void setAeroportArrivee(std::string _aeroportArrivee);
        std::string getAeroportArrivee() const; 

        void setNombrePlaces(int _nombrePlaces);
        int getNombrePlaces() const;

        void setPrix(double _prix);
        double getPrix() const;

        void setTerminalDepart(int _terminalDepart);
        int getTerminalDepart() const;

        void setTerminalArrivee(int _terminalArrivee);
        int getTerminalArrivee() const;  

        void addClient(Client _client);
        void removeClient(Client _client);

        void displayInfoVol() const;
};
#endif