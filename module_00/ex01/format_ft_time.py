# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    format_ft_time.py                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/20 14:24:57 by daeunki2          #+#    #+#              #
#    Updated: 2026/09/20 16:38:17 by daeunki2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
from datetime import datetime


# time.time() returns the number of seconds
# elapsed since January 1, 1970 (Unix timestamp).
seconds = time.time()


# datetime.now() returns the current local date and time
# as a datetime object.
date = datetime.now()


# f-string allows variables to be inserted inside a string.
#
# :,.4f
#   ,  -> adds a thousands separator
#   .4 -> displays 4 digits after the decimal point
#   f  -> fixed-point notation
#
# :.2e
#   .2 -> displays 2 digits after the decimal point
#   e  -> scientific notation
print(f"Seconds since January 1, 1970: "f"{seconds:,.4f} or {seconds:.2e} in scientific notation")


# strftime() converts a datetime object into a formatted string.
#
# %b -> abbreviated month name (Jan, Feb, Mar...)
# %d -> day of the month
# %Y -> four-digit year
print(date.strftime("%b %d %Y"))