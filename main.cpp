#include <iostream>
#include <string>
#include <vector>

class CanBo
{
private:
	std::string hoTen;
	std::string gioiTinh;
	std::string diaChi;
	int tuoi;

public:
	CanBo(std::string hoTen, std::string gioiTinh, std::string diaChi, int tuoi)
		: hoTen(hoTen), gioiTinh(gioiTinh), diaChi(diaChi), tuoi(tuoi) {}
	std::string getHoTen() const
	{
		return hoTen;
	}
	void getThongTin() const
	{
		std::cout << hoTen << " " << gioiTinh << " " << diaChi << " " << tuoi << std::endl;
	}
};

class CongNhan : public CanBo
{
private:
	int capBac;
public:
	CongNhan(std::string hoTen, std::string gioiTinh, std::string diaChi, int tuoi, int capBac)
		: CanBo(hoTen, gioiTinh, diaChi, tuoi), capBac(capBac) {}
};

class KySu : public CanBo
{
private:
	std::string nganhDaoTao;
public:
	KySu(std::string hoTen, std::string gioiTinh, std::string diaChi, int tuoi, std::string nganhDaoTao)
		: CanBo(hoTen, gioiTinh, diaChi, tuoi), nganhDaoTao(nganhDaoTao) {}
};

class NhanVien : public CanBo
{
private:
	std::string congViec;
public:
	NhanVien(std::string hoTen, std::string gioiTinh, std::string diaChi, int tuoi, std::string congViec)
		: CanBo(hoTen, gioiTinh, diaChi, tuoi), congViec(congViec) {}
};


class QLCB
{
private:
	std::vector<CanBo*> listCanBo;
	
public:
	bool timKiem=0;
	void themMoiCanBo(CanBo* canBo)
	{
		listCanBo.push_back(canBo);
	}

	void timKiemCanBo(std::string hoTen)
	{
		for (CanBo* canBo : listCanBo)
		{
			if (canBo->getHoTen() == hoTen)
			{
				std::cout << "Tim thay!" << std::endl;
				canBo->getThongTin();
				timKiem = 1;
			}
		}

		if (timKiem != 1)
		{
			std::cout << "Khong tim thay" << std::endl;
		}
	}

	void hienThiThongTin()
	{
		for (CanBo* canBo : listCanBo)
		{
			canBo->getThongTin();
		}
	}

	void thoatChuongTrinh()
	{
		for (CanBo* canBo : listCanBo)
		{
			delete canBo;
		}
	}
};

int main()
{
	QLCB qlcb;
	std:: string name;

	CanBo* canBo1 = new CongNhan("Nguyen Van A", "Nam", "Hanoi", 40, 5);
	CanBo* canBo2 = new KySu("Nguyen Thi B", "Nu", "Namdinh", 35, "TuDongHoa");
	CanBo* canBo3 = new NhanVien("Nguyen Van C", "Nam", "Haiphong", 25, "GiaoVien");

	qlcb.themMoiCanBo(canBo1);
	qlcb.themMoiCanBo(canBo2);
	qlcb.themMoiCanBo(canBo3);

	qlcb.hienThiThongTin();

	std::cout << "Nhap ten tim kiem" << std::endl;
	std::getline(std::cin, name);

	qlcb.timKiemCanBo(name);

	qlcb.thoatChuongTrinh();
	
	return 0;
}
