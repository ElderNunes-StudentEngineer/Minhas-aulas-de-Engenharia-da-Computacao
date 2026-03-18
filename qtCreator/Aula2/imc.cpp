#include "imc.h"

double IMC::getPeso() const
{
    return peso;
}

void IMC::setPeso(double newPeso)
{
    peso = newPeso;
}

double IMC::getAltura() const
{
    return altura;
}

void IMC::setAltura(double newAltura)
{
    altura = newAltura;
}

double IMC::getResultado() const
{
    return resultado;
}

void IMC::setResultado(double newResultado)
{
    resultado = newResultado;
}

double IMC::calculaImc(void){
    return this->getPeso()/(this->getAltura()*this->getAltura());
}

QString IMC::statusImc(void){
    if(this->getResultado()<18){
        return("IMC<18: abaixo do peso");
    }else if(this->getResultado()<25){
        return("18<=IMC<25: peso normal");
    }else if(this->getResultado()<35){
       return("25<=IMC<35: acima do peso");
    }else{
        return("IMC>=35: obesidade");
    }
}

IMC::IMC()
{

}
