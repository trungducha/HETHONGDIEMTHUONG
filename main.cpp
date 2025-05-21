#include <iostream>
#include <map>
#include <string>
#include "nguoidung.h"
#include "vi.h"
#include "otp.h"
#include "database.h"

using namespace std;

extern map<string, NguoiDung> nguoiDungs;
extern map<string, Vi> vis;

void menuAdmin(const string& tenDangNhap) {
    while (true) {
        system("cls");
        cout << "\n--- GIAO DIEN ADMIN ---\n";
        cout << "1. Lay lai mat khau\n";
        cout << "2. Tao tai khoan cho khach hang\n";
        cout << "3. Danh sach khach hang\n";
        cout << "4. Cap nhat thong tin khach hang\n";
        cout << "0. Dang xuat\n";
        cout << "Chon: ";
        int c;
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le.\n";
            system("pause");
            continue;
        }
 
        switch (c) {
            case 1: layLaiMatKhau(); break;
            case 2: system("cls"); taoTaiKhoan(true); break;
            case 3: system("cls"); hienThiDanhSachKhachHang(); break;
            case 4: system("cls"); yeuCauCapNhatNguoiDung(); break;
            case 0: cout << "Dang xuat...\n"; return;
            default: cout << "Lua chon khong hop le.\n"; break;
        }
        system("pause");
    }
}

void menuClient(const string& tenDangNhap) {
    while (true) {
        system("cls");
        cout << "\nVI CA NHAN CUA: " << tenDangNhap << "\n";
        cout << "1. Xem so diem\n";
        cout << "2. Chuyen diem\n";
        cout << "3. Cap nhat thong tin ca nhan\n";
        cout << "4. Xem thong tin ca nhan\n";
        cout << "0. Dang xuat\n";
        cout << "Chon: ";
        int c;
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le.\n";
            system("pause");
            continue;
        }

        switch (c) {
            case 1: hienThiDiem(tenDangNhap); break;
            case 2: chuyenDiem(tenDangNhap); break;
            case 3: system("cls"); capNhatThongTinCaNhan(tenDangNhap); break;
            case 4:
                system("cls");
                hienThiThongTinCaNhan(tenDangNhap);
                cout << "Nhan phim bat ki de quay lai.\n";
                break;
            case 0:
                cout << "Dang xuat...\n";
                system("pause");
                return;
            default:
                cout << "Lua chon khong hop le.\n";
                break;
        }
        system("pause");
    }
}

bool xuLyDangNhapKhachHang(const string& tenDangNhap) {
    guiOtp(tenDangNhap);
    string inputOtp;
    cout << "Vui long nhap ma OTP: ";
    cin >> inputOtp;

    if (!xacThucOtp(tenDangNhap, inputOtp)) {
        cout << "Ma OTP sai. Dang nhap that bai.\n";
        system("pause");
        return false;
    }

    cout << "XAC THUC THANH CONG, BAM PHIM BAT KI DE TIEP TUC!!!\n";
    system("pause");

    luuDuLieu(nguoiDungs, vis);
    
	xuLyCapNhatSauDangNhap(tenDangNhap); //... 
    menuClient(tenDangNhap);
    
    return true;
}

int main() {
    srand(time(0));
    checkAndCreateFile();
    loadDuLieu(nguoiDungs, vis);
    accountAdmin();

    while (true) {
        system("cls");
        cout << "\nHE THONG DANG NHAP, DANG KY TAI KHOAN VA QUAN LY VI DIEM THUONG\n";
        cout << "1. Tao tai khoan\n";
        cout << "2. Dang nhap\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";

        int ch;
        if (!(cin >> ch)) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Nhap khong hop le.\n";
            system("pause");
            continue;
        }

        switch (ch) {
            case 1:
                system("cls");
                taoTaiKhoan();
                system("pause");
                break;
            case 2: {
                system("cls");
                string tenDangNhap;
                if (dangNhap(tenDangNhap)) {
                    if (nguoiDungs.count(tenDangNhap) == 0) {
                        cout << "Tai khoan khong ton tai.\n";
                        system("pause");
                        break;
                    }

                    if (nguoiDungs[tenDangNhap].laQuanTri) {
                        menuAdmin(tenDangNhap);
                    } else { 
                 	 
                        xuLyDangNhapKhachHang(tenDangNhap);
                        
                    }
                } else {
                    cout << "Dang nhap that bai.\n";
                    system("pause");
                }
                break;
            }
            case 0:
                return 0;
            default:
                cout << "Lua chon khong hop le.\n";
                system("pause");
                break;
        }
    }

    return 0;
}

