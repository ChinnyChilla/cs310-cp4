#!/bin/bash

# Specify the number of lines you want to generate
lines=1000000

# Specify the output file
output_file="./tests/test_register_actor.txt"

# Initialize n
n=1

# Use a while loop to generate the lines
while [ $n -le $lines ]
do
  echo "register_actor $n $n $n" >> $output_file
  n=$(( n + 1 ))
done

n=1

while [ $n -le $(expr $lines / 100) ]
do
  echo "remove_actor $n" >> $output_file
  n=$(( n + 1 ))
done

n=1
while [ $n -le $(expr $lines / 50) ]
do
  echo "register_actor $n $n $n" >> $output_file
  n=$(( n + 1 ))
done

n=$(expr $lines / 2)
praise_points=1
while [ $n -le $lines ]
do
  echo "praise_actor $n $praise_points" >> $output_file
  n=$(( n + 2 ))
  praise_points=$(( praise_points + 1 ))
done
n=$(expr $lines / 2)
while [ $n -le $lines ]
do
  echo "award_actor" >> $output_file
  n=$(( n + 2 ))
done

echo "show_actor" >> $output_file

echo "Script execution completed. The output has been written to $output_file."