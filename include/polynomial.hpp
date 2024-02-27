#ifndef __POLYNOMIAL_HPP_
#define __POLYNOMIAL_HPP_

#include <vector>

class Polynomial
{
public:
    Polynomial(std::vector<int>& coeffs);
    ~Polynomial() = default;

    void print();
    Polynomial derive();
    Polynomial operator+(const Polynomial& other);
    Polynomial operator-(const Polynomial& other);
    bool operator==(const Polynomial& other);
    bool operator!=(const Polynomial& other);
    int degree() const;
    std::vector<int> coeffs() const;
private:
    std::vector<int> m_coeffs;
    int m_degree;
};


#endif /* __POLYNOMIAL_HPP_ */