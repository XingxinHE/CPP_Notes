#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <iostream>
#include <algorithm>

using namespace std;

class num_sequence;
ostream operator<<(ostream&, const num_sequence&);

class num_sequence
{
public:
        typedef vector<unsigned int>::iterator iterator;
        typedef void (num_sequence::*PtrType) (int);

        enum num_seq_type
        {
                num_seq_unset,
                num_seq_fibonacci,
                num_seq_pell,
                num_seq_lucas,
                num_seq_triangular,
                num_seq_square,
                num_seq_pentagonal
        };

        void set_position(int pos)
        {
                if (pos <= 0 || pos > max_seq)
                {
                        cerr << "!! INVALID POSITION: " << pos
                             << " setting pos to default value of 1\n"
                             << "If inadequate, invoke set_position(pos)\n";
                        pos = 1;
                }
                _begin_pos = pos;
        }

        void set_length(int len)
        {
                if (len <= 0 || len + _begin_pos -1 > max_seq)
                {
                         cerr << "!! invalid length for this object: " << len 
			      << " setting length to default value of 1\n"
			      << "If inadequate, invoke set_length(len)\n";
			 len = 1;
                }
                _length = len;
        }

        void set_sequence(num_seq_type nst)
        {
                switch (nst)
                {
                default:
                        cerr << "invalid type: setting to 0\n";

                case num_seq_unset:
                        _pmf = 0;
                        _elem = 0;
                        _current_seq_type = num_seq_unset;
                        break;
                
                case num_seq_fibonacci:
                case num_seq_pell:
                case num_seq_lucas:
                case num_seq_triangular:
                case num_seq_square:
                case num_seq_pentagonal:
                        _pmf = function_table[nst];
                        _elem = &seq[nst];
                        _current_seq_type = nst;
                        break;
                }
        }

        num_sequence(int beg_pos = 1, int len = 1, num_seq_type nst = num_seq_unset)
        {
                set_position(beg_pos);
                set_length(len);
                set_sequence(nst);
        }

        bool operator==(const num_sequence &rhs) const
        {
                bool flag = (_begin_pos == rhs._begin_pos) &&
                            (_length == rhs._length);
                return flag;
        }

        bool operator!=(const num_sequence &rhs) const
        {
                return !(*this==rhs);
        }

        num_sequence operator+(const num_sequence &rhs)
        {
                int b_pos = _begin_pos<rhs._begin_pos ? _begin_pos : rhs._begin_pos;
                int len = _length + rhs._length;
                num_seq_type nt = _current_seq_type == rhs._current_seq_type ? 
                                            _current_seq_type : num_seq_unset;
                return num_sequence(b_pos, len, nt);
        }

        bool check_integrity(int pos) const
        {
                if ((pos <= 0) || (pos > max_seq) || (pos >= _length + _begin_pos))
                {
                        cerr << "!! INVALID POSITION: " << pos
                             << " Cannot honor request\n";
                        return false;
                }

                if (_current_seq_type == num_seq_unset)
                {
                        cerr << "!! OBJECT IS NOT SET TO A SEQUENCE."
                             << " Please set_sequence() and try again!\n";
                        return false;
                }

                if (pos > _elem->size())
                {
                        cout << "check_integrity: calculating "
                             << pos - _elem->size() << " additional elements\n";
                        
                        (this->*_pmf)(pos);
                }
                
                return true;
        }

        int elem(int pos)
        {
                if (!check_integrity(pos))
                {
                        return 0;
                }
                return (*_elem)[pos-1];
        }

        // _pmf(pointer of member function) addresses one of the following
        void fibonacci( int pos );
        void pell( int pos );      
        void lucus( int pos );     
        void triangular( int pos );
	void square( int pos );    
        void pentagonal( int pos );

        const char* what_am_i() const
        {
                static char *names[count_sequence] = 
                {
                        "not set",
                        "fibonacci",
			"pell",
			"lucus",
			"triangular",
			"square",
			"pentagonal"
                };

                return names[_current_seq_type];
        }

        static void init_seq_map()
        {
                seq_map["fibonacci"] = num_seq_fibonacci;
                seq_map["pell"] = num_seq_pell;
                seq_map["lucus"] = num_seq_lucas;
                seq_map["triangular"] = num_seq_triangular;
                seq_map["square"] = num_seq_square;
                seq_map["pentagonal"] = num_seq_pentagonal;
        }

        static num_seq_type set_seq_type(const char* ps)
        {
                if (seq_map.empty())
                {
                        init_seq_map();
                }

                string name(ps);

                num_seq_type nt = seq_map.count(name)?
                                  seq_map[name] :
                                  num_seq_unset;
                return nt;
        }

        ostream& print(ostream &os = cout) const
        {
                if (!check_integrity(_length + _begin_pos - 1))
                {
                        return os;
                }

                int len = _begin_pos + _length - 1;

                for (int ix = 0; ix < _begin_pos; ix++)
                {
                        os << (*_elem)[ix] << ' ';
                }
                return os;
                
        }

        ostream& display(ostream &os = cout) const
        {
                if (!check_integrity(1))
                {
                        return os;
                }

                
                
        }

        num_sequence(/* args */);
        ~num_sequence();

private:
        int _cal_pos(unsigned int elem);

        vector<unsigned int> *_elem;

        PtrType _pmf;
        num_seq_type _current_seq_type;

        int _begin_pos;
        int _length;
        int _max_pos;

        static vector<vector<unsigned int> > seq;

        static const int count_sequence = 7;

        static const int max_seq;
        static map<string, num_seq_type> seq_map;
        static PtrType function_table[count_sequence];

};

num_sequence::num_sequence(/* args */)
{
}

num_sequence::~num_sequence()
{
}
