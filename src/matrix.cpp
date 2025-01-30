#include "matrix.h"
#include <stdexcept>

Matrix createMatrix(int rows, int cols)
{
	if (rows < 0 || cols < 0)
	{
		throw std::invalid_argument("Invalid row/column dimensions.");
	}

	Matrix outputM; // [row][column]

	if (rows == 0 && cols == 0) // 0x0 matrix
	{
		return outputM;
	}

	//if (rows == 0)
	//{
	//	for (int c = 0; c < cols; c++)
	//	{
	//		outputM.begin(.emplace_back();
	//	}
	//	return outputM;
	//}

	//if (cols == 0)
	//{
	//	for (int r = 0; r < rows; r++)
	//	{
	//		outputM.push_back({});
	//	}
	//	return outputM;
	//}

	for (size_t r = 0; r < rows; r++)
	{
		outputM.push_back({ 0 });
		for (size_t c = 1; c < cols; c++)
		{
			outputM[r].emplace_back(0);
		}
	}

	return outputM;
}

Matrix addMatrices(const Matrix& m1, const Matrix& m2)
{
	if (m1.size() != m2.size())
	{
		throw std::invalid_argument("Input matrices have a different row-size.");
	}

	if (m1[0].size() != m2[0].size())
	{
		throw std::invalid_argument("Input matrices have a different column-size.");
	}

	Matrix outputM = m1;;

	for (size_t r = 0; r < m1.size(); r++)
	{
		for (size_t c = 0; c < m1[0].size(); c++)
		{
			outputM[r][c] = m1[r][c] + m2[r][c];
		}
	}

	return outputM;
}

Matrix subtractMatrices(const Matrix& m1, const Matrix& m2)
{
	if (m1.size() != m2.size())
	{
		throw std::invalid_argument("Input matrices have a different row-size.");
	}

	if (m1[0].size() != m2[0].size())
	{
		throw std::invalid_argument("Input matrices have a different column-size.");
	}

	Matrix outputM = m1;;

	for (size_t r = 0; r < m1.size(); r++)
	{
		for (size_t c = 0; c < m1[0].size(); c++)
		{
			outputM[r][c] = m1[r][c] - m2[r][c];
		}
	}

	return outputM;
}

Matrix multiplyMatrices(const Matrix& m1, const Matrix& m2)
{
	if (m1[0].size() != m2.size())
	{
		throw std::invalid_argument("Input matrices have incompatible dimensions for this operation.");
	}

	Matrix outputM = createMatrix(m1.size(), m2[0].size());
	for (size_t r = 0; r < m1.size(); r++)
	{
		for (size_t c = 0; c < m2[0].size(); c++)
		{
			for (size_t i = 0; i < m1[0].size(); i++)
			{
				outputM[r][c] += m1[r][i] * m2[i][c];
			}
		}
	}

	return outputM;
}