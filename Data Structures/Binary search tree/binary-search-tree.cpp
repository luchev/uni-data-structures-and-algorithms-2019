#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    
    Node(int value) {
        data = value;
    }

    ~Node() {
        delete left;
        delete right;
    }

    Node(const Node& rhs) {
        data = rhs.data;
        if (rhs.left) {
            left = new Node(*rhs.left);
        }
        if (rhs.right) {
            right = new Node(*rhs.right);
        }
    }

    Node& operator=(const Node& rhs) {
        if (this != &rhs) {
            delete left;
            delete right;

            data = rhs.data;
            if (rhs.left) {
                left = new Node(*rhs.left);
            }
            if (rhs.right) {
                right = new Node(*rhs.right);
            }
        }
        return *this;
    }
};

class BST {
private:
    Node* root = nullptr;

    bool _exists(int value, Node* current) const {
        if (current) {
            if (current->data == value) {
                return true;
            } else if (value > current->data) {
                return _exists(value, current->right);
            } else { // value < data
                return _exists(value, current->left);
            }
        } else {
            return false;
        }
    }

    Node* _insert(int value, Node* current) {
        if (!current) {
            return new Node(value);
        }

        if (value < current->data) {
            current->left = _insert(value, current->left);
        } else if (value > current->data) {
            current->right = _insert(value, current->right);
        }

        return current;
    }

    void _inorder(Node* current) const {
        if (current) {
            _inorder(current->left);
            cout << current->data << " ";
            _inorder(current->right);
        }
    }

    void _preorder(Node* current) const {
        if (current) {
            cout << current->data << " ";
            _preorder(current->left);
            _preorder(current->right);
        }
    }

    void _postorder(Node* current) const {
        if (current) {
            _postorder(current->left);
            _postorder(current->right);
            cout << current->data << " ";
        }
    }

    Node* _remove(int value, Node* current) {
        if (!current) {
            return nullptr;
        }

        if (value < current->data) {
            current->left = _remove(value, current->left);
        } else if (value > current->data) {
            current->right = _remove(value, current->right);
        } else { // value = current->data;
            if (!current->left && !current->right) {
                free(current);
                return nullptr;
            } else if (!current->left) {
                Node* tempRight = current->right;
                free(current);
                return tempRight;
            } else if (!current->right) {
                Node* tempLeft = current->left;
                free(current);
                return tempLeft;
            } else {
                Node* swapWith = current->right;
                while (swapWith->left) {
                    swapWith = swapWith->left;
                }
                
                current->data = swapWith->data;
                current->right = _remove(swapWith->data, current->right);
            }
        }

        return current;
    }

public:
    BST() = default;

    BST(const BST& rhs) {
        root = new Node(*rhs.root);
    }

    BST& operator=(const BST& rhs) {
        if (this != &rhs) {
            delete root;
            root = new Node(*rhs.root);
        }
        return *this;
    }

    ~BST() {
        delete root;
    }

    bool exists(int value) const {
        return _exists(value, root);
    }

    void insert(int value) {
        root = _insert(value, root);
    }

    void remove(int value) {
        root = _remove(value, root);
    }

    void inorder() const {
        _inorder(root);
        cout << "\n";
    }

    void preorder() const {
        _preorder(root);
        cout << "\n";
    }

    void postorder() const {
        _postorder(root);
        cout << "\n";
    }

    void levelorder() const {
        queue<Node*> que;
        que.push(root);

        while(!que.empty()) {
            Node* current = que.front();
            que.pop();
            if (current) {
                cout << current->data << " ";
             
                if (current->left) {
                    que.push(current->left);
                }
                if (current->right) {
                    que.push(current->right);
                }
            }
        }
    }
};

int main() {
    BST s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(2);
    s.insert(5);

    s.inorder();

    return 0;
}