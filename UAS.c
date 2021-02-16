#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

	char user[100], pass[100], passHasil[100], daftarUser[100][100], daftarPass[100][100];
	char telp[15], nama[50], alamat[100];
	char jawab;
	int i, berat, harga, pilihan,input, member = 0, simpanIndex;
	bool cekSimbol, cekUpper, cekLower, cekAngka, cekUser;

	FILE *crud;
	
	void daftar();
	void masuk();
	void utama(char user[255]);
	void menu(char user[255]);
	void riwayat(char user[255]);
	void akun(char user[255]);

	
int main()
{
	
	printf("\n\n\n\n\n\n\n\t\t\t   SELAMAT DATANG DI E-LAUNDRY\n");
	printf("\n\n");
	printf("\t\t     Apakah Anda Sudah Memiliki Akun ? (y/n)\n");
	scanf("%c", &jawab);
	
	if(jawab == 'y' ||jawab== 'Y')
	{
		masuk();
	} 
	else if(jawab=='n'|| jawab== 'N')
	{
		daftar();
	} 
	else
	{
		printf("Inputan Anda Salah!!\n");
		return 0;
	}
	return 0;
}

void daftar()
{
	system("cls");
	
	while(0 < 5)
	{
		
		printf("\n\n\n\n\n\n\n\t\t\t      Registrasi Akun Anda\n\n\n");
		printf("\t\tInput Username : ");
		scanf("%s", user);
			
		if(strlen(user) > 6)
		{
			
			cekSimbol = false;
			
			for(i = 0; i < strlen(user); i++)
			{
				
				if(isalnum(user[i]) == 0)
				{
					if(user[i] != '.')
					{
						cekSimbol = true; 
					}
				}
			}

			if(cekSimbol == true)
			{
				
				printf("\n\n\t\tUsername Yang Anda Input Mengandung Simbol Selain Titik!\n\n");
				continue;
				
			}
			cekUser = false;
			
			for(i = 0; daftarUser[i][i] != '\0'; i++)
			{
				
				if(strcmp(daftarUser[i], user) == 0)
				{
					
					cekUser = true;
					
				}
				
			}

			if(cekUser == true)
			{
				
				printf("\n\n\t\tUsername Yang Anda Input Sudah Terdaftar!\n\n");
				continue;
				
			}
			break;
		}
		else
		{
			
			printf("\n\n\t\tUsername Yang Anda Input Kurang Dari 6 Karakter!\n\n");
			continue;
			
		}
	}

	while(8 > 7)
	{
		
		printf("\t\tInput Password : ");
		scanf("%s", pass);
		if(strlen(pass) > 8)
		{

			cekAngka = false;
			cekUpper = false;
			cekLower = false;
			cekSimbol = false;
					
		for(i =0; i < strlen(pass); i++)
		{
						
			if(pass[i] >= 48 && pass[i] <= 57)
			{
				
				cekAngka = true;
				
			}
			else if(pass[i] >= 65 && pass[i] <= 90)
			{   
				
				cekUpper = true;
				
			}
			else if(pass[i] >= 97 && pass[i]<=122)
			{    
				
				cekLower = true;
				
			}
			else
			{
				
				cekSimbol = true;
							
			}
		}

		if(cekAngka == true && cekUpper == true && cekLower == true && cekSimbol == true){
						
		}
		else
		{
			
			printf("\n\n\tPassword Harus Mengandung Angka, Upper Case, Lower Case, dan Simbol!\n\n");
			continue;
			
		}
		
		strcpy(passHasil, pass);
		strrev(passHasil);
					
		if(strcmp(pass, passHasil)==0)
		{
			
			printf("Password Anda Palindrome!\n");
			continue;
			
		}
		break;
		}
		else
		{
			
			printf("\n\n\t\tPassword Yang Anda Input Kurang Dari 8 Karakter!\n\n");
			continue;
			
		}
	}
	
		strcpy(daftarUser[member], user);
		strcpy(daftarPass[member], pass);
		
		
		char temp[255];
		int plus = 1;
		FILE *open = fopen("Input.txt", "r");
		while(fgets(temp, 255, open)!=NULL)
		{
			
			plus++;
			
		}
		
		char huruf[255] = "M";
		char konvert[255];
		itoa(plus, konvert, 10);
	
		strcat(huruf, konvert);;
			
		printf("Username Berhasil Ditambah \n");
		printf("Username : %s\nPassword : %s\n", user, pass, member);
		crud = fopen("Input.txt", "a+");
		fprintf(crud, "\n%s,%s,%s ", user, pass, huruf);
		fclose(crud); 
		
		masuk(user);
}

