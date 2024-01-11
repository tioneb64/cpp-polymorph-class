# cpp-polymorph-class
Two classes to create a polymorphic table in C++ accepting all types of data
I created the small MultiArray project for educational purposes.

It offers two versions of the same MultiArray class.

The polymorphic version is flexible but limited. The variant version is limited but flexible.

##Project Explanation:

The starting premise is that in C++, a multidimensional array is generally a homogeneous structure, meaning that all elements of the array must be of the same data type (int, float, char, std::string, std::vector, ...). However, for a project, I needed to store a certain amount of data with multiple types in an array to work on it easily.

The MultiArray class is designed to address this issue. It simulates the behavior of an array. A multidimensional array with different data types can be simulated using structures or classes.

##Polymorphic Version:

In this version, the MultiArrayPolymorphic class uses an internal "Any" class that can store any data type using polymorphic pointers. This class is compatible with C++14 to C++17. It is not compatible with C++11 because I use "std::unique_ptr," which did not exist and only appeared in C++14.

Thanks to the "struct Any" in the class, it can store any data type. The advantage, unlike the "variant" version, is that I can add all data types, or almost all. Almost, because unfortunately, I cannot store <vector> in it.

However, it has a major advantage over the "variant" version; I can add data types without modifying the source. I can compile it into a library without having to recompile it every time I add a new data type.

##Variant Version:

Similar to the previous version, the MultiArrayVariant class can handle almost all data types. To do this, you just need to add the types that the class container should process in the line:

using ValueVariant = std::variant<int, float, bool, std::string, std::vector<int>>;
std::vector<ValueVariant> data;

However, if you want to add or remove a type that can be processed by the MultiArrayVariant class, you need to modify this line and then recompile your source.



Both classes have advantages and disadvantages. Each person will make their choice based on their needs.



## Execute unit tests

To compile and run the tests, you need to execute

```sh
$ mkdir build
$ cd build
$ cmake ..
$ make
$ ./MultiArrayVariant
$ ./MultiArrayPoly
