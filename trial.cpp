#include <utility>
#include <string>
#include <iostream>


template<class... T>
auto pack(T... t)
{ 
	return [...t=std::move(t)](auto&& f){f(t...);};
};


void f( int age, const std::string& name)
{
	std::cout<< "I am " << name << " and am "<< age<< " years old \n";
}

int main(int arg, char** argv)
{
	if(arg !=3)
	{
		std::cerr << "  Provide  age  name \n";
		return -1;
	}

	int age = std::stoi(argv[1]);
	std::string name= argv[2];
	auto func = pack(age, name);
	func(f);
	return 0;
}
