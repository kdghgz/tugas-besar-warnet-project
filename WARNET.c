//FINAL

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>



struct User {
    char username[30]; 
    char password[30]; 
    int saldo; 
    int totalmenitbermain; 
    int riwayatdalambermain;  
    char riwayat[50][100];
};


struct User pengguna[100]; 
int jumlahuser = 0; 
int jumlahlogin = -1; 



struct Device {
    char nama[50]; 
    int tersedia; 
    char userBooking[30]; 
}; 

struct Device devices[13]; 



void initDevices() { 
    char *namaDevices[] = { //  DATA SUMBER. CHAR ADALAH JENIS TIPE DATA YANG DIGUNAKAN. [] UNTUK MENYIMPAN ARRAY BERUPA JENIS JENIS DEVICE. SEDANGKAN * ADALAH POINTER DIMANA KITA TIDAK HARUS MENULISKAN [13] [50] UNTUK JUMLAH DEVICES DAN NAMA KARAKTER STRING SETIAP DEVICE . TANPA WASTED SPACE
        "PC A", "PC B", "PC C", "PC D", "PC E", //  STRING YANG BEBERISI 13 POINTER UNTUK NAMA DEVICE 
        "PS4", "PS4 Pro", "PS5", "PS5 Pro",
        "Nintendo Switch A", "Nintendo Switch B", 
        "Nintendo Switch C", "Nintendo Switch D"
    };

    // INISIALISASI DAN CEK DEVICE PERULANGAN, MAKSUDNYA DEVICE APA SAJA YANG TERSEDIA TANPA INISIALISASI DEVICE. NAMA DEVICE DAN STATUS DEVICE AKAN MEMILIKI  OUTPUT NUMBER YANG RANDOM
    for(int i = 0; i < 13; i++) { //PERULANGAN PENCATATAN SATU PERSATU SETIAP DEVICES DICEK SAMPAI 12 [INDEKS 0-12] { ISI PERULANGAN }
        strcpy(devices[i].nama, namaDevices[i]); // SALIN NAMA DEVICE YAANG ADA DI CHAR NAMADEVICES LALU SIMPAN , BUAT PERULANGAN SEBANYAK 0-12
        devices[i].tersedia = 1; // PENANDA APAKAH DEVICES MASIH TERSEDIA DEVICE [DARI 0-12]. TERSEDIA = 1. CEK DEVICE PASTIKAN SETIAP DEVICES 1 (TERSEDIA)
        strcpy(devices[i].userBooking, ""); //SALIN NAMA USER BOOKING YG TELAH DI INPUT USER DISINI. KOSONG HANYA " " NAMA UKARENA SESUAI INPUTAN USER
    } 

    
}

//
void updateDeviceStatus(const char* deviceName, int status, const char* username) { //BIKIN PROSEDURE MENERIMA DATA DARI DEVICE NAME, STATUS, USRENAME
    for (int i = 0; i < 13; i++) { // CARI DARI KOMPUTER PERTAMA HINGGA TERAKHIR
        if (strcmp(devices[i].nama, deviceName) == 0) { //CEK APAKAH NAMA KOMPUTER SAMA DENGAN YANG DICARI. JIKA DEVICENAMA KE I SMA PERSIS DENGAN NAMA DEVICE YG DICARI MAKA UBAH STATUS KETERSEDIAN
            devices[i].tersedia = status; //UPDATE STATUS KETERSEDIAN
            if (status == 0) { //JIKA STATUS  0 MAKA ARTINYA DIBOOKING
                strcpy(devices[i].userBooking, username);  //SIMPAN NAMA USERNAME
            } else { // JIKA STATUS 1 MAKA BELUM ADA YG BOOKING
                strcpy(devices[i].userBooking, ""); //KOOSONGKAN NAMA 
            }
            break;
        }
    }
}

// FUNGSI UNTUK PAUSE AGAR BISA LANJUT KE PILIHAN BERIKUTNYA
void pauseProgram() {
    printf("\nTekan Enter untuk melanjutkan..."); 
    getchar(); //TUNGGU UUSER MENEKAN ENTER
    getchar(); //TUNGGU UUSER MENEKAN ENTER
}

// FUNGSI UNTUK MENAMBAH RIWAYAT
void tambahRiwayat(const char* aktivitas) {
    if (jumlahlogin == -1) return; // JIKA JUMLAH LOGIN SAMA DENGAN -1 MAKA KELUAR DARI FUNGSI
    
    if (pengguna[jumlahlogin].riwayatdalambermain < 50) { // Kalau orang yang lagi login, catatannya masih kurang dari 50 (masih ada tempat kosong)
        strcpy(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], aktivitas);  //USER YANG SEDANG LOGIN 
        pengguna[jumlahlogin].riwayatdalambermain++;
    }
}


// FUNGSI UNTUK MEMBILANG WAKTU 
void bilangWaktu(int menit) { 
    int jam = menit / 60; //
    int sisaMenit = menit % 60; 
    
    if (jam > 0 && sisaMenit > 0) { // JIKA JAM LEBIH DARI 0 DAN SISA MENIT LEBIH DARI 0 MAKA PRINT  JAM DAN SISA MENIT
        printf("%d jam %d menit", jam, sisaMenit);
    } else if (jam > 0) { //
        printf("%d jam", jam);
    } else {
        printf("%d menit", menit);
    }
}


