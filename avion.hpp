#ifndef DEF_AVION
#define DEF_AVION
#include <string> 
#include <vector>
#include <iostream>


class Avion {
private:
    std::string nomModele; 
    int capacite;
    double vitesseMoy;
    double altitudeMoy;
    double poids;
    double distanceMax;
    std::string dateService;
    std::string pays;

public:
    Avion(std::string _nomModele, int _capacite, double _vitesseMoy, 
          double _altitudeMoy, double _poids, double _distanceMax,
          std::string _dateService, std::string _pays)
        : nomModele(_nomModele), capacite(_capacite), vitesseMoy(_vitesseMoy),
          altitudeMoy(_altitudeMoy), poids(_poids), distanceMax(_distanceMax),
          dateService(_dateService), pays(_pays) {

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

              if (_dateService.length() > 10  ){
                std::cerr << "dateService incorrecte" << std::endl;
                dateService = "date inconnue";
              }else{
                dateService = _dateService;
              }

              if (_pays.length() > 30 ){
                std::cerr << "Max 30 caracteres pays" << std::endl;
                pays = "Pays inconnu";
              }else{
                pays = _pays;
              }       
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

    void setDateService(const std::string _dateNaissance);
    std::string getDateService() const;

    void setPays(const std::string _pays);
    std::string getPays() const;
    
    void displayInfoAvion() const;
};

class AvionDeLigne : public Avion {
private:
    int placeBusiness;
    int placeEconomie;
    int placeFirstClasse;

public:
    AvionDeLigne(std::string _nomModele, int _capacite, double _vitesseMoy, 
                 double _altitudeMoy, double _poids, double _distanceMax,
                 std::string _dateService, std::string _pays, 
                 int _placeBusiness, int _placeEconomie, int _placeFirstClasse) 
        : Avion(_nomModele, _capacite, _vitesseMoy, _altitudeMoy, _poids, _distanceMax, _dateService, _pays),
          placeBusiness(_placeBusiness), placeEconomie(_placeEconomie), placeFirstClasse(_placeFirstClasse) {

            if (_placeBusiness < 0){
                std::cerr << "PlaceBusiness doit etre > 0" << std::endl;
                placeBusiness = 0;
            }else{
                placeBusiness = _placeBusiness;
            }

            if (_placeEconomie < 0){
                std::cerr << "PlaceEconomie doit etre > 0" << std::endl;
                placeEconomie = 0;
            }else{
                placeEconomie = _placeEconomie;
            }

            if (_placeFirstClasse < 0){
                std::cerr << "PlaceBFirstClasse doit etre > 0" << std::endl;
                placeFirstClasse = 0;
            }else{
                placeFirstClasse = _placeFirstClasse;
            }          
          }

    void setPlaceBusiness(int _placeBusiness);
    int getPlaceBusiness() const;

    void setPlaceEconomie(int _placeEconomie);
    int getPlaceEconomie() const;

    void setPlaceFirstClasse(int _placeFirstClasse);
    int getPlaceFirstClasse() const;

    void displayInfoLigne() const;
};



class JetPrive : public Avion {

    private:
        int nombreSalon;
        int nombreBar;
        int nombreJacuzzi;

    public:

    JetPrive(std::string _nomModele, int _capacite, double _vitesseMoy, 
                 double _altitudeMoy, double _poids, double _distanceMax,
                 std::string _dateService, std::string _pays,
                 int _nombreSalon, int _nombreBar, int _nombreJacuzzi)   
        : Avion(_nomModele, _capacite, _vitesseMoy, _altitudeMoy, _poids, _distanceMax, _dateService, _pays),
          nombreSalon(_nombreSalon), nombreBar(_nombreBar), nombreJacuzzi(_nombreJacuzzi) {

            if (_nombreSalon < 0){
                std::cerr << "nombreSalon doit etre > 0" << std::endl;
                nombreSalon = 0;
            }else{
                nombreSalon = _nombreSalon;
            }

            if (_nombreBar < 0){
                std::cerr << "nombreBar doit etre > 0" << std::endl;
                nombreBar = 0;
            }else{
                nombreBar = _nombreBar;
            }

            if (_nombreJacuzzi < 0){
                std::cerr << "nombreJacuzzi doit etre > 0" << std::endl;
                nombreJacuzzi = 0;
            }else{
                nombreJacuzzi = _nombreJacuzzi;
            }
          }
        
    void setNombreSalon(int _nombreSalon);
    int getNombreSalon() const;

    void setNombreBar(int _nombreBar);
    int getNombreBar() const;

    void setNombreJacuzzi(int _nombreJacuzzi);
    int getNombreJacuzzi() const;

    void displayInfoJet() const;
};
#endif
