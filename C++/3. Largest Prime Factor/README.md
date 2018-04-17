# Largest prime factor
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?

---

well this one is hard... first, the term prime factors does't *tick* in my head, since I learn math using bahasa so the term is kinda different (IT IS different, I mean it is two different language)

First, I think the closest think that I think is make sense to be prime factor in Indonesia, and that is FPB or KPK... but both doesn't really match the example given...

And also, I remember the product of two prime number is always different (It is used for encryption I think)... I think the source is Ted-Ed video...

When I multiply 5*7*13*29 I got 13195, so 5, 7, 13, 29 are the factor for 13195... and also they're prime number... So prime factor is just that? Factors of a number that are prime number... IDK, but let's just use that

---

I think of using for-loop from 1 to n, where n is the number that we want to find the prime factor... since we know there are at least two factor of a number, 1 and the number itself... since 1 isn't prime, don't add it to X vector...

X vector is the list of accepted answer (Prime factor of n)

I will find if a number is the factor of n, by using module... if it is, then module should be 0. Then I will check if that number is a prime number using a function

---

Checking if a number is a prime number, well I'm new to C++ so I'm not quite sure how to make a function (Though I know JAVA, but it's been 5 months since the last time I use it, since the last time I program for android,, because my computer still broken :'( )

A PRIME NUMBER:
1. Have 2 factor, the number 1 and itself
2. ... nothing more really, as far as I can remember

I will implement prime checker function according to that rules, or rule..., who cares...

LET'S CODE!

---

well... while coding I realize that I can use the same logic to check if it is a prime... by using modulo :v ... if it has two factor... then IT IS a prime number

---

Wait... I can use ternary operator? YEAY!!!

...

Well I think my definition of prime factors is wrong... since using my definition, the prime factors of 13195 are 2,3,5,7,11,13 which is different from the example given

How about... find the smallest factor THAT IS PRIME, then using recursion, find the next smallest of factor of n divided by previous factor?... Already tried it in calculator... I think it would work

---

well... pointer, reference... it's weird... or at least, I yet to understand it, it took me way too long to find a way to use pointer(or was it reference)... somehow, I think I can solve this problem easier with other language... I think I intendedly make it hard for myself, just because I want to learn about pointer... and reference

---

I'm a bit annoyed by C++ not having hoisting (JavaScript), since I've been coding for JS for quite a while... I'm not sure, was Java have something similiar to Hoisting in JS?

Who care for now... anyway, Finally I finish it...

I made this example on April 17th 2018, the day I suppose to follow the warming up for INVENTION UNUD competition, but I warming up before warming up... simple right... wkwkwk

Why don't they allow C#, Java, Python or JS... the language that I already familiar with...

**type**: Challange
**source**: https://projecteuler.net/problem=3
**time**: April 17th 2018, 
**time spent**: About 2 hours(Minus ten minutes or more) ... damn it took way too long