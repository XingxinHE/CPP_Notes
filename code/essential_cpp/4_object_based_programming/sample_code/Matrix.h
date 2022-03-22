class Matrix
{
private:
    int _row, _col;
    double *_pmat;
public:
    Matrix(const Matrix &rhs);
    Matrix(int row, int col);
    ~Matrix();
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