// DEKLARASI FUNGSI
void mainMenu(); // menu pertama tersedia 1. sign up 2.log in 3.
void Warnetmenu(); //WARNET MENU TAMPILAN LIST LAYANAN WARNET YANG TERSEDIA
void Signup(); // SIGN UP REGISTER DAFTAR AKUN BARU
void Signin(); // SIGN IN MASUK LOGIN
void exitProgram(); // EXIT PROGRAM 
void list(int menu); //LIST RENTAL (MENU 1)
void tambahJamMain(); // TAMBAH JAM MAIN (MENU 2) TUBES-TAMBAH !
void cariDevice(); // CEK DEVICE KOSONG SEARCHING (MENU 3) TUBES - SEARCHING !
void editUser(); // EDIT USER (MENU 5) TUBES-EDIT !
void hapusAkun(); // HAPUS AKUN (MENU 6) TUBES - DELETE !
void topUpSaldo(); // TOP UP SALDO (MENU 7)
void sortingLamaBermain(); // URUTKAN (MENU 8) TUBES- SORTING !
int cekUserSedangRental(); // CEK APAKAH USER SUDAH RENTAL DEVICE LAIN
void tampilkanDeviceYangDisewa(); // TAMPILKAN DEVICE YANG SEDANG DISEWA






// MAIN MENU WARNET USER UNTUK LOGIN DAN REGISTER 
void mainMenu(){ 
 printf(" ========================================\n");

    for (int i = 0; i < 5; i++)
{
    if(i == 2){  
        printf("| %29s \n", "SELAMAT DATANG\t\t|"); // %29S ADALAH CONTOH BERAPA SPASI SEMAKAIN BESAR ANGKANYA MAKA SUATU KARAKTER AKAN BERPINDAH KE KANAN
        printf("| %23s \n", "DI\t\t\t|");
        printf("| %25s \n", "WARNET\t\t\t|");
        printf("| %34s \n", "tongkrongannya para gamers\t|");
    } else {
        printf("|\t\t\t\t\t|\n"); // BISA MENGGUNAKAN TAB JIKA LEBIH MUDAH
    }
     printf(" ========================================\n");
}



printf("========================================\n");
printf("| %26s \n", "Pilih Menu\t\t|");
printf("========================================\n");

printf("| 1. Sign Up (buat akun baru)\t\t|\n");
printf("| 2. Sign In (login)\t\t\t|\n");
printf("| 3. Exit\t\t\t\t|\n");

printf("========================================\n");
printf("\nPilih menu: ");
}

// FUNGSI UNTUK CEK APAKAH USER SEDANG RENTAL
int cekUserSedangRental() { 
    if (jumlahlogin == -1) return 0; // JIKA JUMLAH LOGIN TIDAK ADA KEMBALIKAN NILAI 0
    
    for (int i = 0; i < 13; i++) { // PERULANGAN JIKA
        if (strcmp(devices[i].userBooking, pengguna[jumlahlogin].username) == 0) {
            return 1; // Sedang rental
        }
    }
    return 0; // Tidak sedang rental
}

// FUNGSI UNTUK MENAMPILKAN DEVICE YANG SEDANG DISEWA
void tampilkanDeviceYangDisewa() {
    printf("\n DEVICE YANG SEDANG ANDA SEWA:\n");
    printf("========================================\n");
    
    int adaSewa = 0; // MEMBERITAHU JIKA ADA YG SEWA ITU SAMA DENGAN 0
    for (int i = 0; i < 13; i++) {
        if (strcmp(devices[i].userBooking, pengguna[jumlahlogin].username) == 0) { 
            printf(" %s\n", devices[i].nama);
            adaSewa = 1;
        }
    }
    
    if (!adaSewa) { //JIKA
        printf("Tidak ada device yang sedang disewa.\n");
    }

}

