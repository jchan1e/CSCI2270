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
	}    

	BigNum::BigNum(int num)
	{
	}

	// Constructor that receives a string; leading 0's will be ignored
	BigNum::BigNum(const string& strin)
	{
	}
 
    BigNum::BigNum(const BigNum& anotherBigNum)
    {
    }

    BigNum::~BigNum()
    {
    }
    
    void BigNum::resize(unsigned int n)
	{
	}

	BigNum& BigNum::operator=(const BigNum& anotherBigNum)
	{
		return *this;
	}

  
	BigNum& BigNum::operator+=(const BigNum& addend)  
	{
		return *this;
	}

	BigNum& BigNum::operator-=(const BigNum& subtractand)
	{
		return *this;
	}

	BigNum& BigNum::operator*=(const BigNum& multiplicand)
	{
		return *this;
	}

	BigNum& BigNum::operator/=(const BigNum& divisor)
	{
		return *this;
	}

	BigNum& BigNum::operator%=(const BigNum& divisor)
	{
		return *this;
	}

	BigNum& BigNum::operator++()
	{
		return *this;
	}

	BigNum& BigNum::operator--()
	{
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
		BigNum result;
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
		BigNum result;
		return result;
	}

	bool operator>(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator>=(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator<(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator<=(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator==(const BigNum& a, const BigNum& b)
	{
		return true;
	}


	bool operator!=(const BigNum& a, const BigNum& b)
	{
		return true;
	}

	// trim leading zeros
	void BigNum::trim()
	{
	}
	
	
	std::ostream& operator<<(std::ostream &os, const BigNum& bignum)
	{
		return os;
	}	 

	std::istream& operator>>(std::istream &is, BigNum& bignum)
	{
		return is;
	}
	
	BigNum factorial(const BigNum& a)
	{
		BigNum result;
		return result;
    }
  }



#endif



