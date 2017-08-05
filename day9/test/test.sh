#!/bin/bash

assert_equals () {
	eval expected="$1"
	eval actual="$2"
	if [ "${expected}" != "${actual}" ]
		then
			cat <<-END
			Assertion failed
			Expected: $expected
			Actual: $actual
			END
			return 0
		else
			printf "OK\n"
			return 1
	fi
}

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
MAIN="$DIR/../day9"

printf "TEST 1: "
expected=$'6\n6'
actual=$($MAIN < $DIR/test1)
assert_equals "\${expected}" "\${actual}"

printf "TEST 2: "
expected=$'7\n7'
actual=$($MAIN < $DIR/test2)
assert_equals "\${expected}" "\${actual}"

printf "TEST 3: "
expected=$'9\n9'
actual=$($MAIN < $DIR/test3)
assert_equals "\${expected}" "\${actual}"

printf "TEST 4: "
expected=$'11\n11'
actual=$($MAIN < $DIR/test4)
assert_equals "\${expected}" "\${actual}"

printf "TEST 5: "
expected=$'6\n3'
actual=$($MAIN < $DIR/test5)
assert_equals "\${expected}" "\${actual}"

printf "TEST 6: "
expected=$'18\n20'
actual=$($MAIN < $DIR/test6)
assert_equals "\${expected}" "\${actual}"

printf "TEST 7: "
expected=$'324\n241920'
actual=$($MAIN < $DIR/test7)
assert_equals "\${expected}" "\${actual}"

printf "TEST 8: "
expected=$'238\n445'
actual=$($MAIN < $DIR/test8)
assert_equals "\${expected}" "\${actual}"
