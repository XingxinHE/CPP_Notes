#include <iostream>
#include "LibraryMaterial.h"
#include "Book.h"

using namespace std;

void print(const LibraryMaterial &libmat)
{
        cout << "In global print(): about to print libmat.print()" << endl;
        libmat.print();
}

int main()
{
        cout << "Creating a LibraryMaterial object to print()" << endl;
        LibraryMaterial libmat;
        print(libmat);

        cout << "Creating a Book object to print()" << endl;
        Book b("The Castle", "Franz Kafka");
        print(b);

        return 0;
}