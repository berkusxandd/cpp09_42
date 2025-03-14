/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:44 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:45 by bince            ###   ########.fr       */
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
    std::deque<int> d_numbers;
    std::vector<int> v_numbers;

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
    std::cout << "Before: ";
    std::deque<int>::iterator it = d_numbers.begin();
    for (; it!=d_numbers.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n\n";
    pmg.merge_sort(d_numbers,0,d_numbers.size() - 1);
    
    clock_t end_d = clock();
    double duration_d = (double)(end_d - start_d) / CLOCKS_PER_SEC * 1000000;
    
    std::cout << "After: ";
    std::deque<int>::iterator it2 = d_numbers.begin();
    
    for (; it2!=d_numbers.end(); it2++)
    {
        std::cout << *it2 << " ";
    }

    std::cout << std::endl;
    std::cout << "Time to process a range of " << d_numbers.size() << " elements with std::deque : " << duration_d << "us" << std::endl;

    clock_t start = clock();
    try
    {
        v_numbers = create_v(av);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 0;
    }
    pmg.merge_sort(v_numbers,0,v_numbers.size() - 1);
    clock_t end = clock();
    double duration_v = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << v_numbers.size() << " elements with std::vector : " << duration_v << "us" << std::endl;

}