#include<iostream>

using namespace std;

class Carro{
    private: //atributos
        int ano;
        float valor;
        float km;

    public: //métodos

        int getAno(){
            return this->ano;
        } 

        float getValor(){
            return this->valor;
        } 

        float getKm(){
            return this->km;
        } 

        void atualizarKm(float km);

        Carro(int a, float v, float k){
            ano = a; // this->ano = ano;
            valor = v; // this->valor = valor;
            km = k; // this->km = km;
            cout<<"Objeto criado com sucesso!"<<endl;
        }

        ~Carro(){
            cout<<"Objeto destruído com sucesso!"<<endl;
        }//destrutor
};

int main(void){
    Carro impala1(1967, 55000, 10110); //objeto
    Carro *impala2 = new Carro(1967, 55000, 10110);//ponteiro para objeto

    cout<<"Impala ano: "<<impala1.getAno()<<endl;
    cout<<"Impala valor: "<<impala1.getValor()<< " reais"<<endl;
    cout<<"Impala km: "<<impala1.getKm()<< " km"<<endl;

    cout<<endl;

    cout<<"Impala ano: "<<impala2->getAno()<<endl;
    cout<<"Impala valor: "<<impala2->getValor()<< " reais"<<endl;
    cout<<"Impala km: "<<impala2->getKm()<< " km"<<endl;
    delete impala2;

    return 0;
}