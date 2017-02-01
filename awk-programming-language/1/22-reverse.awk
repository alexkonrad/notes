# reverse - print input in reverse order line by line
{ line[NR] = $0 }
END {
  i = NR
  while (i > 0) {
    print line[i]
    i = i - 1
  }
}
