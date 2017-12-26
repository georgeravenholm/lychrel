#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // std::reverse
#include <cmath> // stD::pow

// class for number
struct num
{
	num( int i )
	{
		while(i) // its fine, no reference and sgit
		{
			d.push_back(i%10); // push right-most digit
			i /= 10; // cut off that digit
		}

		// we get a reverse order here, so we flip vectore
		reverse();
	}

	void reverse()
	{
		std::reverse(d.begin(),d.end());
	}
	
	unsigned long int revadd()
	{
		num rev(toint()); // copy

		rev.reverse();

		return toint() + rev.toint();
	}

	unsigned long int toint() const
	{
		unsigned long int i=0;
		int j = 0;
		for (auto n : d)
		{
			j++;
			i += n * std::pow(10,d.size()-j);
		}
		return i;
		
	}

	bool isDromic()
	{
		// // check if no. of digits is even
		//if (d.size() % 2 == 0) return false;

		// lel buttpaste
		decltype(d) first_half, second_half;
		auto half_way = d.size() / 2;
		std::copy(begin(d), begin(d)+half_way, back_inserter(first_half));
		std::copy(begin(d)+half_way, end(d), back_inserter(second_half));

		num h0(0); // new thing
		num h1(0);
		h0.d = first_half; h1.d=second_half;

		h1.reverse();
		if (d.size()%2!=0) h1.d.pop_back(); // remove middle digit if odde`
		
		// debug sgit
		//std::cout << h0.toint() << ":" << h1.toint() << std::endl;
		
		return h0.toint()==h1.toint();
	}
	
	std::vector<int> d;
};

int main()
{
	std::cout << "Hello, World!" << std::endl;

	num teste(47);	

	std::cout << teste.toint() << " -> " << teste.revadd() << std::endl;

	num pomf(12344321);
	std::cout << "is " << pomf.toint() << "paenl??!";;

	if (pomf.isDromic()) std::cout << "yes it is!";
	
	return 0;
}
