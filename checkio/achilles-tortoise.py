def chase(a1_speed, t2_speed, advantage):
    """
    Sa1 = a1_speed * (t - advantage)
    St2 = t2_speed * t
    
    We want to know when Sa1 == St2, equating one equation to the other we have:
    a1_speed * (t - advantage) = t2_speed * t
    t / (t - advantage) = a1_speed / t2_speed
    
    we're going to attibute X = (a1_speed / t2_speed)
    
    t / (t - advantage) = X
    t = X * (t - advantage)
    t = X * t - X * advantage
    X * t - t - X * advantage = 0
    (X - 1) * t - X * advantage = 0
    t = (X * advantage) / (X - 1)
    
    So we have that t = ((a1_speed / t2_speed) * advantage) / ((a1_speed / t2_speed) - 1)
    """
    X = a1_speed / t2_speed
    t = (X * advantage) / (X - 1)
    
    return float('{:.8f}'.format(t))


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    def almost_equal(checked, correct, significant_digits):
        precision = 0.1 ** significant_digits
        return correct - precision < checked < correct + precision

    assert almost_equal(chase(6, 3, 2), 4, 8), "example"
    assert almost_equal(chase(10, 1, 10), 11.111111111, 8), "long number"

