class Solution {
    public boolean isAnagram(String s, String t) {
        s = s.toLowerCase();
        t = t.toLowerCase();
        int[] s1 = new int[s.length()];
        int[] s2 = new int[t.length()];

        for(int i=0;i<s1.length;i++)
        {
            s1[i] = s.charAt(i);
        }
        for(int i=0;i<s2.length;i++)
        {
            s2[i] = t.charAt(i);
        }

        Arrays.sort(s1);
        Arrays.sort(s2);

        return Arrays.equals(s1,s2);
    }
}
