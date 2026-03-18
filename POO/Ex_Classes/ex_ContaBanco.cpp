#include<iostream>

using namespace std;

class ContaBanco{
    private:
         float saldo;
         bool status;
         string dono;

    protected:
        string tipo;

    public:
        int numConta;

        ContaBanco(string dono, int numConta){
            this->dono = dono;
            this->numConta = numConta;
            this->saldo = 0;
            this->status = false;
            cout<<"Objeto criado com sucesso!"<<endl;
        };
        ~ContaBanco(){
            cout<<"Objeto destruído com sucesso!"<<endl;
        };    

        void abrirConta(string tipo){
            if(this->status){
                cout<<"Conta já está aberta!"<<endl;
                return;
            }

            this->tipo = tipo;
            this->status = true;

            if(tipo == "CC"){
                this->saldo = 150.00;
                cout<<"Conta corrente aberta com R$150.00 de bônus!"<<endl;
            }else if(tipo == "CP"){
                this->saldo = 50.00;
                cout<<"Conta corrente aberta com R$50.00 de bônus!"<<endl;
            }else{
                this->status = false;
                cout<<"Tipo de conta inválido! Use 'CC' ou 'CP'"<<endl;
            }
        }

        void fecharConta(){
            if(!this->status){
            cout<<"Conta já está fechada!"<<endl;
            return;
            }

            if(this->saldo != 0){
                cout<<"Não é possível fechar a conta. Saldo tem que ser zero!(Saldo atual: R$"<<this->saldo<<")."<<endl;
                return;
            }

            this->status = false;
            this->tipo = "";
            cout<<"Conta fechada com sucesso!"<<endl; 
        }

        void depositar(float valor){
            if(!this->status){
                cout<<"Depósito inválido. Conta fechada!"<<endl;
                return;
            }

            if(valor <= 0){
                cout<<"Depósito inválido!"<<endl;
                return;
            }

            this->saldo += valor;
            cout<<"Depósito de R$"<<valor<<" realizado com sucesso. Saldo Atual: R$"<<this->saldo<<endl;
        }

        void sacar(float valor){
            if(!this->status){
                cout<<"Saque não permitido. Conta fechada!"<<endl;
                return;
            }

            if(valor <= 0){
                cout<<"Saque inválido!"<<endl;
                return;
            }

            if(valor > this->saldo){
                cout<<"Saldo insuficinte. Saldo atual: R$"<<this->saldo<<endl;
                return;
            }

            this->saldo -= valor;
            cout<<"Saque de R$"<<valor<<" realizado com sucesso. Saldo atual: R$"<<this->saldo<<endl;
        }

        void pagarMens(){
            if(!this->status){
                cout<<"Operação não permitida. Conta fechada!"<<endl;
                return;
            }

            float taxa = (this->tipo == "CC") ? 12.00 : 20.00;

            if(this->saldo < taxa){
                cout<<"Saldo insuficiente!"<<endl;
                return;
            }

            this->saldo -= taxa;
            cout<<"Mensalidade de R$"<<taxa<<" paga com sucesso. Saldo atual: R$"<<this->saldo<<endl;
        }

        int getNumConta(){
            return this->numConta;
        }

        void setNumConta(int numConta){
            this->numConta = numConta;
        }

        float getSaldo(){
            return this->saldo;
        }

        void setSaldo(float saldo){
            this->saldo = saldo;
        }

        int getStatus(){
            return this->status;
        }

        void setStatus(int status){
            this->status = status;
        }

        string getDono(){
            return this->dono;
        }

        string getTipo(){
            return this->tipo;
        }
};

int main(void){
    ContaBanco *conta = new ContaBanco("Moisés", 123);

    cout<<"ABRINDO CONTA..."<<endl;
    conta->abrirConta("CC");

    cout<<endl;

    cout<<"INFORMAÇÕES DA CONTA:"<<endl;    
    cout<<"Nome: "<<conta->getDono()<<endl;
    cout<<"ID: "<<conta->getNumConta()<<endl;
    cout<<"Tipo: "<<conta->getTipo()<<endl;
    cout<<"Saldo: R$"<<conta->getSaldo()<<endl;
    cout<<"Status: "<<(conta->getStatus() ? "Aberta" : "Fechada")<<endl;

    cout<<endl;

    cout<<"OPERAÇÕES:"<<endl;
    conta->depositar(200.00);
    conta->sacar(50.00);
    conta->pagarMens();

    cout<<endl;

    cout << "Tentando fechar conta com saldo.." << endl;
    conta->fecharConta();

    cout<<endl;
    
    cout << "Zerando saldo para fechar.." << endl;
    conta->sacar(conta->getSaldo());
    conta->fecharConta();
    delete conta;

    return 0;
}