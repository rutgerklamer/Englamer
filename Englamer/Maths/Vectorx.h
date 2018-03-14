#ifndef VECTORX_H
#define VECTORX_H

#include <iostream>

template <typename...> class Vectorx;

typedef Vectorx<int, int> Vector2i;
typedef Vectorx<float, float> Vector2f;
typedef Vectorx<double, double> Vector2d;
typedef Vector2f vec2;
typedef Vectorx<int, int, int> Vector3i;
typedef Vectorx<float, float, float> Vector3f;
typedef Vectorx<double, double, double> Vector3d;
typedef Vector3f vec3;
typedef Vectorx<int, int, int, int> Vector4i;
typedef Vectorx<float, float, float, float> Vector4f;
typedef Vectorx<double, double, double, double> Vector4d;
typedef Vector4f vec4;

/**
DECLARE VECTOR 2,3,4
*/
template <typename X, typename Y>
class Vectorx<X, Y>
{
public:
	Vectorx<X, Y>(X xx, Y yy);
	bool operator==(const Vectorx<typename X, typename Y> &other);
	bool operator!=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y>& operator+=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y>& operator-=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y>& operator*=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y>& operator/=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y>& operator%=(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y> operator+(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y> operator-(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y> operator*(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y> operator/(const Vectorx<typename X, typename Y> &other);
	Vectorx<typename X, typename Y> operator%(const Vectorx<typename X, typename Y> &other);
	X x;
	Y y;
};

template <typename X, typename Y, typename Z>
class Vectorx<X, Y, Z>
{
public:
	Vectorx<X, Y, Z>(X xx, Y yy, Z zz);
	bool operator==(const Vectorx<typename X, typename Y, typename Z> &other);
	bool operator!=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z>& operator+=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z>& operator-=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z>& operator*=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z>& operator/=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z>& operator%=(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z> operator+(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z> operator-(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z> operator*(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z> operator/(const Vectorx<typename X, typename Y, typename Z> &other);
	Vectorx<typename X, typename Y, typename Z> operator%(const Vectorx<typename X, typename Y, typename Z> &other);
	X x;
	Y y;
	Z z;
};

template <typename X, typename Y, typename Z, typename W>
class Vectorx<X, Y, Z, W>
{
public:
	Vectorx<X, Y, Z, W>(X xx, Y yy, Z zz, W ww);
	bool operator==(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	bool operator!=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W>& operator+=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W>& operator-=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W>& operator*=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W>& operator/=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W>& operator%=(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W> operator+(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W> operator-(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W> operator*(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W> operator/(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	Vectorx<typename X, typename Y, typename Z, typename W> operator%(const Vectorx<typename X, typename Y, typename Z, typename W> &other);
	X x;
	Y y;
	Z z;
	W w;

};
#include "Englamer\Maths\Vectorxoperators.h"

/**
	VECTOR 2
	*/
template <typename X, typename Y>
Vectorx<X, Y>::Vectorx(X xx, Y yy) {
	this->x = xx;
	this->y = yy;
}

/**
	VECTOR 3
	*/
template <typename X, typename Y, typename Z>
Vectorx<X, Y, Z>::Vectorx(X xx, Y yy, Z zz) {
	this->x = xx;
	this->y = yy;
	this->z = zz;
}

/**
	VECTOR 4
	*/
template <typename X, typename Y, typename Z, typename W>
Vectorx<X, Y, Z, W>::Vectorx(X xx, Y yy, Z zz, W ww) {
	this->x = xx;
	this->y = yy;
	this->z = zz;
	this->w = ww;
}

#endif VECTORX_H