// WARNET MENU DIMANA USER DIHADAPKAN OLEH BEBERAPA PILIHAN YANG TERSEDIA DI WARNET
void Warnetmenu() {
    printf("\n========================================\n");
    printf("Selamat datang di Warnet %s!\n", pengguna[jumlahlogin].username); // NAMA PENGGUNA[MASUK DI INDEKS KE BERAPA AGAR DIKETAHUI PENEMPATAN NAMA DI ARRAY BERPA]
    printf("Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo); // PENGGUNA KE BERAPA SESAUI INDEKS ARRAY DAN TOTTAL SALDO DITAMPILKAN
    printf("Total waktu main: ");
    bilangWaktu(pengguna[jumlahlogin].totalmenitbermain); // PEMANGGILAN INDEKS DAN TOTAL MENIT BERMAIN

    // TAMPILKAN JIKA SEDANG RENTAL
   if (cekUserSedangRental()) {
    tampilkanDeviceYangDisewa();
}
    printf("\n========================================\n");
    printf("Silahkan pilih menu yang tersedia:\n");
    printf(" 1. Rental Device (PC/PS/NINTENDO)\n");
    printf(" 2. Tambah jam main\n");
    printf(" 3. Cek device kosong\n");
    printf(" 4. Edit profil\n");
    printf(" 5. Hapus akun\n");
    printf(" 6. Top up saldo\n");
    printf(" 7. Sorting daftar user\n");
    printf(" 8. Log out\n");
    printf("========================================\n");
    printf("Pilihan Anda: "); // USER HARUS PILIH DARI KE 9 NOMOR TERSEBUT
}

// SIGN UP DIMANA USER MENGHARUSKAN DAFTAR ATAU REGISTER AGAR TERDATA
void Signup() {
    char usernameuserbaru[50]; 
    char passwordbaru[50];
    
    printf("\n=== SIGN UP (BUAT AKUN BARU) ===\n"); // BUAT AKUN BARU 
    printf("Silakan masukan username yang anda ingin buat: ");
    scanf("%s", usernameuserbaru);
    
    printf("Masukan password yang anda ingin buat: ");
    scanf("%s", passwordbaru);
    
    for (int i = 0; i < jumlahuser; i++) {
        if (strcmp(pengguna[i].username, usernameuserbaru) == 0) { //JIKA ST
            printf("Username sudah digunakan! Pilih username lain\n");
            pauseProgram();
            return;
        }
    }
    
    strcpy(pengguna[jumlahuser].username, usernameuserbaru); //SALIN PENGGUNA [JUMLAH USE]
    strcpy(pengguna[jumlahuser].password, passwordbaru);
    pengguna[jumlahuser].saldo = 0;
    pengguna[jumlahuser].totalmenitbermain = 0;
    pengguna[jumlahuser].riwayatdalambermain = 0;
    
    jumlahuser++;
    printf("Selamat username telah didaftarkan!\n");
    printf("Silakan login dengan akun baru Anda.\n");
    pauseProgram();
}


//VOID LOGIN
void Signin() {
    char username[50]; //SIMPAN 50 KARAKTER
    char password[50]; //SIMPAN 50 KARAKTER
    
    printf("\n=== SIGN IN (LOGIN) ===\n"); // MASUKAN USERNAME
    printf("Silakan masukan username anda: ");
    scanf("%s", username);
    
    printf("Silakan masukan password anda: "); //MASUKAN PASSWORD
    scanf("%s", password);
    
    for (int i = 0; i < jumlahuser; i++) { // PERULANGAN JIKA I =0 I< JUMLAH USER 
        if (strcmp(pengguna[i].username, username) == 0 &&
            strcmp(pengguna[i].password, password) == 0) {
            jumlahlogin = i;
            printf("Login berhasil!\nSelamat datang %s\n", username);
            printf("Saldo Anda: Rp %d\n", pengguna[i].saldo);
            printf("Total waktu main: ");
            bilangWaktu(pengguna[i].totalmenitbermain);
            printf("\n");
            pauseProgram();
            return;
        }
    }
    
    printf("Username atau password salah!\n");
    pauseProgram();
}




// FUNGSI UNTUK TAMBAH JAM MAIN (MENU 2)
void tambahJamMain() {
    // Cari device yang disewa
    char device[50] = "";
    for (int i = 0; i < 13; i++) {
        if (strcmp(devices[i].userBooking, pengguna[jumlahlogin].username) == 0) { //
            strcpy(device, devices[i].nama);
            break;
        }
    }
    
    if (strlen(device) == 0) { //JIKA DEVICE TIDAK DI RENTAL MAKA MENUNJUKAN ADNTA TIDAK RENTALA APAPUN
        printf("\nAnda tidak sedang rental device!\n"); 
        pauseProgram();
        return; //KEMBALI
    }
    
    printf("\nTambah jam untuk %s\nJam: ", device); //TAMBAH JAM MAIN UNTUK DEVICE APA DAN,BRP JAM
    int jam;
    scanf("%d", &jam);
    
    if (jam <= 0) return; // JIKA JAM NYA KURANG DARI 0 KEMBALI
    
    int harga = 3000 * jam; // DEKLARASIKAN HARGA RENTAL 3000 PER JAM
    
    if (pengguna[jumlahlogin].saldo < harga) { // JIKA SALDO PENGGUNA KURANG DARI HARGA RENTAL PRINT SALDO KURANG
        printf("Saldo kurang!\n");
        pauseProgram();
        return;
    }
    
    printf("Konfirmasi Tambah jam main sebesar (Rp 3.000 / jam ) ? (Y/T): "); // KOMFIRMASI TAMBAH JAM MAIN
    char konfirmasi;
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'Y' || konfirmasi == 'y') { //JIKA PENGGUNA MENGKONFIRMASI Y ATAU y MAKA
        pengguna[jumlahlogin].saldo -= harga; //MAKA SALDO USER DIKURANGIN DENGAN HARGA RENTAL 
        pengguna[jumlahlogin].totalmenitbermain += jam * 60; // TOTAL MENIT BERMAIN AKAN DITAMBAH
        
        char riwayat[100];
        sprintf(riwayat, "Tambah %d jam %s (Rp %d)", jam, device, harga);
        tambahRiwayat(riwayat);
        
        printf("Berhasil! Saldo: Rp %d\n", pengguna[jumlahlogin].saldo);
    }
    
    pauseProgram();
}




