    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Types.cpp                   //
////////////////////////////////////////

#include "Vectors.h"

#include <cmath>


////////////////
//  Vector2i  //
////////////////

snow::Vector2i::Vector2i() :
	x(0), y(0)
{
}

snow::Vector2i::Vector2i(const snow::Vector2i& vector) :
	x(vector.x), y(vector.y)
{
}

snow::Vector2i::Vector2i(int x, int y) :
	x(x), y(y)
{
}

snow::Vector2i::Vector2i(sf::Vector2i vector) :
	x(vector.x), y(vector.y)
{
}

snow::Vector2i::operator sf::Vector2i() const
{
	return sf::Vector2i(x, y);
}

snow::Vector2i snow::Vector2i::operator=(const snow::Vector2i& vector)
{
	x = vector.x;
	y = vector.y;
	return *this;
}

snow::Vector2i snow::Vector2i::operator+(const snow::Vector2i& vector) const
{
	snow::Vector2i result(x + vector.x, y + vector.y);
	return result;
}

snow::Vector2i snow::Vector2i::operator+=(const snow::Vector2i& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

snow::Vector2i snow::Vector2i::operator-(const snow::Vector2i& vector) const
{
	snow::Vector2i result(x - vector.x, y - vector.y);
	return result;
}

snow::Vector2i snow::Vector2i::operator-=(const snow::Vector2i& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

snow::Vector2i snow::Vector2i::operator*(int multiplier) const
{
	snow::Vector2i result(x * multiplier, y * multiplier);
	return result;
}

snow::Vector2i snow::operator*(const int& multiplier, const snow::Vector2i& vector)
{
	return vector * multiplier;
}

int snow::Vector2i::operator*(const snow::Vector2i& vector) const
{
	return x * vector.x + y * vector.y;
}

snow::Vector2i snow::Vector2i::operator*=(int multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}

snow::Vector2i snow::Vector2i::operator/(int divider) const
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector2i result(x / divider, y / divider);
	return result;
}

snow::Vector2i snow::Vector2i::operator/=(int divider)
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	return *this;
}

bool snow::Vector2i::operator==(const snow::Vector2i& vector) const
{
	return x == vector.x && y == vector.y;
}

bool snow::Vector2i::operator!=(const snow::Vector2i& vector) const
{
	return !(*this == vector);
}

snow::Vector2i snow::Vector2i::operator-() const
{
	snow::Vector2i result(-x, -y);
	return result;
}

float snow::Vector2i::length() const
{
	return static_cast<float>(sqrt(x * x + y * y));
}

float snow::Vector2i::getAngle() const
{
	return atan(static_cast<float>(y) / static_cast<float>(x));
}


////////////////
//  Vector2f  //
////////////////

snow::Vector2f::Vector2f() :
	x(0.f), y(0.f)
{
}

snow::Vector2f::Vector2f(const Vector2f& vector) :
	x(vector.x), y(vector.y)
{
}

snow::Vector2f::Vector2f(const Vector2i& vector) :
	x(static_cast<float>(vector.x)), y(static_cast<float>(vector.y))
{
}

snow::Vector2f::Vector2f(float x, float y) :
	x(x), y(y)
{
}

snow::Vector2f::Vector2f(double x, double y) :
	x(static_cast<float>(x)), y(static_cast<float>(y))
{
}

snow::Vector2f::Vector2f(int x, int y) :
	x(static_cast<float>(x)), y(static_cast<float>(y))
{
}

snow::Vector2f::Vector2f(sf::Vector2f vector) :
	x(vector.x), y(vector.y)
{
}

snow::Vector2f::operator sf::Vector2f()
{
	return sf::Vector2f(x, y);
}

snow::Vector2f snow::toVector2f(const Vector2i& vector)
{
	return snow::Vector2f(vector);
}

snow::Vector2i snow::Vector2f::toVector2i() const
{
	return snow::Vector2i(static_cast<int>(x), static_cast<int>(y));
}

snow::Vector2i snow::Vector2f::floor() const
{
	return snow::Vector2i(static_cast<int>(std::floor(x)), static_cast<int>(std::floor(y)));
}

snow::Vector2i snow::Vector2f::ceil() const
{
	return snow::Vector2i(static_cast<int>(std::ceil(x)), static_cast<int>(std::ceil(y)));
}

snow::Vector2i snow::Vector2f::round() const
{
	return snow::Vector2i(static_cast<int>(std::round(x)), static_cast<int>(std::round(y)));
}

snow::Vector2f snow::Vector2f::operator=(const snow::Vector2f& vector)
{
	x = vector.x;
	y = vector.y;
	return *this;
}

snow::Vector2f snow::Vector2f::operator=(const snow::Vector2i& vector)
{
	x = static_cast<float>(vector.x);
	y = static_cast<float>(vector.y);
	return *this;
}

