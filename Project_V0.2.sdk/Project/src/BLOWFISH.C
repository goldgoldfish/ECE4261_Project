#ifdef little_endian   /* Eg: Intel */
   #include <dos.h>
   #include <graphics.h>
   #include <io.h>
#endif

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef little_endian   /* Eg: Intel */
   #include <alloc.h>
#endif

#include <ctype.h>

#ifdef little_endian   /* Eg: Intel */
   #include <dir.h>
   #include <bios.h>
#endif

#ifdef big_endian
   #include <Types.h>
#endif

#include "Blowfish.h"

#define N               16
#define noErr            0
#define DATAERROR         -1
#define KEYBYTES         8
#define subkeyfilename   "encryption_only/src/Blowfish.dat"

unsigned long P[N + 2];
unsigned long S[4][256];
FILE*         SubkeyFile;

short opensubkeyfile(void) /* read only */
{
   short error;

   error = noErr;

   if((SubkeyFile = open(subkeyfilename,"rb")) == NULL) {
      error = DATAERROR;
   }
 
   return error;
}

unsigned long F(unsigned long x)
{
   unsigned short a;
   unsigned short b;
   unsigned short c;
   unsigned short d;
   unsigned long  y;

   d = x & 0x00FF;
   x >>= 8;
   c = x & 0x00FF;
   x >>= 8;
   b = x & 0x00FF;
   x >>= 8;
   a = x & 0x00FF;
   //y = ((S[0][a] + S[1][b]) ^ S[2][c]) + S[3][d];
   y = S[0][a] + S[1][b];
   y = y ^ S[2][c];
   y = y + S[3][d];

   return y;
}

void Blowfish_encipher(unsigned long *xl, unsigned long *xr)
{
   unsigned long  Xl;
   unsigned long  Xr;
   unsigned long  temp;
   short          i;

   Xl = *xl;
   Xr = *xr;

   for (i = 0; i < N; ++i) {
      Xl = Xl ^ P[i];
      Xr = F(Xl) ^ Xr;

      temp = Xl;
      Xl = Xr;
      Xr = temp;
   }

   temp = Xl;
   Xl = Xr;
   Xr = temp;

   Xr = Xr ^ P[N];
   Xl = Xl ^ P[N + 1];
  
   *xl = Xl;
   *xr = Xr;
}

void Blowfish_decipher(unsigned long *xl, unsigned long *xr)
{
   unsigned long  Xl;
   unsigned long  Xr;
   unsigned long  temp;
   short          i;

   Xl = *xl;
   Xr = *xr;

   for (i = N + 1; i > 1; --i) {
      Xl = Xl ^ P[i];
      Xr = F(Xl) ^ Xr;

      /* Exchange Xl and Xr */
      temp = Xl;
      Xl = Xr;
      Xr = temp;
   }

   /* Exchange Xl and Xr */
   temp = Xl;
   Xl = Xr;
   Xr = temp;

   Xr = Xr ^ P[1];
   Xl = Xl ^ P[0];

   *xl = Xl;
   *xr = Xr;
}

