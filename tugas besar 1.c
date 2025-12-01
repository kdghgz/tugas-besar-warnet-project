#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//tes perubahan lagi


//IDENTITAS USER
struct User {
    char username[30];
    char password[30];
    int saldo;
    int totalmenitbermain;
    int riwayatdalambermain;
    char riwayat[50][100]; 
};

//UNTUK MENYIMPAN DATA USER
struct User pengguna[100]; // data dapat ditampung hanya 100 org
int jumlahuser = 0; // jumlah user 
int jumlahlogin = -1; // dimulai dari -1 karena sebagai index jika 0 maka ada orang yang login 

// PROCEDURE 
void mainMenu();
void Warnetmenu();
void Signup();
void Signin();
void list(int menu);
void exitProgram();

// MAIN MENU WARNET USER UNTUK LOGIN DAN REGISTER edit di ihda
void mainMenu(){
    printf(" ========================================\n");
    
    for (int i = 0; i < 5; i++) {
        if(i == 2){  
            printf("| %29s |\n", "SELAMAT DATANG\t\t");
            printf("| %23s |\n", "DI\t");
            printf("| %28s |\n", "WARNET\t");
            printf("| %34s |\n", "tongkrongannya para gamers\t");
        } else {
            printf("|\t\t\t\t\t|\n");
        }
    }
    
    //
    printf(" ========================================\n");
    printf("| %34s |\n", "Pilih ");
    printf(" ========================================\n");
    
    printf("| 1. Sign Up (buat akun baru)\t\t|\n");
    printf("| 2. Sign In (login)\t\t\t|\n");
    printf("| 3. Exit\t\t\t\t|\n");
    
    printf(" ========================================\n");
    printf("\n");
}

//WARNET MENU DIMANA USER DIHADAPKAN OLEH BEBERAPA PILIHAN YANG TERSEDIA DI WARNET
void Warnetmenu() {
    printf("\nSelamat datang di Warnet! \n");
    printf("silahkan pilih menu yang tersedia di warnet kami!\n");
    printf(" 1. Rental Device (PC/PS/NITENDO)\n");
    printf(" 2. Tambah jam main\n");
    printf(" 3. Searching atau cek device kosong\n");
    printf(" 4. Riwayat pemakaian\n");
    printf(" 5. Edit user\n");
    printf(" 6. Delete user\n");
    printf(" 7. Top up saldo\n");
    printf(" 8. Sorting daftar user\n");
    printf(" 9. Log out\n");
    printf("Pilihan Anda: ");
}

//SIGN UP DIMANA USER MENGHARUSKAN DAFTAR ATAU REGISTER AGAR TERDATA
void Signup() {
    char usernameuserbaru[50];
    char passwordbaru[50];
    
    printf("Memilih Sign Up\n");
    printf("silakan masukan username yang anda ingin buat: ");
    scanf("%s", usernameuserbaru);
    
    printf("masukan password yang anda ingin buat: ");
    scanf("%s", passwordbaru);
    
    // Cek apakah username sudah ada
    for (int i = 0; i < jumlahuser; i++) {
        if (strcmp(pengguna[i].username, usernameuserbaru) == 0) {
            printf("username sudah digunakan! pilih username lain\n");
            return;
        }
    }
    
    // AGAR BISA TAMBAH USER BARU
    strcpy(pengguna[jumlahuser].username, usernameuserbaru);
    strcpy(pengguna[jumlahuser].password, passwordbaru);
    pengguna[jumlahuser].saldo = 0;
    pengguna[jumlahuser].totalmenitbermain = 0;
    pengguna[jumlahuser].riwayatdalambermain = 0;
    
    jumlahuser++;
    printf("selamat username telah didaftarkan!\n");
    printf("silahkan tekan enter untuk kembali ke menu awal untuk login\n");
    getchar(); // clear buffer
    getchar(); // tunggu enter
}

void Signin() {
    char username[50];
    char password[50];
    
    printf("memilih Sign In\n");
    printf("silakan masukan username anda: ");
    scanf("%s", username);
    
    printf("silakan masukan password anda: ");
    scanf("%s", password);
    
    for (int i = 0; i < jumlahuser; i++) {
        if (strcmp(pengguna[i].username, username) == 0 &&
            strcmp(pengguna[i].password, password) == 0) {
            jumlahlogin = i;
            printf("login berhasil!\n selamat datang %s\n", username);
            return;
        }
    }
    
    printf("Username atau password salah!\n");
}

