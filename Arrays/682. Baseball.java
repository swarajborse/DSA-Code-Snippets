class Solution {
    public int calPoints(String[] operations) {
        Stack<Integer> st = new Stack<>();
        int sum = 0;
        for(int i=0;i<operations.length;i++)
        {
            String ch = operations[i];
            
            if(ch.equals("+"))
            {
                st.add(st.get(st.size()-1)+st.get(st.size()-2));
                sum+=st.peek();
            }
            else if(ch.equals("D"))
            {
                st.add(st.peek()*2);
                sum += st.peek();
            }
            else if(ch.equals("C"))
            {
                sum -= st.pop();
            }
            else
            {
            st.add(Integer.parseInt(ch));
            sum += st.peek();
            }
        }
        return sum;
    }
}
