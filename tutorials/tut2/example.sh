#!/bin/bash

func(){
	# prints out the first two arguments to func
	echo "func has parameters $1 $2"
	var=apple
}

echo "script has parameters $@"
func
func foo
func foo bar

# prints out apple
echo "var stores $var"
