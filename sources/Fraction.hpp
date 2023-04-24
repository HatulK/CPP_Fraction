//
// Created by vboxuser on 4/18/23.
//
#ifndef FRACTION_A_MAIN_FRACTION_H
#define FRACTION_A_MAIN_FRACTION_H

#include <iostream>

namespace ariel {

    class Fraction {
    public:
        // Constructors
        Fraction();

        Fraction(int numerator, int denominator);

        explicit Fraction(float num);

        Fraction(const Fraction &other);

        // Destructor
        ~Fraction();

        // Copy assignment operator
        Fraction &operator=(const Fraction &other);

        // Arithmetic operators
        Fraction operator-(const Fraction &other) const;

        Fraction operator-(float num) const;

        Fraction operator-(int num) const;

        bool operator>(int num) const;

        bool operator>(double num) const;

        bool operator<(int num) const;

        bool operator<(double num) const;

//    friend Fraction operator-(float num, const Fraction &other);

        Fraction operator-(const Fraction &other);

        Fraction operator-() const;

//    friend Fraction operator-(float num, const Fraction &other);

        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float num) const;

//    friend Fraction operator+(float num, const Fraction &other);

        Fraction operator*(const Fraction &other) const;

        Fraction operator*(float num) const;

//    friend Fraction operator*(float num, const Fraction &other);

        Fraction operator/(const Fraction &other) const;

        Fraction operator/(const Fraction &other);

        Fraction operator/(float num) const;

        Fraction operator/(double num) const;

        Fraction operator/(int num) const;

        bool operator==(const Fraction &other) const;

        bool operator==(float number) const;

        friend bool operator==(float num, const Fraction &other);

        friend bool operator!=(float num, const Fraction &other);

        bool operator!=(const Fraction &other) const;

        bool operator!=(float num) const;

        friend bool operator!=(float num, const Fraction &other);

        bool operator<(const Fraction &other) const;

        bool operator<(float num) const;

        friend bool operator<(float num, const Fraction &other);

        bool operator>(const Fraction &other) const;

        bool operator>(float num) const;

        friend bool operator>(float num, const Fraction &other);

        bool operator<=(const Fraction &other) const;

        bool operator<=(float num) const;

        friend bool operator<=(float num, const Fraction &other);

        bool operator>=(const Fraction &other) const;

        bool operator>=(float num) const;

        friend bool operator>=(float num, const Fraction &other);

        // Compound assignment operators
        Fraction &operator+=(const Fraction &other);

        Fraction &operator+=(float num);

        Fraction &operator-=(const Fraction &other);

        Fraction &operator-=(float num);

        Fraction &operator*=(const Fraction &other);

        Fraction &operator*=(float num);

        Fraction &operator/=(const Fraction &other);

        Fraction &operator/=(float num);

        // Increment and decrement operators
        Fraction &operator++();

        // Addition operator
        friend Fraction operator+(const Fraction& frac, double doub);
        friend Fraction operator+(double doub, const Fraction& frac);

// Subtraction operator
        friend Fraction operator-(const Fraction& frac, double doub);
        friend Fraction operator-(double doub, const Fraction& frac);


        Fraction operator++(int); //what does it do?
        Fraction &operator--();

        Fraction operator--(int); // what does it do?

        // Type conversion operators
        explicit operator float() const;

        // Output stream operator
        friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

        // Helper functions
        int gcd(int num1, int num2) const;

        void simplify();

        void invert();

        void swap(Fraction &other);

        //Float functions
        friend Fraction operator+(float frac1, const Fraction &frac2);

        friend Fraction operator-(float frac1, const Fraction &frac2);

        friend Fraction operator*(float frac1, const Fraction &frac2);

        friend Fraction operator/(float frac1, const Fraction &frac2);

        friend Fraction operator+(const Fraction &frac2, float frac1);

        friend Fraction operator-(const Fraction &frac2, float frac1);

        friend Fraction operator*(const Fraction &frac2, float frac1);

        friend Fraction operator/(const Fraction &frac2, float frac1);

        friend bool operator>(const Fraction &frac2, float frac1);

        friend bool operator<(const Fraction &frac2, float frac1);

        friend bool operator>=(const Fraction &frac2, float frac1);

        friend bool operator<=(const Fraction &frac2, float frac1);

        Fraction &operator=(float number);

        Fraction &operator=(Fraction &&other) noexcept;

        Fraction(Fraction &&other) noexcept;


    private:
        // Member variables
        int numerator{};
        int denominator{};
    };
}
#endif //FRACTION_A_MAIN_FRACTION_H