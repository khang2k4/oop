#include <bits/stdc++.h>
#include<conio.h>
#include<string.h>
#include<iomanip>
using namespace std;
//xay dung lop nhan vien

class nhanvien{
	private:
		int Manv, Cmt;
		string hoten, ngaysinh, diachi;
		float luongCB, phucap, thuclinh;
	public:
		// phuong thuc nhap
		void nhap(){
			cout<<"\nNhap ma nhan vien: ";cin>>Manv ; fflush(stdin);
			cout<<"\nNhap ho ten: "; getline(cin,hoten); fflush(stdin);
			cout<<"\nNhap ngay sinh: "; getline(cin,ngaysinh); fflush(stdin);
			cout<<"\nNhap dia chi: "; getline(cin,diachi); fflush(stdin);
			cout<<"\nNhap so the CMT: "; cin>>Cmt; fflush(stdin);
			cout<<"\nNhap luong co ban: "; cin>>luongCB; fflush(stdin);
			cout<<"\nNhap phu cap: "; cin>>phucap; fflush(stdin);
			thuclinh=luongCB+phucap;
		}
		// phuong thuc xuat
		void xuat() {
        cout << left << setw(10) << Manv
         << setw(25)<<left<< hoten
         << setw(12) << left << ngaysinh
         << setw(12) << left << diachi
         << setw(12) << left << Cmt
         << setw(12) << left << luongCB
         << setw(12) << left << phucap
         << setw(12) << left << thuclinh<<endl;
}
		
		
		// lay gia tri trong private
	
		int get_Manv(){
			return Manv;		
		}
		
			int get_Cmt(){
			return Cmt;		
		}
		
			float get_thuclinh(){
			return thuclinh;		
		}
		
			float get_phucap(){
			return phucap;		
		}
		
};

// nhap n nhan vien

void nhapds(nhanvien nv[], int n){
	for(int i=0;i<n;i++){
		cout<<" \n Nhan vien thu: "<< i+1<<"";
		nv[i].nhap();
	}
}


// xuat n nhan vien

void xuatds(nhanvien nv[], int n){
	cout<<setw(12)<<left<<"  Manv"<<setw(25)<<left<<"Ho ten"<<setw(12)<<left<<"Ngay sinh"<<setw(12)<<left<<"Dia chi"<<setw(12)<<left<<"Cmt"<<setw(12)<<left<<"LuongCB"<<setw(12)<<left<<"Phu cap"<<setw(12)<<left<<"Thuc linh\n";
	for(int i =0; i<n; i++){
		if(i>=1){
			cout<<"  ";nv[i].xuat();
		}
		else{
			nv[i].xuat();
		}
	}
}

// tim kiem theo ma nhan vien

void timkiemManv(nhanvien nv[], int n){
	int ma;
	int count=0;
	cout<<" \nNhap ma nhan vien can tim: "; cin>>ma;
	for(int i=0;i<n;i++){
		if(nv[i].get_Manv()==ma){
			cout<<setw(12)<<left<<"Manv"<<setw(25)<<left<<"Ho ten"<<setw(12)<<left<<"Ngay sinh"<<setw(12)<<left<<"Dia chi"<<setw(12)<<left<<"Cmt"<<setw(12)<<left<<"LuongCB"<<setw(12)<<left<<"Phu cap"<<setw(12)<<left<<"Thuc linh\n";
			nv[i].xuat();
			count++;
		}
	}
	if(count==0){
		cout<<" \nKhong tim thay Manv can tim.";
	}
}

// tim kiem nhan vien theo cmt

void timkiemCmt(nhanvien nv[], int n){
	int cm;
	int count=0;
	cout<<" \nNhap so CMT nhan vien can tim: "; cin>>cm;
	for(int i=0;i<n;i++){
		if(nv[i].get_Cmt()==cm){
			cout<<setw(12)<<left<<"Manv"<<setw(25)<<left<<"Ho ten"<<setw(12)<<left<<"Ngay sinh"<<setw(12)<<left<<"Dia chi"<<setw(12)<<left<<"Cmt"<<setw(12)<<left<<"LuongCB"<<setw(12)<<left<<"Phu cap"<<setw(12)<<left<<"Thuc linh\n";
			nv[i].xuat();
			count++;
		}
	}
	if(count==0){
		cout<<" \nKhong tim thay CMT nhan vien can tim.";
	}
}

