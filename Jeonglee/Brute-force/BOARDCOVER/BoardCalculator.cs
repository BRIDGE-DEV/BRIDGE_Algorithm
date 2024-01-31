namespace BOARDCOVER
{
    public class BoardCalculator
    {
        private readonly Board _board;

        public BoardCalculator(Board board)
        {
            _board = board;
        }

        private (int y, int x) GetFirstBlock()
        {
            for (var i = 0; i < _board.Hight; i++)
            {
                for (var j = 0; j < _board.Width; j++)
                {
                    if (_board.IsBlock(i, j))
                    {
                        return (i, j);
                    }
                }
            }

            return (-1, -1);
        }

        public int GetCoverCount()
        {
            var (y, x) = GetFirstBlock();

            if (y == -1)
            {
                return 1;
            }

            var count = 0;

            for (var i = 0; i < 4; i++)
            {
                if (_board.CanSetBlock(x, y, i))
                {
                    _board.SetBlock(x, y, i);
                    count += GetCoverCount();
                    _board.RemoveBlock(x, y, i);
                }
            }

            return count;
        }
    }
}