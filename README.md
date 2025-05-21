HỆ THỐNG QUẢN LÝ VÍ ĐIỂM THƯỞNG 
link Demo Google Driver : https://drive.google.com/file/d/1D5-_OYGjCbLrk-0LH0eCMEgjpnA5yBkF/view?usp=drive_link
1.Giới thiệu dự án
Dự án xây dựng một ứng dụng quản lý ví điểm thưởng bằng C++. Hệ thống hỗ trợ:

Đăng ký và đăng nhập người dùng (phân quyền khách hàng và admin)

Quản lý thông tin cá nhân người dùng

Giao dịch chuyển điểm giữa các ví

Ghi lịch sử giao dịch

**Xác thực người dùng bằng OTP khi thực hiện các thao tác quan trọng
----------------------------------------------------------------------------
2.Thành viên tham gia dự án
Họ tên	          Vai trò / Công việc đảm nhiệm
Ha Trung Duc	Thiết kế kiến trúc hệ thống, xử lý đăng nhập, phân quyền người dùng
	            Xây dựng chức năng quản lý ví, chuyển điểm, OTP
               Phát triển chức năng quản trị (admin), cập nhật thông tin người dùng
               Tích hợp dữ liệu, xử lý file, và lưu/đọc dữ liệu từ hệ thống tệp
----------------------------------------------------------------------------**
3.Đặc tả chức năng chính
Tài khoản

Đăng ký tài khoản (Admin / Khách hàng)

Đăng nhập

Khôi phục mật khẩu (admin)

Đổi mật khẩu khi đăng nhập bằng mật khẩu tạm

Quản lý thông tin người dùng

Cập nhật thông tin cá nhân (ho tên, email, SĐT)

Admin yêu cầu cập nhật thay cho người dùng, xác nhận khi đăng nhập

Ví điện tử

Tạo ví khi tạo tài khoản

Xem số điểm

Chuyển điểm giữa các ví (có xác thực OTP)

Ghi lịch sử chuyển điểm

OTP

Sinh mã OTP ngẫu nhiên

OTP có hiệu lực trong 5 phút

OTP dùng khi chuyển điểm hoặc cập nhật thông tin
----------------------------------------------------------------------------
4.Cài đặt & Biên dịch chương trình
Yêu cầu
Trình biên dịch hỗ trợ chuẩn C++ (g++ trên Linux hoặc MinGW/Visual Studio trên Windows)
Biên dịch
bash
Copy
Edit
g++ -o vi_diem main.cpp database.cpp nguoidung.cpp vi.cpp otp.cpp
Hoặc biên dịch từng file .cpp riêng nếu cần.
----------------------------------------------------------------------------
5.Cấu trúc tệp
Tệp	Mô tả chức năng
main.cpp	Hàm main, hiển thị menu chính, xử lý dòng lệnh
database.cpp	Đọc/ghi dữ liệu người dùng và ví từ file
nguoidung.cpp	Đăng ký, đăng nhập, cập nhật thông tin người dùng
vi.cpp	Xử lý ví: tạo ví, chuyển điểm, hiển thị điểm, lịch sử
otp.cpp	Sinh, gửi và xác thực mã OTP
*.h	Khai báo struct, hàm và biến toàn cục
nguoidung.txt	File dữ liệu chứa danh sách người dùng và ví
lichsu_chuyendiem.txt	File lưu lịch sử giao dịch chuyển điểm
----------------------------------------------------------------------------
6.Hướng dẫn chạy chương trình
6.1 Thao tác người dùng:

Chọn 1 để đăng ký/ tạo tài khoản

Chọn 2 để đăng nhập

Nếu đăng nhập với admin: dùng tài khoản admin / mật khẩu admin

Nếu là khách hàng: cần xác thực OTP
----------------------------------------------------------------------------
6.2 Giao diện người dùng:

Có 2 menu: Admin và Khách hàng

Thao tác được nhập qua bàn phím số

7.Sơ đồ hệ thống
             +---------------------------+
             |   GIAO DIỆN DÒNG LỆNH     |
             |   (Console Menu UI)       |
             +---------------------------+
                        |
                        v
             +---------------------------+
             |  ĐĂNG KÝ / ĐĂNG NHẬP      |
             | - Nhập thông tin          |
             | - Tạo tài khoản           |
             | - Mật khẩu tự sinh / băm |
             +---------------------------+
                        |
                        v
             +---------------------------+
             |     PHÂN QUYỀN NGƯỜI DÙNG |
             | - Người dùng thường       |
             | - Quản trị viên           |
             +---------------------------+
               |                     |
        (User) v                     v (Admin)
+---------------------+   +------------------------+
| QUẢN LÝ VÍ ĐIỂM      |   |  QUẢN LÝ TÀI KHOẢN     |
| - Xem số dư         |   | - Danh sách người dùng|
| - Chuyển điểm       |   | - Tạo tài khoản hộ    |
| - Lịch sử giao dịch |   | - Cập nhật thông tin  |
+---------------------+   +------------------------+
        |                               |
        +---------------+---------------+
                        v
              +----------------------+
              |      OTP MODULE      |
              | - Sinh mã OTP        |
              | - Gửi và xác thực    |
              +----------------------+
                        |
                        v
              +----------------------+
              |   LƯU TRỮ DỮ LIỆU    |
              | - nguoidung.txt (người dùng, ví)
                - lichSu_chuyendiem.txt|
              | - Backup định kỳ     |
              +----------------------+

