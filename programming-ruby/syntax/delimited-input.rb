# single-quoted string
p %q{\a and #{1+2} are literal}

# double-quoted string
p %Q{\a and #{1+2} are expanded}

# array of strings
p %w[one two three]

# array of symbols
p %i[one two three]

# regular expression pattern
p %r{cat|dog}

# a symbol
p %s{a symbol}

# shell command
p %x(df -h)
