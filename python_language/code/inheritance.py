class my_class:
    def __init__(self):
        self.x = 10
        self.y = 10

    def print_values(self):
        print(f"x is {self.x}")
        print(f"y is {self.y}")

class my_child_class(my_class):
    def __init__(self):
        super().__init__()
        self.z = 10
        self.a = 10

    def print_values(self):
        super().print_values()
        print(f"z is {self.z}")
        print(f"a is {self.a}")

    def new_function_only_child_has(self):
        print("I am new!")

parent = my_class()
child  = my_child_class()

print("printing parent")
parent.print_values()
print()

print("printing child")
child.print_values()
child.new_function_only_child_has()
