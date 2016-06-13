class Song
  @@count = 0

  def initialize
    @@count += 1
  end

  def Song.get_count
    @@count
  end
end

p Song.get_count # => 0

10.times { Song.new }

p Song.get_count # => 9
