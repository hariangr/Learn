//#include <windows.h>
#include "main.h"

User user_login;
int is_login = 0;

void setup(void);
void start(void);
void header(char nav[256]);
int login(void);
void home(void);
int confirm(char str[]);

void categoryMenu(void);
void categoryView(void);
void categorySet(Category *category);

void memberMenu(void);
void memberView(void);
void memberSet(Member *member);

void userMenu(void);
void userView(void);
void userSet(User *user);

void bookMenu(void);
void bookView(int show_all, int load);
void bookSet(Book *book);

int transactionSet(Transaction *transaction);
void transactionMenu(void);
void transactionView(void);
void transactionDetail(Transaction transaction);
void detailView(Transaction transaction);

int main(void){
	start();
	return 0;
}

void setup(void){
	system("title PROGRAM TOKO BUKU - RILEX BOOKSTORE");
	system("mode con cols=120 lines=50");
}

int confirm(char str[]){
	char c[2];
	printf("\n%s\n", str);
	read(c, "");
	if(cmp(c, "y") || cmp(c, "Y")){
		return 1;
	}
	return 0;
}

void start(){
	loadAllData();
	is_login = 0;
	while(!(login())){
		printf("\nMohon memeriksa username dan password Anda!\n");
		system("pause");
	}
	home();
}

void header(char nav[256]){
	system("cls");
	printf("\nRILEX BOOKSTORE\n");
	if(is_login) printf("\n%s - %s\n", getUserRole(user_login.role), user_login.username);
	printf("\n# %s\n\n", nav);
}

int login(void){
	header("Login");

	int i;

	read(user_login.username, "Username\n> ");
	printf("\n");
	read(user_login.password, "Password\n> ");

	i = getUserIndex(user_login.username);
	if(i > -1){
		if(cmp(usrs[i].password, user_login.password)){
			user_login = usrs[i];
			is_login = 1;
		}
	}

	return is_login;
}

void home(void){
	header("Beranda");

	int i = 1;

	char pilihan[2];
	if(user_login.role == 1 || user_login.role == 2){
		printf("[%d] DATA KATEGORI BUKU\n\n", i); i++;
		printf("[%d] DATA BUKU\n\n", i); i++;
	}
	if(user_login.role == 1 || user_login.role == 3){
		printf("[%d] DATA MEMBER\n\n", i); i++;
		printf("[%d] DATA TRANSAKSI\n\n", i); i++;
	}
	if(user_login.role == 1)	
		printf("[%d] DATA PEGAWAI\n\n", i);
		
	
	printf("\n[9] LOGOUT\n\n");
	printf("[0] KELUAR\n\n");
	
		while(1) {
		read(pilihan, "\n> ");	

		if((user_login.role==1 && pilihan[0]>='1' && pilihan[0]<='5') || ((user_login.role==2 || user_login.role==3) && pilihan[0]>='1' && pilihan[0]<='2') || pilihan[0]=='0' || pilihan[0]=='9')
		break;
			
		printf("\nInput salah!\n");
	} 

	switch(pilihan[0]){
		case '0' :
			exit(0);
			break;
		case '9' :
			start();
			break;
		default :
			switch(user_login.role){
				case 1:
					switch(pilihan[0]){
						case '3' :
							memberMenu();
							break;
						case '4' :
							transactionMenu();
							break;
						case '5' :
							userMenu();
							break;
					}
				case 2:
					switch(pilihan[0]){
						case '1' :
							categoryMenu();
							break;
						case '2' :
							bookMenu();
							break;
					}
					break;
				case 3:
					switch(pilihan[0]){
						case '1' :
							memberMenu();
							break;
						case '2' :
							transactionMenu();
							break;
					}
					break;
			}
	}
}

//CATEGORY FUNCTIONS
void categorySet(Category *category){
	read(category->name, "\nNAMA KATEGORI\n> ");
}

