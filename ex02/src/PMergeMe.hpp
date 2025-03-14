/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:47 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 19:40:25 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP
#define THRESHOLD 32
#include <vector>
#include <deque>
#include <iostream>
class PMergeMe
{
    public:
        PMergeMe();
        ~PMergeMe();
        PMergeMe(PMergeMe const &src);
        PMergeMe &operator=(PMergeMe const &rhs);
        void sort(std::vector<int>& arr);
        void sort(std::deque<int>& arr);
    private:
        void fj_sort(std::vector<int>& arr,int left, int right);
        void fj_sort(std::deque<int>& arr,int left, int right);
    };

//utils
std::vector<int> create_v(char **av);
std::deque<int> create_d(char **av);
void print_vector(std::vector<int>& v);
#endif