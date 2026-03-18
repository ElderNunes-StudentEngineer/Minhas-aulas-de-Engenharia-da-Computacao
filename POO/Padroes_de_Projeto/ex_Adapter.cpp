#include<iostream>

using namespace std;

class Target{
    public:
        virtual void request() = 0;

        ~Target(){
        cout<<"Objeto destruído com sucesso!"<<endl;
        }
};

class Adaptee{
    public:
        void specificRequest(){
            cout<<"Executando specificRequest() em Adaptee"<<endl;
        }

        ~Adaptee() {
            cout << "Objeto Adaptee destruído com sucesso!" << endl;
        }
};

class Adapter : public Target{
    private:
        Adaptee* adaptee;
    public:
        Adapter(Adaptee* adaptee){
            this->adaptee = adaptee;
        }

        void request() override{
            cout<<"Adaptando Adaptee para Target"<<endl;
            this->adaptee->specificRequest();
        }

        ~Adapter() {
            cout << "Objeto Adapter destruído com sucesso!" << endl;
        }

};

int main(void){
    Adaptee* adaptee = new Adaptee();
    Target* adapter = new Adapter(adaptee);

    adapter->request();

    return 0;
}