void categoryMenu(void){
	header("Beranda > Kategori Buku");

	int index;
	char pilihan[2];
	Category category;

	categoryView();

	printf("[1] TAMBAH\t");
	printf("[2] UPDATE\t");
	printf("[3] HAPUS\t");
	printf("[0] KEMBALI\n");
	
	while(1) {
		read(pilihan, "\n>");	
		if(pilihan[0]>='0' && pilihan[0]<='3') break;
		printf("\nInput salah!\n");
	} 

	switch(pilihan[0]){
		case '1': // ADD CATEGORY	
			categorySet(&category);

			addCategory(category);

			printf("\nData kategori buku berhasil ditambahkan!\n");
			system("pause");
			categoryMenu();
			break;
		case '2': // UPDATE CATEGORY
			if(member_data.len!=0){
				while(1) {
					read(category.id, "\nID KATEGORI\n> ");
					index = getCategoryIndex(category.id);
					if(index > -1) break;
					printf("\nId kategori salah!\n");
				} 

				categorySet(&category);

				editCategory(category);

				printf("\nData kategori buku berhasil diupdate!\n");
			} else printf("\nTidak ada data untuk diupdate!\n");
			system("pause");
			categoryMenu();
			break;
		case '3': // DELETE CATEGORY
			if(member_data.len!=0){
				while(1) {
					read(category.id, "\nID KATEGORI\n> ");
					index = getCategoryIndex(category.id);
					if(index > -1) break;
					printf("\nId kategori salah!\n");
				} 

				deleteCategory(category.id);

				printf("\nData kategori buku berhasil dihapus!\n");
			} else printf("\nTidak ada data untuk dihapus!\n");
			system("pause");
			categoryMenu();
			break;
		default : // UPDATE CATEGORY
			home();
			break;
	}
}

void categoryView(void){
	loadAllData();
	int i;
	char kolom1[20], kolom2[20];
	strcpy(kolom1, "ID KATEGORI");
	strcpy(kolom2, "NAMA KATEGORI");

	printf("--------------------------------------------\n");
	printf(" %s | %s\n", kolom1, kolom2);
	printf("--------------------------------------------\n");
	if(category_data.len==0) printf("\n Tidak Ada Data\n\n");
	for(i = 0; i < category_data.len; i++){
		printf(" %-11s | %s\n", ctgs[i].id, ctgs[i].name);
	}
	printf("--------------------------------------------\n");
}

//MEMBER FUNCTIONS

void memberSet(Member *member){
	read(member->name, "\nNAMA MEMBER\n> ");
	read(member->phone, "\nTELP MEMBER\n> ");
}

void memberMenu(void){
	header("Beranda > Member");

	int index;
	char pilihan[2];
	Member member;

	memberView();

	printf("[1] TAMBAH\t");
	printf("[2] UPDATE\t");
	printf("[3] HAPUS\t");
	printf("[0] KEMBALI\n");
	
	while(1) {
		read(pilihan, "\n> ");	
		if(pilihan[0]>='0' && pilihan[0]<='3') break;
		printf("\nInput salah!\n");
	} 

	switch(pilihan[0]){
		case '1': // ADD MEMBER
			memberSet(&member);

			addMember(member);

			printf("\nData member berhasil ditambahkan!\n");
			system("pause");
			memberMenu();
			break;
		case '2': // UPDATE MEMBER
			if(member_data.len!=0){
				while(1) {
					read(member.id, "\nID MEMBER\n> ");
					index = getMemberIndex(member.id);
					if(index >-1) break;
					printf("\nId member salah!\n");
				}

				memberSet(&member);

				editMember(member);

				printf("\nData member berhasil diupdate!\n");
			} else printf("\nTidak ada data untuk diupdate!\n");
			system("pause");
			memberMenu();
			break;
		case '3':  // DELETE MEMBER
			if(member_data.len!=0){
				while(1) {
					read(member.id, "\nID MEMBER\n> ");
					index = getMemberIndex(member.id);
					if(index >-1) break;
					printf("\nId member salah!\n");
				}

				deleteMember(member.id);

				printf("\nData member berhasil dihapus!\n");
			} else printf("\nTidak ada data untuk dihapus!\n");
			system("pause");
			memberMenu();
			break;
		default :
			home();
			break;
	}
}

