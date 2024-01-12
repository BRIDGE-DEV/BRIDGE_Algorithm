namespace CLOCKSYNC
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var testCaseNumber = int.Parse(Console.ReadLine()!);

            for (int i = 0; i < testCaseNumber; i++)
            {
                var input = Console.ReadLine()!;

                var clocks = input.Split(' ').Select(int.Parse).ToArray();

                var clockSync = new ClockSync(clocks);

                Console.WriteLine(clockSync.Solve());
            }
        }
    }
}