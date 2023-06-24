#include "monty.h"

# Read the two digits from stdin
digit1 = int(input("Enter the first digit: "))
digit2 = int(input("Enter the second digit: "))

# Multiply the two digits
result = digit1 * digit2

# If the result is greater than 9, reduce it to one digit
while result > 9:
    result = (result // 10) * (result % 10)

# Print the result
print("The result is: {}".format(result))
