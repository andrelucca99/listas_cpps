/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:08 by andre             #+#    #+#             */
/*   Updated: 2025/11/24 11:54:04 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./includes/Serializer.hpp"

int main(void)
{
	Data data;
	data.id = 42;
	data.name = "André";

	std::cout << "Original pointer: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "Serialized value: " << raw << std::endl;

	Data* restored = Serializer::deserialize(raw);

	std::cout << "Restored pointer: " << restored << std::endl;

	std::cout << "Restored content: id=" << restored->id << " , name=" << restored->name << std::endl;

	return 0;
}
