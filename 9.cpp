//9.A Dictionary stores keywords & its meanings. 
//Provide facility for adding new keywords, deleting keywords, updating values of any entry.
// Provide facility to display whole data sorted in ascending/ Descending order.
// Also find how many maximum comparisons may require for finding any keyword. 
//Use Binary Search Tree for implementation.

#include <iostream>
using namespace std;

struct node {
    string key;
    string meaning;
    node* left;
    node* right;
};

class dict {
public:
    node* insert(node* root, string key, string meaning) {
        node* newnode = new node{key, meaning, nullptr, nullptr};

        if (root == nullptr)
            return newnode;

        if (key < root->key)
            root->left = insert(root->left, key, meaning);
        else if (key > root->key)
            root->right = insert(root->right, key, meaning);
        else
            cout << "Duplicate key ignored: " << key << endl;

        return root;
    }

    void ascending(node* root) {
        if (!root) return;
        ascending(root->left);
        cout << "Word: " << root->key << " | Meaning: " << root->meaning << endl;
        ascending(root->right);
    }

    void descending(node* root) {
        if (!root) return;
        descending(root->right);
        cout << "Word: " << root->key << " | Meaning: " << root->meaning << endl;
        descending(root->left);
    }

    int search(node* root, string key) {
        int comparisons = 0;
        while (root != nullptr) {
            comparisons++;
            if (key == root->key) {
                cout << "Found: " << root->meaning << endl;
                return comparisons;
            } 
            else if (key < root->key)
                root = root->left;
            else
                root = root->right;
        }
        cout << "Not found!" << endl;
        return comparisons;
    }

    int height(node* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    node* minNode(node* root) {
        while (root && root->left)
            root = root->left;
        return root;
    }

    node* deleteNode(node* root, string key) {
        if (!root) return nullptr;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            else if (!root->left) {
                node* temp = root->right;
                delete root;
                return temp;
            }
            else if (!root->right) {
                node* temp = root->left;
                delete root;
                return temp;
            }
            else {
                node* succ = minNode(root->right);
                root->key = succ->key;
                root->meaning = succ->meaning;
                root->right = deleteNode(root->right, succ->key);
            }
        }
        return root;
    }

    void update(node* root, string key, string newMeaning) {
        if (!root) return;
        if (root->key == key)
            root->meaning = newMeaning;
        else if (key < root->key)
            update(root->left, key, newMeaning);
        else
            update(root->right, key, newMeaning);
    }
};

int main() {
    dict d;
    node* root = nullptr;

    // Insertion
    root = d.insert(root, "apple", "a fruit");
    root = d.insert(root, "banana", "yellow fruit");
    root = d.insert(root, "zebra", "animal");
    root = d.insert(root, "cat", "pet");

    cout << "\nAscending:\n";
    d.ascending(root);

    cout << "\nDescending:\n";
    d.descending(root);

    cout << "\nSearch 'banana':\n";
    int c = d.search(root, "banana");
    cout << "Comparisons required: " << c << endl;

    cout << "\nUpdate 'banana':\n";
    d.update(root, "banana", "sweet yellow fruit");
    d.ascending(root);

    cout << "\nDelete 'apple':\n";
    root = d.deleteNode(root, "apple");
    d.ascending(root);

    cout << "\nMaximum comparisons (tree height): " << d.height(root) << endl;

    return 0;
}
