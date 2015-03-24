from datetime import date


def checkio(from_date, to_date):
    from_date, to_date = from_date.toordinal(), to_date.toordinal()

    return [date.fromordinal(x).weekday() in (5,6) for x in range(from_date, to_date+1)].count(True)