// sap xep luong nhan vien tang dan
void sapxep(nhanvien nv[], int n){
	nhanvien tg;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(nv[i].get_thuclinh() > nv[j].get_thuclinh()){
				tg = nv[i];
				nv[i] = nv[j];
				nv[j] = tg;
			}
		}
	}
	
	cout << "Sau khi sap xep: " << endl;
	xuatds(nv, n);
}


// Tinh tong luong cac nhan vien trong danh sach
void tongluong(nhanvien nv[], int n){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=nv[i].get_thuclinh();
	}
	cout<<" \nTong luong cua cac nhan vien trong danh sach: "<<sum;
}

// Tim nhan vien thu nhap cao nhat
void thuclinhMax(nhanvien nv[], int n){
	int max=0;
    nhanvien x;
	for(int i=0;i<n;i++){
		if(nv[i].get_thuclinh()>max){
			max = nv[i].get_thuclinh();
            x=nv[i];
		}	
	}
	
	cout<<" \nNhan vien co luong cao nhat: "<<max<<endl;
    cout<<setw(12)<<left<<"Manv"<<setw(25)<<left<<"Ho ten"<<setw(12)<<left<<"Ngay sinh"<<setw(12)<<left<<"Dia chi"<<setw(12)<<left<<"Cmt"<<setw(12)<<left<<"LuongCB"<<setw(12)<<left<<"Phu cap"<<setw(12)<<left<<"Thuc linh\n";
    x.xuat();
    
	
}


// tim nhan vien co phu cap > 100.000

void timphucap(nhanvien nv[], int n){
 	cout<<setw(12)<<left<<"Manv"<<setw(25)<<left<<"Ho ten"<<setw(12)<<left<<"Ngay sinh"<<setw(12)<<left<<"Dia chi"<<setw(12)<<left<<"Cmt"<<setw(12)<<left<<"LuongCB"<<setw(12)<<left<<"Phu cap"<<setw(12)<<left<<"Thuc linh\n";	
	for (int i=0; i<n; i++){
		if(nv[i].get_phucap()>100000){
		if(i>=1){
			cout<<"  ";nv[i].xuat();
		}
		else{
			nv[i].xuat();
		}
		
			
			
		}
	}
}


// xay dung menu chuc nang nhan vien

void menu(){
	int n;
	nhanvien *nv = new nhanvien[n];
	int choice;
	do{
		system("cls");
		cout<<"\t      CHUONG TRINH QUAN LY NHAN VIEN.\t"<<endl;
		cout<<"===========================Menu=======================\n";
		cout<<"==                                                  ==\n";
		cout<<"==        1. Nhap danh sach nhan vien.     	    ==\n";
		cout<<"==        2. Xuat danh sach nhan vien.              ==\n";
		cout<<"==        3. Tim kiem nhan vien theo Manv.          ==\n";
		cout<<"==        4. Tim kiem nhan vien theo CMT.           ==\n";
		cout<<"==        5. Sap xep luong nhan vien tang dan       ==\n";
		cout<<"==        6. Tinh tong luong cac nhan vien          ==\n";
		cout<<"==        7. Tim kiem nhan vien thu nhap cao nhat   ==\n";
		cout<<"==        8. Tim kiem nhan vien phu cap > 100.000   ==\n";
		cout<<"==        9. Exit                                   ==\n";
		cout<<"======================================================\n";
		cout<<" \t Nhap lua chon cua ban: "; cin>>choice;
	switch(choice){
		case 1:
	        cout<<"Nhap so luong nhan vien: "; cin>>n;
	        delete[] nv; 
	        nv = new nhanvien[n];
			nhapds(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 2:
			xuatds(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 3:
			
			timkiemManv(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 4:
			timkiemCmt(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 5:
			sapxep(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 6:
			tongluong(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 7:
			thuclinhMax(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 8:
			timphucap(nv,n);
			cout<<endl;
			system("\npause");
			break;
		case 9:
			exit(0);
			break;	
		default:
			cout<<"Khong co du lieu ban nhap";
			break;
}
} while(choice!=0);
}


// ham main 
int main(){
	menu();
	getch();
}
