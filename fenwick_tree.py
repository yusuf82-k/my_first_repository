class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * (n + 1)

    # Add value to A[index]
    def update(self, index, value):
        while index <= self.n:
            self.bit[index] += value
            index += index & (-index)

    # Sum of A[1] + A[2] + ... + A[index]
    def query(self, index):
        total = 0

        while index > 0:
            total += self.bit[index]
            index -= index & (-index)

        return total


n = 30

ft = FenwickTree(n)

# A = [1, 2, 3, ..., 30]
for i in range(1, n + 1):
    ft.update(i, i)

# Sum of first 10 elements
print("Sum of first 10 elements =", ft.query(10))