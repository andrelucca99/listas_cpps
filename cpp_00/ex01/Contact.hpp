/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:27:34 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:35:37 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

using namespace std;

class Contact
{
	private:
		string firstName;
		string lastName;
		string nickName;
		string phoneNumber;
		string darkestSecret;
	public:
		Contact();
		void setContact(string firstName, string lastName,
			string nickName, string phoneNumber, string darkestSecret);
		string getFirstName() const;
		string getLastName() const;
		string getNickName() const;
		string getPhoneNumber() const;
		string getDarkestSecret() const;

		bool isEmpty() const;
};