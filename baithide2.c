/*Đề 2: Viết chương trình C tạo ra một tiến trình con sử dụng họ lệnh exec() của system call để gọi lệnh nano để soạn thảo một file văn bản có tên được nhập từ dòng lệnh. Tiến trình chính sử dụng exec() gọi lệnh cat để xem nội dung của file vừa tạo ra.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
int main()
{
    char name[100];
    printf("name of file: ");
    scanf("%s",name);
    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0){
      execlp("nano", "nano",name, NULL);
    }
     else {
        
        int wc = wait(NULL);
        printf("contents of the file: %s\n",name);
        execlp("cat", "cat",name ,NULL);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char pid[100];
    int rc = fork();
    if (rc < 0) {
        printf("fork failed\n");
        exit(1);
    }
    else if (rc == 0){
      execlp("/bin/top", "/bin/top", NULL);
    }
     else {
        // parent goes down this path (original process)
        int wc = wait(NULL);
        printf("hello, I am parent\n");
        printf("enter the pid to kill: \n");
        scanf("%s",pid);
        execlp("kill", "kill", "-9", pid, NULL);
    }
    return 0;
}
