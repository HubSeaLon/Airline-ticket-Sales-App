#ifndef  DEF_CLIENT
#define DEF_CLIENT

#include <string>
#include <ctime>

class Client{
    private:
        int numeroClient;
        static int dernierNumClient;
        std::string nom;
        std::string prenom;
        tm dateNaissance;
        std::string adresse;
        std::string numeroTel;
        std::string mail;

    public:
        Client(std::string _nom, std::string _prenom, int jourNaissance, int moisNaissance, int anneeNaissance, std::string _adresse, std::string _numeroTel, std::string _mail);

        ~Client();

        //void setNumeroClient(int _numeroClient);
        int getNumeroClient() const;

        void setNom(std::string _nom);
        std::string getNom() const;

        void setPrenom(std::string _prenom);
        std::string getPrenom() const;

        void setDateNaissance(int jourNaissance, int moisNaissance, int anneeNaissance);
        std::string getDateNaissance() const;

        void setAdresse(std::string _adresse);
        std::string getAdresse() const;

        void setNumeroTel(std::string _numeroTel);
        std::string getNumeroTel() const;

        void setMail(std::string _mail);
        std::string getMail() const;

        void displayInfoClient() const;

        void affiche() const;

        bool estEgale(Client _client);
};
bool operator==(Client client1,Client client2);

#endif