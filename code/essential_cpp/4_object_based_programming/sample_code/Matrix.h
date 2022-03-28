class Matrix
{
private:
    int _row, _col;
    double *_pmat;
public:
    Matrix(const Matrix &rhs);
    Matrix(int row, int col);
    ~Matrix();
    Matrix& operator= (const Matrix &rhs);
};

Matrix::Matrix(int row, int col)
    : _row(row), _col(col)
{
    // constructor allocates a resource
    _pmat = new double[row * col];
}

Matrix::~Matrix()
{
    // destructor frees the resource
    delete [] _pmat;
}

Matrix::Matrix(const Matrix &rhs)
    : _row(rhs._row), _col(rhs._col)
{
    // create a "deep copy" of the array addressed by rhs._pmat
    int elem_cnt = _row * _col;
    _pmat = new double[elem_cnt];

    for (int ix = 0; ix < elem_cnt; ix++)
    {
        _pmat[ix] = rhs._pmat[ix];
    }
}

Matrix& Matrix::
operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        this->_col = rhs._col;
        this->_row = rhs._row;
        int elem_cnt = this->_col * this->_row;
        delete [] _pmat;
        _pmat = new double[elem_cnt];
        for (int ix = 0; ix < elem_cnt; ix++)
        {
            _pmat[ix] = rhs._pmat[ix];
        }
    }

    return *this;    
}