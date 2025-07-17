# mydict = {"name": "ddd",
#           "age": 12,
#           "city": "New York"}
# value = mydict["age"]
# mydict.popitem()
# print(mydict)
# if ("djj" in mydict):
#     print(mydict["city"])
# elif ("name" in mydict):
#     print(mydict["name"])
# for key in mydict:
#     print(key)
# mydict["email"] = "ddd@hj.com"
# print(mydict)


class Person:
    def __init__(self, name):
        self.name = name  # 这里的 self 指的是创建的 Person 实例本身

    def say_hello(self):
        print(f"Hello, my name is {self.name}")


p = Person("Alice")
p.say_hello()
# print(p)
