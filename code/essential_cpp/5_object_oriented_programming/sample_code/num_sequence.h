#include <iostream>

using namespace std;

class num_sequence
{
protected:
        virtual void gen_elems(int pos) = 0;
        bool check_integrity(int pos) const;
        const static int _max_elems = 1024;

public:
        virtual ~num_sequence() {};

        virtual int elem(int pos) const = 0;
        virtual const char* what_am_i() const = 0;
        virtual ostream& print(ostream &os = cout) const = 0;

        static int max_elems() { return _max_elems; }

        // ...
        num_sequence();
};
