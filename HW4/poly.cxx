#include "poly.h"
using namespace std;

namespace main_savitch_5
{
	polynomial::polynomial(double c, unsigned int exponent)
	{
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
		head_ptr = new polynode;
		recent_ptr = head_ptr;
		tail_ptr = head_ptr;

		current_degree = 0;

		if (!(fabs(c) < EPSILON))
		{
			head_ptr->set_coef(c);
			head_ptr->set_exponent(exponent);
			current_degree = exponent;
		}
	}

	polynomial& polynomial::operator=(const polynomial& source)
	{
		if (this == &source)
			return *this;
		else
		{
		// store machine epsilon
			EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
			clear();
			for(int i = 0; i <= source.current_degree; ++i)
				assign_coef(source.coefficient(i),i);
			current_degree = tail_ptr->exponent();
			return *this;
		}
	}
	
	polynomial::polynomial(const polynomial& source)
	{
		// store machine epsilon
		EPSILON = std::numeric_limits<double>::epsilon();
		// write the rest
		head_ptr = new polynode;
		tail_ptr = head_ptr;
		current_degree = 0;
		*this = source;
	}

	polynomial::~polynomial()
	{
		clear();
	}

	void polynomial::clear()
	{
		recent_ptr = tail_ptr;
		while (recent_ptr != head_ptr)
		{
			recent_ptr = recent_ptr->back();
			delete recent_ptr->fore();
		}
		tail_ptr = head_ptr;
		head_ptr->set_fore(nullptr);
		head_ptr->set_coef(0.0);
		head_ptr->set_exponent(0);
		current_degree = 0;
	}
	
