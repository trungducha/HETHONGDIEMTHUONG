#include "database.h"
#include <fstream>
#include <sstream>
#include <iostream>

void checkAndCreateFile() {
    std::ifstream file("nguoidung.txt");
    if (!file) {
        std::ofstream newFile("nguoidung.txt");
        if (newFile) {
            newFile << "tenDangNhap|matKhauBam|hoTen|email|soDienThoai|laQuanTri|matKhauTam|maVi|soDu\n";
        } else {
            std::cout << "Khong the tao file." << std::endl;
        }
    }
    file.close();
}

void loadDuLieu(std::map<std::string, NguoiDung>& nguoiDungs, std::map<std::string, Vi>& vis) {
    std::ifstream file("nguoidung.txt");
    if (!file.is_open()) return;

    std::string line;
    bool firstLine = true;

    while (getline(file, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }

        std::stringstream ss(line);
        std::string token;
        NguoiDung nd;
        Vi vi;

        getline(ss, nd.tenDangNhap, '|');
        getline(ss, nd.matKhauBam, '|');
        getline(ss, nd.hoTen, '|');
        getline(ss, nd.email, '|');
        getline(ss, nd.soDienThoai, '|');
        getline(ss, token, '|');
        nd.laQuanTri = (token == "1");
        getline(ss, token, '|');
        nd.matKhauTam = (token == "1");
        getline(ss, vi.maVi, '|');
        getline(ss, token, '|');
        vi.soDu = std::stoi(token);
        vi.tenDangNhap = nd.tenDangNhap;

        nguoiDungs[nd.tenDangNhap] = nd;
        vis[vi.maVi] = vi;
    }

    file.close();
}

void luuDuLieu(const std::map<std::string, NguoiDung>& nguoiDungs, const std::map<std::string, Vi>& vis) {
    std::ofstream file("nguoidung.txt");
    if (!file.is_open()) return;

    file << "tenDangNhap|matKhauBam|hoTen|email|soDienThoai|laQuanTri|matKhauTam|maVi|soDu\n";

    for (const auto& pair : nguoiDungs) {
        const NguoiDung& nd = pair.second;
        
        // bo qua tai khoan admin ko luu vao file 
        if (nd.tenDangNhap == "admin") continue;
        
        std::string maVi = nd.tenDangNhap;

        if (vis.count(maVi) == 0) continue;

        const Vi& vi = vis.at(maVi);

        file << nd.tenDangNhap << "|"
             << nd.matKhauBam << "|"
             << nd.hoTen << "|"
             << nd.email << "|"
             << nd.soDienThoai << "|"
             << (nd.laQuanTri ? "1" : "0") << "|"
             << (nd.matKhauTam ? "1" : "0") << "|"
             << vi.maVi << "|"
             << vi.soDu << "\n";
    }

    file.close();
}
