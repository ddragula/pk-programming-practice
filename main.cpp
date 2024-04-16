#include <iostream>

typedef unsigned int uint;

bool isPerfect(const uint n) {
    uint sum = 1;
    const uint sqrtN = static_cast<uint>(sqrt(n));
    for (uint i = 2; i <= sqrtN; i++) {
        if (n % i == 0) {
            sum += 1;
            if (const uint nByI = n / i; nByI != i) {
                sum += nByI;
            }
        }
    }
    return n == sum;
}

uint nwd(uint a, uint b) {
    while (b != 0) {
        const uint temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

uint nww(const uint a, const uint b) {
    return a * b / nwd(a, b);
}

struct pair {
    int a, b;
};

pair extendedEuclidean(int m, int n) {
    if (n == 0) {
        return { 1, 0 };
    }
    const auto p = extendedEuclidean(n, m - m / n * n);
    return { p.b, p.a - m / n * p.b };
}

void perfectNumbersProgram() {
    uint n;

    std::cout << "Podaj liczbę naturalną n: ";
    std::cin >> n;
    std::cout << "Oto liczby doskonałe mniejsze od n = " << n << ":" << std::endl;

    for (uint i = 2; i < n; i++) {
        if (isPerfect(i)) {
            std::cout << i << std::endl;
        }
    }
}

void nwwNwdProgram() {
    int m, n;

    std::cout << "Podaj liczbę naturalną m: ";
    std::cin >> m;
    std::cout << "Podaj liczbę naturalną n: ";
    std::cin >> n;

    std::cout << "NWD(" << m << ", " << n << ") = " << nwd(m, n) << std::endl;
    std::cout << "NWW(" << m << ", " << n << ") = " << nww(m, n) << std::endl;
}

void extendedEuclideanProgram() {
    int m, n;

    std::cout << "Podaj liczbę naturalną m: ";
    std::cin >> m;
    std::cout << "Podaj liczbę naturalną n: ";
    std::cin >> n;

    const uint d = nwd(m, n);
    auto [ a, b ] = extendedEuclidean(m, n);
    std::cout << "d = NWD(" << m << ", " << n << ") = " << d << std::endl;
    std::cout << d << " = a*" << m << " + " << "b*" << n << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
}

int main() {
    char cmd;
    while(true) {
        std::cout << std::endl;
        std::cout << "Dostępne programy:" << std::endl;
        std::cout << "1. perfect numbers" << std::endl;
        std::cout << "2. nww, nwd" << std::endl;
        std::cout << "3. extended euclidean" << std::endl;
        std::cout << "Wybierz program (1-3) lub wyjdź wpisując jakikolwiek inny znak: ";
        std::cin >> cmd;

        switch (cmd) {
            case '1':
                perfectNumbersProgram();
                break;
            case '2':
                nwwNwdProgram();
                break;
            case '3':
                extendedEuclideanProgram();
                break;
            default:
                return 0;
        }
    }
}


