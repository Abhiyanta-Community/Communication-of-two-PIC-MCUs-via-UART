///////////////////////////////////////////////////////////////////////
//Author: Abhiyanta Community 
//Team: Devanshi, Hemangi, Jainam, Harsh
//Note: This Code has been created as part of training task at Abhiyanta Community.
//Discreption : Read readme.md file The code has been created to acomplish task 2.1 
///////////////////////////////////////////////////////////////////////


#include "xc.h"
#define _XATL_FREQ 20000000

int i = 0;
int B,temp;
int A=0b000000000;

void interrupt hardware()
{
    INTCONbits.TMR0IE = 1;                                  
    while(1){                                               
        if(INTCONbits.TMR0IF == 1){                 
            /*B = PORTBbits.RB0;          
            temp =  B<<(8-i);               
            A = A | temp;*/
            PORTC = !(PORTC);
            i++;
            if(i == 9){
                i = 0;
                INTCONbits.TMR0IE = 0;
                //INTCONbits.TMR0IF = 0;
                INTCONbits.INTF = 0;
                break;
            }
            INTCONbits.TMR0IF = 0;
            
            //To verify
            /*PORTC = !(PORTC);                               
            
            i++;
            if(i == 9){
                INTCONbits.TMR0IE = 0;
                i = 0;
            }
            INTCONbits.TMR0IF = 0;                          
            //if(i == 10){i = 0;}*/
        }
    }
    //INTCONbits.INTF = 0;                                     
}

void main(){
    
    
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.INTE = 1;
    
    
    OPTION_REG = 0x00;
    TMR0 = 192;
    
    TRISB = 0xff;
    TRISC = 0;
    PORTB = 1;
    PORTC = 0;
    
    while(1){
        if(A == 12)                                   
            PORTCbits.RC0 = 0;
        if(A == 140)
            PORTCbits.RC0 = 1;
    }
    
}