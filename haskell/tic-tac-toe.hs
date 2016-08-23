data Player = X | O
data Square = Open | Taken Player
data Row = T | M | B
data Column = L | C | R

type Position = (Row, Column)
type Space = (Position, Square)
type Board = [Space]

over :: Board -> Bool
over = undefined

opponent :: Player -> Player
opponent = undefined

play :: Player -> Position -> Board -> Board
play = undefined

openSpace :: Row -> Column -> Space
openSpace r c = ((r, c), Open)

openBoard :: Board
openBoard = openSpace <$> [T, M, B] <*> [L, C, R]
