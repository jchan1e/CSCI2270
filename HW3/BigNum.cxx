// FILENAME: BigNum.cxx
// This is the implementation file of the BigNum class


#ifndef HW3_BIGNUM_CXX
#define HW3_BIGNUM_CXX
#include <algorithm>   // Provides copy function
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include "BigNum.h"
using namespace std;

namespace HW3
{
	BigNum::BigNum()
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned char[capacity];
		digits[0] = 0;
		positive = true;
		used = 1;
	}

	BigNum::BigNum(int num)
	{
		capacity = DEFAULT_CAPACITY;
		digits = new unsigned char[capacity];
		used = 0;
		if (num < 0)		
		{
			positive = false;						//set sign
			num *= -1;
		}
		else
			positive = true;
		if (num == 0)
		{
			digits[0] = 0;
			used = 1;
		}
		for(int i = 0; num > 0; ++i)		//convert to base 100
			{
				digits[i] = num %100;
				num /= 100;
				++used;
			}
}

	// Constructor that receives a string; leading 0's will be ignored
	BigNum::BigNum(const string& strin)
	{
		string temp = strin;
		positive = true;
		if (temp[0] == '-')
		{
			positive = false;
			temp.erase(0,1);
		}
		while (temp[0] == '0')		//trim leading 0s
			temp.erase(0,1);
		if (temp.length() %2 == 1)
			temp.insert(0, "0");

		if (temp.empty())		//in case of empty string, use default constructor
		{
			capacity = DEFAULT_CAPACITY;
			digits = new unsigned char[capacity];
			digits[0] = 0;
			positive = true;
			used = 1;
		}
		else						//otherwise determine values and add
		{
			if (DEFAULT_CAPACITY < temp.length())
				capacity = temp.length();
			else
				capacity = DEFAULT_CAPACITY;
			digits = new unsigned char[capacity];
			int i = 0;
			used = 0;
			for(int j = temp.length(); j > 0; j-=2)
			{
				digits[i] = (char)atoi(temp.substr(j-2,2).c_str());
				++used;
				//printf("%d ", digits[i]);
				++i;
			}
			//cout << endl;
		}

	}

	BigNum::BigNum(const BigNum& anotherBigNum)
	{
		capacity = anotherBigNum.capacity;
		used = anotherBigNum.used;
		positive = anotherBigNum.positive;
		digits = new unsigned char[capacity];
		for(int i = 0; i < used; ++i)
			digits[i] = anotherBigNum.digits[i];
	}

	BigNum::~BigNum()
	{
		delete[] digits;
	}

	void BigNum::resize(unsigned int n)
	{
		if (n <= capacity)
			return;

		capacity = n;
		unsigned char* tmp = new unsigned char[capacity];

		for(int i = 0; i < used; ++i)
			tmp[i] = digits[i];

		delete[] digits;
		digits = tmp;
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		resize(anotherBigNum.capacity);
		used = anotherBigNum.used;
		positive = anotherBigNum.positive;
		for(int i = 0; i < used; ++i)
			digits[i] = anotherBigNum.digits[i];
		return *this;
	}


	BigNum& BigNum::operator+=(const BigNum& addend)  
	{
		*this = *this + addend;
		return *this;
	}

	BigNum& BigNum::operator-=(const BigNum& subtractand)
	{
		*this = *this - subtractand;
		return *this;
	}

	BigNum& BigNum::operator*=(const BigNum& multiplicand)
	{
		*this = *this * multiplicand;
		return *this;
	}

	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		*this = *this / divisor;
		return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		*this = *this % divisor;
		return *this;
	}

	BigNum& BigNum::operator++()
	{
		*this += 1;
		return *this;
	}

	BigNum& BigNum::operator--()
	{
		*this -= 1;
		return *this;
	}

	BigNum& BigNum::diff(const BigNum& a, const BigNum& b)
	{
		return *this;
	}


	BigNum& BigNum::mult(const BigNum& a, const BigNum& b)
	{
		return *this;
	}
	
	BigNum& BigNum::sum(const BigNum& a, const BigNum& b) 
	{
		return *this;
	}

	BigNum operator+(const BigNum& a, const BigNum& b)
	{
		BigNum result = a;
/*		if (a.capacity < b.capacity)
			a.resize(b.capacity);
		for(int i; i < a.used && i < b.used; ++i)
		{

		}*/
		return result;
	}

	BigNum operator-(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}

	BigNum operator*(const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}

	BigNum operator / (const BigNum& a, const BigNum& b)
	{
		BigNum result;
		return result;
	}


	BigNum operator%(const BigNum& a, const BigNum& b)
	{
		BigNum A = a;
		BigNum result;
		while (a >= b)
		{
			result = A - b; 
			A -= b;
		}
		return result;
	}

	bool operator>(const BigNum& a, const BigNum& b)
	{
		if (a.positive && !b.positive)
			return true;
		else if (!a.positive && b.positive)
			return false;
		else if (a.positive && b.positive)
		{
			if (a.used > b.used)
				return true;
			else if (a.used < b.used)
				return false;
			for(int i = a.used-1; i >= 0; --i)
			{
				if (a.digits[i] > b.digits[i])
					return true;
			}
		}
		else
		{
			if (a.used < b.used)
				return true;
			else if (a.used > b.used)
				return false;
			for(int i = a.used-1; i >= 0; --i)
			{
				if (a.digits[i] < b.digits[i])
					return true;
			}
		}
		return false;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		return a > b || a == b;
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		if (!a.positive && b.positive)
			return true;
		else if (a.positive && !b.positive)
			return false;
		else if (a.positive && b.positive)
		{
			if (a.used < b.used)
				return true;
			else if (a.used > b.used)
				return false;
			for(int i = a.used-1; i >= 0; --i)
			{
				if (a.digits[i] < b.digits[i])
					return true;
			}
		}
		else
		{
			if (a.used > b.used)
				return true;
			else if (a.used < b.used)
				return false;
			for(int i = a.used-1; i >= 0; --i)
			{
				if (a.digits[i] > b.digits[i])
					return true;
			}
		}
		return false;
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		return a < b || a == b;
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		if (a.positive != b.positive)
			return false;
		if (a.used != b.used)
			return false;
		for(int i = 0; i < a.used; ++i)
		{
			if (a.digits[i] != b.digits[i])
				return false;
		}
		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		return !(a == b);
	}

	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		char buf[4];
		string str;
		for(int i = bignum.used - 1; i >= 0; --i)
		{
			sprintf(buf, "%02d", bignum.digits[i]);
			str.append(buf);
//			cout << str << endl;
		}
		if (str[0] == '0')
			str.erase(0,1);
		if (!bignum.positive)
			str.insert(0, "-");
		os << str;
		return os;
	}	 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		string str;
		is >> str;
		BigNum tmp = BigNum(str);
		bignum = tmp;
		return is;
	}

	BigNum factorial(const BigNum& a)
	{
		BigNum result = 1;
		for(BigNum i = a; i > 1; --i)
			result *= i;
		return result;
	}
}



#endif



