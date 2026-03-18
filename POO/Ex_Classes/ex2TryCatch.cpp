#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>

using namespace std;

class Exemplo
{
private:
    string nome;
    int valor;
public:
    void imprimeNome()
    {
        if (nome.empty() == true)
        {
            throw invalid_argument("O nome está vazio!");
        }
        cout << "Nome: " << nome << endl;
    }

    void dobraValor(){
        if(this->valor > numeric_limits<int>::max() / 2){
            throw overflow_error("Estouro de memória!");
        }
        this->valor = valor * 2;
    }

    string getNome(){ return this->nome; }
    void setNome(string nome){ this->nome = nome; }
    int getValor(){ return this->valor; }
    void setValor(int valor){ this->valor = valor; }
};

int main(void)
{
    Exemplo obj;

    obj.setNome("Elder");
    obj.setValor(numeric_limits<int>::max());
    
    try{
        obj.imprimeNome();
        obj.dobraValor();
    }catch(const invalid_argument& e){
        cerr<<"ERRO: "<<e.what()<<endl;
    }catch(const overflow_error& e1){
        cerr<<"ERRO1: "<<e1.what()<<endl;

    }
    return 0;
}