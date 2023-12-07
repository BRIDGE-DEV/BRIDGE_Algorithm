namespace BOGGLE
{
    public class Board
    {
        private readonly char[,] _board;
        private readonly int _size;
        private readonly int[] _dx = {-1, -1, -1, 1, 1, 1, 0, 0};
        private readonly int[] _dy = {-1, 0, 1, -1, 0, 1, -1, 1};

        public Board(int size)
        {
            _size = size;
            _board = new char[size, size];
        }

        public void SetBoard(string[] board)
        {
            for (int i = 0; i < _size; i++)
            {
                var line = board[i];
                for (int j = 0; j < _size; j++)
                {
                    _board[i, j] = line[j];
                }
            }
        }

        public bool HasWord(int y, int x, string word)
        {
            if (!InRange(y, x))
                return false;
            if (_board[y, x] != word[0])
                return false;
            if (word.Length == 1)
                return true;
            for (int direction = 0; direction < 8; direction++)
            {
                int nextY = y + _dy[direction];
                int nextX = x + _dx[direction];

                if (HasWord(nextY, nextX, word[1..]))
                {
                    return true;
                }
            }
            return false;
        }

        public bool HasWord(string word)
        {
            for (int y = 0; y < _size; y++)
            {
                for (int x = 0; x < _size; x++)
                {
                    if (HasWord(y, x, word))
                    {
                        return true;
                    }
                }
            }

            return false;
        }

        private bool InRange(int y, int x)
        {
            return x >= 0 && x < _size && y >= 0 && y < _size;
        }
    }
    
    public class Program
    {
        public static void Main(string[] args)
        {
            var testCaseNumber = int.Parse(Console.ReadLine()!);

            for (int i = 0; i < testCaseNumber; i++)
            {
                var boardSize = 5;
                var board = new string[boardSize];
                for (int j = 0; j < boardSize; j++)
                {
                    board[j] = Console.ReadLine()!;
                }
                
                var boardObj = new Board(boardSize);
                boardObj.SetBoard(board);

                var wordNumber = int.Parse(Console.ReadLine()!);

                for (int j = 0; j < wordNumber; j++)
                {
                    var word = Console.ReadLine()!;
                    //Console.WriteLine($"{word} {boardObj.HasWord(1, 1, word)}");
                    Console.WriteLine($"{word} {boardObj.HasWord(word)}");
                }
            }
        }
    }
}