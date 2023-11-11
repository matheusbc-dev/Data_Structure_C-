#include <iostream>

// Definindo a classe TreeNode para representar um nó na árvore binária
class TreeNode {
public:
    int key;          // Chave do nó
    TreeNode* left;   // Ponteiro para o filho esquerdo
    TreeNode* right;  // Ponteiro para o filho direito

    // Construtor para inicializar um nó com uma chave
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Função de busca em árvore binária de forma recursiva
TreeNode* recursiveTreeSearch(TreeNode* x, int key) {
    // Verifica se o nó atual é nulo ou se a chave foi encontrada no nó atual
    if (x == nullptr || key == x->key) {
        return x;
    }

    // Se a chave for menor que a chave do nó atual, recursivamente busca no filho esquerdo
    if (key < x->key) {
        return recursiveTreeSearch(x->left, key);
    }
    // Se a chave for maior, recursivamente busca no filho direito
    else {
        return recursiveTreeSearch(x->right, key);
    }
}

int main() {
    TreeNode* root = new TreeNode(10);      // Cria um nó raiz com chave 10
    root->left = new TreeNode(5);           // Adiciona um filho esquerdo com chave 5
    root->right = new TreeNode(15);         // Adiciona um filho direito com chave 15
    root->left->left = new TreeNode(3);     // Adiciona um neto à esquerda com chave 3
    root->left->right = new TreeNode(7);    // Adiciona um neto à direita com chave 7
    root->right->left = new TreeNode(12);   // Adiciona um neto à esquerda com chave 12
    root->right->right = new TreeNode(18);  // Adiciona um neto à direita com chave 18

    int keyToSearch = 7;
    TreeNode* result = recursiveTreeSearch(root, keyToSearch);

    // Verifica se a chave foi encontrada e exibe uma mensagem correspondente
    if (result != nullptr) {
        std::cout << "Chave encontrada: " << result->key << std::endl;
    } else {
        std::cout << "Chave não encontrada." << std::endl;
    }

    // Libera a memória alocada pelos nós da árvore
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
