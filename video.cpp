// video.cpp
// oberoi, sean
// ssoberoi

#include "video.h"

VideoHandler::VideoHandler(std::string t)
    : type(t)
{
    // constructor w/ initialization list
}

VideoHandler::~VideoHandler()
{
    // destructor
    // videos deallocate after output
}

void VideoHandler::destroy(Video *video)
{
    delete video;
}

void VideoHandler::reassign(Video *vp1, Video *vp2)
{
    // NOTE: vp stands for " video pointer "
    // store vp1 temporarily before reassignment
    Video tmp = *vp1;
    // reassignment
    *vp1 = *vp2;
    // switch vp2 to vp1 stored in tmp
    *vp2 = tmp;
}

void VideoHandler::display(Video *videos[], int length)
{
    for (int i = 0; i < length; i++)
    {
        Video* video = videos[i];
        // output video data
        video->print();
        // deallocate the space since it won't be used again
        destroy(video);
    }
}

void VideoHandler::sort(Video *videos[], int length)
{
    bool check = false;

    for (int inner = 0; inner < (length - 1); inner++)
    {
        for (int outer = 0; outer < (length - inner - 1); outer++)
        {
            Video *first = videos[outer];
            Video *next = videos[outer + 1];

            // check sort types to determine how the videos should be compared
            if(type == "rating")
            {
                check = (first->getRating() < next->getRating());
            }
            else if (type == "length")
            {
                check = (first->getLength() > next->getLength());
            }
            else if (type == "title")
            {
                check = (first->getTitle() > next->getTitle());
            }

            // if check passes, swap the pointers
            if (check) { reassign(first, next); }
        }
    }
}

Video::Video(std::string t, std::string u, std::string c, double l, int r)
    : title(t), url(u), comment(c), length(l), rating(r)
{
    // constructor w/ initialization list
};

Video::~Video()
{
    // destructor
}

std::string Video::getTitle()
{
    // public wrapper function for private variable
    // we keep the variable privatized so it can't be modified externally
    return title;
}

std::string Video::getUrl()
{
    // public wrapper function for private variable
    // we keep the variable privatized so it can't be modified externally
    return url;
}

std::string Video::getComment()
{
    // public wrapper function for private variable
    // we keep the variable privatized so it can't be modified externally
    return comment;
}

double Video::getLength()
{
    // public wrapper function for private variable
    // we keep the variable privatized so it can't be modified externally
    return length;
}

int Video::getRating()
{
    // public wrapper function for private variable
    // we keep the variable privatized so it can't be modified externally
    return rating;
}

std::string Video::asterisk()
{
    std::string str = "";

    if (getRating() > 0)
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
    // data output
    std::cout << title << ", " << url << ", " << comment << ", " << length << ", " << asterisk() << std::endl;
};