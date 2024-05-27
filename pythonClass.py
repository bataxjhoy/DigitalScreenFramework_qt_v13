def test_func(a, b, c):
    return a + b + c

class pythonClass:
    def __init__(self, a=0, b=0):
        self.a = a
        self.b = b
        self.i = 0

    def test(self, c):
        self.i += 1
        return self.a + self.b + c + self.i