void masuk()
{
	do{
		
		system("cls");
		cekUser = true;
		
				printf("\n\n\n\n\n\n\n\t\t\t   Silahkan Masukkan Akun Anda \n\n\n");
				printf("\t\tInput Username : ");
				scanf("%s", &user);
				printf("\t\tInput Password : ");
				scanf("%s", &pass);
				
				char temp[255];
				char temp2[255];
				char *kata;
				char *kata2;
				int cmp, cmp2; 
				
	FILE *open = fopen("Input.txt", "r");
	
	while(fgets(temp, 255, open)!=NULL)
	{
		
		kata = strtok(temp, ",");
		cmp = strcmp(user, kata);
		if(cmp == 0)
		{
			
			break;
			
		}
	}
	fclose(open);
	
	FILE *open2 = fopen("Input.txt", "r");
	while(fgets(temp2, 255, open)!=NULL)
	{
		
		kata2 = strtok(temp2, ",");
		kata2 = strtok(NULL, ",");
		cmp2 = strcmp(pass, kata2);
		if(cmp2 == 0)
		{
			
			break;
			
		}
		
	}
	fclose(open2);
	if(cmp == 0 && cmp2 == 0)
	{
		cekUser = false;
		
	}
	else
	{
		
		printf("\n\n\t\tUSERNAME ATAU PASSWORD SALAH!!\n\n");
		system("pause");
		cekUser = true;
		
	}
				
				
	}while(cekUser);
	
	system("cls"); 	
	printf("\n\n\n\t\t\t====SELAMAT DATANG %s====\n\n", user);
			
	utama(user);
	
}

void utama(char user[255])
{
	
	printf("\n\n\n\n\n\t\t\t\t     DASHBOARD\n\n");
	printf("\t\t1. Menu Layanan\n");
	printf("\t\t2. Riwayat Layanan\n");
	printf("\t\t3. Akun Anda\n");
	printf("\n\n");
	
	printf("\t\tPilih : ");
	scanf("%d", &input);
	printf("\n\n");
	
	if(input == 1)
	{
		
		menu(user);
		
	}
	else if(input == 2)
	{
		
		riwayat(user);
		
	}
	else if(input == 3)
	{
		
		akun(user);
		
	}
}

