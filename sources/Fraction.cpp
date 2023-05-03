//
// Created by vboxuser on 4/21/23.
//
#include <limits>
#include <numeric>
#include "Fraction.hpp"

namespace ariel {
    //Empty constructor
    Fraction::Fraction() = default;

    //Base constructor
    Fraction::Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be 0\n");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        this->simplify();
    }

    //Float constructor
    Fraction::Fraction(float num) {
        this->numerator = (int) (num * 1000);
        this->denominator = 1000;
        this->simplify();
    }

    //Copy constructor
    Fraction::Fraction(const Fraction &other) {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    //Setters Getters
    void Fraction::setNumerator(int mone) {
        Fraction::numerator = mone;
    }

    void Fraction::setDenominator(int mone) {
        Fraction::denominator = mone;
    }

    int Fraction::getNumerator() const {
        return this->numerator;
    }

    int Fraction::getDenominator() const {
        return this->denominator;
    }

    Fraction::Fraction(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
    }

    //Destructor
    Fraction::~Fraction() = default;

    //Move assignemt
    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        this->numerator = other.numerator;
        this->denominator = other.denominator;
        other.numerator = 0;
        other.numerator = 1;
        return *this;
    }

    Fraction &Fraction::operator=(const Fraction &other) = default;

    Fraction Fraction::operator-(const Fraction &other) const {
        long long lcm = std::lcm(denominator,
                                 other.denominator); // Find the least common multiple (LCM) of the denominators
        long long num = static_cast<long long>(numerator) * (lcm / denominator) -
                        static_cast<long long>(other.numerator) * (lcm / other.denominator);
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
            lcm > std::numeric_limits<int>::max() || lcm < std::numeric_limits<int>::min()) {
            throw std::overflow_error("add overflows");
        }
        int resultNumerator = static_cast<int>(num);
        int resultDenominator = static_cast<int>(lcm);
        return {resultNumerator, resultDenominator};
    }

    Fraction Fraction::operator-(float num) const {
        Fraction numtofrac(num);
        return *this - numtofrac;
    }

    Fraction operator-(float num, const Fraction &other) {
        Fraction numtofrac(num);
        return numtofrac - other;
    }

    Fraction Fraction::operator+(const Fraction &other) const {
        long long lcm = std::lcm(denominator,
                                 other.denominator); // Find the least common multiple (LCM) of the denominators
        long long num = static_cast<long long>(numerator) * (lcm / denominator) +
                        static_cast<long long>(other.numerator) * (lcm / other.denominator);
        if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min() ||
            lcm > std::numeric_limits<int>::max() || lcm < std::numeric_limits<int>::min()) {
            throw std::overflow_error("add overflows");
        }
        int resultNumerator = static_cast<int>(num);
        int resultDenominator = static_cast<int>(lcm);
        return {resultNumerator, resultDenominator};
    }

    Fraction Fraction::operator+(float num) const {
        Fraction numtofrac(num);
        return *this + numtofrac;
    }

    Fraction operator+(float num, const Fraction &other) {
        Fraction numtofrac(num);
        return other + numtofrac;
    }

    Fraction Fraction::operator*(const Fraction &other) const {
        auto mone = static_cast<long long>(numerator) * other.numerator;
        auto mechane = static_cast<long long>(denominator) * other.denominator;
        if (mone > std::numeric_limits<int>::max()) throw std::overflow_error("Overflow");
        if (mone < std::numeric_limits<int>::min()) throw std::overflow_error("Overflow");
        if (mechane > std::numeric_limits<int>::max()) throw std::overflow_error("Overflow");
        if (mechane < std::numeric_limits<int>::min()) throw std::overflow_error("Overflow");
        Fraction newfrac = Fraction(static_cast<int>(mone), static_cast<int>(mechane));
        return newfrac;
    }

    Fraction Fraction::operator*(float num) const {
        Fraction numtofrac(num);
        return *this * numtofrac;
    }


    Fraction operator*(float num, const Fraction &other) {
        Fraction numtofrac(num);
        return other * numtofrac;
    }

    Fraction Fraction::operator/(const Fraction &other) const {
        if (other.numerator == 0)throw std::runtime_error("Division by 0 is illegal");
        auto mone = static_cast<long long>(numerator) * other.denominator;
        auto mechane = static_cast<long long>(denominator) * other.numerator;
        if (mone > std::numeric_limits<int>::max()) throw std::overflow_error("Overflow");
        if (mone < std::numeric_limits<int>::min()) throw std::overflow_error("Overflow");
        if (mechane > std::numeric_limits<int>::max()) throw std::overflow_error("Overflow");
        if (mechane < std::numeric_limits<int>::min()) throw std::overflow_error("Overflow");
        Fraction newfrac = Fraction(static_cast<int>(mone), static_cast<int>(mechane));
        return newfrac;
    }

    Fraction Fraction::operator/(float num) const {
        if (num == 0)throw std::runtime_error("Division by 0 is illegal");
        Fraction numtofrac(num);
        return *this / numtofrac;
    }

    Fraction operator/(float num, const Fraction &other) {
        if (other.numerator == 0)throw std::runtime_error("Division by 0 is illegal");
        Fraction numtofrac(num);
        return numtofrac / other;
    }


    bool operator!=(float num, const Fraction &other) {
        const Fraction newfrac = Fraction(num);
        return !(newfrac == other);
    }

    bool Fraction::operator!=(const Fraction &other) const {
        return !(other == *this);
    }

    bool Fraction::operator!=(float num) const {
        const Fraction newfrac = Fraction(num);
        return !(newfrac == *this);
    }

    bool Fraction::operator<(const Fraction &other) const {
        Fraction frac1(*this);
        int x = frac1.numerator * other.denominator;
        int y = other.numerator * frac1.denominator;
        return x < y;
    }


    bool Fraction::operator<(float num) const {
        Fraction newfrac(num);
        bool ans = *this < newfrac;
        return ans;
    }

    bool operator<(float num, const Fraction &other) {
        Fraction newfrac(num);
        bool ans = newfrac < other;
        return ans;
    }

    bool Fraction::operator>(const Fraction &other) const {
        bool ans1 = !(*this < other);
        bool ans2 = !(*this == other);
        return ans1 && ans2;
//double x = numerator/denominator;
//double y =other.numerator/other.denominator;
//        return x>y;
    }

    bool Fraction::operator>(float num) const {
        Fraction newfrac(num);
        bool ans = *this > newfrac;
        return ans;
    }

    bool operator>(float num, const Fraction &other) {
        Fraction newfrac(num);
        bool ans = newfrac > other;
        return ans;
    }

    bool Fraction::operator<=(const Fraction &other) const {
        bool ans = !(*this > other);
        return ans;
    }

    bool Fraction::operator<=(float num) const {
        Fraction newfrac(num);
        bool ans = (*this <= newfrac);
        return ans;
    }

    bool operator<=(float num, const Fraction &other) {
        Fraction newfrac(num);
        bool ans = (newfrac <= other);
        return ans;
    }

    bool Fraction::operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    bool Fraction::operator>=(float num) const {
        Fraction newfrac(num);
        bool ans = *this >= newfrac;
        return ans;
    }

    bool operator>=(float num, const Fraction &other) {
        Fraction newfrac(num);
        bool ans = newfrac >= other;
        return ans;
    }

    Fraction &Fraction::operator+=(const Fraction &other) {
        *this = *this + other;
        return *this;
    }

    Fraction &Fraction::operator+=(float num) {
        Fraction newfrac(num);
        return *this += newfrac;
    }

    Fraction &Fraction::operator-=(const Fraction &other) {
        *this = *this - other;
        return *this;
    }

    Fraction &Fraction::operator-=(float num) {
        Fraction newfrac(num);
        return *this -= newfrac;
    }

    Fraction &Fraction::operator*=(const Fraction &other) {
        *this = *this * other;
        return *this;
    }

    Fraction &Fraction::operator*=(float num) {
        Fraction newfrac(num);
        return *this *= newfrac;
    }

    Fraction &Fraction::operator/=(const Fraction &other) {
        *this = *this / other;
        return *this;
    }

    Fraction &Fraction::operator/=(const float num) {
        Fraction newfrac(num);
        return *this /= newfrac;
    }

    Fraction &Fraction::operator++() {
        Fraction one = Fraction(1, 1);
        *this += one;
        return *this;
    }

    const Fraction Fraction::operator++(int) {
        Fraction copy(*this);
        numerator += denominator;
        return copy;
    }

    Fraction &Fraction::operator--() {
        Fraction one(1, 1);
        *this -= one;
        return *this;
    }

    const Fraction Fraction::operator--(int) {
        Fraction copy(*this);
        numerator -= denominator;
        return copy;
    }

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
        return out << fraction.numerator << "/" << fraction.denominator;
    }


    //FIX
    bool Fraction::operator==(const Fraction &other) const {
        float ans1 = (static_cast<float>(numerator)) / ((static_cast<float>(denominator)));
        float ans2 = ((static_cast<float>(other.numerator)) / static_cast<float>(other.denominator));
        return std::abs(ans1 - ans2) < 0.001;
    }

    bool Fraction::operator==(float num) const {
        Fraction newfrac(num);
        bool ans = (newfrac == *this);
        return ans;
    }

    bool operator==(float num, const Fraction &other) {
        const Fraction newfrac = Fraction(num);
        bool ans = (newfrac == other);
        return ans;
    }

    Fraction &Fraction::operator=(float number) {
        this->numerator = (int) number * 1000;
        this->denominator = 1000;
        return *this;
    }


    void Fraction::simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        bool a = (numerator < 0);
        bool b = (denominator < 0);
        //both negative, turn into positive
        if (a && b) {
            numerator *= -1;
            denominator *= -1;
        }
        //To keep consistency, if only the denominator is negative make it positive and change the numerator to be negative
        if ((!a) && b) {
            numerator *= -1;
            denominator *= -1;
        }
        int gcd = GCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int Fraction::GCD(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    std::istream &operator>>(std::istream &input, Fraction &fraction) {
        int numerator = 0;
        int denominator = 1;
        int optional = 0;
        input >> numerator;
        if (input.fail()) throw std::runtime_error("Invalid numerator");
        input >> optional;
        if (input.fail()) throw std::runtime_error("Invalid divide sign, please use '/'");
        if (optional == '/') {
            input >> denominator;
            if (input.fail()) throw std::runtime_error("Invalid input");
            if (denominator == 0)throw std::runtime_error("Denominator cannot be 0.");
            fraction.setDenominator(denominator);
            fraction.setNumerator(numerator);
            fraction.simplify();
        } else {
            if (input.fail()) throw std::runtime_error("Invalid input");
            if (optional == 0) throw std::runtime_error("Invalid input");
            fraction.setDenominator(optional);
            fraction.setNumerator(numerator);
            fraction.simplify();
        }
        return input;
    }
}
