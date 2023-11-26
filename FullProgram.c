#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>

// Deklrasi
int choice;
int size, row, col, moves;
char player1[50], player2[50];
char board[7][7];

// Deklarasi Fungsi dan Prosedur
void rulesPlaying();
void leaderboard();
void playing();
void mainMenu();
void gameStart();
void displayBoard(char board[7][7], int size);
int checkWin(char board[7][7], int size, char player);
void printWin(int winner, char name[]);
void initializeBoard(char board[7][7], int size);
void stagegame();

// Fungsi dan Prosedur
//  Fungsi untuk menampilkan papan permainan
void displayBoard(char board[7][7], int size)
{
    int i, j, k;
    printf("\n");
    if (size == 3)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%c", board[i][j]);
                if (j < size - 1)
                {
                    printf(" | ");
                }
            }
            printf("\n");
            if (i < size - 1)
            {
                for (k = 0; k < size * 4 - 3; k++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
    }
    else if (size == 5)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%c", board[i][j]);
                if (j < size - 1)
                {
                    printf(" | ");
                }
            }
            printf("\n");
            if (i < size - 1)
            {
                for (k = 0; k < size * 4 - 3; k++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
    }
    else if (size == 7)
    {
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                printf("%c", board[i][j]);
                if (j < size - 1)
                {
                    printf(" | ");
                }
            }
            printf("\n");
            if (i < size - 1)
            {
                for (k = 0; k < size * 4 - 3; k++)
                {
                    printf("-");
                }
                printf("\n");
            }
        }
    }
}

// Fungsi untuk memeriksa apakah ada pemenang
int checkWin(char board[7][7], int size, char player)
{
    if (size == 5 || size == 7)
    {
        int symbolsInLine = (size == 5) ? 4 : 5;

        // Additional logic for horizontal and vertical wins
        for (int i = 0; i <= size - symbolsInLine; i++)
        {
            for (int j = 0; j < size; j++)
            {
                int rowWin = 1;
                int colWin = 1;
                for (int k = 0; k < symbolsInLine; k++)
                {
                    if (board[i + k][j] != player)
                    {
                        rowWin = 0;
                    }
                    if (board[j][i + k] != player)
                    {
                        colWin = 0;
                    }
                }
                if (rowWin || colWin)
                {
                    return 1; // Row or column win
                }
            }
        }

        // Pengecekan kemenangan diagonal dari kiri atas ke kanan bawah 
        for (int i = 0; i <= size - symbolsInLine; i++)
        {
            for (int j = 0; j <= size - symbolsInLine; j++)
            {
                int diagWin = 1;
                for (int k = 0; k < symbolsInLine; k++)
                {
                    if (board[i + k][j + k] != player)
                    {
                        diagWin = 0;
                    }
                }
                if (diagWin)
                {
                    return 1;
                }
            }
        }

        // Pengecekan kemenangan diagonal dari kanan atas ke kiri bawah
        for (int i = 0; i <= size - symbolsInLine; i++)
        {
            for (int j = symbolsInLine - 1; j < size; j++)
            {
                int diagWin = 1;
                for (int k = 0; k < symbolsInLine; k++)
                {
                    if (board[i + k][j - k] != player)
                    {
                        diagWin = 0;
                    }
                }
                if (diagWin)
                {
                    return 1; 
                }
            }
        }
        return 0; // Tidak Ada Pemenang
    }
    else if (size == 3)
    {
        for (int i = 0; i < size; i++)
        {
            int rowWin = 1;
            int colWin = 1;
            for (int j = 0; j < size; j++)
            {
                if (board[i][j] != player)
                {
                    rowWin = 0;
                }
                if (board[j][i] != player)
                {
                    colWin = 0;
                }
            }
            if (rowWin || colWin)
            {
                return 1; // Baris atau kolom menang
            }
            int diagWin1 = 1;
            int diagWin2 = 1;

            for (int i = 0; i < size; i++)
            {
                if (board[i][i] != player)
                {
                    diagWin1 = 0;
                }
                if (board[i][size - 1 - i] != player)
                {
                    diagWin2 = 0;
                }
            }

            if (diagWin1 || diagWin2)
            {
                return 1; // Diagonal menang
            }

            
        }
    }
    return 0; // Tidak ada pemenang
}

