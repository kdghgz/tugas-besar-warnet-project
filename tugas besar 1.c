// final amin YANG BERHASIL YANG BERHASIL YANG INI WOK TINGGAL TAMBAHIN INT MAIN

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>


// MENYIMPAN IDENTITAS USER
struct User {
    char username[30];
    char password[30];
    int saldo;
    int totalmenitbermain;
    int riwayatdalambermain;
    char riwayat[50][100];
};

// UNTUK MENYIMPAN DATA USER 
struct User pengguna[100]; // STRUCT PENGGUNA USER HANYA MENYIMPAN 100 USER
int jumlahuser = 0; //
int jumlahlogin = -1; //SIMPAN LOGIN USER DIMULAI DARI -1 SESUAI INDEKS, JIKA ADA USER DIMULAI DARI 0 

// STATUS DEVICE UNTUK BOOKING APAKAH DEVICE TERSEDIA 
struct Device {
    char nama[50]; // NAMA USER BATAS SAMPAI 50
    int tersedia; // 1 = DEVICE Tersedia, 0 = DEVICE sedang dimainkan 
    char userBooking[30]; // JUMLAH USER YANG BOOKING
};

struct Device devices[13]; // TOTAL JUMLAH DEVICE TERSEDIA

// INISIALISASI DEVICE
void initDevices() {
    char *namaDevices[] = {
        "PC A", "PC B", "PC C", "PC D", "PC E",
        "PS4", "PS4 Pro", "PS5", "PS5 Pro",
        "Nintendo Switch A", "Nintendo Switch B", 
        "Nintendo Switch C", "Nintendo Switch D"
    };
    
    for(int i = 0; i < 13; i++) {
        strcpy(devices[i].nama, namaDevices[i]);
        devices[i].tersedia = 1;
        strcpy(devices[i].userBooking, "");
    }
}

// FUNGSI UNTUK PAUSE AGAR BISA LANJUT KE PILIHAN BERIKUTNYA
void pauseProgram() {
    printf("\nTekan Enter untuk melanjutkan...");
    while(getchar() != '\n');
    getchar();
}

// FUNGSI UNTUK MENAMBAH RIWAYAT
void tambahRiwayat(const char* aktivitas) {
    if (jumlahlogin == -1) return;
    
    if (pengguna[jumlahlogin].riwayatdalambermain < 50) {
        strcpy(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], aktivitas);
        pengguna[jumlahlogin].riwayatdalambermain++;
    }
}

// FUNGSI UPDATE STATUS DEVICE
void updateDeviceStatus(const char* deviceName, int status, const char* username) {
    for (int i = 0; i < 13; i++) {
        if (strcmp(devices[i].nama, deviceName) == 0) {
            devices[i].tersedia = status;
            if (status == 0) {
                strcpy(devices[i].userBooking, username);
            } else {
                strcpy(devices[i].userBooking, "");
            }
            break;
        }
    }
}

