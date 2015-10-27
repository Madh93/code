#! /usr/bin/env ruby

require 'gtk3'

app = Gtk::Application.new("org.gtk.example", :flags_none)

app.signal_connect "activate" do |application|
  window = Gtk::ApplicationWindow.new(application)
  window.set_title("Example Application")
  window.set_default_size(480, 320)
  window.show_all
end

puts app.run