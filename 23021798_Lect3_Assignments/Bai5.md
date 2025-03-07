class queue:
    int *arr
    int maxCapacity
    int top
    int size


    function InitializeStack(capacity):
        maxCapacity = capacity
        arr = new int[capacity]
        top = -1
        size = 0
    end

    function push(x):
        if top == maxCapacity - 1:
            return

        top = top + 1
        arr[top] = x
        size = size + 1
    end

    function pop():
        if top == -1:
            return

        top = top - 1
        size = size - 1
    end

    function print():
        if top == -1:
            return

        For i from 0 to top:
            Print arr[i]
    end
end

Nhận xét:
- Khởi tạo: O(1)
- Thêm phần tử: O(1)
- Xóa phần tử: O(1)
- In tất cả phần tử: O(n)