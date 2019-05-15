#!/usr/bin/ruby

def leerEntrada
  c = gets.chomp.to_i

  unless c >= 0
    puts "Error en la entrada"
  end
end
