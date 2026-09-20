# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Hello.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 14:09:06 by daeunki2          #+#    #+#              #
#    Updated: 2026/09/20 14:24:10 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Original data
ft_list  = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set   = {"Hello", "tutu!"}
ft_dict  = {"Hello": "titi!"}


# LIST
# A list is mutable, so its elements can be changed directly.
# List elements can be accessed by their index.
ft_list[1] = "World!"


# TUPLE
# A tuple is immutable, so its elements cannot be changed directly.
# Therefore, we create a new tuple and reassign it to ft_tuple.
ft_tuple = ("Hello", "France!")


# SET
# A set is mutable, but it has no index because its elements are unordered.
# Therefore, remove the old value and add the new value.
ft_set.remove("tutu!")
ft_set.add("Paris!")


# DICTIONARY
# A dictionary is mutable and stores data as key-value pairs.
# We can access the value using its key and change it directly.
ft_dict["Hello"] = "42paris!"


print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)