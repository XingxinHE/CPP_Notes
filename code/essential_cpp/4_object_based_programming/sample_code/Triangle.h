#include <string>
using namespace std;

class Triangle
{
private:
    string _name;
    int _id, _length;
public:
    Triangle(int len, int id);
    Triangle(const Triangle &rhs);
    ~Triangle();
};

Triangle::Triangle(int len, int id)
: _name("new"), _id(id), _length(len)
{
}

Triangle::Triangle(const Triangle &rhs)
: _name(rhs._name), _id(rhs._id), _length(rhs._length)
{
}

Triangle::~Triangle()
{
}
