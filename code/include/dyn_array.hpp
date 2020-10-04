#pragma once
#include <stdlib.h> // For size_t type

namespace custom_ds
{
    template <typename T>
    class DynArray
    {
    public:
        
        DynArray(size_t size = 0) {
            size_ = size;
            capacity_ = size;
            data_ = new T[size];
        }

        void push_back(const T& elem) {
            size_++;
            if (size_ > capacity_) ReAlloc(2*capacity_);  // Reallocation needed
            std::cout << "size: " << size_ << ", mem: " << capacity_ << std::endl;
            data_[size_-1] = elem;
        }

        size_t Size() const { return size_; }

        size_t Capacity() const { return capacity_; }

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

        void Print() {
            for (size_t i = 0; i < size_; i++)
                std::cout << data_[i] << " ";
            std::cout << std::endl;
        }

    private:
        size_t size_, capacity_; // Initialized memory and reserved memory size
        T* data_; // Array data gets stored in Stack memory

        void ReAlloc(size_t new_capacity) {
            std::cout << "relocating" << std::endl;
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < size_-1; i++)  // Copy values
                new_data[i] = data_[i];
            delete[] data_;

            capacity_ = new_capacity;
            data_ = new_data;
        }
    };
} // namespace custom_ds