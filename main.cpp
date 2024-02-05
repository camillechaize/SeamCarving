#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>

using namespace Imagine;

typedef Image<byte> Img;
using namespace std;

Img Image_energy(Img I){
    return I;
}

int main(){
    Img img;
    if (!load(img,srcPath("Image_test.jpg"))) // Stop si l'image n'est pas chargee
        return 0;
    int const imgw = img.width();
    int const imgh = img.height();
    openWindow(imgw, imgh);
    display(img);
    endGraphics();
    return 0;
}
