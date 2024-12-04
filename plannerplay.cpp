#include <iostream>
#include <vector>
#include <string>

struct Funcionario {
    std::string nome;
    std::string endereco;
    std::string cargo;
    int tempoExpedie; // Em horas (expediente diário)
    double gastoPorHora;

};

int main(){
    std::vector<Funcionario> funcionarios;
    int quantidade;

    std::cout << "Quantos funcionários deseja cadastrar? ";
    std::cin >> quantidade;
    std::cin.ignore(); //Limpa buffer do 'cin'

    for (int i = 0; i < quantidade; ++i){
        Funcionario func;
        std::cout << "Digite os dados do funcionário" << (i + 1) << ":\n";

        //Nome
        std::cout << "Nome: ";
        std::getline(std::cin, func.nome);

        //Endereço
        std::cout << "Endereço: ";
        std::getline(std::cin, func.endereco);

        //Cargo
        std::cout << "Cargo: ";
        std::getline(std::cin, func.cargo);

        //Tempo de expediente
        std::cout << "Tempo de Expediente diário (em horas): ";
        std::cin >> func.tempoExpedie;

        // Gasto por hora trabalhada
        std::cout << "Gasto por hora trabalhada: ";
        std::cin >> func.gastoPorHora;

        std::cin.ignore(); // Limpa buffer do 'cin'

        funcionarios.push_back(func); // Adiciona o funcionário ao vetor

    }

    //Exibindo os dados armazenados e calculando gastos
    std::cout << "\nDados dos funcionários cadastrados:\n";
     for (const auto& func : funcionarios){
        double gastoSemanal = func.tempoExpedie * 5 * func.gastoPorHora; //5 dias úteis
        double gastoMensal = func.tempoExpedie * 22 * func.gastoPorHora; //22 dias úteis

    std::cout << "\n--- Funcionário ---\n";
    std::cout << "Nome: " << func.nome << "\n";
    std::cout << "Endereço: " << func.endereco << "\n";
    std::cout << "Cargo: " << func.cargo << "\n";
    std::cout << "Tempo de expediente diário: " << func.tempoExpedie << "horas\n";
    std::cout << "Gasto por horas trabalhada: R$ " << func.gastoPorHora << "\n";
    std::cout << "Gasto semanal: R$ " << gastoSemanal << "\n";
    std::cout << "Gasto mensal: R$ " << gastoMensal << "\n";
    }
    return 0;
}