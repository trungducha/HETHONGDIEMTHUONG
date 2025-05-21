#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <map>
#include "nguoidung.h"
#include "vi.h"

using namespace std;

// Khai b�o c�c h�m qu?n l? d? li?u
void checkAndCreateFile();
void loadDuLieu(map<string, NguoiDung>& nguoiDungs, map<string, Vi>& vis);
void luuDuLieu(const map<string, NguoiDung>& nguoiDungs, const map<string, Vi>& vis);

// Khai b�o c�c menu (n?u c?n d�ng t? file kh�c)
void menuAdmin(const string& tenDangNhap);
void menuClient(const string& tenDangNhap);
bool xuLyDangNhapKhachHang(const string& tenDangNhap);

#endif // DATABASE_H