// FUNGSI UNTUK CARI DEVICE KOSONG (MENU 3) - SEQUENTIAL SEARCH SEDERHANA
void cariDevice() {

    printf("========================================\n");
    printf("PETUNJUK PENCARIAN:\n");
    printf(" Ketik 'PC' untuk semua PC\n");
    printf(" Ketik 'PS' untuk semua PlayStation\n");
    printf(" Ketik 'NINTENDO' untuk semua Nintendo\n");
    printf("========================================\n");

    char kunci[50];
    scanf("%s", kunci);
    
    printf("\nHASIL:\n");
    
    int ditemukan = 0;
    int tersedia = 0;
    
    // Sequential search sederhana
    for(int i = 0; i < 13; i++) {
        int cocok = 0;
        
        // Cek kategori
        if ((strcmp(kunci, "PC") == 0 && strstr(devices[i].nama, "PC")) ||
            (strcmp(kunci, "PS") == 0 && strstr(devices[i].nama, "PS")) ||
            (strcmp(kunci, "NINTENDO") == 0 && strstr(devices[i].nama, "Nintendo")) ||
            strstr(devices[i].nama, kunci)) {
            cocok = 1;
        }
        
        if (cocok) {
            ditemukan = 1;
            printf("%s: ", devices[i].nama);
            
            if(devices[i].tersedia) {
                printf("Tersedia\n");
                tersedia++;
            } else {
                printf("Terpakai (%s)\n", devices[i].userBooking);
            }
        }
    }
    
    if(!ditemukan) {
        printf("Tidak ditemukan!\n");
    printf("========================================\n");
    }
    printf("========================================\n");
    
    printf("\nSTATISTIK:\nTersedia: %d/%d\n", tersedia, 13);
    
    pauseProgram();
}


