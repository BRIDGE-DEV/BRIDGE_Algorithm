namespace BOARDCOVER
{
    public class Board
    {
        private static readonly int[,,] coverType = new int[4, 3, 2]
        {
            { { 0, 0 }, { 1, 0 }, { 0, 1 } },
            { { 0, 0 }, { 1, 0 }, { 1, 1 } },
            { { 0, 0 }, { 0, 1 }, { 1, 1 } },
            { { 0, 0 }, { 0, 1 }, { -1, 1 } }
        };

        public int Hight { get; }
        public int Width { get; }
        private readonly bool[,] _board;
        
        public Board(int hight, int width)
        {
            Hight = hight;
            Width = width;

            _board = new bool[Hight, Width];

            for (var i = 0; i < Hight; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    _board[i, j] = true;
                }
            }
        }

        public void SetBlock(int y, int x)
        {
            _board[y, x] = false;
        }

        public void SetBlock(int x, int y, int type)
        {
            for (var i = 0; i < 3; i++)
            {
                var nx = x + coverType[type, i, 0];
                var ny = y + coverType[type, i, 1];

               SetBlock(ny, nx);
            }
        }

        public bool IsBlock(int y, int x)
        {
            return _board[y, x];
        }

        public bool CanSetBlock(int x, int y, int type)
        {
            for (var i = 0; i < 3; i++)
            {
                var nx = x + coverType[type, i, 0];
                var ny = y + coverType[type, i, 1];

                if (nx < 0 || nx >= Width || ny < 0 || ny >= Hight)
                {
                    return false;
                }

                if (!IsBlock(ny, nx))
                {
                    return false;
                }
            }

            return true;
        }

        public void RemoveBlock(int x, int y, int type)
        {
            for (var i = 0; i < 3; i++)
            {
                var nx = x + coverType[type, i, 0];
                var ny = y + coverType[type, i, 1];

                _board[ny, nx] = true;
            }
        }

        public void Print()
        {
            for (var i = 0; i < Hight; i++)
            {
                for (var j = 0; j < Width; j++)
                {
                    System.Console.Write(_board[i, j] ? '.' : '#');
                }

                System.Console.WriteLine();
            }
        }
    }
}