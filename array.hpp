// CustomArray.hpp

#ifndef CUSTOM_ARRAY_HPP
#define CUSTOM_ARRAY_HPP

#include <cstddef>   // For size_t
#include <stdexcept> // For std::out_of_range
#include <utility>   // For std::move

namespace MyDS
{

    //=========================================================
    //            Custom Array Declaration
    //=========================================================
    template <typename T>
    class CustomArray
    {
    public:
        CustomArray();
        ~CustomArray();

        void push_back(const T &value);
        void pop_back();
        T &at(size_t index);
        const T &at(size_t index) const;
        T &operator[](size_t index);
        const T &operator[](size_t index) const;
        size_t size() const noexcept;
        size_t capacity() const noexcept;
        bool empty() const noexcept;

    private:
        void reallocate(size_t new_capacity);

        T *m_data;
        size_t m_size;
        size_t m_capacity;
    };

    //=========================================================
    //            Custom Array Implementation
    //=========================================================

    // --- Constructor & Destructor ---
    template <typename T>
    CustomArray<T>::CustomArray()
        : m_data(nullptr), m_size(0), m_capacity(0) {}

    template <typename T>
    CustomArray<T>::~CustomArray()
    {
        delete[] m_data;
    }

    // --- Public Methods ---
    template <typename T>
    void CustomArray<T>::push_back(const T &value)
    {
        if (m_size >= m_capacity)
        {
            reallocate(m_capacity == 0 ? 8 : m_capacity * 2);
        }
        m_data[m_size] = value;
        m_size++;
    }

    template <typename T>
    void CustomArray<T>::pop_back()
    {
        if (!empty())
        {
            m_size--;
        }
        // For simplicity, we don't shrink the capacity here.
        // A more advanced implementation might.
    }

    template <typename T>
    T &CustomArray<T>::at(size_t index)
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    template <typename T>
    const T &CustomArray<T>::at(size_t index) const
    {
        if (index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[index];
    }

    template <typename T>
    T &CustomArray<T>::operator[](size_t index)
    {
        return m_data[index];
    }

    template <typename T>
    const T &CustomArray<T>::operator[](size_t index) const
    {
        return m_data[index];
    }

    template <typename T>
    size_t CustomArray<T>::size() const noexcept
    {
        return m_size;
    }

    template <typename T>
    size_t CustomArray<T>::capacity() const noexcept
    {
        return m_capacity;
    }

    template <typename T>
    bool CustomArray<T>::empty() const noexcept
    {
        return m_size == 0;
    }

    // --- Private Helper Methods ---
    template <typename T>
    void CustomArray<T>::reallocate(size_t new_capacity)
    {
        T *new_block = new T[new_capacity];

        // Use std::move for efficiency with complex types
        if (m_data)
        {
            for (size_t i = 0; i < m_size; ++i)
            {
                new_block[i] = std::move(m_data[i]);
            }
            delete[] m_data;
        }

        m_data = new_block;
        m_capacity = new_capacity;
    }

} // namespace MyDS

#endif