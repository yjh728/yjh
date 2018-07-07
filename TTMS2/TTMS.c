#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include "./View/Main_Menu.h"
#include "./View/Account_UI.h"

account_t gl_CurUser={0, USR_ANOMY, "Anonymous",""};

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);
    if(!SysLogin()) {
		printf("\n对不起您无权登录本系统请按任意键退出......\n");
		getchar();
		exit(0);
	}
	Main_Menu(gl_CurUser);
	return EXIT_SUCCESS;
}
