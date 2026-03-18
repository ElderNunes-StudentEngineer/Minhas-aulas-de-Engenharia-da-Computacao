#include<iostream>
#include<string>

using namespace std;

class Mae{
    protected:

    public:
        virtual void teste() = 0;
};

class Filha: public Mae{
    protected:

    public:
        void teste(){
            cout<<"Imprime teste na FILHA"<<endl;
        }
};

int main(void){
    Filha objFilha;
    objFilha.teste();
    return 0;
}