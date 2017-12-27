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

	unsigned long long toint() const
	{
		unsigned long long i=0;
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
		if (d.size()==1) return true ; // 1 digit numbers are palendromic
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

int iterate(int n)
{
	num a(n);
	int i = 1; 	// start at one, because we will manualo revadd once so that already 'dromic
				// unumbers dont frick my sgit
	a.revadd();	// compensate for pre-palendromic numbers

	if (a.isDromic()) return i; // if it is already dronic after this one, bypass! 
	
	do
	{
		a = num(a.revadd());
		i++;
		//std::cout << "try " << i << "\t" << a.toint() << "\n";

		// check if is a potential lychrel number
		if (a.toint()==0) return 0;
	} while (!a.isDromic());

	return i;
}

int main()
{
	/*std::cout << "Hello, World!" << std::endl;

	num teste(47);	

	std::cout << teste.toint() << " -> " << teste.revadd() << std::endl;

	num pomf(12344321);
	std::cout << "is " << pomf.toint() << "paenl??!";;

	if (pomf.isDromic()) std::cout << "yes it is!";

	std::cout << "-------------\nIterations of " << 10000 << "=" << iterate(10000)<< std::endl;*/

	// Main sgit!!!
	#define TIMES 10000
	
	std::vector<int> lychrels(TIMES);
	unsigned int c = 0;
	for (int n=1 ; n <= TIMES ; ++n)
	{
		int i = iterate(n);
		if (i != 0) std::cout << n << "\ttook " << i << "x iterations!";
		else
		{
			std::cout << "\t\t\t" << n << " is a potential lychrel";
			lychrels.push_back(n);
			c++; //lol
		}
		std::cout << std::endl;
	}

	std::cout << "potential lychrel numbers are:\n";
	
	for ( int n : lychrels ) {if (n==0) continue; std::cout << n << ",";}
	std::cout << "theres bloody " << c << " of 'em!" << std::endl;
	return 0;
}
