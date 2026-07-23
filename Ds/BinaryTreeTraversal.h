//
// Created by Manoloon on 18/12/2023.
//
#ifndef INTERVIEWS_BINARYTREETRAVERSAL_H
#define INTERVIEWS_BINARYTREETRAVERSAL_H

namespace traversal {
    struct Node {
        Node *left;
        Node *right;
        int val;

        explicit Node(int value) : val(value), left(nullptr), right(nullptr) {}
    };

    std::vector<int> Traversal(Node *root) {
        std::vector<int> result;

        while (root != nullptr) {
            if (root->left == nullptr) {
                // If no left child, visit the current node
                result.push_back(root->val);
                root = root->right; // Move to the right
            } else {
                // Find the inorder predecessor
                Node *predecessor = root->left;
                while (predecessor->right != nullptr && predecessor->right != root) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    // Make current the right child of its inorder predecessor
                    predecessor->right = root;
                    root = root->left; // Move to the left
                } else {
                    // Revert the changes made in the tree and visit the current node
                    predecessor->right = nullptr;
                    result.push_back(root->val);
                    root = root->right; // Move to the right
                }
            }
        }
        return result;
    }

// Function to create a new node
    Node *newNode(int val) {
        return new Node(val);
    }

    // create root
    std::vector<int> CreateRootNode() {
        Node *root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(4);
        root->right->right = newNode(5);
        return traversal::Traversal(root);
    }

    void PrintTraversal() {
        // Display gathered values
        std::cout << "In-order traversal values: ";
        for (int val: traversal::CreateRootNode()) {
            std::cout << val << " ";
        }
    }
}

/*
#include <SFML/Graphics.hpp>
void drawTree(Node* root, sf::RenderWindow& window, float x,float y, float nodeOffsetX,float nodeOffsetY){
    if (root== nullptr) return;
    sf::CircleShape circle;
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(x,y);

    sf::Text text(std::to_string(root->val),sf::Font(),20);
    text.setPosition(x+10,y+10);
    text.setFillColor(sf::Color::Red);

    window.draw(circle);
    window.draw(text);
    if(root->left != nullptr){
        sf::Vertex line[]{
        sf::Vertex(sf::Vector2f(x,y+25)),
        sf::Vertex(sf::Vector2f(x-nodeOffsetX,y+nodeOffsetY - 25))
        };
        window.draw(line,2,sf::Lines);
        drawTree(root->right, window, x + nodeOffsetX, y + nodeOffsetY, nodeOffsetX / 2, nodeOffsetY);
    }
}
main()
{
	/*
    sf::RenderWindow window(sf::VideoMode(800,600),"Binary tree trasversal");
    while(window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear(sf::Color::White);
        for(auto val : values){
            drawTree(root,window,400,50,200,100);
        }
        window.display();
    }
    */
}
*/
#endif //INTERVIEWS_BINARYTREETRAVERSAL_H
