#include <iostream>
using namespace std;

//tạo kiểu dữ liệu node
struct node
{
	int data;// data
	node* pLeft;// node trái
	node* pRight;//node phải
};

//tạo 1 node mới
node* makeNode(int x) {
	node* newNode = new node();//tạo 1 node rỗng
	newNode->data = x;//cho data bằng x
	newNode->pLeft = NULL;//node trái bằng NULL
	newNode->pRight = NULL;//node phải bằng NULL
	return newNode;//trả về node mới
}

// tạo 1 class tree
class tree {
public:
	node* root = NULL; //tạo 1 node root = NULl

	// hàm tìm kiếm node có giá trị x
	node* find(node* root, int x)
	{
		if (root == NULL) return root; // nếu cây rỗng thì return NULL
		if (root->data == x) return root; // nếu tìm được thì return địa chỉ node

		node* findInLeft = find(root->pLeft, x);// tạo 1 node findinleft để tìm xuống các nhánh con trái
		if (findInLeft != NULL) return findInLeft; // trả về nếu tìm được

		return find(root->pRight, x); // nếu không tìm ở node phải
		// nếu vẫn không tìm được thì return NULL
	}

	// hàm thêm node vào cây
	void addChild(int parent, int chill)
	{
		node* parentNode = find(root, parent);// tạo 1 node lưu địa chỉ của nod có giá trị parent
		if (parentNode == NULL)// nếu cây rỗng thì cho parent = root
		{
			root = makeNode(parent);
			parentNode = root;
		}

		if (parentNode->pLeft == NULL)// nếu node trái của parent rỗng
		{
			parentNode->pLeft = makeNode(chill);//tạo node trái bằng node có giá trị child
		}
		else if (parentNode->pRight == NULL) // tương tự node trái
		{
			parentNode->pRight = makeNode(chill);
		}
		else {
			cout << "Khong tim thay node cha" << endl;// nếu cả 2 đã đầy
		}
	}

	// hàm trả về chiều cao của cây
	int height(node* root)
	{
		if (root == NULL) return -1;// nếu cây rỗng thì có chiều cao là -1

		int leftHeight = height(root->pLeft); // chiều cao cây con trái
		int rightHeight = height(root->pRight);// chiều cao cây con phải

		return max(leftHeight, rightHeight) + 1; // chiều cao node cha là chiều cao lớn nhất của nod con +1
	}

	void printPreOrder(node* root)
	{
		if (root == nullptr) return;// nếu cây rỗng return
		cout << root->data << " "; // in data node
		printPreOrder(root->pLeft); // đệ quy duyệt trái
		printPreOrder(root->pRight); // đệ quy duyệt phải
	}


	void printPostOrder(node* root)
	{
		if (root == nullptr) return;// nếu cây rỗng return
		printPostOrder(root->pLeft); // đệ quy trái
		printPostOrder(root->pRight); // đệ quy phải
		cout << root->data << " "; // in data khi duyệt hết
	}

	// hàm kiểm tra cây nhị phân
	bool isBinaryTree(node* root)
	{
		if (root == nullptr) return true; // nếu cây rỗng return true

		int childCount = 0; // số con của 1 node
		if (root->pLeft) childCount++; // nếu node trái không rỗng ++
		if (root->pRight) childCount++; // nếu node phải không rỗng ++

		if (childCount > 2) return false; // nếu có hơn 2 node con thì return false

		return isBinaryTree(root->pLeft) && isBinaryTree(root->pRight); // đễ quy kiểm tra tiếp node trái phải
	}

	void printInOder(node* root)
	{
		if (root == nullptr) return;

		if (!isBinaryTree(root)) // nếu cây không phải cây nhị phân
		{
			cout << "NOT BINARY TREE";
		}
		else {
			printInOder(root->pLeft); // duyệt hết node trái
			cout << root->data << " "; // in data khi duyệt hết
			printInOder(root->pRight); // duyệt hết phải
		}
	}
};


int main()
{
	tree tree; // tạo cây
	node* root;
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		tree.addChild(a, b);
	}
	cout << tree.height(tree.root) << endl;
	tree.printPreOrder(tree.root);
	cout << endl;
	tree.printPostOrder(tree.root);
	cout << endl;
	tree.printInOder(tree.root);
	return 0;
}