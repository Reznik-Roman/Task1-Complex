#include <iostream>

using namespace std;

class MyComplex
{
    friend istream& operator>>( istream &o , MyComplex &B);
    friend ostream& operator<<( ostream &o , MyComplex &B);

    friend MyComplex operator+( MyComplex v1 , MyComplex v2 );
    friend MyComplex operator+( MyComplex v1 , double v2 );
    friend MyComplex operator+( double v1 , MyComplex v2 );

    friend MyComplex operator-( MyComplex v1 , MyComplex v2 );
    friend MyComplex operator-( MyComplex v1 , double v2 );
    friend MyComplex operator-( double v1 , MyComplex v2 );

    friend MyComplex operator*( MyComplex v1 , MyComplex v2 );
    friend MyComplex operator*( MyComplex v1 , double v2 );
    friend MyComplex operator*( double v1 , MyComplex v2 );

    public:

        double getRe(){return Re;}
        double getIm(){return Im;}

        int setRe( double newRe )
        {
        Re = newRe ;
        return 1;
        }

        int setIm( double newIm )
        {
        Im = newIm ;
        return 1;
        }

        MyComplex( double pRe=0.0 , double pIm=0.0 )
        {
        Re = pRe ; Im = pIm ;
        }

        MyComplex operator= ( MyComplex A)
        {
        Re = A.getRe();
        Im = A.getIm();
        return *this;
        }


    protected:

    private:
        double Im,Re;
};

        istream& operator>> (istream &o, MyComplex &B)
        {
            double a,b;
            o>>a>>b;
            B.setRe(a);
            B.setIm(b);
            return o;
        }

        ostream& operator<<( ostream &o , MyComplex &B)
        {

            if ( B.getRe() == 0 && B.getIm() == 0 )
                o<<"Zero";

            if ( B.getRe() == 0 && B.getIm() != 0 )
                o<<B.getIm()<<"i";

            if ( B.getIm() == 0 && B.getRe() != 0 )
                o<<B.getRe()<<" ";

            if (B.getIm() > 0 && B.getRe() != 0)
                o<<B.getRe()<<" + "<<B.getIm()<<"i";
            if (B.getIm() < 0 && B.getRe() != 0)
                o<<B.getRe()<<" "<<B.getIm()<<"i";
            return o;
        }



        MyComplex operator+( MyComplex v1 , MyComplex v2 )
        {
        MyComplex C;
        C.setRe( v1.getRe() +  v2.getRe() );
        C.setIm( v1.getIm() +  v2.getIm() );
        return C;
        }

        MyComplex operator+( MyComplex v1 , double v2 )
        {
        MyComplex C;
        C.setRe( v1.getRe() +  v2 );
        C.setIm( v1.getIm() +  v2 );
        return C;
        }

        MyComplex operator+( double v1 , MyComplex v2 )
        {
        return ( v2 + v1 );
        }

        MyComplex operator-( MyComplex v1 , MyComplex v2 )
        {
        MyComplex C;
        C.setRe( v1.getRe() -  v2.getRe() );
        C.setIm( v1.getIm() -  v2.getIm() );
        return C;
        }

        MyComplex operator-( MyComplex v1 , double v2 )
        {
        MyComplex C;
        C.setRe( v1.getRe() -  v2 );
        C.setIm( v1.getIm() -  v2 );
        return C;
        }

        MyComplex operator-( double v1 , MyComplex v2 )
        {
        return ( v2 - v1 );
        }

        MyComplex operator*( MyComplex v1 , MyComplex v2 )
        {
        MyComplex C;
        double a=v1.getRe();double b=v1.getIm();
        double c=v2.getRe();double d=v2.getIm();
        cout<<endl<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<endl;
        C.setRe( a * c - b * d );
        C.setIm( a * d + b * c );
        return C;
        }

        MyComplex operator*( MyComplex v1 , double v2 )
        {
        MyComplex C;
        C.setRe( v1.getRe() * v2 );
        C.setIm( v1.getIm() * v2 );
        return C;
        }

        MyComplex operator*( double v1 , MyComplex v2 )
        {
        return ( v2 * v1 );
        }




int main()
{
    MyComplex A(2.7,2.8);
    MyComplex B(2.9,-3.9);
    //cin>>A;
    //cin>>B;
    MyComplex C;
    C=A+B;
    cout<<C<<endl;
    return 0;
}
