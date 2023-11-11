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

    // Função para excluir um nó da árvore
    void deleteNode(TreeNode* D) {
        if (D->left == nullptr) {
            shiftNodes(D, D->right);
        } else if (D->right == nullptr) {
            shiftNodes(D, D->left);
        } else {
            TreeNode* E = successor(D);

            if (E->parent != D) {
                shiftNodes(E, E->right);
                E->right = D->right;
                E->right->parent = E;
            }

            shiftNodes(D, E);
            E->left = D->left;
            E->left->parent = E;
        }
    }

    // Função para imprimir a árvore em ordem
    void printInOrder(TreeNode* x) {
        if (x != nullptr) {
            printInOrder(x->left);
            std::cout << x->key << " ";
            printInOrder(x->right);
        }
    }

private:
    // Função auxiliar para reorganizar os nós durante a exclusão
    void shiftNodes(TreeNode* u, TreeNode* v) {
        if (u->parent == nullptr) {
            root = v;
        } else if (u == u->parent->left) {
            u->parent->left = v;
        } else {
            u->parent->right = v;
        }

        if (v != nullptr) {
            v->parent = u->parent;
        }
    }

    // Função auxiliar para encontrar o sucessor de um nó na árvore
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

    // Função auxiliar para encontrar o nó com a chave mínima na árvore
    TreeNode* minimum(TreeNode* x) {
        // Enquanto o filho esquerdo não for nulo, avança para o filho esquerdo
        while (x != nullptr && x->left != nullptr) {
            x = x->left;
        }

        // Retorna o nó com a chave mínima
        return x;
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

    // Excluir um nó e imprimir a árvore resultante
    tree.deleteNode(newNode3);
    std::cout << "Árvore após excluir o nó 15: ";
    tree.printInOrder(tree.root);
    std::cout << std::endl;

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
