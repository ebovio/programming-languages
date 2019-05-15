
doble :: Int -> Int
doble x = x + x

doble' :: Num a => a -> a

doble' y = y * 2

triple :: Int -> Int
triple' :: Num a => a -> a
triple y = y + y + y
triple' y = y * 3

nueve :: Num a => a
nueve = triple' 3

dobletriple :: Num a => a -> a
dobletriple x = triple'(doble' x)

dobletriple' :: Num a => a -> a
dobletriple' x = let y = doble' x in triple' y

tripledoble' :: Num a => a -> a
tripledoble' x = let y = triple' x in doble' y 