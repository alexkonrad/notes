import Data.List
numUniques :: (Eq a) => [a] -> Int
numUniques = length . nub
map' :: (a -> b) -> [a] -> [b]
map' f xs = foldr (\x acc -> f x : acc) [] xs
elem' :: (Eq a) => a -> [a] -> Bool
elem' y ys = foldl (\acc x -> if x == y then True else acc) False ys
sum' :: (Num a) => [a] -> a
sum' = foldl (+) 0
numLongChains :: Int
numLongChains = length (filter (\xs -> length xs > 15) (map chain[1..100]))
chain :: (Integral a) => a -> [a]
chain 1 = [1]
chain n
  | even n = n:chain (div n 2)
  | odd n  = n:chain (n*3 + 1)
multThree :: (Num a) => a -> a -> a -> a
multThree x y z = x * y * z
boomBangs xs = [ if x < 10 then "BOOM!" else "BANG!" | x <- xs, odd x]   
doubleMe x = x + x
doubleUs x y = x*2 + y*2
doubleSmallNumber x = if x > 100
			then x
			else x*2
doubleLargeNumber' x = (if x < 100 then x else x*2) + 1
length' xs = sum [1 | _ <- xs]
removeNonUppercase :: [Char] -> [Char]
removeNonUppercase st = [ c | c <- st, c `elem` ['A'..'Z']]
fizzBuzz x = [ y | y <- [1..x], y `mod` 3 == 0 || y `mod` 5 == 0 ]
addThree :: Int -> Int -> Int -> Int
addThree x y z = x + y + z
factorial :: (Integral a) => a -> a
factorial 0 = 1
factorial n = n * factorial (n - 1)
addVectors :: (Num a) => (a, a) -> (a, a) -> (a, a)
addVectors (x1, y1) (x2, y2) = (x1 + x2, y1 + y2) 
head' :: [a] -> a
head' [] = error "Empty list"
head' (x:_) = x

