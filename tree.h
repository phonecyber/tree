using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node {
public:
	Node() { left = right = NULL; }
	Node(const T& el, Node *l = 0, Node *r = 0) {
		key = el; left = l; right = r;
	}
	T key;
	Node *left, *right;
};

template<class T>
class Tree {
public:
	Tree() { root = 0; }
	~Tree() { clear(); }
	void clear() {
		clear(root); root = 0;
		//data = NULL;
		height = 0;
		//delete tmpValue;
		count = 0;
	}
	bool isEmpty() { return root == 0; }
	void inorder() { inorder(root); }
	void insert(const T& el);
	void deleteNode(Node<T> *& node);
	void balance(T data[], int first, int last);
	Node<T>* search(const T &el);
	void print() { print(root); };

	T* data = NULL;
	int height = 0;

protected:
	Node<T> *root, *tmpValue, *prevDelNode;
	int count = 0;

	void clear(Node<T> *p);
	void inorder(Node<T> *p);
	void print(Node<T> *p);

};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0) {
		clear(p->left);
		clear(p->right);
		delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p) {
	//TO DO! This is for an inorder tree traversal!
	if (p != NULL)
	{
		inorder(p->left);
		//cout << p->key << " ";
		data[count++] = p->key;
		inorder(p->right);
	}
}

template<class T>
void Tree<T>::print(Node<T> *p) {
	if (p != NULL)
	{
		print(p->left);
		cout << p->key << " ";
		print(p->right);
	}
}

template<class T>
void Tree<T>::insert(const T &el) {
	Node<T> *p = root, *prev = 0;
	int i = 0;
	while (p != 0) {
		prev = p;
		if (p->key < el)
			p = p->right;
		else
			p = p->left;
		i++;
	}

	if (i > height)
		height = i;

	if (root == 0)
		root = new Node<T>(el);
	else if (prev->key < el)
		prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);

	//cout << el << " ";
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node) {
	Node<T> *prev, *tmp = node;
	if (node != NULL)
	{
		if (prevDelNode->left == tmp)
		{
			if (node->right == 0)
			{
				prevDelNode->left = tmp->left;
				//node = node->left;
			}
			else if (node->left == 0)
			{
				prevDelNode->left = tmp->right;
				//node = node->right;
			}
		}
		else if (prevDelNode->right == tmp)
		{
			if (node->right == 0)
			{
				prevDelNode->right = tmp->left;
				//node = node->left;
			}
			else if (node->left == 0)
			{
				prevDelNode->right = tmp->right;
				//node = node->right;
			}
		}


		if (node->left != NULL && node->right != NULL)
		{
			tmp = node->left;
			prev = node; 
			while (tmp->right != 0) {
				prev = tmp;
				tmp = tmp->right;
			}
			node->key = tmp->key;
			if (prev == node)
				prev->left = tmp->left;
			else prev->right = tmp->left;
		}

		delete tmp;
	}
}

template<class T>
void Tree<T>::balance(T data[], int first, int last) {
	if (first <= last) {
		int middle = (first + last) / 2;
		insert(data[middle]);
		balance(data, first, middle - 1);
		balance(data, middle + 1, last);
	}
}

template<class T>
Node<T>* Tree<T>::search(const T &el) {
	Node<T> *p = root;
	prevDelNode = root;
	//static Node<T> tmp = &p;
	while (p != NULL) {
		if (p->key == el)
		{
			tmpValue = p;
			return tmpValue;
			break;
		}
		else if (p->key < el)
		{
			prevDelNode = p;
			p = p->right;
		}
		else if (p->key > el)
		{
			prevDelNode = p;
			p = p->left;
		}
	}

	if (p == NULL)
	{
		return NULL;
	}
}

#endif // Binary_Search_Tree