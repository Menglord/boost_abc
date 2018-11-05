#include <iostream>
#include <boost/program_options.hpp>
#include <vector>
#include <string>
#include <iterator>

namespace po = boost::program_options;

// A helper function to simplify the main part.
template<class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, " "));
    return os;
}

void SimpleTwoOptions(int argc, char** argv);
void OptionProperties(int argc, char** argv);

int main(int argc, char** argv){
//	SimpleTwoOptions(argc, argv);
	OptionProperties(argc, argv);
}

void SimpleTwoOptions(int argc, char** argv){
	po::options_description desc("Allowed options");
		desc.add_options()
			("help", "produce help message")
			("compression", po::value<int>(), "set compression level")
		;
		po::variables_map vm;
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::notify(vm);
		if (vm.count("help")){
			std::cout << desc << std::endl;
			return;
		}
		if (vm.count("compression")){
			std::cout << "Compression level was set to "
					<< vm["compression"].as<int>() << std::endl;
		} else {
			std::cout << "Compression level was not set" << std::endl;
		}
}

void OptionProperties(int argc, char** argv){
	int opt;
	po::options_description desc("Allowed options");
	desc.add_options()
			("help", "produce help message")
			("optimization", po::value<int>(&opt)->default_value(10), "optimization level")
			("include-path,I", po::value<std::vector<std::string>>(), "include path")
			("input-file", po::value<std::vector<std::string>>(), "input file")
	;
	po::positional_options_description p;
	p.add("input-file", -1);

	po::variables_map vm;
	po::store(po::command_line_parser(argc, argv).
	          options(desc).positional(p).run(), vm);
	po::notify(vm);

	if (vm.count("include-path"))
	{
		std::cout << "Include paths are: " << vm["include-path"].as<std::vector<std::string>>() << std::endl;
	}

	if (vm.count("input-file"))
	{
		std::cout << "Input files are: " << vm["input-file"].as<std::vector<std::string>>() << std::endl;
	}

	std::cout << "Optimization level is " << opt << std::endl;
}

