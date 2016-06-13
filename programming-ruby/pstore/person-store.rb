require 'pstore'

class Person
  CONST = 99

  def initialize(options)
    @first_name = options[:first_name]
    @last_name = options[:last_name]

    @filename = "#{@first_name.downcase}-#{@last_name.downcase}.dat"
    @store = PStore.new(@filename)
  end

  def save
    @store.transaction do 
      @store[:first_name] = @first_name
      @store[:last_name] = @last_name
    end
  end

  def self.create_from_store(filename)
    store = PStore.new(filename)

    store.transaction(true) do |root|
      Person.new(root)
    end
  end
end

Person.new(first_name: "John", last_name: "Smith").save

Person.create_from_store("john-smith.dat")