void list(int menu) {
    int jam;
    
    switch (menu) {
        case 1: {
            int pc;
            char lanjut;
            
            while (1) {
                printf("1. Jenis PC A\n");
                printf("2. Jenis PC B\n");
                printf("3. Jenis PC C\n");
                printf("4. Jenis PC D\n");
                printf("5. Jenis PC E\n");
                printf("6. Kembali ke menu sebelumnya\n");
                printf("====================\n");
                printf("Pilih Jenis PC: ");
                scanf("%d", &pc);
                printf("====================\n");
                
                switch (pc) {
                    case 1:
                        printf("==== Jenis PC A ====\n");
                        printf("CPU: Intel Core i5-10400F \nGPU: GTX 1650\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 24 inch\n");
                        printf("====================\n");
                        printf("Lanjut rental dengan PC A ? (Y/T): ");
                        scanf(" %c", &lanjut);
                        printf("====================\n");
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PC A disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            // Simpan riwayat
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PC A - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 2:
                        printf("==== Jenis PC B ====\n");
                        printf("CPU: Intel Core i5-11400F \nGPU: GTX 1660\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 24 inch\n");
                        printf("====================\n");
                        printf("Lanjut rental dengan PC B ? (Y/T): ");
                        scanf(" %c", &lanjut);
                        printf("====================\n");
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PC B disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PC B - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 3:
                        printf("==== Jenis PC C ====\n");
                        printf("CPU: Ryzen 5 5600G \nGPU: RTX 3050\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 27 inch\n");
                        printf("====================\n");
                        printf("Lanjut rental dengan PC C ? (Y/T): ");
                        scanf(" %c", &lanjut);
                        printf("====================\n");
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PC C disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PC C - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 4:
                        printf("==== Jenis PC D ====\n");
                        printf("CPU: Intel Core i7-11700F \nGPU: RTX 3060\nRAM: 32 GB DDR4\nStorage: SSD 1 TB\nMonitor: 27 inch\n");
                        printf("====================\n");
                        printf("Lanjut rental dengan PC D ? (Y/T): ");
                        scanf(" %c", &lanjut);
                        printf("====================\n");
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PC D disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PC D - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 5:
                        printf("==== Jenis PC E ====\n");
                        printf("CPU: Ryzen 7 5800X \nGPU: RTX 3060 Ti\nRAM: 64 GB DDR4\nStorage: SSD 1 TB\nMonitor: 27 inch\n");
                        printf("====================\n");
                        printf("Lanjut rental dengan PC E ? (Y/T): ");
                        scanf(" %c", &lanjut);
                        printf("====================\n");
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PC E disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PC E - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                    case 6:
                        return;
                }
            }
        } break;
        
        case 2: {
            int ps;
            char lanjut;
            
            while (1) {
                printf("1. PS 4\n");
                printf("2. PS 4 PRO\n");
                printf("3. PS 5\n");
                printf("4. PS 5 PRO\n");
                printf("5. Kembali ke menu sebelumnya\n");
                printf("====================\n");
                printf("Pilih Jenis PS: ");
                scanf("%d", &ps);
                
                switch (ps) {
                    case 1:
                        printf("=== PS4 ===\n");
                        printf("Lanjut rental PS4? (Y/T): ");
                        scanf(" %c", &lanjut);
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PS 4 disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PS4 - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 2:
                        printf("=== PS4 PRO ===\n");
                        printf("Lanjut rental PS4 PRO? (Y/T): ");
                        scanf(" %c", &lanjut);
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PS 4 PRO disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PS4 PRO - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 3:
                        printf("=== PS5 ===\n");
                        printf("Lanjut rental PS5? (Y/T): ");
                        scanf(" %c", &lanjut);
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PS 5 disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PS5 - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 4:
                        printf("=== PS5 PRO ===\n");
                        printf("Lanjut rental PS5 PRO? (Y/T): ");
                        scanf(" %c", &lanjut);
                        
                        if (lanjut == 'Y' || lanjut == 'y') {
                            printf("Masukkan jumlah jam: ");
                            scanf("%d", &jam);
                            printf("====================\n");
                            printf("Booking berhasil! PS 5 PRO disewa %d jam.\n", jam);
                            printf("====================\n");
                            
                            if (jumlahlogin != -1) {
                                sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                        "PS5 PRO - %d jam", jam);
                                pengguna[jumlahlogin].riwayatdalambermain++;
                                pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                            }
                            return;
                        }
                        break;
                        
                    case 5:
                        return;
                }
            }
        } break;
        
        case 3: {
            char lanjut;
            
            while (1) {
                printf("Lanjut rental Nintendo Switch? (Y/T): ");
                scanf(" %c", &lanjut);
                
                if (lanjut == 'Y' || lanjut == 'y') {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! Nintendo Switch disewa %d jam.\n", jam);
                    printf("====================\n");
                    
                    if (jumlahlogin != -1) {
                        sprintf(pengguna[jumlahlogin].riwayat[pengguna[jumlahlogin].riwayatdalambermain], 
                                "Nintendo Switch - %d jam", jam);
                        pengguna[jumlahlogin].riwayatdalambermain++;
                        pengguna[jumlahlogin].totalmenitbermain += jam * 60;
                    }
                    return;
                } else {
                    return;
                }
            }
        } break;
    }
}

