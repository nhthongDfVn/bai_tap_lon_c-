//Bai tap lon bo mon Ngon ngu lap trinh c++
//Hoan thanh ngay: 19/10/2018
//Du an gom co:
//Le Thanh Tuan
//Bui Nhat Duy
//Nguyen Hoang Thong
//Nguyen Trung Tinh 
//Do Anh Quan
// ver 1.0.0 
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class nhaTro {
private:
	int soPhong, soDienCu, soDienMoi, soNuocCu, soNuocMoi, soNguoi;
	int heSoNuoc, heSoDien;
	int soNguoiMax;
public:
	void SetsoPhong(int po) {
		soPhong = po;
	}
	int GetsoPhong() {
		return soPhong;
	}
	void SetsoDienCu(int po1) {
		soDienCu = po1;
	}
	int GetsoDienCu() {
		return soDienCu;
	}
	void SetsoDienMoi(int po2) {
		soDienMoi = po2;
	}
	int GetsoDienMoi() {
		return soDienMoi;
	}
	void SetsoNuocCu(int po3) {
		soNuocCu = po3;
	}
	int GetsoNuocCu() {
		return soNuocCu;
	}
	void SetsoNuocMoi(int po4) {
		soNuocMoi = po4;
	}
	int GetsoNuocMoi() {
		return soNuocMoi;
	}
	void SetsoNguoi(int po5) {
		soNguoi = po5;
	}
	int GetsoNguoi() {
		return soNguoi;
	}
	void SetheSoNuoc(int po6) {
		heSoNuoc = po6;
	}
	int GetheSoNuoc() {
		return heSoNuoc;
	}
	void SetheSoDien(int po7) {
		heSoDien = po7;
	}
	int GetheSoDien() {
		return heSoDien;
	}
	void SetsoNguoiMax() {
		soNguoiMax = 4;
	}
	int GetsoNguoiMax() {
		return soNguoiMax;
	}
};

typedef struct {
	int ngay, thang, nam;
}birth;

class Nguoi {
private:
	char Ten[35];
	birth Ngaysinh;
	int Gioi;			//0 là Nữ, 1 là Nam
	char Quequan[35];
	char CMND[12];
	int soPhong;
public:
	void SetTen(char tenIn[35]) {
		for (int i = 0; i < 35; i++) Ten[i] = tenIn[i];
	}
	string GetTen() {
		string s;
		for (int i = 0; i < 35; i++) {
			if ((Ten[i] == ' ') || ((Ten[i] >= 'A') && (Ten[i] <= 'z')))
				s += Ten[i];
		}
		return s;
	}
	void SetNgaysinh(birth nGaysinh) {
		Ngaysinh = nGaysinh;
	}
	birth GetNgaysinh() {
		return Ngaysinh;
	}
	string GetQuequan() {
		string s1;
		for (int i = 0; i < 35; i++) {
			if ((Quequan[i] == ' ') || ((Quequan[i] >= 'A') && (Quequan[i] <= 'z')) || ((Quequan[i] >= '0') && (Quequan[i] <= '9')))
				s1 += Quequan[i];
		}
		return s1;
	}
	void SetQuequan(char quequan[35]) {
		for (int i = 0; i < 35; i++) Quequan[i] = quequan[i];
	}
	void SetGioi(int a) {
		Gioi = a;			//a=0:Nữ,a=1:Nam;chỉ có 0 và 1
	}
	int GetGioi() {
		return Gioi;
	}
	void SetCMND(char Cm[12]) {
		for (int i = 0; i < 12; i++) CMND[i] = Cm[i];
	}

	string GetCMND() {
		string s1;
		for (int i = 0; i < 12; i++) {
			if ((CMND[i] >= '0') && (CMND[i] <= '9'))
				s1 += CMND[i];
		}
		return s1;
	}
	void SetsoPhong(int po0) {
		soPhong = po0;
	}
	int GetsoPhong() {
		return soPhong;
	}
};

void showThongTin1Phong();
void menuChucNang();
void timKiem(); //{ hàm bao gồm các hàm từ 39 đến 44 + hiển thị thông tin bằng hàm 53 }
//void timThongTinTheoTen(int [],int);
void timThongTinTheoCMND();
void timThongTinTheoGioiTinh();
void timThongTinTheoNamSinh();
void timTheoSoPhong();
int tinhTienDien(int);
int tinhTienNuoc(int);
void tinhTongTien(); //{ bao gồm các hàm 44 + 45 }
void themNguoi();
void chinhSuaThongTinPhong();//{ lấy thông tin từ hàm 44 + hiển thị và chỉnh sửa bằng các hàm get và set }
void chinhSuaThongTinNguoi(); //{ lấy thông tin từ hàm 39 đến 41 + hiển thị và sửa bằng các hàm get set }
void chinhSuaThongTin();//(menu lựa chọn + bao gồm các hàm 50 và 51}
void menuXoaNguoi();
string gioitinh(int i);
void menuThemXoaNguoi();
int checkphong(int i);
int demsoluong(int i);
void intable();

void xoaManHinh() { system("cls"); }
int timduoc[40];
int soNguoi;
nhaTro nhatro[11];
nhaTro nhatro_copy[11];
vector <Nguoi> nguoi;
int dd[45];

//====================================================================================================

void khoitaonhaTro() {
	for (int i = 1; i <= 10; i++) {
		if (nhatro[i].GetsoNguoi() == 0) {
			nhatro[i].SetsoDienCu(0);
			nhatro[i].SetsoDienMoi(0);
			nhatro[i].SetsoNuocCu(0);
			nhatro[i].SetsoNuocMoi(0);
			nhatro[i].SetheSoNuoc(0);
			nhatro[i].SetheSoDien(0);
		}
	}

}

string chuyendoi(int i)
{
	string s1 = nguoi[i].GetTen();
	string temp1, xau1;
	s1 = ' ' + s1;
	while (s1.length() != 0)
	{
		int k = s1.length() - 1;
		while (s1[k] != ' ')
		{
			temp1 += s1[k];
			s1.erase(k, 1);
			k--;
		}                                                                 //đảo tên
		s1.erase(k, 1);                            //Nguyen Hoang Thong ->thong hoang nguyen
		reverse(temp1.begin(), temp1.end());
		xau1 += temp1 + ' ';
		temp1 = "";
	}
	for (int j = 0; j < xau1.length(); j++)
	{
		if ((xau1[j] >= 'A') && (xau1[j] <= 'Z')) xau1[j] = tolower(xau1[j]);
	}
	return xau1;
}

void sapxepTheoTen()
{

	for (int i = 0; i < nguoi.size(); i++)
	{

		for (int j = 0; j < nguoi.size(); j++)
		{
			if (chuyendoi(i) < chuyendoi(j))
			{
				swap(nguoi[i], nguoi[j]);
			}
		}
	}

}

void thoat() {
	system("cls");
	menuChucNang();
	// đưa tất cả các hàm lớn về menu Lớn. 
}

