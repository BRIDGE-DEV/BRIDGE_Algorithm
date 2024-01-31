namespace Picnic
{
    class PicnicPairLogic
    {        private readonly int _studentNumber;
        private readonly int _pairNumber;
        private List<(int, int)> _values;
        public PicnicPairLogic(int studentNumber, int pairNumber)
        {
            _studentNumber = studentNumber;
            _pairNumber = pairNumber;

            _values = new List<(int, int)>();
        }

        public int Solved()
        {
            var input = Console.ReadLine()!.Split(' ');

            for (int i = 0; i < _pairNumber; i++)
            {
                var first = int.Parse(input[i * 2]);
                var second = int.Parse(input[i * 2 + 1]);

                _values.Add((first, second));
            }

            var result = CountPair(0, new bool[_studentNumber]);

            return result;
        }

        private int CountPair(int index, bool[] isPair)
        {
            if (index == _studentNumber)
            {
                return 1;
            }

            if (isPair[index])
            {
                return CountPair(index + 1, isPair);
            }

            var result = 0;
            for (int i = index + 1; i < _studentNumber; i++)
            {
                if (isPair[i])
                {
                    continue;
                }

                if (_values.Contains((index, i)) || _values.Contains((i, index)))
                {
                    isPair[index] = isPair[i] = true;
                    result += CountPair(index + 1, isPair);
                    isPair[index] = isPair[i] = false;
                }
            }

            return result;
        }    
    }

    class Program
    {
        static void Main(string[] args)
        {
            var testCaseNumber = int.Parse(Console.ReadLine()!);

            for (int i = 0; i < testCaseNumber; i++)
            {
                var input = Console.ReadLine()!.Split(' ');
                
                var studentNumber = int.Parse(input[0]);
                var friendPairNumber = int.Parse(input[1]);

                var logic = new PicnicPairLogic(studentNumber, friendPairNumber);
                System.Console.WriteLine(logic.Solved());
            }
        }
    }
}