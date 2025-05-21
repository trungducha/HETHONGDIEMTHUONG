#ifndef OTP_H
#define OTP_H

#include <string>
#include <map>
#include <ctime>
using namespace std;

struct OTP {
    string ma;
    time_t thoiGian;
};

extern map<string, OTP> otpMa;

string taoOtp();
void guiOtp(const string& tenDangNhap);
bool xacThucOtp(const string& tenDangNhap, const string& otp);

#endif

