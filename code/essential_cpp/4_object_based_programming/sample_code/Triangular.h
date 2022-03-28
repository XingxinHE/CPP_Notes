#ifndef TRIANGULAR_H
#define TRIANGULAR_H


#include <vector>
#include <string>
#include "Triangular_iterator.h"

using namespace std;

class Triangular {
	friend class Triangular_iterator;
public:
	Triangular( int len = 1, int bp = 1 ); 
	Triangular( const Triangular& );
	Triangular& operator=( const Triangular &rhs );

   int length()  const { return _length;  }
   int beg_pos() const { return _beg_pos; }
   int elem( int pos ) const;

   void length( int nlen ) { _length = nlen; }
   void beg_pos( int npos ){ _beg_pos = npos; }

   bool next( int &val ) const;
   void next_reset() const { _next = 1; }

   static bool is_elem( int );
   static void gen_elements( int length );
   static void gen_elems_to_value( int value );
   static void display( int length, int beg_pos, ostream &os = cout );

   typedef Triangular_iterator iterator;

   Triangular_iterator begin() const
        { return Triangular_iterator( _beg_pos ); }

   Triangular_iterator end() const
        { return Triangular_iterator( _beg_pos+_length ); }
 
private:
	int _length; 	// number of elements
	int _beg_pos; // beginning position of range
	mutable int _next;    // next element to iterate over

    // static const int   _max_elems = 1024; // ok, but not VC++
	enum { _max_elems = 1024 };
    static vector<int> _elems;
};

#endif