//VLIST MENU UTAMA
void list(int menu) { 

    if (cekUserSedangRental()) { // CEK DULU APAKAH  APAKAH UUSER SEDANG RENTAL DEVICE LAIN
        printf("\n ERROR: Anda sudah menyewa device lain!\n"); //JIKA YA MUNCUL INI
        tampilkanDeviceYangDisewa();
        printf("\nSilakan selesaikan rental tersebut sebelum menyewa device lain.\n");
        pauseProgram();
        return;
    }
    // MENU RENTAL
    int jam; // VARIABEL JAM 
    char lanjut; //
    
    switch (menu) {
        case 1: { // PC
            int pc;
            int hargapc;
            
            while (1) {
                printf("\n=== RENTAL PC ===\n");
                printf("================================\n");
                printf("Pilih PC yang ingin dirental:\n");
                printf("1. PC A (Rp 5.000/jam)\n");
                printf("2. PC B (Rp 6.000/jam)\n");
                printf("3. PC C (Rp 7.000/jam)\n");
                printf("4. PC D (Rp 8.000/jam)\n");
                printf("5. PC E (Rp 9.000/jam)\n");
                printf("0. Kembali\n");
                printf("================================\n");
                printf("Pilihan: ");
                scanf("%d", &pc);

                if (pc == 0) return;
                
                char namaPC[20];
                switch (pc) {
                    case 1: 
                        strcpy(namaPC, "PC A"); 
                        hargapc = 5000;
                        break;
                    case 2: 
                        strcpy(namaPC, "PC B"); 
                        hargapc = 6000;
                        break;
                    case 3: 
                        strcpy(namaPC, "PC C"); 
                        hargapc = 7000;
                        break;
                    case 4: 
                        strcpy(namaPC, "PC D"); 
                        hargapc = 8000;
                        break;
                    case 5:
                        strcpy (namaPC ,"PC E");
                        hargapc = 9000;
                        break;
                    default: 
                        printf("Pilihan tidak valid!\n");
                        pauseProgram();
                        continue;
                }
                
                // Cek apakah device tersedia
                int deviceTersedia = 0;
                for (int i = 0; i < 13; i++) {
                    if (strcmp(devices[i].nama, namaPC) == 0 && devices[i].tersedia == 1) {
                        deviceTersedia = 1;
                        break;
                    }
                }
                
                if (!deviceTersedia) {
                    printf("\n  %s sedang dipakai!\n", namaPC);
                    printf("Silakan pilih device lain atau coba lagi nanti.\n");
                    pauseProgram();
                    continue;
                }
                
                printf("\n=== SPESIFIKASI %s ===\n", namaPC);
                printf("================================\n");
                switch (pc) {
                    case 1:
                        printf("CPU: Intel Core i5-10400F\n");
                        printf("GPU: GTX 1650\n");
                        printf("RAM: 16 GB DDR4\n");
                        printf("Storage: SSD 512 GB\n");
                        printf("Monitor: 24 inch\n");
                        break;
                    case 2:
                        printf("CPU: Intel Core i5-11400F\n");
                        printf("GPU: GTX 1660\n");
                        printf("RAM: 16 GB DDR4\n");
                        printf("Storage: SSD 512 GB\n");
                        printf("Monitor: 24 inch\n");
                        break;
                    case 3:
                        printf("CPU: Ryzen 5 5600G\n");
                        printf("GPU: RTX 3050\n");
                        printf("RAM: 16 GB DDR4\n");
                        printf("Storage: SSD 512 GB\n");
                        printf("Monitor: 27 inch\n");
                        break;
                    case 4:
                        printf("CPU: Intel Core i7-11700F\n");
                        printf("GPU: RTX 3060\n");
                        printf("RAM: 32 GB DDR4\n");
                        printf("Storage: SSD 1 TB\n");
                        printf("Monitor: 27 inch\n");
                        break;
                    case 5:
                        printf("CPU: Ryzen 7 5800X\n");
                        printf("GPU: RTX 3060 Ti\n");
                        printf("RAM: 64 GB DDR4\n");
                        printf("Storage: SSD 1 TB\n");
                        printf("Monitor: 27 inch\n");
                        break;
                }
                printf("Harga: Rp %d/jam\n", hargapc);
                printf("================================\n");
                printf("\nLanjut rental dengan %s? (Y/T): ", namaPC);
                scanf(" %c", &lanjut);
                
                if (lanjut == 'Y' || lanjut == 'y') {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    
                    if (jam <= 0) {
                        printf("Jumlah jam tidak valid!\n");
                        pauseProgram();
                        continue;
                    }
                    
                    int totalHarga = hargapc * jam;
                    
                    if (pengguna[jumlahlogin].saldo < totalHarga) {
                        printf("Saldo tidak cukup! Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
                        pauseProgram();
                        continue;
                    }
                    
                    // Konfirmasi akhir
                    printf("\n=== KONFIRMASI RENTAL ===\n");
                    printf("Device: %s\n", namaPC);
                    printf("Durasi: %d jam\n", jam);
                    printf("Total harga: Rp %d\n", totalHarga);
                    printf("Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
                    printf("\nKonfirmasi rental? (Y/T): ");
                    scanf(" %c", &lanjut);
                    
                    if (lanjut == 'Y' || lanjut == 'y') {
                        pengguna[jumlahlogin].saldo -= totalHarga;
                        int menitTambahan = jam * 60;
                        pengguna[jumlahlogin].totalmenitbermain += menitTambahan;
                        
                        // Update status device
                        updateDeviceStatus(namaPC, 0, pengguna[jumlahlogin].username);
                        
                        char aktivitas[100];
                        sprintf(aktivitas, "Rental %s - %d jam (Rp %d)", namaPC, jam, totalHarga);
                        tambahRiwayat(aktivitas);
                        
                        printf("\n======================================\n");
                        printf("           RENTAL BERHASIL!\n");
                        printf("\n======================================\n");
                        printf(" %s telah dirental\n", namaPC);
                        printf(" Durasi: %d jam\n", jam);
                        printf(" Total bayar: Rp %d\n", totalHarga);
                        printf(" Saldo tersisa: Rp %d\n", pengguna[jumlahlogin].saldo);
                        printf(" Status: %s sekarang 'sedang dipakai'\n", namaPC);
                        printf("======================================\n");
                        
                        pauseProgram();
                        return;
                    } else {
                        printf("Rental dibatalkan.\n");
                        pauseProgram();
                    }
                }
            }
        } break;
        
        case 2: { // PlayStation
            int ps;
            int hargaPS;
            
            while (1) {
                printf("\n=== RENTAL PLAYSTATION ===\n");
                printf("================================\n");
                printf("Pilih PlayStation:\n");
                printf("1. PS A PS4 (Rp 7.000/jam)\n");
                printf("2. PS B PS4 PRO (Rp 8.000/jam)\n");
                printf("3. PS C PS5 (Rp 9.000/jam)\n");
                printf("4. PS D PS5 PRO (Rp 10.000/jam)\n");
                printf("0. Kembali\n");
                printf("================================\n");
                printf("Pilihan: ");
                scanf("%d", &ps);
                
                if (ps == 0) return;
                
                char namaPS[20];
                switch (ps) {
                    case 1: 
                        strcpy(namaPS, "PS4"); 
                        hargaPS = 7000;
                        break;
                    case 2: 
                        strcpy(namaPS, "PS4 PRO"); 
                        hargaPS = 8000;
                        break;
                    case 3: 
                        strcpy(namaPS, "PS5"); 
                        hargaPS = 9000;
                        break;
                    case 4: 
                        strcpy(namaPS, "PS5 PRO"); 
                        hargaPS = 10000;
                        break;
                    default: 
                        printf("Pilihan tidak valid!\n");
                        pauseProgram();
                        continue;
                }
                
                // Cek ketersediaan device
                int deviceTersedia = 0;
                for (int i = 0; i < 13; i++) {
                    if (strcmp(devices[i].nama, namaPS) == 0 && devices[i].tersedia == 1) {
                        deviceTersedia = 1;
                        break;
                    }
                }
                
                if (!deviceTersedia) {
                    printf("\n  %s sedang dipakai!\n", namaPS);
                    pauseProgram();
                    continue;
                }
                
                printf("\n=== RENTAL %s ===\n", namaPS);
                printf("Harga: Rp %d/jam\n", hargaPS);
                printf("Lanjut rental %s? (Y/T): ", namaPS);
                scanf(" %c", &lanjut);
                
                if (lanjut == 'Y' || lanjut == 'y') {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    
                    if (jam <= 0) {
                        printf("Jumlah jam tidak valid!\n");
                        pauseProgram();
                        continue;
                    }
                    
                    int totalHarga = hargaPS * jam;
                    
                    if (pengguna[jumlahlogin].saldo < totalHarga) {
                        printf("Saldo tidak cukup! Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
                        pauseProgram();
                        continue;
                    }
                    
                    // Konfirmasi
                    printf("\nTotal harga: Rp %d\n", totalHarga);
                    printf("Konfirmasi rental? (Y/T): ");
                    scanf(" %c", &lanjut);
                    
                    if (lanjut == 'Y' || lanjut == 'y') {
                        pengguna[jumlahlogin].saldo -= totalHarga;
                        int menitTambahan = jam * 60;
                        pengguna[jumlahlogin].totalmenitbermain += menitTambahan;
                        
                        // Update status device
                        updateDeviceStatus(namaPS, 0, pengguna[jumlahlogin].username);
                        
                        char aktivitas[100];
                        sprintf(aktivitas, "Rental %s - %d jam (Rp %d)", namaPS, jam, totalHarga);
                        tambahRiwayat(aktivitas);
                        
                        printf("\n======================================\n");
                        printf("           RENTAL BERHASIL!\n");
                        printf("=======================================\n");
                        printf(" %s telah dirental\n", namaPS);
                        printf(" Durasi: %d jam\n", jam);
                        printf(" Total bayar: Rp %d\n", totalHarga);
                        printf("Saldo tersisa: Rp %d\n", pengguna[jumlahlogin].saldo);
                        printf("======================================\n");
                        pauseProgram();
                        return;
                    } else {
                        printf("Rental dibatalkan.\n");
                        pauseProgram();
                    }
                }
            }
        } break;
        
        case 3: { // 
            int nintendo;
            int hargaNintendo = 6000;
            
            while (1) {
                printf("\n=== RENTAL NINTENDO SWITCH ===\n");
                printf("================================\n");
                printf("Pilih Nintendo Switch:\n");
                printf("1. Nintendo Switch A (Rp 6.000/jam)\n");
                printf("2. Nintendo Switch B (Rp 6.000/jam)\n");
                printf("3. Nintendo Switch C (Rp 6.000/jam)\n");
                printf("4. Nintendo Switch D (Rp 6.000/jam)\n");
                printf("0. Kembali\n");
                printf("================================\n");
                printf("Pilihan: ");
                scanf("%d", &nintendo);
                
                if (nintendo == 0) return; //JIKA USER MEMILIH AGNKA 0 MAKA DI RETURN DAN AKAN KEMBALI
                
                char namaNintendo[30]; // NAMA NITENDO 
                switch (nintendo) { // SWITCH DENGAN PARAMETER (NINTENDO)
                    case 1: strcpy(namaNintendo, "Nintendo Switch A"); break;
                    case 2: strcpy(namaNintendo, "Nintendo Switch B"); break;
                    case 3: strcpy(namaNintendo, "Nintendo Switch C"); break;
                    case 4: strcpy(namaNintendo, "Nintendo Switch D"); break;
                    default: 
                        printf("Pilihan tidak valid!\n");
                        pauseProgram();
                        continue;
                }
                
                // CEK DEVICE APAKAH TERSEDIA ATAU TIDAK 
                int deviceTersedia = 0;
                for (int i = 0; i < 13; i++) {
                    if (strcmp(devices[i].nama, namaNintendo) == 0 && devices[i].tersedia == 1) {
                        deviceTersedia = 1;
                        break;
                    }
                }
                
                if (!deviceTersedia) {
                    printf("\n  %s sedang dipakai!\n", namaNintendo);
                    pauseProgram();
                    continue;
                }
                
                printf("Lanjut rental? (Y/T): ");
                scanf(" %c", &lanjut);
                
                if (lanjut != 'Y' && lanjut != 'y') {
                    continue;
                }
                
                printf("\n=== %s ===\n", namaNintendo);
                printf("Harga: Rp 6.000/jam\n");
                
                printf("Masukkan jumlah jam: ");
                scanf("%d", &jam);
                
                if (jam <= 0) {
                    printf("Jumlah jam tidak valid!\n");
                    pauseProgram();
                    continue;
                }
                
                int totalHarga = hargaNintendo * jam;
                
                if (pengguna[jumlahlogin].saldo < totalHarga) {
                    printf("Saldo tidak cukup! Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
                    pauseProgram();
                    continue;
                }
                
                // Konfirmasi
                printf("Total harga: Rp %d\n", totalHarga);
                printf("Konfirmasi rental? (Y/T): ");
                scanf(" %c", &lanjut);
                
                if (lanjut == 'Y' || lanjut == 'y') {
                    pengguna[jumlahlogin].saldo -= totalHarga;
                    int menitTambahan = jam * 60;
                    pengguna[jumlahlogin].totalmenitbermain += menitTambahan;
                    
                    // Update status device
                    updateDeviceStatus(namaNintendo, 0, pengguna[jumlahlogin].username);
                    
                    char aktivitas[100];
                    sprintf(aktivitas, "Rental %s - %d jam (Rp %d)", namaNintendo, jam, totalHarga);
                    tambahRiwayat(aktivitas);
                    
                    printf("\n=======================================\n");
                    printf("           RENTAL BERHASIL!\n");
                    printf("=========================================\n");
                    printf(" %s telah dirental\n", namaNintendo);
                    printf(" Durasi: %d jam\n", jam);
                    printf(" Total bayar: Rp %d\n", totalHarga);
                    printf(" Saldo tersisa: Rp %d\n", pengguna[jumlahlogin].saldo);
                    printf("========================================\n");
                    pauseProgram();
                    return;
                } else {
                    printf("Rental dibatalkan.\n");
                    pauseProgram();
                }
            }
        } break;
    }
}


// FUNGSI HAPUS AKUN (MENU 6)
void hapusAkun() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        pauseProgram();
        return;
    }
    
    printf("\n=== HAPUS AKUN ANDA ===\n"); // TAMPILKAN APAKAH INGIN MENGHAPUS AKUN
    printf("Apakah anda yakin ingin menghapus akun anda?\n");
    printf("Username: %s\n", pengguna[jumlahlogin].username); // TAMPILKAN USERNAME 
    printf("Saldo: Rp %d\n", pengguna[jumlahlogin].saldo); //TAMPILKAN SALDO
    printf("Total waktu main: ");  
    bilangWaktu(pengguna[jumlahlogin].totalmenitbermain); // TAMPILKAN TOTAL MENIT BERMAIN 
    printf("\n\nPERINGATAN: Tindakan ini tidak dapat dibatalkan!\n");
    printf("Konfirmasi (Y/T): ");
    
    char konfirmasi; // VARIBAEL KONFIRMASI MENGGUNAKAN CHAR BERUPA HURUF Y ATAU y 
    scanf(" %c", &konfirmasi); // DICEK SESUAI INPUTAN USER
    
    if (konfirmasi == 'Y' || konfirmasi == 'y') { // KONFIRMASI SESUAI INPUT JIKA INPUTAN USER ADLAH Y 
        // Kosongkan device yang sedang dipakai user ini
        for (int i = 0; i < 13; i++) {
            if (strcmp(devices[i].userBooking, pengguna[jumlahlogin].username) == 0) {
                devices[i].tersedia = 1;
                strcpy(devices[i].userBooking, "");
            }
        }
        
        for (int i = jumlahlogin; i < jumlahuser - 1; i++) {
            pengguna[i] = pengguna[i + 1];
        }
        
        jumlahuser--;
        jumlahlogin = -1;
        
        printf("\nAkun berhasil dihapus!\n");
        printf("Anda akan dikembalikan ke menu utama.\n"); 
    } else {
        printf("\nPenghapusan akun dibatalkan.\n");
    }
    
    pauseProgram();
}

// FUNGSI TOP UP SALDO (MENU 7)
void topUpSaldo() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        pauseProgram();
        return;
    }
    
    printf("\n=== TOP UP SALDO ===\n");
    printf("Saldo saat ini: Rp %d\n", pengguna[jumlahlogin].saldo);
    printf("Masukkan nominal saldo yang ingin di top up (Rp): ");
    
    int nominal;
    if (scanf("%d", &nominal) != 1 || nominal <= 0) {
        printf("Masukkan nominal yang valid!\n");
        pauseProgram();
        return;
    }
    
    pengguna[jumlahlogin].saldo += nominal;
    
    char aktivitas[100];
    sprintf(aktivitas, "Top-up saldo Rp %d", nominal);
    tambahRiwayat(aktivitas);
    
    printf("Top-up berhasil!\n");
    printf("Saldo sekarang: Rp %d\n", pengguna[jumlahlogin].saldo);
    pauseProgram();
}

// FUNGSI EDIT USER (MENU 5) - BISA EDIT USERNAME DAN PASSWORD
void editUser() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        pauseProgram();
        return;
    }
    
    int pilihan;
    
    while(1) {
        printf("\n=== EDIT PROFIL ===\n");
        printf("1. Ganti username\n");
        printf("2. Ganti password\n");
        printf("3. Kembali\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        
        if (pilihan == 1) {
            char usernameBaru[30];
            printf("Masukkan username baru: ");
            scanf("%s", usernameBaru);
            
            // Cek apakah username sudah digunakan
            int usernameSudahAda = 0;
            for (int i = 0; i < jumlahuser; i++) {
                if (i != jumlahlogin && strcmp(pengguna[i].username, usernameBaru) == 0) {
                    usernameSudahAda = 1;
                    break;
                }
            }
            
            if (usernameSudahAda) {
                printf("Username sudah digunakan! Pilih username lain\n");
            } else {
                // Update username di semua device yang sedang dipakai
                for (int i = 0; i < 13; i++) {
                    if (strcmp(devices[i].userBooking, pengguna[jumlahlogin].username) == 0) {
                        strcpy(devices[i].userBooking, usernameBaru);
                    }
                }
                
                strcpy(pengguna[jumlahlogin].username, usernameBaru);
                printf("Username berhasil diganti!\n");
                
                char aktivitas[100];
                sprintf(aktivitas, "Ganti username menjadi %s", usernameBaru);
                tambahRiwayat(aktivitas);
            }
            pauseProgram();
            
        } else if (pilihan == 2) {
            char passwordLama[30], passwordBaru[30];
            printf("Masukkan password lama: ");
            scanf("%s", passwordLama);
            
            if (strcmp(pengguna[jumlahlogin].password, passwordLama) != 0) {
                printf("Password lama salah!\n");
                pauseProgram();
                continue;
            }
            
            printf("Masukkan password baru: ");
            scanf("%s", passwordBaru);
            
            strcpy(pengguna[jumlahlogin].password, passwordBaru);
            
            char aktivitas[100];
            sprintf(aktivitas, "Ganti password");
            tambahRiwayat(aktivitas);
            
            printf("Password berhasil diubah!\n");
            pauseProgram();
            
        } else if (pilihan == 3) {
            return;
        } else {
            printf("Pilihan tidak valid!\n");
            pauseProgram();
        }
    }
}

