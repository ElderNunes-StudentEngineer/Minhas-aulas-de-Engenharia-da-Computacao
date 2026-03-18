#include<iostream>

using namespace std;

class Compras{
    public:
        virtual void executarCompras(float valor) = 0;
};

class DescontoA : public Compras{
    public:
        void executarCompras(float valor) override{
            cout<<"Executando desconto fixo de 10%"<<endl;
            valor *= 0.90;
            cout<<"Valor após o deconto: R$"<<valor<<endl;
        }
};

class DescontoB : public Compras{
    public:
        void executarCompras(float valor) override{
            cout<<"Executando desconto progressivo — 5% até R$1000, e 10% acima disso."<<endl;
            if(valor > 1000){
                valor *= 0.95 ;
                cout<<"Valor após o desconto de 5%: R$"<<valor<<endl;
            }else{
                valor *= 0.90;
                cout<<"Valor após o desconto de 10%: R$"<<valor<<endl;
            }
        }
};

class DescontoC : public Compras{
    public:
        void executarCompras(float valor) override{
            cout<<"Sem desconto "<<endl;
            cout<<"Valor da compra: R$"<<valor<<endl;
        }
};

class Contexto{
    private:
        Compras* compras;
    public:
        Contexto(){ this->compras = nullptr; }
        void executarEstrategia(float valor){
            if(this->compras != nullptr){
                compras->executarCompras(valor);
            }else{
                cout<<"Nenhuma Compra foi definida!"<<endl;
            }
        }

        void setCompra (Compras* novaCompra){ this->compras = novaCompra; }
};

int main(void){
    DescontoA a;
    DescontoB b;
    DescontoC c;

    Contexto contexto;

    contexto.setCompra(&a);
    contexto.executarEstrategia(100);
    contexto.setCompra(&b);
    contexto.executarEstrategia(500);
    contexto.setCompra(&c);
    contexto.executarEstrategia(1000);

    return 0;
}