#include <iostream>
#include<string>
#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;

void yetkiligiris();
void uyegiris();
void yeniyetkili();

void uyekleme();
void uyelisteleme();
void uyesilme();
void uyeara();
void yeniuye();

void kitapekle();
void kitapliste();
void kitapara();
void kitapsil();

void uyekitapara();
void uyekitaparayazar();
void uyekitaparatur();
void uyekitaparaad();

void oduncal();
void oduncver();
void odunclistele();
void uyeoduncliste();
void iadeet();

void bilgiguncelle();

void yetoduncislem();
void yetkitapislem();
void yetuyeislem();


void uyearamaislem();
void uyekitapislem();
void uyeoduncislem();
void uyebagis();

int yetkilimenu();
int kullanicimenu();

struct uyeler
{
	string name;
	string surname;
	string tc;
	string ussername;
	string usserpass;
};
struct books
{
	string bookname;
	string writer;
	string bookgenre;
	string ID;
	int pages;
};
struct admin
{
	string adminname;
	string adminsurname;
	string aun;
	string adminpass;
};
struct emenat
{
	string bookname;
	string writer;
	string genre;
	string id;
	string usser;
	int paper;


};
struct bagis
{
	string bookname;
	string writer;
	string bookgenre;
	string ID;
	int pages;

};

void yetkiligiris()
{
	int count = 0;
	admin lgn;
	string adminname, adminpass;
	ifstream login;
	login.open("yetkililer.txt");

	cout << endl << "\t\t\t\t     Kullanici adinizi girin: ";
	cin >> adminname;
	cout << "\t\t\t\t     Sifrenizi girin: ";
	cin >> adminpass;
	while (login >> lgn.adminname >> lgn.adminsurname >> lgn.aun >> lgn.adminpass)
	{
		if (lgn.aun == adminname && lgn.adminpass == adminpass)
		{
			count = 1;
			login.close();
			break;
		}

	}

	if (count == 1)
	{
		system("cls");
		cout << "\t\t\t\t     HOSGELDIN " << adminname << endl;
	}
	else
	{
		cout << endl << "\t\t\t\t     HATALI GIRIS YAPTIN! LUTFEN TEKRAR DENE" << endl;
		yetkiligiris();
	}

}
void uyegiris()
{
	int count = 0;
	uyeler a;
	string name, pass;
	ifstream kullanici;
	kullanici.open("kullanicilar.txt");

	cout << "\t\t\t\t    Kullanici adinizi girin: ";
	cin >> name;
	cout << "\t\t\t\t     Sifrenizi girin: ";
	cin >> pass;

	while (kullanici >> a.name >> a.surname >> a.tc >> a.ussername >> a.usserpass)
	{
		if (a.ussername == name && a.usserpass == pass)
		{
			count = 1;
			kullanici.close();
			break;
		}

	}
	if (count == 1)
	{
		system("cls");
		cout << "\t\t\t\t    HOSGELDIN " << name << endl;
	}
	else
	{
		cout << endl << "\t\t\t\t      HATALI GIRIS YAPTINIZ! LUTFEN TEKRAR DENEYIN" << endl;
		uyegiris();

	}
}
void yeniyetkili()
{
	system("cls");
	admin na;
	ofstream yetkililer;
	yetkililer.open("yetkililer.txt", ios::app);
	cout << endl << "\t\t\t********BILGILERINIZI DOLDURUNUZ*********" << endl;
	cout << "ADI: ";
	cin >> na.adminname;
	cout << "SOYADI: ";
	cin >> na.adminsurname;
	cout << "KULLANICI ADI: : ";
	cin >> na.aun;
	cout << "SIFRE: ";
	cin >> na.adminpass;

	yetkililer << na.adminname << " " << na.adminsurname << " " << na.aun << " " << na.adminpass << endl;
	yetkililer.close();
	system("cls");
	cout << " \t\t\t***HESABINIZ OLUSTURULDU. ARAMIZA HOSGELDINIZ**** " << endl;


}

