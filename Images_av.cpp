#include "Images_av.h"

byte Energie::get_Energie(int x ) const {
    return Energie_list[x];
}

void Energie::set_Energie(int x, byte value) {
    Energie_list[x] = value;
}

Images_av::Images_av(Img img, int height, int width){
    Energie E;
}

void Images_av::set_Energie(){
    byte Value1,Value2;
    for(int i = 1; i < height-1 ; i++){
        Value1 = E.get_Energie((i+1)*width)-E.get_Energie((i-1)*width);
        Value2 = E.get_Energie(i*width+1)-E.get_Energie(i*width);
        E.set_Energie(i*width,Value1 + Value2/2);
        Value1 = E.get_Energie((i+1)*width+width-1)-E.get_Energie((i-1)*width+width-1);
        Value2 = E.get_Energie(i*width+width-1)-E.get_Energie(i*width+width-2);
        E.set_Energie(i*width+width -1,Value1 + Value2/2);
        for(int j = 1; j < width-1 ; j++){
            Value1 = E.get_Energie((i+1)*width+j)-E.get_Energie((i-1)*width+j);
            Value2 = E.get_Energie(i*width +j+1)-E.get_Energie(i*width + j-1);
            E.set_Energie(i*width +j,(Value1 + Value2)/2);
        }
    }
    for(int j = 1; j < width-1 ; j++){
        Value1 = E.get_Energie(width+j)-E.get_Energie(j);
        Value2 = E.get_Energie(j+1)-E.get_Energie(j-1);
        E.set_Energie(j,Value1 + Value2/2);
        Value1 = E.get_Energie((height-1)*width+j)-E.get_Energie((height-2)*width+j);
        Value2 = E.get_Energie((height-1)*width+j+1)-E.get_Energie((height-1)*width+j);
        E.set_Energie((height-1)*width+j,Value1 + Value2/2);
    }
    Value1 = E.get_Energie(width)-E.get_Energie(0);
    Value2 = E.get_Energie(1)-E.get_Energie(0);
    E.set_Energie(0,Value1 + Value2);
    Value1 = E.get_Energie((height-1)*width)-E.get_Energie((height-2)*width);
    Value2 = E.get_Energie((height-1)*width+1)-E.get_Energie((height-1)*width);
    E.set_Energie((height-1)*width,Value1 + Value2);
    Value1 = E.get_Energie(width+width-1)-E.get_Energie(width-1);
    Value2 = E.get_Energie(width-1)-E.get_Energie(width-2);
    E.set_Energie(width-1,Value1 + Value2);
    Value1 = E.get_Energie((height-1)*width+width-1)-E.get_Energie((height-2)*width+width-1);
    Value2 = E.get_Energie((height-1)*width+width-1)-E.get_Energie((height-1)*width+width-2);
    E.set_Energie((height-1)*width+width-1,Value1 + Value2);
}

void Images_av::display_Energie(){
    putGreyImage(0,0,E.Energie_list,width,height);
}
