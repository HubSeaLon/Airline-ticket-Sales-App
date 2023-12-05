#include <iostream>
#include "client.hpp"

Client::Client(int _numeroClient, std::string _nom, std::string _prenom, std::string _date, std::string _adresse, int _numeroTel, std::string _mail){
    numeroClient = _numeroClient;
    nom = _nom;
    prenom = _prenom;
    dateNaissance = _date;
    adresse = _adresse;
    numeroTel = _numeroTel;
    mail = _mail;
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

void Client::setDateNaissance(std::string _date){
    dateNaissance = _date;
}
std::string Client::getDateNaissance() const{
    return dateNaissance;
}

void Client::setAdresse(std::string _adresse){
    adresse = _adresse;
}
std::string Client::getAdresse() const{
    return adresse;
}

void Client::setNumeroTel(int _numeroTel){
    numeroTel = _numeroTel;
}
int Client::getNumeroTel() const{
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