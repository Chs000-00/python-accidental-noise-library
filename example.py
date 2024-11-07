import pyanlib
print(dir(pyanlib))
print("pyanlib version: " + pyanlib.__version__)


for x in range(-10,10):
    print(pyanlib.quintic_blend(x), end="; ")

c = pyanlib.CCoordinate()
c.set(5, 5, 5)
print(c)