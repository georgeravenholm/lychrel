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
	
	std::vector<int> d;
};

void print_vec(const std::vector<int>& vec)
{
	for (auto x: vec) {
		std::cout << ' ' << x;
	}
	std::cout << '\n';
}

int main()
{
	std::cout << "Hello, World!" << std::endl;

	num teste(47);
	print_vec(teste.d);	

	std::cout << teste.toint() << " -> " << teste.revadd() << std::endl;
	
	return 0;
}
