#pragma once
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include "Energie.h"

using namespace Imagine;

typedef Image<byte> Img;
using namespace std;

class Images_av{
    Img img;
    int height,width;
    byte* E;
public:
    Images_av(Img img, int height, int width);
    void set_Energie();
    void set_Energie(int x, byte value);
    void display_Energie();
    byte get_Energie(int x) const;
};

