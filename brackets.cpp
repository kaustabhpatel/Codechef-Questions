#include <iostream>
#include <string>

using namespace std;

struct node
{
    char c;
    int index;
    struct node* next = NULL;
} *top = NULL;

void push(char ch, int i)
{
    struct node* temp = new node;
    temp->c = ch;
    temp->index = i;
    
    if (top == NULL)
        temp->next = NULL;
    
    else
        temp->next = top;
    
    top = temp;
    
}

void pop()
{
    struct node* temp = new node;
    temp = top;
    top = top->next;
    delete temp;
}

void print() {
    struct node *temp = top;
    while(temp != NULL) {
        cout << temp->c << " ";
        temp = temp->next;
    }
    cout << "\n";
}

bool can_pop(char a, char b)
{
    if (a == ']' && b == '[')
        return true;
    else if (a == '}' && b == '{')
        return true;
    else if (a == ')' && b == '(')
        return true;
    return false;
}

int main()
{
    string S;
    cin>>S;
    for (int i = 0; i < S.size(); ++i)
    {
        if (S[i] == '[' || S[i] == '{' || S[i] == '(') {
            push(S[i], i);
        }
        else if (S[i] == ']' || S[i] == '}' || S[i] == ')')
        {
            if (top == NULL)
            {
                push(S[i], i);
                break;
            }
            else
            {
                if (can_pop(S[i], top->c))
                    pop();
                else
                {
                    push(S[i], i);
                    break;
                }
            }
        }
    }
    if (top == NULL)
        cout<<"Success";
    else
        cout<<(top->index) + 1;
}
