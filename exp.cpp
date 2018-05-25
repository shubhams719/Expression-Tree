#include<iostream>
#include<stack>
#include<string.h>
struct Node
{
	char c;
	Node *left,*right;
};

bool IsOperator(char c)
{
	if(c == '+' || c == '-' || c == '/' || c == '*')
		return true;
	else
		return false;
}

Node* newNode(char c)
{
	Node* temp = new Node();
	temp->c = c;
	temp->left = temp->right = NULL;
	return temp;
}

Node* construct(char* c)
{
	std::stack<Node*> s;
	Node *t, *t1,*t2;
	for(int i = 0;i < strlen(c); i++)
	{
		if(!IsOperator(c[i]))
		{
			t = newNode(c[i]);
			s.push(t);
		}
		else
		{
			t = newNode(c[i]);
			t1 = s.top();
			s.pop();
			t2 = s.top();
			s.pop();
			t->right = t1;
			t->left = t2;
			s.push(t);
		}
	}

	t = s.top();
	s.pop();
	return t;
}

void InOrder(Node* root)
{
	if(!root)
		return;
	InOrder(root->left);
	std::cout << root->c << " ";
	InOrder(root->right);
}

int main()
{
    char postfix[] = "ab+ef*g*-";
    Node* r = construct(postfix);
    printf("infix expression is \n");
    InOrder(r);
    return 0;
}

			

