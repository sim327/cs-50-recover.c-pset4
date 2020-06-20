#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   unsigned char buffer[512]={0};
   char jpgname[8]={0};
   int counter =0;
   FILE *img = NULL;

   FILE *f = fopen("card.raw", "r");

    while(fread(buffer, sizeof(buffer), 1, f) == 1){


       if (buffer[0] == 0xff && buffer[1]== 0xd8 && buffer[2]==0xff && (buffer[3] & 0xf0)==0xe0) {
       sprintf(jpgname ,"%03i.jpg",counter);

       img = fopen (jpgname , "w");
       fwrite( (&buffer), sizeof(buffer),1,img );
       counter++;
       }
       else
         {

             if(NULL!=img)
                fwrite(buffer, sizeof(buffer), 1, img);
         }
}
if(f!=NULL)
f.close();
if(img!NULL)
f.close();

}
