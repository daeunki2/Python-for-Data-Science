# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    whatis.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 17:20:03 by daeunki2          #+#    #+#              #
#    Updated: 2026/09/20 17:33:18 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys


if len(sys.argv) > 2:
    print("AssertionError: more than one argument is provided")

elif len(sys.argv) == 2:
    try:
        number = int(sys.argv[1])

        if number % 2 == 0:
            print("I'm Even.")
        else:
            print("I'm Odd.")

    except ValueError:
        print("AssertionError: argument is not an integer")