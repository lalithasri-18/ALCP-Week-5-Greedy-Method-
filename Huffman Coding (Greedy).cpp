#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL) {
        if (code == "")
            code = "0";

        cout << root->ch << " : " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanCoding(char ch[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, compare> pq;

    for (int i = 0; i < n; i++) {
        pq.push(new Node(ch[i], freq[i]));
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    printCodes(pq.top(), "");
}

int main() {
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    if (n <= 0)
        return 0;

    vector<char> ch(n);
    vector<int> freq(n);

    cout << "Enter characters and frequencies:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch[i] >> freq[i];
    }

    cout << "Huffman Codes:\n";
    huffmanCoding(&ch[0], &freq[0], n);

    return 0;
}
