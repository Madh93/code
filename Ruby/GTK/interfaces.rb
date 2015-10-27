#! /usr/bin/env ruby

require 'gtk3'

builder_file = "#{File.expand_path(File.dirname(__FILE__))}/interfaces.ui"

builder = Gtk::Builder.new(file: builder_file)

window = builder.get_object("window")
window.signal_connect("destroy") { Gtk.main_quit }

button = builder.get_object("button1")
button.signal_connect("clicked") { puts "Hello from Button 1" }

button = builder.get_object("button2")
button.signal_connect("clicked") { puts "Hello from Button 2" }

button = builder.get_object("quit")
button.signal_connect("clicked") { Gtk.main_quit }

Gtk.main