void menu(char user[255])
{
	FILE *riwayat2;
	
	system("cls");
	
	menu:
	
	printf("\n\n\n\n\n\n\n\t\t\t\t     MENU\n\n");
	printf("\t\t1. Ekspres                : 10.000 per kilo\n");
	printf("\t\t2. Laundry Kilat          : 8.000 per kilo\n");
	printf("\t\t3. Setrika                : 4.500 per kilo\n");
	printf("\t\t4. Cuci Kering            : 3.000 per kilo\n");
	printf("\t\t5. Cuci Kering + Setrika  : 5.000 per kilo\n");
	printf("\n\n");
	
	printf("\t\tMasukkan Menu Pilihan : ");
	scanf("%d", &pilihan);
	printf("\n\n");
	
	if(pilihan == 1){
		printf("\t\tMasukkan Berat Pakaian (kg) : ");
		scanf("%d", &berat);
		
		harga = berat * 10000;
		printf("\t\tTarif Yang Perlu Dibayar Adalah = %d\n\n", harga);
		
		printf("\t\tPAKAIAN ANDA AKAN DIANTAR\n\n");
		
		printf("\t\tMasukkan Nomor Telepon Anda : ");
		scanf("%s", &telp);
		
		printf("\t\tMasukkan Nama Panggilan Anda : ");
		scanf("%s", &nama);
		
		printf("\t\tMasukkan Alamat Lengkap Anda : ");
		fflush(stdin);
		scanf("%[^\n]", alamat);
		
		printf("\n\n\t     ======TERIMAKASIH TELAH MENGGUNAKAN JASA KAMI======\n\n");
		FILE *ekspres = fopen("data_ekspres.txt", "a");
		fprintf(ekspres, "Berat Pakaian = %d\nTarif = %d\nNomor Telepon = %s\nNama Panggilan = %s\nAlamat = %s\n", berat, harga, telp, nama, alamat);
		fclose(ekspres);
	}
	else if(pilihan == 2){
		printf("\t\tMasukkan Berat Pakaian (kg) : ");
		scanf("%d", &berat);
		
		harga = berat * 8000;
		printf("\t\tTarif Yang Perlu Dibayar Adalah = %d\n", harga);
		
		printf("\t\tMasukkan Nama Panggilan Anda : ");
		scanf("%s", &nama);
		
		printf("\n\t     Silahkan Kembali Besok Untuk Mengambil Pakaian Anda!\n");
		printf("\n\n\t     ======TERIMAKASIH TELAH MENGGUNAKAN JASA KAMI======\n\n");
		FILE *kilat = fopen("data_kilat.txt", "a");
		fprintf(kilat, "Berat Pakaian = %d\nTarif = %d\nNama Panggilan = %s\n", berat, harga, nama);
		fclose(kilat);
	}
	else if(pilihan == 3){
		printf("\t\tPASTIKAN PAKAIAN ANDA DALAH KEADAAN KERING DAN SUDAH DICUCI\n\n");
		printf("\t\tMasukkan Berat Pakaian (kg) : ");
		scanf("%d", &berat);
		
		harga = berat * 4500;
		printf("\t\tTarif Yang Perlu Dibayar Adalah = %d\n", harga);
		
		printf("\t\tMasukkan Nama Panggilan Anda : ");
		scanf("%s", &nama);
		
		if(berat <= 3){
			printf("\n\t     Silahkan Datang Besok Untuk Mengambil Pakaian Anda!\n\n");
		}
		else
		{
			printf("\n\t     Silahkan Datang 3 Hari Lagi Untuk Mengambil Pakaian Anda!\n\n");
		}
		
		printf("\n\n\t     ======TERIMAKASIH TELAH MENGGUNAKAN JASA KAMI======\n\n");
		FILE *setrika = fopen("data_setrika.txt", "a");
		fprintf(setrika, "Berat Pakaian = %d\nTarif = %d\nNama Panggilan = %s\n", berat, harga, nama);
		fclose(setrika);
	}
	else if(pilihan == 4){
		printf("\t\tMasukkan Berat Pakaian (kg) : ");
		scanf("%d", &berat);
		
		harga = berat * 3000;
		printf("\t\tTarif Yang Perlu Dibayar Adalah = %d\n", harga);
		
		printf("\t\tMasukkan Nama Panggilan Anda : ");
		scanf("%s", &nama);
		
		if(berat <= 3){
			printf("\n\t     Silahkan Datang Besok Untuk Mengambil Pakaian Anda!\n\n");
		}
		else
		{
			printf("\n\t     Silahkan Datang 3 Hari Lagi Untuk Mengambil Pakaian Anda!\n\n");
		}
		
		printf("\n\n\t     ======TERIMAKASIH TELAH MENGGUNAKAN JASA KAMI======\n\n");
		FILE *kering = fopen("data_kering.txt", "a");
		fprintf(kering, "Berat Pakaian = %d\nTarif = %d\nNama Panggilan = %s\n", berat, harga, nama);
		fclose(kering);
	}
	else if(pilihan == 5){
		printf("\t\tMasukkan Berat Pakaian (kg) : ");
		scanf("%d", &berat);
		
		harga = berat * 5000;
		printf("\t\tTarif Yang Perlu Dibayar Adalah = %d\n", harga);
		
		printf("\t\tMasukkan Nama Panggilan Anda : ");
		scanf("%s", &nama);
		
		if(berat <= 3){
			printf("\n\t     Silahkan Datang 3 Hari Lagi Untuk Mengambil Pakaian Anda!\n\n");
		}
		else
		{
			printf("\n\t     Silahkan Datang 7 Hari Lagi Untuk Mengambil Pakaian Anda!\n\n");
		}
		
		printf("\n\n\t     ======TERIMAKASIH TELAH MENGGUNAKAN JASA KAMI======\n\n");
		FILE *cuci = fopen("data_cuci.txt", "a");
		fprintf(cuci, "Berat Pakaian = %d\nTarif = %d\nNama Panggilan = %s\n", berat, harga, nama);
		fclose(cuci);
	}
	else
	{
		printf("\t\t\tPilihan Anda Tidak Ada Di Menu!\n\n");
		return 0;
	}
	
	FILE *open = fopen("riwayat.txt","a");
	fprintf(open,"%s",user);
	fclose(open);
	
	riwayat2 = fopen("riwayat.txt","a");
	fprintf(riwayat2,",%d,%d,%d \n",pilihan,berat,harga);
	fclose(riwayat2);
	
	int jawab;
	
	printf("\n\n\t\t\t\t     AKSI\n\n");
	printf("\t\t1. Transaksi Lagi\n");
	printf("\t\t2. Selesai Transaksi\n");
	printf("\t\t3. Kembali Ke DASHBOARD\n");
	scanf("%d", &jawab);
	
	if(jawab == 1)
	{
		
		system("cls");
		goto menu;
		
	}
	else if(jawab == 2)
	{
		
		return 0;
		
	}
	else if(jawab == 3)
	{
		
		system("cls");
		utama(user);
		
	}
	else
	{
		
		printf("Inputan Salah!!\n");
		return 0;
		
	}
	
}

