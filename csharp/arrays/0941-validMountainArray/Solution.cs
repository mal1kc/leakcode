namespace ValidMountainArray
{

  public class Solution
  {
    public bool ValidMountainArray(int[] arr)
    {
      int len = arr.Count();
      if (len < 3)
        return false;

      bool increase = true;
      bool increased_once = false;

      for (int i = 1; i < len; i++)
      {
        int diff = arr[i] - arr[i - 1];
        if (diff == 0)
        {
          return false;
        }

        if (diff > 0)
        {
          increased_once = true;
        }

        if (diff < 0 && increase)
        {
          increase = !increase;
        }

        if (!increase && diff > 0)
        {
          return false;
        }
      }
      return (!increase && increased_once);
    }
  }

}
