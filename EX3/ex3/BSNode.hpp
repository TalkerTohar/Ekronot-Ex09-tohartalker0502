#pragma once
#include <iostream>

template <class T>
class BSNode
{
private:
    T _data;
    BSNode<T>* _left;
    BSNode<T>* _right;
    int count;

public:
    // constructor
    BSNode(const T& data) : _data(data), _left(nullptr), _right(nullptr), _count(1)
    {
    }

    // copy constructor
    BSNode(const BSNode<T>& other) : _data(other._data), _left(nullptr), _right(nullptr), _count(other._count)
    {
        if (other._left)
            _left = new BSNode<T>(*other._left);
        if (other._right)
            _right = new BSNode<T>(*other._right);
    }

    // destructor
    ~BSNode()
    {
        delete _left;
        delete _right;
    }

    // insert
    void insert(const T& value)
    {
        if (value == _data)
        {
            _count++;
        }
        else if (value < _data)
        {
            if (_left)
                _left->insert(value);
            else
                _left = new BSNode<T>(value);
        }
        else
        {
            if (_right)
                _right->insert(value);
            else
                _right = new BSNode<T>(value);
        }
    }

    // assignment operator
    BSNode<T>& operator=(const BSNode<T>& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete _left;
        delete _right;
        _data = other._data;
        _count = other._count;
        _left = other._left ? new BSNode<T>(*other._left) : nullptr;
        _right = other._right ? new BSNode<T>(*other._right) : nullptr;

        return *this;
    }

    bool isLeaf() const
    {
        return (_left == nullptr && _right == nullptr);
    }

    T getData() const
    {
        return _data;
    }

    BSNode<T>* getLeft() const
    {
        return _left;
    }

    BSNode<T>* getRight() const
    {
        return _right;
    }

    int getCount() const
    {
        return _count;
    }

    bool search(const T& val) const
    {
        if (val == _data)
            return true;

        if (val < _data && _left)
            return _left->search(val);

        if (val > _data && _right)
            return _right->search(val);

        return false;
    }

    int getHeight() const
    {
        int leftHeight = 0;
        int rightHeight = 0;

        if (!_left && !_right)
            return 0;

        if (_left)
            leftHeight = _left->getHeight();

        if (_right)
            rightHeight = _right->getHeight();

        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }

    int getDepth(const BSNode<T>& root) const
    {
        if (&root == this)
            return 0;

        if (_data < root._data && root._left)
        {
            int depth = getDepth(*root._left);
            if (depth != -1)
                return depth + 1;
        }

        if (_data > root._data && root._right)
        {
            int depth = getDepth(*root._right);
            if (depth != -1)
                return depth + 1;
        }

        return -1;
    }

    void printNodes() const
    {
        if (_left)
            _left->printNodes();

        std::cout << _data << " " << _count << std::endl;

        if (_right)
            _right->printNodes();
    }

};