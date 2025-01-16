namespace EvalutaBooleanBinaryTree
{
  public class Solution
  {
    public bool EvaluateTree(TreeNode root)
    {
      switch (root.val)
      {
        case 0:
          return false;
        case 2:
          return EvaluateTree(root.left) || EvaluateTree(root.right);
        case 3:
          return EvaluateTree(root.left) && EvaluateTree(root.right);
        default:
          return true;
      }
    }
  }
}
