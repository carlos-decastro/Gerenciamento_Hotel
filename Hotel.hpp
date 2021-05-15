#ifndef Hotel_hpp
#define Hotel_hpp

#include <iostream>
#include <vector>
#include "Cliente.hpp"
#include "Quarto.hpp"

using namespace std;

class Hotel {

public: 

    Hotel(){};

    void adicionaQuartos();
    void totalQuartos();
    void totalReservasClientes();

    void adicionaClientes(string nomeCliente, string cpfCliente);
    void verClientes();
    void quartosDisponiveis();
    void reserva(int numQuarto, string nomeHospede, int d, int m, int previsaoEstadia, string funcionario);
    void editaCliente(string userEdit, string campoEdit);
    void relatorioDetalhado();
    
private:

    vector<Cliente> clientes;
    Quarto quartos[12];
};

#endif