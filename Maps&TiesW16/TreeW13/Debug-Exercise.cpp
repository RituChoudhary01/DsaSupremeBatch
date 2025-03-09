/*
//Q1.Debug the code.
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node> children;

    Node(int value) : data(value) {}

    void addChild(Node* child) {
        children.push_back(child);
    }
};

int main() {
    Node root(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);

    root.addChild(child1);
    root.addChild(child2);

    std::cout << "Root Node: " << root.data << std::endl;
    std::cout << "Children: ";
    for (auto child : root.children) {
        std::cout << child->data << " ";
    }
    std::cout << std::endl;

    // Cleanup - deallocate memory
    delete child1;
    delete child2;

    return 0;
}
Ans:-
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int value) : data(value) {}

    void addChild(Node* child) {
        children.push_back(child);
    }
};

int main() {
    Node root(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);

    root.addChild(child1);
    root.addChild(child2);

    std::cout << "Root Node: " << root.data << std::endl;
    std::cout << "Children: ";
    for (auto child : root.children) {
        std::cout << child->data << " ";
    }
    std::cout << std::endl;

    // Cleanup - deallocate memory
    delete child1;
    delete child2;

    return 0;
}

// Q2. Debug the code
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int value) : data(value) {}

    void addChild(Node* child) {
        children.push_back(child);
    }
};

void preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }

    for (int i = 0; i < node->children.size(); i++) {
        std::cout << node->data << " ";
        preorderTraversal(node->children[i]);
    }
}

int main() {
    Node* root = new Node(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Clean up - deallocate memory
    delete root;
    delete child1;
    delete child2;
    delete child3;

    return 0;
}
Ans:-
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int value) : data(value) {}

    void addChild(Node* child) {
        children.push_back(child);
    }
};

void preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    for (int i = 0; i < node->children.size(); i++) {
        preorderTraversal(node->children[i]);
    }
}

int main() {
    Node* root = new Node(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Clean up - deallocate memory
    delete root;
    delete child1;
    delete child2;
    delete child3;

    return 0;
}
// Q3. Debug the code. Mirror the tree.
void mirror(Node* node) {
	if (node == NULL) return;
  mirror(node->left);
  swap(node->left, node->right);
  mirror(node->right);
}
Ans:-
void mirror(Node* node){
	if (node == NULL) return;
        mirror(node->left);
        mirror(node->right);
        swap(node->left, node->right);
}

// Q4.Debug the code. 
void findBottomView(Node* root)
{
		vector<int> ans;
		if(root == NULL){
		  return ans;
    } 
		map<int, int> mp;
		queue<pair<Node*, int>> Q;
		Q.push({root, 0});
		while(!Q.empty()){
			auto it = Q.front();
			Q.pop();
			Node* node = it.first;
			int col = it.second;
			mp[col] = node;
			Q.push({node->left, col-1});
			Q.push({node->right, col+1});
		}
		for(auto x:mp){
			ans.push_back(x.second);
      cout << x.second << " ";
		}
}
Ans:-
template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
    public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
            tail = head;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        if(isEmpty()){
            return 0;
        }
        T data = head->data;
        head = head->next;
        size--;
        return data;
    }
    
    T front()  {
        if(isEmpty()){
            return 0;
        }
        return head->data;
    }
};
// Q5.Debug the code. 
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
 
    while (!q.empty()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left != NULL) {
            root->left->hd = hd - 1;
            q.push(root->right);
        }
        if (root->right != NULL) {
            root->right->hd = hd + 1;
            q.push(root->left);
        }
        root = q.front();
        q.pop();
    }
 
    for (auto [x,y]:m) {
        cout << y << " ";
    }
}
Ans:-
void topview(Node* root)
{
    if (root == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    root->hd = hd;
    q.push(root);
 
    while (!q.empty()) {
        hd = root->hd;
        if (m.count(hd) == 0)
            m[hd] = root->data;
        if (root->left != NULL) {
            root->left->hd = hd - 1;
            q.push(root->left);
        }
        if (root->right != NULL) {
            root->right->hd = hd + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
 
    for (auto [x,y]:m) {
        cout << y << " ";
    }
}
*/ 