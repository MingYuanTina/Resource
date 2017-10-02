# Question
  # Input: given 'Ride' class with metadata including: start/end date and Items
  # Ouput: design and implement 'ItemCounter' with requested functionalities

#### Assumption of Ride class ####
  # Start/End time, Items are considered as STRING (as not explicitly specified in descriptio)
  # Start_time, end_time, items are ATTRIBUTES of Ride class 
    # (Parsing could be varied based on different form of metadata implemented in Ride class)
  # Consistent format of Start/End times, Items
    # Date followed as "Hour:Minute" in 24 hours EST
    # Item followed as "# item_type_1, # item_type_2, # item_type_3 ..."
    # Item has no spelling errors 

#### Specification of Implementation ####
  # 1. LIST attribute stores an array of INTERVALS
  # 2. ItemCounter#process_ride parse new RIDE into LIST
  # 3. ItemCounter#print_items_per_interval prints all INTERVALS of LIST
  # 4. Each INTERVAL start-end time is SMALLEST overlap given all RIDES
  # 5. INTERVALS are sorted by start time
  # 6. INTERVAL items are sorted by TYPE etc. ["apple", "brwonie" ...]
  # 7. Each item follows plural/single as grammer rules

#### Time/Space Analysis ####
  # Assume N rides needs to processed, where each ride contains M items
  # Time Complexity: O((M * N^2)
    # Since new Ride needs to check with each Interval within List
    # And each validation operates M steps given the size of items is M
  # Space Complexity: O((M + 2) * N)
    # N Rides in total where each requires M space to store itesm and 2 to store time

#### Test Cases ####
  # Empty list
  # Small list with 1 or 2 Rides
  # Large list with the following
    # List of intervals that are all mutually exclusive
    # List of intervals that are fully cover with each other
    # List of intervals that are partially cover with each other 
    # List of intervals that are mix of mutually exclusive, full cover partially cover
  # Different items with the following
    # List of intervals where items are mutually exclusive
    # List of intervals where items are mixed exclusive and non-exclusive
    # List of intervals where items are mixed of single and multiples for each items
    # List of intervals where items are mixed of large item and small items

#!/usr/bin/env ruby
require 'time'

class Ride
  attr_accessor :start_time, :end_time, :items
  def initialize(start_time, end_time, items)
    @start_time = start_time
    @end_time = end_time
    @items = items
  end
end

# Interval holds SMALLEST overlap between all time interval
# Start/End are DATE
# Items are list of hash, where KEY is item and VALUE is # of items
class Interval
  attr_accessor :start, :endt, :items
  def initialize(start, endt, items)
    @start = start
    @endt = endt
    @items = items
  end
end

