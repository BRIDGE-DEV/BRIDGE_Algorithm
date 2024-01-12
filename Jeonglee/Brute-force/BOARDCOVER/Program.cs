namespace BOARDCOVER
{
    class Program
    {
        static void Main(string[] args)
        {
            var testCaseNumber = int.Parse(Console.ReadLine()!);

            for (int i = 0; i < testCaseNumber; i++)
            {
                var input = Console.ReadLine()!.Split(' ');

                var hight = int.Parse(input[0]);
                var width = int.Parse(input[1]);

                var board = new Board(hight, width);

                for (var j = 0; j < hight; j++)
                {
                    var line = Console.ReadLine()!;

                    for (var k = 0; k < width; k++)
                    {
                        if (line[k] == '#')
                        {
                            board.SetBlock(j, k);
                        }
                    }
                }

                var calculator = new BoardCalculator(board);

                Console.WriteLine(calculator.GetCoverCount());
            }       
        }
    }
}