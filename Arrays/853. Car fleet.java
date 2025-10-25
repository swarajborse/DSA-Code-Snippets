
class Solution {
    public int carFleet(int target, int[] position, int[] speed) {
        
        int[][] cars = new int[position.length][2];

        for(int i=0;i<position.length;i++)
        {
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }

        Arrays.sort(cars ,(a,b) -> b[0]-a[0]);

        Stack<Double> st = new Stack<>();

        for(int i=0;i<position.length;i++)
        {
            double time = ((double)target - cars[i][0]) / cars[i][1];

            if(st.isEmpty())
            st.push(time);

            else
            {
                if(time <= st.peek())
                continue;

                else
                st.push(time);
            }
        }
        return st.size();
    }
}
