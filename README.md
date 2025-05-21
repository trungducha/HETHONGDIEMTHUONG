# HETHONGDIEMTHUONG
Hệ thống đăng nhập và đăng ký tài khoản và quản lý ví điểm thưởng
1. Tên đồ án
Hệ thống Đăng nhập, Đăng ký tài khoản và Quản lý ví điểm thưởng
2. Mục tiêu dự án
Xây dựng hệ thống dòng lệnh cho phép người dùng đăng ký, đăng nhập tài khoản, quản lý ví điểm và thực hiện giao dịch chuyển điểm. Hệ thống có phân quyền người quản lý và người dùng thường, sử dụng OTP để tăng cường bảo mật.
3. Tổ chức hệ thống
   
3.1. Ngôn ngữ C++

3.2. Giao diện
Giao diện dòng lệnh (text-based CLI)

3.3. Quản lý mã nguồn
Chia file rõ ràng, lưu dữ liệu bằng tập tin .txt

3.4. Cấu trúc file
File	Vai trò main.cpp	
Điều phối luồng chương trình, gọi menu
nguoidung.cpp/h	Xử lý người dùng: tạo, đăng nhập, cập nhật
vi.cpp/h	Xử lý ví điểm, chuyển điểm, log giao dịch
otp.cpp/h	Sinh và xác thực mã OTP
database.cpp/h	Giao tiếp với file nguoidung.txt (luu tru tai khoan va thong tin nguoi dung)
4. Chức năng hệ thống
- Đăng ký, đăng nhập, phân quyền
- Bảo mật OTP
- Quản lý thông tin cá nhân
- Quản lý ví và giao dịch điểm
5. Ví điểm thưởng
Mỗi người dùng có 1 ví.
Hệ thống cho phép chuyển điểm giữa các ví với kiểm tra số dư và OTP.
Lịch sử giao dịch được lưu lại.
6. Lưu trữ dữ liệu
- File: nguoidung.txt
- Ghi dữ liệu sau mỗi thao tác
- Tải dữ liệu khi khởi động
7. Bảo mật và an toàn dữ liệu
Biện pháp	Cơ chế triển khai
Băm mật khẩu	Hàm djb2 đơn giản
OTP	Tự sinh, giới hạn thời gian
Không lưu pass rõ ràng	Có mã hóa
Rollback giao dịch	Dùng try-catch trong giao dịch
