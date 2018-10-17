# Isaarg

## Description
A simple, header-only C++ library for parameters management.

## Requirements
C++17 __string_view__ and __optional__ classes from the STD library are needed. One can also use an older STD version with an experimental implementation. Another solution is to use alternatives, like optionnal implementation from boost.

## Terminology used in the library
In the library i separate arguments in 3 categories:
* A __value__: A value is everything that is not a flag or an option.
* A __flag__: A flag is a single character long only and is preceed by one '-' only (example __-A__ or __-b__). It can also be chained wit other flags (example __-Ab__ does the same as __-A -b__).
* An __option__: An option is composed of one or more character and is preceed by 2 '-' (example --version). All values after the the option and until the next flag or option are consireded as the option's values (example --file patate.txt plop.txt -a the values are of the option file are patate.txt and plop.txt )

## Quick interface explanations
First create an instance of __Isaag::Args__ with argc and argv as arguments (integer with the correspond char **), then you have several options, here a short list of the most convenient:
* __Args::argv()__: Get you the raw arguments a const reference vector of string_view.
* __Args::operator[std::size_t n]__: Same result as Args::argv()[n].
* __Args::valueExist(const std::string&)__: return true if the value exists otherwise return false.
* ___Args::flagExist(char c)__: return true if the flag exists otherwise return false. You just need to put the letter of the flag (example args.flagExist('a')).
* ___Args::flagOption(const std::string&)__: return true if the option exists otherwise return false. You just need to put the name of the option and not the -- (example "verbose" and not "--verbose").
* ___Args::getOptionValue(const std::string&)__: return an optional string_view with the first option's value if the value exists otherwise empty optional. You just need to put the name of the option and not the -- (example "verbose" and not "--verbose")
* ___Args::operator[const std::string&]__: same as getOptionValue.
* ___Args::getOptionValues(const std::string&)__: return a vector of string_view containing all the option's values. You just need to put the name of the option and not the -- (example "verbose" and not "--verbose")
* __Args::getFlags()__: return a vector of char with all the flags.
*__Args::getOptions()__: return a map with string_view representing the option name as a key and a vector of string_view as values.



## How do I use this lib in my projet?
Simply add the file __src/Isaarg.hpp__ to your include path and inclue the file file in you project, this is a header-only library this is all it needs to work.

## Example
There are several examples of how to use the library in the file __src/main.cpp__.
