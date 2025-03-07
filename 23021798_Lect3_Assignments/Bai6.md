struct node:
    int data
    node * next
end

class stack:
    node * top = NULL
    size = 0

    function push(x):
        Node* newNode = new Node
        newNode.data = x
        newNode.next = NULL

        if top == NULL: top = newNode
        else:
            Node* loop = top
            while loop.next != NULL: loop = loop.next

            loop.next = newNode
        
        size++
    end

    function pop():
        if top == NULL
            return

        Node* loop = top;
        for i from 1 to size - 2
            loop =  loop.next
        
        Node* trash = loop.next
        loop.next = NULL
        delete trash
        size--
    end

    function print():
    if top == NULL:
        return

    Node * current = top
    While current ≠ NULL:
        Print current.data
        current = current.next
    end
end

Nhận xét:
- Khởi tạo: O(1)
- Thêm phần tử: O(n)
- Xóa phần tử: O(n)
- In tất cả phần tử: O(n)




