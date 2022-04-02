#include <string>

using namespace std;

class GlobalProgram
{
private:
    static string _program_name;
    static string _version_stamp;
    static int _version_number;
    static int _tests_run;
    static int _tests_passed;
public:
    // get
    static string get_program_name(){return _program_name;}
    static string get_version_stamp(){return _version_stamp;}
    static int get_version_number(){return _version_number;}
    static int get_tests_run(){return _tests_run;}
    static int get_tests_passed(){return _tests_passed;}
    // set
    static void set_program_name(const string &p_name){_program_name = p_name;}
    static void set_version_stamp(const string &v_stamp){_version_stamp = v_stamp;}
    static void set_version_number(int v_num){_version_number = v_num;}
    static void set_tests_run(int num_test){_tests_run = num_test;}
    static void set_tests_passed(int num_passed){_tests_passed = num_passed;}

    static void Init();

    GlobalProgram(/* args */);
    ~GlobalProgram();
};

//TODO Explain the reason put the declaration here
string GlobalProgram::_program_name;
string GlobalProgram::_version_stamp;
int GlobalProgram::_version_number;
int GlobalProgram::_tests_run;
int GlobalProgram::_tests_passed;
