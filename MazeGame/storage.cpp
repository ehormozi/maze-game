#include "header.h"

template <typename T>
storage<T>::storage(size_t n)
{
	if (n != (std::sqrt(n)) * (std::sqrt(n)))
	{
		throw "n is not valid";
	}
	n_ = n;
	elements_ = std::vector<T>(n);
}

template <typename T>
T& storage<T>::operator()(point2d p)
{
	if (p.x >= std::sqrt(n_) || p.y >= std::sqrt(n_))
	{
		throw std::out_of_range("point not valid");
	}
	return elements_[p.x * std::sqrt(n_) + p.y];
}

template <typename T>
T storage<T>::operator()(point2d p) const
{
	if (p.x >= std::sqrt(n_) || p.y >= std::sqrt(n_))
	{
		throw std::out_of_range("point not valid");
	}
	return elements_[p.x * std::sqrt(n_) + p.y];
}

template <typename T>
coord storage<T>::max_coord() const
{
	return std::sqrt(n_) - 1;
}

template <typename T>
bool storage<T>::has_point(const point2d& p) const
{
	return p.x <= max_coord() && p.y <= max_coord();
}

template <typename T>
void storage<T>::reserve(unsigned n)
{
	elements_.reserve(n);
}

template <typename T>
void storage<T>::resize(unsigned n)
{
	if (n != (std::sqrt(n)) * (std::sqrt(n)))
	{
		throw "n is not valid";
	}
	elements_.resize(n);
	n_ = n;
}

template <typename T>
std::vector<T>& storage<T>::get_storage()
{
	return elements_;
}
