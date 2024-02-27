#include "polynomial.hpp"
#include <cstddef>
#include <iostream>

Polynomial
::Polynomial(std::vector<int>& coeffs)
{
    m_coeffs = std::vector<int> (coeffs.size());
    std::copy(coeffs.begin(), coeffs.end(), m_coeffs.begin());
    m_degree = coeffs.size() - 1;
}

void Polynomial
::print()
{
    size_t max_degree = m_coeffs.size() - 1;
    for (auto e : m_coeffs)
    {
        std::cout << "+ " << e << "x^" << max_degree-- << " ";
    }
    std::cout << std::endl;
}

int Polynomial
::degree() const
{
    return m_coeffs.size() - 1;
}

std::vector<int> Polynomial
::coeffs() const
{
    return m_coeffs;
}

Polynomial Polynomial
::operator+(const Polynomial& other)
{
    std::vector<int> coeffs1, coeffs2;
    std::vector<int> other_coeffs = other.coeffs();
    int new_size;
    const int deg_diff = other.degree() - m_degree;
    if (deg_diff >= 0)
    {
        new_size = other.degree() + 1;
        coeffs1 = std::vector<int> (other.degree() + 1);
        coeffs2 = std::vector<int> (other.degree() + 1);

        std::copy(other_coeffs.begin(), other_coeffs.end(), coeffs1.begin());
        std::copy(m_coeffs.begin(), m_coeffs.end(), coeffs2.begin() + deg_diff);
    }
    else
    {
        new_size = m_degree + 1;
        coeffs1 = std::vector<int> (m_degree + 1);
        coeffs2 = std::vector<int> (m_degree + 1);

        std::copy(other_coeffs.begin(), other_coeffs.end(), coeffs1.begin() + deg_diff);
        std::copy(m_coeffs.begin(), m_coeffs.end(), coeffs2.begin());
    }

    std::vector<int> new_coeffs;
    for (int i = 0 ; i < new_size ; i++)
    {
        new_coeffs.push_back(coeffs1[i] + coeffs2[i]);
    }
    return Polynomial(new_coeffs);
}

Polynomial Polynomial
::operator-(const Polynomial& other)
{
    std::vector<int> coeffs1, coeffs2;
    std::vector<int> other_coeffs = other.coeffs();
    int new_size;
    const int deg_diff = other.degree() - m_degree;
    if (deg_diff >= 0)
    {
        new_size = other.degree() + 1;
        coeffs1 = std::vector<int> (other.degree() + 1);
        coeffs2 = std::vector<int> (other.degree() + 1);

        std::copy(m_coeffs.begin(), m_coeffs.end(), coeffs1.begin() + deg_diff);
        std::copy(other_coeffs.begin(), other_coeffs.end(), coeffs2.begin());
    }
    else
    {
        new_size = m_degree + 1;
        coeffs1 = std::vector<int> (m_degree + 1);
        coeffs2 = std::vector<int> (m_degree + 1);

        std::copy(m_coeffs.begin(), m_coeffs.end(), coeffs1.begin());
        std::copy(other_coeffs.begin(), other_coeffs.end(), coeffs2.begin() + deg_diff);
    }

    std::vector<int> new_coeffs;
    for (int i = 0 ; i < new_size ; i++)
    {
        new_coeffs.push_back(coeffs1[i] - coeffs2[i]);
    }
    return Polynomial(new_coeffs);
}

bool Polynomial
::operator==(const Polynomial& other)
{
    if (m_degree != other.degree())
    {
        return false;
    }
    for (int idx = 0 ; idx < m_degree + 1; idx++)
    {
        if (other.coeffs()[idx] != m_coeffs[idx])
            return false;
    }
    return true;
}

bool Polynomial
::operator!=(const Polynomial& other)
{
    return !(*this==other);
}

Polynomial Polynomial
::derive()
{
    std::vector<int> new_coeffs;
    int degree = m_degree;
    for (int i = 0 ; i < degree ; i++)
    {
        new_coeffs.push_back(m_coeffs[i] * (degree - i));
    }
    return Polynomial(new_coeffs);
}