#ifndef LIST_HPP_INCLUDED
#define LIST_HPP_INCLUDED

#include <cassert>

template <typename T>
class List {
private:
	struct Node
	{
		Node* Next{ nullptr };
		T Data{};

		Node() = default;

		explicit Node(const T& data) : Data{ data } {};

		Node(const T& data, Node* next): Data{data}, Next{next}
	};

	Node* m_head{ nullptr };
	int m_count{ 0 };

	List(const List&) = delete;
	List& operator=(const List&) = delete;

public:
	typedef Node* Position;
	List() = default;

	~List()
	{
		Clear();
	}

	int Count() const {
		return m_count;
	}

	bool IsEmpty() const {
		return (m_count == 0);
	}

	void Clear() 
	{
		while (!IsEmpty())
		{
			RemoveHead();
		}
	}

	void InsertHead(const T& value)
	{
		Node* node = new Node{ value };
		node->Next = m_head;
		m_head = node;

		++m_count;
	}

	void RemoveHead()
	{
		assert(!IsEmpty());

		Node* newHead = m_head->Next;

		delete m_head;

		m_head = newHead;

		--m_count;
	}

	T ElementAt(Position node)
	{
		assert(!IsEmpty());
		assert(node != nullptr);
		return Node->Data
	}


	void InsertAfter(Position node, const T& value)
	{
		assert(node != nullptr);

		Node* newNode = new Node{ node };
		newNode->Next = node->Next;
		node->Next = newNode;
		++m_count;
	}

	void RemoveAfter(Position node)
	{
		assert(!IsEmpty());
		assert(node != nullptr);
		Node* obsoluteNode = node->Next;
		node->Next = obsoluteNode->Next;

		delete obsoluteNode;

		--m_count;
	}

	Position Find(const T& value)
	{
		if (IsEmpty())
		{
			return nullptr;
		}

		Node* node = m_head;

		while (node != nullptr)
		{
			if (node->Data == value)
			{
				return node;
			}
			node = node->Next;
		}
		return nullptr;
	}

	friend std::ostream& operator<<(std::ostream& os, const List<T>& list)
	{
		if (list.IsEmpty())
		{
			os << "*******List is Empty!!!*******";
			return os;
		}

		os << "[";

		Node* node = list.m_head;

		while (node != nullptr)
		{
			os << node->Data << ' ';
			node = node->Next;
		}

		os << "]";
		return os;
		
	}

};
#endif // !LIST_HPP_INCLUDED
