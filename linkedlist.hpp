// CustomLinkedList.hpp

#ifndef CUSTOM_LINKED_LIST_HPP
#define CUSTOM_LINKED_LIST_HPP

#include <cstddef>
#include <stdexcept>

namespace MyDS
{

    //=========================================================
    //            Custom Linked List Declaration
    //=========================================================
    template <typename T>
    class CustomLinkedList
    {
    private:
        struct Node
        {
            T data;
            Node *next;
            Node(const T &value) : data(value), next(nullptr) {}
        };

    public:
        CustomLinkedList();
        ~CustomLinkedList();

        // Disabling copy semantics for this example.
        CustomLinkedList(const CustomLinkedList &) = delete;
        CustomLinkedList &operator=(const CustomLinkedList &) = delete;

        void push_front(const T &value);
        void pop_front();
        T &front();
        const T &front() const;
        size_t size() const noexcept;
        bool empty() const noexcept;
        void clear();

    private:
        Node *m_head;
        size_t m_size;
    };

    //=========================================================
    //            Custom Linked List Implementation
    //=========================================================

    template <typename T>
    CustomLinkedList<T>::CustomLinkedList()
        : m_head(nullptr), m_size(0) {}

    template <typename T>
    CustomLinkedList<T>::~CustomLinkedList()
    {
        clear();
    }

    template <typename T>
    void CustomLinkedList<T>::clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    template <typename T>
    void CustomLinkedList<T>::push_front(const T &value)
    {
        Node *new_node = new Node(value);
        new_node->next = m_head;
        m_head = new_node;
        m_size++;
    }

    template <typename T>
    void CustomLinkedList<T>::pop_front()
    {
        if (empty())
        {
            // It's often better to throw than to crash on a null pointer.
            throw std::out_of_range("Cannot pop from an empty list");
        }
        Node *old_head = m_head;
        m_head = m_head->next;
        delete old_head;
        m_size--;
    }

    template <typename T>
    T &CustomLinkedList<T>::front()
    {
        if (empty())
        {
            throw std::out_of_range("Cannot get front of an empty list");
        }
        return m_head->data;
    }

    template <typename T>
    const T &CustomLinkedList<T>::front() const
    {
        if (empty())
        {
            throw std::out_of_range("Cannot get front of an empty list");
        }
        return m_head->data;
    }

    template <typename T>
    bool CustomLinkedList<T>::empty() const noexcept
    {
        return m_head == nullptr; // or m_size == 0
    }

    template <typename T>
    size_t CustomLinkedList<T>::size() const noexcept
    {
        return m_size;
    }

} // namespace MyDS

#endif // CUSTOM_LINKED_LIST_HPP