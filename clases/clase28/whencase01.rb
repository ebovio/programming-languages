#!/usr/bin/ruby

def verificarTipo(valor)
  case valor
  when 10
    puts "Es un diez"
  when "Hola"
    puts "Hola"
  when true
    puts "Verdadero"
  end
end

