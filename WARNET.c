#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list(int menu)

// test
{
    int jam;

    switch (menu)
    {
    case 1:
    {
        int pc;
        char lanjut;

        while (1)
        {
            printf("1. Jenis PC A\n");
            printf("2. Jenis PC B\n");
            printf("3. Jenis PC C\n");
            printf("4. Jenis PC D\n");
            printf("5. Jenis PC E\n");
            printf("6. Kembali ke menu sebelumnya\n");
            printf("====================\n");
            printf("Pilih Jenis PC: ");
            scanf(" %d", &pc);
            printf("====================\n");

            switch (pc)
            {
            case 1:
                printf("==== Jenis PC A ====\n");
                printf("CPU: Intel Core i5-10400F \nGPU: GTX 1650\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 24 inch\n");
                printf("====================\n");
                printf("Lanjut rental dengan PC A ? (Y/T): ");
                scanf(" %c", &lanjut);
                printf("====================\n");

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PC A disewa %d jam\n", jam);
                    printf("====================\n");

                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");
                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                    
                }
                break;

            case 2:
                printf("==== Jenis PC B ====\n");
                printf("CPU: Intel Core i5-11400F \nGPU: GTX 1660\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 24 inch\n");
                printf("====================\n");
                printf("Lanjut rental dengan PC B ? (Y/T): ");
                scanf(" %c", &lanjut);
                printf("====================\n");

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PC B disewa %d jam\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");
                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 3:
                printf("==== Jenis PC C ====\n");
                printf("CPU: Ryzen 5 5600G \nGPU: RTX 3050\nRAM: 16 GB DDR4\nStorage: SSD 512 GB\nMonitor: 27 inch\n");
                printf("====================\n");
                printf("Lanjut rental dengan PC C ? (Y/T): ");
                scanf(" %c", &lanjut);
                printf("====================\n");

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PC C disewa %d jam\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");
                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 4:
                printf("==== Jenis PC D ====\n");
                printf("CPU: Intel Core i7-11700F \nGPU: RTX 3060\nRAM: 32 GB DDR4\nStorage: SSD 1 TB\nMonitor: 27 inch\n");
                printf("====================\n");
                printf("Lanjut rental dengan PC D ? (Y/T): ");
                scanf(" %c", &lanjut);
                printf("====================\n");

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PC D disewa %d jam\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");
                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 5:
                printf("==== Jenis PC E ====\n");
                printf("CPU: Ryzen 7 5800X \nGPU: RTX 3060 Ti\nRAM: 64 GB DDR4\nStorage: SSD 1 TB\nMonitor: 27 inch\n");
                printf("====================\n");
                printf("Lanjut rental dengan PC E ? (Y/T): ");
                scanf(" %c", &lanjut);
                printf("====================\n");

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PC E disewa %d jam\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");
                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;
            case 6:
                return;
            }
        }

    } break;

    case 2:
    {
        int ps;
        char lanjut;

        while (1)
        {
            printf("1. PS 4\n");
            printf("2. PS 4 PRO\n");
            printf("3. PS 5\n");
            printf("4. PS 5 PRO\n");
            printf("5. Kembali ke menu sebelumnya\n");
            printf("====================\n");
            printf("Pilih Jenis PS: ");
            scanf(" %d", &ps);

            switch (ps)
            {
            case 1:
                printf("=== PS4 ===\n");
                printf("Lanjut rental PS4? (Y/T): ");
                scanf(" %c", &lanjut);

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PS 4 disewa %d jam.\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");

                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 2:
                printf("=== PS4 PRO ===\n");
                printf("Lanjut rental PS4 PRO? (Y/T): ");
                scanf(" %c", &lanjut);

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PS 4 PRO disewa %d jam.\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");

                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 3:
                printf("=== PS5 ===\n");
                printf("Lanjut rental PS5? (Y/T): ");
                scanf(" %c", &lanjut);

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PS 5 disewa %d jam.\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");

                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 4:
                printf("=== PS5 PRO ===\n");
                printf("Lanjut rental PS5 PRO? (Y/T): ");
                scanf(" %c", &lanjut);

                if (lanjut == 'Y' || lanjut == 'y')
                {
                    printf("Masukkan jumlah jam: ");
                    scanf("%d", &jam);
                    printf("====================\n");
                    printf("Booking berhasil! PS 5 PRO disewa %d jam.\n", jam);
                    printf("====================\n");
                    
                    char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");

                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

                }
                break;

            case 5:
                return;
            }
        }

    } break;

    case 3:
    {
        char lanjut;

        while (1)
        {

            printf("Lanjut rental Nintendo Switch? (Y/T): ");
            scanf(" %c", &lanjut);

            if (lanjut == 'Y' || lanjut == 'y')
            {
                printf("Masukkan jumlah jam: ");
                scanf("%d", &jam);
                printf("====================\n");
                printf("Booking berhasil! Nintendo Switch disewa %d jam.\n", jam);
                printf("====================\n");
                
                char ingin;
                    printf("Ingin melanjutkan transaksi?(Y/T):");
                    scanf(" %c", &ingin);
                    printf("====================\n");

                    if (ingin == 'Y' || ingin == 'y') {
                        return;
                    } else {
                        printf("Terima kasih atas orderannya!\n");
                        printf("====================\n");
                        exit(0);
                    }

            }else 
            {
                return;
            }
            
        }

    } break;
    }
}

int main()
{
    int pilihan;

    while (1) 
    {
        printf("====================\n");
        printf("1. PC\n");
        printf("2. PlayStation\n");
        printf("3. Nintendo Switch\n");
        printf("0. Keluar\n"); 
        printf("====================\n");
        printf("Rental yang dipilih: ");
        scanf("%d", &pilihan);
        printf("====================\n");

        if (pilihan == 0)
        {
            printf("Hatur nuhun\n");
            break;
        }

        list(pilihan);
    }

    return 0;
}
