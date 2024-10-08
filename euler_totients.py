def totient(n):
    result = n
    p = 2
    while(p*p <= n+1):
       
        # check if p divides n. As it is a smallest divisor hence it must be prime.
        if n % p == 0:
           # Now, remove all parts of p from n.
           while n % p == 0:
               n /= p
           # multiply result with (1 - 1/p)
           result *= (1.0 - (1.0 / float(p)))
        p = p+1

    # if the modified n is still not 1, then it is the last factor of the original n.
    if (n > 1):
        result *= (1.0 - (1.0 /float(n)))

    return int(result)

# Feel free to change a.
a = 15
    
print("totient(",a,") = ", totient(a));
