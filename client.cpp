#include <iostream>
#include "client.hpp"

Client::Client(int _numeroClient, std::string _nom, std::string _prenom, int jourNaissance, int moisNaissance, int anneeNaissance, std::string _adresse, std::string _numeroTel, std::string _mail){
    numeroClient = _numeroClient;
    nom = _nom;
    prenom = _prenom;
    adresse = _adresse;
    numeroTel = _numeroTel;
    mail = _mail;

    dateNaissance.tm_mday = jourNaissance;
    dateNaissance.tm_mon = moisNaissance - 1;
    dateNaissance.tm_year = anneeNaissance - 1900;
}

void Client::setNumeroClient(int _numeroClient){
    numeroClient = _numeroClient;
}
int Client::getNumeroClient() const{
    return numeroClient;
}

void Client::setNom(std::string _nom){
    nom = _nom;
}
std::string Client::getNom() const{
    return nom;
}

void Client::setPrenom(std::string _prenom){
    prenom = _prenom;
}
std::string Client::getPrenom() const{
    return prenom;
}

void Client::setDateNaissance(int jourNaissance, int moisNaissance, int anneeNaissance){
    dateNaissance.tm_mday = jourNaissance;
    dateNaissance.tm_mon = moisNaissance - 1;
    dateNaissance.tm_year = anneeNaissance - 1900;
}
std::string Client::getDateNaissance() const{
    char buffer[80];
    std::strftime(buffer, sizeof(buffer), "%d-%m-%Y", &dateNaissance);
    return std::string(buffer);
}

void Client::setAdresse(std::string _adresse){
    adresse = _adresse;
}
std::string Client::getAdresse() const{
    return adresse;
}

void Client::setNumeroTel(std::string _numeroTel){
    numeroTel = _numeroTel;
}
std::string Client::getNumeroTel() const{
    return numeroTel;
}

void Client::setMail(std::string _mail){
    mail = _mail;
}
std::string Client::getMail() const{
    return mail;
}

void Client::displayInfoClient() const{
    std::cout<<"Numero client: "<<getNumeroClient()<<std::endl;
    std::cout<<"Nom: "<<getNom()<<std::endl;
    std::cout<<"Prenom: "<<getPrenom()<<std::endl;
    std::cout<<"Date de naissance: "<<getDateNaissance()<<std::endl;
    std::cout<<"Adresse: "<<getAdresse()<<std::endl;
    std::cout<<"Numero de telephone: "<<getNumeroTel()<<std::endl;
    std::cout<<"Mail: "<<getMail()<<std::endl;
}

void Client::affiche() const{
    std::cout<<getNom()<<" "<<getPrenom()<<std::endl;
}
