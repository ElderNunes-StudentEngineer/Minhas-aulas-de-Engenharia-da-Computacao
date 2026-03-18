#ifndef IMC_H
#define IMC_H

#include<QString>

class IMC
{
private:
    double peso, altura, resultado;
public:
    IMC();
    double calculaImc(void);
    QString statusImc(void);
    double getPeso() const;
    void setPeso(double newPeso);
    double getAltura() const;
    void setAltura(double newAltura);
    double getResultado() const;
    void setResultado(double newResultado);
};

#endif // IMC_H
