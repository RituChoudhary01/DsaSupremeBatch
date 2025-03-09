// Debug-Exerices question.
/*
Q1.Debug the code.

void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = root;
    Node* temp = root;
    while (temp) {
				prev = temp;
        if (temp->val > key) {
            temp = temp->left;
        }
        else if (temp->val < key) {
            temp = temp->right;
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}
Ans:-
void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = NULL;
    Node* temp = root;
    while (temp) {
        if (temp->val > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp->val < key) {
            prev = temp;
            temp = temp->right;
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}
Q2.Debug the code. Check if an array represents Inorder of Binary Search tree or not.
bool isArrayInorder(int arr[], int n) {
    if (n == 0)
        return true;
    for (int i = 1; i < n; i++)
        if (arr[i] > arr[i+1])
            return false;
    return true;
}
Ans:-
bool isArrayInorder(int arr[], int n) {
    if (n == 0 || n == 1)
        return true;
    for (int i = 1; i < n; i++)
        if (arr[i-1] > arr[i])
            return false;
    return true;
}
Q3.Debug the code. Second largest element.
void secondLargestUtil(Node *root, int &c) {
    if (root == NULL)
        return;
    secondLargestUtil(root->right, c);
    if (c <= 2) {
        cout << root->key << endl; // Print 2nd Largest Element
        return;
    }
    c++;
    secondLargestUtil(root->left, c);
}

void secondLargest(Node *root) {
    int c = 0;
    secondLargestUtil(root, c);
}
Ans:-
void secondLargestUtil(Node *root, int &c) {
    if (root == NULL || c >= 2)
        return;
    secondLargestUtil(root->right, c);
    c++;
    if (c == 2) {
        cout << root->key << endl; // Print 2nd Largest Element
        return;
    }
    secondLargestUtil(root->left, c);
}

void secondLargest(Node *root) {
    int c = 0;
    secondLargestUtil(root, c);
}
Q4.Debug the code. Two BSTs contain same elements.
void inorder(Node* root, vector<int> &v) {
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool checkBSTs(Node* root1, Node* root2) {
    if (!root1 && !root2)
        return true;
    if (!(root1 && !root2) || (!root1 && root2))
        return false;
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2); 
    return (v1 == v2);
}

Ans:-
void inorder(Node* root, vector<int> &v) {
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool checkBSTs(Node* root1, Node* root2) {
    if (!root1 && !root2)
        return true;
    if ((root1 && !root2) || (!root1 && root2))
        return false;
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2); 
    return (v1 == v2);
}

Q5.Debug the code. Sorted Linked List to Balanced BST.
void transformTreeHelper(Node *root, int sum) {
   if (root == NULL)  return;
   transformTreeHelper(root->right, sum);
   sum = sum + root->data;
   root->data = *sum - root->data;
   transformTreeHelper(root->left, sum);
}
 
void transformTree(struct Node *root) {
    transformTreeHelper(root, 0);
}
Ans:-
void transformTreeHelper(Node *root, int *sum) {
   if (root == NULL)  return;

   transformTreeHelper(root->right, sum);
   *sum = *sum + root->data;
   root->data = *sum - root->data;
   transformTreeHelper(root->left, sum);
}
 
void transformTree(struct Node *root) {
    int sum = 0;
    transformTreeHelper(root, &sum);
}
*/ 