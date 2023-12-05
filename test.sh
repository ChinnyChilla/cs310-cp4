#!/bin/bash

clear

rm ./tests/tests_output/*
mkdir ./tests/tests_output

# Specify the number of lines you want to generate
lines=1000

# Specify the output file
output_file="./tests/test_from_script.txt"
output_directory="./tests/tests_output"
original_directory="./tests/output_michael"

test_with_valgrind=1

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

n=1
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

echo "show_praise" >> $output_file

echo "quit" >> $output_file

echo "Test cast from script file created; placed in $output_file."

echo "making executable"

make clean
make

echo "Testing test cases"
if [ $test_with_valgrind -eq 1 ]
then
  	echo "testing with valgrind"
  	valgrind --leak-check=full -s ./bin/actor_db < ./tests/test_from_script.txt > $output_directory/output_test_from_script.txt
	valgrind --leak-check=full -s ./bin/actor_db < ./tests/test_award_actor_extra.txt > $output_directory/output_test_award_actor_extra.txt
	valgrind --leak-check=full -s ./bin/actor_db < ./tests/test_empty.txt > $output_directory/output_test_empty.txt
	valgrind --leak-check=full -s ./bin/actor_db < ./tests/test_remove_actor.txt > $output_directory/output_test_remove_actor.txt
else
	echo "testing without valgrind"
	./bin/actor_db < ./tests/test_from_script.txt > $output_directory/output_test_from_script.txt
	./bin/actor_db < ./tests/test_award_actor_extra.txt > $output_directory/output_test_award_actor_extra.txt
	./bin/actor_db < ./tests/test_empty.txt > $output_directory/output_test_empty.txt
	./bin/actor_db < ./tests/test_remove_actor.txt > $output_directory/output_test_remove_actor.txt
fi


echo "testing complete; comparing answers from $original_directory"

diff $output_directory/output_test_from_script.txt $original_directory/output_test_from_script.txt
diff $output_directory/output_test_award_actor_extra.txt $original_directory/output_test_award_actor_extra.txt
diff $output_directory/output_test_empty.txt $original_directory/output_test_empty.txt
diff $output_directory/output_test_remove_actor.txt $original_directory/output_test_remove_actor.txt

echo "test script done"
echo "haha loser go fix ur problems"