#include "Hotel.hpp"

void Hotel::adicionaQuartos(){
    int j = 101;
    int l = 201;

    for (int i=0 ; i < 12; i++){
        if (i <= 2){
            quartos[i].setStatusQuarto("Livre");
            quartos[i].setNumeroQuarto(j);
            quartos[i].setTipo("Simples");
            quartos[i].setQtdCamas(1);
            j++;
        }
        if (i >= 3 && i <= 5){
            quartos[i].setStatusQuarto("Livre");
            quartos[i].setNumeroQuarto(j);
            quartos[i].setTipo("Simples");
            quartos[i].setQtdCamas(2);
            j++;
        }

        if (i >= 6 && i <= 8){
            quartos[i].setStatusQuarto("Livre");
            quartos[i].setNumeroQuarto(l);
            quartos[i].setTipo("Luxo");
            quartos[i].setQtdCamas(1);
            l++;
        }

        if (i >= 9){
            quartos[i].setStatusQuarto("Livre");
            quartos[i].setNumeroQuarto(l);
            quartos[i].setTipo("Luxo");
            quartos[i].setQtdCamas(2);
            l++;
        }
    } 
}

void Hotel::totalQuartos(){
    for (int i = 0; i < 12; i++){
        cout << quartos[i].getStatusQuarto() << " | " << quartos[i].getNumeroQuarto() << " | " << quartos[i].getQtdCamas() << " | " <<quartos[i].getTipo() << endl;
    }
}

void Hotel::adicionaClientes(string nomeCliente, string cpfCliente){
    clientes.push_back(Cliente(nomeCliente, cpfCliente));
}

void Hotel::verClientes(){
    cout << endl;
    for (int i = 0; i < clientes.size(); i++){
        cout << "Nome: "<< clientes[i].getNome() << endl << "CPF: " << clientes[i].getCpf() << endl << "Quantidade de reservas: " << clientes[i].getQtdReservas() << endl << endl; 
    }
}

void Hotel::quartosDisponiveis(){
    for (int i = 0; i <= 12; i++){
        if (quartos[i].getStatusQuarto() == "Livre"){
            if (quartos[i].getNumeroQuarto() < 200){
                cout << quartos[i].getStatusQuarto() << " | " << quartos[i].getNumeroQuarto() << " | " << quartos[i].getTipo() << " | "; 
                quartos[i].camasPorTipo(); 
                cout << endl;
            }
            else {
                cout << quartos[i].getStatusQuarto() << " | " << quartos[i].getNumeroQuarto() << " | " << quartos[i].getTipo() << "    | "; 
                quartos[i].camasPorTipo(); 
                cout << endl;
            }
        }
    }
}

void Hotel::reserva(int numQuarto, string nomeHospede, int d, int m, int previsaoEstadia, string funcionario){
    bool validaCliente = false;
    bool cadastroOK = false;
    bool quartoEncontrado = false;
    bool quartoDisponivel = false;

    for (int i = 0; i < clientes.size(); i++){
        if (clientes[i].getNome() == nomeHospede){
            clientes[i].setQtdReservas(); 
            validaCliente = true;
        }
    }

    while (validaCliente != true) {
        cout << "Cliente não encontrado, favor digitar novamente: ";
        cin >> nomeHospede;

        for (int i = 0; i < clientes.size(); i++){
            if (clientes[i].getNome() == nomeHospede){
                clientes[i].setQtdReservas(); 
                validaCliente = true;
            }
        }
    }

    for (int i = 0; i <= 12 ; i++){
        if (quartos[i].getNumeroQuarto() == numQuarto){
            quartoEncontrado = true;
            if (quartos[i].getStatusQuarto() == "Livre"){
                quartos[i].setNomeReserva(nomeHospede);
                quartos[i].setStatusQuarto("Reservado");
                quartos[i].setDia(d);
                quartos[i].setMes(m);
                quartos[i].setPrevisaoEstadia(previsaoEstadia);
                quartos[i].setFuncionarioReserva(funcionario);
                quartoDisponivel = true;
                cadastroOK = true;
            }
            else {
                quartoEncontrado = false;
            }
        }
    }

    while (quartoEncontrado != true) {
        cout << "Quarto não encontrado, ou já reservado/ocupado, favor escolher novamente: ";
        cin >> numQuarto;
    
        for (int i = 0; i <= 12 ; i++){
            if (quartos[i].getNumeroQuarto() == numQuarto){
                quartoEncontrado = true;
                if (quartos[i].getStatusQuarto() == "Livre"){
                    quartos[i].setNomeReserva(nomeHospede);
                    quartos[i].setStatusQuarto("Reservado");
                    quartos[i].setDia(d);
                    quartos[i].setMes(m);
                    quartos[i].setPrevisaoEstadia(previsaoEstadia);
                    quartos[i].setFuncionarioReserva(funcionario);
                    quartoDisponivel = true;
                    cadastroOK = true;
                }
                else {
                    quartoEncontrado = false;
                }
            }
        }      
    }

    if (cadastroOK == true){
        cout << "\nReserva realizada com sucesso\n";
    }   
}

