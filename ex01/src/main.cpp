/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:36 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 16:11:13 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

// 5 1 2 + 4 * + 3 -                    = 14
// 7 2 8 * + 3 -                        = 20
// 9 8 + 7 6 + * 5 4 + 3 2 + * -        = 176
// 9 8 + 7 6 + * 5 4 + * 3 2 + * 1 -    = 9944
// 9 8 + 7 6 + * 5 4 + * 3 2 + * 1 - 0 / = Invalid
int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid arguments" << std::endl;
        return 1;
    }

    RPN rpn;
    try 
    {
        int result = rpn.calculate(argv[1]);
        std::cout << result << std::endl;
    } 
    catch (const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}