#pragma once
#include <Imagine/Images.h>
#include <Imagine/Graphics.h>
#include <iostream>
#include "Energie.h"

using namespace Imagine;

typedef Image<byte> Img;
using namespace std;

class Energie{
public:
    byte* Energie_list;
    byte get_Energie(int x ) const;
    void set_Energie(int x, byte value);
};


class Images_av{
    Img img;
    int height,width;
    Energie E;
public:
    Images_av(Img img, int height, int width);
    void set_Energie();
    void display_Energie();
};

