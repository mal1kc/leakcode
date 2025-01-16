namespace ValidMountainArray
{
  class Program
  {

    static void Main(string[] args)
    {

      int[][] inputs = {
      [2, 1],
      [3, 5, 5],
      [0, 3, 2, 1],
    };

      bool[] results = { false, false, true };

      Solution sol = new Solution();

      for (int i = 0; i < inputs.Length; i++)
      {
        if (sol.ValidMountainArray(inputs[i]) != results[i])
        {
          throw new Exception(
              string.Format("a problem within solution at input {0}", i));
        }
      }

      Console.WriteLine("SUCCESS");
    }
  }
}
