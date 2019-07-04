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
isPrime x = not $ hasDivisible x [2..(floor (sqrt (fromIntegral x :: Double)))]

-- slowFib
-- OBS: THIS IS EXPONENTIALLY SLOW
slowFib :: Int -> Int
slowFib 0 = 0
slowFib 1 = 1
slowFib n = slowFib (n-1) + slowFib (n-2)

-- quickFib
-- Idea: fib = [1, 1, fibs +(element-wise) (tail fibs)]. ie:
--    [ 1, 1, 2, 3,  5, .... ]
-- +  [ 1, 2, 3, 5,  8, .... ]
-- =  [ 2, 3, 5, 8, 13, .... ]
-- OBS: This solution O(n^2)
fibs = 0 : 1 : zipWith (+) fibs (tail fibs)  -- Compute list of all fibs
quickFib :: Int -> Int
quickFib n = fibs !! n -- Get nth elem