void riwayat(char user[255])
{
	system("cls");
	printf("\n\n\n\t\t\t\t     RIWAYAT\n");
	printf("\t\t\t\t=================\n\n");
	
	char* kata;
	char temp[255], temp2[255];

	FILE *riwayat = fopen("riwayat.txt","r");
	
	while(fgets(temp,255,riwayat)!=NULL)
	{
		
		kata = strtok(temp,",");
		if(strcmp(user,kata)==0)
		{
			
			while(kata!=NULL)
			{
				
				printf("\t\t  Nama  : %s\n",kata);
				kata = strtok(NULL,",");
				break;
			
			}
			
			while(kata!=NULL)
			{
				
				if(strcmp(kata,"1")==0)
				{
					
					printf("\t\t  Layanan Ekspres\n");
					
				}
				else if(strcmp(kata,"2")==0)
				{
					
					printf("\t\t  Layanan Laundry Kilat\n");
					
				}
				else if(strcmp(kata,"3")==0)
				{
					
					printf("\t\t  Layanan Setrika\n");
					
				}
				else if(strcmp(kata,"4")==0)
				{
					
					printf("\t\t  Layanan Cuci kering\n");
					
				}
				else if(strcmp(kata,"5")==0)
				{
					
					printf("\t\t  Layanan Cuci kering + strika\n");
					
				}
				
				kata = strtok(NULL,",");
				break;
			
			}
			
			while(kata!=NULL)
			{
				
				printf("\t\t  Berat : %s kg\n",kata);
				kata = strtok(NULL,",");
				break;
			
			}
			
			while(kata!=NULL)
			{
				
				printf("\t\t  Harga : %s \n",kata);
				kata = strtok(NULL," ");
				break;
			
			}
		}
		
	}
	
	fclose(riwayat);

	printf("\n\n");
	
	int a;
	printf("\n\n\t\t\t\t     AKSI\n\n");
	printf("\t\t1. Kembali\n");
	printf("\t\t2. Selesai\n");
	scanf("%d", &a);
	
	if(a == 1)
	{
		
		system("cls");
		utama(user);
		
	}
	else if(a == 2)
	{
		
		return 0;
		
	}
	else
	{
		
		printf("Inputan Salah!");
		return 0;
		
	}
	
}

	void ubah();
	void hapus();

