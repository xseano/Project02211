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

void Sort::reassign(Video *vid, Video *ovid)
{
    Video tmp = *vid;
    *vid = *ovid;
    *ovid = tmp;
}

void Sort::rating(Video *videos[], int length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (length - i - 1); j++)
        {
            if (videos[j]->getRating() > videos[j + 1]->getRating())
            {
                reassign(videos[j], videos[j + 1]);
            }
        }
    }
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

std::string Video::getTitle()
{
    return title;
}

std::string Video::getUrl()
{
    return url;
}

std::string Video::getComment()
{
    return comment;
}

double Video::getLength()
{
    return length;
}

int Video::getRating()
{
    return rating;
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