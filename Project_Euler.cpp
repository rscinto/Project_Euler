#include <iostream>
#include"assistants.cpp"
#include"number_list.h"
#include<iomanip>

void problem_1();
void problem_2();
void problem_3();
void problem_4();
void problem_5();
void problem_6();
void problem_7();
void problem_9();
void problem_10();

int main()
{
	std::cout << "Project Euler Collection" << std::endl;

	//problem_1();
	//problem_2();
	//problem_3();
	//problem_4();
	//problem_5();

	//find the difference of the sum of squares of the first 100 N #s
	//and the sum of the first 100 N numbers
	//problem_6();

	//Find the 10,001st prime number
	//problem_7();

	//need a matrix....thing
	//problem_8();

	//Finds pathagorean triple whose sum equals 1000. 
	//a<b<c where [a^2 + b^2 = c^2] && [a+b+c ==1000]
	//problem_9();

	/*
	Adding ~ sum: 142913828922 i: 1999999
	The sum pof primes below 2,000,000 is: 142913828922
	*/
	problem_10();


}

void problem_1()
{
	std::cout << "If we list all the natural numbers below 10 that are multiples of 3 or 5,\n"
		<< "we get 3, 5, 6 and 9. The sum of these multiples is 23.\n"
		<< "Find the sum of all the multiples of 3 or 5 below 1000.\n";

	int sum = 0;

	for (int i = 1; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	std::cout << "The sum of all multiples of 3 or 5 below 1000 is " << sum << std::endl;
}

void problem_2()
{
	long int sum_evens = 0;

	bool four_million_reached = false;

	double seed1 = 1;
	double seed2 = 2;
	double seed3 = 0;

	NumberList fibonacci_set;
	fibonacci_set.appendNode(seed1);
	fibonacci_set.appendNode(seed2);


	while (!four_million_reached)
	{

		if (seed3 > 4000000)
		{
			//do nothing
			four_million_reached = true;
		}
		else
		{
			seed3 = seed1 + seed2;
			fibonacci_set.appendNode(seed3);
			seed1 = seed2;
			seed2 = seed3;
		}
	}
	std::cout << std::fixed;
	std::cout << std::setprecision(2);

	std::cout << "The sum of all evens in the Fibonacci sequence under 4 million is: "
		<< fibonacci_set.sum_evens() << std::endl;
}

void problem_3()
{
	long long int main_prime = 600851475143;
	long int largest_prime = 0;


	for (long long int i = 2; i < (8000); i++)
	{
		if (assistants::isPrime(i) && ((600851475143 % i) == 0))
		{
			std::cout << "The number " << i << " is prime.\n";
			largest_prime = i;
		}
		else
		{
			std::cout << "The number " << i << " is NOT prime.\n";
		}
	}

	std::cout << "The largest prime factor of " << main_prime
		<< " is " << largest_prime << std::endl;


}

void problem_4()
{
	int largest_palindrome = 0;


	for (int outer = 999; outer >= 900; outer--)
	{
		for (int inner = 999; inner >= 900; inner--)
		{
			if (assistants::isPalindrome(outer * inner))
			{
				std::cout << "Palindrome found: " << outer << "x" << inner
					<< "= " << outer * inner << std::endl;
				if (outer * inner > largest_palindrome)
				{
					largest_palindrome = outer * inner;
				}
			}
			else
			{
				std::cout << "Product: " << outer << "x" << inner
					<< "= " << outer * inner << std::endl;
			}
		}
	}

	std::cout << "Larget palindrome: " << largest_palindrome << std::endl;


}

void problem_5()
{
	long long int target = NULL;
	long long int seeker = 20;
	bool found = false;


	while (!found)
	{
		if (seeker % 1 == 0 &&
			seeker % 2 == 0 &&
			seeker % 3 == 0 &&
			seeker % 4 == 0 &&
			seeker % 5 == 0 &&
			seeker % 6 == 0 &&
			seeker % 7 == 0 &&
			seeker % 8 == 0 &&
			seeker % 9 == 0 &&
			seeker % 10 == 0 &&
			seeker % 11 == 0 &&
			seeker % 12 == 0 &&
			seeker % 13 == 0 &&
			seeker % 14 == 0 &&
			seeker % 15 == 0 &&
			seeker % 16 == 0 &&
			seeker % 17 == 0 &&
			seeker % 18 == 0 &&
			seeker % 19 == 0 &&
			seeker % 20 == 0)
		{
			target = seeker;
			found = true;
		}
		else
		{
			seeker += 20;
			std::cout << "Seeking: " << seeker << std::endl;
		}
	}

	std::cout << "Target number found: " << target << std::endl;
}

void problem_6()
{
	int sum_of_naturals = 0;
	int sum_of_squares = 0;

	for (int i = 0; i <= 100; i++)
	{
		sum_of_naturals += i;
	}

	std::cout << "The sum of the first \n100 numbers is: " << sum_of_naturals << std::endl;
	std::cout << "The square of the sum \nof the first 100 numbers is: "
		<< assistants::square(sum_of_naturals) << std::endl << std::endl;

	for (int i = 0; i <= 100; i++)
	{
		sum_of_squares += assistants::square(i);
	}

	std::cout << "The sum of the first 100 squares numbers is: "
		<< sum_of_squares << std::endl;
	std::cout << "The square of sum of the first 100 numbers is: "
		<< assistants::square(sum_of_naturals) << std::endl;

	std::cout << "The difference of the sum of squares and the sum of naturals\n is: " <<
		assistants::square(sum_of_naturals) - sum_of_squares;
}

void problem_7()
{
	int target_prime = 0;
	bool target_found = false;
	int seed = 2;
	int prime_counter = 0;

	while (!target_found)
	{
		if (assistants::isPrime(seed))
		{
			prime_counter++;
			std::cout << "Prime found: " << seed << std::endl;
		}

		if (prime_counter == 10001)
		{
			target_found = true;
			target_prime = seed;
		}
		seed++;
	}

	std::cout << "The 10,001st prime is: " << target_prime << std::endl;
}

void problem_9()
{
	int a = NULL, b = NULL, c = NULL;

	const int GOAL_SUM = 1000;

	std::cout << "Test: " << std::endl;

	//test
	/*
	if (assistants::isPythagTriple(3,4,5))
	{
		std::cout << "test passed!" << std::endl;
	}
	else
	{

		std::cout << "test failed!" << std::endl;
	}
	*/

	for (int outer = 1; outer < GOAL_SUM; outer++)
	{
		a = outer;
		for (int middle = outer + 1; middle < GOAL_SUM; middle++)
		{
			b = middle;
			for (int inside = middle + 1; inside < GOAL_SUM; inside++)
			{
				c = inside;

				if ((a + b + c) < (GOAL_SUM - 100))
				{
					inside += 100;
					c = inside;
				}

				if (a + b + c > GOAL_SUM)
				{
					inside = GOAL_SUM;
					c = inside;
				}

				if ((outer + middle + inside == GOAL_SUM) &&
					assistants::isPythagTriple(outer, middle, inside))
				{
					std::cout << "The pythagorean triple is: \n" <<
						"a: " << outer << std::endl <<
						"b: " << middle << std::endl <<
						"c: " << inside << std::endl <<
						"a x b x c = " << outer * middle * inside << std::endl;
					//stops the program
					outer = middle = inside = GOAL_SUM;
				}
				else
				{
					std::cout << "searching~ a: " << outer << " b: " << middle
						<< " c: " << inside << std::endl;
				}
			}
		}
	}
	/*
	searching~ a: 200 b: 375 c: 424
	The pythagorean triple is:
	a: 200
	b: 375
	c: 425
	a x b x c = 31875000
	*/
}

void problem_10()
{
	unsigned long long int sum_primes = 0;

	for (long long int i = 2; i < 2000000; i++)
	{
		if (assistants::isPrime(i))
		{
			sum_primes += i;
		}
		std::cout << "Adding ~ sum: " << sum_primes << " i: " << i << std::endl;
	}
	std::cout << "The sum of all primes below 2,000,000 is: " << sum_primes << std::endl;
}