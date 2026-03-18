#include<iostream>

using namespace std;

class Strategy{
    public:
        virtual void executar() = 0;
        Strategy(){}
        ~Strategy(){}
};

class CStrategyA : public Strategy{
    public:
        void executar() override{
            cout<<"Executando Strategy A"<<endl;
        }
};

class CStrategyB : public Strategy{
    public:
        void executar() override{
            cout<<"Executando Strategy B"<<endl;
        }
};

class CStrategyC : public Strategy{
    public:
        void executar() override{
            cout<<"Executando Strategy C"<<endl;
        }
};

class Contexto{
    private:
        Strategy* estrategia;
    public:
        Contexto(){ this->estrategia = nullptr; }
        void executarEstrategia(){
            if(this->estrategia != nullptr){
                estrategia->executar();
            }else{
                cout<<"Nenhuma estratégia foi definida!"<<endl;
            }
        }

        void setEstrategia (Strategy* novaEstrategia){ this->estrategia = novaEstrategia; }
};

int main(void){
    CStrategyA a;
    CStrategyB b;
    CStrategyC c;

    Contexto contexto;

    contexto.setEstrategia(&a);
    contexto.executarEstrategia();
    contexto.setEstrategia(&b);
    contexto.executarEstrategia();
    contexto.setEstrategia(&c);
    contexto.executarEstrategia();



    return 0;
}