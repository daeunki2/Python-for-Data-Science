# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_ft_type.py                                    :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 16:39:12 by daeunki2          #+#    #+#              #
#    Updated: 2026/09/20 16:52:43 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

def all_thing_is_obj(object: any) -> int:

	if type(object) == list:
		print(f"List : {type(object)}")
	elif type(object) == tuple:
		print(f"Tuple : {type(object)}")
	elif type(object) == set:
		print(f"Set : {type(object)}")
	elif type(object) == dict:
		print(f"Dict : {type(object)}")
	elif type(object) == str:
		print(f"{object} is in the kitchen : {type(object)}")
	else:
		print("Type not found")
	return 42