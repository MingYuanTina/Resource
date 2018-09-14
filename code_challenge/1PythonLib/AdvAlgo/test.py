items = [1,2,3,4,5]
squared = map(lambda x: x**2, items)
print squared
squared = list(map(lambda x: x**2, items))
print squared