byte Tandart[] = { 0x42, 0x66, 0x3C, 0x81, 0xC3, 0xBD, 0x66, 0x42 };
byte cthulhu[] = { 0x42, 0x81, 0xBD, 0x42, 0x66, 0x81, 0x66, 0xA5 };
byte Beto[] = { 0x42, 0x99, 0xBD, 0x81, 0x66, 0x3C, 0x66, 0xC3 };
byte M[] = { 0x99, 0xBD, 0x5A, 0x7E, 0x42, 0x3C, 0xdB, 0x81 };
byte Candado[] = { 0x18, 0x24, 0x24, 0x24, 0xff, 0xff, 0xff, 0xff };
char inByte = "";
void setup()                           // Prog_37_1 hiasd
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
void loop()            // Prog_37_1
   {
      if (Serial.available() > 0) 
      {
        inByte = Serial.read();
      }
      else
      {
        Serial.write(inByte);
      }      
      Clear();
      for (int fil = 0; fil <8 ; fil++)
         {
             digitalWrite( fil + 10 , HIGH) ; // Activamos la fila para el barrido
             byte F = M[fil] ;
 
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
