#include "video.h"

Sort::Sort(std::string t)
    : type(t)
{
    //
}

Sort::~Sort()
{
    //
}

void Sort::display(Video *videos[], int length)
{
    for (int i = 0; i < length; i++)
    {
        Video* video = videos[i];
        video->print();
    }
}

Video::Video(std::string t, std::string u, std::string c, double l, int r)
    : title(t), url(u), comment(c), length(l), rating(r)
{
    //
};

Video::~Video()
{
    //
}

std::string Video::toStar(int num)
{
    std::string str;

    if (num <= 0)
    {
        str = " ";
    }
    else
    {
        for (int i = 0; i < num; ++i)
        {
            str += "*";
        }
    }

    return str;
}

void Video::print()
{
    std::cout << title << ", " << url << ", " << comment << ", " << length << ", " << toStar(rating) << std::endl;
};