#include "otp.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

map<string, OTP> otpMa;

string taoOtp() {
    srand(static_cast<unsigned int>(time(0)));
    string otp = "";
    for (int i = 0; i < 6; ++i)
        otp += to_string(rand() % 10);
    return otp;
}

void guiOtp(const string& tenDangNhap) {
    string ma = taoOtp();
    otpMa[tenDangNhap] = {ma, time(0)};
    cout << "[OTP]: " << ma << endl;
}

bool xacThucOtp(const string& tenDangNhap, const string& otp) {
    if (otpMa.count(tenDangNhap) == 0) return false;
    OTP o = otpMa[tenDangNhap];
    return (time(0) - o.thoiGian <= 300) && (o.ma == otp);
}

