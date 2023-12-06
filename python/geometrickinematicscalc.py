import math

def radToDegree(radians):
  return radians * (180/math.pi)

def degToRadian (degrees):
  return degrees * (math.pi / 180)

def forward(q1d,q2d,l1,l2):
  q1 = degToRadian(q1d)
  q2 = degToRadian(q2d)
  points = [l1 * math.cos(q1) + l2 * math.cos(q1 + q2), l1 * math.sin(q1) + l2 * math.sin(q1 + q2)]
  return points

def forward2(q1d, q2d, l1, l2, offset_q1):
    q1 = degToRadian(q1d) + degToRadian(offset_q1)
    q2 = degToRadian(q2d)
    points = [l1 * math.cos(q1) + l2 * math.cos(q1 + q2), l1 * math.sin(q1) + l2 * math.sin(q1 + q2)]
    return points


def inverse(x,y,l1,l2):
  r1 = math.sqrt(pow(x,2) + pow(y,2))
  m = (pow(r1,2) - pow(l1,2) - pow(l2,2)) / (2 * l1 * l2)
  b1 = math.atan2(y,x)
  m2 = (pow(r1,2) + pow(l1,2) - pow(l2,2)) / (2 * r1 * l1)
  angles = [radToDegree(b1 - math.acos(m2)), radToDegree(math.acos(m))]
  return angles

def inverse2(x, y, l1, l2, offset_q1):
    r1 = math.sqrt(pow(x, 2) + pow(y, 2))
    m = (pow(r1, 2) - pow(l1, 2) - pow(l2, 2)) / (2 * l1 * l2)
    b1 = math.atan2(y, x) + degToRadian(offset_q1)
    m2 = (pow(r1, 2) + pow(l1, 2) - pow(l2, 2)) / (2 * r1 * l1)
    angles = [radToDegree(b1 - math.acos(m2)), radToDegree(math.acos(m))]
    return angles


temp = forward(178,160,106,135)
print(temp[0])
print(temp[1])
temp = inverse(80,213,106,135)
print(temp[0])
print(temp[1])


{"shoulder_offset": 170.57635653800241, "elbow_offset": -165.8135947109648}