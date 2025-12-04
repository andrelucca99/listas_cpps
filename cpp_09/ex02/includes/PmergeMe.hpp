/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/04 07:40:52 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <deque>
#include <string>
#include <sys/time.h>
#include <iostream>

class PmergeMe {
    private:
        std::vector<int> vec;
        std::deque<int> deq;

        void sortVector();
        void sortDeque();

        std::vector<int> fordJohnsonVector(const std::vector<int> &input);
        std::deque<int> fordJohnsonDeque(const std::deque<int> &input);

        int stringToInt(const std::string &s);
        void validateInput(const std::vector<std::string> &args);

        template <typename T>
        void printContainer(const T &c);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &o);
        PmergeMe &operator=(const PmergeMe &o);
        ~PmergeMe();

        void process(const std::vector<std::string> &args);
};
