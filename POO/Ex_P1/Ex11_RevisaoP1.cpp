/*
11. (Deitel C++ 6.13 adaptado) Crie uma classe em C++ chamada Retangulo que armazena as coordenadas cartesianas x e y dos 
quatro cantos do retângulo. O construtor chama uma função set que recebe quatro conjuntos de coordenadas e verifica se 
cada um deles está no primeiro quadrante sem que nenhum valor de coordenada x ou y seja maior que 20.0. 
A função set também verifica se as coordenadas fornecidas de fato especificam um retângulo. 
A classe mãe de Retangulo (chamada CalculoGeometriaPlana) é abstrata e constam os métodos que calculam o comprimento, largura, 
perímetro e área, porém tais métodos devem ser implementados na classe derivada. Um adendo, o comprimento é maior das duas 
dimensões e, ainda, inclua um método predicado quadrado, que determina se o retângulo é um quadrado.
*/
#include<iostream>
#include<string>

using namespace std;

class CalculoGeometriaPlana{
    public:
        virtual void comprimento() = 0;
        virtual void largura() = 0;
        virtual void perimetro() = 0;
        virtual void area() = 0;
};

class Retangulo: public CalculoGeometriaPlana{
    private:
        float x;
        float y;
    public:
        Retangulo(){}
        ~Retangulo(){}

};

int main(void){
    

    return 0;
}