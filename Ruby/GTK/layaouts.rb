#! /usr/bin/env ruby

require 'gtk3'

app = Gtk::Application.new("org.gtk.example", :flags_none)

app.signal_connect "activate" do |application|
  window = Gtk::ApplicationWindow.new(application)
  window.set_title("Example Application")
  # window.set_default_size(480, 320)
  window.set_border_width(10)

  grid = Gtk::Grid.new
  window.add(grid)

  button = Gtk::Button.new(label: "Button 1")
  button.signal_connect("clicked") { puts "Hello from Button 1" }
  grid.attach(button, 0, 0, 1, 1)

  button = Gtk::Button.new(label: "Button 2")
  button.signal_connect("clicked") { puts "Hello from Button 2" }
  grid.attach(button, 1, 0, 1, 1)

  button = Gtk::Button.new(label: "Quit")
  button.signal_connect("clicked") { window.destroy }
  # grid cell (0,1)(col,row), 2 columns span, 1 row span
  grid.attach(button, 0, 1, 2, 1)

  window.show_all
end

# puts app.run([$0] + ARGV)
status = app.run

puts status