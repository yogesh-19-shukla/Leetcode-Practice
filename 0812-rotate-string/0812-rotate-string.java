class Solution {
    public boolean rotateString(String s, String goal) {
        String rotated = s+s;
        if(s.length()!=goal.length())   return false;
        return rotated.contains(goal);
    }
}