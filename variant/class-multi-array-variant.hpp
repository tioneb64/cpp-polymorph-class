#ifndef __MULTI_ARRAY_VARIANT_HPP
#define __MULTI_ARRAY_VARIANT_HPP

#include <iostream>
#include <vector>
#include <variant>
#include <string>

namespace MyMultiTest {

    class MultiArrayVariant {

    public:
        MultiArrayVariant(int rowsIn, int colsIn) : rows(rowsIn), cols(colsIn), data(rows * cols) {}

        template <typename T>
        void setElement(int row, int col, T value) {
            data[row * cols + col] = value;
        }

        template <typename T>
        T getElement(int row, int col) const {
            return std::get<T>(data[row * cols + col]);
        }

        int GetRowNum() const {
            return rows;
        }

        int GetColNum() const {
            return cols;
        }

        int GetSize() const {
            return rows * cols;
        }

    private:
        using ValueVariant = std::variant<int, float, bool, std::string, std::vector<int>>;
        int rows;
        int cols;
        std::vector<ValueVariant> data;
    };
}
#endif
