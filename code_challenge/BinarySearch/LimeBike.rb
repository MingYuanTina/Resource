# Question Analysis
  # Input: given 'Ride' class with metadata including: start/end date and Items
  # Ouput: design and implement 'ItemCounter' with requested functionalities

# Runtime/Space Analysis

# Test Case 

# Implementation
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

class IntervalCounter
  attr_accessor :begin_t, :end_t, :items
  def initialize(begin_time, end_time, items)
    @begin_t = begin_time
    @end_t = end_time
    @items = items
  end
end

class ItemCounter
  private
  # parse list of items/ride into hash structure
  def parse_items(items)
    hash = Hash.new
    items.split(',').each { |x| hash[x.split(' ')[1]] = x.split(' ')[0] }
    hash
  end
  
  # Increment items between two rides (new_list, old_list)
  def increment_new_list(new_list, old_list, if_origin)
    list = Hash.new
    new_list.map { |k, v| v.to_i == 1 ? list[k+'s'] = v.to_i : list[k] = v.to_i }
    old_list.each do |k,v|
      if v.to_i == 1
        list[k+'s'] ?  list[k+'s'] += v.to_i : list[k] = v.to_i
      else
        list[k] = list[k] ? list[k] + v.to_i : v.to_i
      end
    end
    if_origin ? old_list = list : list
  end
  
  public
  def initialize()
    @list = [] # list that holds all time slots corresponds to items
  end
  
    # Refresht time slot when new ride is added
  def add_to_list(interval)
    # edge case 
    if (interval.begin_t < @list[0].begin_t)
      @list.insert(0, IntervalCounter.new(interval.begin_t, @list[0].begin_t, interval.items))
    end
    # other cases
    i = 0
    while @list[i]
      if (interval.begin_t < @list[i].begin_t && interval.end_t > @list[i].end_t)
        @list[i].items = increment_new_list(interval.items, @list[i].items, true)
        
      elsif (interval.end_t > @list[i].begin_t && interval.end_t < @list[i].end_t)
        items_list = increment_new_list(interval.items, @list[i].items, false)
        time_slot = IntervalCounter.new(@list[i].begin_t, interval.end_t, items_list)
        @list[i].begin_t = interval.end_t
        @list.insert(i, time_slot)
        
      elsif (interval.begin_t > @list[i].begin_t && interval.begin_t < @list[i].end_t)
        items_list = increment_new_list(interval.items, @list[i].items, false)
        time_slot = IntervalCounter.new(interval.begin_t, @list[i].end_t, items_list)
        @list[i].end_t = interval.begin_t
        @list.insert(i + 1, time_slot)
        
      elsif (interval.begin_t > @list[i].begin_t && interval.end_t < @list[i].end_t)
        time_slot = IntervalCounter.new(interval.end_t, @list[i].end_t, list[i].items)
        @list[i].end_t = interval.begin_t
        items_list = increment_new_list(interval.items, @list[i].items, false)
        @list.insert(i + 1, IntervalCounter.new(interval.begin_t, interval.end_t, items_list))
        @list.insert(i + 1, time_slot)
      end
      if (interval.end_t > @list[@list.length-1].end_t) 
        @list.insert(@list.length, IntervalCounter.new(@list[@list.length-1].end_t, interval.end_t, interval.items))
      end
      i += 1
    end
    @list
  end
  
  # This function process ride to array of hashes 
  def process_ride(ride)
    new_interval = IntervalCounter.new(Time.parse(ride.start_time), Time.parse(ride.end_time), parse_items(ride.items))
    @list.empty? ? @list.push(new_interval) : @list = add_to_list(new_interval)
  end
  
  def print_items_per_interval()
    @list.each do |l|
      line = l.begin_t.strftime("%H:%M") + '-' + l.end_t.strftime("%H:%M") + ' -> '
      l.items.sort.to_h.map { |k,v| line = line + v.to_s + ' ' + k.to_s + ', ' }
      puts line[0..line.length-3]
    end
  end
end

Ride_1 = Ride.new("07:00", "07:30", "2 apples, 1 brownie")
Ride_2 = Ride.new("07:10", "08:00", "1 apple, 3 carrots")
Ride_3 = Ride.new("07:20","07:45","1 apple, 1 brownie, 4 diamonds")

Item_list = ItemCounter.new
Item_list.process_ride(Ride_1)
Item_list.process_ride(Ride_2)
Item_list.process_ride(Ride_3)
Item_list.print_items_per_interval()
