#pragma once

#include <stdlib.h>

namespace custom_ds
{
    // Definition for singly-linked list node.
    template <typename T>
    struct s_list_node
    {
        T val;
        s_list_node *next;

        s_list_node(T x) : val(x), next(nullptr) {}
        s_list_node(T x, s_list_node *next) : val(x), next(next) {}
    };

    // Definition for singly-linked list node.
    template <typename T>
    class Slist
    {
    public:
        Slist() {}
        Slist(s_list_node<T> *root)
        {
            root_ = root;

            // Update size_ and last_elem_ pointer
            last_elem_ = root;
            size_ = 1;
            while (last_elem_->next != nullptr)
            {
                size_++;
                last_elem_ = last_elem_->next;
            }
        }

        int Size() const
        {
            return size_;
        }

        void Add(T elem)
        {
            size_++;
            if (size_ == 1)
            {
                last_elem_ = new s_list_node<T>(elem);
                root_ = last_elem_;
                return;
            }
            last_elem_->next = new s_list_node<T>(elem);
            last_elem_ = last_elem_->next;
        }

        bool Contains(T elem) const
        {
            if (size_ == 0)
                return false;

            s_list_node<T> *node = root_;
            while (node != nullptr)
            {
                if (node->val == elem)
                    return true;
                node = node->next;
            }

            return false;
        }

        s_list_node<T> *GetHead() const
        {
            return root_;
        }

        void Print() const
        {
            s_list_node<T> *node = root_;
            while (node != nullptr)
            {
                std::cout << node->val << " ";
                node = node->next;
            }
            std::cout << std::endl;
        }

    private:
        s_list_node<T> *root_;
        s_list_node<T> *last_elem_; // Remembering last elem helps add stuff in cte time
        size_t size_ = 0;
    };

    Slist<int> getList()
    {
        Slist<int> list;
        for (int i = 0; i < 10; i++)
            list.Add(i);
        return list;
    }
} // namespace custom_ds