//Add the two numbers and return the sum as a linked list.

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;

        carry = sum / 10;
    }
    return dummy.next;
}

struct ListNode* createList(int n) {
    struct ListNode *head = NULL, *temp = NULL, *newNode = NULL;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);

        newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
}

int main() {
    int n1, n2;
    
    printf("Enter number of nodes in first list: ");
    scanf("%d", &n1);
    
    printf("Enter elements of first list: ");
    struct ListNode* l1 = createList(n1);

    printf("Enter number of nodes in second list: ");
    scanf("%d", &n2);

    printf("Enter elements of second list: ");
    struct ListNode* l2 = createList(n2);

    struct ListNode* result = addTwoNumbers(l1, l2);

    printf("Sum list: ");
    printList(result);

    return 0;
}