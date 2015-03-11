from datetime import date


def days_diff(date1, date2):
    """
        Find absolute diff in days between dates
    """
    # Extract data
    year1, month1, day1 = date1
    year2, month2, day2 = date2

    # Create Date objects
    date1 = date(year1, month1, day1)
    date2 = date(year2, month2, day2)

    # Calculate difference
    delta = abs(date1 - date2)

    return delta.days


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert days_diff((1982, 4, 19), (1982, 4, 22)) == 3
    assert days_diff((2014, 1, 1), (2014, 8, 27)) == 238
    assert days_diff((2014, 8, 27), (2014, 1, 1)) == 238
