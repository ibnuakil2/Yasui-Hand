#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g (U8G_I2C_OPT_DEV_0 | U8G_I2C_OPT_NO_ACK | U8G_I2C_OPT_FAST); // Fast I2C / TWI

// initialize the variable to increment the bar
int largPos = 0;

void setup () {  
  u8g.setFont (u8g_font_tpssb); 
  u8g.setColorIndex (1); // Instruksi untuk menyetel piksel ke aktif. (Menampilkan piksel sedikit pun

}

void loop () {  
  bar();
  
  menu();

  if (largPos <108) { // Jika bar belum pada posisi yang diinginkan
    // jika itu tidak cukup cepat, tambahkan lebih dari 1
    largPos +=2; } //  bertambah 1
  else {
    menu();
  }
}  
// fungsi menggambar
void draw () {
    u8g.drawBox (10,15, largPos, 10); // buat persegi panjang yang penuh dengan koordinat dan dimensi (x, y, lebar, tinggi) dan karena itu kami menambah lebarnya (besar)
}

// fungi proggress bar
void bar(){
  // mulai tampilan di sini panggilan
  u8g.firstPage ();
  do {  
    u8g.drawStr (30, 50, "Yasui Hand"); // menulis teks pada koordinat X dan Y.
    u8g.drawFrame (0,10,128,20); // buat persegi panjang kosong (bingkai) dengan nilai (x, y, lebar, tinggi)
    draw (); // pergi ke fungsi menggambar
    } while (u8g.nextPage ()); // tandai di sini akhir dari prosedur tampilan
 
  // jika terlalu cepat tambahkan jeda
  // delay (8);
 // Jika bar belum pada posisi yang diinginkan
    
}
// PAGE MENU
void menu (){
  u8g.drawStr (30, 60, "YasftmyjHand");
}


  
