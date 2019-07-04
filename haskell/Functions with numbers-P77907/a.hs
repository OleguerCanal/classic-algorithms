--absValue
absValue :: Int -> Int
absValue x = if x > 0 
                then x
                else -x

-- power
power :: Int -> Int -> Int
power x p = x^p

-- isPrime
hasDivisible :: Int -> [Int] -> Bool -- True if in list there is a divisor of x
hasDivisible x [] = False
hasDivisible x list = if x `mod` head list == 0
                    then True
                    else hasDivisible x (tail list)

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime x = hasDivisible x [2..(floor (sqrt x))]

-- isPrime n = primeCheck n $ floor $ sqrt $ (fromIntegral n :: Double)

-- slowFib 5
slowFib :: Int -> Int
slowFib 0 = 0
slowFib 1 = 1
slowFib n = slowFib (n-1) + slowFib (n-2)

-- quickFib 40