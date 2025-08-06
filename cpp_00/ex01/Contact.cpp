/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:27:34 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:49:40 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() 
{
    firstName = "";
    lastName = "";
    nickName = "";
    phoneNumber = "";
    darkestSecret = "";
}

void Contact::setContact(string f, string l, string n,
                          string p, string d) 
{
    firstName = f;
    lastName = l;
    nickName = n;
    phoneNumber = p;
    darkestSecret = d;
}

string Contact::getFirstName() const 
{
    return firstName;
}
string Contact::getLastName() const 
{
    return lastName;
}
string Contact::getNickName() const 
{
    return nickName;
}
string Contact::getPhoneNumber() const 
{
    return phoneNumber;
}
string Contact::getDarkestSecret() const 
{
    return darkestSecret;
}

bool Contact::isEmpty() const 
{
    return firstName.empty();
}