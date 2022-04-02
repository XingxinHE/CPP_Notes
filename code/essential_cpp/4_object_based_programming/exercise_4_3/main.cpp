#include <iostream>
#include <string>
#include "GlobalProgram.h"

using namespace std;

int main()
{
    cout << "Set data..." << endl;
    string p_name("LIBIGL");
    GlobalProgram::set_program_name(p_name);
    GlobalProgram::set_tests_passed(0);
    GlobalProgram::set_tests_run(3);
    GlobalProgram::set_version_number(5);
    string v_name("103x");
    GlobalProgram::set_version_stamp(v_name);

    cout << "Get data..." << endl;
    cout << "Tests passed: " << GlobalProgram::get_tests_passed << endl;
    cout << "Tests run: " << GlobalProgram::get_tests_run << endl;
    cout << "Version number: " << GlobalProgram::get_version_number << endl;
    cout << "Version stamp: " << GlobalProgram::get_version_stamp << endl;

    return 0;
}