/********************************/
/************Stack.h*************/
/********************************/

#include <vector>
#include <string>

using namespace std;

class Stack
{
private:
        vector<string> _stack;
public:
        bool push(const string& );
        bool pop(string &elem);
        bool peek(string &elem);

        bool empty();
        bool full();

        bool find(string &elem);
        int count(string &elem);

        int size() { return _stack.size(); };
};
