#include<iostream>

using namespace std;

class PapelA4{
    private:
        int qtde; //estoque
        int vendas; //vendas efetuadas - históricos
        int encomendas; //futuro para chegar e colocar em estoque
    public:
        PapelA4(){
            this->encomendas = 100;
            this->qtde = 100;
            this->vendas = 100;
        }

        bool vendaEfetuada(int qtdeVendida){
            if(this->qtde >= qtdeVendida){
                this->vendas += qtdeVendida;
                this->qtde -= qtdeVendida;
                return true;
            }
            return false;
        }

            int getQtde() const {
        return qtde;
    }

    int getVendas() const {
        return vendas;
    }

    int getEncomendas() const {
        return encomendas;
    }

    void setQtde(int qtde) {
        this->qtde = qtde;
    }

    void setVendas(int vendas) {
        this->vendas = vendas;
    }

    void setEncomendas(int encomendas) {
        this->encomendas = encomendas;
    }
};

class Singleton{
    public: 
        static Singleton *instace(void){
            if(!p){
                p=new Singleton();
            }
            return p;
        }

        void imprimeControleA4(){
            cout<<"\nQuantidade estoque: "<<controleA4.getQtde();
            cout<<"\nQuantidade vendas: "<<controleA4.getVendas()<<endl;
        }

        void vendasRealizadas(int qtdeVendida){
            if(controleA4.vendaEfetuada(qtdeVendida) == true){
                cout<<"Venda realizada com sucesso"<<endl;
            }else{
                cout<<"Ops, não tenho essa quantidade em estoque!"<<endl;
            }
        }

    private:    
        Singleton(){ cout<<"\nSingleton carregado!\n"; };
        static Singleton *p;
        PapelA4 controleA4;
};

Singleton* Singleton::p=nullptr;

int main(){
    Singleton::instace()->imprimeControleA4();
    Singleton::instace()->vendasRealizadas(150);

    return 0;
}