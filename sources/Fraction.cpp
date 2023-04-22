//
// Created by vboxuser on 4/21/23.
//
#include "Fraction.hpp"
namespace ariel {

    Fraction::Fraction() {

    }

    Fraction::Fraction(int numerator, int denominator) {

    }

    Fraction::Fraction(float num) {

    }

    Fraction::Fraction(const Fraction &other) {

    }

    Fraction &Fraction::operator=(const Fraction &other) {
        return *this;
    }

    Fraction Fraction::operator-(const Fraction &other) const {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator-(float num) const {
        return Fraction(1, 1);
    }

    Fraction operator-(float num, const Fraction &other) {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator+(const Fraction &other) const {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator+(float num) const {
        return Fraction(1, 1);
    }

    Fraction operator+(float num, const Fraction &other) {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator*(const Fraction &other) const {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator*(float num) const {
        return Fraction(1, 1);
    }

    Fraction operator*(float num, const Fraction &other) {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator/(const Fraction &other) const {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator/(float num) const {
        return Fraction(1, 1);
    }


    bool operator!=(float num, const Fraction &other) {
        return true;
    }

    bool Fraction::operator!=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator!=(float num) const {
        return true;
    }

    bool Fraction::operator<(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator<(float num) const {
        return true;
    }

    bool operator<(float num, const Fraction &other) {
        return true;
    }

    bool Fraction::operator>(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator>(float num) const {
        return true;
    }

    bool operator>(float num, const Fraction &other) {
        return true;
    }

    bool Fraction::operator<=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator<=(float num) const {
        return true;
    }

    bool operator<=(float num, const Fraction &other) {
        return true;
    }

    bool Fraction::operator>=(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator>=(float num) const {
        return true;
    }

    bool operator>=(float num, const Fraction &other) {
        return true;
    }

    Fraction &Fraction::operator+=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator+=(float num) {
        return *this;
    }

    Fraction &Fraction::operator-=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator-=(float num) {
        return *this;
    }

    Fraction &Fraction::operator*=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator*=(float num) {
        return *this;
    }

    Fraction &Fraction::operator/=(const Fraction &other) {
        return *this;
    }

    Fraction &Fraction::operator/=(float num) {
        return *this;
    }

    Fraction Fraction::operator-() const {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator-(const Fraction &other) {
        return Fraction(1, 1);
    }

    Fraction Fraction::operator/(const Fraction &other) {
        return Fraction(1, 1);
    }

    Fraction &Fraction::operator++() {
        return *this;
    }

    Fraction Fraction::operator++(int) {
        return Fraction(1, 1);
    }

    Fraction &Fraction::operator--() {
        return *this;
    }

    Fraction Fraction::operator--(int) {
        return Fraction(1, 1);
    }

    Fraction::operator float() const {
        return 0;
    }

    std::ostream &operator<<(std::ostream &out, const Fraction &fraction) {
        return out;
    }

    void Fraction::simplify() {

    }

    void Fraction::invert() {

    }

    void Fraction::swap(Fraction &other) {

    }

    Fraction operator/(float frac1, const Fraction &frac2) {
        return Fraction(1, 1);
    }

    Fraction operator+(const Fraction &frac2, float frac1) {
        return Fraction(1, 1);
    }

    Fraction operator-(const Fraction &frac2, float frac1) {
        return Fraction(1, 1);
    }

    int Fraction::gcd(int a, int b) const {
        return 0;
    }

    Fraction operator*(const Fraction &frac2, float frac1) {
        return Fraction(1, 1);
    }

    Fraction operator/(const Fraction &frac2, float frac1) {
        return Fraction(1, 1);
    }

    bool operator>(const Fraction &frac2, float frac1) {
        return true;
    }

    bool operator<(const Fraction &frac2, float frac1) {
        return true;
    }

    bool operator>=(const Fraction &frac2, float frac1) {
        return true;
    }

    bool operator<=(const Fraction &frac2, float frac1) {
        return true;
    }

    bool Fraction::operator==(const Fraction &other) const {
        return true;
    }

    bool Fraction::operator==(float number) const {
        return true;
    }

    bool operator==(float scalar, const Fraction &other) {
        return true;
    }

    Fraction::~Fraction() = default;

    Fraction &Fraction::operator=(float number) {
        return *this;
    }

    Fraction &Fraction::operator=(Fraction &&other) noexcept {
        return *this;
    }

    Fraction::Fraction(Fraction &&other) noexcept {    }

    Fraction operator+(const Fraction &f, double d) {
        return Fraction(1,1);
    }

    Fraction operator+(double d, const Fraction &f) {
        return Fraction(1,1);
    }

    Fraction operator-(const Fraction &f, double d) {
        return Fraction(1,1);
    }

    Fraction operator-(double d, const Fraction &f) {
        return Fraction(1,1);
    }

    Fraction Fraction::operator-(int num) const {
        return Fraction();
    }

    bool Fraction::operator>(int num) const {
        return true;
    }

    bool Fraction::operator<(int num) const {
        return true;
    }

    bool Fraction::operator>(double num) const {
        return false;
    }

    bool Fraction::operator<(double num) const {
        return false;
    }


}
