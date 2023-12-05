#ifndef  DEF_BILLET
#define DEF_BILLET

#include <string>

class Billet{
    private:
        int numeroBillet;
        std::string dateVol;
        std::string paysDepart;
        std::string paysArrivee;
        double prix;
        std::string typeClasse;
        int terminalDepart;
        int terminalArrivee;
        int siegePassager;
    
    public:
        Billet(int _numeroBillet, std::string _date, std::string _paysDepart, std::string _paysArrivee, double _prix, std::string _typeClasse, int _terminalDepart, int _terminalArrivee, int _siegePassager);

        void setNumeroBillet(int _numeroBillet);
        int getNumeroBillet() const;


        void setDateVol(std::string _date);
        std::string getDateVol() const;


        void setPaysDepart(std::string _paysDepart);
        std::string getPaysDepart() const;

        void setPaysArrivee(std::string _paysArrivee);
        std::string getPaysArrivee() const;
        
        void setPrix(double _prix);
        double getPrix() const;

        void setTypeClasse(std::string _typeClasse);
        std::string getTypClasse() const;

        void setTerminalDepart(int _terminalDepart);
        int getTerminalDepart() const;

        void setTerminalArrivee(int _terminalArrivee);
        int getTerminalArrivee() const;

        void setSiegePassager(int _siegePassager);
        int getSiegePassager() const;

        void displayInfoBillet() const;
};

#endif