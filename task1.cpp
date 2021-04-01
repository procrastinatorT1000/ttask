#include <iostream>
#include <new>
#include <string.h>

using namespace std;

#define X1_SIZE 1024
#define X2_SIZE (1024*1024)

class SomeClass

{

public:

    SomeClass()
    {
        cout<<"Standard constructor\n"<<endl;

        x1 = new char[ X1_SIZE ];
        x2 = new char[ X2_SIZE ];

        if( !x1 || !x2 )
        {
            cerr<<"bad_alloc caught\n";
            cout<<"bad_alloc caught\n";
        }
    }

    SomeClass(const SomeClass &obj)
    {
        cout<<"Copy constructor\n"<<endl;

        x1 = new char[ X1_SIZE ];
        x2 = new char[ X2_SIZE ];
        
        if( !x1 || !x2 )
        {
            cerr<<"bad_alloc caught\n";
            cout<<"bad_alloc caught\n";
        }
        else
        {
            memcpy( x1, obj.x1, X1_SIZE );
            memcpy( x2, obj.x2, X2_SIZE );
        }
    }

    SomeClass & operator=( const SomeClass & obj )
    {
        if( this != &obj )
        {
            cout<<"Reloaded = operator\n"<<endl;
            if( x1 != 0 )
                delete[] x1;
            if( x2 != 0 )
                delete[] x2;

            x1 = new char[ X1_SIZE ];
            x2 = new char[ X2_SIZE ];
            
            if( !x1 || !x2 )
            {
                cerr<<"bad_alloc caught\n";
                cout<<"bad_alloc caught\n";
            }
            else
            {
                memcpy( x1, obj.x1, X1_SIZE );
                memcpy( x2, obj.x2, X2_SIZE );
            }
        }
        else
        {
            cout<<"Self equality"<<endl;
        }
    }

    ~SomeClass()
    {
        if( x1 != 0 )
            delete[] x1;
        if( x2 != 0 )
            delete[] x2;
    }

    int set(char *str)
    {
        if( strlen(str)<X1_SIZE && strlen(str)<X2_SIZE )
        {
            strcpy( x1, str );
            strcpy( x2, str );
        }
    }

    void print()
    {
        cout<<"x1:"<<x1<<endl;
        cout<<"x2:"<<x2<<endl;
    }

private:

    char *x1 = NULL;
    char *x2 = NULL;

};


int main( void )
{
    SomeClass obj;

    obj.set( (char*) "guten morgen");

    SomeClass obj1(obj);
    SomeClass obj2 = obj1;
    SomeClass obj3 = SomeClass(obj2);
    SomeClass *obj4_ptr = new SomeClass(obj3);

    obj.print();
    obj1.print();
    obj2.print();
    obj3.print();
    obj4_ptr->print();

    obj = obj1;
    obj1 = obj1;

    return 0;
}