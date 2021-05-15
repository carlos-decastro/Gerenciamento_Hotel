#ifndef Quarto_hpp
#define Quarto_hpp

#include <iostream>
#include "Cliente.hpp"
using namespace std;

class Quarto {

public: 

    Quarto(){};
//    Quarto(string statusQuarto, int numeroQuarto, int qtdCamas, string tipo);
    
    void setStatusQuarto(string statusQuarto);
    void setNumeroQuarto(int numeroQuarto);
    void setQtdCamas(int qtdCamas);
    void setTipo(string tipo);   
    void setNomeReserva(string nomeCliente);
    void setFuncionarioReserva(string funcionarioReserva);
    void setDia(int dia);
    void setMes(int mes);
    void setPrevisaoEstadia(int previsaoEstadia);
    
    
    void camasPorTipo();
  
    string getStatusQuarto(){return statusQuarto;};
    int getNumeroQuarto(){return numeroQuarto;};
    int getQtdCamas(){return qtdCamas;};
    string getTipo(){return tipo;};
    string getNomeReserva(){return nomeReserva;};
    string getFuncionarioReserva(){return funcionarioReserva;};
    int getDia(){return dia;};
    int getMes(){return mes;};
    int getPrevisaoEstadia(){return previsaoEstadia;};

private:

    string statusQuarto;
    int numeroQuarto; 
    int qtdCamas; 
    string tipo; 
    string nomeReserva;
    string funcionarioReserva;
    int dia;
    int mes;
    int previsaoEstadia;
    
};

#endif
