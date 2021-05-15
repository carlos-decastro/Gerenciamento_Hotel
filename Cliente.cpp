#include "Cliente.hpp"

Cliente::Cliente (string nomeCliente, string cpf){
    this->nomeCliente = nomeCliente;
    this->cpf = cpf;
}

void Cliente::setNome(string nomeCliente){
	this->nomeCliente = nomeCliente;
}

void Cliente::setCpf(string cpf){
	this->cpf = cpf;
}

void Cliente::setQtdReservas(){
	qtdReservas = 1 + qtdReservas;
} 

void Cliente::ajusteReservas(int reservas){
    this->qtdReservas = reservas;
}
