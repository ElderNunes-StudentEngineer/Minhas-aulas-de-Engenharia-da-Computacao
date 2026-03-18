#include<iostream>

using namespace std;

class Atendente{
    private:
        string nome;
        string login;
    public:
        bool autenticar(string usuario, string senha){
            if(usuario == this->login && senha == true){
                return true;
            }else{
                return false;
            }
        }
};

class Quarto{
    private:
        string tipo;
        double valorDiaria;
    public:
        Quarto(string tipo, double valorDiaria){
            this->tipo = tipo;
            this->valorDiaria = valorDiaria;
        }
};

class ControladorReserva{ //Singleton
    private:
        static ControladorReserva* instance(void){
            if(!p){
                p = new ControladorReserva();
            }

            return p;
        }

        static void delInstance(void){
            if(p){
                delete p;
                p = 0;
            }

            cout<<"Singleton Finalizada!"<<endl;
        }
};

class DescontoStrategy{ //Strategy
    protected:
        double porcentagem;
    public:
        double calcularDesconto(double valor){}
};

class Reserva{
    private:
        int id;
        string localidade;
        Quarto quarto;
        int numDiarias;
        DescontoStrategy* desconto;
        Atendente atendente;
    public:
        double calcularValorTotal(){
            double valorBase, valorComDesconto;
            valorBase = quarto.valorDiaria * this->numDiarias;
            valorComDesconto = desconto->calcularDesconto(valorBase);
            return valorComDesconto;
        }
};

int main(void){



    return 0;
}