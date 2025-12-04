/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andre <andre@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 13:05:46 by andre             #+#    #+#             */
/*   Updated: 2025/12/03 14:42:38 by andre            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <string>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();

    // carrega o CSV com as taxas (date,rate)
    // retorna true se carregou com sucesso, false se não conseguiu abrir
    bool loadDatabase(const std::string &filename);

    // (será implementado depois)
    void processInput(const std::string &filename) const;

private:
    std::map<std::string, double> _db;

    // helpers
    static std::string trim(const std::string &s);
    static bool isValidDateFormat(const std::string &date); // YYYY-MM-DD (basic check)
};
