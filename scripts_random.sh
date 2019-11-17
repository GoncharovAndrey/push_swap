# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    scripts_random.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjosue <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 19:20:31 by cjosue            #+#    #+#              #
#    Updated: 2019/11/15 19:20:33 by cjosue           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#!/bin/bash

MAXCOUNT=500
RANGE=1000
count=1

while [ "$count" -le $MAXCOUNT ]
do
  number=$RANDOM
  let "number %= $RANGE"
  echo -n $number ' '
  let "count += 1"
done