void akun(char user[255])
{
	
	system("cls");
	
	printf("\n\n\n\t\t\t\t     AKUN ANDA\n");
	printf("\t\t\t\t================== \n\n");
	
	char *kata;
	char* kata2;
	char temp[255];
	
	FILE *akun = fopen("Input.txt", "r");
	
	while(fgets(temp, 255, akun)!=NULL)
	{
		
		kata = strtok(temp, ",");
		kata2 = strtok(NULL,",");
		if(strcmp(user,kata)==0)
		{
			
			printf("\n\n\t\t\tUsername Anda     : %s \n",kata);
			printf("\t\t\tPassword Anda : %s \n",kata2);
			
		}
		
	}
	
	fclose(akun);
	
	int b;
	
	printf("\n\t\t\t\t     AKSI\n\n");
	printf("\t\t1. Update\n");
	printf("\t\t2. Delete\n");
	printf("\t\t3. Kembali\n");
	printf("\t\t4. Selesai\n");
	scanf("%d", &b);
	
	if(b == 1)
	{
		
		ubah();
		
	}
	else if(b == 2)
	{
		
		hapus();
		
	}
	else if(b == 3)
	{
		
		system("cls");
		utama(user);
		
	}
	else if(b == 4)
	{
		
		return 0;
		
	}
	else
	{
		
		printf("Inputan Salah!");
		return 0;
		
	}
}

struct Variable
{

	char* nama;
		
};

void ubah()
{
	
	struct Variable var,var2,var3,var4;
	
	char temp[255], temp2[255], temp3[255], temp4[255];
	char* kata;
	char* kata2;
	char nuser[255],  nuser2[255], npass[255], npass2[255];
	char* cek;
	char periksa[255];
	int pilih;
	bool cekUbah = false;
	
	ubah:
	
	system("cls");
	
	printf("\n\n\n\t\t\t      = = = UPDATE = = =\n\n");
	
	printf("\t\t\t 1. Update Username\n");
	printf("\t\t\t 2. Update Password\n");
	printf("\n\t\t\t PILIH : ");
	scanf("%d",&pilih);
	
	switch(pilih)
	{	
	case 1:
			
	printf("\n\t\t Masukkan Username Lama : ");
	scanf("%s",&nuser);
	
	do
	{
	
	printf("\n\t\t Masukan Username Baru : ");
	scanf("%s",&nuser2);
	
	FILE *cek2 = fopen("Input.txt", "r");
	
	while(fgets(periksa, 255, cek2)!=NULL)
	{
		cek = strtok(periksa, ",");
		if(strcmp(nuser2, cek) == 0)
		{
			
			break;
			
		}
	}
	
	fclose(cek);
	
	if(strcmp(nuser2, cek) == 0)
		{
			
			printf("\t\t\t Username Sudah Ada\n");
			cekUbah = true;
			
		}
	if(!(strcmp(nuser2, cek) == 0))
		{
			
			cekUbah = false;
			
		}
	}
	
	while(cekUbah);
	
	FILE *open = fopen("Input.txt","r+");
	
	FILE *open2 = fopen("Inputalias.txt","w");
		
		while(fgets(temp,255,open)!=NULL)
		{
			
			strcpy(temp2,temp);
			kata = strtok(temp,",");
			var.nama = strtok(NULL,",");
			var2.nama = strtok(NULL,",");

			if(strcmp(nuser,kata)==0)
			{
				
				fprintf(open2,"%s,%s,%s",nuser2,var.nama,var2.nama);
				
			}
			if(!(strcmp(nuser,kata)==0))
			{
				
				fprintf(open2,"%s",temp2);
				
			}
		}
		
		fclose(open2);
		fclose(open);
		
		remove("Input.txt");
		rename("Inputalias.txt","Input.txt");
		
		printf("\n\t\t\t===BERHASIL MENGUBAH DATA USERNAME===\n");
		
		break;
	case 2:
	
	printf("\n\t\t Masukkan Pasword Lama : ");
	scanf("%s",&npass);
	
	printf("\n\t\t Masukkan Password Baru : ");
	scanf("%s",&npass2);
	
	FILE *open3 = fopen("Input.txt","r+");
	FILE *open4 = fopen("Inputalias.txt","w");
	
	while(fgets(temp3,255,open3)!=NULL)
	{
		
		strcpy(temp4,temp3);
		kata2 = strtok(temp3,",");
		var3.nama = strtok(NULL,",");
		var4.nama = strtok(NULL,",");
		
		if(strcmp(npass,var3.nama)==0)
		{
			
			fprintf(open4,"%s,%s,%s",kata2,npass2,var4.nama);
			
		}
		if(!(strcmp(npass,var3.nama)==0))
		{
			
			fprintf(open4,"%s",temp4);
			
		}
	}
	
	fclose(open3);
	fclose(open4);
	
	remove("Input.txt");
	rename("Inputalias.txt","Input.txt");
	
	printf("\n\t\t\t===BERHASIL MENGUBAH DATA PASSWORD===\n");
	
		break;

	default:
		break;	
	}
	
	int c;
	printf("\n\t\t\t\t     AKSI\n\n");
	printf("\t\t1. Kembali Ke Dashboard\n");
	printf("\t\t2. Kembali Ke Form Ubah\n");
	printf("\t\t3. Selesai\n");
	scanf("%d", &c);
	
	if(c == 1)
	{
		
		system("cls");
		utama(user);
		
	}
	else if(c == 2)
	{
		
		system("cls");
		goto ubah;
		
	}
	else if(c == 3)
	{
		
		return 0;
		
	}
	else
	{
		
		printf("Inputan Salah!");
		return 0;
		
	}
	
}

