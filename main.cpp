#ifdef USE_STD
# define NAMESPACE std
# include <vector>
# include <stack>
# include <map>
#else
# define NAMESPACE ft
# include "map.hpp"
# include "stack.hpp"
# include "vector.hpp"
#endif

#include <iostream>
#define SIZE 1000000

int	main(void)
{
	// MAP
	NAMESPACE::map<int, float>	map;
	for(int i = 0; i < SIZE; i++)
		map.insert(NAMESPACE::make_pair(i, 3.1415f));
	std::cout << "map size: " << map.size() << std::endl;
	if (SIZE > 4)
		std::cout << "map at 4: " << map.at(4) << std::endl;
	NAMESPACE::map<int, float>	new_map(map);
	for(int i = 0; i < SIZE; i++)
		map.erase(i);

	// STACK
	NAMESPACE::stack<int>	stack;
	for(int i = 0; i < SIZE; i++)
		stack.push(i);
	std::cout << "stack size: " << stack.size() << std::endl;
	NAMESPACE::stack<int>	new_stack(stack);
	for(int i = 0; i < SIZE; i++)
		stack.pop();

	// VECTOR
	NAMESPACE::vector<int>	vector;
	for(int i = 0; i < SIZE; i++)
		vector.push_back(i);
	std::cout << "vector size: " << vector.size() << std::endl;
	if (SIZE > 4)
		std::cout << "vector at 4: " << vector.at(4) << std::endl;
	NAMESPACE::vector<int>	new_vector(vector);
	for(int i = 0; i < SIZE; i++)
		vector.pop_back();
}
