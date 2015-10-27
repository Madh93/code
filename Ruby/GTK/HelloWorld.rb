#! /usr/bin/env ruby

require 'gtk3'

class HelloWorld < Gtk::Window

  def initialize
    super("Ventana de Hola Mundo")

    set_default_size 480, 320
    set_window_position Gtk::WindowPosition::CENTER

    signal_connect "destroy" do
      Gtk.main_quit
    end

    show
  end
end

window = HelloWorld.new
Gtk.main