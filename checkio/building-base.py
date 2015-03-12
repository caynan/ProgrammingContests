class Building:
    def __init__(self, south, west, width_WE, width_NS, height=10):
        self.south = south
        self.west = west
        self.width_WE = width_WE
        self.width_NS = width_NS
        self.height = height
        self.corner = {}

    def corners(self):
        if self.corner:
            return self.corner
        else:
            self.__calculate_corner()
            return self.corner


    def __calculate_corner(self):
        # south-west
        self.corner['south-west'] = (self.south, self.west)
        # south-east
        self.corner['south-east'] = (self.south, self.west + self.width_WE)
        # north-west
        self.corner['north-west'] = (self.south + self.width_NS, self.west)
        # north-east
        self.corner['north-east'] = (self.south + self.width_NS,
                                     self.west + self.width_WE)

    def area(self):
        return self.width_WE * self.width_NS

    def volume(self):
        return self.area() * self.height

    def __repr__(self):
        return "Building(%s, %s, %s, %s, %s)" % (self.south, self.west,
                                                 self.width_WE, self.width_NS,
                                                 self.height)


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    def json_dict(d):
        return dict((k, list(v)) for k, v in d.items())

    b = Building(1, 2, 2, 3)
    b2 = Building(1, 2, 2, 3, 5)
    assert json_dict(b.corners()) == {'north-east': [4, 4], 'south-east': [1, 4],
                                      'south-west': [1, 2], 'north-west': [4, 2]}, "Corners"
    assert b.area() == 6, "Area"
    assert b.volume() == 60, "Volume"
    assert b2.volume() == 30, "Volume2"
    assert str(b) == "Building(1, 2, 2, 3, 10)", "String"