// FUNGSI SORTING BERDASARKAN LAMA BERMAIN (MENU 8)
void sortingLamaBermain() {
    if (jumlahuser == 0) {
        printf("Belum ada data pengguna!\n");
        pauseProgram();
        return;
    }
    
    struct User temp[100];
    for (int i = 0; i < jumlahuser; i++) {
        temp[i] = pengguna[i];
    }
    
    // Bubble sort descending berdasarkan total menit bermain
    for (int i = 0; i < jumlahuser - 1; i++) {
        for (int j = 0; j < jumlahuser - i - 1; j++) {
            if (temp[j].totalmenitbermain < temp[j+1].totalmenitbermain) {
                struct User swap = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = swap;
            }
        }
    }
    
    printf("\n=== RANKING PENGGUNA ===\n");
    printf("=========================================\n");
    printf("Rank  Username          Total Waktu      \n");
    printf("=========================================\n");
    
    for (int i = 0; i < jumlahuser; i++) {
        printf("%-4d  %-16s  ", i + 1, temp[i].username);
        bilangWaktu(temp[i].totalmenitbermain);
        printf ("\n");
        
    }
    printf("\n=========================================\n");
    
    printf("\n PENGGUNA DENGAN WAKTU BERMAIN TERBANYAK:\n");
    printf("Nama: %s\n", temp[0].username);
    printf("Total: ");
    bilangWaktu(temp[0].totalmenitbermain);
    printf("\n");
    
    int totalSemua = 0;
    for (int i = 0; i < jumlahuser; i++) {
        totalSemua += pengguna[i].totalmenitbermain;
    }
    printf("\n TOTAL SEMUA PENGGUNA: ");
    bilangWaktu(totalSemua);
    printf("\n");
    pauseProgram();
}

