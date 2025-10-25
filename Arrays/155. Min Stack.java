class MinStack {

    Stack<Integer> st = new Stack<>();
    Stack<Integer> minst = new Stack<>();
    public MinStack() {
        
    }
    
    public void push(int val) {
        
        st.push(val);

        if(minst.isEmpty() || val <= minst.peek())
        {
            minst.push(val);
        }
    }
    
    public void pop() {
        int remove = st.pop();

        if(remove == minst.peek())
        {
            minst.pop();
        }
    }
    
    public int top() {
        return st.peek();
    }
    
    public int getMin() {
        return minst.peek();
    }
}
