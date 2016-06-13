# Tests evaluation order of begin / end blocks
BEGIN {
  p "First"
}
BEGIN {
  p "Hello"
}
BEGIN {
  p "XYZ"
}
END {
  p "Alex"
}
END {
  p "Konrad"
}
END {
  p "world"
}
