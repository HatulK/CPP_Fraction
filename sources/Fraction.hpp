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
        ~Fraction();

        Fraction &operator=(Fraction &&other) noexcept;
        //Setter Getters
        void setNumerator(int mone);

        void setDenominator(int mone);

        int getNumerator() const;

        int getDenominator() const;

        // Copy assignment operator
        Fraction &operator=(const Fraction &other);

        // Arithmetic operators
        Fraction operator-(const Fraction &other) const;

        Fraction operator-(float num) const;

        friend Fraction operator-(float num, const Fraction &frac2);

        Fraction operator+(const Fraction &other) const;

        Fraction operator+(float num) const;

        friend Fraction operator+(float num, const Fraction &other);

        Fraction operator*(const Fraction &other) const;

        Fraction operator*(float num) const;

        friend Fraction operator*(float num, const Fraction &frac2);

        Fraction operator/(const Fraction &other) const;

        Fraction operator/(float num) const;

        friend Fraction operator/(float num, const Fraction &other);

        bool operator==(const Fraction &other) const;

        bool operator==(float number) const;

        friend bool operator==(float num, const Fraction &other);

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

        Fraction &operator++();

        const Fraction operator++(int); //what does it do?

        Fraction &operator--();

        const Fraction operator--(int); // what does it do?

        friend std::istream &operator>>(std::istream &input,Fraction &fraction);

        friend std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

        // Helper functions
        static int GCD(int num1, int num2) ;

        void simplify();

        Fraction &operator=(float num);

        Fraction(Fraction &&other) noexcept;


    private:
        // Member variables
        int numerator{};
        int denominator{};
    };
}
#endif //FRACTION_A_MAIN_FRACTION_H