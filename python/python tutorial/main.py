mydict = {"name": "ddd",
          "age": 12,
          "city": "New York"}
value = mydict["age"]
mydict.popitem()
print(mydict)
if ("djj" in mydict):
    print(mydict["city"])
elif ("name" in mydict):
    print(mydict["name"])
for key in mydict:
    print(key)
mydict["email"] = "ddd@hj.com"
print(mydict)
