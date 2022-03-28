#ifndef TRIANGULAR_ITERATOR_H
#define TRIANGULAR_ITERATOR_H
class Triangular_iterator
{
public:
    Triangular_iterator( int index ) : _index( index-1 ){} //***

    bool operator==( const Triangular_iterator& ) const;
    bool operator!=( const Triangular_iterator& ) const;
    int  operator*() const;
    Triangular_iterator& operator++();       // prefix version
    Triangular_iterator  operator++( int );  // postfix version

private:
    void check_integrity() const;  
    int _index;
};

#endif