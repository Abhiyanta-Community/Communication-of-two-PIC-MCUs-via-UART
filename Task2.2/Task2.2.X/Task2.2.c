///////////////////////////////////////////////////////////////////////
//Author: Abhiyanta Community 
//Team: Devanshi, Hemangi, Jainam, Harsh
//Note: This Code has been created as part of training task at Abhiyanta Community.
//Discreption : Read readme.md file The code has been created to acomplish task 2.2
///////////////////////////////////////////////////////////////////////


#include <xc.h>
#define _XTAL_FREQ 20000000
#define Baud_Rate 9600

void UART_Initialize(void){
    TRISC6 = 0; 
    TRISC7 = 1; 
     
    SPBRG = ((_XTAL_FREQ/16)/Baud_Rate) - 1;
    BRGH  = 1;  
    SYNC  = 0;    
    SPEN  = 1;    
    TXEN  = 1; 
    CREN  = 1;      
    TX9   = 0;    
    RX9   = 0;    
     
}

void UART_send_char(char bt){
    while(!TXIF); 
    TXREG = bt;
}

char UART_get_char(){
    if(OERR){
        CREN = 0;  
        CREN = 1;  
    }    
    while(!RCIF); 
    
    return RCREG; 
}

void UART_send_string(char* st_pt){
    while(*st_pt) 
        UART_send_char(*st_pt++);
}

void main(void){
    int get_value;
    
    TRISB = 0x00; 
    PORTB = 0;
    UART_Initialize();                        
    
    while(1){
        UART_send_string("Input:");
        get_value = UART_get_char(); 
        
        if (get_value == '1'){
            PORTB = 0b00000010;
            UART_send_string("  Output:1 "); 
        }
        if (get_value == '2'){
            PORTB = 0b00000100;
            UART_send_string("  Output:2  ");      
        }
        if (get_value == '3'){
            PORTB = 0b00001000;
            UART_send_string("  Output:3  ");      
        }   
    }
}