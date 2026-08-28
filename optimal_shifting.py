t=int(input())
while t>0:
    t-=1
    n=int(input())
    s=input()
    s=s+s
    count=0
    maxi=0
    for c in s:
        if c=='0':
            count+=1;
            maxi=max(maxi,count)
        else:
            count=0

    print(min(maxi,n))