void memberView(void){
	loadAllData();
	int i;
	char kolom1[20], kolom2[20], kolom3[20];
	strcpy(kolom1, "ID MEMBER");
	strcpy(kolom2, "NAMA MEMBER");
	strcpy(kolom3, "TELP MEMBER");

	printf("-------------------------------------------------\n");
	printf(" %s | %-20s | %s\n", kolom1, kolom2, kolom3);
	printf("-------------------------------------------------\n");
	if(member_data.len==0) printf("\n Tidak Ada Data\n\n");
	for(i = 0; i < member_data.len; i++){
		printf(" %-9s | %-20s | %s\n", mbrs[i].id, mbrs[i].name, mbrs[i].phone);
	}
	printf("-------------------------------------------------\n");
}

//BOOK FUNCTIONS
void bookSet(Book *book){
	int index;
	printf("\nPILIH KATEGORI\n");
	categoryView();
	while(1) {
		read(book->ctg_id, "\nID KATEGORI BUKU\n> ");
		index = getCategoryIndex(book->ctg_id);
		if(index>-1) break;
		printf("\nId kategori salah!\n");
	} 
	read(book->title, "\nJUDUL BUKU\n> ");
	read_int(&book->price, "\nHARGA BUKU\n> ");
	read_int(&book->stock, "\nSTOK BUKU\n> ");
}

void bookMenu(void){
	header("Beranda > Buku");

	int index;
	char pilihan[2];
	Book book,book2;

	bookView(1,1);

	printf("[1] TAMBAH\t");
	printf("[2] UPDATE\t");
	printf("[3] HAPUS\t");
	printf("[0] KEMBALI\n");
	
	while(1) {
		read(pilihan, "\n>");	
		if(pilihan[0]>='0' && pilihan[0]<='3') break;
		printf("\nInput salah!\n");
	} 

	switch(pilihan[0]){
		case '1': // ADD BOOK
			if(category_data.len!=0){
				bookSet(&book);

				addBook(book);

				printf("\nData buku berhasil ditambahkan!\n");
			} else printf("\nTidak dapat menambah data buku karena belum ada data kategori buku!\n");
			system("pause");
			bookMenu();
			break;
		case '2': // UPDATE BOOK
			if(book_data.len!=0){
				while(1) {
					read(book.id, "\nID BUKU\n>");
					index = getBookIndex(book.id);
					if(index>-1) break;
					printf("\nId buku salah!\n");
				} 

				bookSet(&book);

				editBook(book);

				printf("\nData buku berhasil diupdate!\n");
			} else printf("\nTidak ada data untuk diupdate!\n");
			system("pause");
			bookMenu();
			break;
		case '3':  // DELETE BOOK
			if(book_data.len!=0){
				while(1) {
					read(book.id, "\nID BUKU\n>");
					index = getBookIndex(book.id);
					if(index>-1) break;
					printf("\nId buku salah!\n");
				} 

				deleteBook(book.id);

				printf("\nData buku berhasil dihapus!\n");
			} else printf("\nTidak ada data untuk dihapus!\n");
			system("pause");
			bookMenu();
			break;
		default :
			home();
			break;
	}
}

