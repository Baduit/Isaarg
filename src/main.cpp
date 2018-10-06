#include <iostream>
#include <map>

#include "Isaarg.hpp"

using namespace Isaarg;

int	main(int argc, char **argv)
{
	Args args(argc, argv);

	std::cout << "Args are" << std::endl;
	for (const auto& s: args.argv())
		std::cout << s << std::endl;
	std::cout << std::endl;

	std::cout << "First arg is (program name) "<< args[0] << " it was to test operator[](size_t)" << std::endl << std::endl;

	std::cout << "Flags are" << std::endl;
	for (const auto& s: args.getFlags())
		std::cout << s << std::endl;
	std::cout << std::endl;

	std::cout << "Options are" << std::endl;
	for (const auto& s: args.getOPtions())
	{
		std::cout << s.first << " == ";
		for (const auto& v: s.second)
			std::cout << v << " ";
		std::cout << std::endl;		
	}
	std::cout << std::endl;

	std::cout << "Is there an option named 'lait'" << std::endl;
	auto result = args.optionExist("lait") ? "yes" : "no";
	std::cout << result << std::endl << std::endl;

	std::cout << "Does this option have a value" << std::endl;
	if (args["lait"].has_value())
		std::cout << "yes and it is : " << *args["lait"] << std::endl;
	else
		std::cout << "no" << std::endl;

	return 0;
}
