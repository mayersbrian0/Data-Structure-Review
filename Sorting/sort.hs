
--merge sort
merge :: Ord a => [a] -> [a] -> [a]
merge [] xs = xs
merge xs [] = xs
merge (x:xs) (y:ys) | x < y = x : merge xs (y:ys)
                    | otherwise = y : merge (x:xs) ys

msort :: Ord a => [a] -> [a]
msort (x:[]) = [x]
msort xs = merge (msort (take n xs)) (msort (drop n xs))
            where
                n = length xs `div` 2
