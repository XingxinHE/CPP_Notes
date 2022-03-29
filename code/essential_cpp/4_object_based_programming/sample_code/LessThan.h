class LessThan
{
private:
        int _val;
public:
        LessThan(int val)
                : _val(val) {}
        
        int comp_val() const {return _val;}

        void comp_val(int nval) {_val = nval;}

        bool operator() (int value) const;
};

inline bool LessThan::
operator() (int value) const 
{
        return value < _val;
}
