import sys

def main():
    input = sys.stdin.read
    data = input().split()
    if not data:
        return
    
    t = int(data[0])
    idx = 1
    
    for _ in range(t):
        n = int(data[idx])
        s = data[idx + 1]
        idx += 2
        
        # If the string has no '1's, maximum consecutive '0's is capped at n
        if '1' not in s:
            print(n)
            continue
            
        s += s
        count = 0
        maxi = 0
        
        for c in s:
            if c == '0':
                count += 1
                maxi = max(maxi, count)
            else:
                count = 0
                
        print(maxi)

if __name__ == '__main__':
    main()
