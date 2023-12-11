#ifndef DEF_JET
#define DEF_JET
#include <string> 
#include <vector>
#include <iostream>
#include <ctime>
#include "avion.hpp"


class JetPrive : public Avion {

    private:
        int nombreSalon;
        int nombreBar;
        int nombreJacuzzi;

    public:

    JetPrive(std::string _nomModele, int _capacite, double _vitesseMoy, 
                 double _altitudeMoy, double _poids, double _distanceMax,
                 int jour, int mois, int annee, std::string _pays, Compagnie* _compagnie,
                 int _nombreSalon, int _nombreBar, int _nombreJacuzzi)   
        : Avion(_nomModele, _capacite, _vitesseMoy, _altitudeMoy, _poids, _distanceMax, jour, mois, annee, _pays, _compagnie),
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

    virtual void displayInfoAvion() const override;
};
#endif