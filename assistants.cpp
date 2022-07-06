namespace assistants
{
	/*
	@pre: Needs an argument of size >= 3 or else there will be bounds errors.
	@post: The function will return a pointer pointing to a dynamic array of
	fibonnaci numbers. The size of the array will be as the user defined in the const
	int parameter.
	*/
	long long int* fibonnaci_array_PTR(const long long int size)
	{
		long long int* int_array_ptr = new long long int[size];

		long long int a_1 = 1;
		long long int a_2 = 2;

		int_array_ptr[0] = a_1;
		int_array_ptr[1] = a_2;

		for (long long int i = 2; i < size; i++)
		{
			int_array_ptr[i] = int_array_ptr[i - 1] + int_array_ptr[i - 2];
			//std::cout << int_array_ptr[i] << std::endl; //testing
		}

		return int_array_ptr;

	}

	bool isPrime(const int questionable)
	{
		bool prime_confirmed = true;

		for (int i = (questionable / 2); i > 0; i--)
		{
			if (questionable % 2 == 0 && (i != 1))
			{
				//the number is even
				i = 0;
				prime_confirmed = false;
			}
			else if ((questionable % i == 0) && (i != 1))
			{
				//number is divisible
				i = 0;
				prime_confirmed = false;
			}
		}
		return prime_confirmed;
	}


	//overload for LONG ints
	bool isPrime(const long long int questionable)
	{
		bool prime_confirmed = true;

		for (int i = (questionable / 2); i > 0; i--)
		{
			if (questionable % 2 == 0 && questionable != 2)
			{
				//the number is even
				i = 0;
				prime_confirmed = false;
			}
			else if ((questionable % i == 0) && (i != 1) && i != 2)
			{
				//number is divisible
				i = 0;
				prime_confirmed = false;
			}
		}
		return prime_confirmed;
	}

	bool isPalindrome(const int input)
	{
		bool palindrome_confirmed = false;
		int number = input;

		if (input > 100000)
		{
			int digits[6] = { 0, 0, 0, 0, 0, 0 };

			digits[0] = number / 100000;
			number -= 100000 * (digits[0]);

			digits[1] = number / 10000;
			number -= 10000 * (digits[1]);

			digits[2] = number / 1000;
			number -= 1000 * (digits[2]);

			digits[3] = number / 100;
			number -= 100 * (digits[3]);

			digits[4] = number / 10;
			number -= 10 * (digits[4]);

			digits[5] = number / 1;


			if (digits[0] == digits[5] && digits[1] == digits[4] && digits[2] == digits[3])
			{
				palindrome_confirmed = true;
			}
		}
		else
		{
			int digits[5] = { 0, 0, 0, 0, 0 };

			digits[0] = number / 10000;
			number -= 10000 * (digits[0]);

			digits[1] = number / 1000;
			number -= 1000 * (digits[1]);

			digits[2] = number / 100;
			number -= 100 * (digits[2]);

			digits[3] = number / 10;
			number -= 10 * (digits[3]);

			digits[4] = number / 1;

			if (digits[0] == digits[4] && digits[1] == digits[3])
			{
				palindrome_confirmed = true;
			}
		}
		return palindrome_confirmed;
	}

	int square(const int number)
	{
		return number * number;
	}

	bool isPythagTriple(const int a, const int b, const int c)
	{
		bool triple_confirmed = false;
		if (c < b && b < a && c < a)
		{
			//do nothing, it's not a triple
			// a<b<c must be the condition
		}
		else if(assistants::square(a) +
			assistants::square(b) ==
			assistants::square(c))
		{
			triple_confirmed = true;
		}

		return triple_confirmed;

	}

}
