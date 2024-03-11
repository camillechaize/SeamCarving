#include "Images_av.h"

byte Images_av::get_Energie(int x) const{
    return E[x];
}

void Images_av::set_Energie(int x, byte value){
    E[x] = value;
}

Images_av::Images_av(Img im, int h, int w){
    img = im;
    height = h;
    width = w;
    E = new byte [height*width];
    for (int i =0;i<width*height;i++){
        E[i] = byte(0);
    }
}

void Images_av::set_Energie(){
    int Value1,Value2;
    for(int j = 1; j < height-1 ; j++){
        Value1 = img(1,j)-img(0,j);
        Value2 = img(0,j+1)-img(0,j-1);
        set_Energie(j,byte(Value1 + Value2/2));
        Value1 = abs(img(height-1,j)-img(height-2,j));
        Value2 = abs(img(height-1,j+1)-img(height-1,j));
        set_Energie((height-1)*width+j,byte(Value1 + Value2/2));
        for(int i = 1; i < width-1 ; i++){
            Value1 = abs(img(i+1,j)-img(i-1,j));
            Value2 = abs(img(i,j+1)-img(i, j-1));
            set_Energie(j*width +i,byte((Value1 + Value2)/2));

        }
    };
    for(int i = 1; i < width-1 ; i++){
        Value1 = abs(img(i+1,0)-img(i-1,0));
        Value2 = abs(img(i,1)-img(i,0));
        set_Energie(i,byte(Value1 + Value2/2));
        Value1 = abs(img(i+1,height-1)-img(i-1,height-1));
        Value2 = abs(img(i,height-1)-img(i,height-2));
        set_Energie(i +(height -1)*width,byte(Value1 + Value2/2));
    }
    cout << 1 << endl;
    Value1 = abs(img(1,0)-img(0,0));
    Value2 = abs(img(0,1)-img(0,0));
    set_Energie(0,byte(Value1 + Value2));
    Value1 = abs(img(width-1,0)-img(width-2,0));
    Value2 = abs(img(width-1,1)-img(width-1,0));
    set_Energie(width-1,byte(Value1 + Value2));
    Value1 = abs(img(1,height-1)-img(0,height-1));
    Value2 = abs(img(0,height-1)-img(0,height-2));
    set_Energie((height-1)*width,byte(Value1 + Value2));
    Value1 = abs(img(width-1,height-1)-img(width-2,+height-1));
    Value2 = abs(img(width-1,height-1)-img(width-1,height-2));
    set_Energie((height-1)*width+width-1,byte(Value1 + Value2));
}

void Images_av::display_Energie(){
    putGreyImage(0,0,E,width,height);
}
