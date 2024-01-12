namespace CLOCKSYNC
{
    public class ClockSync
    {
        private const int SwitchNumber = 10;
        private const int ClockNumber = 16;
        private const int Inf = 9999;

        private readonly string[] Linkend = new string[SwitchNumber]
        {
            "xxx.............",
            "...x...x.x.x....",
            "....x.....x...xx",
            "x...xxxx........",
            "......xxx.x.x...",
            "x.x...........xx",
            "...x..........xx",
            "....xx.x......xx",
            ".xxxxx..........",
            "...xxx...x...x.."
        };

        private readonly int[] _clocks;

        public ClockSync(int[] clocks)
        {
            _clocks = clocks;
        }

        public int Solve()
        {
            var ret = Solve(0);

            return ret >= Inf ? -1 : ret;
        }

        private bool AreAligned()
        {
            for (int i = 0; i < ClockNumber; i++)
            {
                if (_clocks[i] != 12)
                {
                    return false;
                }
            }

            return true;
        }

        private void Push(int switchNumber)
        {
            for (int clockNumber = 0; clockNumber < ClockNumber; clockNumber++)
            {
                if (Linkend[switchNumber][clockNumber] == 'x')
                {
                    _clocks[clockNumber] += 3;

                    if (_clocks[clockNumber] == 15)
                    {
                        _clocks[clockNumber] = 3;
                    }
                }
            }
        }

        private int Solve(int switchNumber)
        {
            if (switchNumber == SwitchNumber)
            {
                return AreAligned() ? 0 : Inf;
            }

            int ret = Inf;

            for (int count = 0; count < 4; count++)
            {
                ret = Math.Min(ret, count + Solve(switchNumber + 1));

                Push(switchNumber);
            }

            return ret;
        }
    }
}