module Math

  class << self

    def to_degrees(angle)
      angle * (180 / PI);
    end

    def to_radians(angle)
      angle * (PI / 180);
    end
  end
end