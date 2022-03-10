#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &numbers)
{
        for (int i = 0; i < numbers.size(); i++)
        {
                cout << numbers[i] << " ";
        }
}

int this_pentag(int n)
{
        return n * (3 * n - 1) / 2;
}

vector<int> generate_pentag(int size)
{
        vector<int> pentagonal_numbers(size);

        for (int i = 1; i < size+1; i++)
        {
                int current_number = this_pentag(i);
                cout << current_number << endl;
                pentagonal_numbers.push_back(current_number);
        }
        return pentagonal_numbers;
}

int main()
{
        int user_choice;
        cout << "Please insert a number: " << endl;
        cin >> user_choice;
        vector<int> my_numbers = generate_pentag(user_choice);
        display(my_numbers);

        return 0;
}