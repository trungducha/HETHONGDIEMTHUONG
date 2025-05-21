#ifndef NGUOIDUNG_H
#define NGUOIDUNG_H

#include <string>
#include <map>
using namespace std;

struct NguoiDung {
    string tenDangNhap;
    string matKhauBam;
    string hoTen;
    string email;
    string soDienThoai;
    bool laQuanTri;
    bool matKhauTam;
};
struct ThongTinTam {
    string hoTen;
    string email;
    string soDienThoai;
};
// bien toan cuc 
extern map<string, NguoiDung> nguoiDungs;
extern map<string, ThongTinTam> thongTinTamThoi;




// ham chuc nang 
string bamMatKhau(const string& matKhau);
string matKhauTuDong();

void taoTaiKhoan(bool laQuanTri = false);
bool dangNhap(string& tenDangNhapOut);

void capNhatThongTinCaNhan(const string& tenDangNhap);
void hienThiThongTinCaNhan(const string& tenDangNhap);

void accountAdmin();
void layLaiMatKhau();
void hienThiDanhSachKhachHang();

void xuLyCapNhatSauDangNhap(const string& tenDangNhap);
void yeuCauCapNhatNguoiDung();
#endif