void nhapFile()
{
	fstream filein("D:\DATABASE.DATA", ios::in | ios::binary);
	if (!filein)
	{
		cout << "Khong the mo file de doc. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	Nguoi ng1;
	while (filein.read(reinterpret_cast<char*>(&ng1), sizeof(Nguoi)))
	{
		nguoi.push_back(ng1);
	}
	filein.close();
}

void nhapFilePhong()
{
	fstream filein("D:\DATABASE_PHONG.DATA", ios::in | ios::binary);
	nhaTro tro;
	int i = 1;
	if (!filein)
	{
		cout << "Khong the mo file de doc. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	//nhaTro tro[11];
	while (filein.read(reinterpret_cast<char*>(&tro), sizeof(nhaTro)))
	{
		nhatro[i] = tro;
		i++;
	}
	filein.close();
}

void xuatFile()
{
	fstream fileout("D:\DATABASE.DATA", ios::out | ios::binary);
	if (!fileout)
	{
		cout << "Khong the mo file de ghi. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	for (int i = 0; i < nguoi.size(); i++)
	{
		Nguoi ng1;
		ng1 = nguoi[i];
		fileout.write(reinterpret_cast<char*>(&ng1), sizeof(Nguoi));
	}
	fileout.close();
}

void xuatFilePhong()
{
	fstream fileout("DATABASE_PHONG.DATA", ios::out | ios::binary);
	if (!fileout)
	{
		cout << "Khong the mo file de ghi. Vui long thu lai!";
		system("pause");
		exit(0);
	}
	for (int i = 1; i <= 11; i++)
	{
		nhaTro tro;
		tro.SetheSoDien(nhatro[i].GetheSoDien());
		tro.SetheSoNuoc(nhatro[i].GetheSoNuoc());
		tro.SetsoDienCu(nhatro[i].GetsoDienCu());
		tro.SetsoDienMoi(nhatro[i].GetsoDienMoi());
		tro.SetsoNguoi(nhatro[i].GetsoNguoi());
		tro.SetsoNguoiMax();
		tro.SetsoNuocCu(nhatro[i].GetsoNuocCu());
		tro.SetsoNuocMoi(nhatro[i].GetsoNuocMoi());
		tro.SetsoPhong(nhatro[i].GetsoPhong());
		fileout.write(reinterpret_cast<char*>(&tro), sizeof(nhaTro));
	}
	fileout.close();
}

string chuyendoingaysinh(int i)
{
	string s, s1, s2, s3;
	int k = nguoi[i].GetNgaysinh().ngay;
	while (k!= 0)
	{

		s1 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s1.begin(), s1.end());
	if (s1.length() == 1) s1 = '0' + s1;
	s += s1 + '/';
	k = nguoi[i].GetNgaysinh().thang;
	while (k!= 0)
	{

		s2 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s2.begin(), s2.end());
	if (s2.length() == 1) s2 = '0' + s2;
	s += s2 + '/';
	k = nguoi[i].GetNgaysinh().nam;
	while (k!= 0)
	{
		s3 += (k % 10) + '0';
		k /= 10;
	}
	reverse(s3.begin(), s3.end());
	s += s3;
	return s;
}

string gioitinh(int i)
{
	if (nguoi[i].GetGioi() == 1) return  "Nam";
	else return "Nu";
}

void showThongTin1Nguoi(Nguoi person, int i)
{
	cout << endl;
	string gioi;
	if (person.GetGioi() == 1) gioi = "Nam";
	else gioi = "Nu";

	//cout << left << setw(5) << i + 1 << setw(35) << person.GetTen() << setw(2) << person.GetNgaysinh().ngay << "/" << setw(2) << person.GetNgaysinh().thang << "/" << setw(20) << person.GetNgaysinh().nam << setw(10) << gioi << setw(20) << person.GetCMND() << setw(20) << person.GetQuequan() << setw(20) << person.GetsoPhong();
	//cout << endl;
	cout << "| " << left << setw(3) << i << "| " << left << setw(23) << nguoi[i].GetTen()
		<< "| " << left << setw(8) << gioitinh(i)
		<< "| " << left << setw(12) << chuyendoingaysinh(i)
		<< "| " << left << setw(15) << nguoi[i].GetQuequan()
		<< "| " << left << setw(11) << nguoi[i].GetCMND()
		<< "|     " << left << setw(5) << nguoi[i].GetsoPhong()
		<< setw(12) << "|";

}//checked

void showDanhSachPhong() {
	for (int i = 1; i <= 10; i++) {
		cout << i << "." << "Phong " << i << "." << endl;
	}
};//checked

void timTheoSoPhong2(int a, int timduoc[], int &soNguoi) {   //ham nay chi show thong tin cua nguoi o trong phong "a"
	soNguoi = 0;
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetsoPhong() == a) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
} //checked

void showThongTin1Phong(int n)     //cái này là thông tin của cái phòng(của đồ vật) thôi nha các cha, méo phải cái hàm show thông tin người trong phòng ở trên đâu
{
	cout << "So dien cu: " << nhatro[n].GetsoDienCu();
	cout << "\nSo nuoc cu: " << nhatro[n].GetsoNuocCu();
	cout << "\nHe so nuoc: " << nhatro[n].GetheSoNuoc();
	cout << "\nHe so dien: " << nhatro[n].GetheSoDien();
	cout << "\nSo nguoi hien tai: " << checkphong(n);
	cout << "\nSo nguoi max: " << nhatro[n].GetsoNguoiMax();
}//checked

void xemPhongCuThe() {
	showDanhSachPhong();
	cout << "\nNhap so phong ban muon xem: ";
	int luachon;
	cin >> luachon;
	while (luachon < 1 || luachon>10) {
		cout << "\nSo phong khong hop le, xin vui long nhap lai: ";
		cin >> luachon;
	}
	system("cls");
	// hàm này lấy lựa chọn được truyền vào và chỉ in ra dữ liệu của "MỘT" phòng cụ thể 
	cout << "Thong tin phong so:" << luachon << '\n';
	showThongTin1Phong(luachon); //-show điện nước ...
	cout << endl;
	timTheoSoPhong2(luachon, timduoc, soNguoi); //  show người
}

//===========================================================================================================================

int checkphong(int i)
{
	int num = 0;
	for (int j = 0; j < nguoi.size(); j++)
	{
		if (nguoi[j].GetsoPhong() == i) num++;
	}
	return num;
}

void timThongTinTheoTen(int timduoc[], int &soNguoi) {
	char a[35];
	soNguoi = 0;
	bool kytu = false;
	while (kytu == false)
	{
		cout << "Nhap ten can tim kiem: ";
		cin.ignore();
		cin.getline(a, 34);
		a[0] = toupper(a[0]);
		for (int i = 1; i < 35; i++)
		{
			if (a[i - 1] == ' ')
			{
				a[i] = toupper(a[i]);              //ki?m tra chính t?, ch? hoa ch? thu?ng tên
			}
			else
			{
				a[i] = tolower(a[i]);
			}
		}
		kytu = true;
		for (int i = 0; i < 35; i++) if ((a[i] >= '0') && (a[i] <= '9')) kytu = false; //ki?m tra có s? hay không
		if (kytu == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
	}
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	for (int i = 0; i < nguoi.size(); i++) {

		if (nguoi[i].GetTen() == a) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	if (soNguoi == 0) {
		cout << "\n[<>]Khong co ket qua tim kiem phu hop";
	}
} //checked

void timThongTinTheoCMND(int timduoc[], int &soNguoi) {
	char a[12];
	soNguoi = 0;
	bool kt = false;
	while (kt == false)
	{
		cout << "Nhap CMND can tim:";
		cin.ignore();
		cin.getline(a, 12);
		cin.ignore(0);
		kt = true;
		for (int i = 0; i < 12; i++) if ((a[i] >= 'A') && (a[i] <= 'z')) kt = false; //ki?m tra có s? hay không
		if (kt == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
	}
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";

	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetCMND() == a) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}

	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	if (soNguoi == 0) {
		cout << "\n[<>]Khong co ket qua tim kiem phu hop";
	}
} //checked

void timThongTinTheoGioiTinh(int timduoc[], int &soNguoi) {
	cout << "\n Nhap gioi tinh can tim(1 = nam / 0 = nu): ";
	int gioi;
	soNguoi = 0;
	cin >> gioi;
	while (gioi > 1 || gioi < 0 || cin.fail() == true) {
		cin.clear();
		cin.ignore();
		cout << "\n[<>]Gioi tinh khong xac dinh xin vui long nhap lai:";
		cin >> gioi;
	}
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetGioi() == gioi) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	if (soNguoi == 0) {
		cout << "\n[<>]Khong co ket qua tim kiem phu hop";
	}

} //checked chưa kiểm tra nếu nhập số 

void timThongTinTheoNamSinh(int timduoc[], int &soNguoi) {
	int a;
	soNguoi = 0;
	cout << "\nNhap nam sinh:";
	cin >> a;
	while (a > 2018 && a < 1800 || cin.fail() == true) {
		cin.clear();
		cin.ignore();
		cout << "\n[<>]Nam sinh khong hop le xin vui long nhap lai:";
		cin >> a;
	}
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetNgaysinh().nam == a) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	if (soNguoi == 0) {
		cout << "\n[<>]Khong co ket qua tim kiem phu hop" << endl;
	}
} //checked

int demsoluong(int i)
{
	int ans = 0;
	for (int j = 0; j < nguoi.size(); j++)
	{
		if (nguoi[j].GetQuequan() == nguoi[i].GetQuequan())
		{
			ans++;
			dd[j] = 1;
		}
	}
	return ans;
}

void intable()
{
	int dem = 0;
	cout << "_______________________________________________________" << endl;
	cout << "|  STT |            Que quan               |  So luong | " << endl;
	cout << "|______|___________________________________|___________|" << endl;

	for (int i = 0; i < nguoi.size(); i++)
	{
		if (dd[i] == 0)
		{
			dem++;
			cout << "|" << left << setw(6) << dem;
			cout << "|" << left <<setw(35)<<nguoi[i].GetQuequan();
			cout << "|   " << left << setw(7) << demsoluong(i);
			cout << "|" << left << setw(9) << endl;
		}
	}
}


void timTheoSoPhong(int timduoc[], int &soNguoi) {   //ham nay chi show thong tin cua nguoi o trong phong "a"
	system("cls");
	int a;
	soNguoi = 0;
	cout << "\n Nhap so phong ban muon tim nguoi: ";
	cin >> a;
	while (a < 0 || a>10 || cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "\n[<>]Ban da nhap sai. Vui long nhap lai: ";
		cin >> a;
	}
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetsoPhong() == a) {
			showThongTin1Nguoi(nguoi[i], i);
			timduoc[soNguoi] = i + 1;
			soNguoi++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	if (soNguoi == 0) {
		cout << "\n[<>]Khong co ket qua tim kiem phu hop" << endl;
	}
} //checked

void xemThongTinNguoi(int timduoc[], int &soNguoi) {
	cout << "\n========================================";
	cout << "\n|           BAN MUON TIM THEO          |";
	cout << "\n|======================================|";
	cout << "\n|        1.Tim theo ten                |";    // checked xong.
	cout << "\n|        2.Tim theo gioi tinh          |";    // chưa check
	cout << "\n|        3.Tim theo CMND               |";    //checked
	cout << "\n|        4.Tim theo nam sinh           |";     //checked
	cout << "\n|        5.Tim theo so phong           |";
	cout << "\n|        6.Quay lai menu               |";
	cout << "\n========================================";
	cout << "\n|   Xin hay nhap lua chon cua ban...   |";
	cout << "\n========================================" << endl;

	int luachon;
	soNguoi = 0;
	cin >> luachon;
	while (luachon < 0 || luachon>6) {
		cout << "\Ban da nhap sai lua chon. Vui long nhap lai (1,2,3,4,5,6): ";
		cin >> luachon;
	}
	switch (luachon) {
	case 1:
		system("cls");
		timThongTinTheoTen(timduoc, soNguoi);
		break;
	case 2:
		system("cls");
		timThongTinTheoGioiTinh(timduoc, soNguoi);
		break;
	case 3:
		system("cls");
		timThongTinTheoCMND(timduoc, soNguoi);
		break;
	case 4:
		system("cls");
		timThongTinTheoNamSinh(timduoc, soNguoi);
		break;
	case 5:
		system("cls");
		timTheoSoPhong(timduoc, soNguoi);
		break;
	case 6:thoat();
	}
}//chạy rất tốt
//===========================================================================================================================

void themNguoi()
{
	system("cls");
	Nguoi person;
	char Ten[35];
	birth Ngaysinh;
	int Gioi;			//0 là Nữ, 1 là Nam
	char Quequan[35];
	char CMND[20];
	int soPhong;
	bool kt = false;
	int ngaymax;
	while (kt == false)
	{
		cout << "\nNhap vao so phong:";
		cin >> soPhong;
		kt = true;
		if ((soPhong > 11) || (soPhong < 1) || cin.fail() == true)
		{
			cin.clear();
			cin.ignore();
			cout << "\n[<>]So phong khong hop le xin vui long nhap lai!" << endl;
			kt = false;
		}
		if (checkphong(soPhong) >= 4) {
			kt = false;
			cout << "[<>]So phong da day xin nhap phong khac" << endl;
		}
	}
	kt = false;
	nhatro[soPhong].SetsoNguoi(nhatro[soPhong].GetsoNguoi() + 1);
	while (kt == false)
	{
		cin.ignore();
		cout << "Nhap ten: ";
		cin.getline(Ten, 35); cin.ignore(0);
		Ten[0] = toupper(Ten[0]);
		for (int i = 1; i < 35; i++)
		{
			if (Ten[i - 1] == ' ')
			{
				Ten[i] = toupper(Ten[i]);              //kiểm tra chính tả, chữ hoa chữ thường tên
			}
			else
			{
				Ten[i] = tolower(Ten[i]);
			}
		}
		kt = true;
		for (int i = 0; i < 35; i++) if ((Ten[i] >= '0') && (Ten[i] <= '9')) kt = false; //kiểm tra có số hay không
		if (kt == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
	}
	kt = false;
	while (kt == false)
	{
		cout << "Nhap ngay sinh:";
		cin >> Ngaysinh.ngay; cin.ignore();
		while (cin.fail() == true) {
			cout << "Nhap lai ngay sinh:";
			cin.clear();
			cin.ignore();
			cin >> Ngaysinh.ngay;
		}
		cout << "Nhap thang sinh:";
		cin >> Ngaysinh.thang; cin.ignore();
		while (cin.fail() == true) {
			cout << "Nhap lai thang sinh:";
			cin.clear();
			cin.ignore();
			cin >> Ngaysinh.thang;
		}
		cout << "Nhap nam sinh:";
		cin >> Ngaysinh.nam;
		cin.ignore(1);
		while (cin.fail() == true) {
			cout << "Nhap lai nam sinh:";
			cin.clear();
			cin.ignore();
			cin >> Ngaysinh.nam;
		}
		kt = true;
		if (Ngaysinh.nam <= 1800 || Ngaysinh.nam > 2018 || Ngaysinh.thang <= 0 || Ngaysinh.thang > 12 || Ngaysinh.ngay <= 0 || Ngaysinh.ngay > 31)
		{
			kt = false; cout << "[<>]Khong hop le!.Vui long nhap lai" << endl;
		}
		else
		{
			switch (Ngaysinh.thang)
			{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				ngaymax = 31;
				break;
			case 2:
				if ((Ngaysinh.nam % 4 == 0 && Ngaysinh.nam % 100 != 0) || (Ngaysinh.nam % 400 == 0))
					ngaymax = 29;
				else
					ngaymax = 28;
				break;
			case 4:
			case 6:
			case 9:
			case 11:
				ngaymax = 30;
				break;
			}
			if (Ngaysinh.ngay <= ngaymax)
			{
				kt = true;
			}
			else
			{
				kt = false;
				cout << "[<>]Khong hop le! Vui long nhap lai." << endl;
			}
		}
	}
	cout << "Nhap Gioi(Nam 1, Nu 0): ";
	cin >> Gioi;
	while ((Gioi > 1) || (Gioi < 0) || cin.fail() == true)
	{
		cin.clear();
		cin.ignore();
		cout << "[<>]Khong hop le. Vui long nhap lai: " << endl;
		cin >> Gioi;
	}
	cin.ignore();
	kt = false;
	while (kt == false)
	{
		cout << "Nhap que quan:";
		cin.getline(Quequan, 35);
		cin.ignore(0);
		Quequan[0] = toupper(Quequan[0]);
		for (int i = 1; i < 35; i++)
		{
			if (Quequan[i - 1] == ' ')
			{
				Quequan[i] = toupper(Quequan[i]);              //kiểm tra chính tả, chữ hoa chữ thường quê quán
			}
			else
			{
				Quequan[i] = tolower(Quequan[i]);
			}
		}
		kt = true;
		for (int i = 0; i < 35; i++) if ((Quequan[i] >= '0') && (Quequan[i] <= '9')) kt = false; //kiểm tra có số hay không
		if (kt == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
	}
	kt = false;
	while (kt == false)
	{
		cout << "Nhap CMND:";
		cin >> CMND;
		cin.ignore(0);
		kt = true;
		for (int i = 0; i < 12; i++) if ((CMND[i] >= 'A') && (CMND[i] <= 'z')) kt = false; //kiểm tra có số hay không
		if ((strlen(CMND) != 9))
		{
			kt = false;
		}
		for (int i = 0; i < nguoi.size(); i++) {
			if (nguoi[i].GetCMND() == CMND) {
				kt = false;
			}
		}
		if (kt == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
	}
	person.SetTen(Ten);
	person.SetGioi(Gioi);
	person.SetCMND(CMND);
	person.SetNgaysinh(Ngaysinh);
	person.SetsoPhong(soPhong);
	person.SetQuequan(Quequan);
	nguoi.push_back(person);
	cout << "Da nhap thong tin xong. Nhap tiep? (Y/N): ";
	char c;
	cin.ignore(0);
	cin >> c; cin.ignore(1);
	/*while ((c != 'Y') || (c != 'y') || (c != 'N') || (c != 'n'))
	{
		cin >> c;
	}   */
	if ((c == 'Y') || (c == 'y'))
	{
		themNguoi();

	}
	else
	{
		xuatFile();
		xuatFilePhong();
		sapxepTheoTen();
		cout << "Ban da hoan thanh viec nhap thong tin!" << endl;
		system("pause");
		//exit(0);
	}

}

//void xoaNguoi(int timduoc[], int soNguoi) {
//	/*int muonxoa;
//	int luachon[40];
//	int luaxoa[40];  //lua stt nguoi muon xoa
//	cout << "\nBan muon xoa bao nhieu nguoi? ";
//	cin >> muonxoa;
//	while (cin.fail() || muonxoa > soNguoi) {
//		cout << "\nBan da nhap sai hoac sai so luong co the xoa ! Vui long nhap lai.";
//		cin.clear();
//		cin.ignore();
//		cin >> muonxoa;
//	}
//	for (int i = 1; i <= muonxoa; i++) {
//		cout << "Nhap stt nguoi thu " << i << " :";
//		cin >> luaxoa[i];
//	}
//	sort(luaxoa + 0, luaxoa + 39);
//	for (int kk = 0; kk < muonxoa; kk++)
//	{
//		for (int b = 1; b <= muonxoa; b++) {
//			cout << "\nNhap STT nguoi thu " << b << " muon xoa :";
//			cin.ignore(0);
//			cin >> luachon[b];
//			int k = luachon[b];
//			bool kt = false;
//			while (kt == false) {
//				for (int c = 0; c <= soNguoi; c++) {
//					if (k + 1 == timduoc[c]) {
//						cout << "\nBan co chac chan muon xoa nguoi co STT la " << k << " khong? [Y/N] ";
//						char ktr;
//						cin >> ktr;
//						while (ktr != 'y' && ktr != 'n'&& ktr != 'Y' && ktr != 'N') {
//							cout << "\nBan da nhap sai lua chon! Vui long nhap lai. [Y/N] ";
//							cin >> ktr;
//						}
//						if (ktr == 'y' || ktr == 'Y')
//						{
//							int m = nguoi[k].GetsoPhong();
//							nhatro[m].SetsoNguoi(nhatro[m].GetsoNguoi() - 1);
//							nguoi.erase(nguoi.begin() + k);
//							xuatFile();
//							xuatFilePhong();
//							cout << "\nNguoi nay da bi xoa!";
//							kt = true;
//						}
//					}
//				}
//				if (kt == false) {
//					cout << "\nBan da nhap sai STT."; b--;
//				}
//			}
//		}
//		xuatFile();
//		xuatFilePhong();
//	}
//	for (int i = 0; i < 15; i++) cout << timduoc[i] << " "; cout << endl;
//	cout << "\nBan muon:";
//	cout << "\n1.Xoa nguoi khac.";
//	cout << "\n2.Thoat xoa.";
//	int a;
//	cin >> a;
//	while (cin.fail() || a < 1 || a>2) {
//		cout << "\nVui long nhap lai lua chon!";
//		cin.clear();
//		cin.ignore();
//		cin >> a;
//	}
//	if (a == 1) menuXoaNguoi();
//	if (a == 2) thoat();*/
//	/*int h;
//
//
//	cout << "Nhap so phong muon xoa !";
//	cin >> h;
//	char luachon = 'y';
//	int stt;
//	do {
//		xoaManHinh();
//		timTheoSoPhong2(h);
//		cout << "Nhap stt nguoi muon xoa: ";
//		cin >> stt;
//		for (int m = 0; m < 4; m++) {
//
//		}
//		cout << "\nBan co chac chan xoa nguoi co stt " << stt << " ? [Y/N]";
//		char k;
//		cin >> k;
//		if (k == 'y' || k == 'Y') {
//			int m = nguoi[stt].GetsoPhong();
//			nhatro[m].SetsoNguoi(nhatro[m].GetsoNguoi() - 1);
//			nguoi.erase(nguoi.begin() + stt);
//			xuatFile();
//			xuatFilePhong();
//		}
//		system("cls");
//		timTheoSoPhong2(h);
//		cout << "\nBan co muon xoa tiep hay khong? [Y/N]";
//		cin.ignore();
//
//		cin >> luachon;
//	} while (luachon == 'Y' || luachon == 'y');*/
//}

void menuXoaNguoi() {
	int k;
	int stt;
	char ktr;
	char luachon = 'y';
	do {
		system("cls");
		cout << "\nNhap so phong ban muon xoa hoac nhap 0 de thoat chuong trinh: ";
		cin >> k;
		while (k < 0 || k>10 || cin.fail()) {
			cin.clear();
			cin.ignore();
			cout << "\n[<>]Ban da nhap sai. Vui long nhap lai: ";
			cin >> k;
		}
		if (k == 0) menuThemXoaNguoi();
		timTheoSoPhong2(k, timduoc, soNguoi);
		if (soNguoi == 0) {
			cout << "\nKhong co ai de xoa! Ban muon: ";
			cout << "\n1.Nhap lai.";
			cout << "\n2.Quay ve.";
			int k2;
			cin >> k2;
			if (k2 == 1) menuXoaNguoi();
			if (k2 == 2) menuThemXoaNguoi();
		}
		cout << "\nNhap stt nguoi muon xoa: ";
		cin >> stt;
		for (int c = 0; c <= soNguoi; c++) {
			if (stt + 1 == timduoc[c]) {
				do {
					cout << "\nBan co chac chan muon xoa nguoi co STT la " << stt << " khong? [Y/N] ";
					cin >> ktr;
					while (ktr != 'y' && ktr != 'n'&& ktr != 'Y' && ktr != 'N') {
						cout << "\nBan da nhap sai lua chon! Vui long nhap lai. [Y/N] ";
						cin >> ktr;
					}
					if (ktr == 'y' || ktr == 'Y')
					{
						nhatro[k].SetsoNguoi(nhatro[k].GetsoNguoi() - 1);
						nguoi.erase(nguoi.begin() + stt);
						xuatFile();
						xuatFilePhong();
						cout << "\nNguoi nay da bi xoa!";
					}
					if (ktr == 'N' || ktr == 'n') {
						cout << "\n1.Nhap lai stt.";
						cout << "\n2.Quay lai menu.";
						cout << "\nNhap lua chon: ";
						int luachon3;
						cin >> luachon3;
						if (luachon3 == 1) {
							cout << "\nNhap stt nguoi muon xoa: ";
							cin >> stt;
						}
						if (luachon3 == 2) menuThemXoaNguoi();
					}
				} while (ktr == 'N' || ktr == 'n');
			}
		}
		system("cls");
		timTheoSoPhong2(k, timduoc, soNguoi);
		cout << "\nBan co muon xoa tiep? [Y/N]";
		cin.ignore();
		cin >> luachon;
	} while (luachon == 'y' || luachon == 'Y');
}  //checked

void menuThemXoaNguoi() {
	system("cls");
	int luachon;

	cout << "\n========================================";
	cout << "\n|           THEM, XOA NGUOI            |";
	cout << "\n|======================================|";
	cout << "\n|        1.Xoa nguoi                   |";    // checked xong.
	cout << "\n|        2.Them nguoi                  |";    // chưa check
	cout << "\n|        3.Quay lai menu               |";    //checked
	cout << "\n========================================";
	cout << "\n|   Xin hay nhap lua chon cua ban...   |";
	cout << "\n========================================" << endl;

	cin >> luachon;
	while (luachon < 1 || luachon>3) {
		cout << "\nBan da nhap sai lua chon. Vui long nhap lai (1,2,3): ";
		cin >> luachon;
	}
	if (luachon == 1) {
		system("cls");
		menuXoaNguoi();
	}
	if (luachon == 2) {
		int them = 0;
		system("cls");
		themNguoi();
	}
	system("cls");
	cout << "Ban co muon tiep tuc xoa,them nguoi hay khong? ";
	cout << "\n1.Tiep tuc.";
	cout << "\n2.Thoat.\n";
	int m;
	cin >> m;
	bool h = true;
	if (m != 1 && m != 2) h = false;
	while (h == false) {
		cout << "\nNhap sai,nhap lai:";
		cin >> m;
		if (m != 1 && m != 2) h = false;
		else h = true;
	}
	if (m == 1) menuThemXoaNguoi();
	if (m == 2)thoat();
} //checked
//==========================================================================================================================

void chinhSuaThongTin() {
	cout << "\n========================================";
	cout << "\n|         CHINH SUA THONG TIN          |";
	cout << "\n========================================";
	cout << "\n|       1.Chinh sua thong tin nguoi.   |";
	cout << "\n|       2.Chinh sua thong tin phong.   |";
	cout << "\n|       3.Quay lai menu.               |";
	cout << "\n========================================";
	int luachon;
	cout << "\nNhap lua chon cua ban :";
	cin >> luachon;
	while (luachon < 1 || luachon>3) {
		cout << "Ban da nhap sai lua chon. Vui long nhap lai (1,2): ";
		cin >> luachon;
	}
	if (luachon == 1) {
		xoaManHinh();
		chinhSuaThongTinNguoi();
		xuatFile();
	}
	if (luachon == 2) {
		xoaManHinh();
		chinhSuaThongTinPhong();
	}
	else thoat();
}

void chinhsuathanhcong(vector <Nguoi> nguoii, int poss[4], int sttt, int SoPhong) {
	system("cls");
	cout << "Chinh sua thanh cong!\n";
	cout << "Thong tin ve nguoi da chinh sua:\n";
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";

	showThongTin1Nguoi(nguoi[sttt], sttt);
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	int choonlua = 0;
	cout << "\nBan co muon chinh sua nua khong ? Neu muon chinh sua tiep thi chon 1, chon 0 ban se duoc ve Menu Chinh Sua.\n";
	cout << "Nhap vao day:"; cin >> choonlua; cin.ignore(); cin.clear();
	if (choonlua) {
		system("cls");
		chinhSuaThongTinNguoi();
	}
	else {
		system("cls");
		chinhSuaThongTin();
	}
};

void chinhSuaThongTinPhong() {
	int phongso = 0;
	int menu = 0;
	int tmp = 0;
	cout << "Chon phong muon sua (hoac nhap so 0 de tro ve):";
	cin >> phongso;
	while (cin.fail() == true || phongso > 10 || phongso < 0) {
		cout << "Ban nhap so phong khong hop le, vui long nhap lai.";
		cin.clear();
		cin.ignore();
		cin >> phongso;
	}
	if (phongso == 0)
	{
		system("cls");
		chinhSuaThongTin();
	}

	system("cls");
	cout << "**Phong so:" << phongso << "\n";
	cout << "1.Chi So Nuoc Cu\n2.Chi So Nuoc Moi\n3.Chi So Dien Cu\n4.Chi So Dien Moi\n5.He So Nuoc\n6.He So Dien\nHoac nhap 0 de ve menu truoc\n";
	cout << "Chon thong so can sua:";
	cin >> menu;
	switch (menu) {
	case 0: {
		system("cls");
		chinhSuaThongTin();
		break;
	}
	case 1: {
		cout << "Thong so cu:" << nhatro[phongso].GetsoNuocCu() << '\n';    //không cần  -1 vì bắt đầu đếm từ 1
		cout << "\nNhap chi so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban nhap khong hop le, vui long nhap lai.\n";  //sao while lại còn if?
			cin.clear();
			cin.ignore();
			cin >> tmp;
		};
		nhatro[phongso].SetsoNuocCu(tmp);
		break;
	}
	case 2: {
		cout << "Thong so cu:" << nhatro[phongso].GetsoNuocMoi() << '\n';  //sai
		cout << "Nhap thong so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban vua nhap khong hop le, vui long nhap lai.\n";
			cin.clear();
			cin.ignore();
			cin >> tmp;
		}
		nhatro[phongso].SetsoNuocMoi(tmp);
		break;
	}
	case 3: {
		cout << "Thong so cu:" << nhatro[phongso].GetsoDienCu() << '\n';
		cout << "Nhap thong so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban vua nhap khong hop le, vui long nhap lai.\n";
			cin.clear();
			cin.ignore();
			cin >> tmp;
		}
		nhatro[phongso].SetsoDienCu(tmp);
		break;
	}
	case 4: {
		cout << "Thong so cu:" << nhatro[phongso].GetsoDienMoi() << '\n';
		cout << "Nhap thong so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban vua nhap khong hop le, vui long nhap lai.\n";
			cin.clear();
			cin.ignore();
			cin >> tmp;
		}
		nhatro[phongso].SetsoDienMoi(tmp);
		break;
	}
	case 5: {
		cout << "Thong so cu:" << nhatro[phongso].GetheSoNuoc() << '\n';
		cout << "Nhap thong so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban vua nhap khong hop le, vui long nhap lai.\n";
			cin.clear();
			cin.ignore();
			cin >> tmp;
		}
		nhatro[phongso].SetheSoNuoc(tmp);
		break;
	}
	case 6: {
		cout << "Thong so cu:" << nhatro[phongso].GetheSoDien() << '\n';
		cout << "Nhap thong so moi:";
		cin >> tmp;
		while (!tmp) {
			cout << "Gia tri ban vua nhap khong hop le, vui long nhap lai.\n";
			cin.clear();
			cin.ignore();
			cin >> tmp;
		}
		nhatro[phongso].SetheSoDien(tmp);
		break;
	}
	default: {}
	};
	xuatFilePhong();
	if (tmp != 0) {
		system("cls");
		cout << "\nBan muon chinh sua tiep hay thoat? ";
		cout << "\n1.Chinh sua tiep.";
		cout << "\n2.Thoat.\n";
		int m;
		cin >> m;
		while (cin.fail()) {
			cout << "\nBan nhap co ki tu !";
			cin.clear();
			cin.ignore();
			cin >> m;
		}
		if (m == 1) chinhSuaThongTinPhong();
		else thoat();
	}
}

