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
        int getRating();
        double getLength();
        std::string getTitle();
        std::string getUrl();
        std::string getComment();
        std::string asterisk();
    private:
        int rating;
        double length;
        std::string title;
        std::string url;
        std::string comment;
};

class Sort
{
    public:
        Sort(std::string t);
        ~Sort();
        void sort(Video *videos[], int length);
        void display(Video *videos[], int length);
    private:
        std::string type;
        void reassign(Video *vp1, Video *vp2);
};

#endif
