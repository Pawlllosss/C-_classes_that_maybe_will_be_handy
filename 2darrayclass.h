#include <iostream>
#include <vector>

template < typename T > class Handy2DArray
{
public:
    //2D array constructor (number of rows and columns)
    Handy2DArray( const int rows, const int columns ): max_row(rows), max_col(columns)
    {
        _array2D.reserve(max_row);

        for( int r = 0 ; r < max_row ; r++ )
            _array2D[r].reserve( max_col );
    }

    //it prints whole array content
    void PrintWholeArray() const
    {
        for( int r = 0 ; r < max_row ; r++ )
        {
            for( int c = 0 ; c < max_col; c++ )
                std::cout<<_array2D[r][c]<<" ";
            std::cout<<std::endl;
        }
    }

    //overloaded () operator which returns reference of value holded in _array2D[row][col]
    T& operator()( const int row, const int column ) const
    {
        if( row >= max_row || column >= max_col )
        {
            std::cout<<"Wartosc spoza zakresu"<<std::endl;
            return 0;
        }

        return _array2D[row][column];
    }

    //overloaded () operator which sets value in _array2D[row][col]
    void operator()( const int row, const int column, const T value )
    {
        if( row >= max_row || column >= max_col )
        {
            std::cout<<"Wartosc spoza zakresu"<<std::endl;
            return;
        }

        _array2D[row][column] = value;
    }

private:
    const int max_row;
    const int max_col;
    std::vector< std::vector<T> > _array2D;
};
