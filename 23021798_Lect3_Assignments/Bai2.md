Tính toán 2^n

cách 1:

function solve(n):
    if n >= 0:
        return (1 << n);
    else
        return (1 << -n);

Nhận xét: Độ phức tạp O(1)

Cách 2:

function solve(n):
    int i = 1
    int solve = 1
    bool negative = false

    if n < 0:
        n = -n
        negative = true
    
    while i <= n:
        solve = solve * 2
        i++


    if negative return 1 / solve
    else return solve

Nhận xét: Độ phức tạp O(n)


    
    