### **Kütüphane Yönetim Sistemi**



C++ kullanılarak geliştirilen \*\*Kütüphane Yönetim Sistemi\*\*, kütüphanelerde gerçekleştirilen kitap, kullanıcı, ödünç/iade ve bağış işlemlerinin yönetilmesini sağlayan bir masaüstü uygulamasıdır.



Proje kapsamında kullanıcı ve yetkili işlemleri ayrı olarak ele alınmış, kütüphane verilerinin kalıcı olarak saklanabilmesi amacıyla metin tabanlı veri dosyaları kullanılmıştır.



###### **Proje Özellikleri**



**Kullanıcı İşlemleri**



\* Kullanıcı kaydı oluşturma

\* Kullanıcı girişi

\* Kullanıcı bilgilerini görüntüleme

\* Kullanıcı bilgilerini güncelleme

\* Kullanıcı arama

\* Kullanıcı silme



**Kitap İşlemleri**



\* Kitap ekleme

\* Kitap silme

\* Kitap arama

\* Kitap listeleme

\* Kitap bilgilerini görüntüleme



**Ödünç ve İade İşlemleri**



\* Kitap ödünç alma

\* Ödünç alınan kitapları listeleme

\* Ödünç alınan kitapların iade edilmesi

\* Kullanıcıya ait ödünç kitapların görüntülenmesi



**Bağış İşlemleri**



\* Kullanıcı tarafından kitap bağışı yapılması

\* Bağışlanan kitapların listelenmesi

\* Yetkili tarafından bağışların yönetilmesi

\* Kabul edilen kitapların kütüphane kitap listesine aktarılması



**Yetkili İşlemleri**



\* Yetkili girişi

\* Kitap işlemlerinin yönetilmesi

\* Kullanıcı işlemlerinin yönetilmesi

\* Bağış işlemlerinin yönetilmesi



**Kullanılan Teknolojiler**



\* \*\*C++\*\*

\* \*\*Visual Studio\*\*

\* \*\*Git\*\*

\* \*\*GitHub\*\*

\* \*\*TXT tabanlı veri saklama\*\*



###### **Proje Yapısı**



```text

Kutuphane-Yonetim-Sistemi/

│

├── main.cpp

├── kitaplar.txt

├── kullanicilar.txt

├── yetkililer.txt

├── odunckitaplar.txt

├── bagislar.txt

├── kutuphaneyedek.vcxproj

├── kutuphaneyedek.vcxproj.filters

└── .gitignore

```



###### **Veri Dosyaları**



| Dosya               | Açıklama                                                          |

| ------------------- | ----------------------------------------------------------------- |

| `kitaplar.txt`      | Kütüphanedeki kitapların bilgilerini saklar.                      |

| `kullanicilar.txt`  | Kayıtlı kullanıcı bilgilerini saklar.                             |

| `yetkililer.txt`    | Yetkili kullanıcı bilgilerini saklar.                             |

| `odunckitaplar.txt` | Ödünç verilen kitapların bilgilerini saklar.                      |

| `bagislar.txt`      | Kullanıcılar tarafından bağışlanan kitapların bilgilerini saklar. |



Kurulum



Projeyi çalıştırmak için:



1\. Repository'yi bilgisayarınıza klonlayın.

2\. `kutuphaneyedek.vcxproj` dosyasını \*\*Visual Studio\*\* ile açın.

3\. Projenin derlenmesini bekleyin.

4\. `main.cpp` içerisindeki programı çalıştırın.

###### 

###### **Veri Saklama**



Uygulamada verilerin kalıcı olarak saklanması için TXT dosyalarından yararlanılmıştır.



Program çalışırken gerçekleştirilen kullanıcı, kitap, ödünç/iade ve bağış işlemleri ilgili veri dosyalarına kaydedilmektedir.



Bu yaklaşım, veritabanı kullanmadan temel dosya işlemleri ve veri yönetimi mantığının uygulanmasını sağlamaktadır.



###### **Projenin Amacı**



Projenin temel amacı, kütüphanelerde gerçekleştirilen temel operasyonların bilgisayar ortamında daha düzenli ve yönetilebilir şekilde gerçekleştirilmesini sağlamaktır.



Aynı zamanda proje kapsamında C++ programlama dili kullanılarak:



\* Dosya işlemleri

\* Veri okuma ve yazma

\* Kullanıcı yönetimi

\* Koşullu işlemler

\* Fonksiyonel programlama yapısı

\* Menü tabanlı uygulama geliştirme



gibi temel yazılım geliştirme konularının uygulanması hedeflenmiştir.





Geliştirici

\*\*FeyzaSultanYüceer\*\*

Bu proje eğitim amaçlı geliştirilmiştir.



