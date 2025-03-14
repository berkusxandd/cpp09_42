/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:10 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:54:50 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac < 2)
    {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 0;
    }
    BitcoinExchange BtcXc;
    try
    {
        BtcXc.startConversion(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}