short InitializeBlowfish(char key[], short keybytes)
{
   short          i;
   short          j;
   short          k;
   short          error=0;;
   short          numread;
   unsigned long  data;
   unsigned long  datal;
   unsigned long  datar;
   short pi[1050] = {
   1,4,1,5,9,2,6,5,3,5,8,9,7,9,3,2,3,8,4,6,2,6,4,3,3,8,3,2,7,9,5,0,2,8,8,4,1,9,7,1,6,9,3,9,9,3,7,5,1,0,
   5,8,2,0,9,7,4,9,4,4,5,9,2,3,0,7,8,1,6,4,0,6,2,8,6,2,0,8,9,9,8,6,2,8,0,3,4,8,2,5,3,4,2,1,1,7,0,6,7,9,
   8,2,1,4,8,0,8,6,5,1,3,2,8,2,3,0,6,6,4,7,0,9,3,8,4,4,6,0,9,5,5,0,5,8,2,2,3,1,7,2,5,3,5,9,4,0,8,1,2,8,
   4,8,1,1,1,7,4,5,0,2,8,4,1,0,2,7,0,1,9,3,8,5,2,1,1,0,5,5,5,9,6,4,4,6,2,2,9,4,8,9,5,4,9,3,0,3,8,1,9,6,
   4,4,2,8,8,1,0,9,7,5,6,6,5,9,3,3,4,4,6,1,2,8,4,7,5,6,4,8,2,3,3,7,8,6,7,8,3,1,6,5,2,7,1,2,0,1,9,0,9,1,
   4,5,6,4,8,5,6,6,9,2,3,4,6,0,3,4,8,6,1,0,4,5,4,3,2,6,6,4,8,2,1,3,3,9,3,6,0,7,2,6,0,2,4,9,1,4,1,2,7,3,
   7,2,4,5,8,7,0,0,6,6,0,6,3,1,5,5,8,8,1,7,4,8,8,1,5,2,0,9,2,0,9,6,2,8,2,9,2,5,4,0,9,1,7,1,5,3,6,4,3,6,
   7,8,9,2,5,9,0,3,6,0,0,1,1,3,3,0,5,3,0,5,4,8,8,2,0,4,6,6,5,2,1,3,8,4,1,4,6,9,5,1,9,4,1,5,1,1,6,0,9,4,
   3,3,0,5,7,2,7,0,3,6,5,7,5,9,5,9,1,9,5,3,0,9,2,1,8,6,1,1,7,3,8,1,9,3,2,6,1,1,7,9,3,1,0,5,1,1,8,5,4,8,
   0,7,4,4,6,2,3,7,9,9,6,2,7,4,9,5,6,7,3,5,1,8,8,5,7,5,2,7,2,4,8,9,1,2,2,7,9,3,8,1,8,3,0,1,1,9,4,9,1,2,
   9,8,3,3,6,7,3,3,6,2,4,4,0,6,5,6,6,4,3,0,8,6,0,2,1,3,9,4,9,4,6,3,9,5,2,2,4,7,3,7,1,9,0,7,0,2,1,7,9,8,
   6,0,9,4,3,7,0,2,7,7,0,5,3,9,2,1,7,1,7,6,2,9,3,1,7,6,7,5,2,3,8,4,6,7,4,8,1,8,4,6,7,6,6,9,4,0,5,1,3,2,
   0,0,0,5,6,8,1,2,7,1,4,5,2,6,3,5,6,0,8,2,7,7,8,5,7,7,1,3,4,2,7,5,7,7,8,9,6,0,9,1,7,3,6,3,7,1,7,8,7,2,
   1,4,6,8,4,4,0,9,0,1,2,2,4,9,5,3,4,3,0,1,4,6,5,4,9,5,8,5,3,7,1,0,5,0,7,9,2,2,7,9,6,8,9,2,5,8,9,2,3,5,
   4,2,0,1,9,9,5,6,1,1,2,1,2,9,0,2,1,9,6,0,8,6,4,0,3,4,4,1,8,1,5,9,8,1,3,6,2,9,7,7,4,7,7,1,3,0,9,9,6,0,
   5,1,8,7,0,7,2,1,1,3,4,9,9,9,9,9,9,8,3,7,2,9,7,8,0,4,9,9,5,1,0,5,9,7,3,1,7,3,2,8,1,6,0,9,6,3,1,8,5,9,
   5,0,2,4,4,5,9,4,5,5,3,4,6,9,0,8,3,0,2,6,4,2,5,2,2,3,0,8,2,5,3,3,4,4,6,8,5,0,3,5,2,6,1,9,3,1,1,8,8,1,
   7,1,0,1,0,0,0,3,1,3,7,8,3,8,7,5,2,8,8,6,5,8,7,5,3,3,2,0,8,3,8,1,4,2,0,6,1,7,1,7,7,6,6,9,1,4,7,3,0,3,
   5,9,8,2,5,3,4,9,0,4,2,8,7,5,5,4,6,8,7,3,1,1,5,9,5,6,2,8,6,3,8,8,2,3,5,3,7,8,7,5,9,3,7,5,1,9,5,7,7,8,
   1,8,5,7,7,8,0,5,3,2,1,7,1,2,2,6,8,0,6,6,1,3,0,0,1,9,2,7,8,7,6,6,1,1,1,9,5,9,0,9,2,1,6,4,2,0,1,9,8,9,
   3,8,0,9,5,2,5,7,2,0,1,0,6,5,4,8,5,8,6,3,2,7,8,8,6,5,9,3,6,1,5,3,3,8,1,8,2,7,9,6,8,2,3,0,3,0,1,9,5,2};


   /* First, open the file containing the array initialization data */
   //error = opensubkeyfile();
   if (error == noErr) {
      for (i = 0; i < N + 2; ++i) {
	 numread = pi[i];
   #ifdef little_endian      /* Eg: Intel   We want to process things in byte   */
			   /*   order, not as rearranged in a longword          */
	 data = ((data & 0xFF000000) >> 24) |
		((data & 0x00FF0000) >>  8) |
		((data & 0x0000FF00) <<  8) |
		((data & 0x000000FF) << 24);
   #endif

	 //if (numread != 1) {
	   // return DATAERROR;
	// } else {
	    P[i] = data;
	// }
      }

      for (i = 0; i < 4; ++i) {
	 for (j = 0; j < 256; ++j) {
	     numread = pi[i*j];

   #ifdef little_endian      /* Eg: Intel   We want to process things in byte   */
			   /*   order, not as rearranged in a longword          */
	    data = ((data & 0xFF000000) >> 24) |
		   ((data & 0x00FF0000) >>  8) |
		   ((data & 0x0000FF00) <<  8) |
		   ((data & 0x000000FF) << 24);
   #endif

	     //if (numread != 1) {
	      // return DATAERROR;
	   // } else {
	       S[i][j] = data;
	   // }
	 }
      }

      //fclose(SubkeyFile);

      j = 0;
      for (i = 0; i < N + 2; ++i) {
	 data = 0x00000000;
	 for (k = 0; k < 4; ++k) {
	    data = (data << 8) | key[j];
	    j = j + 1;
	    if (j >= keybytes) {
	       j = 0;
	    }
	 }
	 P[i] = P[i] ^ data;
      }

	datal = 0x00000000;
      datar = 0x00000000;

      for (i = 0; i < N + 2; i += 2) {
	 Blowfish_encipher(&datal, &datar);

	 P[i] = datal;
	 P[i + 1] = datar;
      }

      for (i = 0; i < 4; ++i) {
	 for (j = 0; j < 256; j += 2) {

	    Blowfish_encipher(&datal, &datar);
   
	    S[i][j] = datal;
	    S[i][j + 1] = datar;
	 }
      }
   } else {
      printf("Unable to open subkey initialization file : %d\n", error);
   }

   return error;
}

