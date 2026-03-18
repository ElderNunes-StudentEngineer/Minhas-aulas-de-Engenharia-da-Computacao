#include<iostream>
#include<string>

using namespace std;

class Media{
    private:
        int num1;
        int num2;
    public:
        Media(){
            num1 = num2 = 0;
        };
        Media(int num1, int num2){
            this->num1 = num1;
            this->num2 = num2;
        };

        float calculaMedia(){
            if(this->num1 == 0 && this->num2 == 0){
                throw runtime_error("Não há valores a serem calculados. Por favor, digite os valores");
            }
            return (this->num1 + this->num2)/2.0;
        }
};

int main(void){
    Media m;
    try{
    cout<<"A média é: "<<m.calculaMedia()<<endl;
    }catch(const runtime_error& e){
        cerr<<"Detalhes técnicos: "<<e.what()<<endl;
    }catch(...){
        cerr<<"Erro calcular a média"<<endl;
    }
/*
    string texto = "*pao";

    //char letra = texto[0];
    try{
        char letra = texto.at(10);
        cout<<"A letra na posição 10 é: "<<letra<<endl;
    }catch(const exception *e){
        cerr<<"Erro ao acessar uma posição da string"<<endl;
        cerr<<"Detalhes técnicos: "<<e->what()<<endl;
    }catch(...){
        cerr<<"Erro ao acessar uma posição da string"<<endl;
    }
*/
    return 0;
}