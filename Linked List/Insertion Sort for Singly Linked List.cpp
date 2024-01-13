/*
Ques: Insertion Sort for Singly Linked List
Link: https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
Medium
Company: Microsoft
Given a singly linked list, sort the list (in ascending order) using insertion sort algorithm.

Example 1:
Input:
N = 10
Linked List = 30->23->28->30->11->14->
              19->16->21->25 
Output : 
11 14 16 19 21 23 25 28 30 30 
Explanation :
The resultant linked list is sorted.

*/

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        struct Node* start = new Node(-1);
        start->next = head_ref;
        Node* curr = head_ref, *prev = start;
        
        while(curr){
            if(curr->next && (curr->next->data < curr->data)){
                //Insertion
                
                while(prev->next && prev->next->data<curr->next->data){
                    prev=prev->next;
                }
                
                Node* temp = prev->next;
                prev->next = curr->next;
                curr->next = curr->next->next;
                prev->next->next = temp;
                prev=start;
            }else{
                curr=curr->next;
            }
        }
        
        return start->next;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends
