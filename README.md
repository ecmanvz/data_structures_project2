# data_structures_project2
Program açıldığında klasörde Sayılar.txt dosyasını arıyor. Dosyada yazılı olan satırları satır satır okuyarak SatirEkle fonksiyonuna gönderiyor, bu fonksiyon aynı anda parametre olarak AVL ağacını alıyor, 
Satırdaki sayılar diziye atandıktan sonra Radix Sort sıralama algoritması ile sıralanıyor ve daha sonra AVL ağaca ekleniyor.
AVL Ağacında her düğüm eklendiğinden sonra dengeleme işleminde SeviyeUp veya SeviyeDown fonksiyonları çağrılıyor, 
Bu fonksiyonlar özyinelemeli fonksiyon olarak çağrılan dügümün alt düğümlerinde çağrılmaya başlıyor ve ödevde verilen şartlara göre düğümde olan dizinin son veya ilk sayısı siliniyor.
