void insertAtBottom(stack<int>& stk, int x){
	if(stk.empty()){
		stk.push(x);
		return;
	}

	int data = stk.top();
	stk.pop();
	insertAtBottom(stk,x);
	stk.push(data);
}

void reverseStack(stack<int>& stk){
	if(stk.empty()) return;

	int t = stk.top();
	stk.pop();
	reverseStack(stk);
	insertAtBottom(stk,t);
}
