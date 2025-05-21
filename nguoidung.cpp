#include "nguoidung.h"
#include "database.h"
#include "vi.h"
#include "otp.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
using namespace std;

map<string, NguoiDung> nguoiDungs;
extern void luuDuLieu(const map<string, NguoiDung>& nguoiDungs, const map<string, Vi>& vis);


map<string, ThongTinTam> thongTinTamThoi;



string bamMatKhau(const string& matKhau) {
    unsigned long hash = 5381;
    for (int i = 0; i < matKhau.length(); ++i)
        hash = ((hash << 5) + hash) + matKhau[i];
    stringstream ss;
    ss << hash;
    return ss.str();
}

string matKhauTuDong() {
    int doDai = 6;
    string kyTu = "a123456789";
    string matKhau = "";
    srand(time(0));
    for (int i = 0; i < doDai; ++i) {
        matKhau += kyTu[rand() % kyTu.length()];
    }
    return matKhau;
}

void taoTaiKhoan(bool laQuanTri) {
    NguoiDung nd;
    cout << "Nhap ten dang nhap: "; cin >> nd.tenDangNhap;
    if (nguoiDungs.count(nd.tenDangNhap)) {
        cout << "Tai khoan da ton tai.\n";
        return;
    }
    cout << "Nhap ho ten: "; cin.ignore(); getline(cin, nd.hoTen);
    cout << "Nhap email: "; getline(cin, nd.email);
    cout << "Nhap so dien thoai: "; getline(cin, nd.soDienThoai);
    
    string matKhau;
    if (laQuanTri) {
        matKhau = matKhauTuDong();
        cout << "Mat khau tu dong da duoc tao: " << matKhau << endl;
        nd.matKhauTam = true;
    } else {
        cout << "Nhap mat khau: "; cin >> matKhau;
        nd.matKhauTam = false;
    }
    nd.matKhauBam = bamMatKhau(matKhau);
    nd.laQuanTri = laQuanTri;

    nguoiDungs[nd.tenDangNhap] = nd;
    taoVi(nd.tenDangNhap);
    luuDuLieu(nguoiDungs, vis); 
    cout << "Tao tai khoan thanh cong.\n";
}

bool dangNhap(string& tenDangNhapOut) {
    string tenDangNhap, matKhau;
    cout << "Ten dang nhap: "; cin >> tenDangNhap;
    cout << "Mat khau: "; cin >> matKhau;
    if (nguoiDungs.count(tenDangNhap) == 0 || 
        nguoiDungs[tenDangNhap].matKhauBam != bamMatKhau(matKhau)) {
        cout << "Dang nhap that bai.\n";
        return false;
    }
    tenDangNhapOut = tenDangNhap;
    if (nguoiDungs[tenDangNhap].matKhauTam) {
        cout << "Ban dang dung mat khau tam. Nhap mat khau moi: ";
        string mkMoi; cin >> mkMoi;
        nguoiDungs[tenDangNhap].matKhauBam = bamMatKhau(mkMoi);
        nguoiDungs[tenDangNhap].matKhauTam = false;
        luuDuLieu(nguoiDungs, vis);
    }
    return true;
}

void capNhatThongTinCaNhan(const string& tenDangNhap) {
    cin.ignore(); 
    cout << "Nhap ho ten moi (de trong neu khong muon thay doi): ";
    string hoTenMoi;
    getline(cin, hoTenMoi);
    if (!hoTenMoi.empty()) {
        nguoiDungs[tenDangNhap].hoTen = hoTenMoi;
    }

    cout << "Nhap email moi (de trong neu khong muon thay doi): ";
    string emailMoi;
    getline(cin, emailMoi);
    if (!emailMoi.empty()) {
        nguoiDungs[tenDangNhap].email = emailMoi;
    }

    cout << "Nhap so dien thoai moi (de trong neu khong muon thay doi): ";
    string soDienThoaiMoi;
    getline(cin, soDienThoaiMoi);
    if (!soDienThoaiMoi.empty()) {
        nguoiDungs[tenDangNhap].soDienThoai = soDienThoaiMoi;
    }

    cout << "Nhap mat khau moi (de trong neu khong muon thay doi): ";
    string matKhauMoi;
    getline(cin, matKhauMoi);
    if (!matKhauMoi.empty()) {
        nguoiDungs[tenDangNhap].matKhauBam = bamMatKhau(matKhauMoi);
        nguoiDungs[tenDangNhap].matKhauTam = false;
    }
	guiOtp(tenDangNhap);  

    cout << "Vui long nhap ma OTP de cap nhat thong tin: ";
    string otpNhap;
    cin >> otpNhap;

    if (!xacThucOtp(tenDangNhap, otpNhap)) {
        cout << "Ma OTP khong dung. Khong duoc cap nhat thong tin.\n";
        return;
    }
    luuDuLieu(nguoiDungs, vis);
    cout << "\nCap nhat thong tin ca nhan thanh cong!\n";
}

