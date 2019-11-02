-- myLength
-- OBS:: Built in function: myLength list = length list
myLength :: [Int] -> Int
myLength [] = 0
myLength list = 1 + (myLength (tail list))