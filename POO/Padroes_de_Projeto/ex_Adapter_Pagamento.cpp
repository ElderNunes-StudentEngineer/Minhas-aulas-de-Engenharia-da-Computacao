#include<iostream>

using namespace std;

//Target
class PagamentoOnline{
    public:
        virtual void processaPagamento(string cliente ,double valor) = 0;

        ~PagamentoOnline(){
        cout<<"Objeto Target destruído com sucesso!"<<endl;
        }
};

//Adaptee
class SistemaAntigoPagamento{
    public:
        void realizarCobranca(string cliente, double quantia){
            cout<<"Cobrando "<< quantia<<" reais do cliente: "<< cliente<<endl;
        }

        ~SistemaAntigoPagamento() {
            cout << "Objeto Adaptee destruído com sucesso!" << endl;
        }
};

//Adapter
class PagamentoAdapter : public PagamentoOnline{
    private:
        SistemaAntigoPagamento* antigo;
    public:
        PagamentoAdapter(SistemaAntigoPagamento* antigo){
            this->antigo = antigo;
        }

        void processaPagamento(string cliente ,double valor) override{
            cout<<"Adaptando pagamento para o sistema antigo"<<endl;
            this->antigo->realizarCobranca(cliente, valor);
        }

        ~PagamentoAdapter() {
            cout << "Objeto Adapter destruído com sucesso!" << endl;
        }

};

int main(void){
    SistemaAntigoPagamento* antigo = new SistemaAntigoPagamento();
    PagamentoOnline* online = new PagamentoAdapter(antigo);

    online->processaPagamento("Daniel Elder", 150.00);

    delete online;
    delete antigo;
    return 0;
}