void hapus()
{
	char user[255], temp[255], temp2[255];
	char* kata;
	
	hapus:
	
	system("cls");
	printf("\n\n\n\t\t\t      = = = Delete = = =\n\n");
	printf("\t\t     Username Yang Akan Dihapus : ");
	scanf("%s",&user);
	
	char d;
	printf("\n\t\t     Apakah Anda Yakin Untuk Hapus Data ? (y/n)\n");
	scanf("%s", &d);
	
	if(d == 'y' ||d== 'Y')
	{
		
		FILE *open = fopen("Input.txt","r+");
		FILE *open2 = fopen("Inputalias.txt","w");
	
		while(fgets(temp,255,open)!=NULL)
		{
			
			strcpy(temp2,temp);
			kata = strtok(temp,",");
			if(!(strcmp(user,kata)==0))
			{
				
				fprintf(open2,"%s",temp2);
				
			}
			
		}
	
		fclose(open);
		fclose(open2);
	
		remove("Input.txt");
		rename("Inputalias.txt","Input.txt");
		
		printf("\n\t\t\t===BERHASIL MENGHAPUS DATA===\n");
		
	} 
	else if(d=='n'|| d== 'N')
	{
		
		int e;
		printf("\n\t\t\t\t     AKSI\n\n");
		printf("\t\t1. Kembali Ke Dashboard\n");
		printf("\t\t2. Kembali Ke Form Ubah\n");
		printf("\t\t3. Selesai\n");
		scanf("%d", &e);
	
		if(e == 1)
		{
			
			system("cls");
			utama(user);
			
		}
		else if(e == 2)
		{
			
			system("cls");
			goto hapus;
			
		}
		else if(e == 3)
		{
			
			return 0;
			
		}
		else
		{
			
			printf("Inputan Salah!");
			return 0;
			
		}
	} 
	else
	{
		
		printf("Inputan Anda Salah!!\n");
		return 0;
		
	}
	
}