#ifndef  DEF_BILLET
#define DEF_BILLET

#include <string>

class Billet{
    private:
        int numeroBillet;
        std::string typeClasse;
        int siegePassager;
        Vol* vol;
        Client* client;
    
    public:
        Billet(int _numeroBillet, std::string _typeClasse, int _siegePassager, Vol* _vol, Client* _client);

        void setNumeroBillet(int _numeroBillet);
        int getNumeroBillet() const;

        void setTypeClasse(std::string _typeClasse);
        std::string getTypClasse() const;

        void setSiegePassager(int _siegePassager);
        int getSiegePassager() const;

        void displayInfoBillet() const;
};

#endif