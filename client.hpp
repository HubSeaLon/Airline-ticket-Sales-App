#ifndef DEF_CLIENT
#define DEF_CLIENT

#include <string>

class Client{
    private:
        int numeroClient;
        std::string nom;
        std::string prenom;
        std::string dateNaissance;
        std::string ville;
        std::string numeroTel;
        std::string mail;

    public:
        Client();
        Client(int _numeroClient, std::string _nom, std::string _prenom, std::string _dateNaissance, std::string _ville, std::string _numeroTel, std::string _mail);

        void setNumeroClient(int _numeroClient);
        int getNumeroClient() const;

        void setNom(std::string _nom);
        std::string getNom() const;

        void setPrenom(std::string _prenom);
        std::string getPrenom() const;

        void setDateNaissance(std::string _dateNaissance);
        std::string getDateNaissance() const;

        void setVille(std::string _ville);
        std::string getVille() const;

        void setNumeroTel(std::string _numeroTel);
        std::string getNumeroTel() const;

        void setMail(std::string _mail);
        std::string getMail() const;

        void displayInfoClient() const;
};
#endif