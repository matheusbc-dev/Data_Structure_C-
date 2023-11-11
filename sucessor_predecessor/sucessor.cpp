#include <iostream>

// Definindo a classe TreeNode para representar um nó na árvore binária
class TreeNode {
public:
    int key;          // Chave do nó
    TreeNode* parent;  // Ponteiro para o pai
    TreeNode* left;    // Ponteiro para o filho esquerdo
    TreeNode* right;   // Ponteiro para o filho direito

    // Construtor para inicializar um nó com uma chave
    TreeNode(int k) : key(k), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Definindo a classe BinarySearchTree para representar uma Árvore Binária de Busca
class BinarySearchTree {
public:
    TreeNode* root;  // Ponteiro para o nó raiz

    // Construtor para inicializar uma árvore vazia
    BinarySearchTree() : root(nullptr) {}

    // Função para inserir um nó na árvore
    void insert(TreeNode* z) {
        TreeNode* y = nullptr;  // Inicializando y como nulo
        TreeNode* x = root;     // Inicializando x como a raiz da árvore

        // Enquanto x não for nulo, percorre a árvore para encontrar a posição de inserção
        while (x != nullptr) {
            y = x;  // Atualiza y para o nó atual
            if (z->key < x->key) {
                x = x->left;
            } else {
                x = x->right;
            }
        }

        // Configura o pai do novo nó como y
        z->parent = y;

        // Se y for nulo, a árvore está vazia, então o novo nó se torna a raiz
        if (y == nullptr) {
            root = z;
        } else if (z->key < y->key) {
            y->left = z;  // Se a chave do novo nó for menor, insere à esquerda
        } else {
            y->right = z; // Se a chave do novo nó for maior, insere à direita
        }
    }

    // Função para encontrar o nó com a chave mínima na árvore
    TreeNode* minimum(TreeNode* x) {
        // Enquanto o filho esquerdo não for nulo, avança para o filho esquerdo
        while (x != nullptr && x->left != nullptr) {
            x = x->left;
        }

        // Retorna o nó com a chave mínima
        return x;
    }

    // Função para encontrar o sucessor de um nó na árvore
    TreeNode* successor(TreeNode* x) {
        // Se o filho direito não for nulo, retorna o mínimo do subárvore direita
        if (x->right != nullptr) {
            return minimum(x->right);
        }

        // Inicializa y como o pai de x
        TreeNode* y = x->parent;

        // Enquanto y não for nulo e x é o filho direito de y
        while (y != nullptr && x == y->right) {
            x = y;  // Atualiza x para y
            y = y->parent;  // Atualiza y para o pai de y
        }

        // Retorna o sucessor (pode ser nulo se x for o maior elemento na árvore)
        return y;
    }
};

int main() {
    BinarySearchTree tree;

    TreeNode* newNode1 = new TreeNode(10);
    tree.insert(newNode1);

    TreeNode* newNode2 = new TreeNode(5);
    tree.insert(newNode2);

    TreeNode* newNode3 = new TreeNode(15);
    tree.insert(newNode3);

    TreeNode* newNode4 = new TreeNode(3);
    tree.insert(newNode4);

    TreeNode* newNode5 = new TreeNode(7);
    tree.insert(newNode5);

    TreeNode* newNode6 = new TreeNode(12);
    tree.insert(newNode6);

    TreeNode* newNode7 = new TreeNode(18);
    tree.insert(newNode7);

    // Encontrar o sucessor de um nó e imprimir a chave
    TreeNode* successorNode = tree.successor(newNode5);
    if (successorNode != nullptr) {
        std::cout << "Sucessor de " << newNode5->key << " é: " << successorNode->key << std::endl;
    } else {
        std::cout << "Nó " << newNode5->key << " não tem sucessor." << std::endl;
    }

    // Libera a memória alocada pelos nós da árvore
    delete newNode1;
    delete newNode2;
    delete newNode3;
    delete newNode4;
    delete newNode5;
    delete newNode6;
    delete newNode7;

    return 0;
}