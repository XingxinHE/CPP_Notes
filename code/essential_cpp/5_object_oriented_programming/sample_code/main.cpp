#include <iostream>
#include <typeinfo>
#include "LibraryMaterial.h"
#include "Book.h"
#include "num_sequence.h"
#include "Fibonacci.h"
#include "Animal.h"
#include "Dog.h"


using namespace std;

void print(const LibraryMaterial &libmat)
{
        cout << "In global print(): about to print libmat.print()" << endl;
        libmat.print();
}

void prog_1()
{
        cout << "Creating a LibraryMaterial object to print()" << endl;
        LibraryMaterial libmat;
        print(libmat);

        cout << "Creating a Book object to print()" << endl;
        Book b("The Castle", "Franz Kafka");
        print(b);
}

void prog_2()
{
        // num_sequence *ns_ptr = new Fibonacci(12, 8);

        // //ns_ptr->gen_elems(10);

        // cout << ns_ptr->what_am_i() << endl;

        // delete ns_ptr;
}

int main()
{
        Animal *a = new Dog();

        a->Name();

        if(typeid(*a) == typeid(Dog))
        {
                Dog *d = static_cast<Dog*>(a);
                d->Voice();
        }
        
        //a->Dog::Voice();

        return 0;
}