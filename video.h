#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <iomanip>
#include <set>

class Video
{
    public:
        Video(std::string t, std::string u, std::string c, double l, int r);
        ~Video();
        void print();
        std::string toStar(int num);
    private:
        std::string title;
        std::string url;
        std::string comment;
        double length;
        int rating;
};

class Sort
{
    public:
        Sort(std::string t);
        ~Sort();
        void display(Video *videos[], int length);
    private:
        std::string type;
};

#endif
