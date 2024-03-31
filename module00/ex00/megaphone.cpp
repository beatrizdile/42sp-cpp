/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bedos-sa <bedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 21:05:08 by bedos-sa          #+#    #+#             */
/*   Updated: 2024/03/30 21:05:09 by bedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        for (int i=1; i < argc; i++)
        {
            for (int j=0; j < (int)strlen(argv[i]); j++)
            {
                if ((j == 0 || j == (int)strlen(argv[i]) - 1) && argv[i][j] == ' ')
                    continue;
                char upper_ch = static_cast<char>(toupper(argv[i][j]));
                std::cout << upper_ch;
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
}
