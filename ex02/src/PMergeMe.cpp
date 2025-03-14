/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:46 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 19:47:28 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
}

PMergeMe::~PMergeMe()
{
}

PMergeMe::PMergeMe(PMergeMe const &src)
{
    *this=src;
}

PMergeMe &PMergeMe::operator=(PMergeMe const &rhs)
{
    if (this == &rhs)
        std::cerr << "Copy overload didn't work" << std::endl;
    return *this;
}

void PMergeMe::sort(std::vector<int>& arr) 
{
    if (arr.size() <= 1) 
        return;
    fj_sort(arr, 0, arr.size() - 1);
}

void PMergeMe::sort(std::deque<int>& arr) 
{
    if (arr.size() <= 1) 
        return;
    fj_sort(arr, 0, arr.size() - 1);
}

void PMergeMe::fj_sort(std::vector<int>& arr, int left, int right)
{
    if (right - left <= 0) 
        return;

    std::vector<std::pair<int, int> > pairs;
    std::vector<int> large, small;

    for (int i = left; i + 1 <= right; i += 2) 
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++) 
    {
        large.push_back(pairs[i].first);
        small.push_back(pairs[i].second);
    }

    if ((right - left + 1) % 2 != 0)
        large.push_back(arr[right]);

    fj_sort(large, 0, large.size() - 1);

    std::vector<int> sortedArr = large;
    for (size_t i = 0; i < small.size(); i++) 
    {
        int x = small[i];
        std::vector<int>::iterator pos = std::lower_bound(sortedArr.begin(), sortedArr.end(), x);
        sortedArr.insert(pos, x);
    }
    for (size_t i = 0; i < sortedArr.size(); i++)
        arr[left + i] = sortedArr[i];
}

void PMergeMe::fj_sort(std::deque<int>& arr, int left, int right)
{
    if (right - left <= 0) 
        return;

    std::vector<std::pair<int, int> > pairs;
    std::deque<int> large, small;

    for (int i = left; i + 1 <= right; i += 2) 
    {
        if (arr[i] > arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++) 
    {
        large.push_back(pairs[i].first);
        small.push_back(pairs[i].second);
    }

    if ((right - left + 1) % 2 != 0)
        large.push_back(arr[right]);

    fj_sort(large, 0, large.size() - 1);

    std::deque<int> sortedArr = large;
    for (size_t i = 0; i < small.size(); i++) 
    {
        int x = small[i];
        std::deque<int>::iterator pos = std::lower_bound(sortedArr.begin(), sortedArr.end(), x);
        sortedArr.insert(pos, x);
    }
    for (size_t i = 0; i < sortedArr.size(); i++)
        arr[left + i] = sortedArr[i];
}

