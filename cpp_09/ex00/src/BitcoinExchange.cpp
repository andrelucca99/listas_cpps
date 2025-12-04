/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 14:41:35 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 14:52:12 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> // strtod
#include <cctype>
#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

// trim simples (remove espaços no início e fim)
std::string BitcoinExchange::trim(const std::string &s) {
    size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) start++;
    size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) end--;
    return s.substr(start, end - start);
}

// Validação mínima do formato YYYY-MM-DD (não valida calendário completo)
bool BitcoinExchange::isValidDateFormat(const std::string &date) {
    if (date.length() != 10) return false;
    // positions 4 and 7 must be '-'
    if (date[4] != '-' || date[7] != '-') return false;
    // year
    for (size_t i = 0; i < date.size(); ++i) {
        if (i == 4 || i == 7) continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i]))) return false;
    }
    // check month/day ranges (basic)
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    // optional: reject years that are too small/large
    if (year < 0) return false;
    return true;
}

bool BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }

    std::string line;
    bool firstLine = true;
    while (std::getline(file, line)) {
        // skip empty lines
        if (line.empty()) continue;

        // If there's a header like "date,exchange_rate", skip it
        if (firstLine) {
            std::string tmp = line;
            tmp = trim(tmp);
            // detect header by checking for non-digit chars before comma
            // a simple heuristic: if contains "date" or "exchange" skip header
            if (tmp.find("date") != std::string::npos || tmp.find("exchange") != std::string::npos) {
                firstLine = false;
                continue;
            }
            // else fallthrough (maybe there is no header)
        }
        firstLine = false;

        // split by comma (date,rate)
        std::string::size_type commaPos = line.find(',');
        if (commaPos == std::string::npos) {
            std::cerr << "Error: invalid database line => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));

        if (!isValidDateFormat(date)) {
            std::cerr << "Error: invalid date in database => " << date << std::endl;
            continue;
        }

        // parse rate
        char *endptr = NULL;
        errno = 0;
        double rate = std::strtod(rateStr.c_str(), &endptr);
        if (endptr == rateStr.c_str() || *endptr != '\0' || errno == ERANGE) {
            std::cerr << "Error: invalid rate in database => " << rateStr << std::endl;
            continue;
        }
        // optional: reject negative or zero rates
        if (rate < 0.0) {
            std::cerr << "Error: negative rate in database => " << rateStr << std::endl;
            continue;
        }

        // insert into map (if duplicate date, we'll overwrite with last read)
        _db[date] = rate;
    }

    file.close();
    return true;
}

void BitcoinExchange::processInput(const std::string &filename) const {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    bool firstLine = true;

    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        // Skip header "date | value"
        if (firstLine) {
            firstLine = false;
            if (line.find("date") != std::string::npos)
                continue;
        }

        // Parse format: "YYYY-MM-DD | value"
        std::string::size_type pipePos = line.find('|');

        if (pipePos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        // Validate date
        if (!isValidDateFormat(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Parse numeric value
        char *endptr;
        errno = 0;
        double value = std::strtod(valueStr.c_str(), &endptr);

        // invalid number?
        if (endptr == valueStr.c_str() || *endptr != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Value constraints
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // ---- FIND RATE IN DATABASE ----

        std::map<std::string, double>::const_iterator it = _db.lower_bound(date);

        if (it == _db.end()) {
            // all keys are smaller → pick last
            it = --_db.end();
        } else if (it->first != date) {
            if (it == _db.begin()) {
                // no earlier date available
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            --it; // move to previous date
        }

        // Now "it" is the correct rate for the date or nearest earlier date
        double rate = it->second;
        double result = value * rate;

        // Print result exactly as subject wants
        std::cout << date << " => " << value << " = " << result << std::endl;
    }

    file.close();
}
