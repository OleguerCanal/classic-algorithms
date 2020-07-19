#pragma once
#include <stdlib.h> // For size_t type

namespace custom_ds
{
    /*
OBS: When compiling, this class will be copied to the source file
substituting the template arguments for the ones specified in the code.
*/
    template <typename T, size_t size>
    class Array
    {
    public:
        // constexpr since it can be evaluated at compile time (size is substituted by number then)
        // const since does not affect the class internally
        constexpr size_t Size() const { return size; }

        // Return by reference because we might want to write a value also
        // Not constexpr because it cannot be evaluated at compile time
        // Not const because we might change internal class memory
        T &operator[](size_t index) { return data_[index]; }

        // FUNCTION OVERLOADING: In case the Array is constant (or passed as constant reference),
        // we would not be able to access the previous operator since it is not marked as const,
        // to solve this we can add a const version of the method
        const T &operator[](size_t index) const { return data_[index]; }

        // We might want to return a pointer to the whole data
        T *Data() { return data_; }

        // Same as before, the class might be marked as const
        const T *Data() const { return data_; }

    private:
        T data_[size]; // Array data gets stored in Stack memory
    };
} // namespace custom_ds