snow::Vector2f snow::Vector2f::operator+(const snow::Vector2f& vector) const
{
	snow::Vector2f result(x + vector.x, y + vector.y);
	return result;
}

snow::Vector2f snow::Vector2f::operator+(const snow::Vector2i& vector) const
{
	snow::Vector2f result(x + vector.x, y + vector.y);
	return result;
}

snow::Vector2f snow::operator+(const snow::Vector2i& first, const snow::Vector2f& second)
{
	return second + first;
}

snow::Vector2f snow::Vector2f::operator+=(const snow::Vector2f& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

snow::Vector2f snow::Vector2f::operator+=(const snow::Vector2i& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

snow::Vector2f snow::Vector2f::operator-(const snow::Vector2f& vector) const
{
	snow::Vector2f result(x - vector.x, y - vector.y);
	return result;
}

snow::Vector2f snow::Vector2f::operator-(const snow::Vector2i& vector) const
{
	snow::Vector2f result(x - vector.x, y - vector.y);
	return result;
}

snow::Vector2f snow::operator-(const snow::Vector2i& first, const snow::Vector2f& second)
{
	snow::Vector2f result(first.x - second.x, first.y - second.y);
	return result;
}

snow::Vector2f snow::Vector2f::operator-=(const snow::Vector2f& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

snow::Vector2f snow::Vector2f::operator-=(const snow::Vector2i& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

snow::Vector2f snow::Vector2f::operator*(float multiplier) const
{
	snow::Vector2f result(x * multiplier, y * multiplier);
	return result;
}

snow::Vector2f snow::Vector2f::operator*(int multiplier) const
{
	snow::Vector2f result(x * multiplier, y * multiplier);
	return result;
}

snow::Vector2f snow::operator*(const float& multiplier, const snow::Vector2f& vector)
{
	return vector * multiplier;
}

snow::Vector2f snow::operator*(const int& multiplier, const snow::Vector2f& vector)
{
	return vector * multiplier;
}

float snow::Vector2f::operator*(const Vector2f& vector) const
{
	return x * vector.x + y * vector.y;
}

float snow::Vector2f::operator*(const Vector2i& vector) const
{
	return x * vector.x + y * vector.y;
}

float snow::operator*(const Vector2i& first, const Vector2f& second)
{
	return second * first;
}

snow::Vector2f snow::Vector2f::operator*=(float multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}

snow::Vector2f snow::Vector2f::operator*=(int multiplier)
{
	x *= multiplier;
	y *= multiplier;
	return *this;
}

snow::Vector2f snow::Vector2f::operator/(float divider) const
{
	if (divider == 0.f)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector2f result(x / divider, y / divider);
	return result;
}

snow::Vector2f snow::Vector2f::operator/(int divider) const
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector2f result(x / divider, y / divider);
	return result;
}

snow::Vector2f snow::Vector2f::operator/=(float divider)
{
	if (divider == 0.f)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	return *this;
}

snow::Vector2f snow::Vector2f::operator/=(int divider)
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	return *this;
}

bool snow::Vector2f::operator==(const Vector2f& vector) const
{
	return x == vector.x && y == vector.y;
}

bool snow::Vector2f::operator!=(const Vector2f& vector) const
{
	return !(*this == vector);
}

snow::Vector2f snow::Vector2f::operator-() const
{
	snow::Vector2f result(-x, -y);
	return result;
}

float snow::Vector2f::length() const
{
	return sqrt(x * x + y * y);
}

float snow::Vector2f::getAngle() const
{
	return atan(y / x);
}

float snow::Vector2f::rotate(float angle)
{
	float newAngle = getAngle() + angle;
	setAngle(newAngle);
	return newAngle;
}

void snow::Vector2f::setAngle(float angle)
{
	x = sqrt((x * x + y * y) / (1 + pow(tan(angle), 2)));
	y = x * tan(angle);
}


////////////////
//  Vector3i  //
////////////////

snow::Vector3i::Vector3i() :
	x(0), y(0), z(0)
{
}

snow::Vector3i::Vector3i(const snow::Vector3i& vector) :
	x(vector.x), y(vector.y), z(vector.z)
{
}

snow::Vector3i::Vector3i(int x, int y, int z) :
	x(x), y(y), z(z)
{
}

snow::Vector3i::Vector3i(sf::Vector3i vector) :
	x(vector.x), y(vector.y), z(vector.z)
{
}

snow::Vector3i::operator sf::Vector3i() const
{
	return sf::Vector3i(x, y, z);
}

snow::Vector3i snow::Vector3i::operator=(const snow::Vector3i& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

snow::Vector3i snow::Vector3i::operator+(const snow::Vector3i& vector) const
{
	snow::Vector3i result(x + vector.x, y + vector.y, z + vector.z);
	return result;
}

snow::Vector3i snow::Vector3i::operator+=(const snow::Vector3i& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

snow::Vector3i snow::Vector3i::operator-(const snow::Vector3i& vector) const
{
	snow::Vector3i result(x - vector.x, y - vector.y, z - vector.z);
	return result;
}

snow::Vector3i snow::Vector3i::operator-=(const snow::Vector3i& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

snow::Vector3i snow::Vector3i::operator*(int multiplier) const
{
	snow::Vector3i result(x * multiplier, y * multiplier, z * multiplier);
	return result;
}

snow::Vector3i snow::operator*(const int& multiplier, const snow::Vector3i& vector)
{
	return vector * multiplier;
}

int snow::Vector3i::operator*(const snow::Vector3i& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

snow::Vector3i snow::Vector3i::operator*=(int multiplier)
{
	x *= multiplier;
	y *= multiplier;
	z *= multiplier;
	return *this;
}

snow::Vector3i snow::Vector3i::operator/(int divider) const
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector3i result(x / divider, y / divider, z / divider);
	return result;
}

snow::Vector3i snow::Vector3i::operator/=(int divider)
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	z /= divider;
	return *this;
}

bool snow::Vector3i::operator==(const snow::Vector3i& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}

bool snow::Vector3i::operator!=(const snow::Vector3i& vector) const
{
	return !(*this == vector);
}

snow::Vector3i snow::Vector3i::operator-() const
{
	snow::Vector3i result(-x, -y, -z);
	return result;
}

float snow::Vector3i::length() const
{
	return static_cast<float>(sqrt(x * x + y * y + z * z));
}

float snow::Vector3i::getAngleXY() const
{
	return atan(static_cast<float>(y) / static_cast<float>(x));
}

float snow::Vector3i::getAngleZ() const
{
	return static_cast<float>(atan(static_cast<float>(z) / sqrt(x * x + y * y)));
}


////////////////
//  Vector3f  //
////////////////

snow::Vector3f::Vector3f() :
	x(0.f), y(0.f), z(0.f)
{
}

snow::Vector3f::Vector3f(const Vector3f& vector) :
	x(vector.x), y(vector.y), z(vector.z)
{
}

snow::Vector3f::Vector3f(const Vector3i& vector) :
	x(static_cast<float>(vector.x)),
	y(static_cast<float>(vector.y)),
	z(static_cast<float>(vector.z))
{
}

snow::Vector3f::Vector3f(float x, float y, float z) :
	x(x), y(y), z(z)
{
}

snow::Vector3f::Vector3f(double x, double y, double z) :
	x(static_cast<float>(x)),
	y(static_cast<float>(y)),
	z(static_cast<float>(z))
{
}

snow::Vector3f::Vector3f(int x, int y, int z) :
	x(static_cast<float>(x)),
	y(static_cast<float>(y)),
	z(static_cast<float>(z))
{
}

snow::Vector3f::Vector3f(sf::Vector3f vector) :
	x(vector.x), y(vector.y), z(vector.z)
{
}

snow::Vector3f::operator sf::Vector3f()
{
	return sf::Vector3f(x, y, z);
}

snow::Vector3f snow::toVector3f(const Vector3i& vector)
{
	return snow::Vector3f(vector);
}

snow::Vector3i snow::Vector3f::toVector3i() const
{
	return snow::Vector3i(static_cast<int>(x), static_cast<int>(y), static_cast<int>(z));
}

snow::Vector3i snow::Vector3f::floor() const
{
	return snow::Vector3i(static_cast<int>(std::floor(x)),
						  static_cast<int>(std::floor(y)),
						  static_cast<int>(std::floor(z)));
}

snow::Vector3i snow::Vector3f::ceil() const
{
	return snow::Vector3i(static_cast<int>(std::ceil(x)),
						  static_cast<int>(std::ceil(y)),
						  static_cast<int>(std::ceil(z)));
}

snow::Vector3i snow::Vector3f::round() const
{
	return snow::Vector3i(static_cast<int>(std::round(x)),
						  static_cast<int>(std::round(y)),
						  static_cast<int>(std::round(z)));
}

snow::Vector3f snow::Vector3f::operator=(const snow::Vector3f& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

snow::Vector3f snow::Vector3f::operator=(const snow::Vector3i& vector)
{
	x = static_cast<float>(vector.x);
	y = static_cast<float>(vector.y);
	z = static_cast<float>(vector.z);
	return *this;
}

snow::Vector3f snow::Vector3f::operator+(const snow::Vector3f& vector) const
{
	snow::Vector3f result(x + vector.x, y + vector.y, z + vector.z);
	return result;
}

snow::Vector3f snow::Vector3f::operator+(const snow::Vector3i& vector) const
{
	snow::Vector3f result(x + vector.x, y + vector.y, z + vector.z);
	return result;
}

snow::Vector3f snow::operator+(const snow::Vector3i& first, const snow::Vector3f& second)
{
	return second + first;
}

snow::Vector3f snow::Vector3f::operator+=(const snow::Vector3f& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

snow::Vector3f snow::Vector3f::operator+=(const snow::Vector3i& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

snow::Vector3f snow::Vector3f::operator-(const snow::Vector3f& vector) const
{
	snow::Vector3f result(x - vector.x, y - vector.y, z - vector.z);
	return result;
}

snow::Vector3f snow::Vector3f::operator-(const snow::Vector3i& vector) const
{
	snow::Vector3f result(x - vector.x, y - vector.y, z - vector.z);
	return result;
}

snow::Vector3f snow::operator-(const snow::Vector3i& first, const snow::Vector3f& second)
{
	snow::Vector3f result(first.x - second.x, first.y - second.y, first.z - second.z);
	return result;
}

snow::Vector3f snow::Vector3f::operator-=(const snow::Vector3f& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

snow::Vector3f snow::Vector3f::operator-=(const snow::Vector3i& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

snow::Vector3f snow::Vector3f::operator*(float multiplier) const
{
	snow::Vector3f result(x * multiplier, y * multiplier, z * multiplier);
	return result;
}

snow::Vector3f snow::Vector3f::operator*(int multiplier) const
{
	snow::Vector3f result(x * multiplier, y * multiplier, z * multiplier);
	return result;
}

snow::Vector3f snow::operator*(const float& multiplier, const snow::Vector3f& vector)
{
	return vector * multiplier;
}

snow::Vector3f snow::operator*(const int& multiplier, const snow::Vector3f& vector)
{
	return vector * multiplier;
}

float snow::Vector3f::operator*(const Vector3f& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

float snow::Vector3f::operator*(const Vector3i& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

float snow::operator*(const Vector3i& first, const Vector3f& second)
{
	return second * first;
}

snow::Vector3f snow::Vector3f::operator*=(float multiplier)
{
	x *= multiplier;
	y *= multiplier;
	z *= multiplier;
	return *this;
}

snow::Vector3f snow::Vector3f::operator*=(int multiplier)
{
	x *= multiplier;
	y *= multiplier;
	z *= multiplier;
	return *this;
}

snow::Vector3f snow::Vector3f::operator/(float divider) const
{
	if (divider == 0.f)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector3f result(x / divider, y / divider, z / divider);
	return result;
}

snow::Vector3f snow::Vector3f::operator/(int divider) const
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	snow::Vector3f result(x / divider, y / divider, z / divider);
	return result;
}

snow::Vector3f snow::Vector3f::operator/=(float divider)
{
	if (divider == 0.f)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	z /= divider;
	return *this;
}

snow::Vector3f snow::Vector3f::operator/=(int divider)
{
	if (divider == 0)
	{
		throw std::underflow_error("divide by zero");
	}
	x /= divider;
	y /= divider;
	z /= divider;
	return *this;
}

bool snow::Vector3f::operator==(const Vector3f& vector) const
{
	return x == vector.x && y == vector.y && z == vector.z;
}

bool snow::Vector3f::operator!=(const Vector3f& vector) const
{
	return !(*this == vector);
}

snow::Vector3f snow::Vector3f::operator-() const
{
	snow::Vector3f result(-x, -y, -z);
	return result;
}

float snow::Vector3f::length() const
{
	return sqrt(x * x + y * y + z * z);
}

float snow::Vector3f::getAngleXY() const
{
	return atan(y / x);
}

float snow::Vector3f::getAngleZ() const
{
	return atan(z / sqrt(x * x + y * y));
}

float snow::Vector3f::rotateXY(float angle)
{
	float newAngle = getAngleXY() + angle;
	setAngleXY(newAngle);
	return newAngle;
}

float snow::Vector3f::rotateZ(float angle)
{
	float newAngle = getAngleZ() + angle;
	setAngleZ(newAngle);
	return newAngle;
}

void snow::Vector3f::setAngleXY(float angle)
{
	x = sqrt((x * x + y * y) / (1 + pow(tan(angle), 2)));
	y = x * tan(angle);
}

void snow::Vector3f::setAngleZ(float angle)
{
	float xy = sqrt(x * x + y * y);
	xy = sqrt((xy * xy + z * z) / (1 + pow(tan(angle), 2)));
	z = xy * tan(angle);
	x = sqrt((xy * xy) / (1 + (y * y) / (x * x)));
	y = sqrt(xy * xy - x * x);
}