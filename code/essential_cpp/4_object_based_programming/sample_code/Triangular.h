#include <vector>
#include <string>

using namespace std;

class Triangular
{
private:
        int _length;                // number of elements
        int _begin_pos;             // beginning position of range
        int _next;                  // next element to iterate over
        static vector<int> _elems;  // static vector to store the elments
public:
        // const member functions
        int length() const {return _length;}
        int begin_pos() const {return _begin_pos;}
        int elem(int pos) const;

        // non-const member functions
        bool next(int &val);
        void next_reset() {_next = _begin_pos - 1};

        Triangular();
        ~Triangular();
};

Triangular::Triangular()
{
}

Triangular::~Triangular()
{
}

int sum(const Triangular &trian)
{
        int beg_pos = trian.begin_pos();
        int length = trian.length();
        int sum = 0;
        for (int ix = 0; ix < length; ix++)
        {
                sum += trian.elem(beg_pos + ix);
        }
        return sum;
}

bool Triangular::next(int &value) const
{
        if (_next < _begin_pos + _length - 1)
        {
                //ERROR: modifying _next
                value = _elems[next++];
                return true;
        }
        return false;
}

int Triangular::elem(int pos) const
{
        return _elems[pos - 1];
}