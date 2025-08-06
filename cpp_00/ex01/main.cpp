/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:21:53 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:48:46 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int main() {
    PhoneBook phonebook;
    string command;

    cout << "Welcome to PhoneBook!\n";
    while (true) 
    {
        cout << "Enter command (ADD, SEARCH, EXIT): ";
        getline(cin, command);

        if (cin.eof()) 
        {
            cout << "\nExiting...\n";
            break;
        }

        if (command == "ADD") 
        {
            phonebook.addContact();
        } 
        else if (command == "SEARCH") 
        {
            phonebook.searchContacts();
        } 
        else if (command == "EXIT") 
        {
            cout << "Bye bye!\n";
            break;
        } 
        else 
        {
            cout << "Invalid command.\n";
        }
    }
    return 0;
}