// FUNGSI  RIWAYAT PENGGUNA
void tampilkanRiwayat() {
    if (jumlahlogin == -1) {
        printf("Anda belum login!\n");
        return;
    }
    
    printf("\n=== RIWAYAT PENGGUNAAN ===\n");
    printf("Username: %s\n", pengguna[jumlahlogin].username);
    printf("Total menit bermain: %d menit\n", pengguna[jumlahlogin].totalmenitbermain);
    printf("Riwayat rental:\n");
    
    if (pengguna[jumlahlogin].riwayatdalambermain == 0) {
        printf("Belum ada riwayat rental\n");
    } else {
        for (int i = 0; i < pengguna[jumlahlogin].riwayatdalambermain; i++) {
            printf("%d. %s\n", i+1, pengguna[jumlahlogin].riwayat[i]);
        }
    }
    printf("====================\n");
}

//EXIT PROGRAM USER KELUAR
void exitProgram() {
    printf("Apakah anda yakin ingin menyelesaikan ini semua?\n");
    getchar(); 
    printf("ayo main lagi ;)\n");
    getchar();
    printf("ayo dong main lagi! >:D \n");
    getchar(); 
    printf("yah yakin kamu mau pergi? :( \n");
    getchar(); 
    printf("beneran yakin nihh aku bakal kengen lohh:( \n");
    getchar(); 
    printf("yah yasudah lain kali main lagi yaaaa :3 \n");
    getchar(); 
    printf("Terima kasih! Silakan datang lagi semoga harimu menyenangkan.\n");
    getchar(); 
    exit(0);
}

int main() {
    int pilihan;
    
    while (1) {
        if (jumlahlogin == -1) {
            // Menu utama untuk login/register
            mainMenu();
            printf("Pilih menu: ");
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
            }
        } else {
            // Menu setelah login berhasil
            int pilihanWarnet;
            Warnetmenu();
            scanf("%d", &pilihanWarnet);
            
            switch (pilihanWarnet) {
                case 1: {
                    int pilihanDevice;
                    printf("====================\n");
                    printf("1. PC\n");
                    printf("2. PlayStation\n");
                    printf("3. Nintendo Switch\n");
                    printf("0. Kembali\n"); 
                    printf("====================\n");
                    printf("Rental yang dipilih: ");
                    scanf("%d", &pilihanDevice);
                    printf("====================\n");
                    
                    if (pilihanDevice == 0) {
                        break;
                    }
                    list(pilihanDevice);
                    break;
                }
                case 4:
                    tampilkanRiwayat();
                    break;
                case 9:
                    jumlahlogin = -1;
                    printf("Logout berhasil!\n");
                    break;
                default:
                    printf("Fitur belum diimplementasikan\n");
            }
        }
    }

    //tes
    
    return 0;
}
