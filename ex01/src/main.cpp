/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:36 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:37 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "RPN.hpp"
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