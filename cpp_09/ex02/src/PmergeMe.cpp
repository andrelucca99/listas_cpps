/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:41:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/04 07:37:07 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <limits.h>
#include "../includes/PmergeMe.hpp"

int PmergeMe::stringToInt(const std::string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        if (!isdigit(s[i]))
            throw std::runtime_error("Error: invalid number.");
    }
    long n = atol(s.c_str());
    if (n < 0 || n > INT_MAX)
        throw std::runtime_error("Error: number out of range.");
    return static_cast<int>(n);
}

void PmergeMe::validateInput(const std::vector<std::string> &args) {
    std::vector<int> tmp;
    for (size_t i = 0; i < args.size(); i++) {
        int value = stringToInt(args[i]);

        if (std::find(tmp.begin(), tmp.end(), value) != tmp.end())
            throw std::runtime_error("Error: duplicate number.");

        tmp.push_back(value);
    }
}

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &o) { *this = o; }

PmergeMe &PmergeMe::operator=(const PmergeMe &o) {
    if (this != &o) {
        this->vec = o.vec;
        this->deq = o.deq;
    }
    return *this;
}

template <typename T>
void PmergeMe::printContainer(const T &c) {
    for (size_t i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;
}

static void vectorInsert(std::vector<int> &sorted, int value) {
    std::vector<int>::iterator pos =
        std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

static void dequeInsert(std::deque<int> &sorted, int value) {
    std::deque<int>::iterator pos =
        std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
}

std::vector<int> PmergeMe::fordJohnsonVector(const std::vector<int> &input) {
    if (input.size() <= 1)
        return input;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> leftovers;

    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 < input.size()) {
            int a = input[i];
            int b = input[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        } else {
            leftovers.push_back(input[i]);
        }
    }

    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    std::sort(mainChain.begin(), mainChain.end());

    for (size_t i = 0; i < pairs.size(); i++)
        vectorInsert(mainChain, pairs[i].first);

    for (size_t i = 0; i < leftovers.size(); i++)
        vectorInsert(mainChain, leftovers[i]);

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonDeque(const std::deque<int> &input) {
    if (input.size() <= 1)
        return input;

    std::deque<std::pair<int, int> > pairs;
    std::deque<int> leftovers;

    for (size_t i = 0; i < input.size(); i += 2) {
        if (i + 1 < input.size()) {
            int a = input[i];
            int b = input[i + 1];
            if (a > b)
                std::swap(a, b);
            pairs.push_back(std::make_pair(a, b));
        } else {
            leftovers.push_back(input[i]);
        }
    }

    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);

    std::sort(mainChain.begin(), mainChain.end());

    for (size_t i = 0; i < pairs.size(); i++)
        dequeInsert(mainChain, pairs[i].first);

    for (size_t i = 0; i < leftovers.size(); i++)
        dequeInsert(mainChain, leftovers[i]);

    return mainChain;
}

void PmergeMe::sortVector() {
    vec = fordJohnsonVector(vec);
}

void PmergeMe::sortDeque() {
    deq = fordJohnsonDeque(deq);
}

void PmergeMe::process(const std::vector<std::string> &args) {
    validateInput(args);

    for (size_t i = 0; i < args.size(); i++) {
        int n = stringToInt(args[i]);
        vec.push_back(n);
        deq.push_back(n);
    }

    std::cout << "Before: ";
    printContainer(vec);

    struct timeval start, end;
    gettimeofday(&start, NULL);
    sortVector();
    gettimeofday(&end, NULL);

    long vecTime = (end.tv_sec - start.tv_sec) * 1000000 +
                   (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sortDeque();
    gettimeofday(&end, NULL);

    long deqTime = (end.tv_sec - start.tv_sec) * 1000000 +
                   (end.tv_usec - start.tv_usec);

    std::cout << "After:  ";
    printContainer(vec);

    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << vecTime << " us\n";
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << deqTime << " us\n";
}
