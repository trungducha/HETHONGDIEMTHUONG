#include "vi.h"
#include "otp.h"
#include "nguoidung.h"
#include "database.h"
#include <iostream>
#include <fstream> 
using namespace std;

map<string, Vi> vis;

void taoVi(const string& tenDangNhap) {
    Vi vi;
    vi.maVi = tenDangNhap;
    vi.tenDangNhap = tenDangNhap;
    vi.soDu = 0;
    vis[vi.maVi] = vi;
}

void chuyenDiem(const string& nguoiGui) {
    string viNhan;
    int soDiem;
    cout << "Nhap ma vi nguoi nhan: "; 
    cin >> viNhan;

    if (vis.count(viNhan) == 0) {
        cout << "Vi khong ton tai.\n";
        return;
    }

    cout << "Nhap so diem: ";
    cin >> soDiem;

    string viGui = nguoiGui;

    guiOtp(nguoiGui);
    cout << "Nhap OTP: ";
    string otp;
    cin >> otp;

    if (!xacThucOtp(nguoiGui, otp)) {
        cout << "OTP sai.\n";
        return;
    }

    int oldSoDuGui = vis[viGui].soDu;
    int oldSoDuNhan = vis[viNhan].soDu;

    try {
        if (oldSoDuGui < soDiem) {
            cout << "So du khong du. Cannot proceed.\n";
            return;
        }

        vis[viGui].soDu -= soDiem;
        vis[viNhan].soDu += soDiem;

        ghiLichSuChuyenDiem(viGui, viNhan, soDiem,oldSoDuGui, oldSoDuNhan);
        cout << "Chuyen diem thanh cong.\n";
        luuDuLieu(nguoiDungs, vis);
    }
    catch (...) {
        vis[viGui].soDu = oldSoDuGui;
        vis[viNhan].soDu = oldSoDuNhan;
        cout << "Giao dich bi huy do co loi.\n";
    }
}
void ghiLichSuChuyenDiem(const string& tuTaiKhoan, const string& denTaiKhoan, int soDiem, int soDuTruocGui, int soDuTruocNhan) {
    ofstream file("lichsu_chuyendiem.txt", ios::app);
    if (!file) return;

    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buf[100];
    strftime(buf, sizeof(buf), "%d/%m/%Y %H:%M:%S", ltm);

    file << buf << ": Tai khoan "<< tuTaiKhoan << "(co so du: "<< soDuTruocGui <<" ) da Chuyen " << soDiem << " diem den tai khoan  " << denTaiKhoan << "(co so du: " <<soDuTruocNhan <<")\n";
    file.close();
}
void hienThiDiem(const string& tenDangNhap) {
    if (vis.count(tenDangNhap)) {
        cout << "So diem hien tai cua ban: " << vis[tenDangNhap].soDu << " diem\n";
    } else {
        cout << "Khong tim thay vi cua nguoi dung.\n";
    }
}

