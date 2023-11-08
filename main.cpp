#include <iostream>
#include <string>

using namespace std;

class CanBo{
protected:
    string hoTen;
    int tuoi;
    string gioiTinh;
    string diaChi;

public:
    CanBo(string name, int age, string gender, string adress)
    : hoTen(name), tuoi(age), gioiTinh(gender), diaChi(adress){}

    virtual void hienThi()=0;
    string timTenCanBo(){
        return hoTen;
    }
};

class CongNhan : public CanBo {
public:
    int capBac;
    CongNhan(string name, int age, string gender, string adress, int bac)
    : CanBo(name, age, gender, adress), capBac(bac){}

    void hienThi() override {
    cout << "Cong nhan - " << hoTen << ", Tuoi: " << tuoi << ", Gioi tinh: " << gioiTinh << ", Dia chi: " << diaChi << ", Cap bac:" << capBac << endl;
    }
};

class KySu : public CanBo {
public:
    string nganhDaoTao;
    KySu(string name, int age, string gender, string adress, string nganh)
    : CanBo(name, age, gender, adress), nganhDaoTao(nganh){}

    void hienThi() override {
    cout << "Ky su - " << hoTen << ", Tuoi: " << tuoi << ", Gioi tinh: " << gioiTinh << ", Dia chi: " << diaChi << ", Nganh dao tao: " << nganhDaoTao << endl;
    }
};

class NhanVien : public CanBo {
public:
    string congViec;
    NhanVien(string name, int age, string gender, string adress, string viec)
    : CanBo(name, age, gender, adress), congViec(viec){}

    void hienThi() override {
    cout << "Nhan vien - " << hoTen << ", Tuoi: " << tuoi << ", Gioi tinh: " << gioiTinh << ", Dia chi: " << diaChi << ", Cong viec: " << congViec << endl;
    }
};

class QLCB{
public:
    CanBo** danhSachCanBo;
    int soLuongMax;
    int soChi;
    int timCanBo = 0;

    QLCB(int soMax) : soLuongMax(soMax), soChi(0) {
        danhSachCanBo = new CanBo*[soLuongMax];
    }

    ~QLCB(){
        for( int i=0; i< soLuongMax; i++){
            delete danhSachCanBo[i];
        }
        delete[] danhSachCanBo;
    }

    void themCanBo(CanBo* canBoptr){
        if(soChi < soLuongMax){
            danhSachCanBo[soChi] = canBoptr;
            soChi++;
        }
        else{
            cout << "So luong vuot muc" << endl;
        }
    }

    void timKiem(const string tenCanBo){
        for( int i = 0; i < soLuongMax; i++){
            if (tenCanBo.compare(danhSachCanBo[i]->timTenCanBo())==0){
                timCanBo = 1;
                cout << "Tim thay can bo "<<  tenCanBo << endl;
                danhSachCanBo[i]->hienThi();
                break;
            }
            else if(i = soLuongMax - 1){
                cout << "Sorry he's dead"<< endl;
            }
        }
    }

    void hienThiDanhSach(){
        for( int i = 0; i < soLuongMax; i++){
            danhSachCanBo[i]->hienThi();
        }
    }

    void thoatChuongTrinh(){
        cout << "Okay bye" << endl;
        exit(0);
    }


};

int main()
{
    CongNhan cn1("Faker", 18, "Pan", "North Korea", 3);
    cn1.hienThi();
    KySu ks1("Elon", 40, "Camera", "Alabama", "CEO");
    ks1.hienThi();
    NhanVien nv1("Rizzler", 30, "Male", "Germany", "Nazi");
    nv1.hienThi();
    QLCB ds1(10);
    ds1.themCanBo(&cn1);
    ds1.themCanBo(&ks1);
    ds1.themCanBo(&nv1);
    //ds1.timKiem("Faker");
    ds1.timKiem("Ryu");
    ds1.hienThiDanhSach();
    ds1.thoatChuongTrinh();

    return 0;
}
