Khởi tạo queue dùng danh sách liên kết đơn

struct Node:
    int data
    Node * next
end

class Queue:
    Node * head = NULL
    size = 0

    function push(x):
        Node * newNode = New Node
        newNode.data = x
        newNode.next = NULL

        if head == NULL:
            head = newNode
        else:
            loop = head
            While loop.next ≠ NULL:
                loop = loop.next
            loop.next = newNode

        size = size + 1
    end

    function pop():
        if head ≠ NULL:
            Node* trash = head
            head = head.next
            Delete trash
            size = size - 1
    end

    function print():
        Node* loop = head
        while loop ≠ NULL:
            Print loop.data
            loop = loop.next
    end
end

Nhận xét:
- Khởi tạo: O(1)
- Thêm phần tử: O(n)
- Xóa phần tử: O(1)
- In tất cả phần tử: O(n)



