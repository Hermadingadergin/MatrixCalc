#define CATCH_CONFIG_MAIN			// this line tells Catch to provide a main() function
#define CATCH_CONFIG_COLOUR_NONE

#include "catch2\catch.hpp"
#include "matrix.h"

TEST_CASE("Test createMatrix")
{
	Matrix a = createMatrix(2, 4); // 2 by 4 matrix
	CHECK(a.size() == 2);
	for (size_t i = 0; i < a.size(); i++)
	{
		CHECK(a[i].size() == 4);
	}
	Matrix b = createMatrix(1, 1); // 1 by 1 square matrix
	CHECK(b.size() == 1);
	for (size_t i = 0; i < b.size(); i++)
	{
		CHECK(b[i].size() == 1);
	}

	Matrix c = createMatrix(4, 2); // 4 by 2 matrix
	CHECK(c.size() == 4);
	for (size_t i = 0; i < c.size(); i++)
	{
		CHECK(c[i].size() == 2);
	}
}

TEST_CASE("Test addMatrices")
{
	Matrix m1 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};

	Matrix m2 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};

	Matrix res1 = addMatrices(m1, m2); // since m1 and m2 are the same, checking to see if the sum is equal to double one of the matrices
	for (size_t r = 0; r < res1.size(); r++)
	{
		for (size_t c = 0; c < res1[0].size(); c++)
		{
			CHECK(res1[r][c] == 2 * m1[r][c]);
		}
	}

	Matrix m3 = { // 2 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
	};
	CHECK_THROWS(addMatrices(m1, m3)); // checking to see an error is thrown when row dimensions do not match

	Matrix m4 = { // 3 by 2 matrix
	{1, 2},
	{2, 3},
	{3, 4}
	};
	CHECK_THROWS(addMatrices(m1, m4)); // checking to see an error is thrown when row dimensions match but not column dimensions
}

TEST_CASE("Test subtractMatrices")
{
	Matrix m1 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};

	Matrix m2 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};

	Matrix res1 = subtractMatrices(m1, m2); // since m1 and m2 are the same, checking to see if the sum is equal a zero matrix
	for (size_t r = 0; r < res1.size(); r++)
	{
		for (size_t c = 0; c < res1[0].size(); c++)
		{
			CHECK(res1[r][c] == 0);
		}
	}

	Matrix m3 = { // 2 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
	};
	CHECK_THROWS(subtractMatrices(m1, m3)); // checking to see an error is thrown when row dimensions do not match

	Matrix m4 = { // 3 by 2 matrix
	{1, 2},
	{2, 3},
	{3, 4}
	};
	CHECK_THROWS(subtractMatrices(m1, m4)); // checking to see an error is thrown when row dimensions match but not column dimensions
}

TEST_CASE("Test multiplyMatrices")
{
	Matrix m1 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};
	
	Matrix m2 = { // 3 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5}
	};

	Matrix res1 = multiplyMatrices(m1, m2); // multiplying 2 "identical" matrices
	CHECK(res1[0][0] == 14);
	CHECK(res1[0][1] == 20);
	CHECK(res1[0][2] == 26);

	CHECK(res1[1][0] == 20);
	CHECK(res1[1][1] == 29);
	CHECK(res1[1][2] == 38);

	CHECK(res1[2][0] == 26);
	CHECK(res1[2][1] == 38);
	CHECK(res1[2][2] == 50);

	Matrix m3 = { // 2 by 4 matrix
		{2, 4, 6, 8},
		{1, 3, 5, 7},
	};

	Matrix m4 = { // 4 by 3 matrix
		{1, 2, 3},
		{2, 3, 4},
		{3, 4, 5},
		{4, 5, 6}
	};

	Matrix res2 = multiplyMatrices(m3, m4); // multiplying 2 compatible matrices with different dimensions
	CHECK(res2[0][0] == 60);
	CHECK(res2[0][1] == 80);
	CHECK(res2[0][2] == 100);

	CHECK(res2[1][0] == 50);
	CHECK(res2[1][1] == 66);
	CHECK(res2[1][2] == 82);

	CHECK_THROWS(multiplyMatrices(m4, m3)); // checking to see if an error is thrown when 2 incompatible matrices with different dimensions are multiplied
	CHECK_THROWS(multiplyMatrices(m4, m4)); // checking to see if an error is thrown when 2 incompatible matrices with the same dimensions are multiplied
}