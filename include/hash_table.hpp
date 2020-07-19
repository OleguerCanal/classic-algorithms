#pragma once

#include "array.hpp"
#include "utils.hpp" // For printing
#include "single_link_list.hpp"

namespace custom_ds
{
    template <typename T, int bins, typename hash>
    class HashTable
    {
    public:
        HashTable()
        {
            // Initialize sLists
            for (int i = 0; i < bins; i++)
                data_[i] = new Slist<T>();
        }

        void Insert(T elem)
        {
            Slist<T> *list = GetBinList(elem);
            list->Add(elem);
        }

        bool Contains(T elem) const
        {
            Slist<T> *list = GetBinList(elem);
            return list->Contains(elem);
        }

        void Print() const
        {
            for (int i = 0; i < bins; i++)
            {
                std::cout << "Bin " << i << " contains: ";
                data_[i]->Print();
            }
        }

    private:
        Slist<T> *GetBinList(T elem) const
        {
            int bin = GetBin(elem);
            Slist<T> *list = data_[bin];
            return list;
        }

        size_t GetBin(T elem) const
        {
            hash h;
            h(elem);
            return elem % bins;
        }

        Array<Slist<T> *, bins> data_;
    };

} // namespace custom_ds