// FUNGSI UNTUK MEMBILANG WAKTU DALAM KATA-KATA
void bilangWaktu(int menit) {
    int jam = menit / 60;
    int sisaMenit = menit % 60;
    
    if (jam > 0 && sisaMenit > 0) {
        printf("%d jam %d menit", jam, sisaMenit);
    } else if (jam > 0) {
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
void tampilkanRiwayat(); // RIWAYAT PENGGUNA NGAPAIN AJA (MENU 4)
void editUser(); // EDIT USER (MENU 5) TUBES-EDIT !
void hapusAkun(); // HAPUS AKUN (MENU 6) TUBES - DELETE !
void topUpSaldo(); // TOP UP SALDO (MENU 7)
void sortingLamaBermain(); // URUTKAN (MENU 8) TUBES- SORTING !





// MAIN MENU WARNET USER UNTUK LOGIN DAN REGISTER 
void mainMenu(){
 printf(" ========================================\n");

    for (int i = 0; i < 5; i++)
{
    if(i == 2){  
        printf("| %29s \n", "SELAMAT DATANG\t\t|");
        printf("| %23s \n", "DI\t\t\t|");
        printf("| %25s \n", "WARNET\t\t\t|");
        printf("| %34s \n", "tongkrongannya para gamers\t|");
    } else {
        printf("|\t\t\t\t\t|\n");
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

// WARNET MENU DIMANA USER DIHADAPKAN OLEH BEBERAPA PILIHAN YANG TERSEDIA DI WARNET
void Warnetmenu() {
    printf("\n========================================\n");
    printf("Selamat datang di Warnet %s!\n", pengguna[jumlahlogin].username);
    printf("Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
    printf("Total waktu main: ");
    bilangWaktu(pengguna[jumlahlogin].totalmenitbermain);
    printf("\n========================================\n");
    printf("Silahkan pilih menu yang tersedia:\n");
    printf(" 1. Rental Device (PC/PS/NINTENDO)\n");
    printf(" 2. Tambah jam main\n");
    printf(" 3. Cek device kosong\n");
    printf(" 4. Riwayat pemakaian\n");
    printf(" 5. Edit profil\n");
    printf(" 6. Hapus akun\n");
    printf(" 7. Top up saldo\n");
    printf(" 8. Sorting daftar user\n");
    printf(" 9. Log out\n");
    printf("========================================\n");
    printf("Pilihan Anda: ");
}

// SIGN UP DIMANA USER MENGHARUSKAN DAFTAR ATAU REGISTER AGAR TERDATA
void Signup() {
    char usernameuserbaru[50];
    char passwordbaru[50];
    
    printf("\n=== SIGN UP (BUAT AKUN BARU) ===\n");
    printf("Silakan masukan username yang anda ingin buat: ");
    scanf("%s", usernameuserbaru);
    
    printf("Masukan password yang anda ingin buat: ");
    scanf("%s", passwordbaru);
    
    for (int i = 0; i < jumlahuser; i++) {
        if (strcmp(pengguna[i].username, usernameuserbaru) == 0) {
            printf("Username sudah digunakan! Pilih username lain\n");
            pauseProgram();
            return;
        }
    }
    
    strcpy(pengguna[jumlahuser].username, usernameuserbaru);
    strcpy(pengguna[jumlahuser].password, passwordbaru);
    pengguna[jumlahuser].saldo = 0;
    pengguna[jumlahuser].totalmenitbermain = 0;
    pengguna[jumlahuser].riwayatdalambermain = 0;
    
    jumlahuser++;
    printf("Selamat username telah didaftarkan!\n");
    printf("Silakan login dengan akun baru Anda.\n");
    pauseProgram();
}

void Signin() {
    char username[50];
    char password[50];
    
    printf("\n=== SIGN IN (LOGIN) ===\n");
    printf("Silakan masukan username anda: ");
    scanf("%s", username);
    
    printf("Silakan masukan password anda: ");
    scanf("%s", password);
    
    for (int i = 0; i < jumlahuser; i++) {
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
    printf("\n=== TAMBAH JAM MAIN ===\n");
    printf("Masukkan jumlah jam tambahan: ");
    
    int jam;
    scanf("%d", &jam);
    
    if (jam <= 0) {
        printf("Jumlah jam tidak valid!\n");
        pauseProgram();
        return;
    }
    
    int harga = 5000;
    int totalHarga = harga * jam;
    
    printf("Harga tambahan: Rp %d\n", totalHarga);
    
    if (pengguna[jumlahlogin].saldo < totalHarga) {
        printf("Saldo tidak cukup! Saldo Anda: Rp %d\n", pengguna[jumlahlogin].saldo);
        pauseProgram();
        return;
    }
    
    char konfirmasi;
    printf("Konfirmasi tambah %d jam? (Y/T): ", jam);
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'Y' || konfirmasi == 'y') {
        pengguna[jumlahlogin].saldo -= totalHarga;
        int menitTambahan = jam * 60;
        pengguna[jumlahlogin].totalmenitbermain += menitTambahan;
        
        char aktivitas[100];
        sprintf(aktivitas, "Tambah jam main - ");
        bilangWaktu(menitTambahan);
        strcat(aktivitas, " (Rp ");
        char hargaStr[20];
        sprintf(hargaStr, "%d)", totalHarga);
        strcat(aktivitas, hargaStr);
        tambahRiwayat(aktivitas);
        
        printf("\n Berhasil menambah ");
        bilangWaktu(menitTambahan);
        printf("!\n");
        printf(" Saldo tersisa: Rp %d\n", pengguna[jumlahlogin].saldo);
        pauseProgram();
    } else {
        printf("Batal menambah jam.\n");
        pauseProgram();
    }
}

// FUNGSI UNTUK CARI DEVICE KOSONG (MENU 3) - SEQUENTIAL SEARCH SEDERHANA
void cariDevice() {
    printf("\n=== CARI DEVICE ===\n");
    printf("========================================\n");
    printf("PETUNJUK PENCARIAN:\n");
    printf(" Ketik 'PC' untuk semua PC\n");
    printf(" Ketik 'PS' untuk semua PlayStation\n");
    printf(" Ketik 'NINTENDO' untuk semua Nintendo\n");
    printf("========================================\n");
    printf("Masukkan kata kunci: ");
    
    char kataKunci[50];
    scanf("%s", kataKunci);
    
    printf("\n=== HASIL PENCARIAN ===\n");
    printf("========================================\n");
    
    int ditemukan = 0;
    
    // Sequential Search sederhana
    for(int i = 0; i < 13; i++) {
        int cocok = 0;
        
        // Cek kategori umum
        if (strcmp(kataKunci, "PC") == 0) {
            if (strstr(devices[i].nama, "PC") != NULL) {
                cocok = 1;
            }
        }
        else if (strcmp(kataKunci, "PS") == 0) {
            if (strstr(devices[i].nama, "PS") != NULL) {
                cocok = 1;
            }
        }
        else if (strcmp(kataKunci, "NINTENDO") == 0) {
            if (strstr(devices[i].nama, "Nintendo") != NULL) {
                cocok = 1;
            }
        }
        else {
            // Cari nama spesifik
            if (strstr(devices[i].nama, kataKunci) != NULL) {
                cocok = 1;
            }
        }
        
        if (cocok) {
            ditemukan = 1;
            printf("%-20s: ", devices[i].nama);
            
            if(devices[i].tersedia == 1) {
                printf("Tersedia\n");
            } else {
                printf("Terpakai (%s)\n", devices[i].userBooking);
            }
        }
    }
    
    if(!ditemukan) {
        printf("Tidak ditemukan device dengan kata kunci '%s'\n", kataKunci);
    }
    
    printf("========================================\n");
    
    // Statistik
    printf("\n=== STATISTIK ===\n");
    printf("Total Device: 13\n");
    
    int tersedia = 0;
    for(int i = 0; i < 13; i++) {
        if(devices[i].tersedia == 1) tersedia++;
    }
    
    printf("Device Tersedia: %d\n", tersedia);
    printf("Device Terpakai: %d\n", 13 - tersedia);
    printf("========================================\n");
    
    pauseProgram();
}

void list(int menu) {
    int jam;
    char lanjut;
    
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
        
        case 3: { // Nintendo Switch
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
                
                if (nintendo == 0) return;
                
                char namaNintendo[30];
                switch (nintendo) {
                    case 1: strcpy(namaNintendo, "Nintendo Switch A"); break;
                    case 2: strcpy(namaNintendo, "Nintendo Switch B"); break;
                    case 3: strcpy(namaNintendo, "Nintendo Switch C"); break;
                    case 4: strcpy(namaNintendo, "Nintendo Switch D"); break;
                    default: 
                        printf("Pilihan tidak valid!\n");
                        pauseProgram();
                        continue;
                }
                
                // Cek ketersediaan device
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

// FUNGSI RIWAYAT PENGGUNA (SIMPLE - hanya nama user dan lama waktu main)
void tampilkanRiwayat() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        pauseProgram();
        return;
    }
    
    printf("\n=== RIWAYAT PENGGUNAAN ===\n");
    printf("Username: %s\n", pengguna[jumlahlogin].username);
    printf("Total waktu main: ");
    bilangWaktu(pengguna[jumlahlogin].totalmenitbermain);
    printf("\n");
    
    if (pengguna[jumlahlogin].riwayatdalambermain == 0) {
        printf("Belum ada riwayat aktivitas\n");
    } else {
        printf("Riwayat:\n");
        for (int i = 0; i < pengguna[jumlahlogin].riwayatdalambermain; i++) {
            printf("- %s\n", pengguna[jumlahlogin].riwayat[i]);
        }
    }
    printf("========================================\n");
    pauseProgram();
}

// FUNGSI HAPUS AKUN (MENU 6)
void hapusAkun() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        pauseProgram();
        return;
    }
    
    printf("\n=== HAPUS AKUN ANDA ===\n");
    printf("Apakah anda yakin ingin menghapus akun anda?\n");
    printf("Username: %s\n", pengguna[jumlahlogin].username);
    printf("Saldo: Rp %d\n", pengguna[jumlahlogin].saldo);
    printf("Total waktu main: ");
    bilangWaktu(pengguna[jumlahlogin].totalmenitbermain);
    printf("\n\nPERINGATAN: Tindakan ini tidak dapat dibatalkan!\n");
    printf("Konfirmasi (Y/T): ");
    
    char konfirmasi;
    scanf(" %c", &konfirmasi);
    
    if (konfirmasi == 'Y' || konfirmasi == 'y') {
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

