#include<iostream>
#include<string>
#include<vector>

using namespace std;

class historicoTransacoes{// utiliza padrão singleton
    public:
        static historicoTransacoes* instance(void){
            if(!p){
                p = new historicoTransacoes();
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

        void registrarTransacoes(const string& msg){
            this->transacoes.push_back(msg);
        }

        void exibirHistorico(){
            cout<<"\n\n======================================\n";
            cout<<"           Histórico de Transações";
            cout<<"\n\n======================================\n";

            for(const auto& msg: transacoes){
                cout<<"\n- "<<msg;
            }
        }

    private:                              
        historicoTransacoes();
        static historicoTransacoes* p;
        vector<string> transacoes;
};

historicoTransacoes* historicoTransacoes::p = nullptr;

historicoTransacoes::historicoTransacoes(){
    cout<<"Singleton carregado."<<endl;
}

class ContaBanco{
    private:
        int numConta;
        string tipo;
        double saldo;
        bool status;
        string dono; 
    public:
        ContaBanco(int num, const string& tipo, string dono){
            this->numConta = num;
            this->tipo = tipo;
            this->dono = dono;
            this->status = false;
            this->saldo = 0;
        }
        ~ContaBanco(){
            cout<<"Objeto destruído com sucesso!"<<endl;
        }

        void abrirConta(){
            if(this->status == true){
                cout<<"Conta já está aberta!"<<endl;
                return;
            }

            this->status = true;

            if(this->tipo == "CP"){
            this->saldo += 50.00;
            }else if(this->tipo == "CC"){
                this->saldo += 150.00;
            }else{
                this->status = false;
                cout<<"Tipo de conta inválido! Use 'CC' ou 'CP'"<<endl;
            }

            historicoTransacoes::instance()->registrarTransacoes("Conta aberta "+this->tipo+" saldo: "+to_string(this->saldo) +" Dono: "+this->dono);
        }

        void fecharConta(){
            if(this->status == false){
                cout<<"Conta já está fechada!"<<endl;
                return;
            }

            if(this->saldo != 0){
                cout<<"Não é possível fechar a conta. Saldo diferente de 0!"<<endl;
                return;
            }

            this->status = false;
            cout<<"Conta de "<<this->dono<<" fechada com sucesso!"<<endl;

            historicoTransacoes::instance()->registrarTransacoes("Conta de "+this->dono+" fechada com sucesso!");
        }

        void depositar(double valor){
            if(this->status == false){
                cout<<"Depósito inválido. Conta inativa!"<<endl;
                return;
            }

            this->saldo += valor;
            cout<<"Depósito de R$"<<valor<<" realizado com sucesso. Saldo Atual: R$"<<this->saldo<<endl;
            historicoTransacoes::instance()->registrarTransacoes("Déposito de "+to_string(valor)+" na conta de "+this->dono+" realizada com sucesso!");
        }

        void sacar(double valor){
            if(this->status == false){
                cout<<"Saque não permitido. Conta inativa!"<<endl;
                return;
            }

            if(valor <= this->saldo){
                this->saldo -= valor;
                cout<<"Saque de R$"<<valor<<" realizado com sucesso. Saldo atual: R$"<<this->saldo<<endl;
                historicoTransacoes::instance()->registrarTransacoes("Saque de "+to_string(valor)+" na conta de "+this->dono+" realizada com sucesso!");
            }else{
                cout<<"Saldo insuficinte. Saldo atual: R$"<<this->saldo<<endl;
                historicoTransacoes::instance()->registrarTransacoes(this->dono+" tentou sacar "+to_string(valor)+" (Saldo insuficiente)");
            }
        }

        void pagarMens(){
            if(this->status == false){
                cout<<"Operação não permitida. Conta inativa!"<<endl;
                return;
            }

            double taxa = (this->tipo == "CP") ? 20.0 : 12.0;
            this->saldo -= taxa;
            cout<<"Mensalidade de R$ "<<taxa<<" paga com sucesso!"<<endl;
            historicoTransacoes::instance()->registrarTransacoes(this->dono+" pagou a mensalidade de R$"+to_string(taxa)+" com sucesso!");            
        }

        int getNumConta(){ return this->numConta; }

        void setNumConta(int numConta){ this->numConta = numConta; }

        float getSaldo(){ return this->saldo; }

        void setSaldo(float saldo){ this->saldo = saldo; }

        int getStatus(){ return this->status; }

        void setStatus(int status){ this->status = status; }

        string getDono(){ return this->dono; }

        string getTipo(){ return this->tipo; }

};

int main(void){
    historicoTransacoes* p = historicoTransacoes::instance(); 
    ContaBanco c1(10, "CP", "Kroda");
    ContaBanco c2(11, "CC", "Elder");

    c1.abrirConta();
    c2.abrirConta();

    c1.depositar(100);
    c2.sacar(30);

    c1.pagarMens();
    c2.pagarMens();

    c2.sacar(20);
    historicoTransacoes::instance()->exibirHistorico();

    p->delInstance();
    return 0;
}