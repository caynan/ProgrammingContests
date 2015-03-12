class Friends:
    def __init__(self, connections):
        self.connection = {}
        self.__add_connections(connections)


    def __add_connections(self, connections):
        for connection in connections:
            self.add(connection)


    def add(self, connection):
        p1, p2 = connection
        p1_friends = self.connection.setdefault(p1, set())
        p2_friends = self.connection.setdefault(p2, set())

        if p1 in p2_friends and p2 in p1_friends:
            return False
        else:
            p1_friends.add(p2)
            p2_friends.add(p1)
            return True


    def remove(self, connection):
        p1, p2 = connection

        if p1 in self.connection and p2 in self.connection:
            try:
                self.connection[p1].remove(p2)
                self.connection[p2].remove(p1)
                return True
            except KeyError:
                return False
        else:
            return False


    def names(self):
        c = self.connection
        return {x for x in c if c[x]}


    def connected(self, name):
        if name in self.connection:
            return self.connection[name]
        else:
            return set()  # empty set


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    letter_friends = Friends(({"a", "b"}, {"b", "c"}, {"c", "a"}, {"a", "c"}))
    digit_friends = Friends([{"1", "2"}, {"3", "1"}])
    assert letter_friends.add({"c", "d"}) is True, "Add"
    assert letter_friends.add({"c", "d"}) is False, "Add again"
    assert letter_friends.remove({"c", "d"}) is True, "Remove"
    assert digit_friends.remove({"c", "d"}) is False, "Remove non exists"
    assert letter_friends.names() == {"a", "b", "c"}, "Names"
    assert letter_friends.connected("d") == set(), "Non connected name"
    assert letter_friends.connected("a") == {"b", "c"}, "Connected name"
