#pragma once
#include <iostream>
#include <cmath>

class vec2 {
protected:
    double x, y;

private:
    // stolen from quake
    inline double q_rsqrt( float number ) {
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = number * 0.5F;
        y  = number;
        i  = * ( long * ) &y;                       // evil floating point bit level hacking
        i  = 0x5f3759df - ( i >> 1 );               // what the fuck?
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
        // y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed
        return y;
    }

public:
    // Constructors
    vec2() : x(0.0), y(0.0) {};
    vec2(double x, double y) : x(x), y(y) {};
    vec2(vec2& v) : x(v.x), y(v.y) {};

    // Vector operations
    inline vec2 unitVec() {
        return *this/magnitude();
    };
    inline double magnitude() {
        return sqrt(x*x + y*y);
    }
    inline double dot(vec2 v) {
        return x*v.x + y*v.y;
    }
    inline double comp(vec2 v) {
        return this->dot(v.unitVec());
    }
    inline vec2 proj(vec2 v) {
        return *this * v.unitVec();
    }

    // Accessors and Mutators
    inline double getX() {return this->x;}
    inline double getY() {return this->x;}
    inline void setX(double x) {this->x = x;}
    inline void setY(double y) {this->y = y;}

    // Operator overloads
    inline vec2 operator+(vec2 const& v)   {return vec2(x + v.x, y + v.y);}
    inline vec2 operator-(vec2 const& v)   {return vec2(x - v.x, y - v.y);}
    inline vec2 operator*(vec2 const& v)   {return vec2(x * v.x, y * v.y);}
    inline vec2 operator/(vec2 const& v)   {return vec2(x / v.x, y / v.y);}
    inline vec2 operator*(double const& s) {return vec2(x*s, y*s);}
    inline vec2 operator/(double const& s) {return vec2(x/s, y/s);}
    inline friend std::ostream& operator<<(std::ostream& os, vec2 const& v) {os << "vec2[" << v.x << ", " << v.y <<"]";return os;}


    // Other useful methods
    inline void to_string(char* buff, size_t len) {
        std::snprintf(buff, len, "vec2[%lf, %lf]", x, y);
    }
    static std::string to_string(vec2& v) {
        return "vec2[" + std::to_string(v.x) + ", " + std::to_string(v.y) + "]\n";
    }
};