void hienThiThongTinCaNhan(const string& tenDangNhap) {
    if (nguoiDungs.count(tenDangNhap) == 0) {
        cout << "Khong tim thay nguoi dung.\n";
        return;
    }
    const NguoiDung& nd = nguoiDungs[tenDangNhap];
    cout << "----- Thong tin ca nhan -----\n";
    cout << "Ten dang nhap: " << nd.tenDangNhap << "\n";
    cout << "Ho ten: " << nd.hoTen << "\n";
    cout << "Email: " << nd.email << "\n";
    cout << "So dien thoai: " << nd.soDienThoai << "\n";
    cout << "----------------------------\n";
}

void accountAdmin() {
    NguoiDung admin;
    admin.tenDangNhap = "admin";   
    admin.matKhauBam = bamMatKhau("admin"); 
    admin.laQuanTri = true;
    admin.matKhauTam = false;
    nguoiDungs[admin.tenDangNhap] = admin;
}

void layLaiMatKhau() {
    cout << "Nhap ten tai khoan can lay lai mat khau: ";
    string tenCanLay;
    cin >> tenCanLay;

    if (nguoiDungs.count(tenCanLay) == 0) {
        cout << "Tai khoan khong ton tai.\n";
        return;
    }

    string matKhauMoi = "123456";
    nguoiDungs[tenCanLay].matKhauBam = bamMatKhau(matKhauMoi);
    nguoiDungs[tenCanLay].matKhauTam = true;
    luuDuLieu(nguoiDungs, vis);

    cout << "Mat khau moi cua tai khoan '" << tenCanLay << "' da duoc dat ve: " << matKhauMoi << "\n";
    cout << "Nguoi dung phai doi mat khau ngay sau khi dang nhap.\n";
}

void hienThiDanhSachKhachHang() {
    cout << "DANH SACH KHACH HANG \n";
    int stt = 1;
    for (const auto& it : nguoiDungs) {
    const string& tenDangNhap = it.first;
    const NguoiDung& nd = it.second;
        if (!nd.laQuanTri) {
            cout << stt << ". " << tenDangNhap << endl;
            ++stt;
        }
    }
    if (stt == 1) {
        cout << "Khong co tai khoan khach hang nao.\n";
    }
}   


void xuLyCapNhatSauDangNhap(const string& tenDangNhap) {
    if (thongTinTamThoi.count(tenDangNhap) == 0) return;

    ThongTinTam tt = thongTinTamThoi[tenDangNhap];
    NguoiDung& nd = nguoiDungs[tenDangNhap];

    cout << "\n[THONGBAO] Co yeu cau cap nhat thong tin ca nhan:\n";
    cout << " - Ho ten: " << nd.hoTen << " -> " << tt.hoTen << "\n";
    cout << " - Email: " << nd.email << " -> " << tt.email << "\n";
    cout << " - So dien thoai: " << nd.soDienThoai << " -> " << tt.soDienThoai << "\n";

    cout << "Ban co dong y cap nhat? (y/n): ";
    char c;
    cin >> c;
    if (c == 'y' || c == 'Y') {
        guiOtp(tenDangNhap);
        cout << "Nhap OTP: ";
        string otp;
        cin >> otp;
 
        if (xacThucOtp(tenDangNhap, otp)) {
            nd.hoTen = tt.hoTen;
            nd.email = tt.email;
            nd.soDienThoai = tt.soDienThoai;
            thongTinTamThoi.erase(tenDangNhap);
            cout << "Cap nhat thanh cong!\n";
            luuDuLieu(nguoiDungs, vis); // Ghi file
        } else {
            cout << "OTP sai. Huy cap nhat.\n";
        }
    } else {
        cout << "? Ban da tu choi. Yeu cau bi huy.\n";
        thongTinTamThoi.erase(tenDangNhap);
    }
}


void yeuCauCapNhatNguoiDung() {
    string tenKH;
    cout << "Nhap ten dang nhap khach hang: ";
    cin >> tenKH;

    if (nguoiDungs.count(tenKH) == 0) {
        cout << "Khong tim thay tai khoan khach hang.\n";
        return;
    }

    ThongTinTam tam; 
    cout << "Nhap thong tin moi:\n";
    cout << "Ten moi: "; cin.ignore(); getline(cin, tam.hoTen);
    cout << "Email moi: "; getline(cin, tam.email);
    cout << "SDT moi: "; getline(cin, tam.soDienThoai);

    thongTinTamThoi[tenKH] = tam; 
    cout << "? Yeu cau cap nhat da duoc tao. Khach hang se xac nhan khi dang nhap.\n";
}


