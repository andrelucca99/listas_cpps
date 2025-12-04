/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:41:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/04 07:15:16 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <cstdlib>
#include "../includes/RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) {(void)other;}
RPN &RPN::operator=(const RPN &other) {(void)other; return *this;}
RPN::~RPN() {}

bool RPN::isOperator(char c) const {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int RPN::applyOperation(int a, int b, char op) const {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/') {
        if (b == 0)
            throw std::runtime_error("Error: division by zero");
        return a / b;
    }
    throw std::runtime_error("Error: invalid operator");
}

int RPN::evaluate(const std::string &expr) {
    std::stack<int> st;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            st.push(token[0] - '0');
        }
        else if (token.size() == 1 && isOperator(token[0])) {

            if (st.size() < 2)
                throw std::runtime_error("Error: invalid expression");

            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            int result = applyOperation(a, b, token[0]);
            st.push(result);
        }
        else {
            throw std::runtime_error("Error: invalid token");
        }
    }

    if (st.size() != 1)
        throw std::runtime_error("Error: invalid expression");

    return st.top();
}