// Tampilan hasil game selesai
void printWin(int winner, char name[])
{
    system("cls");
    printf("\n");
    switch (winner)
    {
    case 1:
        printf("Game is Tie");
        break;
    case 2:
        printf("%s Win", name);
        break;
    case 3:
        printf("%s Win", name);
        break;
    }
}

// Fungsi untuk menginisialisasi papan permainan
void initializeBoard(char board[7][7], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void stagegame()
{
    system("cls");
    printf("\n_________________|=============|_________________");
    printf("\n|                |==INPUTNAME==|                |");
    printf("\n|                |=============|                |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|            Masukkan nama pemain 1             |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|_______________________________________________|");
    printf("\n\t\tInput Nama:");
    scanf("%s", player1);
    system("cls");

    printf("\n_________________|=============|_________________");
    printf("\n|                |==INPUTNAME==|                |");
    printf("\n|                |=============|                |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|            Masukkan nama pemain 2             |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|_______________________________________________|");
    printf("\n\t\tInput Nama:");
    scanf("%s", player2);
    system("cls");

    initializeBoard(board, size);
    moves = 0;

    do
    {
        system("cls");

        // Tampilkan papan permainan
        displayBoard(board, size);

        // Gantian pemain
        char currentPlayer = (moves % 2 == 0) ? 'X' : 'O';

        // Input posisi dari pemain
        printf("Giliran pemain %s (%c). Masukkan baris (1-%d) dan kolom (1-%d): ",
               (currentPlayer == 'X') ? player1 : player2, currentPlayer, size, size);
        scanf("%d %d", &row, &col);

        // Validasi input
        if (row < 1 || row > size || col < 1 || col > size || board[row - 1][col - 1] != ' ')
        {
            printf("Masukan tidak valid. Coba lagi.\n");
            continue;
        }

        // Isi papan permainan
        board[row - 1][col - 1] = currentPlayer;
        moves++;

        // Periksa pemenang atau seri
        if (checkWin(board, size, currentPlayer))
        {
            system("cls");
            displayBoard(board, size);
            printf("Pemain %s (%c) memenangkan permainan!\n",
                   (currentPlayer == 'X') ? player1 : player2, currentPlayer);
            break;
        }
        else if (moves == size * size)
        {
            system("cls");
            displayBoard(board, size);
            printf("Permainan berakhir seri.\n");
            break;
        }

    } while (1);
}

void rulesPlaying()
{
    system("cls");
    // List tutorial
    printf("Toturial\n");
    printf("1. Pilihlah papan yang anda inginkan!\n");
    printf("Mode-3x3\t Mode-5x5\t\t Mode-7x7\n");
    printf("_____________\t_____________________\t_____________________________\n");
    printf("|___|___|___|\t|___|___|___|___|___|\t|___|___|___|___|___|___|___|\n");
    printf("|___|___|___|\t|___|___|___|___|___|\t|___|___|___|___|___|___|___|\n");
    printf("|___|___|___|\t|___|___|___|___|___|\t|___|___|___|___|___|___|___|\n");
    printf(".............\t|___|___|___|___|___|\t|___|___|___|___|___|___|___|\n");
    printf(".............\t|___|___|___|___|___|\t|___|___|___|___|___|___|___|\n");
    printf(".............\t.....................\t|___|___|___|___|___|___|___|\n");
    printf(".............\t.....................\t|___|___|___|___|___|___|___|\n");
    printf("2. Pilih mode player yang diinginkan (Single Player/Multi Player).\n");
    printf("3. Jika single player, maka harus memilih difficulty mode terlebih dahulu.\n");
    printf("4. Masukkan nama yang anda inginkan!\n");
    printf("5. Player 1 = 'X' Player 2 = 'O'!\n");
    printf("6. Jika game sudah dimulai, cara menginputkan adalah dengan [nomor] spasi [nomor] \n");
    printf("7. Cara untuk menang adalah membuat baris sejajar horizontal/vertikal/diagonal  \n");
    printf("   sesuai dengan papan board dengan simbol yang sama\n");
    printf("8. Note: Untuk papan board 5x5 harus  mendapat 4 baris sejajar untuk meraih kemenangan \n");
    printf("9. Note: Untuk papan board 7x7 harus  mendapat 5 baris sejajar untuk meraih kemenangan \n");
    printf("\n\n");
    printf("\n\t\tPress Enter To Continue");
    getchar();
    getchar();     // Menunggu user menekan Enter
    system("cls"); // Membersihkan layar terminal
    mainMenu();
}

void leaderboard()
{
    system("cls");
    printf("Leaderboard:\n");
    printf("\n\n Press Enter To Continue");
    getchar();
    getchar();
    system("cls");
    mainMenu();
    // Logika untuk menampilkan leaderboard dapat ditambahkan di sini
}

void playing()
{
    system("cls");

    // Pilihan Mode
    printf("\n_________________|=============|_________________");
    printf("\n|                |=Choice Mode=|                |");
    printf("\n|                |=============|                |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                 1. Mode-3x3                   |");
    printf("\n|                 2. Mode-5x5                   |");
    printf("\n|                 3. Mode-7x7                   |");
    printf("\n|                 0. Kembali                    |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|                                               |");
    printf("\n|_______________________________________________|");
    printf("\n\t\tPilih mode (0/1/2/3): ");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        size = 3;
        stagegame();
        break;
    case 2:
        size = 5;
        stagegame();
        break;
    case 3:
        size = 7;
        stagegame();
        break;
    case 0:
        mainMenu();
        break;
    default:
        printf("Pilihan tidak valid. Silahkan pilih lagi\n");
    }
}
void mainMenu()
{
    do
    {
        system("cls");
        printf("\t_________________|===========|___________________\n");
        printf("\t|                |=MAIN MENU=|                  |\n");
        printf("\t|                |===========|                  |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                1. Bermain                     |\n");
        printf("\t|                2. Aturan Bermain              |\n");
        printf("\t|                3. Leaderboard                 |\n");
        printf("\t|                0. Keluar                      |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|                                               |\n");
        printf("\t|_______________________________________________|\n");
        printf("\n\t\tPilih menu (0/1/2/3): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            playing();
            break;
        case 2:
            rulesPlaying();
            break;
        case 3:
            leaderboard();
            break;
        case 0:
            printf("Terima kasih telah bermain!\n");
            break;
        default:
            printf("Pilihan tidak valid. Silakan pilih lagi.\n");
        }
        printf("Credit =\n");
        printf("Daffa Muzhaffar Fakhruddin (231524038) (Guardian of Waifu)\n");
        printf("Muhammad Adhyaksa Fadillah (231524051) (Wibu Slayer)\n");
        printf("Tirta Rifky Fauzan         (231524063) (Jendral of Anime)\n");
        printf("Tekan Enter untuk melanjutkan :"); // Teks "tekan enter untuk melanjutkan"
        getchar();                                 // Mengambil karakter dari input (enter) untuk melanjutkan
        getchar();                                 // Untuk menunggu sampai pengguna menekan Enter
    } while (choice != 0);
}

