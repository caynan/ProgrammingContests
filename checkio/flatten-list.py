flat_list = lambda a: [y for x in a for y in (flat_list(x) if isinstance(x, list) else [x])]
