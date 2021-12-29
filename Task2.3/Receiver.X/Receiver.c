///////////////////////////////////////////////////////////////////////
//Author: Abhiyanta Community 
//Team: Devanshi, Hemangi, Jainam, Harsh
//Note: This Code has been created as part of training task at Abhiyanta Community.
//Discreption : Read readme.md file The code has been created to acomplish task 2.3
///////////////////////////////////////////////////////////////////////

#include <xc.h>
#define _XTAL_FREQ 20000000
#define Baud_rate 9600

void Initialize_UART(void)
{
    TRISC6 = 0; //TX Pin set as output
    TRISC7 = 1; // RX Pin set as input
    
    SPBRG = ((_XTAL_FREQ/16)/Baud_rate) - 1;
    BRGH  = 1;  // for high baud_rate
    
    SYNC  = 0;    // Asynchronous
    SPEN  = 1;    // Enable serial port pins

    TXEN  = 1;    //enable transmission
    CREN  = 1;    // enable reception
    
    TX9   = 0;    // 8-bit transmission mode selected
    RX9   = 0;    // 8-bit reception mode selected
}

char UART_get_char()   
{
    while(!RCIF);  // hold the program till RX buffer is free
    return RCREG; //receive the value and send it to main function
}

void main()
{
  TRISB = 0x00; //PORTB as Output
  Initialize_UART();    //Initialize UART module 

  while(1)
  {
      if(RCIF)
       PORTB = UART_get_char();
  }
}
