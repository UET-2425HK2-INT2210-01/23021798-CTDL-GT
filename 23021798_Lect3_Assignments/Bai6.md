struct node:
    int data
    node * next
end

class stack:
    node * top = NULL
    size = 0

    function push(x):
        node * newnode = new node
        newnode.data = x
        newnode.next = top
        top = newnode
        size = size + 1
    end

    function pop():
        if top == NULL:
            return

        temp = top
        top = top.next
        delete temp
        size = size - 1
    end

    function print():
    if top == nULL:
        return

    Node * current = top
    While current ≠ NULL:
        Print current.data
        current = current.next
    end
end

Nhận xét:
- Khởi tạo: O(1)
- Thêm phần tử: O(1)
- Xóa phần tử: O(1)
- In tất cả phần tử: O(n)




