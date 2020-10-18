/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:25:09 by cmckelvy          #+#    #+#             */
/*   Updated: 2020/10/17 17:51:28 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrix.hpp"

Matrix::Matrix(void) : _rows(0), _columns(0){}

//lacks any sort of data validation
Matrix::Matrix(std::vector<std::vector<int>> data) : _rows(data.size()), _columns(data.size() ? data[0].size() : 0), _data(data) {}
Matrix::Matrix(int rows, int columns) : _rows(rows), _columns(columns)
{
	for (int i = 0; i < rows; i++)
	{
		std::vector<int> col(columns, 0);
		_data.push_back(col);
	}
}
Matrix::~Matrix(void) {}

Matrix::Matrix(const Matrix& cpy)
	{ *this = cpy; }

Matrix& Matrix::operator =(const Matrix& other)
{
	_rows = other.getRows();
	_columns = other.getColumns();
	_data = other.getData();
	return *this;
}

int	Matrix::getRows(void) const
{ return _rows; }

int	Matrix::getColumns(void) const
{ return _columns; }

std::vector<std::vector<int>> Matrix::getData(void) const
{ return _data; }

std::pair<int, int> Matrix::getDimensions(void) const
{ return (std::make_pair(_rows, _columns)); }

void	Matrix::setData(std::vector<std::vector<int>> data)
{
	_data = data;
	_rows = data.size();
	_columns = _rows ? data[0].size() : 0;
}
void	Matrix::setEntry(int row, int col, int val)
{
	try
	{
		_data[row][col] = val;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}


Matrix Matrix::add(Matrix other)
{
	if (this->getDimensions() != other.getDimensions())
	{
		std::cerr << "Tried to add matrices with different dimensions!\n";
		return *this;
	}

	Matrix result(_rows, _columns);
	std::vector<std::vector<int>> otherData;

	otherData = other.getData();
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
			result.setEntry(i, j, _data[i][j] + otherData[i][j]);
	}
	return result;
}
Matrix Matrix::multiply(Matrix other)
{
	if (_columns != other.getRows())
	{
		std::cerr << "Tried to multiply matrices with mismatched dimensions!\n";
		return *this;
	}

	Matrix dotProduct(_rows, other.getColumns());
	std::vector<std::vector<int>> otherData = other.getData();
	for (int i = 0; i < dotProduct.getRows(); i++)
	{
		for (int j = 0; j < dotProduct.getColumns(); j++)
		{
			int sum = 0;
			for (int k = 0; k < _columns; k++)
			{
				sum += _data[i][k] * otherData[k][j];
			}
			dotProduct.setEntry(i, j, sum);
		}
	}
	return dotProduct;
}

void	Matrix::print(void)
{
	for (int i = 0; i < _rows; i++)
	{
		for (int j = 0; j < _columns; j++)
		{
			std::cout << _data[i][j];
			if (j == _columns - 1)
				std::cout << '\n';
			else
			{
				std::cout << "  ";
			}
		}
	}
}
