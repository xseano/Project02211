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

void Sort::reassign(Video *vp1, Video *vp2)
{
    Video tmp = *vp1;
    *vp1 = *vp2;
    *vp2 = tmp;
}

void Sort::display(Video *videos[], int length)
{
    for (int i = 0; i < length; i++)
    {
        Video* video = videos[i];
        video->print();
    }
}

void Sort::sort(Video *videos[], int length)
{
    for (int i = 0; i < (length - 1); i++)
    {
        for (int j = 0; j < (length - i - 1); j++)
        {
            if(type == "rating")
            {
                if (videos[j]->getRating() < videos[j + 1]->getRating())
                {
                    reassign(videos[j], videos[j + 1]);
                }
            }
            else if (type == "length")
            {
                if (videos[j]->getLength() > videos[j + 1]->getLength())
                {
                    reassign(videos[j], videos[j + 1]);
                }
            }
            else if (type == "title")
            {
                if (videos[j]->getTitle() > videos[j + 1]->getTitle())
                {
                    reassign(videos[j], videos[j + 1]);
                }
            }
        }
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

std::string Video::asterisk()
{
    std::string str;

    if (getRating() <= 0)
    {
        str = " ";
    }
    else
    {
        for (int i = 0; i < getRating(); ++i)
        {
            str += "*";
        }
    }

    return str;
}

void Video::print()
{
    std::cout << title << ", " << url << ", " << comment << ", " << length << ", " << asterisk() << std::endl;
};