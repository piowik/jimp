//
// Created by Piotrek on 01.04.2017.
//

#include <iostream>
#include "Matrix.h"

using std::vector;
using std::complex;
using std::swap;

namespace algebra {
    Matrix::Matrix() {
        rows_ = 0;
        cols_ = 0;
        matrix_ = nullptr;
    }

    Matrix::Matrix(int cols, int rows) {
        AllocateMemory(cols, rows);
    }

    Matrix::~Matrix() {
        for (int i = 0; i < cols_; i++)
            delete[] matrix_[i];
        delete[] matrix_;
    }

    Matrix::Matrix(const Matrix &mat) {
        cols_ = mat.cols_;
        rows_ = mat.rows_;
        AllocateMemory(cols_, rows_);
        for (int i = 0; i < cols_; i++)
            for (int j = 0; j < rows_; j++)
                matrix_[i][j] = mat.matrix_[i][j];
    }

    Matrix &Matrix::operator=(const Matrix &mat) {
        if (this == &mat) {
            return *this;
        }
        for (int i = 0; i < cols_; i++)
            delete[] matrix_[i];
        delete[] matrix_;
        rows_ = mat.rows_;
        cols_ = mat.cols_;
        AllocateMemory(cols_, rows_);
        for (int i = 0; i < cols_; i++)
            for (int j = 0; j < rows_; j++)
                matrix_[i][j] = mat.matrix_[i][j];
        return *this;
    }

    void Matrix::AllocateMemory(int cols, int rows) {
        complex<double> **matr = new complex<double> *[cols];
        for (int i = 0; i < cols; i++)
            matr[i] = new complex<double>[rows];
        rows_ = rows;
        cols_ = cols;
        matrix_ = matr;
    }

    Matrix::Matrix(const std::initializer_list<vector<complex<double>>> &elements) {
        complex<double> **matr = new complex<double> *[elements.size() - 1];
        int i = 0;
        for (vector<complex<double>> ve : elements) {
            matr[i] = new complex<double>[ve.size()];
            for (int j = 0; j < ve.size(); j++)
                matr[i][j] = ve[j];
            i++;
        }
        cols_ = (int) elements.size();
        rows_ = (int) elements.begin()->size();
        matrix_ = matr;
    };

    Matrix::Matrix(std::string str) {
        const char *characters = str.c_str();
        size_t strSize = str.size();
        cols_ = 1;
        rows_ = 0;
        bool done = false;
        for (int i = 0; i<strSize; i++) {
            if (characters[i] == ' ' && !done)
                cols_++;
            else if (characters[i] == ';') {
                rows_++;
                done = true;
            }
        }
        AllocateMemory(cols_,rows_);
        int col = 0;
        int row = 0;
        complex<double> num = (0.0);
        std::stringstream number;
        number << "(";
        std::cout << str << std::endl;
        for (int i = 1; i<strSize-1; i++) {
            if (characters[i] == ';') {
                row++;
            }
            else if (characters[i] == ' ') {
                number << ")";
                number >> num;
                matrix_[row][col] = num;
                number.str("");
                number << "(";
                col++;
            }
            else if (characters[i] == 'i')
                number << ",";
            else
                number << characters[i];
        }
    }

    std::pair<size_t, size_t> Matrix::Size() {
        return std::make_pair(rows_, cols_);
    }

    Matrix Matrix::Add(const Matrix &m) const {
        if ((m.rows_ != rows_) || (m.cols_ != cols_))
            return Matrix();
        int moves = std::min(m.rows_, m.cols_);
        Matrix ret = Matrix(cols_, rows_);
        for (int i = 0; i < moves; i++)
            for (int j = 0; j < moves; j++)
                ret.matrix_[i][j] = matrix_[i][j] + m.matrix_[i][j];
        return ret;
    }

    Matrix Matrix::Mul(const Matrix &m) const {
        if ((rows_ != m.cols_))
            return Matrix();
        int roz1 = cols_;
        int roz2 = rows_;
        int m2_roz2 = m.rows_;
        Matrix ret = Matrix(roz1, m2_roz2);
        for (int i = 0; i < roz1; i++) {
            for (int j = 0; j < m2_roz2; j++) {
                ret.matrix_[i][j] = (0,0);
                for (int k = 0; k < roz2; k++)
                    ret.matrix_[i][j] += matrix_[i][k] * m.matrix_[k][j];
            }
        }
        return ret;
    }

    Matrix Matrix::Sub(const Matrix &m) const {
        if ((m.rows_ != rows_) || (m.cols_ != cols_))
            return Matrix();
        Matrix ret = Matrix(cols_, rows_);
        for (int i = 0; i < cols_; i++)
            for (int j = 0; j < rows_; j++)
                ret.matrix_[i][j] = matrix_[i][j] - m.matrix_[i][j];
        return ret;
    }

    Matrix Matrix::Pow(int m) const {
        if (rows_ != cols_)
            return Matrix();
        if (m == 0) {
            Matrix ret = Matrix(cols_, rows_);
            for (int i = 0; i < cols_; i++)
                ret.matrix_[i][i] = 1;
            return ret;
        } else {
            Matrix ret(*this);
            if (m > 1) {
                Matrix org(*this);
                for (int i = 0; i < m - 1; i++)
                    ret = ret.Mul(org);
            }
            return ret;
        }
    }

    std::string Matrix::Print() const {
        if ((rows_ == 0) || (cols_ == 0) || (matrix_ == nullptr))
            return "[]";
        std::stringstream out;
        out << "[";
        for (int i = 0; i < cols_; i++) {
            for (int j = 0; j < rows_; j++) {
                out << matrix_[i][j].real() << "i" << matrix_[i][j].imag();
                if (j < rows_ - 1)
                    out << ", ";
            }
            if (i < cols_ - 1)
                out << "; ";
        }
        out << "]";
        return out.str();
    }
}