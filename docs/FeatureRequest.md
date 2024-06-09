# Requirement Features

<details>
<summary>Mục lục</summary>

- [Requirement Features](#requirement-features)
  - [1. Cho người dùng nhập danh sách sinh viên bằng cách import file excel DSSV.xlsx gồm các nội dung như sau](#1-cho-người-dùng-nhập-danh-sách-sinh-viên-bằng-cách-import-file-excel-dssvxlsx-gồm-các-nội-dung-như-sau)
  - [2. Cho người dùng chọn cách thức lưu trữ danh sách trên bằng mảng, danh sách liên kết đơn, danh sách liên kết vòng, danh sách liên kết kép](#2-cho-người-dùng-chọn-cách-thức-lưu-trữ-danh-sách-trên-bằng-mảng-danh-sách-liên-kết-đơn-danh-sách-liên-kết-vòng-danh-sách-liên-kết-kép)
  - [3. Xây dựng chức năng cho phép người dùng nhập điều kiện tìm kiếm các sinh viên dựa theo 1 trong các tiêu chí (Mã sinh viên, Họ, Tên, Lớp, Điểm), không phân biệt chữ hoa hay chữ thường](#3-xây-dựng-chức-năng-cho-phép-người-dùng-nhập-điều-kiện-tìm-kiếm-các-sinh-viên-dựa-theo-1-trong-các-tiêu-chí-mã-sinh-viên-họ-tên-lớp-điểm-không-phân-biệt-chữ-hoa-hay-chữ-thường)
  - [4. Xây dựng chức năng thêm mới sinh viên, cho phép người dùng nhập các thông tin: Mã sinh viên, Họ, Tên, Lớp , Điểm](#4-xây-dựng-chức-năng-thêm-mới-sinh-viên-cho-phép-người-dùng-nhập-các-thông-tin-mã-sinh-viên-họ-tên-lớp--điểm)
  - [5. Xây dựng chức năng cho phép người dùng xóa sinh viên theo Mã sinh viên nhập vào](#5-xây-dựng-chức-năng-cho-phép-người-dùng-xóa-sinh-viên-theo-mã-sinh-viên-nhập-vào)
  - [6. Xây dựng chức năng cho người dùng chọn](#6-xây-dựng-chức-năng-cho-người-dùng-chọn)
  - [7. Xây dựng chức năng cho người dùng chọn cách sắp xếp danh sách tăng dần gồm](#7-xây-dựng-chức-năng-cho-người-dùng-chọn-cách-sắp-xếp-danh-sách-tăng-dần-gồm)

</details>

## 1. Cho người dùng nhập danh sách sinh viên bằng cách import file excel DSSV.xlsx gồm các nội dung như sau

- Mã sinh viên (số +chữ)
- Họ
- Tên sinh viên
- Lớp
- Điểm

> :heavy_exclamation_mark:**Note**: Báo lỗi nếu nhập trùng mã sinh viên.

## 2. Cho người dùng chọn cách thức lưu trữ danh sách trên bằng mảng, danh sách liên kết đơn, danh sách liên kết vòng, danh sách liên kết kép

## 3. Xây dựng chức năng cho phép người dùng nhập điều kiện tìm kiếm các sinh viên dựa theo 1 trong các tiêu chí (Mã sinh viên, Họ, Tên, Lớp, Điểm), không phân biệt chữ hoa hay chữ thường

- Cho phép chọn yêu cầu Xuất đảo ngược thông tin họ và tên các sinh viên được tìm thấy. Nếu có thì hiển thị thêm chuỗi này trong kết quả tìm kiếm.

    :writing_hand: ***Ví dụ:***  chuỗi đảo ngược họ và tên của `Nguyen Ngoc Mai` là : `iaM cogN neyugN`.

- Trong kết quả hiển thị, in đậm / tô đỏ thông tin sinh viên tương ứng tiêu chí đang tìm kiếm.

- Hiển thị thời gian tìm kiếm.

## 4. Xây dựng chức năng thêm mới sinh viên, cho phép người dùng nhập các thông tin: Mã sinh viên, Họ, Tên, Lớp , Điểm

## 5. Xây dựng chức năng cho phép người dùng xóa sinh viên theo Mã sinh viên nhập vào

## 6. Xây dựng chức năng cho người dùng chọn

- Liệt kê các sinh viên có điểm thấp nhất
- Liệt kê các sinh viên có điểm cao nhất.
- Tính điểm trung bình của lớp.

## 7. Xây dựng chức năng cho người dùng chọn cách sắp xếp danh sách tăng dần gồm

- Chọn 1 trong các cách sắp xếp:
  - Bubble sort
  - Selection sort
  - Insertion sort
  - Quick sort
  - Merge sort
  - Heap sort
- Chọn một trong các tiêu chí sắp xếp:  Mã SV, Tên, Điểm.
- Hiển thị kết quả danh sách sau khi sắp xếp và thời gian thực hiện.
