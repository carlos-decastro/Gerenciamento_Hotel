#include <iostream>
#include "Cliente.hpp"
#include "Quarto.hpp"
#include "Hotel.hpp"
using namespace std;

/*
Atividade prática realizada por:
    CARLOS RICARDO DE CASTRO JUNIOR
    MARIA LUIZA CARVALHO DE OLIVEIRA
*/


int main() {

    int menu = -1;
    //case 1
    string nomeCliente, cpfCliente;

    //case 3
    int numQuarto, d, m, previsaoEstadia;
    string nomeHospede, funcionario;

    //case 5
    string userEdit, campoEdit;

    Hotel hotel;

    hotel.adicionaQuartos();

    while (menu != 0){

        cout << "\n============================================\n";
        cout << "Hotel Tabajara"; 
        cout << "\n============================================\n\n";

        cout <<  "Menu\n";

        cout << "1) Cadastro de Clientes\n";
        cout << "2) Quartos disponiveis\n";
        cout << "3) Reserva de Quartos\n";
        cout << "4) Reservas por clientes\n";
        cout << "5) Ver/Editar clientes\n";
        cout << "6) Relatório detalhado\n";
        cout << "0) Encerrar programa\n\n";
        cout << "Escolha uma opção: ";
        cin >> menu;

        switch (menu) {
            case 0:
                cout << "Programa encerrado.";
                break;

            case 1: 
                cout << "\nCadastro de Clientes\n";
                    cout << "\nNome: ";
                    cin >> nomeCliente;
                    
                    cout << "CPF: ";
                    cin >> cpfCliente;

                hotel.adicionaClientes(nomeCliente, cpfCliente);
                break;

            case 2:
                cout << "Quartos disponiveis:\n\n";
                hotel.quartosDisponiveis();    
                break;

            case 3: 
                cout << "Reserva:\n\n";
                cout << "Quartos disponiveis:\n";
                hotel.quartosDisponiveis();    

                cout << "\nQuarto: ";
                cin >> numQuarto;

                cout << "Hospede: ";
                cin >> nomeHospede;

                cout << "Data de entrada: \n";
                cout << "   Dia: ";
                cin >> d;
                cout << "   Mês: ";
                cin >> m;
                cout << "Total de dias de estadia: ";
                cin >> previsaoEstadia;
                cout << "Funcionário responsavel pela reserva: ";
                cin >> funcionario;

                hotel.reserva(numQuarto, nomeHospede, d, m, previsaoEstadia, funcionario);
                break;  

            case 4:
                cout << "Total de reservas por clientes: \n\n";
                hotel.totalReservasClientes();
                break;      

            case 5:
                hotel.verClientes();
                cout << "Digite 0 para voltar ao meu inicial";
                cout << endl;
                cout << "\nSelecione o usuario que deseja editar: ";
                cin >> userEdit;
                
                if (userEdit == "0"){
                    break;
                }

                cout << "Digite o campo que seja editar: ";
                cin >> campoEdit;

                if (campoEdit == "0"){
                    break;
                }

                hotel.editaCliente(userEdit, campoEdit);
                break;   

            case 6:
                hotel.relatorioDetalhado();
                break;    
        }
    }
}


/*
Cliente POO;
Quarto A;
Hotel h;

    //CLIENTE TOTALMENTE FUNCIONAL
	POO.setNome("JR");
    POO.setCpf("030.099.910-02");

	cout << POO.getNome() << " | " <<POO.getCpf() << " | "  << POO.getQtdReservas() << endl << endl;

    A.setNumeroQuarto(101);
    A.setStatusQuarto("Reservado");
    A.setQtdCamas(2);
    A.setTipo("Luxo");
    A.setFuncionarioReserva("Maria");
    A.setNomeReserva("JR");

    cout << A.getStatusQuarto() << " | " << A.getNumeroQuarto() << " | " << A.getTipo() << " | " << A.getQtdCamas() << " | " << A.getNomeReserva() << " | " << A.getFuncionarioReserva() << endl << endl;

    h.adicionaQuartos();
    h.totalQuartos();
*/