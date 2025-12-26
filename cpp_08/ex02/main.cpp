/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:04:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/26 08:52:34 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <iostream>
#include "./includes/MutantStack.hpp"

void separator(const std::string &title) {
    std::cout << "\n==== " << title << " ====\n";
}

int main()
{
    /* ========================================================= */
    separator("TEST 1: Basic stack behavior");
    /* ========================================================= */

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;

    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "Stack content using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 2: Const iterator");
    /* ========================================================= */

    const MutantStack<int> constStack(mstack);

    std::cout << "Const stack iteration:" << std::endl;
    for (MutantStack<int>::const_iterator it = constStack.begin();
         it != constStack.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 3: Reverse iterator");
    /* ========================================================= */

    std::cout << "Reverse iteration:" << std::endl;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin();
         it != mstack.rend(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 4: Copy constructor");
    /* ========================================================= */

    MutantStack<int> copyStack(mstack);

    copyStack.pop();
    copyStack.push(999);

    std::cout << "Original stack:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it)
        std::cout << *it << std::endl;

    std::cout << "Copied stack (after modification):" << std::endl;
    for (MutantStack<int>::iterator it = copyStack.begin(); it != copyStack.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 5: Assignment operator");
    /* ========================================================= */

    MutantStack<int> assignStack;
    assignStack = mstack;

    assignStack.push(42);

    std::cout << "Assigned stack:" << std::endl;
    for (MutantStack<int>::iterator it = assignStack.begin();
         it != assignStack.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 6: Compatibility with std::stack");
    /* ========================================================= */

    std::stack<int> stdStack(mstack);

    std::cout << "std::stack top: " << stdStack.top() << std::endl;
    std::cout << "std::stack size: " << stdStack.size() << std::endl;

    /* ========================================================= */
    separator("TEST 7: Comparison with std::list");
    /* ========================================================= */

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.pop_back();
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "std::list content:" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 8: Different type (std::string)");
    /* ========================================================= */

    MutantStack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("CPP");
    stringStack.push("42");

    for (MutantStack<std::string>::iterator it = stringStack.begin();
         it != stringStack.end(); ++it)
        std::cout << *it << std::endl;

    /* ========================================================= */
    separator("TEST 9: Empty stack iteration");
    /* ========================================================= */

    MutantStack<int> emptyStack;

    std::cout << "Iterating empty stack (should print nothing):" << std::endl;
    for (MutantStack<int>::iterator it = emptyStack.begin();
         it != emptyStack.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
