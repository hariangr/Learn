#include "main.h"

User user_login;
int is_login = 0;

int login(void){
	//header("Login");

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

// void start(){
// 	loadAllData();
// 	is_login = 0;
// 	while(!(login())){
// 		printf("\nMohon memeriksa username dan password Anda!\n");
// 		system("pause");
// 	}
// 	home();
// }

int main(void){
	login();
	return 0;
}