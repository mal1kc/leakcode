namespace CheckIfnAndItsDoubleExist {
class Program {
  static void Main(string[] args) {
    int[][] inputs = {
[10,2,5,3],
[3,1,7,11],
    };

    bool[] results = { true, false};

    Solution sol = new Solution();

    for (int i = 0; i < inputs.Length; i++) {
      if (sol.CheckIfExist(inputs[i]) != results[i]) {
        throw new Exception(
            string.Format("a problem within solution at input {0}", i));
      }
    }

    Console.WriteLine("SUCCESS");
  }
}
}
