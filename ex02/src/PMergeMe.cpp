/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:46 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:47 by bince            ###   ########.fr       */
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

void PMergeMe::merge_sort(std::vector<int>& arr,int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void PMergeMe::merge_sort(std::deque<int>& arr,int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void PMergeMe::merge(std::vector<int>&arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        rightArr[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < n1) 
        arr[k++] = leftArr[i++];
    while (j < n2) 
        arr[k++] = rightArr[j++];
}

void PMergeMe::merge(std::deque<int>&arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++) 
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++) 
        rightArr[j] = arr[mid + 1 + j];

    int i = 0; 
    int j = 0; 
    int k = left;

    while (i < n1 && j < n2) 
    {
        if (leftArr[i] <= rightArr[j]) arr[k++] = leftArr[i++];
        else arr[k++] = rightArr[j++];
    }

    while (i < n1) 
        arr[k++] = leftArr[i++];
    while (j < n2) 
        arr[k++] = rightArr[j++];
}
