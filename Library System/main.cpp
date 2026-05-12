#include <iostream>
#include "LibraryAVL.h"
#include "LibraryBST.h"

using namespace std;

// =====================================================
// Helpers
// =====================================================

void printBST(LibraryBST* bst, const string& title) {
    cout << "\n" << title << "\n";
    bst->inorder(bst->getRoot());

    cout << "Height: " << bst->treeHeight() << endl;

    cout << "Range 20 -> 70:\n";
    bst->inrange(20, 70, bst->getRoot());
}

void printAVL(LibraryAVL* avl, const string& title) {
    cout << "\n" << title << "\n";
    avl->inorderTraversal();

    cout << "Height: " << avl->treeHeight() << endl;

    cout << "Range 20 -> 70:\n";
    avl->rangeSearch(20, 70);
}

// =====================================================
// BST Tests
// =====================================================

void testBST() {
    cout << "\n================ BST TEST ================\n";

    Book bstRandom[20] = {
        {45,"A","A1"}, {12,"B","A2"}, {78,"C","A3"}, {3,"D","A4"}, {67,"E","A5"},
        {23,"F","A6"}, {89,"G","A7"}, {34,"H","A8"}, {56,"I","A9"}, {1,"J","A10"},
        {99,"K","A11"}, {10,"L","A12"}, {41,"M","A13"}, {72,"N","A14"}, {28,"O","A15"},
        {60,"P","A16"}, {5,"Q","A17"}, {38,"R","A18"}, {84,"S","A19"}, {50,"T","A20"}
    };

    // Random BST
    LibraryBST bst1;
    for (auto& b : bstRandom)
        bst1.insertBook(b);

    printBST(&bst1, "BST Inorder (Random)");

    // Sorted BST
    cout << "\nBST (SORTED INSERTION CASE)\n";

    LibraryBST bst2;
    for (int i = 1; i <= 20; i++) {
        bst2.insertBook({ i, "Book", "Author" });
    }

    cout << "\nBST Inorder (Sorted):\n";
    bst2.inorder(bst2.getRoot());

    cout << "Height: " << bst2.treeHeight() << endl;
}

// =====================================================
// AVL Tests
// =====================================================

void testAVL() {
    cout << "\n================ AVL TEST ================\n";

    Book avlRandom[20] = {
        {45,"A","A1"}, {12,"B","A2"}, {78,"C","A3"}, {3,"D","A4"}, {67,"E","A5"},
        {23,"F","A6"}, {89,"G","A7"}, {34,"H","A8"}, {56,"I","A9"}, {1,"J","A10"},
        {99,"K","A11"}, {10,"L","A12"}, {41,"M","A13"}, {72,"N","A14"}, {28,"O","A15"},
        {60,"P","A16"}, {5,"Q","A17"}, {38,"R","A18"}, {84,"S","A19"}, {50,"T","A20"}
    };

    // Random AVL
    LibraryAVL avl1;
    for (auto& b : avlRandom)
        avl1.insert(b);

    printAVL(&avl1, "AVL Inorder (Random)");

    // Sorted AVL
    cout << "\nAVL (SORTED INSERTION CASE)\n";

    LibraryAVL avl2;
    for (int i = 1; i <= 20; i++) {
        avl2.insert({ i, "Book", "Author" });
    }

    cout << "\nAVL Inorder (Sorted):\n";
    avl2.inorderTraversal();

    cout << "Height: " << avl2.treeHeight() << endl;
}

// =====================================================
// Main
// =====================================================

int main() {
    testBST();
    testAVL();
    return 0;
}