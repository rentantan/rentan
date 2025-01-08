N = input("回数を入力してください")
n = int(N)
ans = 0
for i in range(n):
    line = "{:d}回目です".format(i+1)
    print(line)
    a = input("始めた時刻を入力してください")
    b = input("終わった時刻を入力してください")
    if len(a) == 4 and len(b) == 4:
        c = a[0]
        d = a[1]
        e = a[2]
        f = a[3]
        g = b[0]
        h = b[1]
        j = b[2]
        k = b[3]
        C = int(c)
        D = int(d)
        E = int(e)
        F = int(f)
        G = int(g)
        H = int(h)
        J = int(j)
        K = int(k)
        ans += (10*(G-C)+(H-D))*60 + (10*(J-E)+(K-F))
    else:
        print("エラー")
        exit()
x = ans // 60
y = ans % 60
line2 = "働いた総時間は{0:2d}時間{1:2d}分です".format(x,y)
print(line2)
z = x*1000 + y*1000//60
line3 = "今月の給料は{:d}円です".format(z)
print(line3)
input()
