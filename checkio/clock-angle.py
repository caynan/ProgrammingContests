from math import fabs

def clock_angle(time):
    hour, minutes = time.split(':')
    hour = int(hour) % 12
    minutes = int(minutes)
    
    total = fabs(60 * hour - 11 * minutes) / 2
    
    return min(total, 360 - total)