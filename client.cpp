#include <iostream>
#include "client.hpp"

Client::Client(){

}

Client::Client(int _numeroClient, std::string _nom, std::string _prenom, std::string _dateNaissance, std::string _ville, std::string _numeroTel, std::string _mail){
    numeroClient = _numeroClient;
    nom = _nom;
    prenom = _prenom;
    dateNaissance = _dateNaissance;
    ville = _ville;
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

void Client::setDateNaissance(std::string _dateNaissance){
    dateNaissance = _dateNaissance;
}
std::string Client::getDateNaissance() const{
    return dateNaissance;
}

void Client::setVille(std::string _ville){
    ville = _ville;
}
std::string Client::getVille() const{
    return ville;
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
    std::cout << "-------------------------------------------------\n";
    std::cout << "Numero client          : "<<getNumeroClient()<<std::endl;
    std::cout << "Nom                    : "<<getNom()<<std::endl;
    std::cout << "Prenom                 : "<<getPrenom()<<std::endl;
    std::cout << "Date de naissance      : "<<getDateNaissance()<<std::endl;
    std::cout << "Ville                  : "<<getVille()<<std::endl;
    std::cout << "Numero de telephone    : "<<getNumeroTel()<<std::endl;
    std::cout << "Mail                   : "<<getMail()<<std::endl;
    std::cout << "-------------------------------------------------\n";
    std::cout << "\n";
    std::cout << "\n";
}

std::string Client::affiche() const{
    std::cout<<"Client: "<<getNom()<<" "<<getPrenom()<<std::endl;
}
