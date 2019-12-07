#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

#define DIR_BOOK "data/books.txt"
#define DIR_CTG "data/categories.txt"
#define DIR_USER "data/users.txt"
#define DIR_MBR "data/members.txt"
#define DIR_TRS "data/transactions.txt"
#define DIR_DTL "data/details.txt"
#define DIR_STRK "data/struk.txt"

//Data Store
Books book_data;
Categories category_data;
Members member_data;
Users user_data;
Transactions transaction_data;

//Pointer to array Data Store
Category *ctgs = category_data.categories; 
User *usrs = user_data.users; 
Member *mbrs = member_data.members; 
Book *books = book_data.books; 
Transaction *trcs = transaction_data.transactions; 


/*
** CATEGORY FUNCTIONS
*/

void syncCategory(void){
	FILE *fp = fopen(DIR_CTG, "w");
	int i;
	for(i = 0; i < category_data.len; i++)
		fprintf(fp, "%s\t%s\n", ctgs[i].id, ctgs[i].name);
	fclose(fp);
}

void reCategory(int index){
	int i;
	category_data.len--;
	for(i = index; i < category_data.len; i++){
		ctgs[i] = ctgs[i+1];
	}
}

void loadCategory(void){
	FILE *fp = fopen(DIR_CTG, "a+");
	int i, p = 0;
	char buff[LEN_NAME];
	i = 0;
	while(p != EOF)  {
		p = fscanf(fp, "%s", ctgs[i].id);
		if (p == EOF) break;
		fgets(buff, LEN_NAME, fp);
		trim(buff, ctgs[i].name);
		i++;
	}
	category_data.len = i;
	fclose(fp);
}

int getCategoryIndex(char id[LEN_ID]){
	int i;
	for (i = 0; i < category_data.len; i++) {
		if(cmp(ctgs[i].id, id))
			return i;
	}
	return -1;
}

Category getCategory(char id[LEN_ID]){
	int i = getCategoryIndex(id);
	return ctgs[i];
}

void editCategory(Category category){
	int i = getCategoryIndex(category.id);
	ctgs[i] = category;
	syncCategory();
}

void addCategory(Category category){
	if(category_data.len==0) strcpy(category.id, "C0001");
	else autoId(ctgs[category_data.len - 1].id, category.id);
	ctgs[category_data.len] = category;
	category_data.len++;
	syncCategory();
}

void deleteCategory(char id[LEN_ID]){
	int i = getCategoryIndex(id);
	reCategory(i);
	syncCategory();
}

/*
** USER FUNCTIONS
*/

char *getUserRole(int role){
	switch(role){
		case 1  : return "Administrator"; break;
		case 2  : return "Operator"; break;
		default : return "Seller"; break;
	}
}

void syncUser(void){
	FILE *fp = fopen(DIR_USER, "w");
	int i;
	for(i = 0; i < user_data.len; i++)
		fprintf(fp, "%s\t%s\t%d\n", usrs[i].username, usrs[i].password, usrs[i].role);
	fclose(fp);
}

void reUser(int index){
	int i;
	user_data.len--;
	for(i = index; i < user_data.len; i++){
		usrs[i] = usrs[i+1];
	}
}

void loadUser(void){
	FILE *fp = fopen(DIR_USER, "a+");
	int i, p = 0;
	i = 0;
	while(p != EOF)  {
		p = fscanf(fp, "%s %s %d", usrs[i].username, usrs[i].password, &usrs[i].role);
		if (p == EOF) break;
		i++;
	}
	user_data.len = i;
	fclose(fp);
}

int getUserIndex(char username[LEN_USER]){
	int i;
	for (i = 0; i < user_data.len; i++) {
		if(cmp(usrs[i].username, username))
			return i;
	}
	return -1;
}

User getUser(char username[LEN_USER]){
	int i = getUserIndex(username);
	return usrs[i];
}

void editUser(User user){
	int i = getUserIndex(user.username);
	usrs[i] = user;
	syncUser();
}

void addUser(User user){
	usrs[user_data.len] = user;
	user_data.len++;
	syncUser();
}

void deleteUser(char username[LEN_USER]){
	int i = getUserIndex(username);
	reUser(i);
	syncUser();
}

/*
** MEMBER FUNCTIONS
*/

