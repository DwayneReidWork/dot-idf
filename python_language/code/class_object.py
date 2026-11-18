class Car:
    def __init__(self, acceleration, top_speed, color):
        self.acceleration = acceleration
        self.top_speed    = top_speed
        self.color        = color
        self.running      = False
        self.speed        = 0

    def start(self):
        self.running = True

    def stop(self):
        self.running = False
        self.speed   = 0

    def update(self, time):
        if self.running:
            self.speed = self.speed + (self.acceleration * time)
            if self.speed > self.top_speed:
                self.speed = self.top_speed

car1 = Car(10, 200, "red")
car2 = Car(25, 120, "orange")
car3 = Car(15, 1000, "blue")

cars = [car1, car2, car3]

for car in cars:
    car.start()

for i in range(15):
    for car in cars:
        car.update(1)
        print(f"{car.color} car is going {car.speed} mph!")

    print()