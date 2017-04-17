byte P[] = { 0x78, 0x44, 0x44, 0x78, 0x40, 0x40, 0x40, 0x40 };
byte R[] = { 0x78, 0x44, 0x44, 0x78, 0x70, 0x58, 0x4C, 0x46 };
byte O[] = { 0x3C, 0x42, 0x42, 0x42, 0x42, 0x42, 0x42, 0x3C };
byte M[] = { 0x66, 0x7E, 0x5A, 0x42, 0x42, 0x42, 0x42, 0x42 };
byte E[] = { 0x7C, 0x40, 0x40, 0x78, 0x78, 0x40, 0x40, 0x7C };
byte T[] = { 0x7E, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18 };
byte C[] = { 0x7c, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x7C };
byte N[] = { 0x42, 0x62, 0x72, 0x5A, 0x4E, 0x46, 0x42, 0x42 };
byte dot[]={ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06 };
byte sp[]= { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
String inByte;
void setup()
   { 
        for (int j=2; j<19; j++)
        pinMode(j, OUTPUT);
        Serial.begin(9600);
        
   }
bool GetBit( byte N, int pos)
   {                 // pos = 7 6 5 4 3 2 1 0
       int b = N >> pos ;         // Shift bits
       b = b & 1 ;                // coger solo el ultimo bit
       return b ;
   }
   
   void Clear()
   {
      for (int j=2; j<10; j++)  // Valores de los pines de columna
      digitalWrite(j, HIGH);     // Todos apagados
      for (int k= 10 ; k<18 ; k++)
           digitalWrite(k, LOW);    // Todas las filas cortadas
   }
   
String GetLine()
   {   String S = "" ;
       if (Serial.available())
          {    char c = Serial.read(); ;
                while ( c != '\n')            //Hasta que el caracter sea intro
                  {     S = S + c ;
                        delay(25) ;
                        c = Serial.read();
                  }
                return( S + '\n') ;
          }
   }
   
void loop()            // Prog_37_1
   {
      if (Serial.available() > 0) 
      {
        inByte = GetLine();
        delay (10);
      }
      //else
      //{
       // Serial.write(inByte);
      //}      
      Clear();
      for (int fil = 0; fil <8 ; fil++)
         {
             digitalWrite( fil + 10 , HIGH) ; // Activamos la fila para el barrido
             byte F = R[fil] ;
 
             for (int col =7; col >= 0 ; col--)
               {
                  bool b = GetBit(F, col)  ;
                  if (b)
                      digitalWrite( 9 - col  ,LOW); //Levantamos la columna
                   else
                      digitalWrite( 9 - col  ,HIGH); // Si 0, apagamos
                }                                   
             digitalWrite( fil + 10 , LOW) ; // Apagamos fila antes de salir
         }
   }
