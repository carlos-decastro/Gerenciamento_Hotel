#include "Quarto.hpp"

void Quarto::setStatusQuarto(string statusQuarto){
    this->statusQuarto = statusQuarto;
}

void Quarto::setNumeroQuarto(int numeroQuarto){
    this->numeroQuarto = numeroQuarto;
}

void Quarto::setQtdCamas(int qtdCamas){
    this->qtdCamas = qtdCamas;
}

void Quarto::setTipo(string tipo){
    this->tipo = tipo;
}

void Quarto::setNomeReserva(string nomeCliente){
    this->nomeReserva = nomeCliente;
}

void Quarto::setFuncionarioReserva(string funcionarioReserva){
    this->funcionarioReserva = funcionarioReserva;
}

void Quarto::setDia(int dia){
    this->dia = dia;
}
    
void Quarto::setMes(int mes){
    this->mes = mes;
}

void Quarto::setPrevisaoEstadia(int previsaoEstadia){
    this->previsaoEstadia = previsaoEstadia;
}

void Quarto::camasPorTipo(){
    if (qtdCamas == 1) {
        cout << qtdCamas << " | " << "Cama de Casal";
    }

    else {
        cout << qtdCamas << " | " << "Camas de Solteiro";
    }
}