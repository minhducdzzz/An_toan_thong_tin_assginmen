#  Tìm nghịch đảo nhân trong GF(2¹⁰) bằng thuật toán Euclid mở rộng
## Sinh viên
* Họ và tên: Nguyễn Minh Đức
* MSSV: 20234001


## 1. Yêu cầu bài toán

Cài đặt chương trình tìm **nghịch đảo nhân** của một phần tử trong trường **GF(2¹⁰)**.

Cho:

* Đa thức tối giản:

[
m(x) = x^{10} + x^3 + 1
]

* Hai phần tử cần tìm nghịch đảo:

```
a = 523
b = 1015
```

Yêu cầu:

* Tính (a^{-1}) và (b^{-1}) trong GF(2¹⁰)
* In ra **các giá trị trung gian của thuật toán Euclid mở rộng** (r, q, v, w).

---

## 2. Lý thuyết

Trong trường **GF(2ⁿ)**, mỗi phần tử được biểu diễn dưới dạng **đa thức nhị phân**.

Ví dụ:

```
523 = 1000001011
```

tương ứng:

[
a(x) = x^9 + x^3 + x + 1
]

Các phép toán trong GF(2):

| Phép toán | Thực hiện        |
| --------- | ---------------- |
| Cộng      | XOR              |
| Trừ       | XOR              |
| Nhân      | Nhân đa thức     |
| Chia      | Chia đa thức     |
| Mod       | Lấy dư theo m(x) |

---

## 3. Thuật toán sử dụng

Sử dụng **Euclid mở rộng cho đa thức** để tìm:

[
r_i(x) = a(x)v_i(x) + b(x)w_i(x)
]

Khởi tạo:

| i  | r(x) | v(x) | w(x) |
| -- | ---- | ---- | ---- |
| -1 | a(x) | 1    | 0    |
| 0  | b(x) | 0    | 1    |

Lặp:

```
r_i = r_{i-2} mod r_{i-1}
q_i = thương của phép chia
v_i = v_{i-2} - q_i*v_{i-1}
w_i = w_{i-2} - q_i*w_{i-1}
```

Trong GF(2):

```
- = XOR
```

---

## 4. Cách giải bài toán

1. Biểu diễn số nguyên thành **đa thức nhị phân**.
2. Áp dụng **Euclid mở rộng cho đa thức** để tìm gcd.
3. Cập nhật các hệ số (v(x)) và (w(x)) sau mỗi bước.
4. Khi số dư bằng **1**, hệ số (w(x)) chính là **nghịch đảo của phần tử**.

---


## 6. Biên dịch và chạy

```
gcc main.c -o inverse
./inverse
```







