/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas-e <alucas-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 10:09:52 by andre             #+#    #+#             */
/*   Updated: 2025/11/25 13:42:13 by alucas-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <cstdlib>
#include <iostream>

class Base {
	public:
		virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};