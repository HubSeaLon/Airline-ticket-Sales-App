#ifndef DEF_AVION
#define DEF_AVION
#include <string> 
#include <vector>
#include <iostream>
#include <ctime>
#include "compagnie.hpp"
#include "vol.hpp"



class Avion {

protected:
    std::string nomModele; 
    int capacite;
    double vitesseMoy;
    double altitudeMoy;
    double poids;
    double distanceMax;
    tm dateService;
    std::string pays;
    Compagnie* compagnie;
    Vol* vol;



public:
    Avion(std::string _nomModele, int _capacite, double _vitesseMoy, 
          double _altitudeMoy, double _poids, double _distanceMax,
          int jour, int mois, int annee, std::string _pays, Compagnie* _compagnie, Vol* _vol)
        : nomModele(_nomModele), capacite(_capacite), vitesseMoy(_vitesseMoy),
          altitudeMoy(_altitudeMoy), poids(_poids), distanceMax(_distanceMax),
          pays(_pays), compagnie(_compagnie), vol(_vol) {

        dateService.tm_mday = jour;
        dateService.tm_mon = mois - 1;
        dateService.tm_year = annee - 1900;

        if (_capacite < 0){
                std::cerr << "Capacite doit etre > 0" << std::endl; 
                capacite = 0;
              }else{
                capacite = _capacite;      
              }

              if (_vitesseMoy < 0){
                std::cerr << "VitesseMoy doit etre > 0" << std::endl; 
                vitesseMoy = 0.0;
              }else{
                vitesseMoy = _vitesseMoy;      
              }

              if (_altitudeMoy < 0){
                std::cerr << "altitudeMoy doit etre > 0" << std::endl; 
                altitudeMoy = 0.0;
              }else{
                altitudeMoy = _altitudeMoy;      
              }

              if (_poids < 0){
                std::cerr << "Poids doit etre > 0" << std::endl; 
                poids = 0.0;
              }else{
                poids = _poids;      
              }

              if (_distanceMax < 0){
                std::cerr << "distanceMax doit etre > 0" << std::endl; 
                distanceMax = 0;
              }else{
                distanceMax = _distanceMax;      
              }

              if (_nomModele.length() > 50 ){
                std::cerr << "Max 50 caracteres nomModele" << std::endl;
                nomModele = "Modele inconnu";
              }else{
                nomModele = _nomModele;
              }

              if (_pays.length() > 30 ){
                std::cerr << "Max 30 caracteres pays" << std::endl;
                pays = "Pays inconnu";
              }else{
                pays = _pays;
              }       
        }


    ~Avion(){
      // Destruction de l'avion entraine la destruction du vol 
    } 
    

    void setNomModele(const std::string _nomModele);
    std::string getNomModele() const;

    void setCapacite(int _capacite);
    int getCapacite() const;

    void setVitesseMoy(double _vitesseMoy);
    double getVitesseMoy() const;

    void setAltitudeMoy(double _altitudeMoy);
    double getAltitudeMoy() const;

    void setPoids(double _poids);
    double getPoids() const;

    void setDistanceMax(double _distanceMax);
    double getDistanceMax() const;

    void setDateService(int jour, int mois, int annee);
    std::string getDateService() const;

    void setPays(const std::string _pays);
    std::string getPays() const;
    
    virtual void displayInfoAvion() const = 0 ;
};
#endif
