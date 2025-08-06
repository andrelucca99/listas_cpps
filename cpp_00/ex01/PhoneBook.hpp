/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:36:55 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:50:04 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int count, oldestIndex;
		string truncateField(const string& str) const;
	
	public:
		PhoneBook();
		void addContact();
		void searchContacts() const;
		void displayContact(int index) const;
};