class ItemCounter
  private
  # Parse Ride item to a list of hash where KEY is item, VALUE is # of items
  def parse_items(items)
    hash = Hash.new
    items.split(',').each { |x| hash[x.split(' ')[1]] = x.split(' ')[0] }
    hash
  end
  
  # Increment items between two rides including new_list, old_list
  # Update the sum value to old_list if necessary
  def combine_items(new_list, old_list, if_origin)
    # Take singular form and sum it up
    list = Hash.new(0)
    list_final = Hash.new(0)
    new_list.map { |k,v| v.to_i > 1 ? list[k.chomp('s')] = v.to_i : list[k] = v.to_i }
    old_list.each do |k,v|
      v.to_i > 1 ? k = k.chomp('s') : nil 
      list[k] ? list[k] += v.to_i : list[k] = v.to_i
    end
    # Add plural if necessary
    list.map { |k,v| v > 1 ? list_final[k+'s'] = v.to_i : list_final[k] = v.to_i }
    if_origin ? old_list = list_final : list_final
  end
  
  public
  def initialize()
    @list = [] # list that holds list of INTERVAL
  end
  
  # Add_to_list refreshes LIST for each INTERVAL when an new RIDE is being processed
  # Update items of existing INTERVALs and create new INTERVAL if necessary
  def add_to_list(new_r)
    # Other Cases
    # For each INTERVAL in LIST, update items if necessary
    # 5 cases between two INTERVALs interactions
    # Case 1. A fully cover B
    # Case 2. B partically overlap A (end_item of B is between A)
    # Case 3. A partially overlap B (end_item of A is between B)
    # Case 4. B fully cover A 
    # Case 5. A, B are mutually exclusive --> do nothing 
    i = 0
    while @list[i]
      # Case 1
      if (new_r.start <= @list[i].start && new_r.endt >= @list[i].endt)
        @list[i].items = combine_items(new_r.items, @list[i].items, true)
      # Case 2
      elsif (new_r.endt > @list[i].start && new_r.endt < @list[i].endt)
        items_list = combine_items(new_r.items, @list[i].items, false)
        time_slot = Interval.new(@list[i].start, new_r.endt, items_list)
        @list[i].start = new_r.endt
        @list.insert(i, time_slot)
        i += 1
      # Case 3
      elsif (new_r.start > @list[i].start && new_r.start < @list[i].endt)
        items_list = combine_items(new_r.items, @list[i].items, false)
        time_slot = Interval.new(new_r.start, @list[i].endt, items_list)
        @list[i].endt = new_r.start
        @list.insert(i + 1, time_slot)
        i += 1
      # Case 4
      elsif (new_r.start > @list[i].start && new_r.endt < @list[i].endt)
        time_slot = Interval.new(new_r.endt, @list[i].endt, list[i].items)
        @list[i].endt = new_r.start
        items_list = combine_items(new_r.items, @list[i].items, false)
        @list.insert(i+1, Interval.new(new_r.start, new_r.endt, items_list))
        @list.insert(i+1, time_slot)
        i += 2
      end
      i += 1
    end
    
    # Edge Case
    # Check begin/end of LIST as new RIDE could be out of LIST boundary
    if (new_r.start < @list[0].start)
      @list.insert(0, Interval.new(new_r.start, @list[0].start, new_r.items))
    end
    if (new_r.endt > @list[@list.length-1].endt) 
      @list.insert(@list.length, Interval.new(@list[@list.length-1].endt, new_r.endt, new_r.items))
    end
    @list
  end
  
  # Processes a Ride object that contains metadata about the ride, including:
  # start time, end time, and bike basket items.
  def process_ride(ride)
    new_interval = Interval.new(Time.parse(ride.start_time), Time.parse(ride.end_time), parse_items(ride.items))
    if @list.empty? 
      @list.push(new_interval)
    else 
      @list = add_to_list(new_interval)
    end
  end

  # Prints a summary of the numbers of each type of item in transit during any
  # given time interval. Excludes time intervals during which no items were in
  # transit.
  def print_items_per_interval()
    @list.each do |l|
      line = l.start.strftime("%H:%M") + '-' + l.endt.strftime("%H:%M") + ' -> '
      l.items.sort.to_h.map { |k,v| line = line + v.to_s + ' ' + k.to_s + ', ' }
      puts line[0..line.length-3]
    end
  end
end


############################## Testing ##############################
# Give Test
Ride_1 = Ride.new("07:00", "07:30", "2 apples, 1 brownie")
Ride_2 = Ride.new("07:10", "08:00", "1 apple, 3 carrots")
Ride_3 = Ride.new("07:20","07:45", "1 apple, 2 brownies, 4 diamonds")

Item_list = ItemCounter.new
Item_list.process_ride(Ride_1)
Item_list.process_ride(Ride_2)
Item_list.process_ride(Ride_3)
Item_list.print_items_per_interval()

# Other Tests 
# Ride_4 = Ride.new("06:20","08:45", "1 apple, 1 avacado")
# Item_list.process_ride(Ride_4)
# Item_list.print_items_per_interval()

# Ride_5 = Ride.new("07:10","07:20", "3 apples, 1 brownie, 3 carrots")
# Item_list.process_ride(Ride_5)
# Item_list.print_items_per_interval()

# Ride_6 = Ride.new("07:10","07:15", "3 apples, 1 brownie, 3 carrots")
# Item_list.process_ride(Ride_6)
# Item_list.print_items_per_interval()

# Ride_7 = Ride.new("07:25", "07:35", "1 brownie, 1 mango")
# Item_list.process_ride(Ride_7)
# Item_list.print_items_per_interval()





