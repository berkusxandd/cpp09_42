/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:44 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 19:43:14 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <deque>
#include "PMergeMe.hpp"
#include <stdexcept>
#include <ctime>

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cerr << "Error: Bad Input." << std::endl;
        return 0;
    }

    
    PMergeMe pmg;
    std::vector<int> v_numbers;
    std::deque<int> d_numbers;
    clock_t start_v = clock();
    try
    {
        v_numbers = create_v(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    std::cout << "Before: ";
    print_vector(v_numbers);
    pmg.sort(v_numbers);
    clock_t end_v = clock();
    std::cout << "After: ";
    print_vector(v_numbers);
    double duration_v = (double)(end_v - start_v) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << v_numbers.size() << " elements with std::vector : " << duration_v << "us" << std::endl;
    
    clock_t start_d = clock();
    try
    {
        d_numbers = create_d(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    pmg.sort(d_numbers);
    clock_t end_d = clock();
    double duration_d = (double)(end_d - start_d) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << d_numbers.size() << " elements with std::deque : " << duration_d << "us" << std::endl;
}