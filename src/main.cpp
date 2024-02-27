#include "polynomial.hpp"
#include <iostream>
#include <cassert>


void test_egalite_et_inegalite()
{
    std::vector<int> coeffs {1, 2, 1};
    std::vector<int> coeffs2 {3, 2, 1, 3};

    Polynomial p1 { coeffs }, p2 { coeffs }, p3 {coeffs2};

    assert(p1 == p2);
    assert(p1 != p3);
}

void test_addition()
{
    std::vector<int> coeffs {1, 2, 1};
    std::vector<int> coeffs2 {3, 2, 1, 3};
    std::vector<int> coeffs_attendus_addition {3, 3, 3, 4};

    Polynomial p1 { coeffs }, p2 { coeffs2 }, p3 {coeffs_attendus_addition};

    assert((p1 + p2) == p3);
}

void test_soustraction()
{   
    std::vector<int> coeffs {1, 2, 1};
    std::vector<int> coeffs2 {3, 2, 1, 3};
    std::vector<int> coeffs_attendus_soustraction {-3, -1, 1, -2};

    Polynomial p1 { coeffs }, p2 { coeffs2 }, p3 {coeffs_attendus_soustraction};

    assert((p1 - p2) == p3);
}

void test_derivee()
{
    std::vector<int> coeffs {1, 2, 1};
    std::vector<int> coeffs_attendus_derivee {2, 2};

    Polynomial p1 { coeffs }, p2 { coeffs_attendus_derivee };

    assert(p1.derive() == p2);
}




int
main()
{
    
    test_egalite_et_inegalite();
    test_addition();
    test_soustraction();
    test_derivee();
    
    // FIN
    std::cout << "Hello, World!" << std::endl;
    return 0;
}