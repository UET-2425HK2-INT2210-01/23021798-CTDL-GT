Khởi tạo queue bằng mảng

class queue:
    int *arr
    int maxCapacity
    int front
    int rear
    int size


    function InitializeQueue(capacity):
        maxCapacity = capacity
        arr = new int[capacity]
        front = 0
        rear = -1
        size = 0
    end

    function push(x):
        If size = maxCapacity:
            return

        rear = (rear + 1) % maxCapacity
        queue[rear] = x
        size = size + 1
    end

    function pop():
        If size = 0:
            return

        front = (front + 1) % maxCapacity
        size = size - 1
    end

    function print():
        if size = 0:
            return

        index = front
        for i from 0 to size - 1:
            Print arr[index]
            index = (index + 1) % maxCapacity
    end
end

Nhận xét:
- Khởi tạo: O(1)
- Thêm phần tử: O(1)
- Xóa phần tử: O(1)
- In tất cả phần tử: O(n)