void uyekleme()
{
	system("cls");
	cout << "\n\t\t\t********UYE EKLEME********" << endl << endl;
	uyeler a;
	ofstream usser;
	usser.open("kullanicilar.txt", ios::app);

	cout << "ADI: ";
	cin >> a.name;
	cout << "SOYADI: ";
	cin >> a.surname;
	cout << "T.C. KIMLIK NO: ";
	cin >> a.tc;
	cout << "KULLANICI ADI: ";
	cin >> a.ussername;
	cout << "SIFRE: ";
	cin >> a.usserpass;

	usser << a.name << " " << a.surname << " " << a.tc << " " << a.ussername << " " << a.usserpass << endl;
	usser.close();
	system("cls");
	cout << endl << "\n\t\t\t***********KULLANICI BASARIYLA EKLENDI**********" << endl;
}
void uyelisteleme()
{
	system("cls");
	cout << "\n\t\t\t********UYE LISTELEME*********" << endl << endl;
	ifstream usser2;
	string metin;
	usser2.open("kullanicilar.txt");
	while (getline(usser2, metin))
	{
		cout << metin << endl;
	}
	usser2.close();

}
void uyesilme()
{
	system("cls");
	cout << "\n\t\t\t*********UYE SILME*********" << endl << endl;
	uyeler a;
	string tcsil;
	int var = 0;

	uyelisteleme();

	cout << endl << "Silmek istedigin kisinin T.C. kimlik numarasini girin: ";
	cin >> tcsil;

	ifstream acma;
	ofstream dosya;
	acma.open("kullanicilar.txt");
	dosya.open("gecici.txt", ios::app);

	while (!(acma.eof()))
	{
		acma >> a.name >> a.surname >> a.tc >> a.ussername >> a.usserpass;
		if (a.tc == tcsil)
		{
			var = 1;
			continue;
		}
		else
			dosya << a.name << " " << a.surname << " " << a.tc << " " << a.ussername << " " << a.usserpass << endl;

	}
	acma.close();
	dosya.close();
	
	remove("kullanicilar.txt");
	 rename("gecici.txt", "kullanicilar.txt");

	if (var)
	{
	  system("cls");
	  cout <<"\n\t\t\t**********KULLANICI BASARIYLA SILINDI*********" << endl;

	}

	else
	{
		cout << "\t\t\tHATALI T.C. KIMLIK  NO GIRDINIZ!TEKRAR DENEYIN" << endl;
		uyesilme();
	}

}
void uyeara()
{
	system("cls");
	cout << "\n\t\t\t*********UYE ARAMA*********" << endl << endl;
	char cevap;
	int var = 0;
	uyeler g;
	string tcara;
	cout << "Aramak istediginiz uyenin T.C. kimlik numarasini girin: ";
	cin >> tcara;

	ifstream arama;
	arama.open("kullanicilar.txt");

	while (!(arama.eof()))
	{
		arama >> g.name >> g.surname >> g.tc;
		if (g.tc == tcara)
		{
			cout << endl<<"KULLANICI BULUNDU";
			cout << endl << " Adi: " << g.name;
			cout << endl << "Soyadi: " << g.surname;
			cout << endl << "Tc: " << g.tc;

			arama.close();
			var = 1;
			break;

		}

	}

	if (var == 0)
	{
		system("cls");
		cout << "KULLANICI BULUNMADI";
		cout << endl << "Kullaniciyi eklemek ister misiniz? (e/h)" << endl;
		cin >> cevap;
		if (cevap == 'e' || cevap == 'E')
		{
			system("cls");
			uyekleme();

		}

		else
		{
			system("cls");
			cout << "ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}


	}

}
void yeniuye()
{
	system("cls");
	uyeler yu;
	ofstream yenikayit;
	yenikayit.open("kullanicilar.txt", ios::app);
	cout << "\n\t\t\t*********BILGILERINIZI GIRINIZ*********" << endl;
	cout << "AD: ";
	cin >> yu.name;
	cout << "SOYAD: ";
	cin >> yu.surname;
	cout << "TC: ";
	cin >> yu.tc;
	cout << "KULLANICI ADI: ";
	cin >> yu.ussername;
	cout << "SIFRE: ";
	cin >> yu.usserpass;


	yenikayit << yu.name << " " << yu.surname << " " << yu.tc << " " << yu.ussername << " " << yu.usserpass << endl;
	yenikayit.close();
	system("cls");
	cout << "\t\t\t***********KAYDINIZ BASARIYLA TAMAMLANDI. ARAMIZA HOSGELDINIZ************" << endl;




}

void kitapekle()
{
	system("cls");
	cout << "\n\t\t\t********KITAP EKLEME********" << endl << endl;
	books c;
	ofstream newbook;
	newbook.open("kitaplar.txt", ios::app);

	cout << "KITAP ADI: ";
	cin >> c.bookname;
	cout << "KITAP YAZARI:";
	cin >> c.writer;
	cout << "KITAP TURU: ";
	cin >> c.bookgenre;
	cout << "SAYFA SAYISI: ";
	cin >> c.pages;
	cout << "BIR BARKOD NUMARASI BELIRLEYIN: ";
	cin >> c.ID;

	newbook << c.bookname << " " << c.writer << " " << c.bookgenre << " " << c.pages << " " << c.ID << endl;
	newbook.close();
	cout << endl << "\t\t\t***********KITAP BASARIYLA EKLENDI*************" << endl;



}
void kitapliste()
{
	system("cls");
	cout << "\n\t\t\t********KITAP LISTELEME********" << endl << endl;
	cout << endl;
	ifstream newbook2;
	string metin2;
	newbook2.open("kitaplar.txt");
	while (getline(newbook2, metin2))
	{
		cout << metin2 << endl;

	}
	newbook2.close();

}
void kitapara()
{
	system("cls");
	cout << "\n\t\t\t********KITAP ARAMA*********" << endl << endl;
	int var1 = 0;
	books ab;
	string kitap;

	cout << "Aramak istediginiz kitabin barkod numarasini girin: ";
	cin >> kitap;
	cout << endl;
	ifstream kitaparama;
	kitaparama.open("kitaplar.txt");
	while (!(kitaparama.eof()))
	{
		kitaparama >> ab.bookname >> ab.writer >> ab.bookgenre >> ab.pages >> ab.ID;
		if (ab.ID == kitap)
		{
			cout << endl<< "KITAP BULUNDU" << endl;
			cout << endl << "Kitap Adi: " << ab.bookname;
			cout << endl << "Yazar: " << ab.writer;
			cout << endl << "Kitap Turu: " << ab.bookgenre;
			cout << endl << "Sayfa Sayisi: " << ab.pages;
			cout << endl << "Barkod No: " << ab.ID << endl;
			kitaparama.close();
			var1 = 1;
			break;
		}
	}

	if (var1 == 0)
	{
		char cevap;
		cout << endl<<"KITAP BULUNAMADI" << endl;
		cout << "Kitabi eklemek ister misiniz ? (e/h) ";
		cin >> cevap;

		if (cevap == 'e' || cevap == 'E')
		{
			system("cls");
			cout << "\t\t\t**********KITAP BILGILERINI GIRIN***********" << endl;
			kitapekle();
		}
		else
		{
			system("cls");
			cout << "\t\t\tANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}

	}


}
void kitapsil()
{
	system("cls");
	cout << "\n\t\t\t********KITAP SILME*********" << endl << endl;
	books abc;
	string idsil;

	kitapliste();

	cout << endl << "Silmek istediginiz kitabin barkod numarasini girin:";
	cin >> idsil;

	ifstream kitapsilme;
	ofstream gecicikitap;
	kitapsilme.open("kitaplar.txt");
	gecicikitap.open("gecici.txt", ios::app);

	while (!(kitapsilme.eof()))
	{
		kitapsilme >> abc.bookname >> abc.writer >> abc.bookgenre >> abc.pages >> abc.ID;

		if (abc.ID == idsil)
		{
			continue;
		}

		else
			gecicikitap << abc.bookname << " " << abc.writer << " " << abc.bookgenre << " " << abc.pages << " " << abc.ID << endl;

	}
	kitapsilme.close();
	gecicikitap.close();

	remove("kitaplar.txt");
	rename("gecici.txt", "kitaplar.txt");

	cout << "\n\t\t\t**********KITAP BASARIYLA SILINDI************" << endl;



}

void uyekitapara()
{
	system("cls");

	cout << "\n\t\t\t **********KITAP BARKOD NUMARASIYLA ARAMA**********" << endl << endl;
	int var2 = 0;
	books ara;
	string kitap;

	cout << "Aramak istediginiz kitabin barkod numarasini girin: ";
	cin >> kitap;
	cout << endl;
	ifstream kitaparama;
	kitaparama.open("kitaplar.txt");
	while (!(kitaparama.eof()))
	{
		kitaparama >> ara.bookname >> ara.writer >> ara.bookgenre >> ara.pages >> ara.ID;
		if (ara.ID == kitap)
		{
			cout << "KITAP BULUNDU";
			cout << endl << "Kitap Adi: " << ara.bookname;
			cout << endl << "Yazar: " << ara.writer;
			cout << endl << "Kitap Turu: " << ara.bookgenre;
			cout << endl << "Sayfa Sayisi: " << ara.pages;
			cout << endl << "ID: " << ara.ID;

			kitaparama.close();
			var2 = 1;
			break;
		}
	}

	if (var2 == 0)
	{
		cout << "\t\t\t    KITAP BULUNAMADI.ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
	}

}
void uyekitaparayazar()
{

	system("cls");
	int var2 = 0;
	books ara;
	string kitap;

	cout << "\n\t\t\t*********YAZAR ADIYLA ARAMA*********" << endl << endl;
	cout << "\t\t\t    Aramak istediginiz yazarin adini giriniz: ";
	cin >> kitap;
	cout << endl;

	ifstream kitaparama;
	kitaparama.open("kitaplar.txt");

	if (!kitaparama.is_open())
		cout << "\t\t\t    Hata:Dosya açılamadı.";
	else
	{
		while (!(kitaparama.eof()))
		{
			kitaparama >> ara.bookname >> ara.writer >> ara.bookgenre >> ara.pages >> ara.ID;
			if (ara.writer == kitap)
			{
				cout << "\t\t\t    YAZAR BULUNDU" << endl;
				cout << "\t\t\t    Kitap Adi: " << ara.bookname << endl;
				cout << "\t\t\t    Yazar: " << ara.writer << endl;
				cout << "\t\t\t    Kitap Turu: " << ara.bookgenre << endl;
				cout << "\t\t\t    Sayfa Sayisi: " << ara.pages << endl;
				cout << "\t\t\t    ID: " << ara.ID << endl;

				kitaparama.close();
				var2 = 1;
			}
		}

		if (var2 == 0)
		{
			cout << "\n\t\t\t    YAZAR BULUNAMADI.ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}
	}



}
void uyekitaparatur()
{
	system("cls");
	cout << "\n\t\t\t*********KITAP TURU ARAMA*********" << endl << endl;
	int var2 = 0;
	books ara;
	string kitap;

	cout << "\t\t\t\t    Aramak istediginiz turun adini girin: ";
	cin >> kitap;
	cout << endl;

	ifstream kitaparama;
	kitaparama.open("kitaplar.txt");

	if (!kitaparama.is_open())
		cout << "\t\t\t    Hata:Dosya açılamadı!";
	else
	{
		while (!(kitaparama.eof()))
		{
			kitaparama >> ara.bookname >> ara.writer >> ara.bookgenre >> ara.pages >> ara.ID;
			if (ara.bookgenre == kitap)
			{
				cout << "\t\t\t    TUR BULUNDU" << endl;
				cout << "\t\t\t    Kitap Adi: " << ara.bookname << endl;
				cout << "\t\t\t    Yazar: " << ara.writer << endl;
				cout << "\t\t\t    Kitap Turu: " << ara.bookgenre << endl;
				cout << "\t\t\t    Sayfa Sayisi: " << ara.pages << endl;
				cout << "\t\t\t    ID: " << ara.ID << endl;

				kitaparama.close();
				var2 = 1;

			}
		}

		if (var2 == 0)
		{
			cout << "\n\t\t\t    TUR BULUNAMADI.ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}
	}

}
void uyekitaparaad()
{

	int var2 = 0;
	books ara;
	string kitap;

	system("cls");
	cout << "\n\t\t\t*********KITAP ADIYLA ARAMA*********" << endl << endl;
	cout << "\t\t\t    Aramak istediginiz kitabin adini girin: ";
	cin >> kitap;
	cout << endl;

	ifstream kitaparama;
	kitaparama.open("kitaplar.txt");

	if (!kitaparama.is_open())
		cout << "\t\t\t    Hata:Dosya açılamadı.";
	else
	{
		while (!(kitaparama.eof()))
		{
			kitaparama >> ara.bookname >> ara.writer >> ara.bookgenre >> ara.pages >> ara.ID;
			if (ara.bookname == kitap)
			{
				cout << "\t\t\t    KITAP BULUNDU" << endl;
				cout << "\t\t\t    Kitap Adi: " << ara.bookname << endl;
				cout << "\t\t\t    Yazar: " << ara.writer << endl;
				cout << "\t\t\t    Kitap Turu: " << ara.bookgenre << endl;
				cout << "\t\t\t    Sayfa Sayisi: " << ara.pages << endl;
				cout << "\t\t\t    ID: " << ara.ID << endl;

				kitaparama.close();
				var2 = 1;
				break;
			}
		}

		if (var2 == 0)
		{
			cout << "\n\t\t\t    KITAP BULUNAMADI.ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}
	}




}


void oduncal()
{
	system("cls");
	cout << "\n\t\t\t*********ODUNC ALMA*********" << endl << endl;
	string name;
	string id;
	books l;

	bool a = false;

	ofstream gecici;
	ofstream odunckitap;
	ifstream kitapara;

	gecici.open("gecici.txt", ios::app);
	odunckitap.open("odunckitaplar.txt", ios::app);
	kitapara.open("kitaplar.txt");

	kitapliste();

	cout << endl << "Odunc almak icin kullanici adinizi girin: ";
	cin >> name;

	cout << "Odunc almak istediginiz kitabin barkod numarasini girin: ";
	cin >> id;



	while (kitapara >> l.bookname >> l.writer >> l.bookgenre >> l.pages >> l.ID)
	{
		if (l.ID == id)
		{
			odunckitap << l.bookname << " " << l.writer << " " << l.bookgenre << " " << l.pages << " " << l.ID << " " << name << endl;
			a = true;
		}
		else
		{
			gecici << l.bookname << " " << l.writer << " " << l.bookgenre << " " << l.pages << " " << l.ID << endl;
		}


	}
	odunckitap.close();
	gecici.close();
	kitapara.close();


	if (a)
	{
		remove("kitaplar.txt");
		rename("gecici.txt", "kitaplar.txt");

		cout << endl << "\n\t\t\t**********KITABI BASARIYLA ODUNC ALDINIZ***********" << endl;
	}

	else
	{
		cout << endl << "\n\t\t\tHATALI BARKOD NUMARASI GIRDINIZ! TEKRAR DENEYIN" << endl;
		oduncal();
	}




}
void oduncver()
{
	system("cls");
	cout << "\n\t\t\t*******ODUC VERME********" << endl << endl;

	bool a = 0;
	string name, id;
	uyeler b;
	books l;

	ofstream gecici;
	ofstream odunckitap;
	ifstream kitapara;
	ifstream kullanici;

	gecici.open("gecici.txt", ios::app);
	odunckitap.open("odunckitaplar.txt", ios::app);
	kitapara.open("kitaplar.txt");
	kullanici.open("kullanicilar.txt");

	uyelisteleme();

	cout << endl << "Odunc verilicek kisinin kullanici adin giriniz: ";
	cin >> name;
	while (kullanici >> b.name >> b.surname >> b.tc >> b.ussername >> b.usserpass)
	{
		if (b.ussername == name)
		{
			a = 1;
		}
	}

	if (a == 0)
	{
		cout << "BOYLE BIR KULLANICI BULUNAMADI! LUTFEN TEKRAR DENEYIN" << endl;
		oduncver();
	}

	a = 0;
	kitapliste();
	cout << endl << "Odunc verilcek kitabin barkot numarasini giriniz: ";
	cin >> id;


	while (kitapara >> l.bookname >> l.writer >> l.bookgenre >> l.pages >> l.ID)
	{
		if (l.ID == id)
		{
			odunckitap << l.bookname << " " << l.writer << " " << l.bookgenre << " " << l.pages << " " << l.ID << " " << name << endl;
			a = 1;
		}
		else
		{
			gecici << l.bookname << " " << l.writer << " " << l.bookgenre << " " << l.pages << " " << l.ID << endl;
		}


	}
	odunckitap.close();
	gecici.close();
	kitapara.close();


	if (a)
	{
		remove("kitaplar.txt");
		rename("gecici.txt", "kitaplar.txt");

		cout << endl << id << " barkod numarali kitap " << name << " kisine odunc verildi" << endl;
	}

	else
	{
		cout << endl << "HATALI BARKOD NUMRASI GIRDIBIZ! LUTFEN TEKRAR DENEYIN" << endl;
		oduncver();
	}


}
void odunclistele()
{
	system("cls");
	cout << "\n\t\t\t********ODUNC LISTELE********" << endl << endl;
	string metin3;
	ifstream odunclist;
	odunclist.open("odunckitaplar.txt");
	while (getline(odunclist, metin3))
	{
		cout << metin3 << endl;

	}
	odunclist.close();
}
void uyeoduncliste()
{
	system("cls");
	cout << "\n\t\t\t********ODUNC KITAPLARIM********" << endl << endl;
	string id;
	char karar;
	int flag = 0;
	ifstream okuma;
	okuma.open("odunckitaplar.txt");

	emenat a;
	string name;
	cout << "Listelemek icin kullanici adinizi girin: ";
	cin >> name;

	while (okuma >> a.bookname >> a.writer >> a.genre >> a.paper >> a.id >> a.usser)
	{
		if (a.usser == name)
		{
			cout << endl;
			cout << a.bookname << " " << a.writer << a.genre << " " << a.paper << " " << a.id << endl;
			flag = 1;
		}

	}
	okuma.close();
	if (flag == 0)
	{

		cout << "Henuz odunc aldiginiz bir kitap yok" << endl;
		cout << "Kitap odunc almka ister misiniz (e/h) : ";
		cin >> karar;
		if (karar == 'e' || karar == 'E')
		{
			system("cls");
			oduncal();
		}
		else
		{
			system("cls");
			cout << "\n\t\t\ANA MENUYE YONLENDIRILIYORSUNUZ..." << endl;
		}
	}








}
void iadeet()
{
	system("cls");
	cout << "\n\t\t\t*********IADE ETME********" << endl << endl;
	string id;
	emenat a;
	int flag = 0;
	ofstream guncelleme;
	ofstream gecici;
	ifstream okuma;
	guncelleme.open("kitaplar.txt", ios::app);
	okuma.open("odunckitaplar.txt");
	gecici.open("gecici.txt", ios::app);


	uyeoduncliste();

	cout << endl << "Iade etmek istediginiz kitabin barkot numarasini giriniz: ";
	cin >> id;

	while (okuma >> a.bookname >> a.writer >> a.genre >> a.paper >> a.id >> a.usser)
	{
		if (a.id == id)
		{
			guncelleme << a.bookname << " " << a.writer << " " << a.genre << " " << a.paper << "  " << a.id << endl;
			flag = 1;
			continue;
		}

		gecici << a.bookname << " " << a.writer << " " << a.genre << " " << a.paper << "  " << a.id << " " << a.usser << endl;

	}
	guncelleme.close();
	gecici.close();
	okuma.close();

	remove("odunckitaplar.txt");
	rename("gecici.txt", "odunckitaplar.txt");


	if (flag)
	{
		cout << "***KITABI BASARIYLA IADE ETTINIZ***";

	}

	else
	{
		cout << "HATALI BARKOD NUMARASI!";
	}


}

void bilgiguncelle()
{
	
	system("cls");
	cout << "\n\t\t\t*********BILGI GUNCELLEME*********" << endl << endl;
	int flag = 0;
	uyeler a, b;
	string name;
	ifstream okuma;
	ofstream gecici;
	okuma.open("kullanicilar.txt");
	gecici.open("gecici.txt", ios::app);

	
	cout << "Bilgilerinizi guncellemek icin once kullanici adinizi giriniz: ";
	cin >> name;
	cout << endl;
	while (okuma >> a.name >> a.surname >> a.tc >> a.ussername >> a.usserpass)
	{

		if (a.ussername == name)
		{
			cout << "ADI: " << a.name << endl;
			cout << "SOYAD: " << a.surname << endl;
			cout << "T.C. KIMLIK NO: " << a.tc << endl;
			cout << "KULLANICI ADI: " << a.ussername << endl;
			cout << "SIFRE: " << a.usserpass << endl;

			cout << endl << "        ***YENI BILGILERINIZI GIRIN***        " << endl;

			cout << "AD: ";
			cin >> b.name;
			cout << "SOYAD: ";
			cin >> b.surname;
			cout << "T.C. KIMLIK NO: ";
			cin >> b.tc;
			cout << "KULLANICI ADI: ";
			cin >> b.ussername;
			cout << "SIFRE: ";
			cin >> b.usserpass;

			gecici << b.name << " " << b.surname << " " << b.tc << " " << b.ussername << " " << b.usserpass << endl;
			flag = 1;

		}
		else
			gecici << a.name << " " << a.surname << " " << a.tc << " " << a.ussername << " " << a.usserpass << endl;

	}

	okuma.close();
	gecici.close();

	remove("kullanicilar.txt");
	rename("gecici.txt", "kullanicilar.txt");

	if (flag)
	{
		system("cls");
		cout << endl << "\n\t\t\t**********BILGILERINIZ BASARIYLA GUNCELLENDI**********" << endl;
	}

	else
	{
		system("cls");
		cout << "KULLANICI ADINIZ HATALI! ANA MENUYE GERI YONLENDIRILIYORSUNUZ" << endl;
	}







}

void yetkitapislem()
{

	system("cls");
	cout << "\n\t\t\t*********KITAP ISLEMLERI*********" << endl << endl;
	int kitapislem;
	cout << endl << "1-kitap ekle";
	cout << endl << "2-kitap listele";
	cout << endl << "3-kitap arama";
	cout << endl << "4-kitap silme";
	cout << endl << "Hangi islemi yapmak istiyorsunuz: ";
	cin >> kitapislem;

	switch (kitapislem)
	{
	case 1: kitapekle();
		break;
	case 2: kitapliste();
		break;
	case 3:kitapara();
		break;
	case 4:kitapsil();
		break;
	default:
		cout << "HATALI ISLEM! LUTFEN TEKRAR DENEYIN" << endl;
		yetkitapislem();
	}
}
void yetuyeislem()
{
	system("cls");
	cout << "\n\t\t\t*********UYE ISLEMLERI********" << endl << endl;
	int uyeislem;
	cout << endl << "1-uye ekleme";
	cout << endl << "2-uye listeleme";
	cout << endl << "3-uye silme";
	cout << endl << "4-uye arama";
	cout << endl << "Islem seciniz: ";
	cin >> uyeislem;
	switch (uyeislem)
	{
	case 1: uyekleme();
		break;
	case 2: uyelisteleme();
		break;
	case 3: uyesilme();
		break;
	case 4: uyeara();
		break;
	default: cout << "\n\t\t\t********HATALI ISLEM! LUTFEN TEKRAR DENEYIN********" << endl;
		yetuyeislem();
	}
}
void yetoduncislem()
{
	system("cls");
	cout << "                  ***ODUNC KITAP ISLEMLERI***           " << endl << endl;

	int islem;
	cout << "1-Odunc verilmis kitaplari listele" << endl;
	cout << "2-Odunc ver" << endl;
	cout << "Islem seciniz: ";
	cin >> islem;
	switch (islem)
	{
	case 1:odunclistele();
		break;
	case 2:oduncver();
		break;
	default:
		cout << "HATALI ISLEM SECTINIZ! TEKRAR DENEYIN" << endl;
		yetoduncislem();

	}


}

void uyearamaislem()
{
	int s;
	cout << "\n\t\t\t*********KITAP ARAMA*********" << endl << endl;
	cout << "\t\t\t     1.kitap barkoduyla arama" << endl;
	cout << "\t\t\t    2.kitap adiyla arama" << endl;
	cout << "\t\t\t    3.yazar adiyla arama" << endl;
	cout << "\t\t\t     4.tur ile arama" << endl;
	cout << "\t\t\t     Islem seciniz: ";
	cin >> s;


	switch (s)
	{
	case 1:uyekitapara();
		break;
	case 2: uyekitaparaad();
		break;
	case 3:uyekitaparayazar();
		break;
	case 4: uyekitaparatur();
		break;
	default:
		cout << "HATALI ISLEM! LUTFEN TEKRAR DENEYIN" << endl;
		uyearamaislem();
	}




}
void uyekitapislem()
{
	system("cls");
	cout << "\n\t\t\t*********KITAP ISLEMLERI*********" << endl << endl;
	int kitapislem;
	cout << "1-Kitap listele" << endl;
	cout << "2-Kitap Ara" << endl;
	cout << "Islem seciniz: ";
	cin >> kitapislem;

	switch (kitapislem)
	{
	case 1:kitapliste();
		break;
	case 2: uyearamaislem();
		break;
	default:
		cout << "HATALI ISLEM! lUTFEN TEKRAR DENEYIN" << endl;
		uyekitapislem();

	}



}
void uyeoduncislem()
{

	system("cls");
	cout << "\n\t\t\t*********ODUNC ISLEMLERI*********" << endl << endl;
	int oduncislem;
	cout << "1-Odunc aldigim kitaplari listele" << endl;
	cout << "2-Odunc al" << endl;
	cout << "3-Iade et" << endl;
	cout << "Islem seciniz: ";
	cin >> oduncislem;


	switch (oduncislem)
	{
	case 1:uyeoduncliste();
		break;
	case 2:oduncal();
		break;
	case 3:iadeet();
		break;
	default:
		cout << "HATALI ISLEM YAPTINIZ! TEKRAR DENEYIN" << endl;
		uyeoduncislem();

	}


}

void uyebagis()
{
	system("cls");
	cout << "\n\t\t\t*********KITAP BAGISI********" << endl << endl;
	bagis a;
	ofstream bagis;
	bagis.open("bagislar.txt", ios::app);

	cout << "Bagislamak istediginiz kitabıin bilgilerini giriniz" << endl;

	cout << "KITAP ADI: ";
	cin >> a.bookname;
	cout << "KITAP YAZARI:";
	cin >> a.writer;
	cout << "KITAP TURU: ";
	cin >> a.bookgenre;
	cout << "SAYFA SAYISI: ";
	cin >> a.pages;
	cout << "BIR BARKOD NUMARASI BELIRLEYIN: ";
	cin >> a.ID;

	bagis << a.bookname << " " << a.writer << " " << a.bookgenre << " " << a.pages << " " << a.ID << endl;
	bagis.close();
	system("cls");
	cout << endl << "***BAGIS ISTEGINIZ BASARIYLA ALINDI****" << endl;


}
void bagisekle()
{

	string satir;
	string id;
	bagis a;
	int flag = 0;
	int var = 0;
	ofstream guncelleme;
	ofstream gecici;
	ifstream okuma;

	guncelleme.open("kitaplar.txt", ios::app);
	okuma.open("bagislar.txt");
	gecici.open("gecici.txt", ios::app);

	while (getline(okuma, satir))
	{
		cout << satir << endl;
		var = 1;

	}
	okuma.close();


	if (var == 0)
		cout << "Henuz bagislanan kitap yok";
	else
	{


		cout << endl;
		cout << endl << "Kabul etmek istediginiz kitabin barkod numrasini giriniz:  ";
		cin >> id;

		okuma.open("bagislar.txt");
		while (okuma >> a.bookname >> a.writer >> a.bookgenre >> a.pages >> a.ID)
		{
			if (a.ID == id)
			{
				guncelleme << a.bookname << " " << a.writer << " " << a.bookgenre << " " << a.pages << "  " << a.ID << endl;
				flag = 1;
				continue;
			}

			gecici << a.bookname << " " << a.writer << " " << a.bookgenre << " " << a.pages << "  " << a.ID << endl;

		}
		guncelleme.close();
		gecici.close();
		okuma.close();

		remove("bagislar.txt");
		rename("gecici.txt", "bagislar.txt");


		if (flag)
		{
			cout << "***KITAB KUTUPHANEYE EKLENDI***";

		}

		else
		{
			cout << "HATALI BARKOD NUMARASI!";
		}
	}


}

int yetkilimenu()
{

	int islem;
	cout << endl << "0-programi kapat";
	cout << endl << "1-kitap islemleri";
	cout << endl << "2-uye islemleri";
	cout << endl << "3-odunc kitap islemleri";
	cout << endl << "4-yeni yetkili";
	cout << endl << "5-bagis listele";
	cout << endl << "islem seciniz: ";
	cin >> islem;

	return islem;

}
int kullanicimenu()
{
	int islem1;
	cout << endl << "0-programi kapat";
	cout << endl << "1-Kitap islemleri";
	cout << endl << "2-Odunc islemleri";
	cout << endl << "3-kullanici bilgilerimi guncelle";
	cout << endl << "4-kitap bagisla";
	cout << endl << "Islem seciniz: ";
	cin >> islem1;
	return islem1;



}

int main()
{
	int statu, giris;

	cout << "                                   *****IGU KUTUPHANESINE HOSGELDINIZ*****           " << endl << endl;
	cout << "                                           **ANA MENU**  ";
	cout << endl << "                                         1-yetkili giris";
	cout << endl << "                                         2-uye giris";
	cout << endl << "                                       Lutfen giris bicimini seciniz:";
	cin >> statu;
	cout << endl;
	if (statu == 1)
	{
		cout << "\t\t\t\t     1-Var olan hesapla giris yap" << endl;
		cout << "\t\t\t\t     2-Yeni yetkili hesabi olustur" << endl;
		cout << "\t\t\t\t     Giris biciminizi seciniz: ";
		cin >> giris;

		if (giris == 1)
		{
			yetkiligiris();
			int secim = yetkilimenu();
			while (secim != 0)
			{
				switch (secim)
				{
				case 1:yetkitapislem();
					break;
				case 2:yetuyeislem();
					break;
				case 3:yetoduncislem();
					break;
				case 4: yeniyetkili();
					break;
				case 5:bagisekle();
					break;
				default:
					cout << "HATALI ISLEM YAPTINIZ! LUTFEN GECERLI ISLEM SECINIZ" << endl;

				}
				secim = yetkilimenu();

			}
			system("cls");
			cout << endl << endl << "                                  ****HOSCAKALIN****                             " << endl << endl;
		}

		else if (giris == 2)
		{
			yeniyetkili();
			int secim = yetkilimenu();
			while (secim != 0)
			{
				switch (secim)
				{
				case 1:yetkitapislem();
					break;
				case 2:yetuyeislem();
					break;
				case 3:odunclistele();
					break;
				case 4: yeniyetkili();
					break;

				default:
					cout << "HATALI ISLEM YAPTINIZ! LUTFEN GECERLI ISLEM SECINIZ" << endl;

				}
				secim = yetkilimenu();

			}
			system("cls");
			cout << endl << endl << " HOSCAKALIN ";

		}

		else
		{
			system("cls");
			main();
		}
	}

	else if (statu == 2)
	{
		cout << "\t\t\t\t     1-Var olan hesapla giris yap" << endl;
		cout << "\t\t\t\t     2-Yeni uye hesabi olustur" << endl;
		cout << "\t\t\t\t     Giris bicimini seciniz: ";
		cin >> giris;
		cout << endl;
		if (giris == 1)
		{

			uyegiris();
			int secim1 = kullanicimenu();
			while (secim1 != 0)
			{
				switch (secim1)
				{

				case 1:uyekitapislem();
					break;
				case 2:uyeoduncislem();
					break;
				case 3: bilgiguncelle();
					break;
				case 4: uyebagis();
					break;
				default:
					cout << "HATALI ISLEM YAPTINIZ! LUTFEN GECERLI ISLEM SECIN" << endl;

				}

				secim1 = kullanicimenu();

			}
			cout << "HOSCAKALIN";

		}
		else if (giris == 2)
		{

			yeniuye();
			int secim2 = kullanicimenu();
			while (secim2 != 0)
			{
				switch (secim2)
				{

				case 1:uyekitapislem();
					break;
				case 2:uyeoduncislem();
					break;
				case 3:bilgiguncelle();
					break;
				default:
					cout << "HATALI ISLEM YAPTINIZ! LUTFEN GECERLI ISLEM SECIN" << endl;

				}

				secim2 = kullanicimenu();

			}
			cout << "HOSCAKALIN";


		}

		else
		{
			system("cls");
			main();
		}

	}


	else
	{
		system("cls");
		cout << "                                           LUTFEN GECERLI GIRIS BICIMI SECIN                  " << endl << endl;
		main();
	}



}