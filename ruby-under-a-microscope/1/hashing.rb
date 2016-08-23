require 'benchmark'

100.times do |size|
  hashes = []
  10000.times do
    hash = {}
    (1..size).each do
      hash[rand] = rand
    end
    hashes << hash
  end

  GC.disable

  Benchmark.bm do |bench|
    bench.report("adding element number #{size+1}") do
      10000.times do |n|
        hashes[n][size] = rand
      end
    end
  end

  GC.enable
end