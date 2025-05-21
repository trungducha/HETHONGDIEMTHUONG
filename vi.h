#ifndef VI_H
#define VI_H

#include <string>
#include <map>
using namespace std;

struct Vi {
    string maVi;
    string tenDangNhap;
    int soDu;
};

extern map<string, Vi> vis;

void taoVi(const string& tenDangNhap);
void chuyenDiem(const string& nguoiGui);
void hienThiDiem(const string& tenDangNhap);
void ghiLichSuChuyenDiem(const string& tuTaiKhoan, const string& denTaiKhoan, int soDiem, int soDuTruocGui, int soDuTruocNhan);
#endif

