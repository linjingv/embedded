//用 AT89C52 实现的跑马灯程序
#include <reg52.h>
#include <data_type_def.h>
#include <intrins.h>

extern void delay_ms(void);

uint8 code num[10] = {//anode segment code 共阳数码管段码
    0xc0, //0
    0xf9, //1
    0xa4, //2
    0xb0, //3
    0x99, //4
    0x92, //5
    0x82, //6
    0xf8, //7
    0x80, //8
    0x90, //9
};

void disp_num4(uint8 k){ //选择位
    p2 = 0x08;
    p0 = num[k];
}

void disp_num3(uint8 k){
    p2 = 0x04;
    p0 = num[k];
}

void disp_num2(uint8 k){
    p2 = 0x02;
    p0 = num[k];
}

void disp_num1(uint8 k){  //
    p2 = 0x01;
    p0 = num[k];
}

main(){ //主函数这么写主要是方便理解，实际产品中要用中断来实现。
    while (1)
    {
        disp_num4(4); //选择第四位的函数，传入 4
        delay_ms();
        disp_num3(3);
        delay_ms();
        disp_num2(2);
        delay_ms();
        disp_num1(1);
        delay_ms();
    }
    return 1;
}

/* 1ms */
void delay_ms(void){
    uint16 i, k;
    for(i = 90; i > 0; i--);
    for(k = 80; k > 0; k--);
}