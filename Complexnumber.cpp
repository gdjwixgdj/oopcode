#include<iostream>
using namespace std;
class Complex{
    private:
        float real,imag;
    public:
        Complex(float r=0.0,float i=0.0):real(r),imag(i){}

        Complex operator +(Complex& other){
            return Complex(real+other.real,imag+other.imag);
        }
        Complex operator *(Complex& other){
            return Complex((real*other.real)-(imag*other.imag),
                            (imag*other.imag)+real*other.imag);
        }
        friend istream& operator>>(istream& is,Complex& c){
            cout<<"Enter real part: ";
            is>>c.real;
            cout<<"\nEnter imag part: ";
            is>>c.imag;

        }
        friend ostream& operator<<(ostream& os,Complex& c){
            os<<c.real<<"+"<<c.imag<<"i";
        }
};  
int main(){
    Complex a,b,sum,product;

    cout<<"Enter the first Complex number:\n";
    cin>>a;

    cout<<"\nEnter the second Complex number:\n";
    cin>>b;

    sum=a+b;
    cout<<"sum:"<<sum;

    product=a*b;
    cout<<"\nProduct: "<<product;
    
    
    return 0;
}
