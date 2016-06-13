#! /usr/bin/env ruby

# NAME          : Volafile Downloader
# DESCRIPTION   : Download all files from Volafile room
# AUTHOR        : Madh93 (Miguel Hernandez)
# VERSION       : 0.0.1
# LICENSE       : GNU General Public License v3
# USAGE         : ruby volafile.rb

require 'rubygems'
require 'selenium-webdriver'

# Volafile
module Volafile
  PATH = '/home/username/volafile' # CHANGE
  WEB_DRIVER = :chrome # :firefox, :ie
  ROOMS = [ # CHANGE
    'https://volafile.io/r/sdfh78df7hdfs',
    'https://volafile.io/r/8d7fhsd8f7hsd'
  ]

  def self.find_links(room)
    Utils.logger("Opening #{room}...")
    driver = Selenium::WebDriver.for Volafile::WEB_DRIVER
    driver.manage.timeouts.implicit_wait = 30 # seconds
    driver.navigate.to(room)
    files = driver.find_elements(class: 'file_name').map do |e|
      e.attribute('href')
    end
    driver.quit
    Utils.get_links(files)
  end

  def self.dump
    Utils.check_dir("#{PATH}/downloads")
    Utils.check_dir("#{PATH}/downloads/#{Date.today}")
    path = "#{PATH}/downloads/#{Date.today}/"
    Utils.logger("Begin to download files in #{path}")

    File.readlines("#{PATH}/links/links_#{Date.today}.txt").each do |link|
      if !File.exist?("#{path}#{File.basename(link.strip)}")
        begin
          Utils.logger("Downloading... #{path}#{File.basename(link.strip)}")
          `wget "#{link}" -O "#{path}#{File.basename(link.strip)}"`
          Utils.logger("Downloaded #{path}#{File.basename(link.strip)}")
        rescue
          Utils.logger("Problems downloading #{path}#{File.basename(link.strip)}")
        end
      end
    end

    Utils.logger("Terminated downloads in #{path}")
  end
end

# Utils
module Utils
  def self.check_dir(dir)
    Dir.mkdir(dir) unless File.exist?(dir)
  end

  def self.get_links(links)
    Utils.logger('Get links...')
    check_dir("#{Volafile::PATH}/links")
    File.open("#{Volafile::PATH}/links/links_#{Date.today}.txt", 'w+') do |f|
      links.each do |link|
        f.puts link
      end
    end
    Utils.logger("Links in #{Volafile::PATH}/links/links_#{Date.today}.txt")
  end

  def self.logger(text)
    File.open("#{Volafile::PATH}/volafile.log", 'a') do |f|
      f.puts "#{Time.now}: #{text}"
    end
  end
end

# Search available links in rooms
Volafile::ROOMS.each do |room|
  Volafile.find_links(room)
end

# Download all found files
Volafile.dump
