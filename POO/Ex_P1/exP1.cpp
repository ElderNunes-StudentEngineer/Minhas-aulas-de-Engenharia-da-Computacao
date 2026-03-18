/*
Você deve implementar duas classes em C++ que representem conceitos geométricos básicos: Ponto e Circulo. 
Faça o tratamento de exceções de maneira adequada. Além disso, os requisitos mínimos delas estão descritos abaixo:
Classe Ponto: deve armazenar duas coordenadas de um ponto no plano cartesiano: x e y. Deve conter:
Um construtor que permita inicializar as coordenadas x e y (caso não haja inicialização de valores, inicializem as coordenadas com zero).
Utilizem polimorfismo para tratar isso
Um método chamado distancia que recebe como parâmetro outro objeto Ponto e retorna a distância euclidiana entre os dois pontos.
Métodos de acesso  para obter os valores de x e y.
Classe Circulo: deve representar um círculo no plano. O círculo possui um centro, que é um objeto da classe Ponto, e 
um raio (número real positivo). Deve conter:
Um construtor que receba um Ponto (centro) e um valor raio.
Um método area que calcule e retorne a área do círculo.
Um método contem, que recebe um objeto Ponto e retorna verdadeiro (true) se o ponto está dentro ou sobre a borda do círculo, ou 
falso (false) caso contrário.
Métodos de acesso para obter o centro e o raio.
*/

#include<iostream>
#include<cmath>
#include<stdexcept>

using namespace std;

/*
Classe Ponto: deve armazenar duas coordenadas de um ponto no plano cartesiano: x e y. Deve conter:
Um construtor que permita inicializar as coordenadas x e y (caso não haja inicialização de valores, inicializem as coordenadas com zero).
Utilizem polimorfismo para tratar isso
Um método chamado distancia que recebe como parâmetro outro objeto Ponto e retorna a distância euclidiana entre os dois pontos.
Métodos de acesso  para obter os valores de x e y.
*/

class Ponto{
    private:
        float x, y;
    public:
        Ponto(){this->x = this->y = 0;};
        Ponto(float x, float y) {this->x = x; this->y = y;};
        ~Ponto(){}

        float getX(){ return this->x; }
        void setX(float x){ this->x = x; }
        float getY(){ return this->y; }
        void setY(float y){ this->y = y; }

        float distancia(Ponto ponto){
            float dx = this->x - ponto.getX();
            float dy = this->y - ponto.getY();
            return sqrt(pow(dx, 2) + pow(dy, 2));
        }
};

/*
Classe Circulo: deve representar um círculo no plano. O círculo possui um centro, que é um objeto da classe Ponto, e 
um raio (número real positivo). Deve conter:
Um construtor que receba um Ponto (centro) e um valor raio.
Um método area que calcule e retorne a área do círculo.
Um método contem, que recebe um objeto Ponto e retorna verdadeiro (true) se o ponto está dentro ou sobre a borda do círculo, ou 
falso (false) caso contrário.
Métodos de acesso para obter o centro e o raio.
*/

class Circulo{
    private:
        Ponto centro;
        float raio;
    public:
        Circulo(Ponto ponto, float raio){
            setCentro(ponto);
            this->setRaio(raio);
        };

        float area(){
            return  M_PI * pow(raio, 2);
        }

        Ponto getCentro(){ return this->centro; }
        float getRaio(){ return this->raio; }
        void setCentro(Ponto centro){
            this->centro = centro;
        }
        void setRaio(float raio){ 
            if(raio <= 0){
                throw invalid_argument("O raio deve ser um valor positivo!");
            }
            this->raio = raio;
        }

        bool contem(Ponto ponto){
            return centro.distancia(ponto) <= raio;
        }
};

int main(void){
    try {
        Ponto p1(2, 3);
        Circulo c(p1, 5);

        Ponto teste1(4, 6);
        Ponto teste2(10, 10);

        cout << "Área do círculo: " << c.area() << endl;

        cout << "O ponto (4,6) está dentro do círculo? " << (c.contem(teste1) ? "Sim" : "Não") << endl;
        cout << "O ponto (10,10) está dentro do círculo? " << (c.contem(teste2) ? "Sim" : "Não") << endl;
    } catch (exception& e) {
        cerr << "Erro: " << e.what() << endl;
    }

    return 0;
}