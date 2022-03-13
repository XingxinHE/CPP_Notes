#include <iostream>
#include <vector>

using namespace std;

template <typename elemType>
elemType* find(vector<elemType> &input_vector, elemType input)
{
        for (int i = 0; i < input_vector.size(); i++)
        {
                if (input_vector[i] == input)
                {
                        return &input_vector[i];
                }
        }
        return 0;
}


int main()
{
        vector<int> int_vectors = {1,2,3,4,5};
        int* int_ptr = find<int>(int_vectors, 3);
        
        cout << int_ptr << endl;
        cout << *int_ptr << endl;


        vector<string> string_vectors = {
                "Vector",
                "John",
                "Smith",
                "Laura",
        };

        string* string_ptr = find<string>(string_vectors, "Laura");

        cout << string_ptr << endl;
        cout << *string_ptr << endl;
        return 0;
}