#ifndef STRUCT_H_
#define STRUCT_H_

#define LEN_ID 6
#define LEN_NAME 40
#define LEN_USER 11

#define MAX_BOOK 90
#define MAX_CTG 30
#define MAX_USER 90
#define MAX_MBR 90
#define MAX_TRS 30
#define MAX_DTL 30

typedef struct date {
	int day;
	int month;
	int year;
} Date;

typedef struct book {
	char id[LEN_ID];
	char ctg_id[LEN_ID];
	int stock;
	int price;
	char title[LEN_NAME];
} Book;

typedef struct category {
	char id[LEN_ID];
	char name[LEN_NAME];
} Category; 

typedef struct user {
	char username[LEN_USER];
	char password[LEN_USER];
	int role;
} User;

typedef struct member {
	char id[LEN_ID];
	char name[LEN_NAME];
	char phone[15];
} Member;

typedef struct detail {
	char book_id[LEN_ID];
	int qty;
	int price;
} Detail;

typedef struct transaction {
	char id[LEN_ID];
	char username[LEN_USER];
	char member_id[LEN_ID];
	Date date;
	Detail details[MAX_DTL];
	int len;
} Transaction;

typedef struct books {
	Book books[MAX_BOOK];
	int len;
} Books;

typedef struct categories {
	Category categories[MAX_CTG];
	int len;
} Categories;

typedef struct users {
	User users[MAX_USER];
	int len;
} Users;

typedef struct members {
	Member members[MAX_MBR];
	int len;
} Members;

typedef struct transactions {
	Transaction transactions[MAX_TRS];
	int len;
} Transactions;

#endif