void syncMember(void){
	FILE *fp = fopen(DIR_MBR, "w");
	int i;
	for(i = 0; i < member_data.len; i++)
		fprintf(fp, "%s\t%s\t%s\n", mbrs[i].id, mbrs[i].phone, mbrs[i].name);

	fclose(fp);
}

void reMember(int index){
	int i;
	member_data.len--;
	for(i = index; i < member_data.len; i++){
		mbrs[i] = mbrs[i+1];
	}
}

void loadMember(void){
	FILE *fp = fopen(DIR_MBR, "a+");
	int i, p = 0;
	char buff[LEN_NAME];
	i = 0;
	while(p != EOF)  {
		p = fscanf(fp, "%s %s", mbrs[i].id, mbrs[i].phone);
		if (p == EOF) break;
		fgets(buff, LEN_NAME, fp);
		trim(buff, mbrs[i].name);
		i++;
	}
	member_data.len = i;
	fclose(fp);
}

int getMemberIndex(char id[LEN_ID]){
	int i;
	for (i = 0; i < member_data.len; i++) {
		if(cmp(mbrs[i].id, id))
			return i;
	}
	return -1;
}

Member getMember(char id[LEN_ID]){
	int i = getMemberIndex(id);
	return mbrs[i];
}

void editMember(Member member){
	int i = getMemberIndex(member.id);
	mbrs[i] = member;
	syncMember();
}

void addMember(Member member){
	if(member_data.len==0) strcpy(member.id, "M0001");
	else autoId(mbrs[member_data.len - 1].id, member.id);
	mbrs[member_data.len] = member;
	member_data.len++;
	syncMember();
}

void deleteMember(char id[LEN_ID]){
	int i = getMemberIndex(id);
	reMember(i);
	syncMember();
}

/*
** BOOK FUNCTIONS
*/

void syncBook(void){
	FILE *fp = fopen(DIR_BOOK, "w");
	int i;
	for(i = 0; i < book_data.len; i++)
		fprintf(fp, "%s\t%s\t%d\t%d\t%s\n", books[i].id, books[i].ctg_id, books[i].stock, books[i].price, books[i].title);
	fclose(fp);
}

void reBook(int index){
	int i;
	book_data.len--;
	for(i = index; i < book_data.len; i++){
		books[i] = books[i+1];
	}
}

void loadBook(void){
	FILE *fp = fopen(DIR_BOOK, "a+");
	int i, p = 0;
	char buff[LEN_NAME];
	i = 0;
	while(p != EOF)  {
		p = fscanf(fp, "%s %s %d %d", books[i].id, books[i].ctg_id, &books[i].stock, &books[i].price);
		if (p == EOF) break;
		fgets(buff, LEN_NAME, fp);
		trim(buff, books[i].title);
		i++;
	}
	book_data.len = i;
	fclose(fp);
}

int getBookIndex(char id[LEN_ID]){
	int i;
	for (i = 0; i < book_data.len; i++) {
		if(cmp(books[i].id, id))
			return i;
	}
	return -1;
}

Book getBook(char id[LEN_ID]){
	int i = getBookIndex(id);
	return books[i];
}

void editBook(Book book){
	int i = getBookIndex(book.id);
	books[i] = book;
	syncBook();
}

void addBook(Book book){
	if(book_data.len==0) strcpy(book.id, "B0001");
	else autoId(books[book_data.len - 1].id, book.id);
	books[book_data.len] = book;
	book_data.len++;
	syncBook();
}

void deleteBook(char id[LEN_ID]){
	int i = getBookIndex(id);
	reBook(i);
	syncBook();
}

int checkBookStock(void){
	int i;
	if(book_data.len==0) return 0;
	for(i = 0; i < book_data.len; i++){
		if(books[i].stock > 0)
			return 1;
	}
	return 0;
}

/*
** TRANSACTION FUNCTIONS
*/

void syncTransaction(void){
	FILE *fp = fopen(DIR_TRS, "a");
	FILE *fp2 = fopen(DIR_DTL, "a");
	int i, index, book_index;
	Date date;
	Detail *dtls;

	index = transaction_data.len-1;
	date = trcs[index].date;
	fprintf(fp, "%s\t%s\t%s\t%d-%d-%d\n", trcs[index].id, trcs[index].member_id, trcs[index].username, date.day, date.month, date.year);
	for(i = 0; i < trcs[index].len; i++){
		dtls = trcs[index].details;
		fprintf(fp2, "%s\t%s\t%d\t%d\n", trcs[index].id, dtls[i].book_id, dtls[i].qty, dtls[i].price);

		syncBook();
	}	
	
	fclose(fp);
	fclose(fp2);
}

