#! /usr/bin/env ruby

require 'gtk3'

app = Gtk::Application.new("org.gtk.example", :flags_none)

app.signal_connect "activate" do |application|
  window = Gtk::ApplicationWindow.new(application)
  window.set_title("Example Application")
  window.set_default_size(480, 320)

  button_box = Gtk::ButtonBox.new(:horizontal)
  window.add(button_box)

  button = Gtk::Button.new(label: "Say Hello", action: :destructive_action)
  button.signal_connect "clicked" do |widget|
    puts "Hellooo!!!"
    window.destroy
  end
  
  button_box.add(button)

  window.show_all
end

# puts app.run([$0] + ARGV)
puts app.run