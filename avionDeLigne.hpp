#ifndef DEF_AVIONDELIGNE
#define DEF_AVIONDELIGNE
#include <string> 
#include <vector>
#include <ctime>
#include <iostream>
#include "avion.hpp"



class AvionDeLigne : public Avion {
private:
    int placeBusiness;
    int placeEconomie;
    int placeFirstClasse;

public:
    AvionDeLigne(std::string _nomModele, int _capacite, double _vitesseMoy, 
                 double _altitudeMoy, double _poids, double _distanceMax,
                 int jour, int mois, int annee, std::string _pays, Compagnie* _compagnie, 
                 int _placeBusiness, int _placeEconomie, int _placeFirstClasse) 
        : Avion(_nomModele, _capacite, _vitesseMoy, _altitudeMoy, _poids, _distanceMax, jour, mois, annee, _pays, _compagnie),
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

    virtual void displayInfoAvion() const override;
};

#endif
