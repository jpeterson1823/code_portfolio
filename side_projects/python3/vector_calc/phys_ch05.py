import math

m1 = 9.6
m2 = 19.2
t = 42.5
g = 9.8

f1 = -m1*g*math.sin(math.radians(t))
f2 = m2*g

a = (f1+f2) / (m1 + m2)

print(a)