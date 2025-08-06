/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:36:55 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:47:47 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <limits>

PhoneBook::PhoneBook()
{
	count = 0;
	oldestIndex = 0;
}

string PhoneBook::truncateField(const string& str) const
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void PhoneBook::addContact() 
{
    string firstName, lastName, nickname, phoneNumber, darkestSecret;

    cout << "First Name: ";
    getline(cin, firstName);
    cout << "Last Name: ";
    getline(cin, lastName);
    cout << "Nickname: ";
    getline(cin, nickname);
    cout << "Phone Number: ";
    getline(cin, phoneNumber);
    cout << "Darkest Secret: ";
    getline(cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty()
        || phoneNumber.empty() || darkestSecret.empty()) {
        cout << "All fields are required! Contact not saved.\n";
        return;
    }

    contacts[oldestIndex].setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    oldestIndex = (oldestIndex + 1) % 8;
    if (count < 8)
        count++;

    cout << "Contact added successfully!\n";
}

void PhoneBook::searchContacts() const 
{
    if (count == 0) 
    {
        cout << "Phonebook is empty.\n";
        return;
    }

    cout << setw(10) << "Index" << "|"
              << setw(10) << "First Name" << "|"
              << setw(10) << "Last Name" << "|"
              << setw(10) << "Nickname" << endl;
    int i = 0;
    while (i < count) 
    {
        cout << setw(10) << i << "|"
                  << setw(10) << truncateField(contacts[i].getFirstName()) << "|"
                  << setw(10) << truncateField(contacts[i].getLastName()) << "|"
                  << setw(10) << truncateField(contacts[i].getNickName()) << endl;
        i++;
    }

    cout << "Enter index to view details: ";
    int index;
    cin >> index;

    if (cin.fail() || index < 0 || index >= count) 
    {
        cout << "Invalid index.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    displayContact(index);
}

void PhoneBook::displayContact(int index) const 
{
    const Contact& c = contacts[index];
    cout << "First Name: " << c.getFirstName() << endl;
    cout << "Last Name: " << c.getLastName() << endl;
    cout << "Nickname: " << c.getNickName() << endl;
    cout << "Phone Number: " << c.getPhoneNumber() << endl;
    cout << "Darkest Secret: " << c.getDarkestSecret() << endl;
}