void gameStart()
{
    printf("\n________________________________________________");
    printf("\n|    _______    |      __      |   _________   |");
    printf("\n|    |_   _|    |     |  |     |   |  _____|   |");
    printf("\n|      | |      |     |  |     |   | |_____    |");
    printf("\n|      |_|      |     |__|     |   |_______|   |");
    printf("\n|_______________|______________|_______________|");
    printf("\n|    _______    |   ________   |   _________   |");
    printf("\n|    |_   _|    |   |  __  |   |   |  _____|   |");
    printf("\n|      | |      |   | |__| |   |   | |_____    |");
    printf("\n|      |_|      |   |_|  |_|   |   |_______|   |");
    printf("\n|_______________|______________|_______________|");
    printf("\n|    _______    |    ______    |  __________   |");
    printf("\n|    |_   _|    |   |  __  |   |  |  |______   |");
    printf("\n|      | |      |   | |__| |   |  |  _______|  |");
    printf("\n|      |_|      |   |______|   |  |__|______   |");
    printf("\n|_______________|______________|_______________|");
    printf("\n\t\t   Start Game");
    printf("\n\t\tPress Enter To Continue");
    getchar();     // Menunggu user menekan Enter
    system("cls"); // Membersihkan layar terminal
    mainMenu();
}

int main()
{
    system("Color 31");

    // Panggil fungsi gameStart saat program dimulai
    gameStart();

    return 0;
}
