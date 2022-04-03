#include <iostream>
#include <vector>

using namespace std;

typedef float elemType;

class Matrix
{
    
private:
    elemType _matrix[4][4];
    
public:
    Matrix
    (
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0.,
            elemType=0.,elemType=0.,elemType=0.,elemType=0. 
    );
    Matrix(elemType*);    
    ~Matrix();

    friend Matrix operator+( const Matrix&, const Matrix& );
    friend Matrix operator*( const Matrix&, const Matrix& );
    void operator+=(const Matrix&);
    elemType& operator()(int row, int col) {return _matrix[row][col];}
    elemType operator()(int row, int col) const {return _matrix[row][col];}

    int row() const {return 4;}
    int col() const {return 4;}
    elemType get_elem(int n_row, int n_col) const;
    bool validate_index(int n_row, int n_col) const;
    ostream& print(ostream &os) const;
};

Matrix::Matrix
(
    elemType m00, elemType m01, elemType m02, elemType m03,
    elemType m10, elemType m11, elemType m12, elemType m13,
    elemType m20, elemType m21, elemType m22, elemType m23,
    elemType m30, elemType m31, elemType m32, elemType m33
)
{
    _matrix[0][0]=m00; _matrix[0][1]=m01; _matrix[0][2]=m02; _matrix[0][3]=m03;
    _matrix[1][0]=m10; _matrix[1][1]=m11; _matrix[1][2]=m12; _matrix[1][3]=m13;
    _matrix[2][0]=m20; _matrix[2][1]=m21; _matrix[2][2]=m22; _matrix[2][3]=m23;
    _matrix[3][0]=m30; _matrix[3][1]=m31; _matrix[3][2]=m32; _matrix[3][3]=m33;
}

Matrix::Matrix(elemType* array)
{
    int cnt = 0;
    for (int ix = 0; ix < row(); ix++)
    {
        for (int iy = 0; iy < col(); iy++)
        {
            _matrix[ix][iy] = array[cnt++];
        }
    }
}

Matrix::~Matrix()
{

}

ostream&
Matrix::print(ostream &os) const
{
    for (int ix = 0; ix < 4; ix++)
    {
        for (int iy = 0; iy < 4; iy++)
        {
            os << _matrix[ix][iy] << " ";
        }
        os << endl;
    }
    return os;
}

inline void
Matrix::operator+=(const Matrix& m)
{
    for (int ix = 0; ix < row(); ix++)
    {
        for (int iy = 0; iy < col(); iy++)
        {
            this->_matrix[ix][iy] += m._matrix[ix][iy];
        }
    }
}

inline
Matrix operator*(Matrix& m1, Matrix& m2)
{
    Matrix m;
    for (int ix = 0; ix < m.row(); ix++)
    {
        for (int iy = 0; iy < m.col(); iy++)
        {
            m(ix, iy) = 0;
            for (int iz = 0; iz < m.col(); iz++)
            {
                 m(ix, iy) += ( m1(ix, iz) * m2(iz, iy) );
            }
        }
    }
    return m;
}

Matrix operator+(Matrix& m1, Matrix& m2)
{
    Matrix result(m1);
    result += m2;
    return result;
}

inline
ostream& operator<< (ostream &os, const Matrix &rhs)
{
    return rhs.print(os);
}

bool
Matrix::validate_index(int n_row, int n_col) const
{
    if (n_row < 0 || n_col <0 || n_row > 3 || n_col > 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

elemType
Matrix::get_elem(int n_row, int n_col) const
{
    if (Matrix::validate_index(n_row, n_col))
    {
        return _matrix[n_row][n_col];
    }
    else
    {
        return 0;
    }
}




