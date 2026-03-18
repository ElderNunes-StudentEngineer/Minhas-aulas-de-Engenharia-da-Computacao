#include<iostream>

using namespace std;

class Animais{ //classe abstrata
    private:
        string nome;
        int idade;

    protected:
        float peso;
        int numIdent;

    public:
        //Animais();
        //~Animais();
        string getNome(){
            return this->nome;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        int getNumIdent(){
            return this->numIdent;
        }

        void setNumIdent(int id){
            this->numIdent = id;
        }

        int getIdade(){
            return this->idade;
        }

        void setIdade(int idade){
            this->idade = idade;
        }

};


class Tartaruga: public Animais {
    private:
        float diametroCasco;
        float espessura;

    public:
        Tartaruga(){
        };

        //~Tartaruga();

};

class Gato: public Animais{
    private:
        string cor;
        string tipoPelo;

    public:
        Gato(string nome, int id, float peso, int idade){
            this->peso = peso;
            this->numIdent = id;
            setIdade(idade);
            setNome(nome);

        };

        float getPeso(){
            return this->peso;
        }

       // ~Gato(){};
};

int main(void){
    Gato *g = new Gato("Miau", 123, 3.2, 2);
    cout<<"Nome:"<<g->getNome()<<endl<<"ID:"<<g->getNumIdent()<<endl<<"Peso:"<<g->getPeso()<<endl<<"Idade:"<<g->getIdade()<<endl;

    delete g;
    return 0;
}

