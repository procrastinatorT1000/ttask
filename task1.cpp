#include <iostream>

using namespace std;

class SomeClass

{

public:

    SomeClass()
    {

        x1 = new char[ 1024 ];

        x2 = new char[ 1024 * 1024 ];

    }

private:

    char *x1;
    char *x2;

};


int main( void )
{
    cout<<"Hello!"<<endl;
    return 0;
}