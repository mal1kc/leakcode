namespace EvalutaBooleanBinaryTree
{

  public class TreeNode
  {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
    {
      this.val = val;
      this.left = left;
      this.right = right;
    }
  }

  class Program
  {
    static void Main(string[] args)
    {
      // Construct the test cases
      TreeNode tree1 = new TreeNode(2, new TreeNode(0),
                                    new TreeNode(1)); // Represents: (0 OR 1)
      TreeNode tree2 = new TreeNode(0);               // Represents: false
      TreeNode tree3 = new TreeNode(3, new TreeNode(1),
                                    new TreeNode(1)); // Represents: (1 AND 1)

      List<TreeNode> inputTrees = new List<TreeNode> { tree1, tree2, tree3 };
      bool[] expectedResults = { true, false, true };

      Solution sol = new Solution();

      for (int i = 0; i < inputTrees.Count; i++)
      {
        bool result = sol.EvaluateTree(inputTrees[i]);
        if (result != expectedResults[i])
        {
          throw new Exception(
              $"A problem within solution at input {i}: expected {expectedResults[i]}, got {result}");
        }
      }

      Console.WriteLine("SUCCESS");
    }
  }
}
