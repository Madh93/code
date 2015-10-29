#! /usr/bin/env ruby

require 'gtk3'
require "fileutils"


# Load a resource file
# see here https://developer.gnome.org/gio/stable/GResource.html
current_path = File.expand_path(File.dirname(__FILE__))
gresource_bin = "#{current_path}/exampleapp.gresource"
gresource_xml = "#{current_path}/exampleapp.gresource.xml"

# Generate the resource file:
# see here https://developer.gnome.org/gio/stable/glib-compile-resources.html
system("glib-compile-resources",
       "--target", gresource_bin,
       "--sourcedir", File.dirname(gresource_xml),
       gresource_xml)

at_exit do
  FileUtils.rm_f(gresource_bin)
end

resource = Gio::Resource.load(gresource_bin)
Gio::Resources.register(resource)


class ExampleAppWindow < Gtk::ApplicationWindow
  type_register # Method inherited from GLib::Object

  class << self
    def init
      set_template(resource: "/org/gtk/exampleapp/window.ui")
      bind_template_child("stack")
    end
  end

  def initalize(application)
    super(application: application)
  end

  def open(file)
    basename = file.basename
    
    scrolled = Gtk::ScrolledWindow.new
    scrolled.show
    scrolled.set_hexpand(true)
    scrolled.set_vexpand(true)
    
    view = Gtk::TextView.new
    view.set_editable(false)
    view.set_cursor_visible(false)
    view_show

    scrolled.add(view)
    stack.add_title(scrolled, basename, basename)
    stream = file.read
    view.buffer.text = stream.read
  end
end

class ExampleApp < Gtk::Application
  def initialize
    super("org.gtk.exampleapp", :handles_open)

    signal_connect "startup" do |application|

      # Quit Button
      quit_accels = ["<Ctrl>Q"]
      action = Gio::SimpleAction.new("quit")
      action.signal_connect("activate") do |_action, parameter|
        application.quit
      end
      application.add_action(action)
      application.set_accels_for_action("app.quit", quit_accels)

      # Preferences Buttons
      action = Gio::SimpleAction.new("preferences")
      action.signal_connect("activate") do |_action, parameter|

      end
      application.add_action(action)

      # Load Menu UI
      builder = Gtk::Builder.new(:resource => "/org/gtk/exampleapp/app-menu.ui")
      app_menu = builder.get_object("appmenu")
      application.set_app_menu(app_menu)
    end    

    signal_connect "activate" do |application|
      window = ExampleAppWindow.new(application: application)
      window.present
    end
    signal_connect "open" do |application, files, hin|
      windows = application.windows
      win = nil
      unless windows.empty?
        win = windows.first
      else
        win = ExampleAppWindow.new(application)
      end

      files.each { |file| win.open(file) }

      win.present
    end
  end
end

app = ExampleApp.new


# puts app.run([$0] + ARGV)
puts app.run