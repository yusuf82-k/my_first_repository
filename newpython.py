# A simple loop and conditional check
curr_limit = 6

for i in range(1, curr_limit + 1):
    # Conditional statement using the modulo operator (%)
    if i % 2 == 0:
        print(f"{i} is Even")
    else:
        print(f"{i} is Odd")