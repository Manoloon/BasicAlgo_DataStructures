#pragma once

#include <stdexcept>
#include <iostream>

template<typename T>
class Stack {
    int MaxSize=100;
    T stack[100];
    int top=0;

    void Resize() {
        MaxSize = 2 * stack.max_size();
        T copyStack[MaxSize];
        for (int i = 0; i < MaxSize; i++) {
            copyStack[i] = stack[i];
            stack = copyStack;
        }
    }

public:
    void Push(T Val) {
        if (top >= MaxSize - 1) {
            throw std::domain_error("item not found");
        }
        if (top == MaxSize) {
            Resize();
        }
        stack[++top] = Val;
    }

    T Pop() {
        if (top < 1) {
            throw std::domain_error("item not found");
        }

        return stack[--top];
    }

    void Peek() {
        if (top < 1) {
            throw std::domain_error("item not found");
        }
        std::cout << stack[top] << std::endl;
    }
};
