OUTER_CONST = 99

class Const
  def get_const
    CONST
  end

  CONST = OUTER_CONST + 1
end

p Const.new.get_const # => 100

p Const::CONST        # => 100

p ::OUTER_CONST       # => 99

Const::NEW_CONST = 123
