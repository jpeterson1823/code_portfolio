import math

SIG = 5
class vector:
    def __init__(self, i, j, k):
        self.v = [ i, j, k ]

    def __str__(self):
        return f"< {self.v[0]}i, {self.v[1]}j, {self.v[2]}k >"

    def add(self, v2):
        return [ round(self.v[0]+v2[0], SIG), round(self.v[1]+v2[1], SIG), round(self.v[2]+v2[2], SIG) ]

    def scale(self, n):
        return [ round(self.v[0]*n, SIG), round(self.v[1]*n, SIG), round(self.v[2]*n, SIG) ]

    def cross(self, v):
        i = round(self.v[1]*v[2] - self.v[2]*v[1], SIG)
        j = round(self.v[0]*v[2] - self.v[2]*v[0], SIG)
        k = round(self.v[0]*v[1] - self.v[1]*v[0], SIG)
        return [ i, -j, k ]

    def mag(self):
        return round(math.sqrt(pow(self.v[0], 2) + pow(self.v[1], 2) + pow(self.v[2], 2)), SIG)
