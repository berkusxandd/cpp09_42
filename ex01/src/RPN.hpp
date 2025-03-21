/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:39 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:40 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <sstream>
#include <stack>
#include <stdexcept>
#include <cstdlib>
#include <iostream>
class RPN 
{
    public:
        RPN();
        ~RPN();
        RPN(RPN const &src);
        RPN &operator=(RPN const &rhs);
        int calculate(const std::string &exp);
};

//utils
bool isOperator(const std::string &token);
int applyOperation(int a, int b, const std::string &op);

#endif