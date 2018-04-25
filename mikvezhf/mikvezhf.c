#include<p18f452.h>
#include<delays.h> //v�g�l nem ezt alkalmaztuk, hanem timert

int i=0; // Ez l�ptet�shez van
int memoria[8]; // Ez a mem�ria amibe irkalunk kb. binarisan
int k=0; // Ezt is l�ptet�shez haszn�ljuk


//idozitohoz
void high_isr(void); // ez fog lefutni ha a timer t�lcsordul

#pragma code high_vector=0x08
void interrupt_at_high_vector(void)
{
  _asm GOTO high_isr _endasm //v�ltunk assemblyre �s odamegy�nk a high isr -hez
}
#pragma code /* return to the default code section */
#pragma interrupt high_isr
void high_isr (void)
{
  if(PIR1bits.TMR1IF){ // ez itt az interrupt flag
  	PIR1bits.TMR1IF=0; // els� l�p�sben ezt resetelj�k
  	PORTD=memoria[k];	//port D registerre �rjuk a mem�ri�ba t�rolt cum�t
  	TMR1H=0xc0;         // honnan induljon �jra a timer, de a TMR1L-t is �ll�tani kellene szerintem
  	k=k+1;
  }
}



int gombegytolnyolcig ();

int gombkilenctoltizenhatig ();


int gombegytolnyolcig ()
{

int melyek=0; //ebbe �rom bele a bin�ris t�m�t amit majd megkap a led l�mpa registere.


LATBbits.LATB0=0; //bekapcsoljuk az els� sort �s ha mindkett� nulla akkor lett lenyomva
if(PORTBbits.RB4==0){
melyek=melyek+1;
}
if(PORTBbits.RB5==0){
melyek=melyek+2;
}
if(PORTAbits.RA3==0){
melyek=melyek+4;
}
if(PORTAbits.RA5==0){
melyek=melyek+8;
}
LATBbits.LATB0=1; //lekapcsoljuk az els� sort
LATBbits.LATB1=0; //a m�sodik sort kapcsoljuk be �s ha mindkett� nulla akkor jelez a gomb
if(PORTBbits.RB4==0){
melyek=melyek+16;
}
if(PORTBbits.RB5==0){
melyek=melyek+32;
}
if(PORTAbits.RA3==0){
melyek=melyek+64;
}
if(PORTAbits.RA5==0){
melyek=melyek+128;
}
LATBbits.LATB1=1;

return melyek;
}


int gombkilenctoltizenhatig ()
{

int melyek1=0;


LATBbits.LATB2=0;
if(PORTBbits.RB4==0){
melyek1=melyek1+1;
}
if(PORTBbits.RB5==0){
melyek1=melyek1+2;
}
if(PORTAbits.RA3==0){
melyek1=melyek1+4;
}
if(PORTAbits.RA5==0){
melyek1=melyek1+8;
}
LATBbits.LATB2=1;
LATBbits.LATB3=0;
if(PORTBbits.RB4==0){
melyek1=melyek1+16;
}
if(PORTBbits.RB5==0){
melyek1=melyek1+32;
}
if(PORTAbits.RA3==0){
melyek1=melyek1+64;
}
if(PORTAbits.RA5==0){
melyek1=melyek1+128;
}
LATBbits.LATB3=1;

return melyek1;
}




void main(){
int gomb=0;
int gombelozo=0;
//int memoria[8];
//int i=0;


ADCON1=0x07; //Minden bemenet digit�lis
INTCON2bits.RBPU=0; // pull-upok enged�lyez�se
TRISD=0x00; //Ez itt a l�nyeg. A Port D-n mindenki output. A t�bbit meg nem is haszn�ljuk.
PORTD=0x00; //Minden l�mpa lekapcsolva
TRISA=0xFF; // Minden input
TRISB=0b11110000; //B-n 0-4-ig output
TRISC=0xFF; // Ez nincs semmilyen szinten haszn�lva

while(i<8)
{gomb=gombegytolnyolcig();
if(gombelozo!=gomb)
{i=i+1;
memoria[i-1]=gomb; // ez netto h�lyes�g
}
gombelozo=gomb;
}

T1CON=0x0B; //timer on m�r itt pedig az k�s�bb kellene. B helyett ha a van akkor m�g nem indulna
INTCON=0xC0; //glob�lis �s perif�ri�lis interrupt is enged�lyezve van, de hogy minek
PIE1bits.TMR1IE=1; //interrupt flag j�v�hagyva
TMR1H=0xc0; //honnan indul az �ra
while (k<9)
{}
T1CON=0x0A; //Timert lekapcsoljuk
PIE1bits.TMR1IE=0; //interrupt flag kikapcsolva


}
