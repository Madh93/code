#! /usr/bin/env ruby

require 'open-uri'
require 'nokogiri'
require 'ruby-progressbar'

BASE_URL = URI.parse("http://pastebin.com/raw/1wtytNJN").read

module Debug
  def debug (str)
    puts str
  end
end

class Episode

  include Debug

  attr_reader :number, :title, :url

  def initialize(url)
    @url = url
    @html = open(@url).read

    info = Nokogiri.HTML(@html).search('span').to_s
    @number = info.split(":")[0].split(">")[1]
    @title = info.split("\"")[1]

    debug("Found #{@number}!")
  end

  def download
    debug("Downloading: #{@number} #{@title}...")

    # PROGRESS BAR
    # bar = ProgressBar.create(:format => '%a |%b>>%i| %p%% %t', :starting_at => 0)
    # 100.times do
    #   bar.increment
    #   sleep 0.1
    # end

    # File.open("out.mp4", "wb") do |saved_file|
    #   open("http://somedomain.net/flv/sample/sample.flv", "rb") do |read_file|
    #     saved_file.write(read_file.read)
    #   end
    # end
  end

end

class Season

  include Debug

  attr_reader :url

  def initialize(number)
    @number = number
    @url = "#{BASE_URL}simpsons-temporada-#{@number}.html"
    @html = open(@url).read
    @episodes = []
  end

  def to_s
    get_episodes if @episodes.empty?

    "+-+-+-+-+-+-+-+-+-+-+-+\n" <<
    "| Season: #{@number}\n" <<
    "| URL: #{@url}\n" <<
    "| Episodes: #{@episodes.size}\n" <<
    show_episodes <<
    "+-+-+-+-+-+-+-+-+-+-+-+"
  end

  private

  def get_episodes
    debug("Searching episodes for season #{@number}...")

    @html.each_line do |line| 
      if (line[/Audio Español/]) 
        url = Nokogiri.HTML(line).search('a').map { |a| a['href'] }
        @episodes.push(Episode.new(url.join))
      end
    end
  end

  def show_episodes
    episodes = ""

    @episodes.each do |e|
      episodes << "| \t #{e.number}: #{e.title}\n" 
    end

    episodes
  end

end

# Obtener datatos de la 4ª temporada
season = Season.new(4)
puts season