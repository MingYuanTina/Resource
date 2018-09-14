class View(object):
	def __init__(self, problem_name, problem_description, type_description):
		self.problem_name = problem_name
		self.problem_description = problem_description
		self.type_description = type_description

	def print_format_layer(self):
		print "****************************************"
	def print_problem_name(self):
		print "PROBLEM NAME:  ", self.problem_name

	def print_problem_description(self):
		print "DESCRIPTION:   ", self.problem_description

	def print_type_description(self):
		print "TYPE:          ", self.type_description

	def print_description(self):
		self.print_problem_name()
		self.print_problem_description()
		self.print_type_description()

	def print_example_input(self, example_input):
		print "EXAMPLE INPUT: ", example_input

	def print_example_output(self, example_output):
		print "EXAMPLE OUTPUT:", example_output

	def run_view(self, user_function, *args):
		self.print_description()
		self.print_example_input(args)
		res = user_function(*args)
		self.print_example_output(res)







