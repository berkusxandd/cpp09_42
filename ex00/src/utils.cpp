/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bince <bince@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:53:31 by bince             #+#    #+#             */
/*   Updated: 2025/03/14 15:53:32 by bince            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <sstream>
#include <iostream>
float strtofloat(std::string str)
{
    float f_val;
    std::stringstream ss(str);
    
    ss >> f_val;
    if (!ss.fail())
        return f_val;
    else
    {
        std::cerr << "Error: cannot convert to float." << std::endl;
        return -1;
    }
}