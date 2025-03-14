/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:47 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:48 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

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
        void merge_sort(std::vector<int>& arr,int left, int right);
        void merge_sort(std::deque<int>& arr,int left, int right);
    private:
        void merge(std::vector<int>&arr, int left, int mid, int right);
        void merge(std::deque<int>&arr, int left, int mid, int right);
};

//utils
std::vector<int> create_v(char **av);
std::deque<int> create_d(char **av);

#endif