/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrix.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmckelvy <cmckelvy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 16:11:52 by cmckelvy          #+#    #+#             */
/*   Updated: 2020/10/17 17:43:43 by cmckelvy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iostream>
#include <vector>
#include <utility>
#include <optional>


class Matrix
{
private:
	int	_rows;
	int	_columns;
	std::vector<std::vector<int>> _data;
public:
	Matrix(void);
	Matrix(std::vector<std::vector<int>> data);
	Matrix(int rows, int columns);
	~Matrix(void);
	Matrix(const Matrix& cpy);
	Matrix& operator =(const Matrix& other);

	int		getRows(void) const;
	int		getColumns(void) const;
	std::vector<std::vector<int>> getData(void) const;
	std::pair<int, int> getDimensions(void) const;

	void	setData(std::vector<std::vector<int>> data);
	void	setEntry(int row, int col, int val);

	Matrix	add(Matrix other);
	Matrix	multiply(Matrix other);
	void	print(void);
};

#endif
