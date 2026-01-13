class car:
    def __init__(self):
        pass

class car_with_gas_engine(car):
    def __init__(self):
        pass

    def drive(self):
        # drive with gas

class car_with_electric_engine(car):
    def __init__(self):
        pass

    def drive(self):
        # drive with electrons


class car:
    def __init__(self, engine, four_wheel_drive):
        self.engine = engine
        self.four_wheel_drive = four_wheel_drive

    def drive(self):
        self.engine.drive()

class my_custom_engine:
    def __init__(self, ...):
        # set engine properties

    def drive(self):
        # drive custom

class car:
    def __init__(self, engine, four_wheel_drive):
        self.engine = engine
        self.four_wheel_drive = four_wheel_drive

    def drive(self):
        self.engine.drive()

