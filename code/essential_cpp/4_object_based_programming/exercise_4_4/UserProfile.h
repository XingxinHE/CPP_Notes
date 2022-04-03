#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

// UserProfile Class
class UserProfile {

public:
    enum user_level {Beginner, Intermediate, Master, Guru};

    // ctor
    UserProfile()
        :_user_name("guest"), _current_level(Beginner), _num_logged(1),
         _num_tried_guess(0), _num_correct_guess(0)
         {

         }
    UserProfile(const string& user_name, user_level level = Beginner)
    :_user_name(user_name), _current_level(level), _num_logged(1),
     _num_tried_guess(0), _num_correct_guess(0)
     {

     }

    // get-only function
    string user_name() const { return _user_name; }
    int num_login() const {return _num_logged; }
    int num_tried() const {return _num_tried_guess;}
    int num_correct() const {return _num_correct_guess;}
    string current_level() const;
    double percent_correct();

    // reset
    void reset_user_name( const string& name){_user_name = name;}
    void reset_login_count( int val ){ _num_logged = val; }
    void reset_guess_count( int val ){ _num_tried_guess = val; }
    void reset_guess_correct( int val ){ _num_correct_guess = val; }
    void reset_current_level(const string &level);

    // bump
    void bump_login_count( int cnt=1 ){ _num_logged += cnt; }
    void bump_guess_count( int cnt=1 ){ _num_tried_guess += cnt; }
    void bump_guess_correct(int cnt=1){ _num_correct_guess += cnt;}

    // user level
    void init_string_level_map();
private:
    string _user_name;
    int _num_logged;
    int _num_tried_guess;
    int _num_correct_guess;
    user_level _current_level;
    double _percent_correct;
    static map<string, UserProfile::user_level> string_level_map;
};

// the user_level ToString() method
inline
string UserProfile::current_level() const
{
    static string USER_LEVEL_MAP [] = 
    {
        "Beginner", "Intermediate", "Master", "Guru"
    };
    return USER_LEVEL_MAP[_current_level];
}

//TODO Explain why it is here for compilation
map<string, UserProfile::user_level> UserProfile::string_level_map;

// init the map
void UserProfile::init_string_level_map()
{
    string_level_map["Beginner"] = user_level::Beginner;
    string_level_map["Intermediate"] = user_level::Intermediate;
    string_level_map["Master"] = user_level::Master;
    string_level_map["Guru"] = user_level::Guru;
}

// reset current level
void UserProfile::reset_current_level(const string &level)
{
    // check if the map is empty
    if(string_level_map.empty())
    {
        UserProfile::init_string_level_map();
    }
    map<string, user_level>::const_iterator end_it = string_level_map.end();
    map<string, user_level>::const_iterator find_it = string_level_map.find(level);

    if (end_it != find_it)
    {
        _current_level = string_level_map[level];
    }
    else
    {
        _current_level = user_level::Beginner;
    }
}

// overwrite operator <<
inline
ostream& operator<< (ostream &os, const UserProfile &rhs)
{
    os << rhs.user_name() << " " << rhs.current_level() << " "
       << rhs.num_login() << " " << rhs.num_tried() << " "
       << rhs.num_correct() << endl;
    return os;
}

// overwrite operator >>
inline
istream& operator>> (istream &is, UserProfile &rhs)
{
    string log_name, level;
    int num_log, num_tried, num_correct;
    cin >> log_name >> level;
    cin >> num_log >> num_tried >> num_correct;

    rhs.reset_user_name(log_name);
    rhs.reset_current_level(level);
    rhs.reset_guess_correct(num_correct);
    rhs.reset_guess_count(num_tried);
    rhs.reset_login_count(num_log);

    return is;
}