# LogiGraph: Hibrit Lojistik Ağı ve Paket Takip Sistemi

Bu proje, Kırklareli Üniversitesi Yazılım Mühendisliği bölümü **Veri Yapıları** dersi kapsamında geliştirilmiş dinamik bir kargo yönlendirme ve takip simülasyonudur. Sistem, şehirler arası bağlantıları yönetmek için **Graf (Graph)** yapısını, paketlerin durumlarını hızlı sorgulamak için ise **Hash Tablosu (Hash Table)** yapısını hibrit olarak kullanmaktadır.

##  Geliştirici Bilgileri
* **Ad Soyad:** [Hüseyin Emre Alemdar]
* **Öğrenci Numarası:** 1250505063
* **Bölüm:** Yazılım Mühendisliği
* **Kurum:** Kırklareli Üniversitesi

---

## ⚙️ Projede Uygulanan Teknik Kurallar (Öğrenci No Referanslı)

Ödev yönergesi gereği, 1250505063 numarasına göre aşağıdaki algoritmalar sisteme entegre edilmiştir:

1. **Hash Fonksiyonu (Tip B):** Numaranın tamamı tek sayı olduğu için (sonu 3), anahtar karakterlerin ASCII değerlerini dinamik bir katsayı ile çarpan polinom tabanlı (Polynomial Rolling Hash) Tip B fonksiyonu yazılmıştır.
2. **Çakışma / Collision (Açık Adresleme):** Son rakam (3) 0-4 aralığında olduğu için, Hash tablosundaki çakışmalar "Linear Probing" (Doğrusal Sınama) yöntemiyle çözülmüştür.
3. **Graf Gezinme (BFS):** Sondan ikinci rakam (6) çift sayı olduğu için, lojistik ağı üzerindeki tarama işlemleri Sığ Öncelikli Arama (Breadth-First Search) algoritması ile gerçekleştirilmiştir.

---

## 📂 Mantıksal Katmanlar ve Dosya Yapısı

Proje, birbirine bağlı 4 temel modülden oluşmaktadır:

* `types.h`: Sistemde kullanılan ortak veri yapılarını (Package, tanımlamalar) içerir.
* `graph.c` & `graph.h`: Şehirleri (Düğüm) ve aralarındaki mesafeleri (Kenar) Adjacency List (Komşuluk Listesi) mantığıyla bağlar. BFS algoritmasını barındırır.
* `hash.c` & `hash.h`: Kargo takip numaralarını (Örn: TR1003) anahtar olarak alıp, paket bilgilerini bellek üzerinde indeksler.
* `memory_report.c` & `memory_report.h`: Program çalıştığında Heap üzerinde oluşturulan verilerin RAM adreslerini (0x...) okuyarak teknik analiz dökümü verir.
* `main.c`: Lojistik simülasyonunu başlatır, 5 şehir ve 5 paket verisini sisteme yükleyerek algoritmaları test eder.

---

## 🚀 Derleme ve Çalıştırma

Projeyi lokal bilgisayarınızda derlemek ve çalıştırmak için GCC derleyicisine sahip olmanız gerekmektedir. Terminal veya komut satırına aşağıdaki komutu girerek projeyi çalıştırabilirsiniz:

```bash
gcc main.c graph.c hash.c memory_report.c -o LojistikProjesi
./LojistikProjesi
