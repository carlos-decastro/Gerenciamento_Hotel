#ifndef Cliente_hpp
#define Cliente_hpp

#include <iostream>
using namespace std;

class Cliente {

public: 
    Cliente(){};
    Cliente(string nomeCliente, string cpf);
    
    void setNome(string nomeCliente);
    void setCpf(string cpf);
    void setQtdReservas();
    void ajusteReservas(int reservas);
  
    string getNome(){return nomeCliente;};
    string getCpf(){return cpf;};
    int getQtdReservas(){return qtdReservas;};

private:

    string nomeCliente;
    string cpf;
    int qtdReservas = 0;        
};

#endif