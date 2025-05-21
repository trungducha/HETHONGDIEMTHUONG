#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>
#include "nguoidung.h"
#include "vi.h"

using namespace std;

// Khai báo các hàm qu?n l? d? li?u
void checkAndCreateFile();
void loadDuLieu(map<string, NguoiDung>& nguoiDungs, map<string, Vi>& vis);
void luuDuLieu(const map<string, NguoiDung>& nguoiDungs, const map<string, Vi>& vis);

// Khai báo các menu (n?u c?n dùng t? file khác)
void menuAdmin(const string& tenDangNhap);
void menuClient(const string& tenDangNhap);
bool xuLyDangNhapKhachHang(const string& tenDangNhap);

#endif // DATABASE_H

