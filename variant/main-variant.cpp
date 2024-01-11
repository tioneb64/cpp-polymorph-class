#include "class-multi-array-variant.hpp"

int main() {

    //=========================================================
    // input

	//Create an instance of the MultiArrayVariant class
	MyMultiTest::MultiArrayVariant multiArray(5, 4); // par exemple, un tableau 3x4

    // Initialize array with values

	// std::string, float, bool
    multiArray.setElement<std::string>(0,0, "Test Multi Array Class,");
    multiArray.setElement<std::string>(0,1, "Program Created by Benoit Thibaudeau. Version");
    multiArray.setElement(0,2, 1.01f);
    multiArray.setElement(0,3, true);

    // array
    const int size = 5;
    std::vector<int> myVector(size);

    // Initialize the array with values 0, 2, 4, 6, 8
    for (int i = 0; i < size; ++i) {
        myVector[i] = i * 2;
    }

    // Add the Array in thee content
    multiArray.setElement(1,0, myVector);
    multiArray.setElement(1,1, myVector);
    multiArray.setElement(1,2, myVector);
    multiArray.setElement(1,3, myVector);

    // Complete the array with some int value
    for (int i = 2; i < multiArray.GetRowNum(); ++i)
    {
        for (int j = 0; j < multiArray.GetColNum(); ++j)
        {
        	multiArray.setElement(i, j, i * multiArray.GetColNum() + j);
        }
    }

    //=========================================================
    // Output

    // Call some functions of the class to display the data information contained in the "Array"
    std::cout << std::endl;
    std::cout << "The Array have " << multiArray.GetRowNum() << " rows and " << multiArray.GetColNum() << " columns, " << multiArray.GetSize() << " elements." << std::endl;
    std::cout << std::endl;

    // Print the string, float and bool values
    std::cout << multiArray.getElement<std::string>(0, 0) << " ";
    std::cout << multiArray.getElement<std::string>(0, 1) << " ";
    std::cout << multiArray.getElement<float>(0, 2) << " ";
    std::cout << (multiArray.getElement<bool>(0, 3) ? "true" : "false") << std::endl;
    std::cout << std::endl;

    std::cout << "The array values : ";

    // unlike the polymorphic version, the function using "variant" correctly displays
    // the contents of the class, when the data is arrays
    const auto& vectorElement = multiArray.getElement<std::vector<int>>(1, 0);
    for (const auto& element : vectorElement) {
        std::cout << element << " ";
    }
    std::cout << std::endl << std::endl;

    // Show Array contents
    for (int i = 2; i < multiArray.GetRowNum(); ++i) {
        for (int j = 0; j < multiArray.GetColNum(); ++j) {
            std::cout << multiArray.getElement<int>(i, j) << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
