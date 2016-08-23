require "benchmark"
# converts a positive number n to a bit of position n
# for some binary number
def num_to_bitmap(n)
  2 ** (n - 1)
end

def bit_to_num(n)
  Math.log2(n).to_i
end

def gen_bitmap_from_seq(seq)
  seq.map { |m| num_to_bitmap m }.reduce(:|)
end

# BUG: loop terminates before it can get to the last n
def gen_seq_from_bitmap(m)
  i = 1
  seq = []

  loop do
    return seq if i > m.to_i(2)

    seq.push(bit_to_num(i)) if m.to_i(2) & i > 0 

    i = i << 1 
  end
end

test = (1..1000).to_a.sample(2700)

# generate the bitmap and print for verification
puts Benchmark.realtime { gen_bitmap_from_seq(test).to_s(2) }
puts Benchmark.realtime { test.sort }
bitmap = gen_bitmap_from_seq(test).to_s(2)
# generate the sequence back from the bitmap
puts Benchmark.realtime { seq = gen_seq_from_bitmap(bitmap) }
