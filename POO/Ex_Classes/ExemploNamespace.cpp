#include<iostream>
#include<cmath>

namespace myLib{
    double sin(double x){
        return x*( 1 + x*x*( -1./6 + x*x*(1./120) ) );
    }
}// namespace myLib

int main(void){
    double seno = sin(3.0);
    double senoMyLib = myLib::sin(3.0);

    using namespace std;
    cout<<"Seno(3.0) = "<<seno<<endl;
    cout<<"SenoMyLib(3.0) = "<<senoMyLib<<endl;

    return 0;
}