void Hotel::totalReservasClientes(){
    for (int i = 0; i < clientes.size(); i++){
        cout << "Nome: " << clientes[i].getNome() << endl;
        cout << "Reservas: " << clientes[i].getQtdReservas() << endl << endl;
    }
}

void Hotel::editaCliente(string userEdit, string campoEdit){
    string nome, cpf;
    int reservas;
    bool updateOK = false;

    for (int i = 0; i < clientes.size(); i++){
        if (userEdit == clientes[i].getNome()){
            if (campoEdit == "Nome" || campoEdit == "nome" || campoEdit == "NOME"){
                cout << "Nome: ";
                cin >> nome;
                clientes[i].setNome(nome);
                cout << "Alteração realizada com sucesso!";
                updateOK = true;
            }

            if (campoEdit == "CPF" || campoEdit == "Cpf" || campoEdit == "cpf"){
                cout << "CPF: ";
                cin >> cpf;
                clientes[i].setCpf(cpf);
                cout << "Alteração realizada com sucesso!";
                updateOK = true;
            }

            if (campoEdit == "reservas" || campoEdit == "Reservas" || campoEdit == "reservas"){
                cout << "Total de reservas: ";
                cin >> reservas;
                clientes[i].ajusteReservas(reservas);
                cout << "Alteração realizada com sucesso!";
                updateOK = true;
            }
        }
    }

    while (updateOK != true){
        cout << "Nome ou campo não encontrado, favor tentar novamente: \n";
        cout << "Nome: ";
        cin >> userEdit;
        cout << "Campo: ";
        cin >> campoEdit; 

        for (int i = 0; i < clientes.size(); i++){
            if (userEdit == clientes[i].getNome()){
                if (campoEdit == "Nome" || campoEdit == "nome" || campoEdit == "NOME"){
                    cout << "Nome: ";
                    cin >> nome;
                    clientes[i].setNome(nome);
                    cout << "Alteração realizada com sucesso!";
                    updateOK = true;
                }

                if (campoEdit == "CPF" || campoEdit == "Cpf" || campoEdit == "cpf"){
                    cout << "CPF: ";
                    cin >> cpf;
                    clientes[i].setCpf(cpf);
                    cout << "Alteração realizada com sucesso!";
                    updateOK = true;
                }

                if (campoEdit == "reservas" || campoEdit == "Reservas" || campoEdit == "reservas"){
                    cout << "Total de reservas: ";
                    cin >> reservas;
                    clientes[i].ajusteReservas(reservas);
                    cout << "Alteração realizada com sucesso!";
                    updateOK = true;
                }
            }
        }
    }
}

void Hotel::relatorioDetalhado(){
    bool registrosEncontrados = false;
    for (int i = 0; i <= 11; i++){
        if (quartos[i].getStatusQuarto() != "Livre"){
            cout << "\nNome do Hospede: " << quartos[i].getNomeReserva() << endl;
            cout << "Quarto: " << quartos[i].getNumeroQuarto() << endl;
            cout << "Tipo: " << quartos[i].getTipo() << endl;
            cout << "Data da reserva: " << quartos[i].getDia() << "/" << quartos[i].getMes() << endl;
            cout << "Período: " << quartos[i].getPrevisaoEstadia() << " dias" << endl;
            cout << "Funcionário responsável pela reserva: " << quartos[i].getFuncionarioReserva() << endl;
            registrosEncontrados = true;
        }
    }

    if (registrosEncontrados != true){
        cout << "\nNenhum quarto reservado no momento.\n";
    }
}
