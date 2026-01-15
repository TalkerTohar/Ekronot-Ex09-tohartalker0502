#include "BSNode.h"
#include <string>
#include <iostream>


BSNode::BSNode(std::string data) : _data(data), _left(nullptr), _right(nullptr), _count(1)
{
}

BSNode::BSNode(const BSNode& other) : _data(other._data), _left(nullptr), _right(nullptr), _count(other._count)
{
	if (other._left)
	{
		_left = new BSNode(*other._left);
	}
	if (other._right)
	{
		_right = new BSNode(*other._right);
	}
}

BSNode::~BSNode()
{
	delete _left;
	delete _right;
}

void BSNode::insert(std::string value)
{
	if (value == _data)
	{
		_count++;
	}
	else if (value < _data)
	{
		if (_left)
		{
			_left->insert(value);
		}
		else
		{
			_left = new BSNode(value);
		}
	}
	else
	{
		if (_right)
		{
			_right->insert(value);
		}
		else
		{
			_right = new BSNode(value);
		}
	}
}

BSNode& BSNode::operator=(const BSNode& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete _left;
	delete _right;
	_data = other._data;
	_count = other._count;
	_left = other._left ? new BSNode(*other._left) : nullptr;  
	_right = other._right ? new BSNode(*other._right) : nullptr;
	return *this;
}


bool BSNode::isLeaf() const
{
	return (_left == nullptr && _right == nullptr);
}

std::string BSNode::getData() const
{
	return this->_data;
}

BSNode* BSNode::getLeft() const
{
	return this->_left;
}

BSNode* BSNode::getRight() const
{
	return this->_right;
}

int BSNode::getCount() const
{
	return this->_count;
}

bool BSNode::search(std::string val) const
{
	if (val == _data)
	{
		return true;
	}
	else if (val < _data)
	{
		if (_left)
		{
			return _left->search(val);
		}
	}
	else
	{
		if (_right)
		{
			return _right->search(val);
		}
	}
	return false;
}

int BSNode::getHeight() const
{
	int leftHeight = 0;
	int rightHeight = 0;
	if (!_left && !_right)
	{
		return 0;
	}
	if (_left)
	{
		leftHeight = _left->getHeight();
	}
	if (_right)
	{
		rightHeight = _right->getHeight();
	}
	if (leftHeight > rightHeight)
	{
		return leftHeight + 1;
	}
	else
	{
		return rightHeight + 1;
	}
}

int BSNode::getDepth(const BSNode& root) const
{
	if (&root == this)
	{
		return 0;
	}
	if (this->_data < root._data && root._left)
	{
		int depth = getDepth(*root._left);
		if (depth != -1)
		{
			return depth + 1;
		}
	}

	if (this->_data > root._data && root._right)
	{
		int depth = getDepth(*root._right);
		if (depth != -1)
		{
			return depth + 1;
		}
	}
	return -1;
}

void BSNode::printNodes() const
{
	if (_left != nullptr)
	{
		_left->printNodes();
	}
	std::cout << _data << " " << _count << std::endl;
	if (_right != nullptr)
	{
		_right->printNodes();
	}
}