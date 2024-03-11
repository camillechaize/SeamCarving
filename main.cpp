#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include "Images_av.h"

using namespace Imagine;

typedef Image<byte> Img;
using namespace std;

Img Image_energy(Img I){
    return I;
}

int main(){
    Img img;
    if (!load(img,srcPath("projet_test.png"))) // Stop si l'image n'est pas chargee
        return 0;
    int const imgw = img.width();
    int const imgh = img.height();
    openWindow(imgw, imgh);
    Images_av imga(img,imgh,imgw);
    imga.set_Energie();
    imga.display_Energie();
    endGraphics();
    return 0;
}
