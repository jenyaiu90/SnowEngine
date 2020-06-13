    ////////////////////////////////////////
   //         After by SnegirSoft        //
  //                                    //
 //  File: Types.h                     //
////////////////////////////////////////

////////////////////////////////////////////////////////////
///	\file
///	\brief The vectors are declared in this file.
///	
///	This files contains the declarations of the SnowEngine vectors: Vector2i, Vector2f, Vector3i
///	and Vector3f.
////////////////////////////////////////////////////////////

#pragma once

#include <SFML/System.hpp>
#include <stdexcept>

namespace snow
{

////////////////////////////////////////////////////////////
///	\brief A two-dimensional vector of integer
///	
///	This structure contains two integer variables: x and y. They are public and you can directly
///	change them values. Can be converted to and from sf::Vector2i (an SFML type).
////////////////////////////////////////////////////////////
struct Vector2i
{
	int x; ///< Vector`s x coordinate.
	int y; ///< Vector`s y coordinate.

	////////////////////////////////////////////////////////////
	///	/brief The default contructor, it sets a default value (0; 0).
	///	
	///	The default constructor of Vector2i. It sets a default value (0; 0).
	////////////////////////////////////////////////////////////
	Vector2i();

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2i(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed integer values.
	///	\param x,y Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2i(int x, int y);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector from sf::Vector2i.
	///
	///	This constructor allows you to create a snow::Vector2i from sf::Vector2i (an SFML type).
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2i(sf::Vector2i vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an SFML vector.
	///
	///	Allows to convert a snow::Vector2i to an sf::Vector2i (an SFML type). For example:
	///	\code
	///		snow::Vector2i snowVector;
	///		sf::Vector2i sfmlVector;
	///
	///		sfmlVector = (sf::Vector2i)snowVector; //C-style cast
	///		//or
	///		sfmlVector = static_cast<sf::Vector2i>(snowVector); //Static cast
	///	\endcode
	///	\return An SFML Vector2i that is equal to SnowEngine Vector2i.
	////////////////////////////////////////////////////////////
	operator sf::Vector2i() const;

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Just copies a value of a passed vector.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2i operator=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x and y values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector2i operator+(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2i operator+=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x and y values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector2i operator-(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2i operator-=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector2i operator*(int multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier.
	///	\param vector A multiplied vector.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector2i operator*(const int& multiplier, const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	int operator*(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///	
	///	Multiplies each coordinate of the vector by a passed integer and writes a result in the first
	///	operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2i operator*=(int multiplier);

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by an integer.
	///
	///	Divides each coordinate of the vector by a passed intger.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2i operator/(int divider) const;

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///	
	///	Divides each coordinate of the vector by a passed integer and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return The final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2i operator/=(int divider);

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors are equal.
	///
	///	Is used to check whether two vectors are equal.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are equal;
	///	- <b>false</b> if coordinates of the vectors are not equal.
	////////////////////////////////////////////////////////////
	bool operator==(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors have different values.
	///
	///	Is used to check whether two vectors have different values.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are not equal;
	///	- <b>false</b> if coordinates of the vectors are equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies vector by -1.
	///
	///	Change a sing of each coordinate of the vector.
	///	\return The result vector.
	////////////////////////////////////////////////////////////
	Vector2i operator-() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the length of the vector.
	///
	///	A length is calculating using the formula: \f$ \sqrt{ x^2 + y^2 } \f$.
	///	\return The length of the vector.
	////////////////////////////////////////////////////////////
	float length() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the vector and the x-axis in degrees.
	///
	///	This method allows to get the angle between the vector and the positive direction of the
	///	x-axis. This angle is used, for example, in polar coordinates.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngle() const;
};


////////////////////////////////////////////////////////////
///	\brief A two-dimensional vector of float
///	
///	This structure contains two float variables: x and y. They are public and you can directly
///	change them values. Can be converted to and from sf::Vector2f (an SFML type).
////////////////////////////////////////////////////////////
struct Vector2f
{
	float x; ///< Vector`s x coordinate.
	float y; ///< Vector`s y coordinate.

	////////////////////////////////////////////////////////////
	///	/brief The default contructor, it sets a default value (0.0; 0.0).
	///	
	///	The default constructor of Vector2i. It sets a default value (0.0; 0.0).
	////////////////////////////////////////////////////////////
	Vector2f();

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2f(const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector. It also authomatically coverts an
	///	integer vector to a float one.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2f(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed float values.
	///	\param x,y Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2f(float x, float y);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed integer values, that will be
	///	authomatically converted to a float.
	///	\param x,y Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2f(int x, int y);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector from sf::Vector2f.
	///
	///	This constructor allows you to create a snow::Vector2f from sf::Vector2f (an SFML type).
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector2f(sf::Vector2f vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an SFML vector.
	///
	///	Allows to convert a snow::Vector2f to an sf::Vector2f (an SFML type). For example:
	///	\code
	///		snow::Vector2f snowVector;
	///		sf::Vector2f sfmlVector;
	///
	///		sfmlVector = (sf::Vector2f)snowVector; //C-style cast
	///		//or
	///		sfmlVector = static_cast<sf::Vector2f>(snowVector); //Static cast
	///	\endcode
	///	\return An SFML Vector2f that is equal to SnowEngine Vector2f.
	////////////////////////////////////////////////////////////
	operator sf::Vector2f();

	////////////////////////////////////////////////////////////
	///	/brief Cast to a float vector.
	///
	///	Allows to convert a Vector2i to a Vector2f.
	///	\return A Vector2f that is equal to Vector2i.
	////////////////////////////////////////////////////////////
	friend Vector2f toVector2f(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an integer vector.
	///
	///	Allows to convert a Vector2f to a Vector2i.
	///	\warning This method removes a fractional parts of the coordinates of the vector. It can
	///	cause a data lose!
	///	\return A Vector2i that is <i>approximately<i> equal to Vector2f.
	////////////////////////////////////////////////////////////
	Vector2i toVector2i() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector down.
	///
	///	Works like an std::floor, rounds x and y coordinates of the vector down.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded down Vector2i.
	////////////////////////////////////////////////////////////
	Vector2i floor() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector up.
	///
	///	Works like an std::ceil, rounds x and y coordinates of the vector up.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded up Vector2i.
	////////////////////////////////////////////////////////////
	Vector2i ceil() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector to the nearest integer.
	///
	///	Works like an std::round, rounds each coordinate of the vector down if its first digit
	///	after the point is less then 5, else rounds it up.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded Vector2i.
	////////////////////////////////////////////////////////////
	Vector2i round() const;

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Just copies a value of a passed vector.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator=(const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Copies a value of a passed vector and converts its coordinates from integer to float.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x and y values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector2f operator+(const Vector2f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x and y values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector2f operator+(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x and y values of two vectors.
	///	\param first The first summand.
	///	\param second The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	friend Vector2f operator+(const Vector2i& first, const Vector2f& second);

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator+=(const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator+=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x and y values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector2f operator-(const Vector2f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x and y values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector2f operator-(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x and y values of two vectors.
	///	\param first The minuend
	///	\param second The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	friend Vector2f operator-(const Vector2i& first, const Vector2f& second);

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator-=(const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator-=(const Vector2i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a float.
	///
	///	Multiplies each coordinate of the vector by a passed float.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector2f operator*(float multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector2f operator*(int multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a float.
	///
	///	Multiplies each coordinate of the vector by a passed float.
	///	\param multiplier A multiplier :-D.
	///	\param vector A... vector!
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector2f operator*(const float& multiplier, const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed integer.
	///	\param multiplier A multiplier :-D.
	///	\param vector A... vector!
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector2f operator*(const int& multiplier, const Vector2f& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	float operator*(const Vector2f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	float operator*(const Vector2i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param first The first vector.
	///	\param second The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	friend float operator*(const Vector2i& first, const Vector2f& second);

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///	
	///	Multiplies each coordinate of the vector by a passed float and writes a result in the first
	///	operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator*=(float multiplier);

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///	
	///	Multiplies each coordinate of the vector by a passed int and writes a result in the first
	///	operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector2f operator*=(int multiplier);

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by a float.
	///
	///	Divides each coordinate of the vector by a passed float.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2f operator/(float divider) const;

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by an integer.
	///
	///	Divides each coordinate of the vector by a passed integer.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2f operator/(int divider) const;

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///	
	///	Divides each coordinate of the vector by a passed float and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return The final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2f operator/=(float divider);

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///	
	///	Divides each coordinate of the vector by a passed integer and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return The final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector2f operator/=(int divider);

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors are equal.
	///
	///	Is used to check whether two vectors are equal.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are equal;
	///	- <b>false</b> if coordinates of the vectors are not equal.
	////////////////////////////////////////////////////////////
	bool operator==(const Vector2f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors have different values.
	///
	///	Is used to check whether two vectors have different values.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are not equal;
	///	- <b>false</b> if coordinates of the vectors are equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const Vector2f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies vector by -1.
	///
	///	Change a sing of each coordinate of the vector.
	///	\return The result vector.
	////////////////////////////////////////////////////////////
	Vector2f operator-() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the length of the vector.
	///
	///	A length is calculating using the formula: \f$ \sqrt{ x^2 + y^2 } \f$.
	///	\return The length of the vector.
	////////////////////////////////////////////////////////////
	float length() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the vector and the x-axis in degrees.
	///
	///	This method allows to get the angle between the vector and the positive direction of the
	///	x-axis. This angle is used, for example, in polar coordinates.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngle() const;

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle of the vector without changing its length.
	///
	///	This method adds a passed angle to an angle between the vector and the positive direction
	///	of the x-axis and sets result for the vector. The length of the vector is not changed.
	///	\param angle An angle that will be added to an old one in degrees.
	///	\return A new angle between the vector and the positive direction of the x-axis.
	////////////////////////////////////////////////////////////
	float rotate(float angle);

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle of the vector without changing its length.
	///
	///	This method sets a passed angle as an angle between the vector and the positive direction
	///	of the x-axis. The length of the vector is not changed.
	///	\param angle An angle that will be set for the vector in degrees.
	////////////////////////////////////////////////////////////
	void setAngle(float angle);
};


////////////////////////////////////////////////////////////
///	\brief A three-dimensional vector of integer
///
///	This structure contains three integer variables: x, y and z. They are public and you can
///	directly change them values. Can be converted to and from sf::Vector3i (an SFML type).
////////////////////////////////////////////////////////////
struct Vector3i
{
	int x; ///< Vector`s x coordinate.
	int y; ///< Vector`s y coordinate.
	int z; ///< Vector`s z coordinate.

	////////////////////////////////////////////////////////////
	///	/brief The default contructor, it sets a default value (0; 0; 0).
	///
	///	The default constructor of Vector3i. It sets a default value (0; 0; 0).
	////////////////////////////////////////////////////////////
	Vector3i();

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3i(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed integer values.
	///	\param x,y,z Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3i(int x, int y, int z);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector from sf::Vector3i.
	///
	///	This constructor allows you to create a snow::Vector3i from sf::Vector3i (an SFML type).
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3i(sf::Vector3i vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an SFML vector.
	///
	///	Allows to convert a snow::Vector3i to an sf::Vector3i (an SFML type). For example:
	///	\code
	///		snow::Vector3i snowVector;
	///		sf::Vector3i sfmlVector;
	///
	///		sfmlVector = (sf::Vector3i)snowVector; //C-style cast
	///		//or
	///		sfmlVector = static_cast<sf::Vector3i>(snowVector); //Static cast
	///	\endcode
	///	\return An SFML Vector3i that is equal to SnowEngine Vector3i.
	////////////////////////////////////////////////////////////
	operator sf::Vector3i() const;

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Just copies a value of a passed vector.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3i operator=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x, y and z values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector3i operator+(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3i operator+=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x, y and z values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector3i operator-(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3i operator-=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector3i operator*(int multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier.
	///	\param vector A multiplied vector.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector3i operator*(const int& multiplier, const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	int operator*(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///
	///	Multiplies each coordinate of the vector by a passed integer and writes a result in the
	///	first operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3i operator*=(int multiplier);

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by an integer.
	///
	///	Divides each coordinate of the vector by a passed intger.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3i operator/(int divider) const;

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///
	///	Divides each coordinate of the vector by a passed integer and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return The final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3i operator/=(int divider);

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors are equal.
	///
	///	Is used to check whether two vectors are equal.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are equal;
	///	- <b>false</b> if coordinates of the vectors are not equal.
	////////////////////////////////////////////////////////////
	bool operator==(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors have different values.
	///
	///	Is used to check whether two vectors have different values.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are not equal;
	///	- <b>false</b> if coordinates of the vectors are equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies vector by -1.
	///
	///	Change a sing of each coordinate of the vector.
	///	\return The result vector.
	////////////////////////////////////////////////////////////
	Vector3i operator-() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the length of the vector.
	///
	///	A length is calculating using the formula: \f$ \sqrt{ x^2 + y^2 + z^2 } \f$.
	///	\return The length of the vector.
	////////////////////////////////////////////////////////////
	float length() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the projection of the vector on the xy-plane and x-axis.
	///
	///	This method allows to get the angle between the projection of the vector on the plane
	///	formed by the x- and y-axes and the positive direction of the x-axis. This angle is used,
	///	for example, in polar coordinates.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngleXY() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the vector and the xy-plane.
	///
	///	This method allows to get the angle between the vector and the plane formed by the x- and
	///	y-axes. This angle is used, for example, in polar coordinates. If the projection of the
	///	vector on z-axis has a negative direction, the method also returns a negative angle.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngleZ() const;
};


////////////////////////////////////////////////////////////
///	\brief A three-dimensional vector of float
///	
///	This structure contains three float variables: x, y and z. They are public and you can directly
///	change them values. Can be converted to and from sf::Vector3f (an SFML type).
////////////////////////////////////////////////////////////
struct Vector3f
{
	float x; ///< Vector`s x coordinate.
	float y; ///< Vector`s y coordinate.
	float z; ///< Vector`s z coordinate.

	////////////////////////////////////////////////////////////
	///	/brief The default contructor, it sets a default value (0.0; 0.0; 0.0).
	///	
	///	The default constructor of Vector3i. It sets a default value (0.0; 0.0; 0.0).
	////////////////////////////////////////////////////////////
	Vector3f();

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3f(const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that copies a vector.
	///
	///	The constructor that allows you to copy a vector. It also authomatically coverts an
	///	integer vector to a float one.
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3f(const Vector3i& vector);
	
	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed float values.
	///	\param x,y,x Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3f(float x, float y, float z);
	
	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector with passed values.
	///
	///	This constructor allows you to create a vector with passed integer values, that will be
	///	authomatically converted to a float.
	///	\param x,y,z Values that will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3f(int x, int y, int z);

	////////////////////////////////////////////////////////////
	///	\brief The constructor that create a vector from sf::Vector3f.
	///
	///	This constructor allows you to create a snow::Vector3f from sf::Vector3f (an SFML type).
	///	\param vector A source vector whose value will be set for new vector.
	////////////////////////////////////////////////////////////
	Vector3f(sf::Vector3f vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an SFML vector.
	///
	///	Allows to convert a snow::Vector3f to an sf::Vector3f (an SFML type). For example:
	///	\code
	///		snow::Vector3f snowVector;
	///		sf::Vector3f sfmlVector;
	///
	///		sfmlVector = (sf::Vector3f)snowVector; //C-style cast
	///		//or
	///		sfmlVector = static_cast<sf::Vector3f>(snowVector); //Static cast
	///	\endcode
	///	\return An SFML Vector3f that is equal to SnowEngine Vector2f.
	////////////////////////////////////////////////////////////
	operator sf::Vector3f();

	////////////////////////////////////////////////////////////
	///	/brief Cast to a float vector.
	///
	///	Allows to convert a Vector3i to a Vector3f.
	///	\return A Vector3f that is equal to Vector3i.
	////////////////////////////////////////////////////////////
	friend Vector3f toVector3f(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	/brief Cast to an integer vector.
	///
	///	Allows to convert a Vector3f to a Vector3i.
	///	\warning This method removes a fractional parts of the coordinates of the vector. It can
	///	cause a data lose!
	///	\return A Vector3i that is <i>approximately<i> equal to Vector3f.
	////////////////////////////////////////////////////////////
	Vector3i toVector3i() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector down.
	///
	///	Works like an std::floor, rounds x, y and z coordinates of the vector down.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded down Vector3i.
	////////////////////////////////////////////////////////////
	Vector3i floor() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector up.
	///
	///	Works like an std::ceil, rounds x, y and z coordinates of the vector up.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded up Vector3i.
	////////////////////////////////////////////////////////////
	Vector3i ceil() const;

	////////////////////////////////////////////////////////////
	///	\brief Rounds the vector to the nearest integer.
	///
	///	Works like an std::round, rounds each coordinate of the vector down if its first digit
	///	after the point is less then 5, else rounds it up.
	///	\warning A round operations can cause a data lose.
	///	\return A rounded Vector3i.
	////////////////////////////////////////////////////////////
	Vector3i round() const;

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Just copies a value of a passed vector.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator=(const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief An assignment of vectors.
	///
	///	Copies a value of a passed vector and converts its coordinates from integer to float.
	///	\param vector A source vector, its value will be copied.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x, y and z values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector3f operator+(const Vector3f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x, y and z values of two vectors.
	///	\param vector The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	Vector3f operator+(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to add two vectors.
	///
	///	This operator adds the x, y and z values of two vectors.
	///	\param first The first summand.
	///	\param second The second summand.
	///	\return The result of addition of two vectors.
	////////////////////////////////////////////////////////////
	friend Vector3f operator+(const Vector3i& first, const Vector3f& second);

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator+=(const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief An addition with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The second summand.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator+=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x, y and z values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector3f operator-(const Vector3f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x, y and z values of two vectors.
	///	\param vector The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	Vector3f operator-(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Allows to subtract two vectors.
	///
	///	This operator subtracts the x, y and z values of two vectors.
	///	\param first The minuend
	///	\param second The subtrahend.
	///	\return The result of the subtraction.
	////////////////////////////////////////////////////////////
	friend Vector3f operator-(const Vector3i& first, const Vector3f& second);

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator-=(const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief A subtraction with an assignment.
	///
	///	Adds two vectors and writes a result in the first operand.
	///	\param vector The subtrahend.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator-=(const Vector3i& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a float.
	///
	///	Multiplies each coordinate of the vector by a passed float.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector3f operator*(float multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed intger.
	///	\param multiplier A multiplier :-D.
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	Vector3f operator*(int multiplier) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a float.
	///
	///	Multiplies each coordinate of the vector by a passed float.
	///	\param multiplier A multiplier :-D.
	///	\param vector A... vector!
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector3f operator*(const float& multiplier, const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by an integer.
	///
	///	Multiplies each coordinate of the vector by a passed integer.
	///	\param multiplier A multiplier :-D.
	///	\param vector A... vector!
	///	\return The result of the multiplication.
	////////////////////////////////////////////////////////////
	friend Vector3f operator*(const int& multiplier, const Vector3f& vector);

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	float operator*(const Vector3f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param vector The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	float operator*(const Vector3i& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies a vector by a vector.
	///
	///	Calculates a scalar product of two vectors.
	///	\param first The first vector.
	///	\param second The second vector.
	///	\return The result of the scalar product.
	////////////////////////////////////////////////////////////
	friend float operator*(const Vector3i& first, const Vector3f& second);

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///	
	///	Multiplies each coordinate of the vector by a passed float and writes a result in the
	///	first operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator*=(float multiplier);

	////////////////////////////////////////////////////////////
	///	\brief A multiplication with an assignment.
	///	
	///	Multiplies each coordinate of the vector by a passed int and writes a result in the first
	///	operand.
	///	\param multiplier A multiplier :-D.
	///	\return The final vector.
	////////////////////////////////////////////////////////////
	Vector3f operator*=(int multiplier);

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by a float.
	///
	///	Divides each coordinate of the vector by a passed float.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3f operator/(float divider) const;

	////////////////////////////////////////////////////////////
	///	\brief Divides a vector by an integer.
	///
	///	Divides each coordinate of the vector by a passed integer.
	///	\param divider A divider :-D.
	///	\return The result of the division.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3f operator/(int divider) const;

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///	
	///	Divides each coordinate of the vector by a passed float and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return The final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3f operator/=(float divider);

	////////////////////////////////////////////////////////////
	///	\brief A division with an assignment.
	///	
	///	Divides each coordinate of the vector by a passed integer and writes a result in the first
	///	operand.
	///	\param divider A divider :-D.
	///	\return An address of the final vector.
	///	\throws std::underflow_error when trying to divide by zero.
	////////////////////////////////////////////////////////////
	Vector3f operator/=(int divider);

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors are equal.
	///
	///	Is used to check whether two vectors are equal.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are equal;
	///	- <b>false</b> if coordinates of the vectors are not equal.
	////////////////////////////////////////////////////////////
	bool operator==(const Vector3f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Check whether two vectors have different values.
	///
	///	Is used to check whether two vectors have different values.
	///	\param vector The second vector to compare.
	///	\return
	///	- <b>true</b> if coordinates of the vectors are not equal;
	///	- <b>false</b> if coordinates of the vectors are equal.
	////////////////////////////////////////////////////////////
	bool operator!=(const Vector3f& vector) const;

	////////////////////////////////////////////////////////////
	///	\brief Multiplies vector by -1.
	///
	///	Change a sing of each coordinate of the vector.
	///	\return The result vector.
	////////////////////////////////////////////////////////////
	Vector3f operator-() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the length of the vector.
	///
	///	A length is calculating using the formula: \f$ \sqrt{ x^2 + y^2 + z^2 } \f$.
	///	\return The length of the vector.
	////////////////////////////////////////////////////////////
	float length() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the projection of the vector on the xy-plane and x-axis.
	///
	///	This method allows to get the angle between the projection of the vector on the plane
	///	formed by the x- and y-axes and the positive direction of the x-axis. This angle is used,
	///	for example, in polar coordinates.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngleXY() const;

	////////////////////////////////////////////////////////////
	///	\brief Returns the angle between the vector and the xy-plane.
	///
	///	This method allows to get the angle between the vector and the plane formed by the x- and
	///	y-axes. This angle is used, for example, in polar coordinates. If the projection of the
	///	vector on z-axis has a negative direction, the method also returns a negative angle.
	///	\return The angle in degrees.
	////////////////////////////////////////////////////////////
	float getAngleZ() const;

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle between the projection of the vector on the xy-plane and x-axis
	///	without changing the length.
	///
	///	This method adds a passed angle to an angle between the projection of the vector on the
	///	xy-plane and x-axis and sets result for the vector. The length of the vector is not changed.
	///	\param angle An angle that will be added to an old one in degrees.
	///	\return A new angle between the projection of the vector on the xy-plane and x-axis.
	////////////////////////////////////////////////////////////
	float rotateXY(float angle);

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle between the vector and the xy-plane without changing the length.
	///
	///	This method adds a passed angle to an angle between between the vector and the xy-plane
	///	and sets result for the vector. The length of the vector is not changed. For a vector whose
	///	projection on the z-axis has the negative direction that angle is also negative.
	///	\param angle An angle that will be added to an old one in degrees.
	///	\return A new angle between the vector and the xy-plane.
	////////////////////////////////////////////////////////////
	float rotateZ(float angle);

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle between the projection of the vector on the xy-plane and x-axis
	///	without changing the length.
	///
	///	This method sets a passed angle as an angle between the projection of the vector on the
	///	xy-plane and x-axis. The length of the vector is not changed.
	///	\param angle An angle that will be set for the vector in degrees.
	////////////////////////////////////////////////////////////
	void setAngleXY(float angle);

	////////////////////////////////////////////////////////////
	///	\brief Changes the angle between the vector and the xy-plane without changing the length.
	///
	///	This method sets a passed angle as an angle between the vector and the xy-plane. The
	///	length of the vector is not changed.
	///	\param angle An angle that will be set for the vector in degrees.
	////////////////////////////////////////////////////////////
	void setAngleZ(float angle);
};

}
