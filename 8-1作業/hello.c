#include"myos.h"
extern void uart_init(void);            //extern void 告訴編譯器 uart_init(void) 函數在其他檔案已被宣告
extern void uart_r(void);                   //extern void 告訴編譯器 uart_puts(char* s) 函數在其他檔案已被宣告

extern void page_init(void);
extern void page_test(void);
extern void malloc_init(void);
extern void * malloc(int nbytes);
extern void free(void *p);

void main(void)
{
    int i;
    uart_init();                                                    //執行uart_init函數初始化UART
    uart_puts("\n\n-----------  Hello!  ------------------\n");     //使用uart_puts函數傳輸 hello 字串

    printf("\n----- page init -----\n");
    page_init();

    printf("\n----- page test -----\n");
    page_test();

    printf("\n----- malloc init -----\n");
    malloc_init();

    printf("\n-----malloc test-----\n");
    void *test1 = malloc(4);
    void *test2 = malloc(1);
    void *test3 = malloc(2);
    void *test4 = malloc(3);
    free(test3);
    void *test5 = malloc(2);
    free(test5);
    void *test6 = malloc(7);
    free(test4);
    free(test6);
    void *test7 = malloc(8);

    free(test1);
    free(test2);   
    free(test7);

    test1 = malloc(4);
    test2 = malloc(1);
    test3 = malloc(2);
    test4 = malloc(3);
    test5 = malloc(2);
    test6 = malloc(7);
    test7 = malloc(8);
    free(test1);
    free(test2);
    free(test3);
    free(test4);
    free(test5);
    free(test6);
    free(test7);


    printf("\n----- malloc test success -----\n");

    printf("\n----- uart polling input -----\n");
    uart_puts("please input , and use Enter to newline , or use exit to quit\n");        //使用uart_puts函數傳輸 please input 字串
    uart_r();                           //使用uart_r函數進入輪詢狀態，取得用戶輸入的字，並將它回傳到用戶的終端機
    


    
    while (1)                           //進入迴圈
    {
        uart_puts("don't go here\n");
    };                       
}