s = int(input("Enter your age: "))
print(f"Your age is {s}")

if s >= 60:
    print("You are an elderly person")
elif s >= 40:
    print("You are an adult")
elif s >= 20:
    print("You are a youth")
else:
    print("You are a kid")
for i in range(1,11):
 print(i,end=" ")
print()