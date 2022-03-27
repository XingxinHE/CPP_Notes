#ifndef TRIANGULAR_ITERATOR_H
#define TRIANGULAR_ITERATOR_H

class Triangular;

class Triangular_iterator
{
private:
        void check_integrity() const;
        int _index;
public:
        Triangular_iterator(int index)
                : _index(index) {};
        
        bool operator==(const Triangular_iterator&) const;
        bool operator!=(const Triangular_iterator&) const;

        int operator*() const;
        int& operator++();            // prefix version
        int operator++(int);          // postfix version

        ~Triangular_iterator();
};


inline bool Triangular_iterator::
operator==(const Triangular_iterator& rhs) const
{
        bool flag = this->_index == rhs._index;
        return flag;
}

inline bool Triangular_iterator::
operator!=(const Triangular_iterator&rhs) const
{
        return !(*this == rhs);
}

inline int Triangular_iterator::
operator*()const
{
        check_integrity();
        return Triangular::_elems[_index];
}

inline int
operator* (const Triangular_iterator &rhs)
{
        rhs.check_integrity();
        return Triangular::_elems[rhs._index];
}

inline int& Triangular_iterator::
operator++()
{
        // prefix instance
        ++_index;
        check_integrity();
        return Triangular::_elem[_index];
}

inline int Triangular_iterator::
operator++(int)
{
        // post instance
        check_integrity();
        return Triangular::_elems[_index++];
}

#endif