//EXIT PROGRAM USER KELUAR
void exitProgram() {
    printf("\nTerima kasih telah menggunakan program warnet!\n");
    pauseProgram();
    exit(0);
}

int main() {
    initDevices(); //PANGGIL NAMA NAMA DEVICES
    int pilihan; 
    
    while (1) {
        if (jumlahlogin == -1) { //JIKA JUMLAH LOGIN 
            mainMenu();
            scanf("%d", &pilihan);
            
            switch (pilihan) {
                case 1:
                    Signup();
                    break;
                case 2:
                    Signin();
                    break;
                case 3:
                    exitProgram();
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
                    pauseProgram();
            }
        } else {
            Warnetmenu();
            scanf("%d", &pilihan);
            
            switch (pilihan) {
                case 1: {
                    int pilihanDevice;
                    printf("\n=== RENTAL DEVICE ===\n");
                    printf("1. PC\n");
                    printf("2. PlayStation\n");
                    printf("3. Nintendo Switch\n");
                    printf("0. Kembali\n"); 
                    printf("====================\n");
                    printf("Pilih menu: ");
                    scanf("%d", &pilihanDevice);
                    
                    if (pilihanDevice == 0) {
                        break;
                    }
                    list(pilihanDevice);
                    break;
                }
                case 2:
                    tambahJamMain();
                    break;
                case 3:
                    cariDevice();
                    break;
                case 4:
                    editUser();
                    break;
                case 5:
                    hapusAkun();
                    break;
                case 6:
                    topUpSaldo();
                    break;
                case 7:
                    sortingLamaBermain();
                    break;
                case 8:
                    jumlahlogin = -1;
                    printf("Logout berhasil!\n");
                    pauseProgram();
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
                    pauseProgram();
            }
        }
    }
    
    return 0;
}