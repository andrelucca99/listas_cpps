/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 17:12:18 by alucas-e          #+#    #+#             */
/*   Updated: 2025/07/18 17:17:00 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return 0;
	}

	int i = 1;
	while (i < argc)
	{
		string str = argv[i];
		size_t j = 0;
		while (j < str.length())
		{
			cout << (char)toupper(str[j]);
			j++;
		}
		if (i < argc - 1)
			cout << " ";
		i++;
	}
	cout << endl;

	return 0;
}