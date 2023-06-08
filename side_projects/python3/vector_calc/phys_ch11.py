import math
import vector_calc

g = -9.8

def prob07():
    F2T = 61.0
    F2 = 270.0
    L = 3.2
    d = 0.25

    # find center of rod
    center = L / 2.0

    # redefine axis
    T = 90.0 - F2T

    # torques must equal
    # t2 == t1 =====>
    F1 = (L-d)*F2 / L
    print(f"F1: {F1}")

    # mass of fish implies that the weight applies a torque equal to sum(all torque)
    g = 9.8
    theta = math.radians(T)
    tf = -(F1*math.cos(-theta)*0) + (F2*math.cos(theta)*d)
    mf = tf / (L*g*math.cos(-theta))
    print(f"Mass of Fish: {mf}")
    
def prob08():
    m1 = 15.0
    m2 = 35.0
    d  =  3.0

    # force from each child
    f1 = m1*g
    f2 = m2*g

    # summation of forces must equal 0, implying:
    Fn = -g*(m1 + m2)

    r1 = (m2*d) / (m2 + m1)
    print(f"r1 = {r1}")

def prob12():
    F = 320.0
    t = 0.19
    d = 0.24

    torque = F*d