void bookView(int show_all, int load){
	if(load) loadAllData();
	int i;
	Category category;
	char kolom1[20], kolom2[20], kolom3[20], kolom4[20], kolom5[20];
	strcpy(kolom1, "ID BUKU");
	strcpy(kolom2, "JUDUL BUKU");
	strcpy(kolom3, "KATEGORI");
	strcpy(kolom4, "STOK");
	strcpy(kolom5, "HARGA");

	printf("---------------------------------------------------------------------------------------------------\n");
	printf(" %s | %-40s | %-20s | %s | %s \n", kolom1, kolom2, kolom3, kolom4, kolom5);
	printf("---------------------------------------------------------------------------------------------------\n");
	if(book_data.len == 0 || (!(show_all) && !(checkBookStock()))) printf("\n Tidak Ada Data\n\n");
	for(i = 0; i < book_data.len; i++){
		category = getCategory(books[i].ctg_id);
		if(show_all || books[i].stock)
			printf(" %-7s | %-40s | %-20s | %4d | Rp %8d.00\n", books[i].id, books[i].title, category.name, books[i].stock, books[i].price);
	}
	printf("---------------------------------------------------------------------------------------------------\n");
}

//USER FUNCTIONS
void userSet(User *user){
	read(user->password, "\nPASSWORD USER\n> ");
	printf("\nPILIH ROLE\n");
	printf("\n[1] Administrator [2] Operator [3] Seller\n");
	while(1) {
		read_int(&user->role, "\nROLE USER\n> ");
		if(user->role >=1 && user->role <=3) break;
		printf("\nRole salah!\n");
	} 
}

void userMenu(void){
	header("Beranda > Pegawai (User)");

	int index;
	char pilihan[2];
	User user;

	userView();

	printf("[1] TAMBAH\t");
	printf("[2] UPDATE\t");
	printf("[3] HAPUS\t");
	printf("[0] KEMBALI\n");
	
	while(1) {
		read(pilihan, "\n>");	
		if(pilihan[0]>='0' && pilihan[0]<='3') break;
		printf("\nInput salah!\n");
	} 

	switch(pilihan[0]){
		case '1': // ADD USER
			while(1){
				read(user.username, "\nUSERNAME USER\n> ");
				index = getUserIndex(user.username);
				if(index < 0) break;
				printf("\nUsername sudah digunakan!\n");
			}
			userSet(&user);

			addUser(user);

			printf("\nData user berhasil ditambahkan!\n");
			system("pause");
			userMenu();
			break;
		case '2': // UPDATE USER
			while(1) {
				read(user.username, "\nUSERNAME USER\n> ");
				index = getUserIndex(user.username);
				if(index > -1) break;
				printf("\nUsername salah!\n");
			} 

			userSet(&user);

			editUser(user);

			printf("\nData user berhasil diupdate!\n");
			system("pause");
			userMenu();
			break;
		case '3':  // DELETE USER
			while(1) {
				read(user.username, "\nUSERNAME USER\n> ");
				if(cmp(user_login.username, user.username)){
					printf("\nMaaf, tidak bisa menghapus akun Anda sendiri\n");
					continue;
				}
				index = getUserIndex(user.username);
				if(index > -1) break;
				printf("\nUsername salah!\n");
			} 

			deleteUser(user.username);

			printf("\nData user berhasil dihapus!\n");
			system("pause");
			userMenu();
			break;
		default :
			home();
			break;
	}
}

void userView(void){
	loadAllData();
	int i;
	char kolom1[20], kolom2[20], kolom3[20];
	strcpy(kolom1, "USERNAME");
	strcpy(kolom2, "PASSWORD");
	strcpy(kolom3, "ROLE");

	printf("------------------------------------------------\n");
	printf(" %-11s | %-11s | %s\n", kolom1, kolom2, kolom3);
	printf("------------------------------------------------\n");

	for(i = 0; i < user_data.len; i++){
		printf(" %-11s | %-11s | %s\n", usrs[i].username, usrs[i].password, getUserRole(usrs[i].role));
	}
	printf("------------------------------------------------\n");
}

