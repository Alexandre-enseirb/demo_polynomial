# demo_polynomial

Un exemple-jouet d'implémentation de polynômes en C++.

## Fonctionnalités
### Instantiation de polynômes

Un polynôme peut être instantié comme suit

```cpp
void foo()
{
  // instantie un polynome a partir d'un vecteur de coefficients entiers
  std::vector<int> coeffs {1, 2, 3};
  Polynomial p { coeffs };
}
```

### Addition et soustraction de polynômes

Deux polynômes peuvent être ajoutés ou soustraits comme suit 

```cpp
void bar()
{
  std::vector<int> coeffs1 {1, 2, 3};
  std::vector<int> coeffs2 {4, 5, 2, -1};
  Polynomial p1 { coeffs };
  Polynomial p2 { coeffs2 };

  // Calcule la somme et la difference de p1 et p2
  Polynomial addition = p1 + p2;
  Polynomial soustraction = p1 - p2;
}
```

### Dérivation de polynômes

Le polynôme peut-être dérivé comme suit

```cpp
void baz()
{
  std::vector<int> coeffs1 {1, 2, 3};
  Polynomial p1 { coeffs };

  // calcule la derivee de p1
  Polynomial derive = p1.derive();
}
```

### Égalité entre polynômes

On peut vérifier que deux polynômes possèdent les mêmes coefficients comme suit

```cpp
void qux()
{
  // Instantie deux polynomes avec des coeffs similaires
  std::vector<int> coeffs1 {1, 2, 3};
  std::vector<int> coeffs2 {1, 2, 3};
  Polynomial p1 { coeffs1 };
  Polynomial p2 { coeffs2 };

  // verifie l'egalite des coefficients
  assert(p1 == p2);

  std::vector<int> coeffs3 { 1 };
  Polynomial p3 { coeffs3 };

  // Verifie que p1 et p3 ont des coeffs differents
  assert(p1 != p3);
}
```

### Affichage des coefficients

On peut afficher les coefficients d'un polynôme comme suit

```cpp
void quux()
{
  std::vector<int> coeffs1 {1, 2, 3};
  Polynomial p1 { coeffs };

  // affiche le polynome dans la console
  p1.print();
}
```

## Limites

- Absence de multiplication et de division euclidienne sur les polynômes
- Coefficients entiers uniquement
- Implémentation loin d'être optimale
