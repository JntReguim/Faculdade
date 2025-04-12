// Bibliotecas
#include <iostream>

class Conta {
  protected:
    double saldo;

  public:
    Conta(double saldo = 0) : saldo(saldo) {}

    void debitar(double valor) {
        if(valor > 0 && valor <= saldo) {
            saldo -= valor;
            std::cout << "Débito de R$" << valor << " realizado com sucesso."
                      << std::endl;
        }
        else {
            std::cout << "Erro: Valor de débito inválido." << std::endl;
        }
    }

    void creditar(double valor) {
        if(valor > 0) {
            saldo += valor;
            std::cout << "Crédito de R$" << valor << " realizado com sucesso."
                      << std::endl;
        }
        else {
            std::cout << "Erro: Valor de crédito inválido." << std::endl;
        }
    }

    double getSaldo() const { return saldo; }

    void setSaldo(double novoSaldo) {
        if(novoSaldo >= 0) {
            saldo = novoSaldo;
            std::cout << "Saldo atualizado com sucesso." << std::endl;
        }
        else {
            std::cout << "Erro: Saldo não pode ser negativo." << std::endl;
        }
    }

    void printInfo() const { std::cout << "Saldo: R$" << saldo << std::endl; }
};

class Poupanca : public Conta {
  private:
    double juros;

  public:
    Poupanca(double saldo = 0, double juros = 0.02)
        : Conta(saldo), juros(juros) {}

    double calcularJuros() const { return saldo * juros; }

    void printInfo() const {
        Conta::printInfo();
        std::cout << "Juros: " << juros * 100 << "%" << std::endl;
    }
};

class ContaCorrente : public Conta {
  private:
    double taxaTransacao;

  public:
    ContaCorrente(double saldo = 0, double taxaTransacao = 0.01)
        : Conta(saldo), taxaTransacao(taxaTransacao) {}

    void debitar(double valor) {
        double taxaDebito = valor * taxaTransacao;
        double valorTotal = valor + taxaDebito;
        Conta::debitar(valorTotal);
        std::cout << "Taxa de débito de R$" << taxaDebito << " aplicada."
                  << std::endl;
    }

    void creditar(double valor) {
        double taxaCredito = valor * taxaTransacao;
        double valorTotal = valor - taxaCredito;
        Conta::creditar(valorTotal);
        std::cout << "Taxa de crédito de R$" << taxaCredito << " aplicada."
                  << std::endl;
    }

    void printInfo() const {
        Conta::printInfo();
        std::cout << "Taxa de transação: " << taxaTransacao * 100 << "%"
                  << std::endl;
    }
};

int main() {
    // Exemplo de uso:

    // Criar uma conta poupança
    Poupanca contaPoupanca(1000);

    // Realizar operações na conta poupança
    contaPoupanca.printInfo();
    contaPoupanca.creditar(500);
    contaPoupanca.debitar(200);
    std::cout << "Juros auferidos: R$" << contaPoupanca.calcularJuros()
              << std::endl;
    contaPoupanca.printInfo();

    // Criar uma conta corrente
    ContaCorrente contaCorrente(2000);

    // Realizar operações na conta corrente
    contaCorrente.printInfo();
    contaCorrente.debitar(300);
    contaCorrente.creditar(1000);
    contaCorrente.printInfo();

    return 0;
}