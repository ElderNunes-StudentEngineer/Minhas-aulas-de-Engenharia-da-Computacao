#include<iostream>

using namespace std;

class Singleton{
    public:
        static Singleton* instance(void){
            if(!p){
                p = new Singleton();
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

        char* retornarString(void){ return "Hello World"; }
        int retornarInt(void){ return 19; }
    private:                              
        Singleton();
        static Singleton* p;
};

class ClasseA{
    public:
        ClasseA();
};

Singleton* Singleton::p = 0;

Singleton::Singleton(){
    cout<<"Singleton carregado."<<endl;
}

ClasseA::ClasseA(){
    Singleton* p = Singleton::instance();

    cout<<"ClasseA string: "<<p->retornarString()<<endl;
    cout<<"ClasseA int: "<<Singleton::instance()->retornarInt()<<endl;

    cout<<"ClasseA p: "<<Singleton::instance()<<endl;
}

char* Funcao(void){
    return Singleton::instance()->retornarString();
}

int main(void){
    Singleton* p = Singleton::instance(); 
    
    cout<<"p: "<<p<<endl;
    cout<<"p: "<<Singleton::instance()<<endl;

    cout<<"String: "<<p->retornarString()<<endl;
    cout<<"Int: "<<p->retornarInt()<<endl;
    ClasseA classe;

    cout<<"Função: "<<Funcao()<<endl;

    p->delInstance();
    return 0;
}