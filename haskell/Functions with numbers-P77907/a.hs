--absValue
absValue :: Int -> Int
absValue x = if x > 0 
                then x
                else -x

-- power
power :: Int -> Int -> Int
power x p = x^p

-- isPrime
has_divisible :: Int -> [Int] -> bool -- True if in list there is a divisor of x
has_divisible x [] = False
has_divisible x list = if x mod head list
                    then True
                    else has_divisible x tail list

isPrime :: Int -> bool
isPrime x = has_divisible x [2..floor sqrt x]

-- slowFib 5
-- quickFib 40