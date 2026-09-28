#include <vector>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdlib>

using namespace std;

void displayInt(int num)
{
	cout << num << " ";
}

int main()
{
	cout << "Number Cruncher Program\n\n";
	vector<int> numbers;
	int max = 100; // don't worry bout it
	numbers.reserve(max);

	srand(time(nullptr));

	for(int i = 0; i < numbers.capacity(); i++)
	{
		int number = rand() % 101;
		numbers.push_back(number);
	}
	cout << numbers.size() << " Random Numbers: ";
	for_each(numbers.begin(), numbers.end(), displayInt); 
	cout << "\n\n";

	//sort asc
	sort(numbers.begin(), numbers.end());

        cout << numbers.size() << " Sorted Numbers: ";
        for_each(numbers.begin(), numbers.end(), displayInt); 
        cout << "\n\n";

	//sum
	int sum = accumulate(numbers.begin(), numbers.end(), 0);//0 is start sum

        cout << "Sum of " << numbers.size() << " Numbers: " << sum; 
        cout << "\n\n";

	//avg
	int avg = sum / numbers.size();

        cout << "Average of " << numbers.size() << " Numbers: " << avg;
        cout << "\n\n";

	//max
	auto maxIter = max_element(numbers.begin(), numbers.end());
	cout << "Max of " << numbers.size() << " Numbers: " << *maxIter << "\n\n";

	//min
	auto minIter = min_element(numbers.begin(), numbers.end());
	cout << "Min of " << numbers.size() << " Numbers: " << *minIter << "\n\n";

	//binary search
	int num = 7;
	bool numExists = binary_search(numbers.begin(), numbers.end(), num);
	if(numExists)
	{
		int c = count(numbers.begin(), numbers.end(), num);
		cout << "The Number " << num << " Occurs " << c << " Time(s)\n\n";
	}
	else
	{
		cout << num << " Not Found\n\n";
	}
	return 0;
}




























