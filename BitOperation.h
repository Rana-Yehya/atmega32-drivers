#ifndef BitOperation
#define BitOperation
#define SETBIT(num,bit) num=((num)|((unsigned char)(0x01<<(bit))))

#define CLRBIT(num,bit) num=((num)& ~((unsigned char)(0x01<<(bit))))

#define TOGGLEBIT(num,bit) num=((num)^((unsigned char)(0x01<<(bit))))

#define GETBIT(num,bit) ((num>>bit)&((unsigned char)(1)))

#endif
