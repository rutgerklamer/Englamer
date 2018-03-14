#include "Englamer\Maths\Vectorx.h"

/**
VECTOR 2
*/
template <typename X, typename Y>
bool Vectorx<typename X, typename Y>::operator==(const Vectorx<typename X, typename Y>& other) {
	return (this->x == other.x && this->y == other.y ? true : false);
}

template <typename X, typename Y>
bool Vectorx<typename X, typename Y>::operator!=(const Vectorx<typename X, typename Y>& other) {
	return (this->x != other.x || this->y != other.y ? true : false);
}

template <typename X, typename Y>
Vectorx<typename X, typename Y>& Vectorx<typename X, typename Y>::operator+=(const Vectorx<typename X, typename Y>& other) {
	this->x += other.x;
	this->y += other.y;
	return *this;
}

template <typename X, typename Y>
Vectorx<typename X, typename Y>& Vectorx<typename X, typename Y>::operator-=(const Vectorx<typename X, typename Y>& other) {
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

template <typename X, typename Y>
Vectorx<typename X, typename Y>& Vectorx<typename X, typename Y>::operator*=(const Vectorx<typename X, typename Y>& other) {
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

template <typename X, typename Y>
Vectorx<typename X, typename Y>& Vectorx<typename X, typename Y>::operator/=(const Vectorx<typename X, typename Y>& other) {
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

template <typename X, typename Y>
Vectorx<typename X, typename Y>& Vectorx<typename X, typename Y>::operator%=(const Vectorx<typename X, typename Y>& other) {
	this->x %= other.x;
	this->y %= other.y;
	return *this;
}

template <typename X, typename Y>
Vectorx<typename X, typename Y> Vectorx<typename X, typename Y>::operator+(const Vectorx<typename X, typename Y>& other) {
	return Vectorx<typename X, typename Y>(this->x + other.x, this->y + other.y);
}

template <typename X, typename Y>
Vectorx<typename X, typename Y> Vectorx<typename X, typename Y>::operator-(const Vectorx<typename X, typename Y>& other) {
	return Vectorx<typename X, typename Y>(this->x - other.x, this->y - other.y);
}

template <typename X, typename Y>
Vectorx<typename X, typename Y> Vectorx<typename X, typename Y>::operator*(const Vectorx<typename X, typename Y>& other) {
	return Vectorx<typename X, typename Y>(this->x * other.x, this->y * other.y);
}

template <typename X, typename Y>
Vectorx<typename X, typename Y> Vectorx<typename X, typename Y>::operator/(const Vectorx<typename X, typename Y>& other) {
	return Vectorx<typename X, typename Y>(this->x / other.x, this->y / other.y);
}

template <typename X, typename Y>
Vectorx<typename X, typename Y> Vectorx<typename X, typename Y>::operator%(const Vectorx<typename X, typename Y>& other) {
	return Vectorx<typename X, typename Y>(this->x % other.x, this->y % other.y);
}

template <typename X, typename Y>
std::ostream& operator<<(std::ostream& output, const Vectorx<typename X, typename Y> &other) {
	output << other.x << " " << other.y;
	return output;
}

/**
VECTOR 3
*/
template <typename X, typename Y, typename Z>
bool Vectorx<typename X, typename Y, typename Z>::operator==(const Vectorx<typename X, typename Y, typename Z>& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z ? true : false);
}

template <typename X, typename Y, typename Z>
bool Vectorx<typename X, typename Y, typename Z>::operator!=(const Vectorx<typename X, typename Y, typename Z>& other) {
	return (this->x != other.x || this->y != other.y || this->z != other.z ? true : false);
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z>& Vectorx<typename X, typename Y, typename Z>::operator+=(const Vectorx<typename X, typename Y, typename Z>& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	return *this;
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z>& Vectorx<typename X, typename Y, typename Z>::operator-=(const Vectorx<typename X, typename Y, typename Z>& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z>& Vectorx<typename X, typename Y, typename Z>::operator*=(const Vectorx<typename X, typename Y, typename Z>& other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	return *this;
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z>& Vectorx<typename X, typename Y, typename Z>::operator/=(const Vectorx<typename X, typename Y, typename Z>& other) {
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	return *this;
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z>& Vectorx<typename X, typename Y, typename Z>::operator%=(const Vectorx<typename X, typename Y, typename Z>& other) {
	this->x %= other.x;
	this->y %= other.y;
	this->z %= other.z;
	return *this;
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z> Vectorx<typename X, typename Y, typename Z>::operator+(const Vectorx<typename X, typename Y, typename Z>& other) {
	return Vectorx<typename X, typename Y, typename Z>(this->x + other.x, this->y + other.y, this->z + other.z);

}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z> Vectorx<typename X, typename Y, typename Z>::operator-(const Vectorx<typename X, typename Y, typename Z>& other) {
	return Vectorx<typename X, typename Y, typename Z>(this->x - other.x, this->y - other.y, this->z - other.z);
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z> Vectorx<typename X, typename Y, typename Z>::operator*(const Vectorx<typename X, typename Y, typename Z>& other) {
	return Vectorx<typename X, typename Y, typename Z>(this->x * other.x, this->y * other.y, this->z * other.z);
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z> Vectorx<typename X, typename Y, typename Z>::operator/(const Vectorx<typename X, typename Y, typename Z>& other) {
	return Vectorx<typename X, typename Y, typename Z>(this->x / other.x, this->y / other.y, this->z / other.z);
}

template <typename X, typename Y, typename Z>
Vectorx<typename X, typename Y, typename Z> Vectorx<typename X, typename Y, typename Z>::operator%(const Vectorx<typename X, typename Y, typename Z>& other) {
	return Vectorx<typename X, typename Y, typename Z>(this->x % other.x, this->y % other.y, this->z % other.z);
}

template <typename X, typename Y, typename Z>
std::ostream& operator<<(std::ostream& output, const Vectorx<typename X, typename Y, typename Z> &other) {
	output << other.x << " " << other.y << " " << other.z;
	return output;
}

/**
	VECTOR 4
	*/
template <typename X, typename Y, typename Z, typename W>
bool Vectorx<typename X, typename Y, typename Z, typename W>::operator==(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w ? true : false);
}

template <typename X, typename Y, typename Z, typename W>
bool Vectorx<typename X, typename Y, typename Z, typename W>::operator!=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return (this->x != other.x || this->y != other.y || this->z != other.z || this->w != other.w ? true : false);
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W>& Vectorx<typename X, typename Y, typename Z, typename W>::operator+=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
	return *this;
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W>& Vectorx<typename X, typename Y, typename Z, typename W>::operator-=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
	return *this;
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W>& Vectorx<typename X, typename Y, typename Z, typename W>::operator*=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
	this->w *= other.w;
	return *this;
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W>& Vectorx<typename X, typename Y, typename Z, typename W>::operator/=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	this->w /= other.w;
	return *this;
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W>& Vectorx<typename X, typename Y, typename Z, typename W>::operator%=(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	this->x %= other.x;
	this->y %= other.y;
	this->z %= other.z;
	this->w %= other.w;
	return *this;
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W> Vectorx<typename X, typename Y, typename Z, typename W>::operator+(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return Vectorx<typename X, typename Y, typename Z, typename W>(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);

}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W> Vectorx<typename X, typename Y, typename Z, typename W>::operator-(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return Vectorx<typename X, typename Y, typename Z, typename W>(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W> Vectorx<typename X, typename Y, typename Z, typename W>::operator*(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return Vectorx<typename X, typename Y, typename Z, typename W>(this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w);
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W> Vectorx<typename X, typename Y, typename Z, typename W>::operator/(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return Vectorx<typename X, typename Y, typename Z, typename W>(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

template <typename X, typename Y, typename Z, typename W>
Vectorx<typename X, typename Y, typename Z, typename W> Vectorx<typename X, typename Y, typename Z, typename W>::operator%(const Vectorx<typename X, typename Y, typename Z, typename W>& other) {
	return Vectorx<typename X, typename Y, typename Z, typename W>(this->x % other.x, this->y % other.y, this->z % other.z, this->w % other.w);
}

template <typename X, typename Y, typename Z, typename W>
std::ostream& operator<<(std::ostream& output, const Vectorx<typename X, typename Y, typename Z, typename W> &other) {
	output << other.x << " " << other.y << " " << other.z << " " << other.w;
	return output;
}