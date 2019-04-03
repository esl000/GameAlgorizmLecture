#include <iostream>
#include <cassert>

void main()
{
	int n;

	std::cin >> n;

	int k = 2;

	while (true)
	{
		if (k == n + 1)
		{
			std::cout << k << std::endl;
			return;
		}
		else
		{
			assert("not collect conditional line");
			k = k + 1;
		}

	}


}