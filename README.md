# 📚 Kütüphane Yönetim Sistemi

**Kütüphane Yönetim Sistemi**, C++ programlama dili kullanılarak geliştirilmiş, kütüphanelerde gerçekleştirilen temel işlemlerin dijital ortamda yönetilmesini sağlayan bir masaüstü uygulamasıdır.

Uygulama; **kullanıcı yönetimi, kitap yönetimi, ödünç/iade işlemleri, kitap bağışı ve yetkili işlemleri** gibi temel kütüphane operasyonlarını kapsamaktadır. Verilerin kalıcı olarak saklanması amacıyla metin tabanlı `.txt` dosyalarından yararlanılmıştır.

---

## Özellikler

###  Kullanıcı İşlemleri

* Kullanıcı kaydı oluşturma
* Kullanıcı girişi
* Kullanıcı bilgilerini görüntüleme
* Kullanıcı bilgilerini güncelleme
* Kullanıcı arama
* Kullanıcı silme

###  Kitap İşlemleri

* Kitap ekleme
* Kitap silme
* Kitap arama
* Kitap listeleme
* Kitap bilgilerini görüntüleme

###  Ödünç ve İade İşlemleri

* Kitap ödünç alma
* Ödünç alınan kitapları listeleme
* Kitap iade etme
* Kullanıcıya ait ödünç kitapları görüntüleme

###  Bağış İşlemleri

* Kullanıcı tarafından kitap bağışı yapılması
* Bağışlanan kitapların listelenmesi
* Yetkili tarafından bağışların yönetilmesi
* Kabul edilen kitapların kütüphane envanterine eklenmesi

###  Yetkili İşlemleri

* Yetkili girişi
* Kitap işlemlerinin yönetilmesi
* Kullanıcı işlemlerinin yönetilmesi
* Bağış işlemlerinin yönetilmesi

---

##  Kullanılan Teknolojiler

| Teknoloji         | Kullanım Alanı               |
| ----------------- | ---------------------------- |
| **C++**           | Uygulama geliştirme          |
| **Visual Studio** | Geliştirme ortamı            |
| **TXT**           | Veri saklama                 |
| **Git**           | Versiyon kontrolü            |
| **GitHub**        | Proje ve kaynak kod yönetimi |

---

##  Proje Yapısı

```text
Kutuphane-Yonetim-Sistemi/
│
├── main.cpp
│
├── kitaplar.txt
├── kullanicilar.txt
├── yetkililer.txt
├── odunckitaplar.txt
├── bagislar.txt
│
├── kutuphaneyedek.vcxproj
├── kutuphaneyedek.vcxproj.filters
│
└── .gitignore
```

###  Veri Dosyaları

| Dosya               | Açıklama                                                          |
| ------------------- | ----------------------------------------------------------------- |
| `kitaplar.txt`      | Kütüphanede bulunan kitapların bilgilerini saklar.                |
| `kullanicilar.txt`  | Sisteme kayıtlı kullanıcıların bilgilerini saklar.                |
| `yetkililer.txt`    | Sistemdeki yetkili kullanıcıların bilgilerini saklar.             |
| `odunckitaplar.txt` | Ödünç verilen kitapların bilgilerini saklar.                      |
| `bagislar.txt`      | Kullanıcılar tarafından bağışlanan kitapların bilgilerini saklar. |

---

##  Kurulum ve Çalıştırma

Projeyi bilgisayarınızda çalıştırmak için aşağıdaki adımları izleyebilirsiniz.

### 1. Repository'yi klonlayın

```bash
git clone https://github.com/fyuceer/Kutuphane-Yonetim-Sistemi.git
```

### 2. Proje dosyasını açın

`kutuphaneyedek.vcxproj` dosyasını **Visual Studio** ile açın.

### 3. Projeyi derleyin

Visual Studio üzerinden projeyi **Build** ederek gerekli derleme işlemini gerçekleştirin.

### 4. Uygulamayı çalıştırın

Projeyi çalıştırarak kütüphane yönetim sisteminin menülerine erişebilirsiniz.

---

##  Veri Yönetimi

Uygulamada verilerin kalıcı olarak saklanması için **metin tabanlı TXT dosyaları** kullanılmaktadır.

Kullanıcı, kitap, ödünç/iade ve bağış işlemleri gerçekleştirildiğinde ilgili bilgiler sistem tarafından veri dosyalarına kaydedilmektedir.

Bu yapı sayesinde harici bir veritabanı sistemi kullanılmadan temel **dosya okuma, dosyaya yazma ve veri yönetimi** işlemleri gerçekleştirilmiştir.

---

##  Projenin Amacı

Projenin temel amacı, kütüphanelerde gerçekleştirilen kitap ve kullanıcı işlemlerinin bilgisayar ortamında daha düzenli ve yönetilebilir şekilde gerçekleştirilmesini sağlamaktır.

Proje geliştirme sürecinde C++ programlama dilinin temel ve orta seviye özellikleri kullanılarak aşağıdaki konularda uygulama deneyimi kazanılması hedeflenmiştir:

* Dosya işlemleri
* Veri okuma ve yazma
* Kullanıcı yönetimi
* Koşullu ifadeler
* Fonksiyon kullanımı
* Menü tabanlı uygulama geliştirme
* Veri yönetimi
* Versiyon kontrolü

---

##  Proje Kapsamı

Sistem iki temel kullanıcı rolü üzerinden çalışmaktadır:

**Kullanıcı**

* Sisteme kayıt olabilir.
* Kitapları görüntüleyebilir ve arayabilir.
* Kitap ödünç alabilir ve iade edebilir.
* Kitap bağışında bulunabilir.

**Yetkili**

* Kitap kayıtlarını yönetebilir.
* Kullanıcı kayıtlarını yönetebilir.
* Bağış işlemlerini yönetebilir.

---

## Geliştirici

**Feyza Sultan Yüceer**

GitHub: [@fyuceer](https://github.com/fyuceer)

> Bu proje eğitim amaçlı geliştirilmiştir.