//TRANSACTION FUNCTIONS
int transactionSet(Transaction *transaction){
	header("Beranda > Transaksi > Tambah Transaksi");	

	Detail detail;
	transaction->len = 0;
	int i = 0, j, dtl_index, book_index, mbr_index;
	
	//SET TRANSACTION ID, USERNAME, DATE
	if(transaction_data.len==0) strcpy(transaction->id, "T0001");
	else autoId(trcs[transaction_data.len - 1].id, transaction->id);
	strcpy(transaction->username, user_login.username);
	transaction->date = getDateNow();

	//SET TRANSACTION MEMBER
	printf("PILIH MEMBER\n");
	memberView();
	
	printf("\n[0] BATAL\n");
	while(1) {
		read(transaction->member_id, "\nID MEMBER\n> ");

		if(cmp(transaction->member_id, "0")){
			if(confirm("Batalkan transaksi ini? [y/n]"))				
				return 0;
			continue;
		}

		mbr_index = getMemberIndex(transaction->member_id);
		if(mbr_index > -1) break;
		printf("\nId member salah!\n");
	}
	
	while(1) {	
		header("Beranda > Transaksi > Tambah Transaksi");
		printf("DATA BUKU TERSEDIA\n");
		bookView(0,0);

		//CART
		printf("\n");
		transactionDetail(*transaction);

		printf("\n[9] CHECKOUT [0] BATAL\n");
		
		//SET TRS DETAIL
		//SET DTL BOOK ID
		read(detail.book_id, "\nID BUKU\n> ");

		//checkout without item
		if (cmp(detail.book_id, "9")) {
			if(confirm("Checkout transaksi? [y/n]")){	
				if(i) return 1;
				printf("\nCheckout hanya bisa dilakukan pada transaksi minimal 1 buah buku!\n");	
				system("pause");
			}
			continue;
		} else if(cmp(detail.book_id, "0")){
			if(confirm("Batalkan transaksi ini? [y/n]"))
				return 0;
			continue;
		}

		//book id check
		book_index = getBookIndex(detail.book_id);
		if(book_index == -1) {
			printf("\nId buku salah!\n");
			system("pause");
			continue;
		}

		dtl_index = i;
		
		//search book_id in details transaction
		for(j = 0; j < i; j++){
			if(cmp(detail.book_id, transaction->details[j].book_id)){
				dtl_index = j;
				break;
			}
		}

		//SET DTL QTY
		while(1) {
			read_int(&detail.qty, "\nJumlah\n>");
			if(detail.qty <= books[book_index].stock) break;
			printf("\nJumlah beli melebihi stok yang tersedia!\n");
			system("pause");
		}

		//sync book stock
		books[book_index].stock -= detail.qty;

		//SET DTL PRICE
		detail.price = books[book_index].price;

		//new book id
		if(dtl_index == i) {
			transaction->details[dtl_index] = detail;	
			i++;
		} else //book_id found
			transaction->details[dtl_index].qty += detail.qty;
		
		transaction->len = i;
	}
	return 1;
}

void transactionMenu(void){
	header("Beranda > Transaksi");

	int index;
	char pilihan[2];
	Transaction transaction;

	transactionView();

	printf("[1] TAMBAH\t");
	printf("[2] DETAIL\t");
	printf("[0] KEMBALI\n");
	
	while(1) {
		read(pilihan, "\n> ");	
		if(pilihan[0]>='0' && pilihan[0]<='2') break;
		printf("\nInput salah!\n");
	}

	switch(pilihan[0]){
		case '1': // ADD TRANSACTION
			if(!(checkBookStock())) 
				printf("\nTransaksi tidak dapat dilakukan karena tidak ada stok buku yang tersedia!\n");	
			else {
				if(transactionSet(&transaction)){
					addTransaction(transaction);
					printf("\nData transaksi berhasil ditambahkan!\n");	
					saveStruk();			
				} else 
					printf("\nTransaksi dibatalkan\n");				
			}

			system("pause");
			transactionMenu();
			break;
		case '2': // DETAIL TRANSACTION
			if(transaction_data.len){
				while(1) {
					read(transaction.id, "\nID TRANSAKSI\n> ");
					index = getTransactionIndex(transaction.id);
					if(index > -1) break;
					printf("\nId transaksi salah!\n");
				}
				printf("\n");
				transaction = trcs[index];
				transactionDetail(transaction);
			} else 
				printf("\nTidak ada transaksi yang dapat dipilih untuk melihat detail!\n");
			system("pause");
			transactionMenu();
			break;
		default :
			home();
			break;
	}
}


