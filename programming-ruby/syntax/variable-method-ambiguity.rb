# As Ruby parses a source file, it keeps track of sybols that have been
# assigned to. When it comes across a sybol that could be a variable or
# a method call, it checks to see whether it has seen a previous
# assigment to that symbol. If so, it treats it as a variable. Otherwise
# a method call (from Programming Ruby)

def a
  puts "Function 'a' called"
  99
end

for i in 1..2
  if i == 2
    puts "i==2, a=#{a}"
  else
    a = 1
    puts "i==1, a=#{a}"
  end
end