void loadTransaction(void){
	FILE *fp = fopen(DIR_TRS, "a+");
	FILE *fp2 = fopen(DIR_DTL, "a+");
	int i, j, p = 0,q = 0;
	char trs_id[LEN_ID];

	Date *date;
	Detail detail;

	i = 0;
	while(p != EOF)  {
		date = &trcs[i].date;
		p = fscanf(fp, "%s %s %s %d-%d-%d", trcs[i].id, trcs[i].member_id, trcs[i].username, &date->day, &date->month, &date->year);
		if (p == EOF) break;
		
		j = 0;
		while(q != EOF){
			q = fscanf(fp2, "%s %s %d %d", trs_id, detail.book_id, &detail.qty, &detail.price);
			if (q == EOF) break;
			if (!(cmp(trs_id, trcs[i].id))) continue;
			trcs[i].details[j] = detail;
			j++;
		}
		trcs[i].len = j;
		q = 0;
		rewind(fp2);
		i++;
	}
	transaction_data.len = i;
	fclose(fp);
	fclose(fp2);
}

int getTransactionIndex(char id[LEN_ID]){
	int i;
	for (i = 0; i < transaction_data.len; i++) {
		if(cmp(trcs[i].id, id))
			return i;
	}
	return -1;
}

Transaction getTransaction(char id[LEN_ID]){
	int i = getTransactionIndex(id);
	return trcs[i];
}

void addTransaction(Transaction transaction){
	trcs[transaction_data.len] = transaction;
	transaction_data.len++;
	syncTransaction();
}

void loadAllData(void){
	loadUser();
	loadMember();
	loadCategory();
	loadBook();
	loadTransaction();
}

void saveStruk(void){
	Transaction transaction = trcs[transaction_data.len-1];

	FILE *fp = fopen(DIR_STRK, "a");
	int i, book_total = 0;
	long int grand_total = 0, sub_total;
	char kolom1[20], kolom2[20], kolom3[20], kolom4[20], kolom5[20], kolom6[20];
	
	Book book;

	Detail *dtls = transaction.details;

	Member member = getMember(transaction.member_id);
	Date date = transaction.date;

	fprintf(fp, "ID TRANSAKSI\t: %s\n", transaction.id);
	fprintf(fp, "TANGGAL\t\t: %d-%d-%d\n", date.day, date.month, date.year);
	fprintf(fp, "MEMBER\t\t: %s - %s\n", transaction.member_id, member.name);
	fprintf(fp, "USERNAME\t: %s\n", transaction.username);

	strcpy(kolom1, "NO");
	strcpy(kolom2, "ID BUKU");
	strcpy(kolom3, "JUDUL");
	strcpy(kolom4, "JUMLAH");
	strcpy(kolom5, "HARGA");
	strcpy(kolom6, "SUBTOTAL");

	fprintf(fp, "------------------------------------------------------------------------------------------------------\n");
	fprintf(fp, " %s | %s | %-40s | %s | %-14s | %s\n", kolom1, kolom2, kolom3, kolom4, kolom5, kolom6);
	fprintf(fp, "------------------------------------------------------------------------------------------------------\n");
	for(i = 0; i < transaction.len; i++){
		book = getBook(dtls[i].book_id);

		sub_total = dtls[i].qty * dtls[i].price;
		book_total += dtls[i].qty;
		grand_total += sub_total;
		fprintf(fp, " %-2d | %-7s | %-40s | %6d | Rp %8d.00 | Rp %10d.00\n", i+1, dtls[i].book_id, book.title, dtls[i].qty, dtls[i].price, sub_total);
	}
	fprintf(fp, "------------------------------------------------------------------------------------------------------\n");
	fprintf(fp, " %-58s %5d %18s Rp %10d.00\n", "TOTAL", book_total, "", grand_total);
	fprintf(fp, "------------------------------------------------------------------------------------------------------\n\n");
	fclose(fp);

}

#endif