void detailView(Transaction transaction){

	int i, book_total = 0;
	long int grand_total = 0, sub_total;
	Book book;

	Detail *dtls = transaction.details;
	char kolom1[20], kolom2[20], kolom3[20], kolom4[20], kolom5[20], kolom6[20];

	strcpy(kolom1, "NO");
	strcpy(kolom2, "ID BUKU");
	strcpy(kolom3, "JUDUL");
	strcpy(kolom4, "JUMLAH");
	strcpy(kolom5, "HARGA");
	strcpy(kolom6, "SUBTOTAL");

	printf("------------------------------------------------------------------------------------------------------\n");
	printf(" %s | %s | %-40s | %s | %-14s | %s\n", kolom1, kolom2, kolom3, kolom4, kolom5, kolom6);
	printf("------------------------------------------------------------------------------------------------------\n");
	if(transaction.len == 0) printf(" TIDAK ADA DATA\n");
	for(i = 0; i < transaction.len; i++){
		book = getBook(dtls[i].book_id);

		sub_total = dtls[i].qty * dtls[i].price;
		book_total += dtls[i].qty;
		grand_total += sub_total;
		printf(" %-2d | %-7s | %-40s | %6d | Rp %8d.00 | Rp %10d.00\n", i+1, dtls[i].book_id, book.title, dtls[i].qty, dtls[i].price, sub_total);
	}
	printf("------------------------------------------------------------------------------------------------------\n");
	printf(" %-58s %5d %18s Rp %10d.00\n", "TOTAL", book_total, "", grand_total);
	printf("------------------------------------------------------------------------------------------------------\n");
}

void transactionDetail(Transaction transaction){
	Member member = getMember(transaction.member_id);
	Date date = transaction.date;

	printf("ID TRANSAKSI\t: %s\n\n", transaction.id);
	printf("TANGGAL\t\t: %d-%d-%d\n\n", date.day, date.month, date.year);
	printf("MEMBER\t\t: %s - %s\n\n", transaction.member_id, member.name);
	printf("USERNAME\t: %s\n\n", transaction.username);

	detailView(transaction);
}

void transactionView(void){
	loadAllData();
	int i, j, book_total, grand_total;
	Date date;
	Detail *dtls;
	char kolom1[20], kolom2[20], kolom3[20], kolom4[20], kolom5[20], kolom6[20];
	strcpy(kolom1, "ID TRANSAKSI");
	strcpy(kolom2, "ID MEMBER");
	strcpy(kolom3, "USERNAME");
	strcpy(kolom4, "TANGGAL");
	strcpy(kolom5, "TOTAL BUKU");
	strcpy(kolom6, "TOTAL HARGA");

	printf("----------------------------------------------------------------------------------\n");
	printf(" %s | %s | %-10s | %-10s | %s | %s\n", kolom1, kolom2, kolom3, kolom4, kolom5, kolom6);
	printf("----------------------------------------------------------------------------------\n");
	if(transaction_data.len==0) printf("\n Tidak Ada Data\n\n");
	for(i = 0; i < transaction_data.len; i++){
		date = trcs[i].date;
		dtls = trcs[i].details;

		book_total = 0;
		grand_total = 0;
		for(j = 0; j < trcs[i].len; j++){
			book_total += dtls[j].qty;
			grand_total += dtls[j].price * dtls[j].qty;
		}
		printf(" %-12s | %-9s | %-10s | %2d-%2d-%4d | %10d | Rp %8d.00\n", trcs[i].id, trcs[i].member_id, trcs[i].username, date.day, date.month, date.year, book_total, grand_total);
	}
	printf("----------------------------------------------------------------------------------\n");
}