	double polynomial::coefficient(unsigned int exponent) const
	{
		set_recent(exponent);
		if (recent_ptr == nullptr)
			return 0.0;
		if (recent_ptr->exponent() == exponent)
			return recent_ptr->coef();
		else
			return 0.0;
	}

	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		set_recent(exponent);
		if (recent_ptr != nullptr && recent_ptr->exponent() == exponent)
			assign_coef(recent_ptr->coef() + amount, recent_ptr->exponent());
		else
			assign_coef(amount, exponent);
	}

	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		set_recent(exponent);
		if (recent_ptr != nullptr && recent_ptr->exponent() == exponent)
			recent_ptr->set_coef(coefficient);
		else if (recent_ptr == nullptr)
		{
			tail_ptr->set_fore(new polynode);
			recent_ptr = tail_ptr->fore();
			recent_ptr->set_back(tail_ptr);
			tail_ptr = recent_ptr;
			recent_ptr->set_coef(coefficient);
			recent_ptr->set_exponent(exponent);
			current_degree = tail_ptr->exponent();
		}
		else 
		{
			polynode* temp_ptr = recent_ptr->back();

			recent_ptr->set_back(new polynode);
			recent_ptr->back()->set_fore(recent_ptr);

			recent_ptr = recent_ptr->back();

			recent_ptr->set_back(temp_ptr);
			temp_ptr->set_fore(recent_ptr);

			recent_ptr->set_coef(coefficient);
			recent_ptr->set_exponent(exponent);
		}
		if (fabs(coefficient) < EPSILON)
		{
			if (recent_ptr->fore() == nullptr && recent_ptr->back() == nullptr)
			{
				recent_ptr->set_coef(0.0);
				recent_ptr->set_exponent(0);
				current_degree = 0;
				return;
			}
			else
			{
				if (recent_ptr->fore() != nullptr)
				{
					recent_ptr->fore()->set_back(recent_ptr->back());
				}
				if (recent_ptr->back() != nullptr)
				{
					recent_ptr->back()->set_fore(recent_ptr->fore());
				}

				if (recent_ptr == head_ptr)
					head_ptr = head_ptr->fore();
				else if (recent_ptr == tail_ptr)
				{
					tail_ptr = tail_ptr->back();
					current_degree = tail_ptr->exponent();
				}
				delete recent_ptr;
				recent_ptr = head_ptr;
			}
		}
	}

	unsigned int polynomial::next_term(unsigned int exponent) const
	{
		set_recent(exponent+1);
		//if (recent_ptr != nullptr && recent_ptr->exponent() == exponent)
		//	recent_ptr = recent_ptr->fore();
		if (recent_ptr == nullptr)
			return 0;
		else
			return recent_ptr->exponent();
	}

	unsigned int polynomial::previous_term(unsigned int exponent) const
	{
		if (exponent > current_degree)
			return tail_ptr->exponent();
		set_recent(exponent);
		recent_ptr = recent_ptr->back();
		if (recent_ptr != nullptr)
			return recent_ptr->exponent();
		else
			return UINT_MAX;
	}
	
	void polynomial::set_recent(unsigned int exponent) const
	{
		recent_ptr = head_ptr;
		while (recent_ptr != nullptr && recent_ptr->exponent() < exponent)
			recent_ptr = recent_ptr->fore();
	}
	
	double polynomial::eval(double x) const
	{
		double total = 0;
		recent_ptr = head_ptr;
		while (recent_ptr != nullptr)
		{
			total += pow(x, (double)recent_ptr->exponent()) * recent_ptr->coef();
			recent_ptr = recent_ptr->fore();
		}
		return total;
	}

	polynomial polynomial::derivative() const
	{
		polynomial p_prime(*this);

		p_prime.head_ptr = p_prime.head_ptr->fore();
		delete p_prime.head_ptr->back();
		p_prime.head_ptr->set_back(nullptr);
		p_prime.set_recent(0);
		while(p_prime.recent_ptr != nullptr)
		{
			p_prime.recent_ptr->set_coef(p_prime.recent_ptr->coef()*p_prime.recent_ptr->exponent());
			p_prime.recent_ptr->set_exponent(p_prime.recent_ptr->exponent()-1);
			p_prime.recent_ptr = p_prime.recent_ptr->fore();
		}
		p_prime.current_degree = p_prime.tail_ptr->exponent();
		return p_prime;
	}
	
	polynomial operator+(const polynomial& p1, const polynomial& p2)
	{
		polynomial p;
		unsigned int m = max(p1.degree(), p2.degree());
		for(unsigned int i = 0; i <= m; ++i)
		{
			if (p1.coefficient(i) != 0 || p2.coefficient(i) != 0)
				p.assign_coef(p1.coefficient(i)+p2.coefficient(i),i);
		}
		return p;
	}
	
	polynomial operator-(const polynomial& p1, const polynomial& p2)
	{
		polynomial p;
		unsigned int m = max(p1.degree(), p2.degree());
		for(unsigned int i = 0; i <= m; ++i)
		{
			if (p1.coefficient(i) != 0 || p2.coefficient(i) != 0)
				p.assign_coef(p1.coefficient(i)-p2.coefficient(i),i);
		}
		return p;
	}
	
	polynomial operator*(const polynomial& p1, const polynomial& p2)
	{		
		polynomial p;
		for(int i = 0; i <= p1.degree(); ++i)
		{
			for(int j = 0; j <= p2.degree(); ++j)
				p.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i+j);
		}
		return p;
	}

	ostream& operator << (ostream& out, const polynomial& p)
	{
		char buf[64];
		string str;
		int pd = p.degree();
		if (pd == 0 && p.coefficient(0) == 0.0)
			str.append("0");
		else
		{
			if (p.coefficient(pd) < 0.0)
				str.append("- ");
			sprintf(buf, "%fx^%d", p.coefficient(pd), pd);
			str.append(buf);
			for(int i = pd - 1; i > 0; --i)
			{
				if (p.coefficient(i) != 0.0)
				{
					if (p.coefficient(i) < 0.0)
						str.append(" - ");
					else
						str.append(" + ");
					sprintf(buf, "%fx^%d", p.coefficient(i), i);
					str.append(buf);
				}
			}
			if (pd != 0 && p.coefficient(0) != 0.0)
			{
				if (p.coefficient(0) < 0.0)
					str.append(" - ");
				else
					str.append(" + ");
				sprintf(buf, "%f", p.coefficient(0));
				str.append(buf);
			}
		}
		out << str;
		return out;
	}
	
	void polynomial::find_root(
	double& answer,
	bool& success,
	unsigned int& iterations,
	double guess,
	unsigned int maximum_iterations,
	double epsilon) const
	{
	}
}
