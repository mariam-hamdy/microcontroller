#include "uart.h"
#include "keypad.h"

typedef struct room
{
   char id;
   char password [4];
   char status; // 0 means free, 1 means occupied , 2 means cleaning
   char door; //0 means locked and 1 means unlocked

}Room;
int main()
{
    char roomNo;
    char pass[4];
    char stat;
    UART_Init(0);
    KeyPad_Init(PortB);
    Room hotelRooms[3]={{1,0000,0,0},{2,0000,0,0},{3,0000,0,0}};
    UART_receiveString(&roomNo);
    UART_receiveString(&stat);
    UART_receiveString(&pass);
   hotelRooms[roomNo-1].password[4]=pass[4];
   hotelRooms[roomNo-1].status=1;
   while(1)
   {
       hotelRooms[roomNo-1].status=stat;
       if(hotelRooms[roomNo-1].status==2)
       {
           hotelRooms[roomNo-1].door=1;
       }
       else if(hotelRooms[roomNo-1].status==0)
       {
           hotelRooms[roomNo-1].password[4]=0000;
           hotelRooms[roomNo-1].door=0;
       }
       else if(hotelRooms[roomNo-1].status==1)
       {
           for(int i=0; i<4; i++)
           {
               pass[i]=KeyPad_getPressedKey();
           }
            if(pass==hotelRooms[roomNo-1].password)
                hotelRooms[roomNo-1].door=1;
            else
                hotelRooms[roomNo-1].door=0;


       }

   }

    return 0;
}
