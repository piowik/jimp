//
// Created by Piotrek on 01.04.2017.
//

#ifndef JIMP_EXERCISES_MATRIX_H
#define JIMP_EXERCISES_MATRIX_H


#include <complex>
#include <vector>

namespace algebra {
    class Matrix {
    public:
        Matrix();

        Matrix(const Matrix &xxx);

        Matrix &operator=(const Matrix &xxx);

        ~Matrix();

        std::string Print() const;

        Matrix(const std::initializer_list<std::vector<std::complex<double>>> &elements);

        Matrix(std::string str);

        Matrix(int rows, int cols);

        void AllocateMemory(int rows, int cols);

        std::pair<size_t, size_t> Size();

        Matrix Add(const Matrix &m) const;

        Matrix Mul(const Matrix &m) const;

        Matrix Sub(const Matrix &m) const;

        Matrix Pow(int m) const;

    private:
        int rows_ = 0;
        int cols_ = 0;
        std::complex<double> **matrix_;

    };
}

#endif //JIMP_EXERCISES_MATRIX_H
