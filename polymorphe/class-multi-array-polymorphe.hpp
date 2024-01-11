#ifndef __MULTI_ARRAY_POLYMORPHE_HPP

	#define __MULTI_ARRAY_POLYMORPHE_HPP

	#include <iostream>
	#include <vector>
	#include <memory>
	#include <variant>
	#include <string>

	namespace MyMultiTest{

		class MultiArrayPolymorphe {

			public:

				MultiArrayPolymorphe(int rowsIn, int colsIn) : rows(rowsIn), cols(colsIn), data(rows * cols) {}

				template <typename T>
				void setElement(int row, int col, T value) {
					data[row * cols + col] = Any(value);
				}

				template <typename T>
				T getElement(int row, int col) const
				{
				    try {
				        if (row < 0 || row >= rows || col < 0 || col >= cols) {
				            throw std::out_of_range("Index out of bounds");
				        }

				        return data[row * cols + col].get<T>();
				    } catch (const std::exception& e) {
				        std::cerr << "Error getting element: " << e.what() << std::endl;
				        throw;
				    }
				}

		        int GetRowNum() const {
		            return rows;
		        }

		        int GetColNum() const{
		        	return cols;
		        }

		        int GetSize() const {
		            return rows * cols;
		        }

			private:
				struct Any {
					Any() {}

// compatibility with versions < C++14
//					template <typename T>
//					Any(const T& value) : storage(new Holder<T>(value)) {}

					template <typename T>
					Any(const T& value) : storage(std::make_unique<Holder<T>>(value)) {}


					template <typename T>
					T get() const {
						return static_cast<Holder<T>*>(storage.get())->value;
					}

					struct BaseHolder {
						virtual ~BaseHolder() {}
					};

					template <typename T>
					struct Holder : public BaseHolder {
						Holder(const T& valueIn) : value(valueIn) {}
						T value;
					};

					std::unique_ptr<BaseHolder> storage;
				};

				int rows;
				int cols;
				std::vector<Any> data;
		};

	}
#endif