void chinhSuaThongTinNguoi()
{
	int SoPhong; int i = 0; string stt; int ttn = 0, pos[4]; int j = 0;
	cout << "\nNhap vao so phong ma nguoi can chinh sua dang o:"; cin >> SoPhong; cin.ignore();
	while (SoPhong < 1 || SoPhong>10) {
		cout << "\nSo phong khong hop le, vui long nhap lai hoac nhap 0 de thoat.";
		cin >> SoPhong; cin.ignore();
		if (SoPhong == 0)
		{
			system("cls");
			chinhSuaThongTin();
		}
	};
	cout << "\nThong tin so nguoi trong phong" << endl;
	cout << "________________________________________________________________________________________________" << endl;
	cout << "| ID |         Ten            |Gioi tinh|  Ngay sinh  |    Que quan    |     CMND   | So phong |" << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|";
	bool ktnguoi = false;
	for (int i = 0; i < nguoi.size(); i++) {
		if (nguoi[i].GetsoPhong() == SoPhong) {
			ktnguoi = true;
		}
	}
	if (ktnguoi == false) {
		cout << "\nKhong co nguoi nao trong phong!!!";
		system("pause");
		system("cls");
		chinhSuaThongTin();
	}
	int loops = 0;
	for (i = 0; i < nguoi.size(); i++) { //loops<5 nghia la so nguoi toi da trong phong la 4 nguoi
		if (nguoi[i].GetsoPhong() == SoPhong) {
			showThongTin1Nguoi(nguoi[i], i);
			pos[loops] = i;; loops++; j++;
		}
	}
	cout << endl;
	cout << "|____|________________________|_________|_____________|________________|____________|__________|" << endl;
	cout << "Chon nguoi muon chinh sua:";
	getline(cin, stt);
	if (stt == "n") {
		system("cls"); chinhSuaThongTin();
	}
	int stt2 = 0;
	if (stt[1] != 0) {
		stt2 = (stt[0] - '0') * 10 + (stt[1] - '0');
	}
	else stt2 = stt[0] - '0';
	bool kt = false;
	while (kt == false) {
		for (int h = 0; h < 4; h++) {
			if ((stt2) == pos[h]) {
				kt = true;
			}
		}
		if (kt == false) {
			cout << "\nBan da nhap sai ! Vui long nhap lai: ";
			cin >> stt2;
		}
	}
	cout << "Chinh sua thong tin nguoi:\n";
	cout << "1.Ten: " << nguoi[stt2].GetTen() << endl;
	cout << "2.Ngay sinh: " << nguoi[stt2].GetNgaysinh().ngay << "/" << nguoi[stt2].GetNgaysinh().thang << "/" << nguoi[stt2].GetNgaysinh().nam << endl;
	cout << "3.Gioi tinh: " << gioitinh(stt2) << endl;
	cout << "4.Que quan: " << nguoi[stt2].GetQuequan() << endl;
	cout << "5.CMND :" << nguoi[stt2].GetCMND() << endl;
	cout << "6.So phong: " << nguoi[stt2].GetsoPhong() << endl;
	//cout << setw(3) << "1." << "Ten" << endl << setw(3) << "2." 
	//<< "Ngay sinh/Thang sinh/Nam sinh" << endl << setw(3) << "3." << "Gioi tinh" << endl << setw(3) << 
		//"4." << "Que quan" << endl << setw(3) << "5." << "CMND" << endl << setw(3) << "6." << "So phong hoac nhap bat ki de quay lai.\n";
	cout << "Thong tin can chinh sua: ";
	cin >> ttn;
	while (ttn < 1 || ttn > 7) {
		cout << "So nhap vao khong hop le, vui long nhap lai.\n";
		cin >> ttn;
	}
	switch (ttn) {
	case 1: {
		bool ktr = false;
		char ng[35];
		while (ktr == false)
		{
			/*for (int i = 0; i < 35; i++) {
				ng[i] = ' ';
			}*/
			cout << "\nNhap ten moi:";
			cin.ignore();
			cin.getline(ng, 35);
			ng[0] = toupper(ng[0]);
			for (int i = 1; i < 35; i++)
			{
				if (ng[i - 1] == ' ')
				{
					ng[i] = toupper(ng[i]);              //kiểm tra chính tả, chữ hoa chữ thường tên
				}
				else
				{
					ng[i] = tolower(ng[i]);
				}
			}
			ktr = true;
			for (int i = 0; i < 35; i++) if ((ng[i] >= '0') && (ng[i] <= '9')) ktr = false; //kiểm tra có số hay không
			if (ktr == false) cout << "\n[<>]Khong hop le!. Vui long nhap lai" << endl;
		}
		nguoi[stt2].SetTen(ng);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	case 2: {
		cout << "Hay nhap ngay thang nam sinh moi, moi thong tin cach nhau 1 dau cach:";
		int ngAy, thAng, naM;
		cin.ignore();
		cin >> ngAy >> thAng >> naM;
		while (cin.fail() == true) {
			cout << "Nhap lai ngay sinh:";
			cin.clear();
			cin.ignore();
			cin >> ngAy >> thAng >> naM;
		}
		while (naM >= 2018 || naM <= 1900) {
			cout << "\nNam khong hop le, vui long nhap lai.";
			cin >> naM; cin.ignore();
		};
		while (naM >= 2018 || naM <= 1900) {
			switch (thAng) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
			{
				do {
					if (ngAy <= 0 || ngAy >= 32) cout << "So ngay khong hop le, vui long nhap lai.\n";
					cin >> ngAy; cin.clear(); cin.ignore();
				} while (ngAy <= 0 || ngAy >= 32);
				break;
			}
			case 2: {
				do {
					if ((ngAy <= 0 || ngAy >= 29) && naM % 4 != 0) {
						cout << "So ngay khong hop le, vui long nhap lai.\n";
						cin >> ngAy; cin.clear(); cin.ignore();
					}
					if ((ngAy <= 0 || ngAy >= 30) && naM % 4 == 0) {
						cout << "So ngay khong hop le, vui long nhap lai.\n";
						cin >> ngAy; cin.clear(); cin.ignore();
					}
				} while (((ngAy <= 0 || ngAy >= 29) && naM % 4 != 0) || ((ngAy <= 0 || ngAy >= 30) && naM % 4 == 0));
				break;
			}
			case 4:
			case 9:
			case 6:
			case 11: {
				do {
					if (ngAy <= 0 || ngAy >= 31) {
						cout << "So ngay khong hop le, vui long nhap lai.\n";
						cin >> ngAy; cin.clear(); cin.ignore();
					}
				} while (ngAy <= 0 || ngAy >= 31);
				break;
			}
			default: {
				do {
					cout << "So thang khong hop le, vui long nhap lai.\n";
					cin >> thAng; cin.clear(); cin.ignore();
				} while (thAng < 1 || thAng>12);
			}
			}
		};
		birth birth1;
		birth1.nam = naM; birth1.thang = thAng; birth1.ngay = ngAy;
		nguoi[stt2].SetNgaysinh(birth1);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	case 3: {
		cout << "\nNhap gioi tinh moi(0 la Nu, 1 la Nam):";
		int tinhgioi; cin >> tinhgioi;
		while (cin.fail() == true) {
			cout << "\Ban da nhap sai ! Moi nhap lai ngay sinh:";
			cin.clear();
			cin.ignore();
			cin >> tinhgioi;
		}
		nguoi[stt2].SetGioi(tinhgioi);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	case 4: {
		char ctry[35];
		bool kt = false;
		while (kt == false)
		{
			/*for (int i = 0; i < 35; i++) {
				ctry[i] = ' ';
			}*/
			cout << "\nNhap que quan moi:";
			cin.ignore();
			cin.getline(ctry, 35);;
			ctry[0] = toupper(ctry[0]);
			for (int i = 1; i < 35; i++)
			{
				if (ctry[i - 1] == ' ')
				{
					ctry[i] = toupper(ctry[i]);              //kiểm tra chính tả, chữ hoa chữ thường tên
				}
				else
				{
					ctry[i] = tolower(ctry[i]);
				}
			}
			kt = true;
			for (int i = 0; i < 35; i++) if ((ctry[i] >= '0') && (ctry[i] <= '9')) kt = false; //kiểm tra có số hay không
			if (kt == false) cout << "[<>]Khong hop le!. Vui long nhap lai" << endl;
		}
		nguoi[stt2].SetQuequan(ctry);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	case 5: {
		char cmnd[12];
		bool kt = false;
		while (kt == false) {
			cout << "Nhap CMND moi:";
			//cin.clear();
			cin.ignore();
			cin.getline(cmnd, 12);
			kt = true;
			for (int i = 0; i < 12; i++) {
				if ((cmnd[i] >= 'A') && (cmnd[i] <= 'z')) kt = false;
			}//kiểm tra có số hay không
			for (int i = 0; i < nguoi.size(); i++) {
				if (nguoi[i].GetCMND() == cmnd) {
					cout << "\nCMND ban da nhap da trung voi nguoi khac";
					kt = false;
				}
			}
			if (kt == false) cout << "Ban nhap gia tri khong hop le. Vui long nhap lai." << endl;
		}
		nguoi[stt2].SetCMND(cmnd);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	case 6: {

		int sp = 0, max = 0;;
		do {
			cout << "Nhap so phong moi cho nguoi nay:";
			cin >> sp;
			while (cin.fail() == true) {
				cout << "So phong moi vua nhap khong hop le, vui long nhap lai.\n";
				cin.clear();
				cin.ignore();
				cin >> sp;
			}
			if (!sp || sp > 10) cout << "So phong moi vua nhap khong hop le, vui long nhap lai.\n"; cin.clear(); cin.ignore();
		} while (!sp || sp > 10);
		nguoi[stt2].SetsoPhong(sp);
		xuatFile();
		chinhsuathanhcong(nguoi, pos, stt2, SoPhong);
		break;
	}
	default:
		chinhSuaThongTinNguoi();
	};
};//check ok, trừ cái giao diện
//======================================================================================================================================

void tinhTienDien(int luachon, int &sotiendien) {
	int sodienmoi = 0;
	int sodiencu = 0;
	cout << "\n So dien cu: " << nhatro[luachon].GetsoDienCu();
	sodiencu = nhatro[luachon].GetsoDienCu();
	cout << "\nNhap so dien moi: ";
	cin >> sodienmoi;
	nhatro[luachon].SetsoDienCu(nhatro[luachon].GetsoDienMoi());  //so dien cua thang truoc se thanh so dien cu
	nhatro[luachon].SetsoDienMoi(sodienmoi);                              //so dien cua thang moi se thanh so dien moi
	cout << "So dien ban vua moi nhap la: " << sodienmoi;
	bool kt = false;
	while (kt == false) {
		cout << "\nBan co muon nhap lai khong? [Y/N]";
		char luachon_3;
		cin.ignore();
		cin >> luachon_3;
		while (cin.fail() || (luachon_3 != 'n'&&luachon_3 != 'N'&&luachon_3 != 'y'&&luachon_3 != 'Y')) {
			cout << "\nLua chon sai ! Vui long chon lai.[Y/N]";
			cin.clear();
			cin.ignore();
			cin >> luachon_3;
		}
		if (luachon_3 == 'n' || luachon_3 == 'N') {
			kt = true;
			cout << "\nSo tien dien thang moi cua phong " << luachon << " la : " << (sodienmoi - sodiencu)*nhatro[luachon].GetheSoDien();
			sotiendien = (sodienmoi - sodiencu)*nhatro[luachon].GetheSoDien();
		}
		if (luachon_3 == 'y' || luachon_3 == 'Y') {
			cout << "\nMoi ban nhap lai so dien: ";
			cin >> sodienmoi;
		}
	}
}


void tinhTienNuoc(int luachon, int &sotiennuoc) {
	int sonuocmoi = 0;
	int sonuoccu = 0;
	cout << "\n So nuoc cu: " << nhatro[luachon].GetsoNuocCu();
	sonuoccu = nhatro[luachon].GetsoNuocCu();
	cout << "\nNhap so nuoc moi: ";
	cin >> sonuocmoi;
	nhatro[luachon].SetsoNuocCu(nhatro[luachon].GetsoNuocMoi());  //so nuoc cua thang truoc se thanh so nuoc cu
	nhatro[luachon].SetsoNuocMoi(sonuocmoi);                              //so nuoc cua thang moi se thanh so nuoc mo
	cout << "So nuoc ban vua moi nhap la: " << sonuocmoi;
	bool kt = false;
	while (kt == false) {
		cout << "\nBan co muon nhap lai khong? [Y/N]";
		char luachon_3;
		cin.ignore();
		cin >> luachon_3;
		while (cin.fail() || (luachon_3 != 'n'&&luachon_3 != 'N'&&luachon_3 != 'y'&&luachon_3 != 'Y')) {
			cout << "\nLua chon sai ! Vui long chon lai.[Y/N]";
			cin.clear();
			cin.ignore();
			cin >> luachon_3;
		}
		if (luachon_3 == 'n' || luachon_3 == 'N') {
			cout << "\nSo tien nuoc thang moi cua phong " << luachon << " la : " << (sonuocmoi - sonuoccu)*nhatro[luachon].GetheSoNuoc();
			sotiennuoc = (sonuocmoi - sonuoccu)*nhatro[luachon].GetheSoNuoc();
			kt = true;
		}
		if (luachon_3 == 'y' || luachon_3 == 'Y') {
			cout << "\nMoi ban nhap lai so nuoc: ";
			cin >> sonuocmoi;
		}
	}
}



void tinhTongTien() {
	//system("cls");
	int luachon;
	int tiendien = 0;
	int tiennuoc = 0;;
	int luachon_2;
	cout << "\n=========================================";
	cout << "\n|               TINH TIEN               |";
	cout << "\n=========================================" << endl;
	do {
		showDanhSachPhong();
		cout << "\nNhap 0 neu muon thoat.";
		cout << "\nNhap so phong muon tinh: ";
		cin >> luachon;
		if (luachon == 0) thoat();
		while (cin.fail() || luachon < 0 || luachon>10) {
			cout << "\nBan da nhap sai so phong! Vui long nhap lai!";
			cin.clear();
			cin.ignore();
			cin >> luachon;
		}
		while (nhatro[luachon].GetsoNguoi() == 0) {
			cout << "\nPhong khong co nguoi o. Vui long chon phong co nguoi de tinh !";
			cin >> luachon;
		}
		cout << "\n========================================";
		cout << "\n|            TINH TIEN DIEN            |";
		cout << "\n========================================";
		tinhTienDien(luachon, tiendien);
		cout << "\n========================================";
		cout << "\n|            TINH TIEN NUOC            |";
		cout << "\n========================================";
		tinhTienNuoc(luachon, tiennuoc);
		//2 hàm trên có chức năng in ra số điện, nước cũ, nhập vào điện nước mới, và trả lại giá tiền
		//lưu ý khi nhập điện và nước mới thì lưu số trước đó ở biến tiền điện mới về biến tiền điện cũ. Rồi mới set giá trị mới vào số điện/nước mới.
		cout << "\nTong tien cua phong " << luachon << " la: " << (tiendien + tiennuoc);
		cout << "\nBan co muon tiep tuc tinh tien khong?";
		cout << "\n1.Co";
		cout << "\n2.Khong.";
		cout << "\nVui long chon: ";
		cin >> luachon_2;
	} while (luachon_2 == 1);
	xuatFilePhong();
	thoat();
}
//================================================================================================================================

void xemThongTinTatCaPhong() {
	//hàm này cho lặp số thứ tự từ đầu đến cuối, truyền số vào hàm timTheoSoPhong(luachon) để in ra cả danh sách
	for (int i = 1; i <= 10; i++) {
		cout << endl;
		cout << "                               THONG TIN CUA PHONG " << i << endl;
		timTheoSoPhong2(i, timduoc, soNguoi);                       //show thong tin nguoi trong phong
		cout << endl;
		showThongTin1Phong(i);                    //show thong tin dien, nuoc,..trong phong
	}
} //checked

void xemThongTin() {
	cout << "\n========================================";
	cout << "\n|             XEM THONG TIN            |";
	cout << "\n|======================================|";
	cout << "\n|        1.Xem thong tin nguoi         |";    // checked xong.
	cout << "\n|        2.Xem thong tin phong cu the  |";    // chưa check
	cout << "\n|        3.Xem thong tin tat ca phong  |";    //checked
	cout << "\n|        4.Quay lai menu               |";     //checked
	cout << "\n========================================";
	cout << "\n|   Xin hay nhap lua chon cua ban...   |";
	cout << "\n========================================" << endl;

	int luachon;
	soNguoi = 0;
	cout << "Nhap lua chon cua ban: ";
	cin >> luachon;
	while (luachon < 1 || luachon>4) {
		cout << "\nBan da nhap sai lua chon. Vui long nhap lai (1,2,3) : ";
		cin >> luachon;
	}
	if (luachon == 1) {
		system("cls");
		xemThongTinNguoi(timduoc, soNguoi);//checked
	}
	if (luachon == 2) {
		system("cls");
		xemPhongCuThe();//checked
	}
	if (luachon == 3) {
		system("cls");
		xemThongTinTatCaPhong();//checked
	}
	system("pause");
	system("cls");
	cout << "\nBan muon xem tiep hay thoat? ";
	cout << "\n1.Xem tiep.";
	cout << "\n2.Thoat.\n";
	int m;
	cin >> m;
	while (cin.fail()) {
		cout << "\nBan nhap co ki tu !";
		cin.clear();
		cin.ignore();
		cin >> m;
	}
	if (m == 1)
	{
		system("cls");
		xemThongTin();
	}
	else thoat();
}

int shutdown() {
	system("cls");
	cout << "\n========================================";
	cout << "\n|        QUAN LY NHA TRO  ver.1        |";
	cout << "\n|======================================|";
	cout << "\n| Lap trinh boi:                       |";    // checked xong.
	cout << "\n|        1.Bui Nhat Duy                |";    // chưa check
	cout << "\n|        2.Do Anh Quan                 |";    //checked
	cout << "\n|        3.Nguyen Hoang Thong          |";     //checked
	cout << "\n|        4.Nguyen Trung Tinh           |";
	cout << "\n|        5.Le Thanh Tuan               |";
	cout << "\n========================================";
	cout << endl;
	system("pause");
	exit(0);
}

void menuChucNang() {
	cout << "\n========================================";
	cout << "\n|           QUAN LY NHA TRO            |";
	cout << "\n|======================================|";
	cout << "\n|        1.Them,xoa nguoi.             |";    // checked xong.
	cout << "\n|        2.Chinh sua thong tin.        |";    // chưa check
	cout << "\n|        3.Xem thong tin.              |";    //checked
	cout << "\n|        4.Tinh tien phong.            |";     //checked
	cout << "\n|        5.Thoat chuong trinh.         |";
	cout << "\n========================================";
	cout << "\n|   Xin hay nhap lua chon cua ban...   |";
	cout << "\n========================================" << endl;
	int luachon;
	cout << "                ";
	cin >> luachon;
	while (luachon < 0 || luachon>5) {
		cout << "\Ban da chon sai. Vui long chon lai (1,2,3,4,5) : ";
		cin >> luachon;
	}
	switch (luachon) {
	case 1:
		xoaManHinh();
		menuThemXoaNguoi();
		break;
	case 2:
		xoaManHinh();
		chinhSuaThongTin();
		break;
	case 3:
		xoaManHinh();
		xemThongTin();
		break;
	case 4:
		xoaManHinh();
		tinhTongTien();
		break;
	case 5: shutdown();
	}
}

int main() {

	//nhaTro();
	nhapFile();
	nhapFilePhong();
	//khoitaonhaTro();
	sapxepTheoTen();
	int timduoc[40];
	//timThongTinTheoGioiTinh(timduoc, soNguoi);
	//menuXoaNguoi();
	//menuChucNang();
	intable();
	//cout << nguoi[nguoi.size() - 1].GetTen();
	/*themNguoi();
	int soNguoi = 0;
	for (int i = 0; i < nguoi.size(); i++) {
		showThongTin1Nguoi(nguoi[i], i);
	}
	for (int i = 1; i <= 11; i++) {
		cout << nhatro[i].GetheSoDien();
		cout << nhatro[i].GetheSoNuoc();
		cout << nhatro[i].GetsoNguoi();
		cout << "\n";
	}*/
	//tinhTongTien();
	//timThongTinTheoTen(timduoc,soNguoi);
	//timThongTinTheoNamSinh(timduoc, soNguoi);
	//xoaNguoi(timduoc, soNguoi);
	//timThongTinTheoCMND(timduoc, soNguoi);
	//timTheoSoPhong(timduoc, soNguoi);
	system("pause");
	return 0;
}